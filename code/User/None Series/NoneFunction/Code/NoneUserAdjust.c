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
// ID Code      : UserAdjust.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_ADJUST__
#define __USER_PANEL__   __USER_ADJUST__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _NONE_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _SHARPNESS_TABLE_SIZE                       128
#define _YPEAKING_TABLE_SIZE                        6

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//----------------------------------------------------------------------------------------------------
// Filter Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
#include "SharpnessTable0.h"
//#include "SharpnessTable1.h"
#include "SharpnessTable2.h"
//#include "SharpnessTable3.h"
#include "SharpnessTable4.h"
//#include "SharpnessTable5.h"
#include "SharpnessTable6.h"
//#include "SharpnessTable7.h"
#include "SharpnessTable8.h"
//#include "SharpnessTable9.h"
//#include "SharpnessTable10.h"

code BYTE *tSCALE_H_COEF_TABLE[] =
{
#if((_SCALING_UP_TYPE == _SU_GEN_0) || (_SCALING_UP_TYPE == _SU_GEN_1))
    tSU_COEF_128_TAPS_0,     tSU_COEF_128_TAPS_2,     tSU_COEF_128_TAPS_4,     tSU_COEF_128_TAPS_6,     tSU_COEF_128_TAPS_8,
#elif(_SCALING_UP_TYPE == _SU_GEN_2)
    tSU_COEF_96_TAPS_0,     tSU_COEF_96_TAPS_2,     tSU_COEF_96_TAPS_4,     tSU_COEF_96_TAPS_6,     tSU_COEF_96_TAPS_8,
#endif    
};

code BYTE *tSCALE_H_1to1_COEF_TABLE[] =
{
#if((_SCALING_UP_TYPE == _SU_GEN_0) || (_SCALING_UP_TYPE == _SU_GEN_1))
    tSU_1to1_COEF_128_TAPS_0,     tSU_1to1_COEF_128_TAPS_2,     tSU_1to1_COEF_128_TAPS_4,     tSU_1to1_COEF_128_TAPS_6,     tSU_1to1_COEF_128_TAPS_8,
#elif(_SCALING_UP_TYPE == _SU_GEN_2)
    tSU_1to1_COEF_96_TAPS_0,     tSU_1to1_COEF_96_TAPS_2,     tSU_1to1_COEF_96_TAPS_4,     tSU_1to1_COEF_96_TAPS_6,     tSU_1to1_COEF_96_TAPS_8,
#endif    
};

code BYTE *tSCALE_V_COEF_TABLE[] =
{
#if(_SCALING_UP_TYPE == _SU_GEN_0)    
    tSU_COEF_128_TAPS_0,     tSU_COEF_128_TAPS_2,     tSU_COEF_128_TAPS_4,     tSU_COEF_128_TAPS_6,     tSU_COEF_128_TAPS_8,
#elif((_SCALING_UP_TYPE == _SU_GEN_1) || (_SCALING_UP_TYPE == _SU_GEN_2))
    tSU_COEF_96_TAPS_0,     tSU_COEF_96_TAPS_2,     tSU_COEF_96_TAPS_4,     tSU_COEF_96_TAPS_6,     tSU_COEF_96_TAPS_8,
#endif    
};

#if(_3D_SUPPORT == _ON)
code BYTE *tSCALE_V_3D_3L_COEF_TABLE[] =
{
    tSU_COEF_96_TAPS_0,     tSU_COEF_96_TAPS_2,     tSU_COEF_96_TAPS_4,     tSU_COEF_96_TAPS_6,     tSU_COEF_96_TAPS_8,
};

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
code BYTE *tSCALE_V_3D_2L_COEF_TABLE[] =
{
    tSU_COEF_64_TAPS_0,     tSU_COEF_64_TAPS_2,     tSU_COEF_64_TAPS_4,     tSU_COEF_64_TAPS_6,     tSU_COEF_64_TAPS_8,
};
#endif

#endif // End of #if(_3D_SUPPORT == _ON)

#if(_VGA_SUPPORT == _ON)

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
//----------------------------------------------------------------------------------------------------
// DIGITAL FILTER ENHANCE PHASE MODE TABLE
//----------------------------------------------------------------------------------------------------
#include "DigFilterEnhancePhaseTable.h"

