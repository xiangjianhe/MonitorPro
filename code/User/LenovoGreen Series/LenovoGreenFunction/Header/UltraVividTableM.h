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
// ID Code      : UltraVividTableM.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// ULTRAVIVID TABLE M
//----------------------------------------------------------------------------------------------------

#if(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_0)
BYTE code tCOLOR_ULTRAVIVID_SETTING_M1[] =
{
    4,  _NON_AUTOINC,   0x9F,   0x11,  
    11, _AUTOINC,       0xB9,   0x28, 0xFF, 0x3C, 0x08, 0x16, 0x08, 0x44, 0x33,
    4,  _NON_AUTOINC,   0x9F,   0x12,  
    22, _AUTOINC,       0xA0,   0xE1, 0x00, 0x40, 0x00, 0x12, 0x00, 0x07, 0xFE,
                                0x71, 0x01, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x28,
                                0x00, 0x28, 0x32,
    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M2[] =
{
    4,  _NON_AUTOINC,   0x9F,   0x11,  
    11, _AUTOINC,       0xB9,   0x28, 0xFF, 0x3C, 0x08, 0x16, 0x08, 0x44, 0x22,
    4,  _NON_AUTOINC,   0x9F,   0x12,   
    22, _AUTOINC,       0xA0,   0xE1, 0x00, 0x94, 0x00, 0xC4, 0x00, 0x2F, 0x96,
                                0x5D, 0x79, 0x03, 0x00, 0x32, 0x32, 0x00, 0x3C,
                                0x00, 0x3C, 0x1E,
    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M3[] =
{
    4,  _NON_AUTOINC,   0x9F,   0x11,
    11, _AUTOINC,       0xB9,   0x08, 0xFF, 0x3C, 0x08, 0x16, 0x08, 0x44, 0x22,
    4,  _NON_AUTOINC,   0x9F,   0x12,   
    22, _AUTOINC,       0xA0,   0xE1, 0x00, 0x40, 0x00, 0xD2, 0x01, 0xC4, 0xE2,
                                0x71, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x3C,
                                0x00, 0x3C, 0x1E,
    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M4[] =
{
    4,  _NON_AUTOINC,   0x9F,   0x11, 
    11, _AUTOINC,       0xB9,   0x2C, 0x00, 0x36, 0x04, 0x08, 0x08, 0x55, 0x23,
     4, _NON_AUTOINC,   0x9F,   0x11, 
    20, _AUTOINC,       0xA1,   0x0F,0x17,0x04,0x01,0x90,0x00,0x78,0x00,0xC4,0x00,0x2F,
                                0x01,0xA0,0x01,0xDD,0x01,0xFC,
    4,  _NON_AUTOINC,   0x9F,   0x11,
    8,  _AUTOINC,       0xB3,   0x83,0x1E,0x08,0x1E,0x08,                       
    4,  _NON_AUTOINC,   0x9F,   0x12,
    22, _AUTOINC,       0xA0,   0x47,0x00,0xD4,0x00,0x58,0x00,0x1A,0xCB,0x6F,0x7D,0x03,0x00,0x60,0x60,0x00,0x64,
                                0x00,0x64,0x0F,
    15, _AUTOINC,       0xB4,   0x50,0x00,0x06,0x00,0x60,0x06,0x00,0x06,0x00,0x05,0x00,0x64,
    11, _AUTOINC,       0xC0,   0x14,0x50,0x00,0x10,0x00,0x40,0x01,0x00,
    
    4,  _NON_AUTOINC,   0x9F,   0x13,         
    20, _AUTOINC,       0xD4,   0x3F,0x33,0x31,0x31,0xFF,0x42,0xFF,0xFF,0xFF,0xFF,0x00,0x04,
                                0x10,0xFF,0xFF,0x14,0x14,                                                                   
    _END
};

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
BYTE code tCOLOR_ULTRAVIVID_HSR_SETTING_M[] =
{
    4,  _NON_AUTOINC,   0x9F,   0x12,
    22, _AUTOINC,       0xA0,   0x41, 0x00, 0x40, 0x00, 0x7C, 0x00, 0x08, 0xBA,
                                0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0x14,
                                0x00, 0x4C, 0x10,
    _END
};
#endif

#elif(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_1)   // Elif of #if(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_0)

/////////////////////////////////
//Higher Positive Peaking Value//
/////////////////////////////////
BYTE code tCOLOR_ULTRAVIVID_SETTING_M1[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x22,0xF0,0x00,0x01,0xF4,0x00,0xC8,0x0F,0x00,0x03,0x02,0x00,0x16,0x50,
    14, _AUTOINC,       0xCF,   0x6E,0x2D,0x32,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xF4,0x00,0xC8,0x14,0x00,0x03,0x02,0x00,0x1E,0x50,0x64,0x16,0x28,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x14,0x00,

    _END
};


BYTE code tCOLOR_ULTRAVIVID_SETTING_M2[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x28,0x1B,0x00,0x02,0x1C,0x01,0x0E,0x14,0x00,0x02,0x02,0x00,0x14,0x28,
    14, _AUTOINC,       0xCF,   0x82,0x14,0x32,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xF4,0x00,0xFA,0x1A,0x00,0x02,0x02,0x00,0x1A,0x28,0x7D,0x1E,0x3C,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x14,0x00,

    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M3[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0x00,0x28,0x1B,0x00,0x02,0x12,0x00,0xB4,0x19,0x05,0x04,0x02,0x00,0x28,0x28,
    14, _AUTOINC,       0xCF,   0x87,0x28,0x4B,0x00,0x00,0x28,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x02,0x1C,0x00,0xB4,0x19,0x00,0x04,0x02,0x00,0x32,0x28,0x78,0x28,0x28,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x28,0x00,

    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M4[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x28,0x1B,0x00,0x01,0xA9,0x00,0xDC,0x2D,0x0F,0x03,0x03,0x00,0x2D,0x23,
    14, _AUTOINC,       0xCF,   0x82,0x58,0x59,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xE5,0x00,0xC8,0x28,0x0A,0x03,0x02,0x00,0x2D,0x23,0x78,0x14,0x0F,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x28,0x00,
                                                               
    _END
};

////////////////////////////////
//Lower Positive Peaking Value//
////////////////////////////////
/*
BYTE code tCOLOR_ULTRAVIVID_SETTING_M1[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x22,0xF0,0x00,0x01,0xF4,0x00,0xC8,0x0F,0x00,0x03,0x02,0x00,0x16,0x00,
    14, _AUTOINC,       0xCF,   0x6E,0x2D,0x32,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xF4,0x00,0xC8,0x14,0x00,0x03,0x02,0x00,0x1E,0x00,0x64,0x16,0x28,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x14,0x00,

    _END
};


BYTE code tCOLOR_ULTRAVIVID_SETTING_M2[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x28,0x1B,0x00,0x02,0x1C,0x01,0x0E,0x14,0x00,0x02,0x02,0x00,0x14,0x00,
    14, _AUTOINC,       0xCF,   0x82,0x14,0x32,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xF4,0x00,0xFA,0x1A,0x00,0x02,0x02,0x00,0x1A,0x00,0x7D,0x1E,0x3C,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x14,0x00,

    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M3[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0x00,0x28,0x1B,0x00,0x02,0x12,0x00,0xB4,0x19,0x05,0x04,0x02,0x00,0x28,0x00,
    14, _AUTOINC,       0xCF,   0x87,0x28,0x4B,0x00,0x00,0x28,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x02,0x1C,0x00,0xB4,0x19,0x00,0x04,0x02,0x00,0x32,0x00,0x78,0x28,0x28,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x28,0x00,

    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M4[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x28,0x1B,0x00,0x01,0xA9,0x00,0xDC,0x2D,0x0F,0x03,0x03,0x00,0x2D,0x00,
    14, _AUTOINC,       0xCF,   0x82,0x58,0x59,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xE5,0x00,0xC8,0x28,0x0A,0x03,0x02,0x00,0x2D,0x00,0x78,0x14,0x0F,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x28,0x00,
                                                               
    _END
};
*/

#elif(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_2)   // Elif of #if(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_0)

/////////////////////////////////
//Higher Positive Peaking Value//
/////////////////////////////////
BYTE code tCOLOR_ULTRAVIVID_SETTING_M1[] =
{    
    4,  _AUTOINC,       0x9F,   0x12,
    61, _AUTOINC,       0xA0,   0xF0,0x6C,0x00,0x00,0x00,0x31,0x96,0x00,0x7E,0x00,0x0E,0xB3,0x00,0x00,0x00,0x11,
                                0x00,0x0A,0x78,0x00,0x1E,0x02,0x8A,0x06,0x54,0x44,0x00,0x00,0x01,0x2C,0x01,0x2C,
                                0x20,0x01,0x00,0x00,0x00,0x31,0x96,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x11,
                                0x01,0x00,0x0A,0xDC,0x00,0x1E,0x02,0xBC,0x06,0x02,
    11, _AUTOINC,       0xDE,   0x51,0x0D,0x64,0x1E,0xDC,0x06,0x00,0x03,

    4,  _AUTOINC,       0x9F,   0x13, 
    31, _AUTOINC,       0xD4,   0x3E,0x33,0x31,0x31,0xFF,0x42,0xE6,0xF0,0xD7,0xF0,0x00,0x03,0x10,0xFF,0xFF,0x14,
                                0x14,0x04,0x14,0x00,0x10,0x00,0x40,0x01,0x00,0xFA,0xC8,0x02,               

    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x42,0xF0,0x00,0x01,0xF4,0x00,0xFA,0x0F,0x00,0x03,0x03,0x00,0x16,0x19,
    14, _AUTOINC,       0xCF,   0x64,0x0F,0x3C,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xF4,0x00,0xFA,0x0A,0x00,0x03,0x03,0x00,0x0F,0x19,0x64,0x0F,0x0F,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x14,0x00,

    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M2[] =
{    
    4,  _AUTOINC,       0x9F,   0x12,
    61, _AUTOINC,       0xA0,   0xF0,0x6C,0x00,0x00,0x00,0x21,0x64,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x20,
                                0x00,0x1E,0xA0,0x00,0x64,0x02,0xBC,0x05,0x54,0x44,0x00,0x00,0x01,0x2C,0x01,0x2C,
                                0x20,0x01,0x00,0x00,0x00,0x21,0xFA,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x20,
                                0x01,0x00,0x0D,0xA5,0x00,0x28,0x01,0x90,0x05,0x02,
    11, _AUTOINC,       0xDE,   0x51,0x0E,0x96,0x1E,0x82,0x05,0x00,0x03,

    4,  _AUTOINC,       0x9F,   0x13,                               
    31, _AUTOINC,       0xD4,   0x3E,0x33,0x31,0x31,0xFF,0x42,0xE6,0xF0,0xD7,0xF0,0x00,0x03,0x10,0xFF,0xFF,0x14,
                                0x14,0x04,0x14,0x00,0x10,0x00,0x40,0x01,0x00,0xFA,0xC8,0x02,
            
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x28,0x1B,0x00,0x01,0xE0,0x00,0xF0,0x23,0x00,0x03,0x03,0x00,0x34,0x1E,
    14, _AUTOINC,       0xCF,   0x8C,0x14,0x5A,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xE0,0x00,0xF0,0x23,0x00,0x03,0x03,0x00,0x34,0x1E,0x96,0x0A,0x3F,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x1C,0x00,
    
    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M3[] =
{       
    4,  _AUTOINC,       0x9F,   0x12,
    61, _AUTOINC,       0xA0,   0xF4,0x0C,0x00,0x00,0x00,0x31,0x8C,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x11,
                                0x00,0x0F,0x46,0x00,0x1E,0x02,0x58,0x05,0x24,0x44,0x00,0x00,0x01,0x2C,0x01,0x2C,
                                0x20,0x02,0x00,0x00,0x00,0x11,0xFF,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x11,
                                0x00,0x00,0x0F,0x3C,0x00,0x14,0x01,0x90,0x05,0x01,
    11, _AUTOINC,       0xDE,   0x50,0x06,0x41,0x14,0x82,0x05,0x00,0x03,

    4,  _AUTOINC,       0x9F,   0x13,   
    31, _AUTOINC,       0xD4,   0x3E,0x33,0x31,0x31,0xFF,0x42,0xE6,0xF0,0xD7,0xF0,0x00,0x03,0x10,0xFF,0xFF,0x14,
                                0x14,0x04,0x14,0x00,0x10,0x00,0x40,0x01,0x00,0xFA,0xC8,0x02,

    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0x00,0x48,0x1B,0x00,0x01,0xF4,0x00,0xFA,0x14,0x00,0x03,0x03,0x00,0x1E,0x19,
    14, _AUTOINC,       0xCF,   0x8C,0x3C,0x46,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xF4,0x00,0xFA,0x14,0x00,0x03,0x03,0x00,0x1E,0x19,0x78,0x28,0x28,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x14,0x00,

    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M4[] =
{     
    4,  _AUTOINC,       0x9F,   0x12,
    61, _AUTOINC,       0xA0,   0xF4,0x54,0x00,0x00,0x00,0x31,0x9B,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x21,
                                0x00,0x0A,0xC8,0x00,0x19,0x03,0x52,0x05,0x24,0x44,0x00,0x00,0x01,0x2C,0x01,0x2C,
                                0x20,0x02,0x00,0x00,0x00,0x12,0xFF,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x21,
                                0x50,0x00,0x0A,0x64,0x00,0x19,0x01,0x2C,0x05,0x02,
    11, _AUTOINC,       0xDE,   0x50,0x05,0x96,0x05,0xFF,0x08,0x01,0x00,

    4,  _AUTOINC,       0x9F,   0x13,   
    31, _AUTOINC,       0xD4,   0x3E,0x33,0x31,0x31,0xFF,0x42,0xE6,0xF0,0xD7,0xF0,0x00,0x03,0x10,0xFF,0xFF,0x14,
                                0x14,0x04,0x14,0x00,0x10,0x00,0x40,0x01,0x00,0xFA,0xC8,0x02,

    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x28,0x1B,0x00,0x01,0xA8,0x00,0xD4,0x14,0x00,0x03,0x03,0x00,0x1E,0x10,
    14, _AUTOINC,       0xCF,   0x96,0x00,0x8C,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xB8,0x00,0xDC,0x14,0x00,0x03,0x03,0x00,0x1E,0x10,0x8C,0x00,0x3F,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x3C,0x00,
                                            
    _END
};

////////////////////////////////
//Lower Positive Peaking Value//
////////////////////////////////
/*
BYTE code tCOLOR_ULTRAVIVID_SETTING_M1[] =
{    
    4,  _AUTOINC,       0x9F,   0x12,
    61, _AUTOINC,       0xA0,   0xF0,0x6C,0x00,0x00,0x00,0x31,0x96,0x00,0x7E,0x00,0x0E,0xB3,0x00,0x00,0x00,0x11,
                                0x00,0x00,0x78,0x00,0x00,0x02,0x8A,0x06,0x54,0x44,0x00,0x00,0x01,0x2C,0x01,0x2C,
                                0x20,0x01,0x00,0x00,0x00,0x31,0x96,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x11,
                                0x01,0x00,0xC8,0xDC,0x00,0x00,0x02,0xBC,0x06,0x02,
    11, _AUTOINC,       0xDE,   0x51,0x50,0x64,0x00,0xDC,0x06,0x00,0x03,

    4,  _AUTOINC,       0x9F,   0x13, 
    31, _AUTOINC,       0xD4,   0x3E,0x33,0x31,0x31,0xFF,0x42,0xE6,0xF0,0xD7,0xF0,0x00,0x03,0x10,0xFF,0xFF,0x14,
                                0x14,0x04,0x14,0x00,0x10,0x00,0x40,0x01,0x00,0xFA,0xC8,0x02,               

    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x42,0xF0,0x00,0x01,0xF4,0x00,0xFA,0x0F,0x00,0x03,0x03,0x00,0x16,0x00,
    14, _AUTOINC,       0xCF,   0x64,0x0F,0x3C,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xF4,0x00,0xFA,0x0A,0x00,0x03,0x03,0x00,0x0F,0x00,0x64,0x0F,0x0F,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x14,0x00,

    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M2[] =
{    
    4,  _AUTOINC,       0x9F,   0x12,
    61, _AUTOINC,       0xA0,   0xF0,0x6C,0x00,0x00,0x00,0x21,0x64,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x20,
                                0x00,0x00,0xA0,0x00,0x00,0x02,0xBC,0x05,0x54,0x44,0x00,0x00,0x01,0x2C,0x01,0x2C,
                                0x20,0x01,0x00,0x00,0x00,0x21,0xFA,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x20,
                                0x01,0x00,0x00,0xA5,0x00,0x00,0x01,0x90,0x05,0x02,
    11, _AUTOINC,       0xDE,   0x51,0x00,0x96,0x00,0x82,0x05,0x00,0x03,

    4,  _AUTOINC,       0x9F,   0x13,                               
    31, _AUTOINC,       0xD4,   0x3E,0x33,0x31,0x31,0xFF,0x42,0xE6,0xF0,0xD7,0xF0,0x00,0x03,0x10,0xFF,0xFF,0x14,
                                0x14,0x04,0x14,0x00,0x10,0x00,0x40,0x01,0x00,0xFA,0xC8,0x02,
            
    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x28,0x1B,0x00,0x01,0xE0,0x00,0xF0,0x23,0x00,0x03,0x03,0x00,0x34,0x00,
    14, _AUTOINC,       0xCF,   0x8C,0x14,0x5A,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xE0,0x00,0xF0,0x23,0x00,0x03,0x03,0x00,0x34,0x00,0x96,0x0A,0x3F,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x1C,0x00,
    
    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M3[] =
{       
    4,  _AUTOINC,       0x9F,   0x12,
    61, _AUTOINC,       0xA0,   0xF4,0x0C,0x00,0x00,0x00,0x31,0x8C,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x11,
                                0x00,0x00,0x46,0x00,0x00,0x02,0x58,0x05,0x24,0x44,0x00,0x00,0x01,0x2C,0x01,0x2C,
                                0x20,0x02,0x00,0x00,0x00,0x11,0xFF,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x11,
                                0x00,0x00,0x00,0x3C,0x00,0x00,0x01,0x90,0x05,0x01,
    11, _AUTOINC,       0xDE,   0x50,0x00,0x41,0x00,0x82,0x05,0x00,0x03,

    4,  _AUTOINC,       0x9F,   0x13,   
    31, _AUTOINC,       0xD4,   0x3E,0x33,0x31,0x31,0xFF,0x42,0xE6,0xF0,0xD7,0xF0,0x00,0x03,0x10,0xFF,0xFF,0x14,
                                0x14,0x04,0x14,0x00,0x10,0x00,0x40,0x01,0x00,0xFA,0xC8,0x02,

    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0x00,0x48,0x1B,0x00,0x01,0xF4,0x00,0xFA,0x14,0x00,0x03,0x03,0x00,0x1E,0x00,
    14, _AUTOINC,       0xCF,   0x8C,0x3C,0x46,0x00,0x00,0x14,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xF4,0x00,0xFA,0x14,0x00,0x03,0x03,0x00,0x1E,0x00,0x78,0x28,0x28,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x14,0x00,

    _END
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M4[] =
{     
    4,  _AUTOINC,       0x9F,   0x12,
    61, _AUTOINC,       0xA0,   0xF4,0x54,0x00,0x00,0x00,0x31,0x9B,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x21,
                                0x00,0x00,0xC8,0x00,0x00,0x03,0x52,0x05,0x24,0x44,0x00,0x00,0x01,0x2C,0x01,0x2C,
                                0x20,0x02,0x00,0x00,0x00,0x12,0xFF,0x00,0x6E,0x00,0x08,0xC1,0x00,0x00,0x00,0x21,
                                0x50,0x00,0x00,0x64,0x00,0x00,0x01,0x2C,0x05,0x02,
    11, _AUTOINC,       0xDE,   0x50,0x00,0x96,0x00,0xFF,0x08,0x01,0x00,

    4,  _AUTOINC,       0x9F,   0x13,   
    31, _AUTOINC,       0xD4,   0x3E,0x33,0x31,0x31,0xFF,0x42,0xE6,0xF0,0xD7,0xF0,0x00,0x03,0x10,0xFF,0xFF,0x14,
                                0x14,0x04,0x14,0x00,0x10,0x00,0x40,0x01,0x00,0xFA,0xC8,0x02,

    4,  _AUTOINC,       0x9F,   0x14,
    18, _AUTOINC,       0xC0,   0xB0,0x28,0x1B,0x00,0x01,0xA8,0x00,0xD4,0x14,0x00,0x03,0x03,0x00,0x1E,0x00,
    14, _AUTOINC,       0xCF,   0x96,0x00,0x8C,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,
    18, _AUTOINC,       0xE0,   0x01,0xB8,0x00,0xDC,0x14,0x00,0x03,0x03,0x00,0x1E,0x00,0x8C,0x00,0x3F,0x00,
    6,  _AUTOINC,       0xEF,   0x00,0x3C,0x00,
                                            
    _END
};
*/

#endif  // End of #if(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_0)

