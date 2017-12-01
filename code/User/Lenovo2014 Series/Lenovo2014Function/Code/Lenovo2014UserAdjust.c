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
// ID Code      : UserAdjust.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_ADJUST__
#define __USER_PANEL__   __USER_ADJUST__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LENOVO_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _SHARPNESS_TABLE_SIZE                       128
#define _YPEAKING_TABLE_SIZE                        6

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
#define _HLWIN_TYPE5_MOVE_TIME                      SEC(0.01)
#endif

#if(_DCR_SUPPORT == _ON)//Eli 20121115 The g_usDCRBLOffCunt polling mode revised interrupt timer mode. 
#define _DCR_STEP_BUFFER     			12
#define _DCR_BACKLIGHT_PWM_MAX			255//_PWM_B100
#define _DCR_BACKLIGHT_PWM_MIN			55//_PWM_B00
#endif

//================================================||
#define _B00_09          (_PWM_B10 -_PWM_B00)/10//||
#define _B10_19          (_PWM_B20 -_PWM_B10)/10//||
#define _B20_29          (_PWM_B30 -_PWM_B20)/10//||
#define _B30_39          (_PWM_B40 -_PWM_B30)/10//||
#define _B40_49          (_PWM_B50 -_PWM_B40)/10//||
#define _B50_59          (_PWM_B60 -_PWM_B50)/10//||
#define _B60_69          (_PWM_B70 -_PWM_B60)/10//||
#define _B70_79          (_PWM_B80 -_PWM_B70)/10//||
#define _B80_89          (_PWM_B90 -_PWM_B80)/10//||
#define _B90_99          (_PWM_B100-_PWM_B90)/10//||
//================================================||

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
//----------------------------------------------------------------------------------------------------
// Backlight PWM Table
//----------------------------------------------------------------------------------------------------
BYTE code tBRIGHTNESS_PWM[101] =
{
//------0-------------1-----------------2-------------------3-------------------4-------------------5-------------------6-------------------7-------------------8-------------------9----------//|-----|                                                
    _PWM_B00, _PWM_B00+_B00_09, _PWM_B00+2*_B00_09, _PWM_B00+3*_B00_09, _PWM_B00+4*_B00_09, _PWM_B00+5*_B00_09, _PWM_B00+6*_B00_09, _PWM_B00+7*_B00_09, _PWM_B00+8*_B00_09, _PWM_B00+9*_B00_09,//|00-09|
    _PWM_B10, _PWM_B10+_B10_19, _PWM_B10+2*_B10_19, _PWM_B10+3*_B10_19, _PWM_B10+4*_B10_19, _PWM_B10+5*_B10_19, _PWM_B10+6*_B10_19, _PWM_B10+7*_B10_19, _PWM_B10+8*_B10_19, _PWM_B10+9*_B10_19,//|10-19|
    _PWM_B20, _PWM_B20+_B20_29, _PWM_B20+2*_B20_29, _PWM_B20+3*_B20_29, _PWM_B20+4*_B20_29, _PWM_B20+5*_B20_29, _PWM_B20+6*_B20_29, _PWM_B20+7*_B20_29, _PWM_B20+8*_B20_29, _PWM_B20+9*_B20_29,//|20-29|
    _PWM_B30, _PWM_B30+_B30_39, _PWM_B30+2*_B30_39, _PWM_B30+3*_B30_39, _PWM_B30+4*_B30_39, _PWM_B30+5*_B30_39, _PWM_B30+6*_B30_39, _PWM_B30+7*_B30_39, _PWM_B30+8*_B30_39, _PWM_B30+9*_B30_39,//|30-39|
    _PWM_B40, _PWM_B40+_B40_49, _PWM_B40+2*_B40_49, _PWM_B40+3*_B40_49, _PWM_B40+4*_B40_49, _PWM_B40+5*_B40_49, _PWM_B40+6*_B40_49, _PWM_B40+7*_B40_49, _PWM_B40+8*_B40_49, _PWM_B40+9*_B40_49,//|40-49|
    _PWM_B50, _PWM_B50+_B50_59, _PWM_B50+2*_B50_59, _PWM_B50+3*_B50_59, _PWM_B50+4*_B50_59, _PWM_B50+5*_B50_59, _PWM_B50+6*_B50_59, _PWM_B50+7*_B50_59, _PWM_B50+8*_B50_59, _PWM_B50+9*_B50_59,//|50-59|
    _PWM_B60, _PWM_B60+_B60_69, _PWM_B60+2*_B60_69, _PWM_B60+3*_B60_69, _PWM_B60+4*_B60_69, _PWM_B60+5*_B60_69, _PWM_B60+6*_B60_69, _PWM_B60+7*_B60_69, _PWM_B60+8*_B60_69, _PWM_B60+9*_B60_69,//|60-69|
    _PWM_B70, _PWM_B70+_B70_79, _PWM_B70+2*_B70_79, _PWM_B70+3*_B70_79, _PWM_B70+4*_B70_79, _PWM_B70+5*_B70_79, _PWM_B70+6*_B70_79, _PWM_B70+7*_B70_79, _PWM_B70+8*_B70_79, _PWM_B70+9*_B70_79,//|70-79|
    _PWM_B80, _PWM_B80+_B80_89, _PWM_B80+2*_B80_89, _PWM_B80+3*_B80_89, _PWM_B80+4*_B80_89, _PWM_B80+5*_B80_89, _PWM_B80+6*_B80_89, _PWM_B80+7*_B80_89, _PWM_B80+8*_B80_89, _PWM_B80+9*_B80_89,//|80-89|
    _PWM_B90, _PWM_B90+_B90_99, _PWM_B90+2*_B90_99, _PWM_B90+3*_B90_99, _PWM_B90+4*_B90_99, _PWM_B90+5*_B90_99, _PWM_B90+6*_B90_99, _PWM_B90+7*_B90_99, _PWM_B90+8*_B90_99, _PWM_B90+9*_B90_99,//|90-99|
    _PWM_B100,                                                                                                                                                                                 //|100  |
//------0-------------1-----------------2-------------------3-------------------4-------------------5-------------------6-------------------7-------------------8-------------------9----------//|-----|                                                
};

//----------------------------------------------------------------------------------------------------
// Filter Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
WORD code tOverscanEnTable[][3] =
{
    // VFreq, HWidth, VHeight, 
    {600,  640,  480},    // 480p
    {600,  720,  480},    // 480p
    {600,  960,  480},    // 480p
    {600, 1440,  480},    // 480p    
    
    {500,  720,  576},    // 576p
    {500,  768,  576},    // 576p
    {500,  960,  576},    // 576p
    {500, 1280,  576},    // 576p
    {500, 1440,  576},    // 576p
    {500, 1280,  720},    // 720p
    {600, 1280,  720},    // 720p
    {500, 1920,  1080},   // 1080p
    {600, 1920,  1080},   // 1080p

    // Don't delete it, and place it at last.
    {  0,    0,    0},
};

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

#if(_RINGING_FILTER_SUPPORT == _ON)//Eli 20130102 Update New STD Code Kernel.
//----------------------------------------------------------------------------------------------------
// RINGING FILTER OFFSET COEFFICIENT TABLE
//----------------------------------------------------------------------------------------------------
#include "RingingFilterTable.h"

#endif  // End of #if(_RINGING_FILTER_SUPPORT == _ON)

#endif  // End of #if(_VGA_SUPPORT == _ON)

#if(_OGC_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// Gamma Index for OGC
//----------------------------------------------------------------------------------------------------
WORD code tGAMMA_OSD_INDEX[] = 
{
    _OGC_GAMMA1_ADDRESS,
    _OGC_GAMMA2_ADDRESS,
    _OGC_GAMMA3_ADDRESS,
    
#if(_OGC_TOTAL_GAMMA == 5)
    _OGC_GAMMA4_ADDRESS,
    _OGC_GAMMA5_ADDRESS,
#endif

};

#endif  // End of #if(_OGC_SUPPORT == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// ULTRAVIVID TABLE
//----------------------------------------------------------------------------------------------------
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
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
bit bHLWinRLMove = _RIGHT;
WORD usHLWinHPos = 0;
WORD usHLWinHWidth = 0;
WORD usHLWinVPos = 0;
WORD usHLWinVHeight = 0;
#endif

