/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2010>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/
#if(_PANEL_TYPE == _TPV_CMI_M190CGE_20)
//----------------------------------------------------------------------------------------------------
// ID Code      : Panel.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// 2D / 3D panel type
//--------------------------------------------------
#define _PANEL_DISPLAY_TYPE                     _PANEL_DISPLAY_NORMAL  

//--------------------------------------------------
// Definitions for MultiPanel Support
//--------------------------------------------------
#define _PANEL_EXIST_MULTIPANEL                 _OFF

//--------------------------------------------------
// Panel Normally status (White or Black)
//--------------------------------------------------
#define _PANEL_NORMALLY_STATUS                _PANEL_NORMALLY_BLACK

//--------------------------------------------------
// Maximum Panel Frame Rate
//--------------------------------------------------
#define _PANEL_MAX_FRAME_RATE                   860                 // Unit in 0.1 HZ
#define _PANEL_MIN_FRAME_RATE                   500

//--------------------------------------------------
// Set Last Line Finetune Target
//--------------------------------------------------
#define _LAST_LINE_TARGET                       (400)//(_PANEL_DH_TOTAL - 150)

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     _PANEL_CMO      // _PANEL_CMO or _PANEL_AUO or _PANEL_SAMSUNG or _PANEL_INNOLUX or _PANEL_CPT

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_LVDS         // _PANEL_LVDS or _PANEL_RSDS or _PANEL_TTL
#define _LVDS_TABLE_TYPE                        _LVDS_BIT_MAP_TABLE_1

//--------------------------------------------------
// Definitions for Panel Configuration
//--------------------------------------------------
#define _DISP_OUTPUT_PORT                       _DISP_DOUBLE_PORT   // _DISP_DOUBLE_PORT or _DISP_SINGLE_PORT
#define _DISP_BIT_MODE                          _DISP_24_BIT        // _DISP_24_BIT or _DISP_18_BIT//Eli 20120328 DVI dithering issue.
#define _DHS_MASK                               _DISABLE            // Definitions for First DHS Masking
#define _DISP_SKEW                              _DISABLE            // Definitions for Skew Display Data Output

//--------------------------------------------------
// Definitions for Dither Configuration
//--------------------------------------------------
#define _I_DITHER_TEMP                          _ENABLE               // Definations of I-Temporal Dithering
#define _I_DITHER_VALUE_SIGN                    _DISABLE
#define _I_DITHER_MODE_SELECT                   _DISABLE
#define _I_DITHER_V_FRAME_MOD                   _DISABLE
#define _I_DITHER_H_FRAME_MOD                   _DISABLE

#define _D_DITHER_TEMP                          _DISABLE                // Definitions of D-Temporal Dithering
#define _D_DITHER_VALUE_SIGN                    _DISABLE
#define _D_DITHER_V_FRAME_MOD                   _DISABLE
#define _D_DITHER_H_FRAME_MOD                   _DISABLE
#define _D_DITHER_THRESHOLD_EN                  _DISABLE

// New dither function for IC 6230,6229 and so on
#define _DITHER_MULTI_SEQ_ENABLE                _DISABLE
#define _DITHER_SHARE_SEQ_ENABLE                _DISABLE

#define _DITHER_SEQ_INV_ENABLE                  _DISABLE
#define _DITHER_SEQ_INV_MODE                    0  // 0: r,~r,g,~g,b,~b    1:  r,g,b~r,~g,~b

#define _DITHER_PR_SHIFT_VALUE                  2   //(0:3)

//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#define _PANEL_DH_START                         32                  // Display Horizontal Start Position

#define _PANEL_DH_WIDTH                         1440                // Display Horizontal Width
#define _PANEL_DH_END                           1472                // Display Horizontal End Position

#define _PANEL_DH_TOTAL                         1600               // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX                     1640                // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                     1504                // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_START                         6                  // Display Vertical Start Position
#define _PANEL_DV_HEIGHT                        900                // Display Vertical Width
#define _PANEL_DV_END                           906                // Display Vertical End Position

#define _PANEL_DV_TOTAL                         926                // Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MAX                     942                // Maxinum Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MIN                     905                // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_DH_SYNC_WIDTH                    8                   // Display Horizontal Sync Width
#define _PANEL_DV_SYNC_HEIGHT                   2                   // Display Vertical Sync Height

#define _PANEL_PIXEL_CLOCK                      89                 // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX                  116                 // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN                  68                 // Mininum Pixel Clock in MHz


#define _PANEL_POWER_ON_T1                      20                  // Panel Power On T1 (ms) CMI_spec:0<T2<50ms
#define _PANEL_POWER_ON_T2                      30                  // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      250                 // Panel Power On T3 (ms) CMI_spec:T5>200ms

