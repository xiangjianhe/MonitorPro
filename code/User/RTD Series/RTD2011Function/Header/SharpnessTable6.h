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
// ID Code      : SharpnessTable6.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define HPCF01                                                  0x2B

#if((_SCALING_UP_TYPE == _SU_GEN_0) || (_SCALING_UP_TYPE == _SU_GEN_1))
//----------------------------------------------------------------------------------------------------
// 128 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_128_TAPS_6[] =
{
    0xF6, 0x0F, 0xF6, 0x0F, 0xF5, 0x0F, 0xF2, 0x0F, 0xF0, 0x0F, 0xEC, 0x0F, 0xE8, 0x0F, 0xE4, 0x0F, 
    0xE0, 0x0F, 0xDA, 0x0F, 0xD4, 0x0F, 0xCE, 0x0F, 0xC7, 0x0F, 0xC2, 0x0F, 0xBC, 0x0F, 0xB6, 0x0F, 
    0x09, 0x00, 0x22, 0x00, 0x3C, 0x00, 0x5A, 0x00, 0x78, 0x00, 0x9B, 0x00, 0xBD, 0x00, 0xE4, 0x00, 
    0x08, 0x01, 0x32, 0x01, 0x5B, 0x01, 0x87, 0x01, 0xB1, 0x01, 0xDE, 0x01, 0x09, 0x02, 0x38, 0x02, 
    0x0C, 0x04, 0x05, 0x04, 0xFD, 0x03, 0xEE, 0x03, 0xDE, 0x03, 0xC8, 0x03, 0xB1, 0x03, 0x93, 0x03, 
    0x76, 0x03, 0x54, 0x03, 0x31, 0x03, 0x0A, 0x03, 0xE4, 0x02, 0xB8, 0x02, 0x8F, 0x02, 0x61, 0x02, 
    0xF5, 0x0F, 0xE3, 0x0F, 0xD2, 0x0F, 0xC6, 0x0F, 0xBA, 0x0F, 0xB1, 0x0F, 0xAA, 0x0F, 0xA5, 0x0F, 
    0xA2, 0x0F, 0xA0, 0x0F, 0xA0, 0x0F, 0xA1, 0x0F, 0xA4, 0x0F, 0xA8, 0x0F, 0xAC, 0x0F, 0xB1, 0x0F, 
};

//----------------------------------------------------------------------------------------------------
// 128 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_128_TAPS_6[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F,
    (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F,
    (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04,
    (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04,
    (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F,
    (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F,
};
#endif

#if((_SCALING_UP_TYPE == _SU_GEN_1) || (_SCALING_UP_TYPE == _SU_GEN_2) || (_3D_SUPPORT == _ON))
//----------------------------------------------------------------------------------------------------
// 96 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_96_TAPS_6[] =
{
    0xE2, 0x0F, 0xE3, 0x0F, 0xE2, 0x0F, 0xE3, 0x0F, 0xE3, 0x0F, 0xE3, 0x0F, 0xE3, 0x0F, 0xE4, 0x0F,
    0xE6, 0x0F, 0xE8, 0x0F, 0xEB, 0x0F, 0xEE, 0x0F, 0xF4, 0x0F, 0xFC, 0x0F, 0x03, 0x00, 0x0A, 0x00,
    0x20, 0x02, 0x4F, 0x02, 0x71, 0x02, 0x9F, 0x02, 0xBE, 0x02, 0xEB, 0x02, 0x08, 0x03, 0x31, 0x03, 
    0x4A, 0x03, 0x6F, 0x03, 0x83, 0x03, 0xA3, 0x03, 0xB1, 0x03, 0xC9, 0x03, 0xD1, 0x03, 0xDF, 0x03, 
    0xFE, 0x01, 0xCE, 0x01, 0xAD, 0x01, 0x7E, 0x01, 0x5F, 0x01, 0x32, 0x01, 0x15, 0x01, 0xEB, 0x00,
    0xD0, 0x00, 0xA9, 0x00, 0x92, 0x00, 0x6F, 0x00, 0x5B, 0x00, 0x3B, 0x00, 0x2C, 0x00, 0x17, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,    
};
#endif

#if(_SCALING_UP_TYPE == _SU_GEN_2)
//----------------------------------------------------------------------------------------------------
// 96 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_96_TAPS_6[] =
{
    (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F,
    (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F,
    (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04,
    (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04, (HPCF01 + HPCF01), 0x04,
    (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F,
    (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F, (0xFF - HPCF01 + 0x01), 0x0F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
#endif

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
//----------------------------------------------------------------------------------------------------
// 64 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_64_TAPS_6[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   
    0xC1, 0x0F, 0xCE, 0x0F, 0xD8, 0x0F, 0xF5, 0x0F, 0x0C, 0x00, 0x32, 0x00, 0x4F, 0x00, 0x7D, 0x00,   
    0xA0, 0x00, 0xD2, 0x00, 0xF9, 0x00, 0x2D, 0x01, 0x56, 0x01, 0x8B, 0x01, 0xB5, 0x01, 0xEB, 0x01,   
    0x3F, 0x04, 0x32, 0x04, 0x28, 0x04, 0x0B, 0x04, 0xF4, 0x03, 0xCE, 0x03, 0xB1, 0x03, 0x83, 0x03,   
    0x60, 0x03, 0x2E, 0x03, 0x07, 0x03, 0xD3, 0x02, 0xAA, 0x02, 0x75, 0x02, 0x4B, 0x02, 0x15, 0x02,    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   
};
#endif