#if(_DCR_SUPPORT == _ON)//Eli 20121115 The g_usDCRBLOffCunt polling mode revised interrupt timer mode. 
WORD code tDcrStep[] = {0,48,96,144,288,336,576,672,1000};
BYTE code tBacklightStep[] = {0,50,220,230,230,240,240,255,255};

BYTE g_DcrStep = 0;
BYTE g_ucDCRTimer = 0;
BYTE g_ucPreDCRPWM = 0;
#if(_DCR_PANEL_ON_OFF == _ON)  
BYTE g_ucDCRBLOffPWM = 0xFF;
WORD g_usDCRBLOffCunt = 0;
bit g_bDCRBLOffStart = 0;
#endif
#endif

//20141125 Abel
#if(_AUTO_POWER_DOWN == _ON)
DWORD g_usDisPlayCunt = 0;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_OVERSCAN_SUPPORT == _ON)
bit UserAdjustCheckOverScan(void);
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
void UserAdjustSelectAspectRatio(void);
bit UserCheckAspectRatioFunction(void);
#endif

void UserAdjustContrast(BYTE ucContrast);
void UserAdjustBacklightPercent(BYTE ucValue);
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

#if(_GAMMA_FUNCTION == _ON)
void UserAdjustGamma(BYTE ucGamma);
#endif

#if(_PCM_FUNCTION == _ON)
void UserAdjustPCM(BYTE ucPCM);
#endif

#if(_ICM_SUPPORT == _ON)
void UserAdjustICM(BYTE ucColorEffect);
#endif

#if(_DCC_FUNCTION == _ON)
void UserAdjustDCC(BYTE ucColorEffect);
#endif // End of #if(_DCC_FUNCTION == _ON)

#if(_YPEAKING_SUPPORT == _ON)
void UserAdjustYpeaking(void);
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
void UserAdjustHighLightWindowEffectSpace(void);
void UserAdjustHLWinType(BYTE ucHLWinType);
void UserAdjustHLWinType5Move(void);
#endif

#if(_AUDIO_SUPPORT == _ON)
void UserAdjustAudioMuteSwitch(void);
void UserAdjustAudioVolume(BYTE ucVolume);
WORD UserAdjustAudioVolumeMapping(BYTE ucVolume);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
void UserAdjustAudioSource(void);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if(_OD_SUPPORT == _ON)
void UserAdjustODLoadLUT(void);
#endif

#if(_ULTRA_VIVID_SUPPORT)
void UserAdjustUltraVivid(void);
#endif

#if(_USER_DCR_FUNCTION == _ON)
void UserAdjustDCRControl(bit bEn);
void UserAdjustDCRPwm(BYTE ucPwmValue);
void UserAdjustDCRMeasure(void);
#endif

#if(_ENERGY_STAR_SUPPORT == _ON)//lorimiao 20131218 for ES6.0 test
void UserAdjustESBacklight(void);
#endif//#if(_ENERGY_STAR_SUPPORT == _ON)


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
    bit bDoOverScan = _FALSE;
    BYTE ucTemp = 0;
    
#if(_3D_SUPPORT == _ON)

    if((GET_OSD_OVERSCAN_STATUS() == _OFF) || ((GET_OSD_3D_STATUS() == _3D_ON) && (Scaler3DGetInputFormat() != _NO_3D_FORMAT)))
    {
        return _FALSE;
    }
#else
    if(GET_OSD_OVERSCAN_STATUS() == _OFF)
    {
        return _FALSE;
    }
#endif // End of #if(_3D_SUPPORT == _ON)

    // Decide whether to do over scan
    switch(SysSourceGetSourceType())
    {
#if(_OVERSCAN_VGA_SUPPORT == _ON)           
        case _SOURCE_VGA:
            
            // Interlaced and YUV Timing Always do overscan
            if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
            {
                bDoOverScan = _TRUE;
                break;
            }

            if(GET_VGA_COLOR_FORMAT_STATUS() == _COLOR_SPACE_RGB)
            {
                break;
            }

            while(tOverscanEnTable[ucTemp][0] != 0)
            {
                if((abs(GET_INPUT_TIMING_VFREQ() - tOverscanEnTable[ucTemp][0]) < 10) && \
                    (abs(GET_INPUT_TIMING_HWIDTH() - tOverscanEnTable[ucTemp][1]) < 2) && \
                    (GET_INPUT_TIMING_VHEIGHT() == tOverscanEnTable[ucTemp][2]))
                {
                    bDoOverScan = _TRUE;
                    break;
                }

                ucTemp++;
            }

            break;
#endif

#if((_OVERSCAN_DVI_SUPPORT == _ON) || (_OVERSCAN_HDMI_SUPPORT == _ON) || (_OVERSCAN_DP_SUPPORT == _ON))
#if(_OVERSCAN_DVI_SUPPORT == _ON)
        case _SOURCE_DVI:
#endif

#if(_OVERSCAN_HDMI_SUPPORT == _ON)
        case _SOURCE_HDMI:
#endif

#if((_DP_SUPPORT == _ON) && (_OVERSCAN_DP_SUPPORT == _ON))
        case _SOURCE_DP:
#endif
            // Interlaced and YUV Timing Always do overscan
            if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
            {
                bDoOverScan = _TRUE;
                break;
            }

            if(ScalerColorGetColorSpace() == _COLOR_SPACE_RGB)
            {
                break;
            }

            while(tOverscanEnTable[ucTemp][0] != 0)
            {
                if((abs(GET_INPUT_TIMING_VFREQ() - tOverscanEnTable[ucTemp][0]) < 10) && \
                    (abs(GET_INPUT_TIMING_HWIDTH() - tOverscanEnTable[ucTemp][1]) < 2) && \
                    (GET_INPUT_TIMING_VHEIGHT() == tOverscanEnTable[ucTemp][2]))
                {
                    bDoOverScan = _TRUE;
                    break;
                }

                ucTemp++;
            }

            break;
#endif

        default:

            break;
    }

    return bDoOverScan;
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
    SET_OSD_DO_ASPECT_RATIO(_TRUE);
    
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    ScalerMDomainAspectOriginMode(_FALSE);
#endif

    switch(GET_OSD_ASPECT_RATIO_TYPE())
    {
        // jimmy 20120813
		case _ASPECT_RATIO_OFF:
	
            // Calculate H Width
            PDATA_WORD(0) = (DWORD)_PANEL_DV_HEIGHT * GET_INPUT_TIMING_HWIDTH() / GET_INPUT_TIMING_VHEIGHT();
            PDATA_WORD(0) += (PDATA_WORD(0) % 4);            

            if(PDATA_WORD(0) <= _PANEL_DH_WIDTH)
            {
                // Calculate H Start
                PDATA_WORD(1) = GET_MDOMAIN_OUTPUT_HSTART() + ((GET_MDOMAIN_OUTPUT_HWIDTH() - PDATA_WORD(0)) >> 1);

                // Set H Start
                SET_MDOMAIN_OUTPUT_HSTART(PDATA_WORD(1));
            }
            else
            {
                SET_OSD_DO_ASPECT_RATIO(_FALSE);
            }
			break;
        
        case _ASPECT_RATIO_16_BY_9:
            
            // Calculate H Width
            PDATA_WORD(0) = _PANEL_DV_HEIGHT * 16 / 9;
            PDATA_WORD(0) -= (PDATA_WORD(0) & 0x01);            

            if(PDATA_WORD(0) <= _PANEL_DH_WIDTH)
            {
                // Calculate H Start
                PDATA_WORD(1) = GET_MDOMAIN_OUTPUT_HSTART() + ((GET_MDOMAIN_OUTPUT_HWIDTH() - PDATA_WORD(0)) >> 1);

                // Set H Start
                SET_MDOMAIN_OUTPUT_HSTART(PDATA_WORD(1));
            }
            else
            {
                SET_OSD_DO_ASPECT_RATIO(_FALSE);
            }
            break;
            
        case _ASPECT_RATIO_4_BY_3:

            // Calculate H Width
            PDATA_WORD(0) = _PANEL_DV_HEIGHT * 4 / 3;
            PDATA_WORD(0) -= (PDATA_WORD(0) & 0x01);   
            
            if(PDATA_WORD(0) <= _PANEL_DH_WIDTH)
            {
                // Calculate H Start
                PDATA_WORD(1) = GET_MDOMAIN_OUTPUT_HSTART() + ((GET_MDOMAIN_OUTPUT_HWIDTH() - PDATA_WORD(0)) >> 1);

                // Set H Start
                SET_MDOMAIN_OUTPUT_HSTART(PDATA_WORD(1));
            }
            else
            {
                SET_OSD_DO_ASPECT_RATIO(_FALSE);
            }
            break;
            
        case _ASPECT_RATIO_5_BY_4:

            // Calculate H Width
            PDATA_WORD(0) = _PANEL_DV_HEIGHT * 5 / 4;
            PDATA_WORD(0) -= (PDATA_WORD(0) & 0x01);       
            
            if(PDATA_WORD(0) <= _PANEL_DH_WIDTH)
            {
                // Calculate H Start
                PDATA_WORD(1) = GET_MDOMAIN_OUTPUT_HSTART() + ((GET_MDOMAIN_OUTPUT_HWIDTH() - PDATA_WORD(0)) >> 1);

                // Set H Start
                SET_MDOMAIN_OUTPUT_HSTART(PDATA_WORD(1));
            }
            else
            {
                SET_OSD_DO_ASPECT_RATIO(_FALSE);
            }
            break;
            
#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        case _ASPECT_RATIO_ORIGIN:
            
            ScalerMDomainAspectOriginMode(_TRUE);

#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

#if(_3D_SUPPORT == _ON)
            if(Scaler3DTxInputFormat() == _FRAME_PACKING)
            {
                // Consider V Height
                switch(GET_INPUT_TIMING_VHEIGHT())
                {
                    case 1201: // 576p
                    case 1226: // 576i
                        PDATA_WORD(1) = 576;
                        break;

                    case 1005: // 480p
                    case 1028: // 480i
                        PDATA_WORD(1) = 576;
                        break;

                    case 1470: // 720p
                        PDATA_WORD(1) = 720;
                        break;
                        
                    case 2205: // 1080p
                    case 2228: // 1080i
                        PDATA_WORD(1) = 1080;
                        break;

                    default:
                        PDATA_WORD(1) = GET_MDOMAIN_INPUT_VHEIGHT();
                        break;
                }
            }
            else
            {
                PDATA_WORD(1) = GET_MDOMAIN_INPUT_VHEIGHT();
            }
#else
            PDATA_WORD(1) = GET_MDOMAIN_INPUT_VHEIGHT();
#endif
            // Consider Panel Height and Input Height
            if(GET_MDOMAIN_OUTPUT_VHEIGHT() > PDATA_WORD(1))
            {
                PDATA_WORD(0) = GET_MDOMAIN_OUTPUT_VHEIGHT() - PDATA_WORD(1);
                SET_MDOMAIN_OUTPUT_VSTART(GET_MDOMAIN_OUTPUT_VSTART() + (PDATA_WORD(0) >> 1));
                SET_MDOMAIN_OUTPUT_VHEIGHT(PDATA_WORD(1));
            }

            // Consider Panel Width and Input Width
            if(GET_MDOMAIN_OUTPUT_HWIDTH() > GET_MDOMAIN_INPUT_HWIDTH())
            {
                PDATA_WORD(0) = GET_MDOMAIN_OUTPUT_HWIDTH() - GET_MDOMAIN_INPUT_HWIDTH();                
                SET_MDOMAIN_OUTPUT_HSTART(GET_MDOMAIN_OUTPUT_HSTART() + (PDATA_WORD(0) >> 1));                
                SET_MDOMAIN_OUTPUT_HWIDTH(GET_MDOMAIN_INPUT_HWIDTH());
            }
            
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))

            break;

