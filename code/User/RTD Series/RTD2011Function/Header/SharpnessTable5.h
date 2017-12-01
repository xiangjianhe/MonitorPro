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
// ID Code      : SharpnessTable5.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define HPCF00                                                  0x16

#if((_SCALING_UP_TYPE == _SU_GEN_0) || (_SCALING_UP_TYPE == _SU_GEN_1))
//----------------------------------------------------------------------------------------------------
// 128 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_128_TAPS_5[] =
{
    0xF8, 0x0F, 0xF8, 0x0F, 0xF6, 0x0F, 0xF5, 0x0F, 0xF3, 0x0F, 0xEF, 0x0F, 0xEC, 0x0F, 0xEA, 0x0F,  
    0xE5, 0x0F, 0xE2, 0x0F, 0xDD, 0x0F, 0xD8, 0x0F, 0xD3, 0x0F, 0xCF, 0x0F, 0xCA, 0x0F, 0xC6, 0x0F,  
    0x21, 0x00, 0x3A, 0x00, 0x51, 0x00, 0x6F, 0x00, 0x89, 0x00, 0xAB, 0x00, 0xC9, 0x00, 0xEE, 0x00,  
    0x10, 0x01, 0x37, 0x01, 0x5B, 0x01, 0x85, 0x01, 0xAB, 0x01, 0xD7, 0x01, 0xFD, 0x01, 0x29, 0x02,  
    0xD8, 0x03, 0xD2, 0x03, 0xCB, 0x03, 0xBD, 0x03, 0xAE, 0x03, 0x99, 0x03, 0x85, 0x03, 0x69, 0x03,  
    0x4F, 0x03, 0x2F, 0x03, 0x10, 0x03, 0xEB, 0x02, 0xC8, 0x02, 0x9F, 0x02, 0x7B, 0x02, 0x4F, 0x02,  
    0x0F, 0x00, 0xFC, 0x0F, 0xEE, 0x0F, 0xDF, 0x0F, 0xD6, 0x0F, 0xCD, 0x0F, 0xC6, 0x0F, 0xBF, 0x0F,  
    0xBC, 0x0F, 0xB8, 0x0F, 0xB8, 0x0F, 0xB8, 0x0F, 0xBA, 0x0F, 0xBB, 0x0F, 0xBE, 0x0F, 0xC2, 0x0F,  
}; 

//----------------------------------------------------------------------------------------------------
// 128 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_128_TAPS_5[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F,
    (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F,
    (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04,
    (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04,
    (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F,
    (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F,
};
#endif

#if((_SCALING_UP_TYPE == _SU_GEN_1) || (_SCALING_UP_TYPE == _SU_GEN_2) || (_3D_SUPPORT == _ON))
//----------------------------------------------------------------------------------------------------
// 96 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_96_TAPS_5[] =
{
    0xEA, 0x0F, 0xEA, 0x0F, 0xEB, 0x0F, 0xEB, 0x0F, 0xEC, 0x0F, 0xED, 0x0F, 0xEF, 0x0F, 0xF0, 0x0F, 
    0xF3, 0x0F, 0xF6, 0x0F, 0xFA, 0x0F, 0x00, 0x00, 0x06, 0x00, 0x0E, 0x00, 0x17, 0x00, 0x20, 0x00, 
    0x1B, 0x02, 0x47, 0x02, 0x67, 0x02, 0x91, 0x02, 0xB0, 0x02, 0xD8, 0x02, 0xF4, 0x02, 0x18, 0x03, 
    0x30, 0x03, 0x51, 0x03, 0x64, 0x03, 0x7F, 0x03, 0x8D, 0x03, 0xA2, 0x03, 0xA8, 0x03, 0xB3, 0x03, 
    0xFB, 0x01, 0xCF, 0x01, 0xAE, 0x01, 0x84, 0x01, 0x64, 0x01, 0x3B, 0x01, 0x1D, 0x01, 0xF8, 0x00, 
    0xDD, 0x00, 0xB9, 0x00, 0xA2, 0x00, 0x81, 0x00, 0x6D, 0x00, 0x50, 0x00, 0x41, 0x00, 0x2D, 0x00,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

#endif

#if(_SCALING_UP_TYPE == _SU_GEN_2)
//----------------------------------------------------------------------------------------------------
// 96 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_96_TAPS_5[] =
{
    (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F,
    (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F,
    (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04,
    (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04, (HPCF00 + HPCF00), 0x04,
    (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F,
    (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F, (0xFF - HPCF00 + 0x01), 0x0F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
#endif

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
//----------------------------------------------------------------------------------------------------
// 64 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_64_TAPS_5[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xE6, 0x0F, 0xEF, 0x0F, 0xF8, 0x0F, 0x0D, 0x00, 0x21, 0x00, 0x3F, 0x00, 0x5D, 0x00, 0x83, 0x00, 
    0xA7, 0x00, 0xD3, 0x00, 0xFC, 0x00, 0x2B, 0x01, 0x56, 0x01, 0x89, 0x01, 0xB6, 0x01, 0xE9, 0x01, 
    0x1A, 0x04, 0x11, 0x04, 0x08, 0x04, 0xF3, 0x03, 0xDF, 0x03, 0xC1, 0x03, 0xA3, 0x03, 0x7D, 0x03, 
    0x59, 0x03, 0x2D, 0x03, 0x04, 0x03, 0xD5, 0x02, 0xAA, 0x02, 0x77, 0x02, 0x4A, 0x02, 0x17, 0x02, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif