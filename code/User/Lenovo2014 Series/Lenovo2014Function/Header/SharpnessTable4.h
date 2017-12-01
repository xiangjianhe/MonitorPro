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
// ID Code      : SharpnessTable4.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define LPCF04                                                  0x16

#if((_SCALING_UP_TYPE == _SU_GEN_0) || (_SCALING_UP_TYPE == _SU_GEN_1))
//----------------------------------------------------------------------------------------------------
// 128 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_128_TAPS_4[] =
{
    0xE0, 0x0F, 0xE9, 0x0F, 0xE8, 0x0F, 0xE9, 0x0F, 0xE8, 0x0F, 0xE7, 0x0F, 0xE4, 0x0F, 0xE3, 0x0F, 
    0xE1, 0x0F, 0xDF, 0x0F, 0xDC, 0x0F, 0xDB, 0x0F, 0xD8, 0x0F, 0xD7, 0x0F, 0xD5, 0x0F, 0xD5, 0x0F, 
    0x4C, 0x00, 0x61, 0x00, 0x78, 0x00, 0x92, 0x00, 0xAC, 0x00, 0xC9, 0x00, 0xE6, 0x00, 0x06, 0x01, 
    0x26, 0x01, 0x48, 0x01, 0x69, 0x01, 0x8D, 0x01, 0xAF, 0x01, 0xD4, 0x01, 0xF6, 0x01, 0x1B, 0x02, 
    0x9A, 0x03, 0x8B, 0x03, 0x84, 0x03, 0x75, 0x03, 0x68, 0x03, 0x56, 0x03, 0x44, 0x03, 0x2D, 0x03, 
    0x15, 0x03, 0xFA, 0x02, 0xE0, 0x02, 0xC0, 0x02, 0xA3, 0x02, 0x81, 0x02, 0x61, 0x02, 0x3C, 0x02, 
    0x3A, 0x00, 0x2B, 0x00, 0x1C, 0x00, 0x10, 0x00, 0x04, 0x00, 0xFA, 0x0F, 0xF2, 0x0F, 0xEA, 0x0F, 
    0xE4, 0x0F, 0xDF, 0x0F, 0xDB, 0x0F, 0xD8, 0x0F, 0xD6, 0x0F, 0xD4, 0x0F, 0xD4, 0x0F, 0xD4, 0x0F,  
};

//----------------------------------------------------------------------------------------------------
// 128 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_128_TAPS_4[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00,
    LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00,
    (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03,
    (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03,
    LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00,
    LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, 
};
#endif

#if((_SCALING_UP_TYPE == _SU_GEN_1) || (_SCALING_UP_TYPE == _SU_GEN_2) || (_3D_SUPPORT == _ON))
//----------------------------------------------------------------------------------------------------
// 96 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_96_TAPS_4[] =
{
    0xF1, 0x0F, 0xF1, 0x0F, 0xF2, 0x0F, 0xF3, 0x0F, 0xF5, 0x0F, 0xF7, 0x0F, 0xF9, 0x0F, 0xFD, 0x0F,
    0x00, 0x00, 0x05, 0x00, 0x0B, 0x00, 0x11, 0x00, 0x19, 0x00, 0x23, 0x00, 0x2E, 0x00, 0x39, 0x00,
    0x17, 0x02, 0x3E, 0x02, 0x5C, 0x02, 0x81, 0x02, 0x9E, 0x02, 0xC1, 0x02, 0xDB, 0x02, 0xFA, 0x02,
    0x11, 0x03, 0x2D, 0x03, 0x3F, 0x03, 0x55, 0x03, 0x62, 0x03, 0x72, 0x03, 0x78, 0x03, 0x81, 0x03,
    0xF8, 0x01, 0xD1, 0x01, 0xB2, 0x01, 0x8C, 0x01, 0x6D, 0x01, 0x48, 0x01, 0x2C, 0x01, 0x09, 0x01,
    0xEF, 0x00, 0xCE, 0x00, 0xB6, 0x00, 0x9A, 0x00, 0x85, 0x00, 0x6B, 0x00, 0x5A, 0x00, 0x46, 0x00,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

#endif

#if(_SCALING_UP_TYPE == _SU_GEN_2)
//----------------------------------------------------------------------------------------------------
// 96 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_96_TAPS_4[] =
{
    LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00,
    LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00,
    (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03,
    (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03, (0xFF - LPCF04 - LPCF04 + 1), 0x03,
    LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00,
    LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00, LPCF04, 0x00,   
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
#endif

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
//----------------------------------------------------------------------------------------------------
// 64 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_64_TAPS_4[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x01, 0x00, 0x08, 0x00, 0x13, 0x00, 0x24, 0x00, 0x36, 0x00, 0x4F, 0x00, 0x6A, 0x00, 0x8B, 0x00, 
    0xAD, 0x00, 0xD4, 0x00, 0xFC, 0x00, 0x29, 0x01, 0x56, 0x01, 0x86, 0x01, 0xB6, 0x01, 0xE8, 0x01, 
    0xFF, 0x03, 0xF8, 0x03, 0xED, 0x03, 0xDC, 0x03, 0xCA, 0x03, 0xB1, 0x03, 0x96, 0x03, 0x75, 0x03, 
    0x53, 0x03, 0x2C, 0x03, 0x04, 0x03, 0xD7, 0x02, 0xAA, 0x02, 0x7A, 0x02, 0x4A, 0x02, 0x18, 0x02,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
#endif