#endif // End of #if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)

        case _ASPECT_RATIO_FULL:
        default:

            PDATA_WORD(0) = _PANEL_DH_WIDTH;
            
			break;
    }

    
    // Only Modify HWidth When Target is Smaller than Panel Define
    if((PDATA_WORD(0) <= _PANEL_DH_WIDTH) && (GET_OSD_ASPECT_RATIO_TYPE() != _ASPECT_RATIO_ORIGIN))
    {
        SET_MDOMAIN_OUTPUT_HWIDTH(PDATA_WORD(0));
    }

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)//lorimiao 20130924 for OSD NovoVision .Scaling issue
	if(GET_NOVO_VISION_STATUS() == _NOVO_VISION_SPLIT)
	    UserAdjustHLWinType(_HL_WIN_2);
#endif    
}



//20121018_0 Abel Aspect Ratio Requirement Modify
bit UserCheckAspectRatioFunction(void)
{	 
    //判斷條件...(width*10)/ height < (PanelWidth*10) /PanelHeight
	if( ((DWORD)GET_INPUT_TIMING_HWIDTH() * 1000) /((DWORD)GET_INPUT_TIMING_VHEIGHT() ) < ((DWORD)_PANEL_DH_WIDTH * 1000)/((DWORD)_PANEL_DV_HEIGHT))
	{                
		return _TRUE;	        
	}
	else
	{               
		return _FALSE;	
	}	
}

#endif // End of #if(_ASPECT_RATIO_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Adjust color processing contrast
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if((_FACTORY_MODE_OWNER == _OWNER_TPV)||(_FACTORY_MODE_OWNER == _OWNER_WISTRON))
#define CONTRAST_RATIO_HI   (((WORD)ucContrast-_OSD_CONTRAST_DEF_VALUE)*(MAX_CONTRAST_RATIO-DEF_CONTRAST_RATIO)/(100-_OSD_CONTRAST_DEF_VALUE)+DEF_CONTRAST_RATIO)
#define CONTRAST_RATIO_LO   ((WORD)ucContrast*(DEF_CONTRAST_RATIO-MIN_CONTRAST_RATIO)/(_OSD_CONTRAST_DEF_VALUE)+MIN_CONTRAST_RATIO)

void UserAdjustContrast(BYTE ucContrast)
{
    if(ucContrast>= _OSD_CONTRAST_DEF_VALUE)
    {
        pData[0] = (((WORD)g_stColorProcData.ucColorTempR)*CONTRAST_RATIO_HI/100);
        pData[1] = (((WORD)g_stColorProcData.ucColorTempG)*CONTRAST_RATIO_HI/100);
        pData[2] = (((WORD)g_stColorProcData.ucColorTempB)*CONTRAST_RATIO_HI/100);
    }
    else
    {
        pData[0] = (((WORD)g_stColorProcData.ucColorTempR)*CONTRAST_RATIO_LO/100);
        pData[1] = (((WORD)g_stColorProcData.ucColorTempG)*CONTRAST_RATIO_LO/100);
        pData[2] = (((WORD)g_stColorProcData.ucColorTempB)*CONTRAST_RATIO_LO/100);
    }
    if(pData[0]>255)
    {
       pData[0]=255;
    }
    if(pData[1]>255)
    {
       pData[1]=255;
    }
    if(pData[2]>255)
    {
       pData[2]=255;
    }
    
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    pData[3] = 0x80;
    pData[4] = 0x80;
    pData[5] = 0x80;
#endif

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    if(GET_OSD_HLWIN_TYPE() == _HL_WIN_OFF)
    {
        ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);
        ScalerColorBriConSetCoef(_CONTRAST_COEF_B, &pData[3]);
    }
    else
    {
        ScalerColorBriConSetCoef(_CONTRAST_COEF_B, pData);
        ScalerColorBriConSetCoef(_CONTRAST_COEF_A, &pData[3]);
    }
#else
    ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);