#endif  // End of #if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)

#if(_RINGING_FILTER_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// RINGING FILTER OFFSET COEFFICIENT TABLE
//----------------------------------------------------------------------------------------------------
#include "RingingFilterTable.h"

#endif  // End of #if(_RINGING_FILTER_SUPPORT == _ON)

#endif  // End of #if(_VGA_SUPPORT == _ON)

//----------------------------------------------------------------------------------------------------
// ULTRAVIVID TABLE
//----------------------------------------------------------------------------------------------------
#if(_ULTRA_VIVID_SUPPORT == _ON)
#include "UltraVividTableL.h"
#include "UltraVividTableM.h"
#include "UltraVividTableH.h"
#include "UltraVividTableCDS.h"

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
code BYTE *tCOLOR_ULTRAVIVID_SETTING_HSR[] = 
{
    tCOLOR_ULTRAVIVID_HSR_SETTING_L,     tCOLOR_ULTRAVIVID_HSR_SETTING_M,     tCOLOR_ULTRAVIVID_HSR_SETTING_H,
};
#endif

code BYTE *tCOLOR_ULTRAVIVID_SETTING_TABLE[] =
{
    tCOLOR_ULTRAVIVID_SETTING_L1,        tCOLOR_ULTRAVIVID_SETTING_L2,        tCOLOR_ULTRAVIVID_SETTING_L3,        tCOLOR_ULTRAVIVID_SETTING_L4,   // _SR_OPT_1
    tCOLOR_ULTRAVIVID_SETTING_M1,        tCOLOR_ULTRAVIVID_SETTING_M2,        tCOLOR_ULTRAVIVID_SETTING_M3,        tCOLOR_ULTRAVIVID_SETTING_M4,   // _SR_OPT_2
    tCOLOR_ULTRAVIVID_SETTING_H1,        tCOLOR_ULTRAVIVID_SETTING_H2,        tCOLOR_ULTRAVIVID_SETTING_H3,        tCOLOR_ULTRAVIVID_SETTING_H4,   // _SR_OPT_3
};
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_YPEAKING_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// Ypeaking Coefficient Table 
//----------------------------------------------------------------------------------------------------
#include "YPeakingTable.h"

code BYTE *tYPEAKING_TABLE[] =
{
    tYPK_COEF_1,
};
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_OVERSCAN_SUPPORT == _ON)
bit UserAdjustCheckOverScan(void);
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
void UserAdjustSelectAspectRatio(void);
#endif

void UserAdjustContrast(BYTE ucContrast);
void UserAdjustBacklight(BYTE ucBacklight);
void UserAdjustBrightness(BYTE ucBrightness);
void UserAdjustSharpness(BYTE ucSharpness);
void UserAdjustLoadDitherTable(void);

#if(_VGA_SUPPORT == _ON)

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
void UserAdjustDigitalFilterEnhancePhase(void);
#endif

#if(_RINGING_FILTER_SUPPORT == _ON)
void UserAdjustRingingFilter(void);
#endif

#endif  // End of #if(_VGA_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)
void UserAdjustIDitherOn(void);
#endif

#if(_YPEAKING_SUPPORT == _ON)
void UserAdjustYpeaking(void);
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_OD_SUPPORT == _ON)
void UserAdjustODLoadLUT(void);
#endif

#if(_ULTRA_VIVID_SUPPORT)
void UserAdjustUltraVivid(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_OVERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Timing For Overscan
// Input Value  : Current Input Timing
// Output Value : Modified Input Timing
//--------------------------------------------------
bit UserAdjustCheckOverScan(void)
{
    return _FALSE;
}
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Display Timing For Aspect Ratio
// Input Value  : Current Display Timing and Input H/V
// Output Value : Modified Display Timing
//--------------------------------------------------
void UserAdjustSelectAspectRatio(void)
{

}
#endif

//--------------------------------------------------
// Description  : Adjust color processing contrast
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustContrast(BYTE ucContrast)
{
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    if(SysSourceGetSourceType() == _SOURCE_DVI)
    {
        ucContrast -= 7;
    }

    pData[0] = (((WORD)128 * ucContrast / 128) > 255) ? 255 : (BYTE)((WORD)128 * ucContrast / 128);
    pData[1] = (((WORD)128 * ucContrast / 128) > 255) ? 255 : (BYTE)((WORD)128 * ucContrast / 128);
    pData[2] = (((WORD)128 * ucContrast / 128) > 255) ? 255 : (BYTE)((WORD)128 * ucContrast / 128);

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    if(1)
    {
        ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);
        pData[0] = 0x80;
        pData[1] = 0x80;
        pData[2] = 0x80;
        ScalerColorBriConSetCoef(_CONTRAST_COEF_B, pData);
    }
    else
    {
        ScalerColorBriConSetCoef(_CONTRAST_COEF_B, pData);
        pData[0] = 0x80;
        pData[1] = 0x80;
        pData[2] = 0x80;
        ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);
    }
