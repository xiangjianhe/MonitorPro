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
// ID Code      : ODTable.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// OD TABLE
//****************************************************************************
#if(_OD_TABLE_TYPE == _OD_GEN_0)
BYTE code tOD_TABLE_COMMON[] =
{
	0x00,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x38,0x00,0xF8,0xF6,0xF5,0xF5,0xF4,0xF4,0xF3,0xF2,0xF1,0xF1,0xF0,0xF0,0xF0,0xF0,0xF0,
    0x50,0x18,0x00,0xED,0xE8,0xE6,0xE6,0xE5,0xE5,0xE4,0xE4,0xE4,0xE3,0xE2,0xE1,0xE1,0xE0,
    0x64,0x2D,0x16,0x00,0xEE,0xE0,0xDB,0xD8,0xD7,0xD7,0xD6,0xD5,0xD5,0xD4,0xD4,0xD3,0xD2,
    0x66,0x3B,0x26,0x11,0x00,0xF1,0xE6,0xDC,0xD3,0xCD,0xCA,0xC8,0xC7,0xC6,0xC5,0xC5,0xC5,
    0x61,0x40,0x30,0x1C,0x0D,0x00,0xF6,0xEC,0xE4,0xDA,0xCF,0xC5,0xBD,0xB9,0xB7,0xB7,0xB6,
    0x59,0x3E,0x33,0x25,0x16,0x0A,0x00,0xF7,0xEF,0xE7,0xDD,0xCF,0xC4,0xB6,0xAE,0xAB,0xA9,
    0x4F,0x39,0x30,0x26,0x1C,0x12,0x09,0x00,0xF9,0xF0,0xE6,0xDD,0xD0,0xC2,0xB7,0xAB,0xA7,
    0x42,0x31,0x2A,0x22,0x1A,0x14,0x0E,0x07,0x00,0xF8,0xEF,0xE5,0xD7,0xCB,0xC0,0xB5,0xAE,
    0x36,0x2A,0x24,0x1D,0x18,0x14,0x0F,0x0A,0x06,0x00,0xF9,0xF0,0xE3,0xD6,0xCB,0xC0,0xB8,
    0x2B,0x21,0x1D,0x1A,0x16,0x12,0x0E,0x0B,0x08,0x05,0x00,0xFA,0xF2,0xE7,0xDC,0xD3,0xCE,
    0x20,0x19,0x16,0x14,0x11,0x0F,0x0E,0x0D,0x0B,0x08,0x04,0x00,0xFB,0xF4,0xEB,0xE7,0xE1,
    0x18,0x13,0x11,0x11,0x0E,0x0D,0x0B,0x09,0x09,0x07,0x06,0x03,0x00,0xFD,0xF8,0xF3,0xEF,
    0x24,0x12,0x11,0x0F,0x0E,0x0E,0x0D,0x0B,0x0B,0x0A,0x08,0x06,0x03,0x00,0xFD,0xFA,0xF9,
    0x00,0x14,0x1A,0x14,0x13,0x13,0x11,0x10,0x0F,0x0E,0x0C,0x0A,0x07,0x04,0x00,0xFD,0xFA,
    0x00,0x04,0x0C,0x0F,0x0C,0x0C,0x0F,0x0C,0x0F,0x0F,0x0C,0x0C,0x0C,0x0E,0x0F,0x00,0x00,
    0x00,0x00,0x03,0x00,0x03,0x03,0x00,0x03,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x00,0x00,

/*
    0x00,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,
    0x04,0x00,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,0xFD,
    0x09,0x05,0x00,0xFF,0x00,0xFE,0xFA,0xFD,0xFA,0xFA,0xFA,0xFD,0xFA,0xFA,0xFA,0xFA,0xFA,
    0x11,0x07,0x04,0x00,0xFF,0xFC,0xFC,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF7,0xF0,
    0x17,0x0F,0x09,0x04,0x00,0xFD,0xFA,0xFB,0xF4,0xF4,0xF4,0xF4,0xF4,0xF1,0xED,0xE7,0xE4,
    0x1B,0x14,0x0D,0x08,0x03,0x00,0xFD,0xFA,0xF3,0xF3,0xF3,0xF0,0xEE,0xE9,0xE4,0xDD,0xDA,
    0x21,0x18,0x12,0x0D,0x08,0x04,0x00,0xFD,0xF8,0xF3,0xF1,0xEE,0xE9,0xE5,0xE2,0xD6,0xD4,
    0x27,0x1C,0x1B,0x14,0x0F,0x0A,0x05,0x00,0xFC,0xF8,0xF3,0xEF,0xE9,0xE3,0xE1,0xD6,0xCE,
    0x2B,0x21,0x20,0x1E,0x16,0x12,0x0D,0x07,0x00,0xFC,0xF7,0xF1,0xEB,0xE3,0xDF,0xD5,0xCC,
    0x2F,0x25,0x25,0x21,0x1B,0x1B,0x14,0x0E,0x08,0x00,0xFA,0xF3,0xEC,0xE2,0xDE,0xD6,0xCB,
    0x32,0x27,0x25,0x21,0x1E,0x1E,0x1B,0x15,0x0F,0x08,0x00,0xFA,0xF0,0xE5,0xDE,0xD6,0xCC,
    0x2E,0x26,0x25,0x23,0x21,0x1F,0x1B,0x18,0x12,0x0F,0x08,0x00,0xF7,0xE9,0xDF,0xD7,0xD0,
    0x29,0x24,0x24,0x23,0x20,0x20,0x1E,0x19,0x15,0x10,0x0D,0x08,0x00,0xF3,0xE1,0xDC,0xD4,
    0x24,0x21,0x20,0x1F,0x1D,0x1D,0x1B,0x19,0x17,0x14,0x12,0x0D,0x09,0x00,0xF3,0xE4,0xDD,
    0x1B,0x17,0x19,0x17,0x17,0x17,0x17,0x17,0x14,0x12,0x10,0x0D,0x0A,0x09,0x00,0xF0,0xE6,
    0x11,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0A,0x0B,0x0B,0x0B,0x0A,0x09,0x08,0x00,0xF1,
    0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x00,
*/    
};