#endif

}
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
void UserAdjustContrast(BYTE ucContrast)
{
	if(SysSourceGetSourceType() == _SOURCE_VGA)  
        ucContrast = (_OSD_CONTRAST_DEF_VALUE > ucContrast) ? _CONTRAST_MIN_ANALOG + (WORD)(ucContrast) * (_CONTRAST_CHANG_POINT_ANALOG-_CONTRAST_MIN_ANALOG)/_OSD_CONTRAST_DEF_VALUE : _CONTRAST_CHANG_POINT_ANALOG+((WORD)(_CONTRAST_MAX_ANALOG - _CONTRAST_CHANG_POINT_ANALOG)*(ucContrast-_OSD_CONTRAST_DEF_VALUE)/(100 - _OSD_CONTRAST_DEF_VALUE));
    else    
        ucContrast = (_OSD_CONTRAST_DEF_VALUE > ucContrast) ? _CONTRAST_MIN_DIGITAL + (WORD)(ucContrast) * (_CONTRAST_CHANG_POINT_DIGITAL-_CONTRAST_MIN_DIGITAL)/_OSD_CONTRAST_DEF_VALUE : _CONTRAST_CHANG_POINT_DIGITAL+((WORD)(_CONTRAST_MAX_DIGITAL -_CONTRAST_CHANG_POINT_DIGITAL)*(ucContrast-_OSD_CONTRAST_DEF_VALUE)/(100 - _OSD_CONTRAST_DEF_VALUE));

    pData[0] = (((WORD)g_stColorProcData.ucColorTempR)*ucContrast/100);
    pData[1] = (((WORD)g_stColorProcData.ucColorTempG)*ucContrast/100);
    pData[2] = (((WORD)g_stColorProcData.ucColorTempB)*ucContrast/100);
   
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    pData[3] = 0x80;
    pData[4] = 0x80;
    pData[5] = 0x80;
#endif

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    if(GET_OSD_HLWIN_TYPE() == _HL_WIN_OFF)
    {
        ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);
        ScalerColorBriConSetCoef(_CONTRAST_COEF_B, &pData[3]);
    }
    else
    {
        ScalerColorBriConSetCoef(_CONTRAST_COEF_B, pData);
        ScalerColorBriConSetCoef(_CONTRAST_COEF_A, &pData[3]);
    }
#else
    ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);
#endif

}
#endif


#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON) 
BYTE UserAdjustBacklightChangeRange(BYTE ucValue)
{
	if(ucValue > _BACKLIGHT_DEF)//Backlight default value = 80
		ucValue = (WORD)((100 - GET_OSD_SUBBRIHTNESS()) * (ucValue - _BACKLIGHT_DEF)) / (100 - _BACKLIGHT_DEF) + GET_OSD_SUBBRIHTNESS();
	else
		ucValue = (WORD)(GET_OSD_SUBBRIHTNESS() * ucValue) / _BACKLIGHT_DEF;

     ucValue = UserCommonAdjustPercentToRealValue(ucValue, _BACKLIGHT_PWM_MAX, _BACKLIGHT_PWM_MIN,_BACKLIGHT_PWM_CENTER);
     
     return(ucValue); 
}
#endif
//--------------------------------------------------
// Description  : Adjust backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustBacklight(BYTE ucBacklight)
{
    // Adjust backlight by changing PWM duty    
#if(_BACKLIGHT_PWM_INVERSE == _ON)
    ucBacklight = _BACKLIGHT_MAX - UserCommonAdjustPercentToRealValue(ucBacklight,_BACKLIGHT_MAX,_BACKLIGHT_MIN,_BACKLIGHT_CENTER);
#else
    ucBacklight = UserCommonAdjustPercentToRealValue(ucBacklight,_BACKLIGHT_MAX,_BACKLIGHT_MIN,_BACKLIGHT_CENTER);
#endif
    PCB_BACKLIGHT_PWM(ucBacklight);
}

//--------------------------------------------------
// Description  : Adjust Backlight Percent
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustBacklightPercent(BYTE ucValue)
{
    UserAdjustBacklight(ucValue);
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
    pData[3] = 0x80;
    pData[4] = 0x80;
    pData[5] = 0x80;
#endif

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    if(GET_OSD_HLWIN_TYPE() == _HL_WIN_OFF)
    {
        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_A, pData);
        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_B, &pData[3]);
    }
    else
    {
        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_B, pData);
        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_A, &pData[3]);
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
#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    if(GET_OSD_3D_FORMAT_STATUS() == _3D_MODE_FORMAT_LINE_INTERLACE)
    {
        ScalerColorIDitherAdjust(tDITHER_TABLE_10_TO_8_I_DOMAIN_FOR_PR, tDITHER_SEQ_TABLE_0_I_DOMAIN, tDITHER_TEMPOFFSET_TABLE, GET_CURRENT_BANK_NUMBER());    
    }
    else
#endif
    {
        ScalerColorIDitherAdjust(tDITHER_TABLE_10_TO_8_I_DOMAIN, tDITHER_SEQ_TABLE_0_I_DOMAIN, tDITHER_TEMPOFFSET_TABLE, GET_CURRENT_BANK_NUMBER());    
    }

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
#endif

#if(_GAMMA_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust Gamma
// Input Value  : Gamma type
// Output Value : None
//--------------------------------------------------
void UserAdjustGamma(BYTE ucGamma)
{
    if(ucGamma != _GAMMA_OFF)
    {
        
#if(_OGC_SUPPORT == _ON)
        ScalerColorOutputGammaAdjust(&DISP_CALIBRATION_FLASH[tGAMMA_OSD_INDEX[ucGamma]], _OGC_FLASH_BANK);
        RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
        UserAdjustContrast(GET_OSD_CONTRAST());
#else
        ScalerColorOutputGammaAdjust(tGAMMA_TABLE[ucGamma], GET_CURRENT_BANK_NUMBER());
#endif

    }
}
#endif // End of #if(_GAMMA_FUNCTION == _ON)

#if(_PCM_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust PCM
// Input Value  : PCM type
// Output Value : None
//--------------------------------------------------
void UserAdjustPCM(BYTE ucPCM)
{
    if(ucPCM != _PCM_OSD_NATIVE)
    {

#if(_OCC_SUPPORT == _ON)
        if(ucPCM == _PCM_OSD_SRGB)
        {
            ScalerColorPCMAdjust(_PCM_SRGB, _NULL_POINTER, &DISP_CALIBRATION_FLASH[_OCC_GAMMA10_ADDRESS], &DISP_CALIBRATION_FLASH[_OCC_SRGBMATRIX_ADDRESS], _OGC_FLASH_BANK);
        }
        else if(ucPCM == _PCM_OSD_ADOBE_RGB)
        {
            ScalerColorPCMAdjust(_PCM_ADOBE_RGB, _NULL_POINTER, &DISP_CALIBRATION_FLASH[_OCC_GAMMA10_ADDRESS], &DISP_CALIBRATION_FLASH[_OCC_ADOBEMATRIX_ADDRESS], _OGC_FLASH_BANK);
        }
        else
#endif
        {
            ScalerColorPCMAdjust(_PCM_USER_MODE, tPCM_USER_TABLE[(ucPCM - _PCM_OSD_USER) * 3], tPCM_USER_TABLE[((ucPCM - _PCM_OSD_USER) * 3) + 1], tPCM_USER_TABLE[((ucPCM - _PCM_OSD_USER) * 3) + 2], GET_CURRENT_BANK_NUMBER());
        }

    }
}
#endif  // End of #if(_PCM_FUNCTION == _ON)

#if(_ICM_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust ICM
// Input Value  : Gamma type
// Output Value : None
//--------------------------------------------------
void UserAdjustICM(BYTE ucColorEffect)
{
    BYTE ucI = 0;

    if((ucColorEffect != _COLOREFFECT_STANDARD) && (ucColorEffect != _COLOREFFECT_USER))
    {
        ScalerColorICMAdjust(tICM_CONTROL[ucColorEffect]);

        for(ucI = 0; ucI < 6; ucI++)
        {    
            ScalerColorICMLoadTable(tICM_TABLE[ucColorEffect * 6 + ucI], GET_CURRENT_BANK_NUMBER(), ucI);
        }
    }
}
#endif

