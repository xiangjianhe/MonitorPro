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
// ID Code      : UserOSDFont.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFONT__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Char Alias
//--------------------------------------------------

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
BYTE code tFONT_GLOBAL[]=
{
    0x0f,0xc8,0x1e,0x37,0x2a,0x64,0x5b,0x9d,0x02,0x4e,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x80,0x3d,0xb0,0x0e,0x76,0x17,0xb3,0xe0,0x34,0x7b,0x2a,
    0x55,0x7b,0x07,0x00,0x00,0x34,0x58,0xa5,0xd9,0xc7,0xc2,0xd4,
    0x6e,0x9c,0x74,0x9f,0x13,0x55,0x50,0x05,0x55,0x50,0x05,0x29,
    0x10,0x00,0x00,0x80,0xe7,0x81,0xe7,0x81,0xe7,0x81,0xe7,0x81,
    0xf5,0x80,0x05,0x00,0x00,0x00,0x00,0x04,0x54,0xa0,0x0a,0xaa,
    0xa0,0x0a,0xaa,0x00,0x00,0x00,0x16,0x78,0x16,0x3c,0x0f,0x3c,
    0x0f,0x3c,0x0f,0x3c,0x8f,0x54,0xed,0x9d,0x62,0x76,0x1f,0x58,
    0x53,0xcd,0x76,0x16,0xcc,0x06,0x00,0x00,0xe9,0x3e,0x27,0x47,
    0xb3,0x8b,0xb1,0x70,0x76,0xa3,0x16,0x68,0x00,0x00,0x00,0x00,
    0x00,0x38,0x1b,0xf3,0x17,0x9c,0xf9,0xb1,0x6b,0x66,0x2c,0x9c,
    0xdd,0x00,0x00,0x00,0xe8,0x86,0x6e,0xe8,0x96,0x24,0x89,0xbd,
    0x51,0x63,0x76,0x9f,0x19,0xd6,0xfc,0xfd,0xd8,0x4e,0xc0,0x06,
    0x00,0x00,0x40,0xb2,0x03,0xe9,0x04,0xdd,0xd0,0x0d,0x1a,0x00,
    0x00,0x00,0x00,0x00,0x80,0x19,0x98,0x81,0x19,0x24,0x49,0x82,
    0x2a,0x00,0x00,0x00,0x58,0xa5,0xf9,0xc6,0xa2,0x7f,0xb5,0x5b,
    0xf7,0xb1,0x8a,0x49,0xa4,0x98,0x48,0xcc,0xc0,0x0c,0x18,0x00,
    0x00,0x00,0xec,0xae,0x36,0x8b,0xee,0xd3,0x7c,0x7f,0x85,0x15,
    0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x92,0x9c,0x1d,0x74,0x43,
    0xb7,0xa7,0xf3,0xbd,0xaf,0x7b,0xf5,0xfd,0x5d,0x00,0x00,0x00,
    0x59,0x95,0xc4,0x0c,0xcc,0xe0,0xfe,0x7c,0x9e,0xf7,0xbe,0x3f,
    0x9f,0xcf,0x73,0x5f,0xdd,0xf7,0x7d,0x93,0xbe,0x2f,0x74,0x4b,
    0x9c,0x46,0xec,0x00,0x00,0x00,0xdc,0x9f,0xcf,0xfb,0xb9,0xcd,
    0xcf,0xfb,0x33,0x83,0xac,0x09,0x94,0x04,0x00,0x00,0x00,0x00,
    0x00,0x20,0xc9,0xd9,0x41,0x37,0x74,0x73,0xcf,0xfd,0xfd,0xeb,
    0xf7,0xfe,0xde,0x00,0x00,0x00,0xb2,0x2a,0x89,0x19,0x98,0xc1,
    0xcc,0xdf,0x75,0xce,0xcc,0x5c,0xd7,0xb8,0xef,0xfb,0xc6,0xf4,
    0xf7,0x0f,0xdd,0x12,0xa7,0x11,0x3b,0x00,0x00,0x00,0x33,0x73,
    0x5d,0x63,0xc6,0x19,0x33,0xc8,0x9a,0x40,0x49,0x00,0x00,0x00,
    0x5c,0x1b,0xae,0x0b,0xae,0x0b,0xae,0x0b,0xb9,0xae,0xbd,0xe3,
    0xba,0xe0,0xba,0xe0,0xba,0x60,0x5f,0x20,0x12,0x00,0x00,0x00,
    0x00,0x00,0x12,0x81,0x48,0xd0,0x0d,0xdd,0xd0,0x0d,0xdd,0xd0,
    0x0d,0xdd,0xd0,0x2d,0x11,0x88,0x04,0x55,0x50,0x05,0x55,0x50,
    0x05,0x55,0x50,0x05,0x55,0x12,0x81,0x48,0xb0,0x16,0xac,0x05,
    0x6b,0xc1,0x5a,0xb0,0x16,0xac,0x05,0x6b,0x49,0x04,0x22,0x41,
    0x02,0x09,0x24,0x90,0x40,0x02,0x09,0x24,0x12,0x81,0x48,0x8a,
    0xa4,0x8a,0xa4,0x8a,0xa4,0x8a,0xa4,0x8a,0xa4,0x8a,0xa4,0x8a,
    0xa4,0x12,0x81,0x48,0x16,0xc9,0x5a,0x24,0x6b,0x91,0xac,0x45,
    0xb2,0x16,0xc9,0x5a,0x24,0x6b,0x91,0xac,0x44,0x20,0x92,0x90,
    0x24,0x24,0x09,0x49,0x42,0x92,0x90,0x24,0x24,0x09,0x49,0x12,
    0x81,0x48,0xd2,0x9d,0x24,0xdd,0x49,0xd2,0x9d,0x24,0xdd,0x49,
    0xd2,0x9d,0x24,0xdd,0x49,0xd2,0x9d,0x24,0x11,0x88,0x24,0x55,
    0x49,0x52,0x95,0x24,0x55,0x49,0x52,0x95,0x24,0x55,0x49,0x52,
    0x95,0x24,0x55,0x49,0x12,0x81,0x48,0x92,0x24,0x49,0x92,0x24,
    0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x44,
    0xc0,0x5b,0xf0,0xbe,0xf0,0xbe,0x36,0xef,0xbb,0x53,0xf5,0xbe,
    0xd9,0xbc,0xef,0xc6,0xfb,0xc2,0xfb,0x42,0xbd,0x80,0xc0,0x29,
    0xa8,0x82,0x2a,0xa8,0x82,0x2a,0xa8,0x03,0x01,0x80,0xc0,0xda,
    0xb0,0x37,0xec,0x0d,0x7b,0xc3,0xde,0xb0,0x17,0x04,0xf8,0xff,
};

