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
// ID Code      : SharpnessTable1.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define LPCF01                                                  0x6A

#if((_SCALING_UP_TYPE == _SU_GEN_0) || (_SCALING_UP_TYPE == _SU_GEN_1))
//----------------------------------------------------------------------------------------------------
// 128 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_128_TAPS_1[] =
{
    0xF3, 0x0F, 0xF5, 0x0F, 0xF5, 0x0F, 0xF5, 0x0F, 0xF5, 0x0F, 0xF7, 0x0F, 0xF7, 0x0F, 0xF8, 0x0F, 
    0xF9, 0x0F, 0xFA, 0x0F, 0xFB, 0x0F, 0xFF, 0x0F, 0x00, 0x00, 0x05, 0x00, 0x06, 0x00, 0x0A, 0x00, 
    0xB3, 0x00, 0xC6, 0x00, 0xD8, 0x00, 0xED, 0x00, 0xFE, 0x00, 0x15, 0x01, 0x28, 0x01, 0x3F, 0x01, 
    0x53, 0x01, 0x6B, 0x01, 0x7E, 0x01, 0x96, 0x01, 0xA9, 0x01, 0xC1, 0x01, 0xD4, 0x01, 0xEB, 0x01, 
    0xB5, 0x02, 0xB1, 0x02, 0xAD, 0x02, 0xA6, 0x02, 0xA1, 0x02, 0x96, 0x02, 0x8D, 0x02, 0x81, 0x02, 
    0x75, 0x02, 0x66, 0x02, 0x58, 0x02, 0x46, 0x02, 0x37, 0x02, 0x22, 0x02, 0x12, 0x02, 0xFC, 0x01, 
    0xA5, 0x00, 0x94, 0x00, 0x86, 0x00, 0x78, 0x00, 0x6C, 0x00, 0x5E, 0x00, 0x54, 0x00, 0x48, 0x00, 
    0x3F, 0x00, 0x35, 0x00, 0x2F, 0x00, 0x25, 0x00, 0x20, 0x00, 0x18, 0x00, 0x14, 0x00, 0x0F, 0x00, 
};

//----------------------------------------------------------------------------------------------------
// 128 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_128_TAPS_1[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00,
    LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00,
    (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03,
    (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03,
    LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00,
    LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00 
};
#endif

#if((_SCALING_UP_TYPE == _SU_GEN_1) || (_SCALING_UP_TYPE == _SU_GEN_2) || (_3D_SUPPORT == _ON))
//----------------------------------------------------------------------------------------------------
// 96 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_96_TAPS_1[] =
{
    0x1E, 0x00, 0x1F, 0x00, 0x22, 0x00, 0x25, 0x00, 0x2A, 0x00, 0x31, 0x00, 0x38, 0x00, 0x40, 0x00,
    0x4B, 0x00, 0x55, 0x00, 0x61, 0x00, 0x6D, 0x00, 0x7A, 0x00, 0x8A, 0x00, 0x98, 0x00, 0xA7, 0x00,
    0xF7, 0x01, 0x0C, 0x02, 0x16, 0x02, 0x2A, 0x02, 0x34, 0x02, 0x46, 0x02, 0x4E, 0x02, 0x5E, 0x02,
    0x64, 0x02, 0x74, 0x02, 0x79, 0x02, 0x87, 0x02, 0x8B, 0x02, 0x97, 0x02, 0x99, 0x02, 0xA2, 0x02,
    0xEB, 0x01, 0xD5, 0x01, 0xC8, 0x01, 0xB1, 0x01, 0xA2, 0x01, 0x89, 0x01, 0x7A, 0x01, 0x62, 0x01,
    0x51, 0x01, 0x37, 0x01, 0x26, 0x01, 0x0C, 0x01, 0xFB, 0x00, 0xDF, 0x00, 0xCF, 0x00, 0xB7, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
};

#endif

#if(_SCALING_UP_TYPE == _SU_GEN_2)
//----------------------------------------------------------------------------------------------------
// 96 taps 1:1 Mode Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_1to1_COEF_96_TAPS_1[] =
{
    LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00,
    LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00,
    (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03,
    (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03, (0xFF - LPCF01 - LPCF01 + 1), 0x03,
    LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00,
    LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00, LPCF01, 0x00,   
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
#endif

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
//----------------------------------------------------------------------------------------------------
// 64 taps Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
BYTE code tSU_COEF_64_TAPS_1[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x19, 0x00, 0x2E, 0x00, 0x35, 0x00, 0x5B, 0x00, 0x66, 0x00, 0x8E, 0x00, 0x9E, 0x00, 0xCA, 0x00, 
    0xDD, 0x00, 0x0D, 0x01, 0x23, 0x01, 0x56, 0x01, 0x6E, 0x01, 0xA3, 0x01, 0xBD, 0x01, 0xF3, 0x01, 
    0xE7, 0x03, 0xD2, 0x03, 0xCB, 0x03, 0xA5, 0x03, 0x9A, 0x03, 0x72, 0x03, 0x62, 0x03, 0x36, 0x03, 
    0x23, 0x03, 0xF3, 0x02, 0xDD, 0x02, 0xAA, 0x02, 0x92, 0x02, 0x5D, 0x02, 0x43, 0x02, 0x0D, 0x02,  
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
#endif