#if(_DCC_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Set DCC Table
// Input Value  : Request DCC Table
// Output Value : None
//--------------------------------------------------
void UserAdjustDCC(BYTE ucColorEffect)
{
    if((ucColorEffect != _COLOREFFECT_STANDARD) && (ucColorEffect != _COLOREFFECT_USER))
    {
        ScalerColorDCCAdjust(tDCC_TABLE[ucColorEffect], GET_CURRENT_BANK_NUMBER(), 0x00);
    }
}
#endif // End of #if(_DCC_FUNCTION == _ON)

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

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust All High Light Window Effect Space
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustHighLightWindowEffectSpace(void)
{
    ScalerColorHLWBriConAdjust(_BRI_CON_B_ON_INSIDE_WINDOW);

#if(_GAMMA_FUNCTION == _ON)
    ScalerColorHLWOutputGammaAdjust(_INSIDE_WINDOW);
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
    ScalerColorHLWSRGBAdjust(_INSIDE_WINDOW);
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if((_ICM_SUPPORT == _ON) || (_DCC_FUNCTION == _ON))
    ScalerColorHLWICMDCCAdjust(_INSIDE_WINDOW);
#endif

#if(_YPEAKING_SUPPORT == _ON)    
    ScalerColorHLWYpeakingAdjust(_INSIDE_WINDOW);
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_DCR_SUPPORT == _ON)
    ScalerColorHLWDCRAdjust(_INSIDE_WINDOW);    
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
    ScalerColorHLWUltraVividAdjust(_INSIDE_WINDOW);
#endif

}

//--------------------------------------------------
// Description  : Adjust High Light Window
// Input Value  : HLWinType
// Output Value : None
//--------------------------------------------------
void UserAdjustHLWinType(BYTE ucHLWinType)
{
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_HLWIN_TYPE5_MOVE);

    if(ucHLWinType == _HL_WIN_OFF)
    {
        return;
    }

    if(GET_MDOMAIN_OUTPUT_HWIDTH() == _PANEL_DH_WIDTH)
    {
        usHLWinHPos = 0;
    }
    else
    {
        usHLWinHPos = (_PANEL_DH_WIDTH - GET_MDOMAIN_OUTPUT_HWIDTH()) / 2;
    }
    
    if(GET_MDOMAIN_OUTPUT_VHEIGHT() == _PANEL_DV_HEIGHT)
    {
        usHLWinVPos = 0;
    }
    else
    {
        usHLWinVPos = (_PANEL_DV_HEIGHT - GET_MDOMAIN_OUTPUT_VHEIGHT()) / 2;
    }

    switch(ucHLWinType)
    {
        case _HL_WIN_1:
            
            usHLWinHWidth = GET_MDOMAIN_OUTPUT_HWIDTH() - _HL_WIN_BORDER_SIZE;
            usHLWinVHeight = GET_MDOMAIN_OUTPUT_VHEIGHT() - _HL_WIN_BORDER_SIZE;
            
            break;

        case _HL_WIN_2:

            usHLWinHWidth = GET_MDOMAIN_OUTPUT_HWIDTH() / 2;
            usHLWinVHeight = GET_MDOMAIN_OUTPUT_VHEIGHT() - _HL_WIN_BORDER_SIZE;
			
		    if(GET_MDOMAIN_OUTPUT_HWIDTH() == _PANEL_DH_WIDTH)//lorimiao 20130924 for OSD NovoVision .Scaling issue
		    {
		        usHLWinHPos = _PANEL_DH_WIDTH/2;
		    }
		    else
		    {
		        usHLWinHPos = usHLWinHWidth + (_PANEL_DH_WIDTH - GET_MDOMAIN_OUTPUT_HWIDTH()) / 2;
		    }

            break;

        case _HL_WIN_3:
            
            usHLWinHWidth = GET_MDOMAIN_OUTPUT_HWIDTH() - _HL_WIN_BORDER_SIZE;
            usHLWinVHeight = GET_MDOMAIN_OUTPUT_VHEIGHT() / 2;
            
            break;

        case _HL_WIN_4:
            
            usHLWinHWidth = GET_MDOMAIN_OUTPUT_HWIDTH() / 2;
            usHLWinVHeight = GET_MDOMAIN_OUTPUT_VHEIGHT() / 2;
            usHLWinHPos += (GET_MDOMAIN_OUTPUT_HWIDTH() - usHLWinHWidth) / 2; 
            usHLWinVPos += (GET_MDOMAIN_OUTPUT_VHEIGHT() - usHLWinVHeight) / 2;
            
            break;  
            
        case _HL_WIN_5:
            
            usHLWinHWidth = GET_MDOMAIN_OUTPUT_HWIDTH() / 6;
            usHLWinVHeight = GET_MDOMAIN_OUTPUT_VHEIGHT() - _HL_WIN_BORDER_SIZE;
            usHLWinHPos += (GET_MDOMAIN_OUTPUT_HWIDTH() - usHLWinHWidth) / 2;

            ScalerTimerActiveTimerEvent(_HLWIN_TYPE5_MOVE_TIME, _USER_TIMER_EVENT_HLWIN_TYPE5_MOVE);    

            break;

        default:

            break;
    }

    ScalerColorHLWAdjust(usHLWinHPos, usHLWinHWidth, usHLWinVPos, usHLWinVHeight);
}

//--------------------------------------------------
// Description  : High Light Window Type5 Move
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustHLWinType5Move(void)
{
    if(bHLWinRLMove == _RIGHT)
    {
        usHLWinHPos++;        

        if(GET_MDOMAIN_OUTPUT_HWIDTH() + ((_PANEL_DH_WIDTH - GET_MDOMAIN_OUTPUT_HWIDTH()) / 2) <
            (usHLWinHPos + usHLWinHWidth + _HL_WIN_BORDER_SIZE))
        {
            bHLWinRLMove = _LEFT;
            usHLWinHPos = GET_MDOMAIN_OUTPUT_HWIDTH() + ((_PANEL_DH_WIDTH - GET_MDOMAIN_OUTPUT_HWIDTH()) / 2) - (usHLWinHWidth + _HL_WIN_BORDER_SIZE) + 1;
        }
    }
    else // _LEFT
    {
        usHLWinHPos--;        

        if(usHLWinHPos <= ((_PANEL_DH_WIDTH - GET_MDOMAIN_OUTPUT_HWIDTH()) >> 1) + 1)
        {
            bHLWinRLMove = _RIGHT;
            usHLWinHPos = ((_PANEL_DH_WIDTH - GET_MDOMAIN_OUTPUT_HWIDTH()) >> 1);
        }
    }

    ScalerColorHLWAdjust(usHLWinHPos, usHLWinHWidth, usHLWinVPos, usHLWinVHeight);

    ScalerTimerActiveTimerEvent(_HLWIN_TYPE5_MOVE_TIME, _USER_TIMER_EVENT_HLWIN_TYPE5_MOVE);    
}


#endif // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if(_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Mute/Unmute Aduio Volume
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void UserAdjustAudioMuteSwitch(void)
{            
    SysAudioMuteProc(UserInterfaceGetAudioMute());
}

//--------------------------------------------------
// Description  : Adjust Aduio Volume
// Input Value  : ucVolume
// Output Value : Node
//--------------------------------------------------
//輸入Audio聲音大小調整
void UserAdjustAudioVolume(BYTE ucVolume)
{    

#if(_AUDIO_EXTERNAL_AMP_SUPPORT == _ON)

	#if(_AUDIO_VOLUME_PWM_INVERSE == _OFF)
	PCB_AUDIO_VOLUME_PWM(UserAdjustAudioVolumeMapping(ucVolume));
	#else
    PCB_AUDIO_VOLUME_PWM(0xFF - (BYTE)UserAdjustAudioVolumeMapping(ucVolume)); 
	#endif
	
#else

	#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(UserInterfaceGetAudioSource() == _ANALOG_AUDIO)
    {
        ScalerAudioAnalogAdjustVolume(UserAdjustAudioVolumeMapping(ucVolume), _AUDIO_FROM_AIN);
    }
    else
	#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
    {
        ScalerAudioDigitalAdjustVolume(UserAdjustAudioVolumeMapping(ucVolume));
    }
		
#endif

}