BYTE code tICON_REALTEK_2BIT_ICON[]=
{
    0x07,0xf8,0xec,0x13,0x64,0x9b,0xa2,0x5d,0x02,0x0d,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf4,0x5a,0x7b,
    0x77,0xad,0xb5,0xf7,0x5f,0xf5,0xb2,0x2b,0xdd,0x24,0xab,0x09,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0xdb,0xa6,0x67,0xce,0x69,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x60,0x77,0x9f,0xb3,0xab,0xfb,0x9c,0xb7,0xf4,0x3e,
    0x35,0xec,0x3d,0xc3,0xde,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x80,0x80,0x04,0x12,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x14,0x59,0xdd,0x55,
    0x67,0xad,0xee,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xd4,0xcc,0x39,0x05,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9c,0xc6,0x01,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd2,
    0x4d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x80,0xaa,0xda,0xbb,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x80,0x54,0xcd,0x04,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xf7,0x5a,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x90,0xd3,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xae,0xe1,
    0xa8,0x82,0x2a,0x48,0xce,0xae,0xca,0xb5,0xae,0xe4,0xca,0xfb,
    0xf4,0x7b,0x5d,0x9f,0xcf,0xfa,0xb8,0x7c,0x3f,0x5f,0xf8,0x02,
    0x00,0x00,0x00,0x00,0x00,0x00,0xee,0x7b,0x6f,0xb5,0xee,0xbd,
    0x39,0x86,0xae,0x54,0xa9,0x99,0x4a,0xe5,0x9a,0xaa,0x72,0x5d,
    0xa9,0xaf,0x24,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8b,
    0x9c,0x41,0x55,0x63,0x8a,0xd5,0x33,0x55,0xe7,0x62,0xe6,0xef,
    0x61,0xff,0xfd,0x7e,0x9c,0x9f,0x7b,0xe6,0x77,0xc3,0x0d,0x00,
    0x00,0x00,0x00,0x00,0x00,0x48,0x20,0x81,0x04,0x12,0x48,0x20,
    0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x59,0xab,
    0xfb,0x94,0xae,0xce,0x50,0xb5,0x8a,0xe7,0x99,0x5a,0xdd,0x5d,
    0x67,0xa6,0x3b,0x8c,0xde,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x2c,0xce,0x59,0x8b,0x73,0x56,0xcd,0x9c,0x53,0x8b,0x73,
    0xd6,0xe2,0x9c,0x55,0xe3,0x9c,0xc5,0x38,0x05,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x40,0x56,0x93,0x35,0x8b,0xea,0xcc,0xde,
    0xab,0x2a,0xe7,0xb4,0x53,0x49,0xd9,0x67,0x2e,0x6c,0x03,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x74,0x93,0x74,0x93,0x74,
    0x93,0x74,0xb7,0xa4,0x7b,0x75,0x52,0x3d,0x2b,0x94,0x09,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7b,0x86,0xbd,0x67,0xd8,
    0x7b,0x86,0xbd,0x67,0xd8,0x7b,0x86,0xbd,0x67,0xc6,0x66,0xcc,
    0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xdd,0x24,0xdd,
    0x24,0x55,0x24,0xdd,0x24,0xdd,0x24,0xd5,0x84,0x22,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xe4,0x69,0x92,0x7a,0x49,0x66,
    0xd6,0x4a,0xaa,0x48,0xde,0x22,0xe9,0x67,0x09,0x6d,0x05,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xac,0x01,0x0d,0x40,0x83,
    0x59,0x9a,0x2a,0x90,0x05,0x00,0xff,
};


BYTE code tICON_MAIN_MENU_2BIT_ICON[]=
{
    0x0f,0x18,0x4e,0x23,0x7c,0x69,0xa5,0xbd,0x09,0x07,0x00,0x00,
    0x00,0x00,0x00,0xb4,0x70,0xa1,0x0a,0x00,0x00,0x00,0x00,0x00,
    0x57,0x20,0x09,0x01,0x00,0x00,0x00,0x00,0x80,0x48,0x00,0x00,
    0x00,0x00,0x00,0x00,0x12,0x21,0x49,0x12,0x00,0x00,0x00,0x00,
    0x00,0x88,0x04,0x00,0x00,0x00,0x00,0x00,0x20,0x11,0x92,0x24,
    0x01,0x00,0x00,0x00,0x00,0xa0,0x90,0xa5,0x1b,0x00,0x00,0x00,
    0x00,0x00,0x2c,0x42,0x48,0x82,0x2a,0xa8,0x82,0x2a,0xa8,0x82,
    0x2a,0xa8,0x82,0x2a,0xa8,0x42,0x55,0x49,0x42,0x02,0x09,0x24,
    0x90,0x40,0x02,0x09,0x24,0x90,0x14,0x02,0x00,0x40,0x81,0x36,
    0x6c,0x76,0x81,0xd9,0x3c,0xa7,0x71,0x0f,0x92,0x24,0x01,0x00,
    0x0d,0xd7,0xdd,0x54,0xd6,0x4d,0xb2,0xd6,0xa9,0xe4,0xbd,0xaf,
    0x2b,0x39,0xbf,0x24,0x00,0xa0,0x71,0x0c,0x60,0x36,0x76,0x43,
    0x01,0x00,0x92,0x24,0x01,0x2e,0x90,0xee,0x92,0xdc,0xf7,0xa9,
    0x64,0xdd,0xd7,0x95,0x64,0x25,0x49,0x92,0x24,0x49,0x12,0xdd,
    0xd0,0x0d,0xdd,0xd0,0x0d,0xdd,0xd0,0x0d,0xdd,0xd0,0xdd,0xe8,
    0x1e,0x42,0x92,0x40,0x02,0x09,0x24,0x90,0x40,0x02,0x09,0x24,
    0x74,0xc7,0xde,0x55,0x50,0x05,0x55,0x50,0x05,0x55,0x50,0x05,
    0x55,0x50,0xe5,0x0a,0x3a,0x55,0x24,0x90,0x40,0x92,0x90,0x24,
    0x24,0x09,0x49,0x42,0x92,0x10,0xc2,0x55,0x9a,0x5a,0x9c,0x2e,
    0xb5,0x00,0x00,0x00,0x00,0x24,0xc2,0xca,0x95,0x2c,0x89,0x6b,
    0x51,0x48,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x84,0x48,0x00,0x20,0xab,0x02,0x00,0x00,0x00,0x90,0x08,0x49,
    0x92,0x24,0x49,0xc2,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,
    0x49,0x92,0x24,0x49,0x42,0x24,0xba,0x67,0xe8,0x36,0x74,0x6b,
    0xba,0xa1,0x1b,0xba,0xa1,0x1b,0xba,0xb1,0x88,0x0a,0xdd,0x09,
    0xdd,0x09,0x24,0x24,0x09,0x49,0x42,0x92,0x90,0x24,0x24,0x81,
    0x2c,0x00,0x00,0x00,0x00,0x00,0x36,0x14,0x18,0x00,0x00,0x00,
    0x00,0x00,0x2a,0xc1,0x25,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x80,0x24,0x49,0x88,0x04,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x49,0x12,
    0x22,0x01,0x00,0x00,0x00,0x00,0x60,0xa0,0xc1,0x06,0x00,0x00,
    0x00,0x00,0xa0,0x49,0x2c,0xe4,0x56,0xa0,0x0a,0xaa,0xa0,0x0a,
    0xaa,0x40,0x01,0x00,0x80,0x0b,0xae,0x0b,0xae,0x0b,0xae,0x0b,
    0xae,0x0b,0xae,0x0b,0xae,0x0b,0xae,0xeb,0x14,0xd7,0xa5,0xb8,
    0x76,0x1b,0x76,0xf7,0xcc,0xde,0xdd,0x33,0x7b,0x77,0xcf,0xec,
    0xdd,0x3d,0xb3,0x69,0xb3,0x01,0xe2,0x0a,0x71,0xa5,0x68,0x8a,
    0xee,0x2a,0xba,0xab,0xe8,0xae,0xa2,0xbb,0xa0,0x0b,0x4d,0x22,
    0x0d,0xdd,0x7c,0x7c,0xf1,0xf9,0x7c,0xbf,0x7c,0x3e,0xdf,0x2f,
    0x9f,0xcf,0xf7,0xcb,0xe7,0xf3,0xfd,0xe2,0xe3,0x0b,0x20,0x12,
    0x22,0x31,0x36,0x66,0xf6,0x66,0x66,0x6f,0x66,0xf6,0x66,0x66,
    0x6f,0x8c,0x0d,0x48,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x58,0xb0,0x16,0xac,0x05,0x6b,0xc1,0x5a,0xb0,0x16,0xac,0x45,
    0x5b,0x8b,0x75,0xaf,0x45,0xdf,0x0b,0xd8,0x30,0xa0,0x00,0x40,
    0x01,0x40,0x01,0xb8,0xe0,0xaa,0x84,0x43,0x00,0x00,0x80,0x2a,
    0x00,0x00,0x00,0x00,0x0d,0x06,0x9b,0x1e,0x80,0x1a,0x7a,0x1b,
    0x0c,0x20,0x49,0x12,0x27,0x92,0x2b,0x07,0x7d,0x72,0x55,0x5c,
    0xa7,0x6f,0xa4,0x5b,0x73,0xdd,0x4e,0xe2,0x04,0x00,0x00,0x0d,
    0x65,0xa3,0x6d,0x05,0x4c,0xd9,0x28,0x05,0x20,0x49,0x12,0xb2,
    0x92,0x90,0x45,0xee,0x95,0x50,0x59,0x20,0x2d,0x85,0x65,0x25,
    0x01,0x06,0x36,0x68,0x00,0x0d,0x06,0x00,0x06,0xb0,0x60,0x35,
    0xc9,0x0d,0x01,0x00,0xe8,0x86,0xfb,0x86,0x6e,0x00,0x00,0x00,
    0x00,0x00,0x00,0x2d,0x5c,0xa8,0x02,0x00,0x00,0x00,0x00,0xc0,
    0x15,0x48,0x42,0x00,0x00,0x00,0x00,0x00,0x20,0x12,0x00,0x00,
    0x00,0x00,0x00,0x80,0x44,0x48,0x92,0x04,0x00,0x00,0x00,0x00,
    0x00,0x22,0x01,0x00,0x00,0x00,0x00,0x00,0x48,0x84,0x24,0x49,
    0x00,0x00,0x00,0x00,0x00,0x28,0x64,0xe9,0x06,0x00,0x00,0x00,
    0x00,0x00,0x8b,0x10,0x92,0xa0,0x0a,0xaa,0xa0,0x0a,0xaa,0xa0,
    0x0a,0xaa,0xa0,0x0a,0xaa,0xa0,0x4a,0x12,0x12,0x48,0x20,0x81,
    0x04,0x12,0x48,0xce,0x21,0x39,0x87,0xe4,0x1c,0x02,0x00,0x00,
    0x00,0x00,0x00,0x00,0x24,0x49,0x02,0x00,0x00,0x00,0xdc,0xa7,
    0xa4,0xef,0xe7,0xe1,0xee,0xe7,0xa9,0x34,0x00,0x00,0x00,0x00,
    0x00,0x00,0x90,0x24,0x09,0x00,0x00,0x00,0x50,0x9d,0xb3,0xaa,
    0xba,0xd5,0xfb,0x76,0x2e,0xa5,0x1b,0xba,0xa1,0x1b,0xba,0xa1,
    0x1b,0xba,0xa1,0x1b,0xba,0xa1,0x1b,0x21,0x49,0x20,0x81,0x04,
    0x12,0x48,0x20,0xe1,0xee,0x84,0xfb,0x4e,0xb8,0x3b,0xa8,0x82,
    0x2a,0xa8,0x82,0x2a,0xa8,0x82,0x2a,0xa8,0x82,0x2a,0x57,0xd0,
    0x39,0x87,0xc4,0x21,0x81,0x04,0x12,0x48,0x20,0x09,0x92,0x84,
    0x10,0x2e,0x00,0x00,0x00,0x00,0x00,0x80,0x44,0xb8,0xcf,0xc3,
    0x4d,0xf1,0x00,0x00,0x00,0x24,0x42,0x92,0x24,0x44,0x02,0x00,
    0x00,0x00,0x00,0x00,0x90,0x08,0x6f,0x77,0xd5,0x4b,0xa4,0x00,
    0x00,0x00,0x12,0x21,0x49,0x12,0x22,0xd1,0x0d,0xdd,0xd0,0x0d,
    0xdd,0xd0,0x0d,0xdd,0xd0,0x0d,0xdd,0x58,0x44,0x85,0xfb,0x4e,
    0xd0,0x09,0x24,0x90,0x40,0x02,0x09,0x91,0x90,0x04,0xb2,0x00,
    0x00,0x00,0x00,0x00,0xd8,0x50,0x60,0x00,0x00,0x00,0x00,0x00,
    0xa8,0x04,0x97,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x92,0x24,0x21,0x12,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x24,0x49,0x88,0x04,
    0x00,0x00,0x00,0x00,0x80,0x81,0x06,0x1b,0x00,0x00,0x00,0x00,
    0x80,0x26,0xb1,0x90,0x1b,0xa0,0xa0,0x36,0x14,0xb0,0x41,0x01,
    0x00,0x80,0x0b,0xae,0xab,0x70,0x5d,0xbb,0xb8,0xae,0xbd,0xb9,
    0xae,0x2a,0xae,0x0b,0xae,0x0b,0xae,0x0b,0xae,0x0b,0xae,0x61,
    0x80,0xfd,0x96,0x46,0x01,0xd5,0x98,0xd9,0xb3,0xdf,0xda,0x3f,
    0x4c,0x0f,0x7b,0xc3,0xdb,0x1c,0x0e,0x7d,0x3f,0x5a,0x55,0xe9,
    0xae,0xeb,0x3e,0x74,0x55,0x9f,0x3a,0xf7,0xe3,0x1e,0x1c,0x4d,
    0xdd,0xf0,0x00,0xd3,0xd8,0x9b,0xf2,0xbe,0x65,0xf6,0xf0,0xd9,
    0xef,0x0c,0x3d,0x3d,0x60,0x43,0x57,0x7d,0x18,0xe0,0x68,0xea,
    0x86,0xc7,0x72,0xaa,0x1f,0x75,0x3f,0xa7,0xd1,0xd3,0xc2,0x3b,
    0x30,0x56,0x71,0x00,0x00,0x00,0xd0,0x03,0xb3,0x61,0x40,0x6f,
    0x30,0x16,0xac,0x05,0x6b,0xc1,0x5a,0xb0,0x16,0xd3,0x6b,0xb1,
    0x67,0x2d,0xf6,0x5e,0x8b,0x99,0xb5,0xd0,0x0b,0xd8,0x30,0xa0,
    0x00,0x40,0x01,0x40,0x01,0xb8,0xe0,0xaa,0x84,0x43,0x00,0x00,
    0x80,0x2a,0x00,0x00,0x00,0x00,0x0d,0x06,0x9b,0x1e,0x80,0x1a,
    0x7a,0x1b,0x0c,0x20,0x49,0x12,0x27,0x92,0x2b,0x07,0x7d,0x72,
    0x55,0x5c,0xa7,0x6f,0xa4,0x5b,0x73,0xdd,0x4e,0xe2,0x04,0x00,
    0x00,0x0d,0x65,0xa3,0x6d,0x05,0x4c,0xd9,0x28,0x05,0x20,0x49,
    0x12,0xb2,0x92,0x90,0x45,0xee,0x95,0x50,0x59,0x20,0x2d,0x85,
    0x65,0x25,0x01,0x06,0x36,0x68,0x00,0xc0,0x00,0xc0,0x00,0x16,
    0xac,0x26,0xb9,0x21,0x00,0x00,0xdd,0x70,0xdf,0xd0,0x0d,0x00,
    0x00,0x00,0x00,0x00,0xa0,0x85,0x0b,0x55,0x00,0x00,0x00,0x00,
    0x00,0xb8,0x02,0x49,0x08,0x00,0x00,0x00,0x00,0x00,0x44,0x02,
    0x00,0x00,0x00,0x00,0x00,0x90,0x08,0x49,0x92,0x00,0x00,0x00,
    0x00,0x00,0x40,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x89,0x90,
    0x24,0x09,0x00,0x00,0x00,0x00,0x00,0x85,0x2c,0xdd,0x00,0x00,
    0x00,0x00,0x00,0x60,0x11,0x42,0x12,0x54,0x41,0x15,0x54,0x41,
    0x15,0x54,0x41,0x15,0x54,0x41,0x15,0xfb,0x54,0x49,0x42,0x02,
    0x09,0x24,0x90,0x40,0x02,0x09,0x24,0x90,0x14,0x02,0x00,0x00,
    0x00,0x78,0xa0,0xe6,0x83,0xaf,0x66,0x0f,0xf2,0x49,0x92,0x04,
    0x00,0x00,0x00,0xd0,0x83,0x0d,0xd5,0xc4,0x00,0x00,0x60,0x20,
    0xef,0xbe,0xc8,0xeb,0x1a,0x66,0x03,0x00,0x92,0x24,0x01,0x00,
    0xc0,0x33,0xf0,0xc4,0x09,0x03,0x00,0xd0,0x0d,0xdd,0xd0,0x0d,
    0xdd,0xd0,0x0d,0xdd,0x9a,0x6e,0xe8,0x86,0x6e,0x84,0x24,0x81,
    0x04,0x12,0x48,0x20,0x81,0x04,0x12,0x48,0x20,0x9c,0x2a,0xa8,
    0x82,0x2a,0xa8,0x82,0x2a,0xa8,0x82,0x2a,0xa8,0x72,0x05,0x1d,
    0x48,0x20,0x81,0x04,0x12,0x48,0x20,0x09,0x92,0x84,0x10,0x2e,
    0x48,0x03,0x00,0x00,0x00,0x00,0x90,0x08,0x00,0x00,0x00,0x00,
    0x90,0x08,0x49,0x92,0x10,0x89,0x81,0xbc,0xfb,0x22,0xaf,0x6b,
    0x98,0x0d,0x00,0x00,0x80,0x44,0x00,0x3c,0x03,0x4f,0x9c,0x30,
    0x00,0x80,0x44,0x48,0x92,0x84,0x48,0x74,0x43,0x37,0x74,0x6b,
    0xba,0xa1,0x1b,0xba,0xa1,0x1b,0xba,0xb1,0x88,0x0a,0x24,0x90,
    0x40,0x02,0x09,0x24,0x90,0x10,0x09,0x49,0x20,0x0b,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x0b,0x00,0x00,0x00,
    0x00,0x00,0x00,0x16,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x5a,0x25,0xaa,0xaa,
    0xa8,0xaa,0xa2,0xaa,0x8a,0xaa,0x2a,0xaa,0xaa,0x00,0x00,0x90,
    0x05,0x59,0x8b,0x64,0x2d,0x92,0xb5,0x48,0xd6,0x22,0x59,0x8b,
    0x94,0xc1,0x0d,0x1b,0x73,0x60,0x06,0x66,0x60,0x06,0x66,0x60,
    0x06,0x66,0xc8,0xc1,0x49,0xa8,0x24,0x47,0x92,0x9c,0x93,0x24,
    0xe7,0x24,0xc9,0x39,0x49,0x72,0x4e,0x92,0x9c,0x93,0x24,0xe7,
    0x04,0x55,0x50,0x05,0x55,0xd4,0xae,0xaa,0xa2,0x0a,0x53,0xa5,
    0xec,0xaa,0xa7,0xa8,0xaa,0xa2,0xaa,0xb0,0x16,0xac,0x05,0x6b,
    0xa9,0x75,0xaf,0x45,0xb2,0x56,0x39,0x67,0x2d,0x4f,0xd5,0x5a,
    0x9e,0xaa,0xb5,0x9e,0xa7,0x6a,0xad,0x07,0x2f,0x03,0x8d,0xdd,
    0x1b,0xa5,0x68,0xdd,0x33,0x33,0xc3,0xcc,0xde,0xcc,0xec,0xcd,
    0xcc,0xde,0xf0,0xd0,0x24,0x16,0x75,0xdd,0x41,0xad,0xab,0xb5,
    0xeb,0x74,0x77,0x5f,0xa7,0xfb,0xbe,0xcf,0xe9,0xbe,0xef,0x73,
    0xba,0xef,0xfb,0xa8,0xaa,0xa2,0xaa,0x8a,0xaa,0x2a,0x59,0xa5,
    0x00,0x00,0x00,0x00,0x59,0x8b,0x64,0x2d,0x92,0xb5,0x08,0x8b,
    0x00,0x00,0x00,0x00,0x98,0x81,0x19,0x98,0x81,0x19,0x38,0x63,
    0x43,0x1b,0x14,0x1b,0x40,0x92,0x73,0x92,0xe4,0x9c,0x24,0x39,
    0x27,0x49,0xce,0x49,0x12,0x27,0x95,0x70,0x39,0x01,0x05,0xe0,
    0xd9,0xaa,0xca,0xa8,0x82,0xaa,0xaa,0xad,0x0a,0xaa,0xa0,0x0a,
    0xaa,0x60,0x15,0x40,0xd5,0x5a,0x8f,0x73,0xd6,0x52,0xc9,0x5a,
    0xdc,0x59,0xab,0xb0,0x16,0xac,0x05,0x6b,0x81,0x05,0x30,0xb3,
    0x37,0x33,0x63,0xba,0x35,0x45,0xb1,0xe9,0xad,0x61,0xe0,0x05,
    0x00,0xa7,0xfb,0xbe,0xcf,0xd5,0xdd,0xf7,0xb9,0xb4,0xbe,0x16,
    0xe4,0xe6,0xaa,0x85,0xa4,0xe1,0x01,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x14,0x5c,
    0x07,0x00,0x00,0x00,0x00,0x70,0x05,0xec,0xda,0x45,0x4f,0x0f,
    0x00,0x00,0x00,0x20,0x51,0xb4,0xe4,0x44,0xb9,0x17,0xd7,0xd1,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x37,
    0x58,0x0b,0xee,0x05,0x1a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xa0,0x80,0x82,0xbd,0x61,0x6f,0xd8,
    0x1b,0xf6,0x06,0x50,0xfb,0xc6,0x28,0x36,0x4a,0x5b,0x0f,0xdc,
    0x37,0xdc,0x37,0xdc,0x37,0xea,0xbe,0x71,0xad,0xc5,0x59,0x75,
    0x4a,0x9a,0xeb,0xdc,0x58,0x01,0x0a,0x00,0x00,0x00,0x40,0x83,
    0x1e,0x64,0xcf,0x55,0xf7,0x82,0x75,0x53,0xce,0x05,0x0a,0x00,
    0x00,0xe0,0x69,0x89,0x3a,0x0d,0x1c,0xf0,0xc2,0xb7,0xd8,0x55,
    0x05,0xb5,0xc1,0xc0,0xc6,0xd1,0x70,0xbb,0xee,0xe6,0xdc,0xf7,
    0x5d,0xe2,0xbe,0x73,0xda,0x7d,0xdf,0x8b,0xfb,0x46,0xdd,0x37,
    0x75,0x34,0xb5,0xe0,0x42,0xce,0x0d,0x28,0x30,0x1b,0xa5,0x31,
    0xb0,0x07,0x66,0x60,0x2a,0xd8,0x80,0xeb,0xa0,0x56,0x70,0xf5,
    0xcd,0x59,0x70,0xf5,0x72,0xea,0x7e,0xab,0xce,0x79,0x7b,0xd5,
    0x39,0xef,0xa2,0xea,0xbe,0x12,0x82,0xd9,0x14,0xcd,0x6c,0x94,
    0xc6,0xc0,0x46,0x69,0xcc,0x06,0x0d,0x40,0xdf,0x00,0xa7,0x60,
    0x5d,0x38,0x7d,0x53,0x0b,0xae,0xe6,0xd4,0x8d,0x75,0x41,0xdf,
    0xaa,0xcc,0x06,0x0d,0x00,0x00,0x00,0x00,0x80,0x5e,0x39,0x15,
    0xac,0x0b,0xfa,0x06,0x00,0x00,0x00,0x00,0x68,0x00,0x00,0x00,
    0x00,0x00,0x00,0x60,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xa0,0x85,0x0b,0x55,0x00,0x00,0x00,0x00,0x00,
    0xb8,0x02,0x49,0x08,0x00,0x00,0x00,0x00,0x00,0x44,0x02,0x00,
    0x00,0x00,0x00,0x00,0x90,0x08,0x49,0x92,0x00,0x00,0x00,0x00,
    0x00,0x40,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x89,0x90,0x24,
    0x09,0x00,0x00,0x00,0x00,0x00,0x85,0x2c,0xdd,0x00,0x00,0x00,
    0x00,0x00,0x60,0x11,0x42,0x12,0x54,0x41,0x15,0x54,0x41,0x15,
    0x54,0x41,0x15,0x54,0x41,0x15,0x54,0x49,0x42,0x02,0x09,0x24,
    0x90,0x40,0x02,0x09,0x24,0x90,0x40,0x00,0xc0,0x2e,0xa8,0x0d,
    0xc0,0x2e,0xd8,0x1b,0xf6,0x86,0xbd,0x91,0x24,0x09,0xa0,0x80,
    0x02,0xa0,0x40,0x15,0x54,0x41,0x15,0x00,0x00,0xd3,0xd0,0x03,
    0xc0,0x34,0xcc,0xc0,0x0c,0xcc,0x48,0x92,0x04,0x40,0x03,0x0d,
    0x40,0x83,0x6e,0xe8,0x86,0x6e,0xba,0xa1,0x1b,0xba,0xa1,0x1b,
    0xba,0xa1,0x1b,0xba,0xa1,0x1b,0xba,0x11,0x92,0x04,0x12,0x48,
    0x20,0x81,0x04,0x12,0x48,0x20,0x81,0xa0,0x0a,0xaa,0xa0,0x0a,
    0xaa,0xa0,0x0a,0xaa,0xa0,0x0a,0xaa,0x5c,0x41,0x07,0x12,0x48,
    0x20,0x81,0x04,0x12,0x48,0x82,0x24,0x21,0x84,0xcb,0xde,0xb0,
    0x37,0xec,0x0d,0x7b,0xc3,0xde,0xa0,0x00,0x00,0x89,0xa0,0x0a,
    0xaa,0xa0,0x0a,0xaa,0xa0,0x0a,0x40,0x22,0x24,0x49,0x42,0x24,
    0x98,0x81,0x19,0x98,0x81,0x19,0x98,0x01,0x0d,0x00,0x12,0x01,
    0xdd,0xd0,0x0d,0xdd,0xd0,0x0d,0xdd,0x80,0x44,0x48,0x92,0x84,
    0x48,0x74,0x43,0x37,0x74,0x43,0x37,0x74,0x43,0x37,0x74,0x43,
    0x37,0x16,0x51,0x81,0x04,0x12,0x48,0x20,0x81,0x04,0x12,0x22,
    0x21,0x09,0x64,0xfd,0xff,
};

