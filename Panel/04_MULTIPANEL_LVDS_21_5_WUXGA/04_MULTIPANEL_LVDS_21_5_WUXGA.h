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

#if(_PANEL_TYPE == _MULTIPANEL_LVDS_21_5_WUXGA)
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
#define _PANEL_EXIST_MULTIPANEL                 _ON

//--------------------------------------------------
// Panel Normally status (White or Black)
//--------------------------------------------------
#define _PANEL_NORMALLY_STATUS                  _PANEL_NORMALLY_UNCONFIRMED

//--------------------------------------------------
// Maximum Panel Frame Rate
//--------------------------------------------------
#define _PANEL_MAX_FRAME_RATE                   860                 // Unit in 0.1 HZ
#define _PANEL_MIN_FRAME_RATE                   560


// _PANEL_EXIST_MULTIPANEL Stsrt
//--------------------------------------------------
// Set Last Line Finetune Target (Must Be Larger than 4 Pixel!!)
//--------------------------------------------------
#define _LAST_LINE_TARGET                       ((tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_TOTAL_INDEX]) - (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_LAST_LINE_TARGET_INDEX])) // (_PANEL_DH_TOTAL - 150)

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_MANUFACTURER_INDEX])
// _PANEL_EXIST_MULTIPANEL End

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_LVDS         // _PANEL_LVDS or _PANEL_RSDS or _PANEL_TTL
#define _LVDS_TABLE_TYPE                        _LVDS_BIT_MAP_TABLE_1

//--------------------------------------------------
// Definitions for Panel Configuration
//--------------------------------------------------
#define _DISP_OUTPUT_PORT                       _DISP_DOUBLE_PORT   // _DISP_DOUBLE_PORT or _DISP_SINGLE_PORT
#define _DISP_BIT_MODE                          _DISP_24_BIT        // _DISP_30_BIT or _DISP_24_BIT or _DISP_18_BIT
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

#define _D_DITHER_TEMP                          _ENABLE                // Definitions of D-Temporal Dithering
#define _D_DITHER_VALUE_SIGN                    _DISABLE
#define _D_DITHER_V_FRAME_MOD                   _DISABLE
#define _D_DITHER_H_FRAME_MOD                   _DISABLE
#define _D_DITHER_THRESHOLD_EN                  _DISABLE

// New dither function for IC 6230,6229 and so on
#define _DITHER_MULTI_SEQ_ENABLE                _ENABLE
#define _DITHER_SHARE_SEQ_ENABLE                _ENABLE

#define _DITHER_SEQ_INV_ENABLE                  _ENABLE
#define _DITHER_SEQ_INV_MODE                    0  // 0: r,~r,g,~g,b,~b    1:  r,g,b~r,~g,~b

#define _DITHER_PR_SHIFT_VALUE                  2   //(0:3)

//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#define _PANEL_DH_WIDTH                         (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_WIDTH_INDEX])             // Display Horizontal Width
#define _PANEL_DH_END                           (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_END_INDEX])               // Display Horizontal End Position

#define _PANEL_DH_TOTAL                         (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_TOTAL_INDEX])             // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX                     (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_TOTAL_MAX_INDEX])         // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                     (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_TOTAL_MIN_INDEX])         // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_HEIGHT                        (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_HEIGHT_INDEX])            // Display Vertical Width
#define _PANEL_DV_END                           (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_END_INDEX])               // Display Vertical End Position

#define _PANEL_DV_TOTAL                         (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_TOTAL_INDEX])             // Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MAX                     (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_TOTAL_MAX_INDEX])         // Maxinum Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MIN                     (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_TOTAL_MIN_INDEX])         // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_PIXEL_CLOCK                      (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_PIXEL_CLOCK_INDEX])          // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX                  (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_PIXEL_CLOCK_MAX_INDEX])      // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN                  (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_PIXEL_CLOCK_MIN_INDEX])      // Mininum Pixel Clock in MHz

#define _PANEL_POWER_ON_T1                      (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_ON_T1_INDEX])          // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_ON_T2_INDEX])          // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_ON_T3_INDEX])          // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_OFF_T4_INDEX])         // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                     (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_OFF_T5_INDEX])         // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     (tPanelData [GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_OFF_T6_INDEX])         // Panel Power Off T6 (ms)

#define _PANEL_DH_START                         32
#define _PANEL_DH_SYNC_WIDTH                    8

#define _PANEL_DV_START                         6
#define _PANEL_DV_SYNC_HEIGHT                   2

//========================================================================================
//========================================================================================

//--------------------------------------------------
// Definitions for Panel Amount 
//--------------------------------------------------
#define _PANEL_AMOUNT                           2

//--------------------------------------------------
// Macros of MDomain Panel Index
//--------------------------------------------------
#define SET_MDOMAIN_PANEL_INDEX(x)              (g_ucDDomainPanelIndex = x)
#define GET_MDOMAIN_PANEL_INDEX()               (g_ucDDomainPanelIndex)