#else
    ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);
#endif

}

//--------------------------------------------------
// Description  : Adjust backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustBacklight(BYTE ucBacklight)
{
#if(_BACKLIGHT_PWM_INVERSE == _ON)
    ucBacklight = _BACKLIGHT_MAX - ucBacklight;
#endif

    // Adjust backlight by changing PWM duty
    PCB_BACKLIGHT_PWM(ucBacklight);
}

//--------------------------------------------------
// Description  : Adjust backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustBrightness(BYTE ucBrightness)
{
    pData[0] = ucBrightness;
    pData[1] = ucBrightness;
    pData[2] = ucBrightness;

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    if(1)
    {
        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_A, pData);
        pData[0] = 0x80;
        pData[1] = 0x80;
        pData[2] = 0x80;
        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_B, pData);
    }
    else
    {
        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_B, pData);
        pData[0] = 0x80;
        pData[1] = 0x80;
        pData[2] = 0x80;
        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_A, pData);
    }
#else
    ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_A, pData);
#endif
}

//--------------------------------------------------
// Description  : Set Sharpness Table
// Input Value  : Request Sharpness Table
// Output Value : None
//--------------------------------------------------
void UserAdjustSharpness(BYTE ucSharpness)
{
#if(_3D_SUPPORT == _ON)

    switch(ScalerScalingGetScalingUpType())
    {
        case _VSU_2D_4LINE_COEF:
            
            // 1:1 Mode Use Different Scaling Table
            if((GET_INPUT_TIMING_HWIDTH() == _PANEL_DH_WIDTH) && (GET_INPUT_TIMING_VHEIGHT() == _PANEL_DV_HEIGHT))
            {
                ScalerMemorySetScalingCoef(tSCALE_H_1to1_COEF_TABLE[ucSharpness], tSCALE_V_COEF_TABLE[ucSharpness], _SHARPNESS_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());
            }
            else
            {
                ScalerMemorySetScalingCoef(tSCALE_H_COEF_TABLE[ucSharpness], tSCALE_V_COEF_TABLE[ucSharpness], _SHARPNESS_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());
            }
            
            break;
            
#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
        case _VSU_3D_4LINE_COEF:
#endif            
            ScalerMemorySetScalingCoef(tSCALE_H_COEF_TABLE[ucSharpness], tSCALE_V_COEF_TABLE[ucSharpness], _SHARPNESS_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());
           
            break;            

        case _VSU_2D_3LINE_COEF:
        case _VSU_3D_3LINE_COEF:

            ScalerMemorySetScalingCoef(tSCALE_H_COEF_TABLE[ucSharpness], tSCALE_V_3D_3L_COEF_TABLE[ucSharpness], _SHARPNESS_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());         

            break;

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)            
        case _VSU_3D_2LINE_COEF:

            ScalerMemorySetScalingCoef(tSCALE_H_COEF_TABLE[ucSharpness], tSCALE_V_3D_2L_COEF_TABLE[ucSharpness], _SHARPNESS_TABLE_SIZE, GET_CURRENT_BANK_NUMBER()); 
            
            break;
#endif

        default:

            break;
    }