BYTE code tICON_REALTEK_1BIT_LOGO0[]=
{
    0x0f,0x3c,0xe1,0x87,0x4d,0x25,0x69,0xab,0x04,0xe0,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x93,
    0x74,0x93,0x74,0x93,0x74,0x93,0x74,0x93,0x74,0x93,0x74,0x93,
    0x74,0x92,0x24,0x49,0x92,0x54,0x42,0x55,0x42,0x55,0x42,0x55,
    0x42,0x55,0x42,0x55,0x42,0x01,0x49,0x92,0x24,0x49,0x92,0x24,
    0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,
    0x4d,0xd2,0x49,0x92,0x24,0x49,0x02,0x00,0x00,0x00,0x00,0x40,
    0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x24,0x49,0x25,0x54,0x92,0x24,0x49,0x92,
    0x34,0x49,0x37,0x49,0x37,0x49,0x37,0x49,0x37,0x49,0x37,0x49,
    0x03,0x49,0x92,0x24,0x49,0x52,0x09,0x55,0x09,0x55,0x09,0x55,
    0x09,0x55,0x09,0x55,0x09,0x55,0x09,0xd5,0x24,0xdd,0x24,0xdd,
    0x24,0xdd,0x24,0xdd,0x24,0xdd,0x24,0xdd,0x24,0xdd,0x24,0x9d,
    0x24,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x66,0x34,0x49,0x37,
    0x49,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x90,0x64,0xad,0x00,0x00,0x00,0x00,0x00,0x00,0xa4,0x3b,0x49,
    0x25,0x54,0x25,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xaa,0x50,0x09,0x55,0x09,0x55,0x09,0x55,0x09,
    0x55,0x09,0x55,0x09,0x55,0x09,0x55,0x09,0x95,0x24,0x09,0x66,
    0x60,0x06,0x66,0x60,0x06,0x66,0x60,0x06,0x66,0x60,0x06,0x66,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x49,0xd6,0x4a,0x92,0xb5,
    0x92,0x64,0xad,0x24,0x59,0x2b,0x49,0xd6,0x4a,0x92,0xb5,0x92,
    0x64,0xad,0x24,0x59,0x2b,0x49,0xd6,0x4a,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0xac,0x64,0xd0,0x03,0x7b,
    0x83,0x2d,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x95,0x24,0xb1,0x72,0x12,0x4e,0x25,0x9c,0x74,0x27,
    0x49,0x77,0x92,0x74,0x27,0x49,0x77,0x92,0x74,0x27,0x49,0x77,
    0x92,0x74,0x27,0x49,0x77,0x92,0x74,0x27,0x51,0x05,0x55,0x50,
    0x05,0x55,0x50,0x05,0x55,0x50,0x05,0x55,0x50,0x05,0xcc,0xc0,
    0x0c,0xcc,0xc0,0x0c,0xcc,0xc0,0x0c,0x64,0x34,0xc9,0x0e,0xc9,
    0x24,0x59,0x2b,0x27,0x21,0x2b,0xa1,0x9c,0xc0,0x2a,0x00,0x00,
    0x00,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0xe4,0x24,0x49,0x56,0xe5,0x24,0x64,0x25,0x14,0x80,0x0d,
    0xf6,0x86,0x69,0x4d,0xa2,0x49,0xba,0x49,0xba,0x49,0xba,0x49,
    0xba,0x12,0xea,0x24,0xd4,0x49,0x38,0x49,0x96,0x24,0x49,0x25,
    0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,
    0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,
    0x49,0x92,0x24,0x93,0x24,0xe9,0x4e,0x92,0xee,0x24,0xe9,0x4e,
    0x92,0xdd,0x49,0x86,0x24,0x9b,0xa4,0x31,0x81,0xdd,0x00,0x55,
    0x50,0x05,0x55,0x50,0x05,0x55,0x50,0x05,0x39,0xa8,0x84,0x95,
    0x84,0x93,0xde,0x49,0x92,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x00,0x00,
    0x7a,0x43,0x46,0x93,0xec,0x90,0x4c,0x7a,0x27,0x49,0x26,0x49,
    0x92,0x24,0x4e,0x60,0x15,0x00,0x00,0x00,0x00,0x00,0x48,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x04,0x00,0x80,
    0x24,0x49,0x9a,0xa4,0x9b,0xa4,0x9b,0xa4,0x9b,0xa4,0x9b,0xa4,
    0x01,0x00,0x48,0x92,0x24,0xbb,0x93,0x0c,0x49,0x36,0x49,0x63,
    0x02,0xbb,0x01,0x00,0x00,0x00,0x80,0x5a,0x90,0x83,0x4a,0x58,
    0x49,0x38,0x49,0x6a,0x25,0x49,0x4e,0x92,0x24,0x49,0x52,0x2b,
    0x49,0x72,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0xb2,0x49,0x1a,0x13,0xd8,0x4d,0x2d,
    0x00,0x00,0x00,0x00,0x4d,0xd2,0x4d,0xd2,0x4d,0xd2,0x4d,0xd2,
    0x49,0x92,0x24,0x49,0xb2,0x12,0xca,0x09,0xac,0x02,0x00,0x00,
    0x40,0x92,0x24,0x49,0x92,0x64,0x92,0x24,0xbb,0x93,0x0c,0x49,
    0x36,0x49,0x63,0x02,0xbb,0x01,0x00,0x00,0x00,0x40,0x25,0x54,
    0x25,0x54,0x25,0x54,0x25,0x54,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x24,0x2b,0xa1,0x9c,0xc0,0x2a,0xa0,0xb7,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x27,0xc9,0xee,0x24,0x43,
    0x92,0x4d,0xd2,0x98,0xc0,0x6e,0x6a,0x41,0x0e,0x2a,0x61,0x55,
    0x42,0xc9,0x41,0x25,0xac,0x24,0x9c,0x24,0xb5,0x92,0x24,0x27,
    0x99,0x24,0xc9,0xee,0x24,0x43,0x92,0x4d,0xd2,0x49,0x92,0x24,
    0x49,0xb2,0x49,0x1a,0x13,0xd8,0x0d,0x00,0x80,0x24,0x9c,0x24,
    0x49,0x92,0x24,0x01,0x00,0x00,0x00,0x80,0x24,0x49,0x9a,0xa4,
    0x9b,0xa4,0x9b,0xa4,0x9b,0xa4,0x9b,0xa4,0x9b,0xa4,0x9b,0xa4,
    0x9b,0xa4,0x9b,0xa4,0x01,0xa0,0x12,0xaa,0x12,0xaa,0x12,0x0a,
    0x00,0x00,0x00,0x00,0x9a,0xa4,0x9b,0xa4,0x9b,0xa4,0x01,0x00,
    0x00,0xb2,0x3b,0xc9,0x90,0x64,0x73,0xd2,0x50,0x00,0x00,0x00,
    0x00,0x00,0xa8,0x84,0xaa,0x84,0xaa,0x84,0xaa,0x84,0xaa,0x84,
    0xaa,0x84,0xaa,0x84,0x02,0x80,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0xa4,0x12,0xaa,
    0x12,0x2a,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x95,0x50,
    0x4e,0x60,0x15,0x00,0x00,0x08,0xc9,0x20,0xa3,0x49,0x76,0x48,
    0x26,0xbd,0x93,0x24,0x93,0x24,0xc9,0x49,0x92,0xac,0xca,0x49,
    0xc8,0x4a,0xa8,0x24,0xab,0x72,0x12,0xb2,0x12,0xca,0x09,0xac,
    0x02,0x7a,0x43,0x46,0x93,0xec,0x26,0xe9,0x4a,0xa8,0x4a,0xa8,
    0x4a,0xa8,0x4a,0xa8,0x4a,0xa8,0x4a,0xa8,0x4a,0xa8,0x4a,0xa8,
    0x4a,0x28,0x4c,0x60,0x37,0xb5,0x20,0x07,0x95,0xb0,0x2a,0xa1,
    0x2a,0xa1,0x2a,0xa1,0x2a,0xa1,0x92,0xd4,0x4a,0x92,0x9c,0x6c,
    0x92,0xc6,0x04,0x76,0x53,0x0b,0x72,0x50,0x09,0xab,0x12,0x2a,
    0x49,0x92,0x24,0x49,0x00,0x00,0x48,0x92,0x24,0x49,0x92,0x24,
    0x49,0xd0,0x03,0x00,0x00,0x00,0x00,0x00,0xa0,0x49,0x1a,0x00,
    0xb0,0xc1,0xb4,0x4d,0x62,0x48,0x3a,0x5b,0x92,0x4c,0x27,0x49,
    0x92,0x04,0x00,0x00,0x00,0xb0,0xc0,0x29,0xac,0x04,0x27,0xd9,
    0x0a,0x00,0x2e,0xd0,0x2c,0xdd,0x9c,0xea,0x26,0xe9,0x26,0xe9,
    0x26,0xe9,0x26,0xe9,0x24,0x49,0x92,0x24,0x01,0x00,0x20,0x49,
    0x92,0x24,0x49,0x92,0x24,0x51,0x07,0xe9,0x9d,0x24,0x99,0x24,
    0x2b,0xa1,0x9c,0xc0,0x2a,0xa0,0x37,0x64,0x34,0xc9,0x6e,0x92,
    0x76,0x02,0xab,0x80,0xde,0x90,0xd1,0x24,0xbb,0x49,0xba,0x49,
    0xba,0x49,0xba,0x49,0xba,0x12,0xaa,0x12,0xaa,0x12,0xaa,0x12,
    0xaa,0x12,0x2a,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x04,
    0x36,0xa0,0x12,0xaa,0x12,0xaa,0x12,0xaa,0x12,0xaa,0x12,0xaa,
    0x12,0xaa,0x12,0xaa,0x49,0xba,0x49,0xba,0x49,0xba,0x49,0xba,
    0x49,0x3a,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x04,0x00,
    0x00,0x00,0x00,0x00,0x20,0x49,0x92,0x24,0xe9,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x54,0x42,0x55,0x42,0x01,0x00,0x00,0x00,0x40,
    0x92,0x24,0x49,0x92,0x24,0x49,0x52,0x09,0x55,0x09,0x55,0x09,
    0x55,0x09,0x55,0x09,0x55,0x09,0x95,0x24,0x09,0x0b,0x40,0x93,
    0x74,0x93,0x74,0x93,0x74,0x93,0x74,0x93,0x74,0x93,0x74,0x93,
    0x74,0x93,0x74,0x93,0x74,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0xf2,0xff,
};

