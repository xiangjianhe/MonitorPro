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
	0x00,0xFF,0xFF,0xF2,0xF1,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
	0x0C,0x00,0xFF,0xF2,0xF1,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
	0x0B,0x02,0x00,0xE6,0xE3,0xE9,0xE2,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
	0x14,0x01,0x07,0x00,0xF8,0xF1,0xE9,0xE1,0xD9,0xD1,0xD0,0xD0,0xD0,0xD0,0xD0,0xD0,0xD0,
	0x1D,0x03,0x0F,0x07,0x00,0xF8,0xF0,0xE8,0xE0,0xD7,0xCF,0xC6,0xC0,0xC0,0xC0,0xC0,0xC0,
	0x24,0x1D,0x17,0x10,0x08,0x00,0xF8,0xF0,0xE7,0xDF,0xD6,0xCD,0xC3,0xB9,0xB0,0xB0,0xB0,
	0x27,0x23,0x1D,0x16,0x0F,0x08,0x00,0xF8,0xF0,0xE7,0xDE,0xD5,0xCB,0xC1,0xB4,0xA6,0xA0,
	0x29,0x25,0x20,0x1B,0x15,0x0E,0x07,0x00,0xF8,0xF0,0xE7,0xDE,0xD4,0xC9,0xBD,0xAF,0x9F,
	0x28,0x25,0x21,0x1D,0x17,0x12,0x0C,0x06,0x00,0xF9,0xF1,0xE8,0xDF,0xD4,0xC8,0xB9,0xA8,
	0x27,0x24,0x21,0x1E,0x19,0x15,0x10,0x0B,0x06,0x00,0xFA,0xF3,0xEA,0xE1,0xD5,0xC7,0xB5,
	0x25,0x23,0x20,0x1D,0x1A,0x16,0x12,0x0E,0x0A,0x05,0x00,0xFA,0xE5,0xEC,0xE3,0xD6,0xC6,
	0x22,0x20,0x1E,0x1C,0x19,0x16,0x13,0x10,0x0C,0x08,0x04,0x00,0xFB,0xF5,0xED,0xE4,0xD7,
	0x1F,0x1D,0x1B,0x1A,0x17,0x15,0x13,0x10,0x0E,0x0B,0x08,0x04,0x00,0xFB,0xF6,0xEE,0xE4,
	0x1B,0x1A,0x18,0x17,0x15,0x13,0x12,0x10,0x0E,0x0B,0x09,0x06,0x03,0x00,0xFC,0xF6,0xEF,
	0x17,0x16,0x15,0x14,0x13,0x11,0x10,0x0F,0x0D,0x0C,0x0A,0x08,0x06,0x03,0x00,0xFC,0xF7,
	0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x08,0x07,0x05,0x0F,0x00,0xFC,
	0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x08,0x07,0x05,0x0F,0x0F,0x00,
};

#elif(_OD_TABLE_TYPE == _OD_GEN_1)   // Ada.chen 20170331  (Odin)(Gain= 0x47  6.579ms)(Gain= 0x78 4.998ms)

BYTE code tOD_TABLE_COMMON[] =
{	
	0x00,0x01,0x01,0x0E,0x0F,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x0C,0x00,0x01,0x0E,0x0F,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x0B,0x02,0x00,0x1A,0x1D,0x17,0x1E,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
	0x14,0x01,0x07,0x00,0x08,0x0F,0x17,0x1F,0x27,0x2F,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
	0x1D,0x03,0x0F,0x07,0x00,0x08,0x10,0x18,0x20,0x29,0x31,0x3A,0x40,0x40,0x40,0x40,0x40,
	0x24,0x1D,0x17,0x10,0x08,0x00,0x08,0x10,0x19,0x21,0x2A,0x33,0x3D,0x47,0x50,0x50,0x50,
	0x27,0x23,0x1D,0x16,0x0F,0x08,0x00,0x08,0x10,0x19,0x22,0x2B,0x35,0x3F,0x4C,0x5A,0x60,
	0x29,0x25,0x20,0x1B,0x15,0x0E,0x07,0x00,0x08,0x10,0x19,0x22,0x2C,0x37,0x43,0x51,0x61,
	0x28,0x25,0x21,0x1D,0x17,0x12,0x0C,0x06,0x00,0x07,0x0F,0x18,0x21,0x2C,0x38,0x47,0x58,
	0x27,0x24,0x21,0x1E,0x19,0x15,0x10,0x0B,0x06,0x00,0x06,0x0D,0x16,0x1F,0x2B,0x39,0x4B,
	0x25,0x23,0x20,0x1D,0x1A,0x16,0x12,0x0E,0x0A,0x05,0x00,0x06,0x1B,0x14,0x1D,0x2A,0x3A,
	0x22,0x20,0x1E,0x1C,0x19,0x16,0x13,0x10,0x0C,0x08,0x04,0x00,0x05,0x0B,0x13,0x1C,0x29,
	0x1F,0x1D,0x1B,0x1A,0x17,0x15,0x13,0x10,0x0E,0x0B,0x08,0x04,0x00,0x05,0x0A,0x12,0x1C,
	0x1B,0x1A,0x18,0x17,0x15,0x13,0x12,0x10,0x0E,0x0B,0x09,0x06,0x03,0x00,0x04,0x0A,0x11,
	0x17,0x16,0x15,0x14,0x13,0x11,0x10,0x0F,0x0D,0x0C,0x0A,0x08,0x06,0x03,0x00,0x04,0x09,
	0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x08,0x07,0x05,0x0F,0x00,0x04,
	0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0E,0x0D,0x0C,0x0B,0x0A,0x08,0x07,0x05,0x0F,0x0F,0x00,
};
#endif  // End of #if(_OD_TABLE_TYPE == _OD_GEN_0)

