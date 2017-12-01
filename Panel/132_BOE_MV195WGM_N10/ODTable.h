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
{	//Ada.chen    20161017   Gain 0x70 respanse time: 4.823ms ,  Gain 0x40 respanse time: 6.430ms, )
	  0x00, 0xf0, 0xf0, 0xf7, 0xf3, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
	  0x00, 0x00, 0xf0, 0xf7, 0xf3, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
	  0x0a, 0x06, 0x00, 0xfc, 0xf8, 0xf4, 0xf1, 0xeb, 0xe6, 0xe1, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
	  0x12, 0x0c, 0x05, 0x00, 0xfb, 0xf5, 0xf0, 0xeb, 0xe6, 0xe1, 0xdc, 0xd6, 0xd1, 0xd0, 0xd0, 0xd0, 0xd0,
	  0x17, 0x12, 0x0a, 0x05, 0x00, 0xf9, 0xf3, 0xed, 0xe6, 0xe1, 0xdb, 0xd5, 0xd0, 0xc9, 0xc2, 0xc0, 0xc0,
	  0x1d, 0x17, 0x11, 0x0b, 0x05, 0x00, 0xfa, 0xf4, 0xed, 0xe6, 0xdf, 0xd8, 0xd1, 0xcb, 0xc4, 0xbc, 0xb3,
	  0x21, 0x1b, 0x15, 0x10, 0x0b, 0x05, 0x00, 0xf9, 0xf3, 0xec, 0xe6, 0xdf, 0xd7, 0xcf, 0xc6, 0xbd, 0xb4,
	  0x23, 0x1e, 0x19, 0x14, 0x10, 0x0a, 0x05, 0x00, 0xfa, 0xf4, 0xee, 0xe7, 0xdf, 0xd8, 0xcf, 0xc4, 0xb9,
	  0x24, 0x20, 0x1b, 0x17, 0x13, 0x0e, 0x0a, 0x05, 0x00, 0xfa, 0xf5, 0xee, 0xe8, 0xe1, 0xd8, 0xcf, 0xc4,
	  0x24, 0x21, 0x1d, 0x19, 0x16, 0x12, 0x0d, 0x09, 0x04, 0x00, 0xfb, 0xf5, 0xf0, 0xe9, 0xe2, 0xd9, 0xcf,
	  0x23, 0x20, 0x1d, 0x1a, 0x17, 0x13, 0x10, 0x0c, 0x08, 0x04, 0x00, 0xfb, 0xf6, 0xf0, 0xea, 0xe2, 0xd9,
	  0x21, 0x1e, 0x1c, 0x19, 0x17, 0x14, 0x11, 0x0e, 0x0a, 0x07, 0x03, 0x00, 0xf4, 0xf2, 0xf1, 0xeb, 0xe3,
	  0x1e, 0x1c, 0x1a, 0x18, 0x16, 0x13, 0x11, 0x0f, 0x0c, 0x09, 0x06, 0x03, 0x00, 0xe9, 0xf7, 0xf2, 0xeb,
	  0x1c, 0x1a, 0x18, 0x17, 0x15, 0x13, 0x11, 0x0f, 0x0d, 0x0b, 0x09, 0x06, 0x03, 0x00, 0xfd, 0xf9, 0xe4,
	  0x19, 0x18, 0x16, 0x15, 0x13, 0x12, 0x10, 0x0f, 0x0d, 0x0b, 0x09, 0x07, 0x05, 0x02, 0x00, 0xfd, 0xf9,
	  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c, 0x0a, 0x08, 0x07, 0x05, 0x02, 0x00, 0xfd,
	  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c, 0x0a, 0x08, 0x07, 0x05, 0x02, 0x02, 0x00,
};

#elif(_OD_TABLE_TYPE == _OD_GEN_1)

BYTE code tOD_TABLE_COMMON[] =
{	//Ada.chen	  20161017	 Gain 0x70 respanse time: 4.823ms ,  Gain 0x40 respanse time: 6.430ms, )
	  0x00, 0x10, 0x10, 0x09, 0x0d, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
	  0x00, 0x00, 0x10, 0x09, 0x0d, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
	  0x0a, 0x06, 0x00, 0x04, 0x08, 0x0c, 0x0f, 0x15, 0x1a, 0x1f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	  0x12, 0x0c, 0x05, 0x00, 0x05, 0x0b, 0x10, 0x15, 0x1a, 0x1f, 0x24, 0x2a, 0x2f, 0x30, 0x30, 0x30, 0x30,
	  0x17, 0x12, 0x0a, 0x05, 0x00, 0x07, 0x0d, 0x13, 0x1a, 0x1f, 0x25, 0x2b, 0x30, 0x37, 0x3e, 0x40, 0x40,
	  0x1d, 0x17, 0x11, 0x0b, 0x05, 0x00, 0x06, 0x0c, 0x13, 0x1a, 0x21, 0x28, 0x2f, 0x35, 0x3c, 0x44, 0x4d,
	  0x21, 0x1b, 0x15, 0x10, 0x0b, 0x05, 0x00, 0x07, 0x0d, 0x14, 0x1a, 0x21, 0x29, 0x31, 0x3a, 0x43, 0x4c,
	  0x23, 0x1e, 0x19, 0x14, 0x10, 0x0a, 0x05, 0x00, 0x06, 0x0c, 0x12, 0x19, 0x21, 0x28, 0x31, 0x3c, 0x47,
	  0x24, 0x20, 0x1b, 0x17, 0x13, 0x0e, 0x0a, 0x05, 0x00, 0x06, 0x0b, 0x12, 0x18, 0x1f, 0x28, 0x31, 0x3c,
	  0x24, 0x21, 0x1d, 0x19, 0x16, 0x12, 0x0d, 0x09, 0x04, 0x00, 0x05, 0x0b, 0x10, 0x17, 0x1e, 0x27, 0x31,
	  0x23, 0x20, 0x1d, 0x1a, 0x17, 0x13, 0x10, 0x0c, 0x08, 0x04, 0x00, 0x05, 0x0a, 0x10, 0x16, 0x1e, 0x27,
	  0x21, 0x1e, 0x1c, 0x19, 0x17, 0x14, 0x11, 0x0e, 0x0a, 0x07, 0x03, 0x00, 0x0c, 0x0e, 0x0f, 0x15, 0x1d,
	  0x1e, 0x1c, 0x1a, 0x18, 0x16, 0x13, 0x11, 0x0f, 0x0c, 0x09, 0x06, 0x03, 0x00, 0x17, 0x09, 0x0e, 0x15,
	  0x1c, 0x1a, 0x18, 0x17, 0x15, 0x13, 0x11, 0x0f, 0x0d, 0x0b, 0x09, 0x06, 0x03, 0x00, 0x03, 0x07, 0x1c,
	  0x19, 0x18, 0x16, 0x15, 0x13, 0x12, 0x10, 0x0f, 0x0d, 0x0b, 0x09, 0x07, 0x05, 0x02, 0x00, 0x03, 0x07,
	  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c, 0x0a, 0x08, 0x07, 0x05, 0x02, 0x00, 0x03,
	  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c, 0x0a, 0x08, 0x07, 0x05, 0x02, 0x02, 0x00,
};
#endif  // End of #if(_OD_TABLE_TYPE == _OD_GEN_0)