BYTE code tICON_REALTEK_1BIT_LOGO1[]=
{
    0x0f,0x3c,0x17,0x8e,0x2d,0x45,0x69,0xab,0x04,0x5c,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x90,0x24,0x49,0x92,0x24,0x49,0x92,
    0x48,0x08,0x03,0x00,0x00,0x00,0xa4,0x35,0xc9,0x3e,0x24,0x27,
    0x49,0x92,0x24,0x2b,0x59,0x89,0xc9,0x24,0x94,0x5a,0x30,0x03,
    0x00,0x00,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0xc9,0x4a,0x92,0x54,0x25,0xc9,0x4c,0x42,
    0x92,0x6c,0x49,0xb2,0x77,0x92,0xf4,0x4e,0x92,0xee,0x24,0xe9,
    0x4e,0x92,0xee,0x24,0xe9,0x4e,0x92,0xdd,0x49,0x56,0x42,0x56,
    0xc2,0xaa,0x84,0x55,0x09,0x35,0x09,0x35,0x09,0x33,0x09,0x33,
    0x09,0x33,0x09,0xd3,0x24,0xdd,0x24,0xdd,0x24,0xdd,0x24,0xdd,
    0x24,0xdd,0x24,0xdd,0x24,0xdd,0x24,0xdd,0x24,0x0d,0x00,0x00,
    0x00,0x00,0x95,0x50,0x95,0x50,0x95,0x50,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x39,0x49,0xd2,0x24,0xbd,0x49,0x36,0x12,0x38,0x81,
    0x3e,0xd0,0x0d,0x7b,0x03,0x80,0x4a,0xa8,0x49,0x18,0x09,0xac,
    0x05,0x55,0x30,0x03,0x00,0x00,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x6b,
    0x25,0x49,0x55,0x2a,0xa1,0x2a,0xa1,0x2a,0xa1,0x2a,0xa1,0x2a,
    0xa1,0x2a,0xa1,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x9f,0x24,0xb1,0x93,0x34,0xc9,0x49,0x9f,0x24,0xb1,0x93,0x34,
    0xc9,0x41,0xb2,0xd1,0x07,0x6c,0x00,0x00,0x00,0x00,0xa0,0x06,
    0xb2,0x50,0x09,0x93,0x84,0x95,0xa4,0x26,0x49,0xb2,0x92,0x84,
    0x95,0xa4,0x26,0x49,0xb2,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x02,0x00,0x40,0xf6,
    0x4e,0x12,0x3b,0x49,0x48,0x72,0x48,0xce,0x26,0x69,0x74,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x35,0xa8,0x84,0xaa,
    0x84,0x5a,0x09,0x6b,0x25,0xac,0x24,0x23,0x49,0x6a,0x92,0x64,
    0x55,0x92,0x24,0x49,0x92,0xa4,0x12,0xaa,0x12,0xaa,0x12,0xaa,
    0x12,0xaa,0x12,0xaa,0x12,0xaa,0x12,0xaa,0x12,0xaa,0x12,0x2a,
    0x7d,0x92,0xa4,0x3b,0x49,0xf6,0x4e,0x12,0x92,0x1c,0x92,0xd3,
    0x24,0x67,0x93,0xf4,0x26,0xd9,0x48,0x00,0xea,0x82,0xb5,0x20,
    0xc1,0x24,0x4c,0x25,0xcc,0x4a,0xa8,0x95,0xb0,0x92,0x10,0x00,
    0xc0,0x06,0xbd,0xe1,0x34,0xe4,0x40,0x62,0x93,0xec,0x26,0xe9,
    0x24,0x53,0x49,0x62,0xb2,0x12,0x52,0x09,0x6b,0x12,0x4a,0xc2,
    0x58,0x81,0x5a,0x30,0x85,0x24,0x49,0x92,0x24,0x49,0x92,0x24,
    0x7d,0x92,0xc4,0x4e,0xd2,0x24,0x07,0xc9,0x46,0x1f,0xb0,0x21,
    0xd9,0xe8,0x03,0x36,0x00,0x00,0xd4,0x40,0x16,0x2a,0x61,0xd4,
    0x40,0x16,0x2a,0x61,0x92,0xb0,0x92,0xd4,0x24,0x49,0x56,0x92,
    0x24,0x49,0x92,0x24,0x49,0x12,0x00,0x00,0x64,0x90,0x64,0x64,
    0x25,0x64,0x12,0xca,0x0a,0x4c,0x61,0xb2,0xb0,0x12,0x2a,0xc9,
    0x9a,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x39,0x27,0x49,0xfa,0x24,0xc9,0xee,0x24,0xd9,0x3b,
    0x09,0xce,0x81,0x3e,0xb0,0x1b,0xf6,0x66,0xc0,0x0c,0x54,0xc1,
    0x5a,0x90,0x85,0x24,0x33,0x49,0x52,0x95,0x24,0xab,0x92,0x24,
    0x2b,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,
    0x1c,0x92,0x0e,0xc9,0xc9,0x96,0x24,0x7b,0x27,0x49,0x77,0x92,
    0x9c,0x93,0x24,0x39,0x49,0x92,0x24,0x49,0x92,0xc4,0x0c,0x00,
    0x00,0x00,0x00,0x00,0x1b,0xf4,0x96,0x24,0x49,0x92,0x24,0x49,
    0xd6,0x4a,0x92,0xaa,0x24,0x99,0x49,0x12,0xb2,0x12,0x56,0x25,
    0xd4,0x24,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x7a,0x5b,0x09,
    0x6b,0x12,0x4a,0xc2,0xa8,0x05,0x33,0x00,0x00,0x00,0x48,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0xc9,0x4a,
    0x92,0x4c,0x25,0x89,0x49,0x25,0x2c,0xf4,0x86,0x1c,0x4d,0xb2,
    0x43,0x72,0xd2,0x3b,0x49,0x72,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x00,0x00,0x00,0x00,0x80,0xde,0x90,0xa3,0x49,0x76,
    0x92,0x95,0x24,0x99,0xca,0x4a,0xc8,0x24,0x94,0x15,0x98,0x02,
    0x00,0x00,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x49,0x92,0x64,0x25,0x49,0xa6,0xb2,0x12,0x12,0x92,
    0x1c,0x92,0xd3,0x24,0x67,0x93,0xf4,0x26,0xd9,0x48,0xe0,0x1c,
    0xe8,0x86,0xdd,0x00,0x00,0x00,0x00,0x20,0x49,0x4d,0x92,0xac,
    0x4a,0x92,0xb5,0x02,0x00,0x00,0x00,0x00,0x87,0xe4,0x84,0x24,
    0xd9,0x3b,0x89,0x84,0xb1,0x02,0xb5,0x60,0x0a,0x0c,0x00,0x00,
    0x00,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,
    0x49,0xb2,0x92,0x24,0xb5,0x92,0x64,0x2a,0x49,0x4c,0x70,0xda,
    0x26,0xd1,0x24,0x3b,0x24,0x27,0x5b,0x92,0x9c,0x4e,0x92,0x9c,
    0x24,0x49,0x92,0x24,0x49,0x02,0x00,0x00,0x00,0x00,0x00,0x7a,
    0xc3,0x69,0x12,0xc6,0x0a,0x4c,0x01,0x00,0x00,0x00,0x00,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0xd4,0x4a,0x12,
    0x93,0x95,0x90,0x49,0x28,0x09,0x42,0x72,0xd2,0x3b,0x49,0x72,
    0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,
    0x92,0x24,0x09,0x00,0x00,0xe8,0x0d,0x39,0x9a,0x64,0x87,0xe4,
    0xa4,0x77,0x92,0xe4,0x24,0x99,0x84,0xb2,0x02,0x53,0x00,0x00,
    0x00,0x00,0x80,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0xc9,0x4a,
    0x92,0x4c,0x65,0x25,0x64,0x12,0xca,0x0a,0x4c,0xa1,0x12,0xaa,
    0x12,0xaa,0x12,0x0a,0x00,0x00,0x00,0x00,0x92,0x24,0x49,0x92,
    0x24,0x49,0x12,0x00,0x00,0x00,0x00,0x48,0x92,0x24,0x49,0x92,
    0x9c,0x93,0x24,0xdd,0x49,0xb2,0x3b,0x49,0xec,0x24,0x21,0xc9,
    0x21,0x39,0x4d,0xd2,0xb0,0x99,0x81,0x2a,0x58,0x05,0x59,0x90,
    0x60,0x12,0xa6,0x12,0x6a,0x25,0xac,0xf4,0x4e,0x92,0xd3,0x49,
    0x92,0x93,0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x92,0x24,
    0x49,0x92,0x24,0x49,0x00,0x00,0x00,0xb0,0x37,0x74,0xc3,0x69,
    0xc8,0xb1,0x49,0x24,0x21,0x2b,0x61,0x55,0x42,0x4d,0xc2,0x48,
    0x60,0x2d,0xa8,0x82,0x19,0x00,0x49,0x92,0x24,0x49,0x92,0x24,
    0x49,0x25,0x54,0x25,0x54,0x25,0x54,0x25,0x54,0x25,0x54,0x25,
    0xd4,0x26,0xd1,0x24,0x1d,0x92,0x93,0xbd,0x93,0xe4,0x74,0x92,
    0x24,0x49,0x92,0x24,0x49,0x92,0x24,0x49,0x12,0x00,0x00,0x00,
    0x00,0x40,0x6f,0x38,0xc7,0x26,0xa1,0x16,0x18,0x00,0x00,0x00,
    0x00,0x00,0x90,0x24,0x49,0x92,0x24,0x49,0x56,0x92,0x64,0x2a,
    0x2b,0x21,0x95,0xb0,0x24,0x8c,0xb5,0x60,0x0a,0xff,
};
//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void RTDOsdFontLoadFont(BYTE ucState);
void RTDOsdLoadHardwareVLCFont(BYTE *pArray, WORD usOffset, WORD usFontTableStart, bit bOsdRotate);
//****************************************************************************
// FUNCTION DEFINITIONS
//**************************************************************************** 
//--------------------------------------------------
// Description  : Osd Load Hardware VLC Font
// Input Value  : 
// Output Value : 
//--------------------------------------------------
void RTDOsdLoadHardwareVLCFont(BYTE *pArray, WORD usOffset, WORD usFontTableStart, bit bOsdRotate)
{
    WORD usNum = 0;
    
    if(bOsdRotate == _TRUE)
    {
        usNum = 0x85;
    }
    
    // rotation
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, usNum);
    
    // osd compression
    ScalerOsdAddrMsb(0xC0);
    ScalerOsdAddrLsb(0x05);
    ScalerOsdBurstWriteDataPort(pArray, 8, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
    
    usNum = ((WORD) * (pArray + 8) << 8) | *(pArray + 9);
    
    usOffset = usOffset * 9;
    usOffset += usFontTableStart;
    
    // osd compression enable
    ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x01);
    
    // Osd load font > 12K
    if(usOffset > 4095)
    {
        ScalerOsdScrambleLoadFontAddrHsbSet();
    }
    else
    {
        ScalerOsdScrambleLoadFontAddrHsbClr();
    }
    
    pArray += 10;
    
    ScalerOsdAddrMsb((HIBYTE(usOffset) & 0x000f) | 0xd0);
    ScalerOsdAddrLsb(LOBYTE(usOffset));
    ScalerOsdBurstWriteDataPort(pArray, usNum, GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_DATA_OSD, _BURSTWRITE_FROM_FLASH);
    
    // For osd load font > 12K !!
    ScalerOsdScrambleLoadFontAddrHsbClr();
    ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x00);
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, (BYTE)bOsdRotate);
}