//--------------------------------------------------
// Description  : OSD Volume Mapping to Real Value
// Input Value  : usVolume
// Output Value : usVolume
//--------------------------------------------------
WORD UserAdjustAudioVolumeMapping(BYTE ucVolume)
{ 
#if(_AUDIO_EXTERNAL_AMP_SUPPORT == _ON)
	return (UserCommonAdjustPercentToRealValue(ucVolume, _VOLUME_MAX, _VOLUME_MIN, (_VOLUME_MAX - _VOLUME_MIN)/2));
#else
	#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(UserInterfaceGetAudioSource() == _ANALOG_AUDIO)
    {
        return(UserCommonAdjustPercentToRealValue(ucVolume, _ANALOG_VOLUME_MAX, _ANALOG_VOLUME_MIN, _ANALOG_VOLUME_CENTER));
    }
    else
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)        
    {
        return(UserCommonAdjustPercentToRealValue(ucVolume, _DIGITAL_VOLUME_MAX, _DIGITAL_VOLUME_MIN, _DIGITAL_VOLUME_CENTER));
    }
#endif
}

#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Select Aduio Source
// Input Value  : _ANALOG_AUDIO or _DIGITAL_AUDIO
// Output Value : Node
//--------------------------------------------------
void UserAdjustAudioSource(void)
{   
    WORD usVolume = 0;
       
    if((SysSourceGetSourceType() == _SOURCE_HDMI) || (SysSourceGetSourceType() == _SOURCE_DP))
    {
        if(UserInterfaceGetAudioSource() != _DIGITAL_AUDIO)
        {
            // Get real volume of digital audio
            usVolume = UserCommonAdjustPercentToRealValue(GET_OSD_VOLUME(), _DIGITAL_VOLUME_MAX, _DIGITAL_VOLUME_MIN, _DIGITAL_VOLUME_CENTER);

            // Mute digital audio
            ScalerAudioDigitalVolumeMute(_ON, usVolume);            
        }
        else
        {
            // Get real volume of analog audio
            usVolume = UserCommonAdjustPercentToRealValue(GET_OSD_VOLUME(), _ANALOG_VOLUME_MAX, _ANALOG_VOLUME_MIN, _ANALOG_VOLUME_CENTER);
            
            // Mute analog audio
            ScalerAudioAnalogVolumeMute(_ON, (BYTE) (usVolume & 0x3F));
        }
    }    

    // The switch process is in SysAudioDACHandler() of Sysaudio.c
    
}
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)

#endif // End of #if(_AUDIO_SUPPORT == _ON)

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
    if(GET_OSD_ULTRA_VIVID_STATUS() == _ULTRA_VIVID_OFF)
    {
        ScalerColorUltraVividOff();
    }
    else
    {

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
        ScalerColorUltraVividAdjust(tCOLOR_ULTRAVIVID_SETTING_TABLE[GET_OSD_ULTRA_VIVID_STATUS() * 4],
                                    tCOLOR_ULTRAVIVID_SETTING_TABLE[GET_OSD_ULTRA_VIVID_STATUS() * 4 + 1], 
                                    tCOLOR_ULTRAVIVID_SETTING_TABLE[GET_OSD_ULTRA_VIVID_STATUS() * 4 + 2],
                                    tCOLOR_ULTRAVIVID_SETTING_TABLE[GET_OSD_ULTRA_VIVID_STATUS() * 4 + 3],
                                    tCOLOR_ULTRAVIVID_SETTING_CDS,
                                    tCOLOR_ULTRAVIVID_SETTING_HSR[GET_OSD_ULTRA_VIVID_STATUS()],
                                    GET_CURRENT_BANK_NUMBER());
#else
        ScalerColorUltraVividAdjust(tCOLOR_ULTRAVIVID_SETTING_TABLE[GET_OSD_ULTRA_VIVID_STATUS() * 4],
                                    tCOLOR_ULTRAVIVID_SETTING_TABLE[GET_OSD_ULTRA_VIVID_STATUS() * 4 + 1], 
                                    tCOLOR_ULTRAVIVID_SETTING_TABLE[GET_OSD_ULTRA_VIVID_STATUS() * 4 + 2],
                                    tCOLOR_ULTRAVIVID_SETTING_TABLE[GET_OSD_ULTRA_VIVID_STATUS() * 4 + 3],
                                    tCOLOR_ULTRAVIVID_SETTING_CDS,
                                    GET_CURRENT_BANK_NUMBER());
#endif

    }
}
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_3D_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Select 3D mode
// Input Value  : 3D mode
// Output Value : None
//--------------------------------------------------
//2D&3D切換處理動作(狀態Flag設定)
void UserAdjust3DMode(BYTE uc3DMode)//Eli Add
{       
    if(uc3DMode == _3D_MODE_SBS)
    {
        SET_OSD_3D_STATUS(_3D_ON);
        SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_SBS);
        SET_OSD_3D_EFFECT(1);
        SET_OSD_3D_CONVERGENCE(_2D_TO_3D_INWARD);        // 2D to 3D Function
        SET_OSD_3D_CONVERGENCE_MODE(1);                  // 2D to 3D Function
        SET_OSD_3D_LR_STATUS(_3D_DISPLAY_LR);
        SET_OSD_3D_3DTO2D(_OFF);
        UserCommonAdjustUltraVivid(_OFF);
    }
    else if(uc3DMode == _3D_MODE_TNB)
    {
        SET_OSD_3D_STATUS(_3D_ON);
        SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_TNB);
        SET_OSD_3D_EFFECT(1);
        SET_OSD_3D_CONVERGENCE(_2D_TO_3D_INWARD);        // 2D to 3D Function
        SET_OSD_3D_CONVERGENCE_MODE(1);                  // 2D to 3D Function
        SET_OSD_3D_LR_STATUS(_3D_DISPLAY_LR);
        SET_OSD_3D_3DTO2D(_OFF);
        UserCommonAdjustUltraVivid(_OFF);
    }
    else if(uc3DMode == _3D_MODE_AUTO)
    {
//		ScalerMeasureInputInfo(SysSourceGetSourceType());		
//		ScalerDebugMessage("3D input format",Scaler3DGetInputFormat());

		if(Scaler3DTxInputFormat() == _NO_3D_FORMAT)
		{
			SET_OSD_3D_STATUS(_3D_OFF);	
			SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_AUTO);
			SET_OSD_3D_3DTO2D(_OFF);
		}
		else
		{
			SET_OSD_3D_STATUS(_3D_ON);	
			if(Scaler3DTxInputFormat() == _SIDE_BY_SIDE_HALF)
			{
				SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_SBS);
			}
			else if(Scaler3DTxInputFormat() == _TOP_AND_BOTTOM)
			{
				SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_TNB);
			}
			else
			{
				SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_AUTO);
			}
		}
               
        SET_OSD_3D_EFFECT(1);
        SET_OSD_3D_LR_STATUS(_3D_DISPLAY_LR);
        SET_OSD_3D_3DTO2D(_OFF);
        UserCommonAdjustUltraVivid(_OFF);

    }
    else if(uc3DMode == _2D_TO_3D_MODE1_OUTWARD)			//20120604 Abel
	{
        SET_OSD_3D_STATUS(_3D_2D_TO_3D);
        SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_AUTO);
        SET_OSD_3D_EFFECT(15);
        SET_OSD_3D_CONVERGENCE(_2D_TO_3D_OUTWARD);          // 2D to 3D Function
        SET_OSD_3D_CONVERGENCE_MODE(0);                     // 2D to 3D Function
        SET_OSD_3D_LR_STATUS(_3D_DISPLAY_RL);
        SET_OSD_3D_3DTO2D(_OFF);
        UserCommonAdjustUltraVivid(2);
    }        
	else if(uc3DMode == _2D_TO_3D_MODE4_OUTWARD)
	{
        SET_OSD_3D_STATUS(_3D_2D_TO_3D);
        SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_AUTO);
        SET_OSD_3D_EFFECT(70);
        SET_OSD_3D_CONVERGENCE(_2D_TO_3D_OUTWARD);          // 2D to 3D Function
        SET_OSD_3D_CONVERGENCE_MODE(3);                     // 2D to 3D Function
        SET_OSD_3D_LR_STATUS(_3D_DISPLAY_RL);
        SET_OSD_3D_3DTO2D(_OFF);
        UserCommonAdjustUltraVivid(2);
    }

    