#else // else of #if(_3D_SUPPORT == _ON)

    // 1:1 Mode Use Different Scaling Table
    if((GET_INPUT_TIMING_HWIDTH() == _PANEL_DH_WIDTH) && (GET_INPUT_TIMING_VHEIGHT() == _PANEL_DV_HEIGHT))
    {
        ScalerMemorySetScalingCoef(tSCALE_H_1to1_COEF_TABLE[ucSharpness], tSCALE_V_COEF_TABLE[ucSharpness], _SHARPNESS_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());
    }
    else
    {
        ScalerMemorySetScalingCoef(tSCALE_H_COEF_TABLE[ucSharpness], tSCALE_V_COEF_TABLE[ucSharpness], _SHARPNESS_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());
    }
#endif // end of #if(_3D_SUPPORT == _ON)        
}

//--------------------------------------------------
// Description  : Set dithering
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustLoadDitherTable(void)
{
#if(_I_DITHER_SUPPORT == _ON)    
    // Set I-Domain Dither Table, Sequence Table and Offset Table
    ScalerColorIDitherAdjust(tDITHER_TABLE_10_TO_8_I_DOMAIN, tDITHER_SEQ_TABLE_0_I_DOMAIN, tDITHER_TEMPOFFSET_TABLE, GET_CURRENT_BANK_NUMBER());
#endif

#if(_D_DITHER_SUPPORT == _ON)
    // Set D-Domain Dither Table, Sequence Table and Offset Table
#if(_DISP_BIT_MODE == _DISP_18_BIT)
    ScalerColorDDitherAdjust(tDITHER_TABLE_10_TO_6, tDITHER_SEQ_TABLE_0, tDITHER_TEMPOFFSET_TABLE, _NULL_POINTER, GET_CURRENT_BANK_NUMBER());
#elif(_DISP_BIT_MODE == _DISP_24_BIT)
    ScalerColorDDitherAdjust(tDITHER_TABLE_10_TO_8_D_DOMAIN, tDITHER_SEQ_TABLE_0, tDITHER_TEMPOFFSET_TABLE, _NULL_POINTER, GET_CURRENT_BANK_NUMBER());
#endif
#endif // End of #if(_D_DITHER_SUPPORT == _ON)
}

#if(_VGA_SUPPORT == _ON)

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
//--------------------------------------------------
// Description  : Adjust Digital Filter Enhanced Phase Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustDigitalFilterEnhancePhase(void)
{
    BYTE ucI = 0;
    BYTE ucTemp = 0;
    BYTE ucSpan = 0;
    SWORD shTemp = 0;
    WORD usPixelRate = (ScalerSyncGetInputPixelClk() + 5) / 10;
   
    if(usPixelRate <= tDF_ENHANCE_PHASE_SETTING[0])
    {
        pData[0] = tDF_ENHANCE_PHASE_SETTING[1];
        pData[1] = tDF_ENHANCE_PHASE_SETTING[2];
        pData[2] = tDF_ENHANCE_PHASE_SETTING[3];
    }
    else if(usPixelRate >= tDF_ENHANCE_PHASE_SETTING[sizeof(tDF_ENHANCE_PHASE_SETTING) - 4])
    {
        pData[0] = tDF_ENHANCE_PHASE_SETTING[sizeof(tDF_ENHANCE_PHASE_SETTING) - 3];
        pData[1] = tDF_ENHANCE_PHASE_SETTING[sizeof(tDF_ENHANCE_PHASE_SETTING) - 2];
        pData[2] = tDF_ENHANCE_PHASE_SETTING[sizeof(tDF_ENHANCE_PHASE_SETTING) - 1];
    }
    else
    {
        for(ucI = 0; tDF_ENHANCE_PHASE_SETTING[ucI * 4] < usPixelRate; ucI++)
        {
            ;
        }

        ucI--;

        ucTemp = usPixelRate - tDF_ENHANCE_PHASE_SETTING[ucI * 4];
        ucSpan = tDF_ENHANCE_PHASE_SETTING[(ucI + 1) * 4] - tDF_ENHANCE_PHASE_SETTING[ucI * 4];
        
        shTemp = tDF_ENHANCE_PHASE_SETTING[((ucI + 1) * 4) + 1] - tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 1];
        pData[0] = tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 1] + (SWORD)ucTemp * shTemp / ucSpan;

        shTemp = tDF_ENHANCE_PHASE_SETTING[((ucI + 1) * 4) + 2] - tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 2];
        pData[1] = tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 2] + (SWORD)ucTemp * shTemp / ucSpan;

        shTemp = tDF_ENHANCE_PHASE_SETTING[((ucI + 1) * 4) + 3] - tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 3];
        pData[2] = tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 3] + (SWORD)ucTemp * shTemp / ucSpan;

    }

    ScalerColorDigitalFilterEnhancePhaseAdjust(pData);
}
#endif