#elif(_OD_TABLE_TYPE == _OD_GEN_1)

BYTE code tOD_TABLE_COMMON[] =
{
    0x00,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x38,0x00,0x08,0x0A,0x0B,0x0B,0x0C,0x0C,0x0D,0x0E,0x0F,0x0F,0x10,0x10,0x10,0x10,0x10,
    0x50,0x18,0x00,0x13,0x18,0x1A,0x1A,0x1B,0x1B,0x1C,0x1C,0x1C,0x1D,0x1E,0x1F,0x1F,0x20,
    0x64,0x2D,0x16,0x00,0x12,0x20,0x25,0x28,0x29,0x29,0x2A,0x2B,0x2B,0x2C,0x2C,0x2D,0x2E,
    0x66,0x3B,0x26,0x11,0x00,0x0F,0x1A,0x24,0x2D,0x33,0x36,0x38,0x39,0x3A,0x3B,0x3B,0x3B,
    0x61,0x40,0x30,0x1C,0x0D,0x00,0x0A,0x14,0x1C,0x26,0x31,0x3B,0x43,0x47,0x49,0x49,0x4A,
    0x59,0x3E,0x33,0x25,0x16,0x0A,0x00,0x09,0x11,0x19,0x23,0x31,0x3C,0x4A,0x52,0x55,0x57,
    0x4F,0x39,0x30,0x26,0x1C,0x12,0x09,0x00,0x07,0x10,0x1A,0x23,0x30,0x3E,0x49,0x55,0x59,
    0x42,0x31,0x2A,0x22,0x1A,0x14,0x0E,0x07,0x00,0x08,0x11,0x1B,0x29,0x35,0x40,0x4B,0x52,
    0x36,0x2A,0x24,0x1D,0x18,0x14,0x0F,0x0A,0x06,0x00,0x07,0x10,0x1D,0x2A,0x35,0x40,0x48,
    0x2B,0x21,0x1D,0x1A,0x16,0x12,0x0E,0x0B,0x08,0x05,0x00,0x06,0x0E,0x19,0x24,0x2D,0x32,
    0x20,0x19,0x16,0x14,0x11,0x0F,0x0E,0x0D,0x0B,0x08,0x04,0x00,0x05,0x0C,0x15,0x19,0x1F,
    0x18,0x13,0x11,0x11,0x0E,0x0D,0x0B,0x09,0x09,0x07,0x06,0x03,0x00,0x03,0x08,0x0D,0x11,
    0x24,0x12,0x11,0x0F,0x0E,0x0E,0x0D,0x0B,0x0B,0x0A,0x08,0x06,0x03,0x00,0x03,0x06,0x07,
    0x00,0x14,0x1A,0x14,0x13,0x13,0x11,0x10,0x0F,0x0E,0x0C,0x0A,0x07,0x04,0x00,0x03,0x06,
    0x00,0x04,0x0C,0x0F,0x0C,0x0C,0x0F,0x0C,0x0F,0x0F,0x0C,0x0C,0x0C,0x0E,0x0F,0x00,0x00,
    0x00,0x00,0x03,0x00,0x03,0x03,0x00,0x03,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x00,0x00,
/*
    0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x04,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
    0x09,0x05,0x00,0x01,0x00,0x02,0x06,0x03,0x06,0x06,0x06,0x03,0x06,0x06,0x06,0x06,0x06,
    0x0B,0x07,0x04,0x00,0x01,0x04,0x04,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x10,
    0x11,0x0F,0x09,0x04,0x00,0x03,0x06,0x05,0x0C,0x0C,0x0C,0x0C,0x0C,0x0F,0x13,0x19,0x1C,
    0x1B,0x14,0x0D,0x08,0x03,0x00,0x03,0x06,0x0D,0x0D,0x0D,0x10,0x12,0x17,0x1C,0x23,0x26,
    0x15,0x18,0x12,0x0D,0x08,0x04,0x00,0x03,0x08,0x0D,0x0F,0x12,0x17,0x1B,0x1E,0x2A,0x2C,
    0x17,0x1C,0x1B,0x14,0x0F,0x0A,0x05,0x00,0x04,0x08,0x0D,0x11,0x17,0x1D,0x1F,0x2A,0x32,
    0x1B,0x21,0x20,0x1E,0x16,0x12,0x0D,0x07,0x00,0x04,0x09,0x0F,0x15,0x1D,0x21,0x2B,0x34,
    0x1F,0x20,0x20,0x21,0x1B,0x1B,0x14,0x0E,0x08,0x00,0x06,0x0D,0x14,0x1E,0x22,0x2A,0x35,
    0x24,0x1F,0x1F,0x21,0x1E,0x1E,0x1B,0x15,0x0F,0x08,0x00,0x06,0x10,0x1B,0x22,0x2A,0x34,
    0x22,0x1A,0x1B,0x20,0x21,0x1F,0x1B,0x18,0x12,0x0F,0x08,0x00,0x09,0x17,0x21,0x29,0x30,	
    0x1A,0x18,0x19,0x1E,0x20,0x20,0x1E,0x19,0x15,0x10,0x0D,0x08,0x00,0x0D,0x1F,0x24,0x2C,
    0x16,0x16,0x15,0x16,0x16,0x16,0x17,0x16,0x16,0x14,0x12,0x0D,0x09,0x00,0x0D,0x1C,0x23,
    0x13,0x10,0x12,0x11,0x12,0x12,0x12,0x12,0x11,0x11,0x10,0x0D,0x0A,0x09,0x00,0x10,0x1A,
    0x11,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0B,0x0A,0x0B,0x0B,0x0B,0x0A,0x09,0x08,0x00,0x0F,
    0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x00,	
*/    
};
#endif  // End of #if(_OD_TABLE_TYPE == _TYPE_0)