/*    
    else
    {
        SET_OSD_3D_STATUS(_3D_OFF);
        SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_AUTO);
        SET_OSD_3D_EFFECT(2);
        SET_OSD_3D_CONVERGENCE(_OFF);// 3D to 2D
        SET_OSD_3D_CONVERGENCE_MODE(1);
        SET_OSD_3D_LR_STATUS(_3D_DISPLAY_LR);
        SET_OSD_3D_3DTO2D(_OFF);
    }
*/    

//    UserInterfaceAdjustInputTiming();
    //SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
}
#endif

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
//(OSD選項)Rest重置動作
void OsdReset(void)//Robert Wang 20121210 re name for AllBase Code
{
    BYTE ucLanguage;
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
    BYTE ucFactoryModeStatus;
	BYTE ucSysSearchPort;
#elif (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    BYTE ucFactorySSC;
    BYTE ucSysSearchPort;
#endif
	
#if (_ASPECT_RATIO_SUPPORT == _ON) 
    BYTE ucImageRatio = GET_OSD_ASPECT_RATIO_TYPE();
#endif
#if(_ENERGY_STAR_SUPPORT == _ON)//Eli 20121123 Add ES6.0 Function.
			SET_OSD_ES_STATUS(_ON);
#endif

    //201205 Abel Modify(目前沒這個選項)
    if((GET_FACTORY_MODE()==_TRUE)
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
      ||(GET_ATE_COMMAND_STATUS()==_TRUE)       
#endif
    )
    {     
         RTDNVRamRestorePanelUsedTimeData();  //Panel Timer重置
    } 
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
    ucFactoryModeStatus = GET_FACTORY_MODE();
	ucSysSearchPort = UserCommonNVRamGetSystemData(_SEARCH_PORT);
#elif (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    ucFactorySSC = UserCommonNVRamGetSystemData(_SSC);
    ucSysSearchPort = UserCommonNVRamGetSystemData(_SEARCH_PORT);
#endif

    ucLanguage = GET_OSD_LANGUAGE();

#if 0//lorimiao 20140922
    RTDNVRamSaveColorSetting(_CT_USER);
#endif

    UserCommonNVRamRestoreSystemData();
    
#if(_VGA_SUPPORT == _ON)
    UserCommonNVRamRestoreModeUserData();
#endif

    RTDNVRamRestoreBriCon();
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
    SET_FACTORY_MODE(ucFactoryModeStatus);
#endif

#if 1//lorimiao 20140922
	SET_COLOR_TEMP_TYPE_USER_R(128);
	SET_COLOR_TEMP_TYPE_USER_G(128);
	SET_COLOR_TEMP_TYPE_USER_B(128);
	RTDNVRamSaveColorSetting(_CT_USER);

#else
    SET_COLOR_TEMP_TYPE(_CT_USER);
    g_stColorProcData.ucColorTempR = 128;
    g_stColorProcData.ucColorTempG = 128;
    g_stColorProcData.ucColorTempB = 128;
    RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());
#endif

    RTDNVRamRestoreOSDData();//lorimiao 0723

#if((_FACTORY_MODE_OWNER == _OWNER_TPV) && (_DFM_DC_RESET_7200_FUNCTION == _ON))
    if((TPVDFMModeFlag()==_ON)||(GET_FACTORY_BURNIN() == _ON))		//Irene modify for Factory need.
    {
	    SET_COLOR_TEMP_TYPE(_CT_6500);
		SET_PRESET_COLOR_TEMP_BACKUP(_CT_6500);
        RTDNVRamSaveOSDData();
    }
#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    if(GET_ATE_COMMAND_STATUS()||GET_FACTORY_MODE())    
    {
	    SET_COLOR_TEMP_TYPE(_CT_7200);
    }
    else
    {
	 	SET_COLOR_TEMP_TYPE(_CT_6500);
	    SET_OSD_LANGUAGE(ucLanguage);
    }
    RTDNVRamSaveOSDData();
#endif        

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON) && (_OSD_LBL_ADJUST_FUNCTION == _ON))
	SET_OSD_LBL_STATUS(_OFF);
#endif

    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
    UserAdjustContrast(GET_OSD_CONTRAST());
    UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());   
    
#if 1//lorimiao 20140922
#if(_OD_SUPPORT == _ON)
	if(GET_OSD_OD_STATUS() == _OFF)
    {
	    ScalerODControl(_OFF);
    }
	else
    {
	    ScalerODControl(_ON);
#if(_OD_MULTI_SELECT == _ON)
	    ScalerODAdjustDeltaGain(UserInterfaceGetODGainData()); 
#else		
		ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());  
#endif		 
    }
#endif        
#endif        

#if(_AUDIO_ADJUST_FUNCTION_SUPPORT == _ON)    
    UserAdjustAudioVolume(GET_OSD_VOLUME()); 
#endif

#if(_FACTORY_MODE_OWNER != _OWNER_WISTRON)    
    SET_OSD_LANGUAGE(ucLanguage);
#endif
	
    OsdDisplaySetPosition(_MAIN_OSD, GET_OSD_HPOS(), GET_OSD_VPOS());//Robert Wang 20130605

#if(_VGA_SUPPORT == _ON)
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
    if(TPVDFMAutoConfigByPass()==_FALSE)
#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    if((GET_ATE_COMMAND_STATUS()!=_TRUE)&&(GET_FACTORY_MODE()!=_TRUE))
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20150302 for Foxconn Factory Recall Command
	if(FactoryCommandRecallFlag == 0)
#endif      
    {
        if(SysSourceGetSourceType() == _SOURCE_VGA)
        {
        #if 1//lorimiao 20141104 
            OsdDisplayAutoProc();
		#else
             OsdDisplayDisableOsd();    
             OsdDisplayOsdMessage(_MSG_AUTO);
             UserCommonAutoConfig();
             OsdDisplayDisableOsd();
		#endif
        }
    }
#endif


#if (_ASPECT_RATIO_SUPPORT == _ON)
    if(ucImageRatio != _ASPECT_RATIO_FULL)
    {
        SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_FULL);
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);       
    }    
#endif
	SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
    ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());//lorimiao 20140110 for DDC/CI issue    

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
    UserCommonNVRamSetSystemData(_SEARCH_PORT,ucSysSearchPort);
    UserCommonNVRamSaveSystemData();
    SET_FACTORY_BURNIN(_OFF);
    TPVNVRamSaveFactoryDate();
    TPVDFMFactoryRest();
#elif (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
	SET_FACTORY_MODE(_OFF);
	SET_FACTORY_BURNIN(_OFF);
	SET_FACTORY_LOGO_ON_OFF(_ON);
	NVRamSaveFactoryDate();
	SET_ENERGY_MODE(_OFF);
    
#elif (_FACTORY_MODE_OWNER == _OWNER_WISTRON) 

  #if(_PANEL_EXIST_MULTIPANEL == _ON)
    UserCommonNVRamSetSystemData(_SSC,ucFactorySSC);
  #endif  
    
    UserCommonNVRamSetSystemData(_SEARCH_PORT,ucSysSearchPort);
    UserCommonNVRamSaveSystemData();
    
    if(GET_AUTO_DCOFF())
    {
        SET_AUTO_DCOFF(_OFF);
        NVRamSaveFactoryData();   
    }
#endif   

}