//--------------------------------------------------
// Definitions of Panel data Index
//--------------------------------------------------
typedef enum
{
    _PANEL_LAST_LINE_TARGET_INDEX,
    _PANEL_MANUFACTURER_INDEX,
//--------------------------------
    _PANEL_DH_START_INDEX,
    _PANEL_DH_WIDTH_INDEX,
    _PANEL_DH_END_INDEX,

    _PANEL_DH_TOTAL_INDEX,        
    _PANEL_DH_TOTAL_MAX_INDEX,    
    _PANEL_DH_TOTAL_MIN_INDEX,    

    _PANEL_DV_START_INDEX,     
    _PANEL_DV_HEIGHT_INDEX,    
    _PANEL_DV_END_INDEX,       

    _PANEL_DV_TOTAL_INDEX,      
    _PANEL_DV_TOTAL_MAX_INDEX,  
    _PANEL_DV_TOTAL_MIN_INDEX,  
    _PANEL_DH_SYNC_WIDTH_INDEX, 
    _PANEL_DV_SYNC_HEIGHT_INDEX,

    _PANEL_PIXEL_CLOCK_INDEX,    
    _PANEL_PIXEL_CLOCK_MAX_INDEX,
    _PANEL_PIXEL_CLOCK_MIN_INDEX,

    _PANEL_POWER_ON_T1_INDEX,
    _PANEL_POWER_ON_T2_INDEX,
    _PANEL_POWER_ON_T3_INDEX,

    _PANEL_POWER_OFF_T4_INDEX,
    _PANEL_POWER_OFF_T5_INDEX,
    _PANEL_POWER_OFF_T6_INDEX,
    _PANEL_DATA_AMOUNT,
};

#ifdef __SCALER_DDOMAIN__

//----------------------------------------------------------------------------------------------------
// Panel Data Table
//----------------------------------------------------------------------------------------------------
WORD code tPanelData [_PANEL_AMOUNT][_PANEL_DATA_AMOUNT] =
{
    {
        150,        // _LAST_LINE_TARGET
        _PANEL_AUO, // _PANEL_MANUFACTURER
//---------------------------------------------
        32,         // _PANEL_DH_START
        1920,       // _PANEL_DH_WIDTH
        1952,       // _PANEL_DH_END
     
        2100,       // _PANEL_DH_TOTAL        
        2200,       // _PANEL_DH_TOTAL_MAX    
        2048,       // _PANEL_DH_TOTAL_MIN    
     
        6,          // _PANEL_DV_START     
        1080,       // _PANEL_DV_HEIGHT    
        1086,       // _PANEL_DV_END       
     
        1150,       // _PANEL_DV_TOTAL      
        1600,       // _PANEL_DV_TOTAL_MAX  
        1100,       // _PANEL_DV_TOTAL_MIN  
        8,          // _PANEL_DH_SYNC_WIDTH 
        2,          // _PANEL_DV_SYNC_HEIGHT
     
        144,        // _PANEL_PIXEL_CLOCK    
        180,        // _PANEL_PIXEL_CLOCK_MAX
        110,        // _PANEL_PIXEL_CLOCK_MIN
     
        100,        // _PANEL_POWER_ON_T1
        40,         // _PANEL_POWER_ON_T2
        300,        // _PANEL_POWER_ON_T3
       
        20,         // _PANEL_POWER_OFF_T4
        40,         // _PANEL_POWER_OFF_T5
        600,        // _PANEL_POWER_OFF_T6
    },

    {
        150,        // _LAST_LINE_TARGET
        _PANEL_AUO, // _PANEL_MANUFACTURER
//---------------------------------------------
        32,         // _PANEL_DH_START
        1920,       // _PANEL_DH_WIDTH
        1952,       // _PANEL_DH_END
     
        2100,       // _PANEL_DH_TOTAL        
        2200,       // _PANEL_DH_TOTAL_MAX    
        2048,       // _PANEL_DH_TOTAL_MIN    
     
        6,          // _PANEL_DV_START     
        1080,       // _PANEL_DV_HEIGHT    
        1086,       // _PANEL_DV_END       
     
        1150,       // _PANEL_DV_TOTAL      
        1600,       // _PANEL_DV_TOTAL_MAX  
        1100,       // _PANEL_DV_TOTAL_MIN  
        8,          // _PANEL_DH_SYNC_WIDTH 
        2,          // _PANEL_DV_SYNC_HEIGHT
     
        144,        // _PANEL_PIXEL_CLOCK    
        180,        // _PANEL_PIXEL_CLOCK_MAX
        110,        // _PANEL_PIXEL_CLOCK_MIN
     
        100,        // _PANEL_POWER_ON_T1
        40,         // _PANEL_POWER_ON_T2
        300,        // _PANEL_POWER_ON_T3
       
        20,         // _PANEL_POWER_OFF_T4
        40,         // _PANEL_POWER_OFF_T5
        600,        // _PANEL_POWER_OFF_T6
    },
};

#endif

#ifndef __SCALER_DDOMAIN__

//----------------------------------------------------------------------------------------------------
// Panel Data Table Extern
//----------------------------------------------------------------------------------------------------
extern WORD code tPanelData [_PANEL_AMOUNT][_PANEL_DATA_AMOUNT];

#endif


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

#endif // End of #if(_PANEL_TYPE == _MULTIPANEL_LVDS_21_5_WUXGA)