void RTDOsdFontLoadFont(BYTE ucState)
{
    switch(ucState)
    {
        case _FONT1_GLOBAL:
            RTDOsdLoadHardwareVLCFont(tFONT_GLOBAL,_1BIT_FONT_START_ADDRESS,g_usFontTableStart,GET_OSD_ROTATE_STATUS());
            break;
    
        case _REALTEK_2BIT_ICON:
            RTDOsdLoadHardwareVLCFont(tICON_REALTEK_2BIT_ICON,_2BIT_ICON_START_ADDRESS * 2,g_usFontTableStart,GET_OSD_ROTATE_STATUS());
            break;
    
        case _MAIN_MENU_2BIT_ICON:
            RTDOsdLoadHardwareVLCFont(tICON_MAIN_MENU_2BIT_ICON, (_2BIT_ICON_START_ADDRESS + _MAIN_MENU_2BIT_ICON_START) * 2,g_usFontTableStart,GET_OSD_ROTATE_STATUS());
            break;
    
        case _REALTEK_1BIT_LOGO0:
            RTDOsdLoadHardwareVLCFont(tICON_REALTEK_1BIT_LOGO0, _1BIT_FONT_START_ADDRESS,g_usFontTableStart,GET_OSD_ROTATE_STATUS());
            break;
    
        case _REALTEK_1BIT_LOGO1:
            RTDOsdLoadHardwareVLCFont(tICON_REALTEK_1BIT_LOGO1, _Logo1_0x00,g_usFontTableStart,GET_OSD_ROTATE_STATUS());
            break;
    
        default:
            break;
    };
}

#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)