#if(_USER_DCR_FUNCTION == _ON)
//--------------------------------------------------
// Description  : DCR Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustDCRControl(bit bEn)//Eli 20140909
{  	
    if(bEn == _ON)
    {
    
#if(_ENERGY_STAR_SUPPORT == _ON)//Eli 20121123 Add ES6.0 Function.
				SET_OSD_ES_STATUS(_OFF);
#endif        
 		ScalerColorDCROnOff(_ON);
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)//ym20141015 . 
        g_ucPreDCRPWM = UserAdjustBacklightChangeRange(GET_OSD_BACKLIGHT());        
#else
        g_ucPreDCRPWM = tBRIGHTNESS_PWM[GET_OSD_BACKLIGHT()];
#endif

        g_ucDCRTimer=0;
#if(_DCR_PANEL_ON_OFF == _ON)  
		g_usDCRBLOffCunt=0;
		g_bDCRBLOffStart=_OFF;
#endif		
	}
    else
    {
    
#if(_ENERGY_STAR_SUPPORT == _ON)//Eli 20121123 Add ES6.0 Function.
				SET_OSD_ES_STATUS(_ON);
#endif        
		ScalerColorDCROnOff(_OFF);
        UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
#if(_DCR_PANEL_ON_OFF == _ON)  
		if(SysModeGetModeState()==_MODE_STATUS_ACTIVE)
		{
			UserInterfacePanelPowerAction(_BACKLIGHT_ON);
		}
#endif
    }
}
//--------------------------------------------------
// Description  : DCR Adjust PWM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustDCRPwm(BYTE ucPwmValue)
{
	if(g_ucDCRTimer <= 3)
	{
		g_ucDCRTimer = g_ucDCRTimer + 1;
        if(ucPwmValue == 0)           //20141001 Abel Test
          g_ucDCRTimer =4; 
	}
	else
	{
		g_ucDCRTimer = 0;
		
		// Step by step PWM
		if(g_ucPreDCRPWM > ucPwmValue)				// white to black
		{
			g_ucPreDCRPWM -= 1;
            DebugMessageOsd("g_ucPreDCRPWM--", g_ucPreDCRPWM);    
		}
		else if(g_ucPreDCRPWM < ucPwmValue) 		// black to white
		{
			g_ucPreDCRPWM += 1;
            DebugMessageOsd("g_ucPreDCRPWM++", g_ucPreDCRPWM);    
#if(_DCR_PANEL_ON_OFF == _ON)        
			if(ucPwmValue > 0)
		    {
                //if(GET_PANELPOWERSTATUS() == _PANEL_BACKLIGHT_OFF)
				if(bBACKLIGHTPOWER== _LIGHT_CONTROL_OFF)
                {
        		    //UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
					PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);
                }
			}
#endif
		}
		else
		{
			g_ucPreDCRPWM=ucPwmValue;
		}
		// End of step by step


#if(_DCR_PANEL_ON_OFF == _ON)

		g_ucDCRBLOffPWM = ucPwmValue;

		if(g_bDCRBLOffStart==_ON)
		{
			g_bDCRBLOffStart=_OFF;
			//UserInterfacePanelPowerAction(_BACKLIGHT_OFF);
			PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);
            DebugMessageOsd("@@@Backlght OFF !!", ucPwmValue);            
		}
		else
#endif
		{		 
			// Adjust backlight by changing PWM duty
#if(_BACKLIGHT_PWM_INVERSE == _ON)
			PCB_BACKLIGHT_PWM(0xFF-((DWORD)(_DCR_BACKLIGHT_PWM_MAX-_DCR_BACKLIGHT_PWM_MIN)*g_ucPreDCRPWM/255+_DCR_BACKLIGHT_PWM_MIN));
#else
			PCB_BACKLIGHT_PWM((DWORD)(_DCR_BACKLIGHT_PWM_MAX-_DCR_BACKLIGHT_PWM_MIN)*g_ucPreDCRPWM/255+_DCR_BACKLIGHT_PWM_MIN);
#endif
		}
	}
	
}


//--------------------------------------------------
// Description  : DCR Measure 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//DCR動態調整亮度(隨時在做)
void UserAdjustDCRMeasure(void)
{
    WORD usDcrStepLower = 0;
    DWORD ucValueAvg = 0;
    BYTE ucTemp = 0,ucPWM =0;

    //BYTE ucRGain = 0;
    //BYTE ucGGain = 0;
    //BYTE ucBGain = 0;

    // Check if DVS happened.
    ucTemp = ScalerTimerGetEventStatus(_EVENT_DVS);
    
    if(ucTemp != _EVENT_DVS)
    {
        return;
    }
    
    // Clear DVS Event.
    ScalerTimerClrEventStatus(_EVENT_DVS);
   
	// Get total sum (R+G+B) of  pixel value above thershold1 value
	ucValueAvg = ScalerColorDCRReadResult(_DCR_ABOVE_TH1_VAL) / (GET_MDOMAIN_OUTPUT_HWIDTH()) / (GET_MDOMAIN_OUTPUT_VHEIGHT());	
	//ScalerDebugMessage("DCR Measure result", ucValueAvg);

	//current level is under current step range , but under buffer range, keep last setting
	if ((ucValueAvg < tDcrStep[g_DcrStep])&&(ucValueAvg >= (tDcrStep[g_DcrStep] - _DCR_STEP_BUFFER)))
	{
		ucPWM = tBacklightStep[g_DcrStep];
	}
	//current level is over next step range , but under buffer range, keep last setting
	else if ((ucValueAvg >= tDcrStep[(g_DcrStep+1)]) && (ucValueAvg < (tDcrStep[(g_DcrStep+1)] + _DCR_STEP_BUFFER)))
	{
		ucPWM = tBacklightStep[(g_DcrStep+1)];
	}
	//current level is not in step range , get new range
	else 
	{
		for (ucTemp=0;ucTemp<8;ucTemp++)   //取出對應PWM值
		{
			if (g_DcrStep == 0)//change slope gain from 0
				usDcrStepLower = 0;
			else
				usDcrStepLower = tDcrStep[ucTemp];	 
			
			if (ucValueAvg < tDcrStep[(ucTemp+1)])
			{
				g_DcrStep = ucTemp;
				ucPWM = ((DWORD)(tBacklightStep[(ucTemp+1)] - tBacklightStep[ucTemp]) * 10000 / (tDcrStep[(ucTemp+1)] - usDcrStepLower))  * (ucValueAvg - usDcrStepLower) / 10000 + tBacklightStep[ucTemp];
				
				break;
			}			 
		}		 
	}
    
	//check mouse pointer if in Screen
	if (g_DcrStep == 0)
	{		 
#if(_DCR_PANEL_ON_OFF == _ON)   
		if (ucPWM == 0)
		{
            //ucRGain = ScalerColorDCRReadResult(_HIGH_LV_VAL_R);
            //ucGGain = ScalerColorDCRReadResult(_HIGH_LV_VAL_G);
            //ucBGain = ScalerColorDCRReadResult(_HIGH_LV_VAL_B);            
            //ScalerDebugMessage("ucRGain", ucRGain);
        	//ScalerDebugMessage("ucGGain", ucGGain);
         	//ScalerDebugMessage("ucBGain", ucBGain);
		
			// dynamic detect the hightest level value of R/G/B chanel(偵測黑畫面)
			if((ScalerColorDCRReadResult(_HIGH_LV_VAL_R) < 30) && (ScalerColorDCRReadResult(_HIGH_LV_VAL_G) < 30) && (ScalerColorDCRReadResult(_HIGH_LV_VAL_B) < 30))	
			//if((ucRGain < 30) && (ucGGain < 30) && (ucBGain < 30))	
			{			
				ucPWM = 0;
			}
			else
			{
				ucPWM = 1;
			} 
		}
#else
		ucPWM = 0;
#endif
	}
	//check OSD if is on, turn on backlight
	if((ucValueAvg < 48)&&(ScalerOsdGetOsdEnable() == 1))
	{	
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)//ym20141015 . 
        ucPWM = UserAdjustBacklightChangeRange(GET_OSD_BACKLIGHT());        
#else
        ucPWM = tBRIGHTNESS_PWM[GET_OSD_BACKLIGHT()];
#endif

#if(_DCR_PANEL_ON_OFF == _ON)  
		//if(GET_PANELPOWERSTATUS() == _PANEL_BACKLIGHT_OFF)
		if(bBACKLIGHTPOWER== _LIGHT_CONTROL_OFF)
		{
			//UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
			PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);
		}
#endif
	}
	UserAdjustDCRPwm(ucPWM);
}

#endif


#if(_ENERGY_STAR_SUPPORT == _ON)//lorimiao 20131218 for ES6.0 test
//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserAdjustESBacklight(void)
{
    // Search Target Backlight Value.
    UserCommonAdjustESDcrSearchTargetPWM();

    // Set Adjust Value = Target Value.
    SET_ES_DCR_PWM_ADJUST_VALUE(GET_ES_DCR_PWM_TARGET_VALUE());

    // Set Backlight Value.
    UserAdjustBacklight(GET_ES_DCR_PWM_ADJUST_VALUE());
}
#endif//#if(_ENERGY_STAR_SUPPORT == _ON)

#endif//#if(_OSD_TYPE == _LENOVO_2014_OSD)
