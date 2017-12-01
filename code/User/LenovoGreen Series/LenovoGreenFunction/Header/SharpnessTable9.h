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
// ID Code      : SharpnessTable9.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define HPCF04                                                  0x71

#if((_SCALING_UP_TYPE == _SU_GEN_0) || (_SCALING_UP_TYPE == _SU_GEN_1))
//----------------------------------------------------------------------------------------------------
// 128 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_128_TAPS_9[] =
{
    0x02, 0x00, 0x04, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD, 0x0F, 0xFA, 0x0F, 
    0xF6, 0x0F, 0xF1, 0x0F, 0xED, 0x0F, 0xE7, 0x0F, 0xE0, 0x0F, 0xDA, 0x0F, 0xD3, 0x0F, 0xCB, 0x0F, 
    0x9E, 0x0F, 0xB1, 0x0F, 0xC6, 0x0F, 0xE2, 0x0F, 0xFF, 0x0F, 0x21, 0x00, 0x45, 0x00, 0x6F, 0x00, 
    0x9B, 0x00, 0xCC, 0x00, 0xFC, 0x00, 0x34, 0x01, 0x69, 0x01, 0xA5, 0x01, 0xDD, 0x01, 0x1C, 0x02, 
    0xCE, 0x04, 0xC3, 0x04, 0xB5, 0x04, 0x9E, 0x04, 0x85, 0x04, 0x63, 0x04, 0x3F, 0x04, 0x14, 0x04, 
    0xE6, 0x03, 0xB3, 0x03, 0x7F, 0x03, 0x45, 0x03, 0x0E, 0x03, 0xCF, 0x02, 0x95, 0x02, 0x56, 0x02, 
    0x92, 0x0F, 0x88, 0x0F, 0x82, 0x0F, 0x7E, 0x0F, 0x7C, 0x0F, 0x7C, 0x0F, 0x7F, 0x0F, 0x83, 0x0F, 
    0x89, 0x0F, 0x90, 0x0F, 0x98, 0x0F, 0xA0, 0x0F, 0xA9, 0x0F, 0xB2, 0x0F, 0xBB, 0x0F, 0xC3, 0x0F,   
};

//----------------------------------------------------------------------------------------------------
// 128 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_128_TAPS_9[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F,
    (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F,
    (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04,
    (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04,
    (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F,
    (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F,
};
#endif

#if((_SCALING_UP_TYPE == _SU_GEN_1) || (_SCALING_UP_TYPE == _SU_GEN_2) || (_3D_SUPPORT == _ON))
//----------------------------------------------------------------------------------------------------
// 96 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_96_TAPS_9[] =
{
    0xE2, 0x0F, 0xDF, 0x0F, 0xDC, 0x0F, 0xD6, 0x0F, 0xCF, 0x0F, 0xC6, 0x0F, 0xBC, 0x0F, 0xB2, 0x0F,
    0xA8, 0x0F, 0x9E, 0x0F, 0x96, 0x0F, 0x8E, 0x0F, 0x88, 0x0F, 0x86, 0x0F, 0x86, 0x0F, 0x86, 0x0F,
    0x2A, 0x02, 0x71, 0x02, 0xA9, 0x02, 0xEF, 0x02, 0x26, 0x03, 0x69, 0x03, 0x9D, 0x03, 0xDB, 0x03,
    0x08, 0x04, 0x3E, 0x04, 0x63, 0x04, 0x90, 0x04, 0xAA, 0x04, 0xCC, 0x04, 0xDB, 0x04, 0xEC, 0x04,
    0xF4, 0x01, 0xB0, 0x01, 0x7B, 0x01, 0x3B, 0x01, 0x0B, 0x01, 0xD1, 0x00, 0xA7, 0x00, 0x73, 0x00,
    0x50, 0x00, 0x24, 0x00, 0x07, 0x00, 0xE2, 0x0F, 0xCE, 0x0F, 0xAE, 0x0F, 0x9F, 0x0F, 0x8E, 0x0F,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif

#if(_SCALING_UP_TYPE == _SU_GEN_2)
//----------------------------------------------------------------------------------------------------
// 128 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_96_TAPS_9[] =
{
    (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F,
    (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F,
    (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04,
    (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04, (HPCF04 + HPCF04), 0x04,
    (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F,
    (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F, (0xFF - HPCF04 + 0x01), 0x0F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
#endif

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
//----------------------------------------------------------------------------------------------------
// 64 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_64_TAPS_9[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x07, 0x0F, 0x29, 0x0F, 0x3E, 0x0F, 0x80, 0x0F, 0xA2, 0x0F, 0xEB, 0x0F, 0x14, 0x00, 0x61, 0x00, 
    0x8A, 0x00, 0xD4, 0x00, 0xF9, 0x00, 0x3F, 0x01, 0x5D, 0x01, 0x9D, 0x01, 0xB8, 0x01, 0xF4, 0x01, 
    0xF9, 0x04, 0xD7, 0x04, 0xC2, 0x04, 0x80, 0x04, 0x5E, 0x04, 0x15, 0x04, 0xEC, 0x03, 0x9F, 0x03, 
    0x76, 0x03, 0x2C, 0x03, 0x07, 0x03, 0xC1, 0x02, 0xA3, 0x02, 0x63, 0x02, 0x48, 0x02, 0x0C, 0x02,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
#endif