#define _PANEL_POWER_OFF_T4                     250                 // Panel Power Off T4 (ms) CMI_spec:T6>100ms
#define _PANEL_POWER_OFF_T5                     20//40                  // Panel Power Off T5 (ms) CMI_spec:0<T3<50ms
#define _PANEL_POWER_OFF_T6                     550                // Panel Power Off T6 (ms) CMI_spec:T4>500ms

//----------------------------------------------------------------------------------------------------
// Color Temp Default Value
//----------------------------------------------------------------------------------------------------
#include "ColorTempDefault.h"

#if(_ENERGY_STAR_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// Energy Star Table
//----------------------------------------------------------------------------------------------------
#include "EnergyStarTable.h"
#endif // End of #if(_ENERGY_STAR_SUPPORT == _ON)

#ifdef __USER_PANEL__

#if((_I_DITHER_SUPPORT == _ON) || (_D_DITHER_SUPPORT == _ON))
//----------------------------------------------------------------------------------------------------
// Dithering Table
//----------------------------------------------------------------------------------------------------
#include "DitherTempTable.h"

#if(_I_DITHER_SUPPORT == _ON)
#include "IDitherTable.h"
#endif

#if(_D_DITHER_SUPPORT == _ON)
#include "DDitherTable.h"
#endif

#endif // End of #if((_I_DITHER_SUPPORT == _ON) || (_D_DITHER_SUPPORT == _ON))

#if(_GAMMA_FUNCTION == _ON)
//----------------------------------------------------------------------------------------------------
// Gamma Table
//----------------------------------------------------------------------------------------------------
#include "Gamma18.h"
#include "Gamma20.h"
#include "Gamma22.h"
#include "Gamma24.h"

code BYTE *tGAMMA_TABLE[] =
{
    tLUTGAMMA_18_TABLE,
    tLUTGAMMA_20_TABLE,
    tLUTGAMMA_22_TABLE,
    tLUTGAMMA_24_TABLE,
};

#endif // End of #if(_GAMMA_FUNCTION == _ON)

#if(_PCM_FUNCTION == _ON)
//----------------------------------------------------------------------------------------------------
// PCM Table
//----------------------------------------------------------------------------------------------------
#include "PCMUserInputGammaTable.h"
#include "PCMUserColorMatrixTable.h"
#include "PCMUserOutputGammaTable.h"

code BYTE *tPCM_USER_TABLE[] =
{
    tPCM_USER_INPUT_GAMMA_TABLE,    tPCM_USER_OUTPUT_GAMMA_TABLE,   tPCM_USER_MATRIX,
};
#endif // End of #if(_PCM_FUNCTION == _ON)

#if(_ICM_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// ICM Table
//----------------------------------------------------------------------------------------------------
#include "IcmModeGame.h"
#include "IcmModeMovie.h"
#include "IcmModePhoto.h"
#include "IcmModeVivid.h"

code BYTE *tICM_TABLE[] =
{    
    tICM_GAME0,         tICM_GAME1,         tICM_GAME2,         tICM_GAME3,         NULL,       NULL,
    tICM_MOVIE0,        tICM_MOVIE1,        tICM_MOVIE2,        tICM_MOVIE3,        NULL,       NULL,
    tICM_PHOTO0,        tICM_PHOTO1,        tICM_PHOTO2,        tICM_PHOTO3,        NULL,       NULL,
    tICM_VIVID0,        tICM_VIVID1,        tICM_VIVID2,        tICM_VIVID3,        NULL,       NULL,
};

code WORD tICM_CONTROL[] =
{
    _ICM_GAME_CONTROL, _ICM_MOVIE_CONTROL, _ICM_PHOTO_CONTROL, _ICM_VIVID_CONTROL,               
};

#endif // End of #if(_ICM_SUPPORT == _ON)

#if(_DCC_FUNCTION == _ON) 
//----------------------------------------------------------------------------------------------------
// DCC Table
//----------------------------------------------------------------------------------------------------
#include "DccModeGame.h"
#include "DccModeMovie.h"
#include "DccModePhoto.h"
#include "DccModeVivid.h"

code BYTE *tDCC_TABLE[] =
{
    tDCC_GAME,  tDCC_MOVIE,  tDCC_PHOTO,  tDCC_VIVID,
};

#endif // End of #if(_DCC_FUNCTION == _ON) 

#if(_OD_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// OD Table
//----------------------------------------------------------------------------------------------------
#include "ODTable.h"

code BYTE *tOD_TABLE[] =
{
    tOD_TABLE_COMMON,
};
#endif // End of #if(_OD_SUPPORT == _ON)

#endif // End of #ifdef __USER_PANEL__

#endif // End of #if(_PANEL_TYPE == _TPV_CMI_M190CGE_20)