#if(_RINGING_FILTER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust Ringing Filter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustRingingFilter(void)
{
    BYTE ucI = 0;
    BYTE ucTemp = 0;
    BYTE ucSpan = 0;
    SWORD shTemp = 0;
    WORD usPixelRate = (ScalerSyncGetInputPixelClk() + 5) / 10;
   
    if(usPixelRate <= tRF_OFFSET_COEF_SETTING[0])
    {
        pData[0] = tRF_OFFSET_COEF_SETTING[1];        
    }
    else if(usPixelRate >= tRF_OFFSET_COEF_SETTING[sizeof(tRF_OFFSET_COEF_SETTING) - 2])
    {
        pData[0] = tRF_OFFSET_COEF_SETTING[sizeof(tRF_OFFSET_COEF_SETTING) - 1];
    }
    else
    {
        for(ucI = 0; tRF_OFFSET_COEF_SETTING[ucI * 2] < usPixelRate; ucI++)
        {
            ;
        }

        ucI--;

        ucTemp = usPixelRate - tRF_OFFSET_COEF_SETTING[ucI * 2];
        ucSpan = tRF_OFFSET_COEF_SETTING[(ucI + 1) * 2] - tRF_OFFSET_COEF_SETTING[ucI * 2];
        
        shTemp = tRF_OFFSET_COEF_SETTING[((ucI + 1) * 2) + 1] - tRF_OFFSET_COEF_SETTING[(ucI * 2) + 1];
        pData[0] = tRF_OFFSET_COEF_SETTING[(ucI * 2) + 1] + (SWORD)ucTemp * shTemp / ucSpan;

    }
    
    ScalerColorRingingFilterAdjust(pData);
}
#endif

#endif  // End of #if(_VGA_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable IDither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustIDitherOn(void)
{
    ScalerColorIDitherOn(tDITHER_TABLE_10_TO_8_I_DOMAIN, GET_CURRENT_BANK_NUMBER());
}
#endif  // End of #if(_I_DITHER_SUPPORT == _ON)

#if(_YPEAKING_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Ypeaking Table
// Input Value  : Request Ypeaking Table
// Output Value : None
//--------------------------------------------------
void UserAdjustYpeaking(void)
{
//    ScalerColorYpeakingAdjust(_YPEAKING_TABLE_MODE, 0x00, _YPEAKING_NO_DIV, tYPEAKING_TABLE[0], _YPEAKING_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());

    ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x41, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
}
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_OD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Load OD LUT
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustODLoadLUT(void)
{
    ScalerODLoadLUT(tOD_TABLE[_OD_TABLE_COMMON], GET_CURRENT_BANK_NUMBER(), 289, _OD_TABLE_COMMON);
}
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set UltraVivid Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustUltraVivid(void)
{
    
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))  
    ScalerColorUltraVividAdjust(tCOLOR_ULTRAVIVID_SETTING_TABLE[0],
                                tCOLOR_ULTRAVIVID_SETTING_TABLE[1], 
                                tCOLOR_ULTRAVIVID_SETTING_TABLE[2],
                                tCOLOR_ULTRAVIVID_SETTING_TABLE[3],
                                tCOLOR_ULTRAVIVID_SETTING_CDS,
                                tCOLOR_ULTRAVIVID_SETTING_HSR[0],
                                GET_CURRENT_BANK_NUMBER());
#else
    ScalerColorUltraVividAdjust(tCOLOR_ULTRAVIVID_SETTING_TABLE[0],
                                tCOLOR_ULTRAVIVID_SETTING_TABLE[1], 
                                tCOLOR_ULTRAVIVID_SETTING_TABLE[2],
                                tCOLOR_ULTRAVIVID_SETTING_TABLE[3],
                                tCOLOR_ULTRAVIVID_SETTING_CDS,
                                GET_CURRENT_BANK_NUMBER());
#endif

}
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#endif//#if(_OSD_TYPE == _NONE_OSD)
