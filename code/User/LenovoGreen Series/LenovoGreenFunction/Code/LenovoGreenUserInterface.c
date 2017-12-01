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
// ID Code      : UserInterface.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_INTERFACE__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LEONVO_GREEN_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _USER_SHOW_LOGO_STEP                18 // frames

#define _EDID_VENDOR_SPEC_0                 160
#define _EDID_CHKSUM                        255

//-------------------------------------------------------
//  Definitions of RCP Key Codes
//-------------------------------------------------------
#define _MHL_RCP_VOLUME_UP                      0x41
#define _MHL_RCP_VOLUME_DOWN                    0x42
#define _MHL_RCP_MUTE                           0x43
#define _MHL_RCP_MUTE_FUNCTION                  0x65
#define _MHL_RCP_RESTORE_VOLUME_FUNCTION        0x66

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// EDID DATA TABLE
//--------------------------------------------------
#if((_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_A0_LOCATION == _EDID_TABLE_LOCATION_CODE))
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)

	#warning "Please check EDID location!!"

#else
BYTE code tEDID_TABLE_A0[] =
{
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x4A, 0x8B, 0x3B, 0x2A, 0x01, 0x01, 0x01, 0x01,
    0x1E, 0x13, 0x01, 0x03, 0x0E, 0x33, 0x1D, 0x78, 0xEF, 0x8A, 0x01, 0x9A, 0x58, 0x52, 0x8B, 0x28,
    0x1E, 0x50, 0x54, 0xEF, 0xEF, 0x80, 0x81, 0xC0, 0xA9, 0xC0, 0xD1, 0xC0, 0x95, 0x00, 0x81, 0x40,
    0x81, 0x80, 0x90, 0x40, 0xA9, 0x40, 0x7D, 0x4B, 0x80, 0xA0, 0x72, 0xB0, 0x2D, 0x40, 0x50, 0xC8,
    0x46, 0x48, 0xFE, 0x22, 0x11, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xFD, 0x00, 0x32, 0x55, 0x0A,
    0x6E, 0x15, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x52,
    0x54, 0x44, 0x20, 0x4D, 0x6F, 0x6E, 0x69, 0x74, 0x6F, 0x72, 0x0A, 0x20, 0x00, 0x00, 0x00, 0xFF,
    0x00, 0x52, 0x54, 0x44, 0x30, 0x31, 0x30, 0x32, 0x30, 0x33, 0x30, 0x34, 0x0A, 0x20, 0x00, 0xE5,
};
#endif
#endif

#if((_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D0_LOCATION == _EDID_TABLE_LOCATION_CODE))
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)

	#warning "Please check EDID location!!"

#else
BYTE code tEDID_TABLE_D0[] =
{
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x4A, 0x8B, 0x7E, 0x56, 0xD9, 0x05, 0x00, 0x00,
    0x04, 0x12, 0x01, 0x03, 0xEA, 0x31, 0x20, 0x78, 0xEA, 0xAE, 0xC5, 0xA2, 0x57, 0x4A, 0x9C, 0x25,
    0x12, 0x50, 0x54, 0xAF, 0xEF, 0x80, 0x95, 0x00, 0x81, 0x80, 0x81, 0x40, 0x71, 0x4F, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7C, 0x2E, 0x90, 0xA0, 0x60, 0x1A, 0x1E, 0x40, 0x30, 0x20,
    0x36, 0x00, 0xDA, 0x28, 0x11, 0x00, 0x00, 0x1A, 0x21, 0x39, 0x90, 0x30, 0x62, 0x1A, 0x27, 0x40,
    0x68, 0xB0, 0x36, 0x00, 0xDA, 0x28, 0x11, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0xFD, 0x00, 0x38,
    0x4B, 0x1C, 0x53, 0x0F, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFC,
    0x00, 0x57, 0x32, 0x32, 0x35, 0x32, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0xAF,

#elif((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x10, 0xAC, 0x17, 0xF0, 0x4C, 0x46, 0x30, 0x30,
    0x18, 0x13, 0x01, 0x03, 0xB5, 0x34, 0x20, 0x78, 0x3A, 0x1E, 0xC5, 0xAE, 0x4F, 0x34, 0xB1, 0x26,
    0x0E, 0x50, 0x54, 0xA5, 0x4B, 0x00, 0x81, 0x80, 0xA9, 0x40, 0xD1, 0x00, 0x71, 0x4F, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xE8, 0x35, 0x80, 0xA0, 0x70, 0x38, 0x1F, 0x40, 0x30, 0x20,
    0x25, 0x00, 0x44, 0x68, 0x21, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x4A, 0x32, 0x35,
    0x37, 0x4D, 0x39, 0x36, 0x42, 0x30, 0x30, 0x46, 0x4C, 0x0A, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x44,
    0x45, 0x4C, 0x4C, 0x20, 0x55, 0x32, 0x34, 0x31, 0x30, 0x0A, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFD,
    0x00, 0x38, 0x4C, 0x1E, 0x51, 0x11, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x67,
    0x02, 0x03, 0x1D, 0xF5, 0x50, 0x90, 0x05, 0x04, 0x03, 0x02, 0x07, 0x16, 0x01, 0x1F, 0x12, 0x13,
    0x14, 0x20, 0x15, 0x11, 0x06, 0x23, 0x09, 0x07, 0x07, 0x83, 0x01, 0x00, 0x00, 0x02, 0x3A, 0x80,
    0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C, 0x45, 0x00, 0x06, 0x44, 0x21, 0x00, 0x00, 0x1E, 0x01,
    0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C, 0x25, 0x00, 0x06, 0x44, 0x21, 0x00, 0x00,
    0x9E, 0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20, 0x6E, 0x28, 0x55, 0x00, 0x06, 0x44, 0x21,
    0x00, 0x00, 0x1E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96, 0x00, 0x06,
    0x44, 0x21, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1D,

#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x04, 0x72, 0xBF, 0x01, 0x01, 0x00, 0x50, 0x63,
    0x0C, 0x14, 0x01, 0x04, 0xB5, 0x30, 0x1B, 0x78, 0x3A, 0x35, 0x85, 0xA6, 0x56, 0x48, 0x9A, 0x24,
    0x12, 0x50, 0x54, 0xB3, 0x0C, 0x00, 0x71, 0x4F, 0x81, 0x00, 0x81, 0x80, 0x95, 0x00, 0xD1, 0xC0,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C,
    0x45, 0x00, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xFD, 0x00, 0x38, 0x4B, 0x1E,
    0x53, 0x11, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x41,
    0x63, 0x65, 0x72, 0x20, 0x41, 0x32, 0x32, 0x31, 0x50, 0x48, 0x51, 0x0A, 0x00, 0x00, 0x00, 0xFF,
    0x00, 0x4C, 0x35, 0x36, 0x30, 0x35, 0x31, 0x37, 0x39, 0x34, 0x33, 0x30, 0x32, 0x0A, 0x01, 0x1F,
    0x02, 0x03, 0x22, 0x72, 0x4F, 0x01, 0x02, 0x03, 0x04, 0x05, 0x90, 0x11, 0x12, 0x13, 0x14, 0x9F,
    0x06, 0x07, 0x15, 0x16, 0x23, 0x09, 0x7F, 0x07, 0x83, 0x01, 0x00, 0x00, 0x65, 0x03, 0x0C, 0x00,
    0x10, 0x00, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C, 0x45, 0x00, 0xDD, 0x0C,
    0x11, 0x00, 0x00, 0x1E, 0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C, 0x25, 0x00,
    0xDD, 0x0C, 0x11, 0x00, 0x00, 0x9E, 0x01, 0x1D, 0x80, 0xD0, 0x72, 0x1C, 0x16, 0x20, 0x10, 0x2C,
    0x25, 0x80, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x9E, 0x02, 0x3A, 0x80, 0xD0, 0x72, 0x38, 0x2D, 0x40,
    0x10, 0x2C, 0x45, 0x80, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB2,

#endif
};
#endif
#endif

#if((_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_LOCATION == _EDID_TABLE_LOCATION_CODE))
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)

	#warning "Please check EDID location!!"

#else
BYTE code tEDID_TABLE_D1[] =
{
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x4A, 0x8B, 0x7E, 0x56, 0xD9, 0x05, 0x00, 0x00,
    0x04, 0x12, 0x01, 0x03, 0xEA, 0x31, 0x20, 0x78, 0xEA, 0xAE, 0xC5, 0xA2, 0x57, 0x4A, 0x9C, 0x25,
    0x12, 0x50, 0x54, 0xAF, 0xEF, 0x80, 0x95, 0x00, 0x81, 0x80, 0x81, 0x40, 0x71, 0x4F, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7C, 0x2E, 0x90, 0xA0, 0x60, 0x1A, 0x1E, 0x40, 0x30, 0x20,
    0x36, 0x00, 0xDA, 0x28, 0x11, 0x00, 0x00, 0x1A, 0x21, 0x39, 0x90, 0x30, 0x62, 0x1A, 0x27, 0x40,
    0x68, 0xB0, 0x36, 0x00, 0xDA, 0x28, 0x11, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0xFD, 0x00, 0x38,
    0x4B, 0x1C, 0x53, 0x0F, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFC,
    0x00, 0x57, 0x32, 0x32, 0x35, 0x32, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0xAF,

#elif((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x10, 0xAC, 0x17, 0xF0, 0x4C, 0x46, 0x30, 0x30,
    0x18, 0x13, 0x01, 0x03, 0xB5, 0x34, 0x20, 0x78, 0x3A, 0x1E, 0xC5, 0xAE, 0x4F, 0x34, 0xB1, 0x26,
    0x0E, 0x50, 0x54, 0xA5, 0x4B, 0x00, 0x81, 0x80, 0xA9, 0x40, 0xD1, 0x00, 0x71, 0x4F, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xE8, 0x35, 0x80, 0xA0, 0x70, 0x38, 0x1F, 0x40, 0x30, 0x20,
    0x25, 0x00, 0x44, 0x68, 0x21, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x4A, 0x32, 0x35,
    0x37, 0x4D, 0x39, 0x36, 0x42, 0x30, 0x30, 0x46, 0x4C, 0x0A, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x44,
    0x45, 0x4C, 0x4C, 0x20, 0x55, 0x32, 0x34, 0x31, 0x30, 0x0A, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFD,
    0x00, 0x38, 0x4C, 0x1E, 0x51, 0x11, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x67,
    0x02, 0x03, 0x1D, 0xF5, 0x50, 0x90, 0x05, 0x04, 0x03, 0x02, 0x07, 0x16, 0x01, 0x1F, 0x12, 0x13,
    0x14, 0x20, 0x15, 0x11, 0x06, 0x23, 0x09, 0x07, 0x07, 0x83, 0x01, 0x00, 0x00, 0x02, 0x3A, 0x80,
    0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C, 0x45, 0x00, 0x06, 0x44, 0x21, 0x00, 0x00, 0x1E, 0x01,
    0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C, 0x25, 0x00, 0x06, 0x44, 0x21, 0x00, 0x00,
    0x9E, 0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20, 0x6E, 0x28, 0x55, 0x00, 0x06, 0x44, 0x21,
    0x00, 0x00, 0x1E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96, 0x00, 0x06,
    0x44, 0x21, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1D,

#elif((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT))
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x04, 0x72, 0xBF, 0x01, 0x01, 0x00, 0x50, 0x63,
    0x0C, 0x14, 0x01, 0x04, 0xB5, 0x30, 0x1B, 0x78, 0x3A, 0x35, 0x85, 0xA6, 0x56, 0x48, 0x9A, 0x24,
    0x12, 0x50, 0x54, 0xB3, 0x0C, 0x00, 0x71, 0x4F, 0x81, 0x00, 0x81, 0x80, 0x95, 0x00, 0xD1, 0xC0,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C,
    0x45, 0x00, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xFD, 0x00, 0x38, 0x4B, 0x1E,
    0x53, 0x11, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x41,
    0x63, 0x65, 0x72, 0x20, 0x41, 0x32, 0x32, 0x31, 0x50, 0x48, 0x51, 0x0A, 0x00, 0x00, 0x00, 0xFF,
    0x00, 0x4C, 0x35, 0x36, 0x30, 0x35, 0x31, 0x37, 0x39, 0x34, 0x33, 0x30, 0x32, 0x0A, 0x01, 0x1F,
    0x02, 0x03, 0x22, 0x72, 0x4F, 0x01, 0x02, 0x03, 0x04, 0x05, 0x90, 0x11, 0x12, 0x13, 0x14, 0x9F,
    0x06, 0x07, 0x15, 0x16, 0x23, 0x09, 0x7F, 0x07, 0x83, 0x01, 0x00, 0x00, 0x65, 0x03, 0x0C, 0x00,
    0x10, 0x00, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C, 0x45, 0x00, 0xDD, 0x0C,
    0x11, 0x00, 0x00, 0x1E, 0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2C, 0x25, 0x00,
    0xDD, 0x0C, 0x11, 0x00, 0x00, 0x9E, 0x01, 0x1D, 0x80, 0xD0, 0x72, 0x1C, 0x16, 0x20, 0x10, 0x2C,
    0x25, 0x80, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x9E, 0x02, 0x3A, 0x80, 0xD0, 0x72, 0x38, 0x2D, 0x40,
    0x10, 0x2C, 0x45, 0x80, 0xDD, 0x0C, 0x11, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB2,

#endif
};
#endif
#endif

#if((_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D0_MHL_LOCATION == _EDID_TABLE_LOCATION_CODE))
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)

	#warning "Please check EDID location!!"

#else
BYTE code tEDID_TABLE_D0_MHL[] =
{
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x4A, 0x8B, 0x3B, 0x2A, 0x01, 0x01, 0x01, 0x01,
    0x0D, 0x16, 0x01, 0x03, 0x80, 0x3C, 0x22, 0x78, 0x2A, 0x2C, 0xC5, 0xA5, 0x55, 0x54, 0xA1, 0x27,
    0x0C, 0x50, 0x54, 0xAD, 0xCF, 0x00, 0xD1, 0xC0, 0x81, 0x80, 0x81, 0xC0, 0x95, 0x00, 0xB3, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C,
    0x45, 0x00, 0x56, 0x50, 0x21, 0x00, 0x00, 0x1E, 0x66, 0x21, 0x50, 0xB0, 0x51, 0x00, 0x1B, 0x30,
    0x40, 0x70, 0x36, 0x00, 0x56, 0x50, 0x21, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x56,
    0x53, 0x32, 0x37, 0x30, 0x42, 0x47, 0x54, 0x57, 0x50, 0x0A, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFD,
    0x00, 0x38, 0x4B, 0x1E, 0x53, 0x11, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x6E,
    0x02, 0x03, 0x22, 0xF1, 0x4F, 0xA2, 0x14, 0x10, 0x1F, 0x04, 0x13, 0x03, 0x12, 0x02, 0x11, 0x01,
    0x06, 0x07, 0x15, 0x16, 0x23, 0x09, 0x07, 0x01, 0x83, 0x01, 0x00, 0x00, 0x65, 0x03, 0x0C, 0x00,
    0x10, 0x00, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96, 0x00, 0x56, 0x50,
    0x21, 0x00, 0x00, 0x18, 0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20, 0x6E, 0x28, 0x55, 0x00,
    0x56, 0x50, 0x21, 0x00, 0x00, 0x1E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E,
    0x96, 0x00, 0x56, 0x50, 0x21, 0x00, 0x00, 0x18, 0x8C, 0x0A, 0xD0, 0x90, 0x20, 0x40, 0x31, 0x20,
    0x0C, 0x40, 0x55, 0x00, 0x56, 0x50, 0x21, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3A,
};
#endif
#endif

#if((_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_MHL_LOCATION == _EDID_TABLE_LOCATION_CODE))
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)

	#warning "Please check EDID location!!"

#else
BYTE code tEDID_TABLE_D1_MHL[] =
{
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x4A, 0x8B, 0x3B, 0x2A, 0x01, 0x01, 0x01, 0x01,
    0x0D, 0x16, 0x01, 0x03, 0x80, 0x3C, 0x22, 0x78, 0x2A, 0x2C, 0xC5, 0xA5, 0x55, 0x54, 0xA1, 0x27,
    0x0C, 0x50, 0x54, 0xAD, 0xCF, 0x00, 0xD1, 0xC0, 0x81, 0x80, 0x81, 0xC0, 0x95, 0x00, 0xB3, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x3A, 0x80, 0x18, 0x71, 0x38, 0x2D, 0x40, 0x58, 0x2C,
    0x45, 0x00, 0x56, 0x50, 0x21, 0x00, 0x00, 0x1E, 0x66, 0x21, 0x50, 0xB0, 0x51, 0x00, 0x1B, 0x30,
    0x40, 0x70, 0x36, 0x00, 0x56, 0x50, 0x21, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x56,
    0x53, 0x32, 0x37, 0x30, 0x42, 0x47, 0x54, 0x57, 0x50, 0x0A, 0x20, 0x20, 0x00, 0x00, 0x00, 0xFD,
    0x00, 0x38, 0x4B, 0x1E, 0x53, 0x11, 0x00, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x6E,
    0x02, 0x03, 0x22, 0xF1, 0x4F, 0xA2, 0x14, 0x10, 0x1F, 0x04, 0x13, 0x03, 0x12, 0x02, 0x11, 0x01,
    0x06, 0x07, 0x15, 0x16, 0x23, 0x09, 0x07, 0x01, 0x83, 0x01, 0x00, 0x00, 0x65, 0x03, 0x0C, 0x00,
    0x20, 0x00, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E, 0x96, 0x00, 0x56, 0x50,
    0x21, 0x00, 0x00, 0x18, 0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20, 0x6E, 0x28, 0x55, 0x00,
    0x56, 0x50, 0x21, 0x00, 0x00, 0x1E, 0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3E,
    0x96, 0x00, 0x56, 0x50, 0x21, 0x00, 0x00, 0x18, 0x8C, 0x0A, 0xD0, 0x90, 0x20, 0x40, 0x31, 0x20,
    0x0C, 0x40, 0x55, 0x00, 0x56, 0x50, 0x21, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A,
};
#endif
#endif

//--------------------------------------------------
// HDCP KEY TABLE
//--------------------------------------------------
#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(((_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)) \
  || (_HDCP_KEY_LOCATION == _TABLE_LOCATION_CODE))

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)

	#warning "Please check HDCP KEY location!!"

#else

BYTE code tHDCP_KEY_BKSV[] =
{
    0xB7, 0x28, 0xA9, 0x51, 0xD6,
};

BYTE code tHDCP_KEY_TABLE[] =
{
    0x3a, 0x21, 0x17, 0x06, 0x72, 0x60, 0x3b, 0x6e,     // Key0
    0x0c, 0x58, 0x16, 0x4c, 0x5b, 0x3b, 0x68, 0x4b,     // Key1
    0x2f, 0x7b, 0x5d, 0x64, 0x10, 0x60, 0x71, 0x41,     // Key2
    0x6d, 0x4a, 0x1f, 0x48, 0x35, 0x78, 0x4b, 0x6a,     // Key3
    0x4b, 0x3c, 0x69, 0x2a, 0x20, 0x38, 0x55, 0x1c,     // Key4
    0x10, 0x16, 0x09, 0x5d, 0x0d, 0x07, 0x6e, 0x7a,     // Key5
    0x75, 0x1a, 0x35, 0x55, 0x7b, 0x5c, 0x26, 0x0d,     // Key6
    0x2c, 0x49, 0x1a, 0x1b, 0x3e, 0x55, 0x1f, 0x40,     // Key7
    0x11, 0x24, 0x4b, 0x4a, 0x5d, 0x56, 0x4b, 0x5c,     // Key8
    0x62, 0x70, 0x0b, 0x10, 0x52, 0x3f, 0x2b, 0x4d,     // Key9
    0x5d, 0x06, 0x78, 0x16, 0x72, 0x70, 0x2e, 0x06,     // Key10
    0x3a, 0x2c, 0x60, 0x06, 0x12, 0x6c, 0x32, 0x55,     // Key11
    0x54, 0x62, 0x38, 0x05, 0x13, 0x42, 0x49, 0x40,     // Key12
    0x61, 0x54, 0x28, 0x0c, 0x4a, 0x21, 0x7c, 0x32,     // Key13
    0x4b, 0x74, 0x04, 0x5d, 0x10, 0x69, 0x72, 0x62,     // Key14
    0x5d, 0x77, 0x55, 0x0d, 0x19, 0x79, 0x59, 0x43,     // Key15
    0x0a, 0x5f, 0x0d, 0x50, 0x58, 0x4f, 0x48, 0x42,     // Key16
    0x14, 0x64, 0x65, 0x54, 0x2f, 0x7a, 0x75, 0x04,     // Key17
    0x48, 0x35, 0x00, 0x59, 0x16, 0x0e, 0x2f, 0x4b,     // Key18
    0x4a, 0x7b, 0x04, 0x6c, 0x1a, 0x6d, 0x4b, 0x44,     // Key19
    0x50, 0x11, 0x63, 0x63, 0x47, 0x6e, 0x1a, 0x6b,     // Key20
    0x0f, 0x4c, 0x3e, 0x17, 0x66, 0x0d, 0x3b, 0x3a,     // Key21
    0x47, 0x62, 0x5a, 0x25, 0x3d, 0x0e, 0x1d, 0x55,     // Key22
    0x42, 0x0f, 0x43, 0x60, 0x3e, 0x7e, 0x56, 0x3c,     // Key23
    0x44, 0x4a, 0x44, 0x3b, 0x69, 0x17, 0x1b, 0x47,     // Key24
    0x19, 0x77, 0x2c, 0x7d, 0x72, 0x03, 0x66, 0x53,     // Key25
    0x7f, 0x5a, 0x03, 0x26, 0x17, 0x01, 0x28, 0x5e,     // Key26
    0x09, 0x1d, 0x43, 0x13, 0x35, 0x26, 0x4c, 0x15,     // Key27
    0x1e, 0x7f, 0x4d, 0x6b, 0x4d, 0x52, 0x46, 0x00,     // Key28
    0x3c, 0x38, 0x5c, 0x64, 0x6f, 0x72, 0x78, 0x11,     // Key29
    0x30, 0x65, 0x47, 0x70, 0x7a, 0x3c, 0x38, 0x69,     // Key30
    0x78, 0x26, 0x35, 0x09, 0x37, 0x14, 0x34, 0x57,     // Key31
    0x73, 0x4d, 0x28, 0x28, 0x7e, 0x5a, 0x28, 0x09,     // Key32
    0x08, 0x28, 0x6c, 0x69, 0x42, 0x43, 0x31, 0x15,     // Key33
    0x54, 0x23, 0x60, 0x1c, 0x03, 0x48, 0x7d, 0x48,     // Key34
    0x25, 0x5f, 0x2b, 0x04, 0x6c, 0x42, 0x22, 0x66,     // Key35
    0x11, 0x2a, 0x1a, 0x14, 0x29, 0x68, 0x59, 0x73,     // Key36
    0x76, 0x61, 0x16, 0x00, 0x3e, 0x11, 0x31, 0x20,     // Key37
    0x10, 0x59, 0x13, 0x44, 0x54, 0x32, 0x4f, 0x0e,     // Key38
    0x76, 0x47, 0x13, 0x6f, 0x7e, 0x24, 0x5a, 0x6a,     // Key39
};

#endif

#endif
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
extern BYTE g_ucFlashPageArr[_END_OF_PAGEID - _START_OF_PAGEID + 1];
extern WORD g_usFlashAddrArr[_END_OF_PAGEID - _START_OF_PAGEID + 1];

extern BYTE g_ucLogoTimerCounter;

#if((_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))
BYTE g_ucD0MHLEDIDDiff[2] = {0};
BYTE g_ucD1MHLEDIDDiff[2] = {0};
#endif

#if(_UART_SUPPORT == _ON)
BYTE g_ucUartData[5] = {0};
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserInterfaceTimerEventProc(BYTE ucEventID);

#if(_INSTANT_TIMER_EVENT_0 == _ON)
void UserInterfaceTimer0InstantAccess_TIMER0(void);
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
void UserInterfaceTimer1InstantAccess_TIMER1(void);
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
void UserInterfaceTimer2InstantAccess_TIMER2(void);
#endif

#if(_UART_SUPPORT == _ON)
void UserInterfaceUartIntHandler_SERIALPORT(void);
#endif

void UserInterfacePowerSwitch(EnumPowerAction enumSwitch);
void UserInterfaceInitial(void);
void UserInterfacePanelPowerAction(BYTE ucEvent);
void UserInterfaceOsdPowerOnInitial(void);
void UserInterfaceAdjustColorProc(void);
void UserInterfaceOsdActiveProc(void);
void UserInterfaceOsdResetProc(void);
bit UserInterfaceOsdGetLogoOn(void);
bit UserInterfaceOsdNoSupportCheck(void);
void UserInterfaceAdjustInputTiming(void);
void UserInterfaceAdjustDisplayTiming(void);

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
bit UserInterfaceGetFREESYNCEnable_EXINT1(void);
#endif

#if((_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))
void UserInterfaceSetEmbeddedEDIDData(void);
#endif

#if((_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))
void UserInterfaceChangeMHLEDIDData(BYTE ucInputPort);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
void UserInterfaceGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
void UserInterfaceGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray);

#if((_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
void UserInterfaceNVRamRestoreHDCP(void);
#endif
#endif

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
bit UserInterfaceFlashLoadItem(EnumFlashItemIDType enumItemID, BYTE* pucData, BYTE ucLength);
bit UserInterfaceFlashSaveItem(EnumFlashItemIDType enumItemID, BYTE* pucData, BYTE ucLength);
#endif


#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
BYTE UserInterfaceGetDdcciStatus_EXINT1(void);
BYTE UserInterfaceGetFactoryCommand_EXINT1(void);

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
BYTE UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1(void);
#endif

#endif

bit UserInterfaceGetActiveByPass(void);
bit UserInterfaceCheckIntoPS(void);
void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed);

bit UserInterfaceCheckNVRamData(EnumADCCheckType enumType);

#if(_VGA_SUPPORT == _ON)
BYTE UserInterfaceCheckVGAModeSearch(BYTE ucModeIndex);
bit UserInterfaceFirstAutoConfig(void);
void UserInterfaceAutoConfigPercentage(BYTE ucAutoPercentage);

#if(_YPBPR_SUPPORT == _ON)
bit UserInterfaceCheckHDTVMode(BYTE ucModeNumber);
#endif

#endif

#if(_AUDIO_SUPPORT == _ON)
bit UserInterfaceGetAudioReadyToPlay(void);
bit UserInterfaceGetAudioMute(void);
WORD UserInterfaceGetAudioVolume(void);
bit UserInterfaceGetAudioSource(void);
void UserInterfaceAudioResetProc(void);
bit UserInterfaceDecideAudioNonLPCMMute(void);
void UserInterfaceAudioPowerProc(EnumPowerStatus enumPowStatus);
void UserInterfaceAudioAmpMuteProc(bit bMute);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void);
#endif

#if(_SLEEP_AUDIO_SUPPORT == _ON)
bit UserInterfaceGetAudioStandAlone(void);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

bit UserInterfaceCheckCableReset(void);
void UserInterfaceUncallFunction(void);
bit UserInterfaceGetForcePowSavStatus(void);
bit UserInterfaceDClkNoSupportCheck(void);

#if(_ENERGY_STAR_SUPPORT == _ON)
BYTE UserInterfaceGetOSDBackightValue(void);
#endif

#if(_MHL_SUPPORT == _ON)
bit UserInterfaceMHLMscRCPProc(BYTE ucKeyCode);
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
bit UserInterfaceJudgeRGBQuantizationLimitRange(void);
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
bit UserInterfaceJudgeYCCQuantizationFullRange(void);
#endif


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : None
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceTimerEventProc(BYTE ucEventID)
{
    switch(ucEventID)
    {
        case _USER_TIMER_EVENT_OSD_DISABLE_AUTO_ADJUST_MSG:
            OsdDispDisableOsdTimerEvent(); 
            break;
            
        case _USER_TIMER_EVENT_KEY_REPEAT_ENABLE:
            SET_KEYREPEATSTART();
            break;
            
        case _USER_TIMER_EVENT_KEY_SCAN_READY:
            SET_KEYSCANREADY();
            break;
            
        case _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO:
            OsdDispDisableOsdTimerEvent();
            ScalerDDomainBackgroundSetColor(0, 0, 0);//Robert Wang 20121129

            SET_OSD_LOGO_ON(_OFF);
#if(_INSTANT_TIMER_EVENT_0 == _ON)
            ScalerTimer0SetTimerCount(_TIMER_OFF);
#endif
#if(_PANEL_POW_SEQ_FAST_MODE == _ON)
            UserInterfacePanelPowerAction(_BACKLIGHT_OFF);
#else
            UserInterfacePanelPowerAction(_PANEL_OFF);
#endif
            ScalerDDomainBackgroundEnable(_ENABLE);
            ScalerDDomainPatternGenEnable(_DISABLE);
            break;

        case _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOCABLE_MSG);
            break;
            
        case _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSIGNAL_MSG);
            break;

		case _USER_TIMER_EVENT_OSD_SHOW_NO_SUPPORT:
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSUPPORT_MSG);
			break;

        case _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG);
            break;


		case _USER_TIMER_EVENT_OSD_FLYING:
			OsdDispMessage(_MSG_FLYING);
			ScalerTimerActiveTimerEvent(SEC(0.5), _USER_TIMER_EVENT_OSD_FLYING);
			break;

        case _USER_TIMER_EVENT_FLY_OSD_TO_POWER_SAVING://lorimiao 20140609 for FAIL_SAFE_MODE OOR go to Power saving Issue
            ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_GO_TO_POWER_SAVING); 
            break;

        case _USER_TIMER_EVENT_GO_TO_POWER_SAVING:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG);
            break;
            
        case _USER_TIMER_EVENT_OSD_DISABLE:
            OsdTimeoutSaveData();//Eli 20121001 modify bug T9CGT478FEG3HN-74,T9CGT478FEG3HN-77.            
            OsdDispDisableOsdTimerEvent();
            break;

        case _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON:
            SET_PANELPOWERSTATUS(_READY_FOR_BACKLIGHT);
            break;

        case _USER_TIMER_EVENT_PANEL_POWER_OFF:
            SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);
            break;

#if(_VGA_SUPPORT == _ON)
        case _USER_TIMER_EVENT_DO_AUTO_COLOR:
            //RTDOsdDisplayAutoBalanceProc();
            break;
#endif

        case _USER_TIMER_EVENT_PANEL_USED_TIMER:
            RTDFactoryPanelUsedTimer();
            break;

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
        case _USER_TIMER_EVENT_HLWIN_TYPE5_MOVE:
            UserAdjustHLWinType5Move();
            break;
#endif

#if(_ENERGY_STAR_SUPPORT == _ON)
        case _USER_TIMER_EVENT_ES_ADJUST:
            UserCommonAdjustESDcrAdjustPWM();
            break;
#endif

//DFM rev02 patch note 7>>
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
		case _USER_TIMER_EVENT_BURN_IN:
			TPVFactFuncBurnInPattern();
			break;
#endif			
//DFM rev02 patch note 7<<
#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502	
		case _USER_TIMER_EVENT_BURN_IN:
			FactoryBurnInPattern();
			break;
#endif			

#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
		case _USER_TIMER_EVENT_BURN_IN:
            WISTRONFactoryAdjustBurnInPattern();
			break;

        case _USER_TIMER_EVENT_LED_FLASH:
            UserInterfaceKeyPadLedControl(_LED_TYPE_FLASH);
            ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_LED_FLASH);
            break;

		case _USER_TIMER_EVENT_EDIDVERSION_CLEAR:
			SET_KEYHOLDKEY();
            SET_KEYVERSION();
			SET_KEYMESSAGE(_MENU_KEY_MESSAGE);
			break;            
#endif			

		case _USER_TIMER_EVENT_OSD_LOCK:
			SET_KEYHOLDKEY();
			if(GET_OSD_LOCK_STATUS() == _ON)
			{
				SET_OSD_LOCK_STATUS(_OFF);
				OsdDispMessage(_MSG_UNLOCK);
			}
			else
			{
				SET_OSD_LOCK_STATUS(_ON);
				OsdDispMessage(_MSG_LOCK);
			}
			
		#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)
			ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
		#elif(_FACTORY_MODE_OWNER == _OWNER_TPV)
			ScalerTimerReactiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_DISABLE);
		#else
			ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
		#endif			
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
			break;

		case _USER_TIMER_EVENT_DDCCI:
			SET_KEYHOLDKEY();
			if(GET_OSD_DDCCI_STATUS() == _ON)
			{
				SET_OSD_DDCCI_STATUS(_OFF);
				OsdDispMessage(_MSG_DDCCI_OFF);
			}
			else
			{
				SET_OSD_DDCCI_STATUS(_ON);
				OsdDispMessage(_MSG_DDCCI_ON);
			}
			ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());			
		#if((_FACTORY_MODE_OWNER == _OWNER_FOXCONN) || (_FACTORY_MODE_OWNER == _OWNER_TPV))
			ScalerTimerReactiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_DISABLE);
		#else
			ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
		#endif			
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			

			break;

#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
		case _USER_TIMER_EVENT_INPUT://ym20131009 . 
			CLR_KEYHOLDKEY();
			break;
#endif	
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
        case _USER_TIMER_EVENT_OSD_LOWBLUELIGHT_HOTKEY:
            if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
            {
#if 0//(_USER_DCR_FUNCTION == _ON)
				if(GET_OSD_DCR_STATUS() == _ON)
				{
					UserAdjustDCRControl(_ON);
				}
#endif
                SET_LOWBLUELIGHT_STATUS(_DISABLE);
                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
                UserAdjustContrast(GET_OSD_CONTRAST());
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            }
            else
            {
#if 0//(_USER_DCR_FUNCTION == _ON)
				if(GET_OSD_DCR_STATUS() == _ON)
				{
					UserAdjustDCRControl(_OFF);
				}
#endif
                SET_LOWBLUELIGHT_STATUS(_ENABLE);
                RTDNVRamLoadColorSetting(_CTLOWBLUELIGHT);
                UserAdjustContrast(_LBL_CONTRAST_DEF);
                UserAdjustBacklightPercent(_LBL_BRIGHTNESS_DEF);
            }  
            
			SET_KEYHOLDKEY();
            OsdDisplayLowBlueLightHotKeyMsg();
			ScalerTimerReactiveTimerEvent(SEC(2), _USER_TIMER_EVENT_OSD_DISABLE);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);			
			break;
#endif	
            
        default:
            break;
    }
}

#if(_INSTANT_TIMER_EVENT_0 == _ON)
//--------------------------------------------------
// Description  : Action in Timer0 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceTimer0InstantAccess_TIMER0(void)
{
    if(GET_OSD_LOGO_ON() == _ON)
    {
        g_ucLogoTimerCounter++;

        if(g_ucLogoTimerCounter == 0xFF)
        {
            g_ucLogoTimerCounter = 0xFF;
        }

        switch(g_ucLogoTimerCounter)
        {
            case _USER_SHOW_LOGO_STEP:
            case (_USER_SHOW_LOGO_STEP * 2):         
            case (_USER_SHOW_LOGO_STEP * 3):
            case (_USER_SHOW_LOGO_STEP * 4):
            case (_USER_SHOW_LOGO_STEP * 5):
            case (_USER_SHOW_LOGO_STEP * 6):
            case (_USER_SHOW_LOGO_STEP * 7):

                ScalerOsdSetTransparency_TIMER(7 - (((WORD)g_ucLogoTimerCounter) / _USER_SHOW_LOGO_STEP));
                
                break;

            default:

                break;
        }
    }
}
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
//--------------------------------------------------
// Description  : Action in Timer1 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceTimer1InstantAccess_TIMER1(void)
{
#if((_USER_DCR_FUNCTION == _ON) && (_DCR_PANEL_ON_OFF == _ON))
	//Eli 20121216 update STD code.
		if((GET_OSD_DCR_STATUS() == _ON) && (SysModeGetModeState() == _MODE_STATUS_ACTIVE))
		{
			if((g_ucDCRBLOffPWM == g_ucPreDCRPWM) && (g_ucPreDCRPWM == 0))
			{		 
				if(g_usDCRBLOffCunt == _BACKLIGHT_OFF_TIMER)
				{
					g_usDCRBLOffCunt++;
					g_bDCRBLOffStart = _ON;
				}
				else if(g_usDCRBLOffCunt < _BACKLIGHT_OFF_TIMER)
				{
					g_usDCRBLOffCunt++;
				}
			}
			else
			{
				g_usDCRBLOffCunt = 0;
				g_bDCRBLOffStart = _OFF;
			}
		}
	 
#endif        
}
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
//--------------------------------------------------
// Description  : Action in Timer2 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceTimer2InstantAccess_TIMER2(void)
{

}
#endif

#if(_UART_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Action in Serial Port0 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceUartIntHandler_SERIALPORT(void)
{
    if(GET_UART_RECEIVE_STATUS() == _TRUE)
    {
        g_ucUartData[0] = GET_UART_DATA();

        CLR_UART_RECEIVE_STATUS();
    }
}
#endif

//--------------------------------------------------
// Description  : User Power Switch
// Input Value  : ucSwitch --> Power Action 
// Output Value : None
//--------------------------------------------------
void UserInterfacePowerSwitch(EnumPowerAction enumSwitch)
{
    switch(enumSwitch)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_ON);                

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_ON);

            // Set Monitor Power On Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _ON);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();
            
#if ((_FACTORY_MODE_OWNER == _OWNER_TPV))//DFM
			TPVDFMPowerRecall();			
#endif
            break;


        case _POWER_ACTION_AC_ON_TO_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Panel pown down.
            UserInterfacePanelPowerAction(_PANEL_OFF);

            break;

        case _POWER_ACTION_NORMAL_TO_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Panel pown down.
            UserInterfacePanelPowerAction(_PANEL_OFF);

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();
            

#if ((_FACTORY_MODE_OWNER == _OWNER_TPV))//DFM
			if(GET_FACTORY_MODE() == _ON)
			{
				SET_FACTORY_MODE(_OFF);
				TPVNVRamSaveFactoryDate();
			}
#elif (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
			SET_FACTORY_MODE(_OFF);
			SET_FACTORY_BURNIN(_OFF);
			NVRamSaveFactoryDate();
	        SET_ENERGY_MODE(_OFF);

#elif (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
			if(GET_FACTORY_MODE() == _ON)
			{
    			SET_FACTORY_MODE(_OFF);
			}
#endif

            break;


        case _POWER_ACTION_PS_TO_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();
            
            break;

        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();

            break;

        case _POWER_ACTION_NORMAL_TO_PS:

            // Update LED Status
		#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 20130808 for ddcci issue
            if(ucDDCPowerSavingTemp == 4)
				UserInterfaceKeyPadLedControl(_LED_POWER_OFF);
			else
		#endif		
	            UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);

            // Panel pown down.
            UserInterfacePanelPowerAction(_PANEL_OFF);

            break;

        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);

            break;

        case _POWER_ACTION_NORMAL_TO_NOSUPPORT_PS:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT_SAVING);

            UserCommonInterfaceOsdResetProc();

            // Panel pown down.
            UserInterfacePanelPowerAction(_PANEL_OFF);

            break;

        default:

            break;
    }

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(_TIMER_OFF);
#endif
}

//--------------------------------------------------
// Description  : User Power On Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceInitial(void)
{
    // Call Uncalled Function for Compile Warning
    UserInterfaceUncallFunction();

#if((_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))
    UserInterfaceSetEmbeddedEDIDData();
#endif

    PCB_PWM_SETTING();
    RTDNVRamStartup();
    
    ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), UserCommonNVRamGetSystemData(_SEARCH_PORT));
    RTDKeyInitial();
    SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);
    SET_SHOW_SOURCE_INFO(_ON);
    // Adjust Backlight
    #if(CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER != ENABLE)
    UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
    #endif

#if(_INPUT_PORT_MAX == 1)//Robert Wang 20140425
    SysSourceSetScanType(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE));
#endif
    
#if ((_FACTORY_MODE_OWNER == _OWNER_TPV))//DFM
	TPVDFMInitial();
    TPVKeyIntoFactory();
#endif
    
}

//--------------------------------------------------
// Description  : Power Power On/Off Sequence
// Input Value  : ucEvent --> _PANEL_ON
//                            _PANEL_OFF
//                            _BACKLIGHT_ON
//                            _BACKLIGHT_OFF
// Output Value : None
//--------------------------------------------------
void UserInterfacePanelPowerAction(BYTE ucEvent)
{
    switch(ucEvent)
    {
        case _PANEL_ON:

            if(GET_PANELPOWERSTATUS() == _PANEL_POWER_OFF_STATE)
            {                
                // Check T6
                ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_PANEL_POWER_OFF);

                // LCD Power on
                PCB_PANEL_POWER(_PANEL_CONTROL_ON);   
                
                ScalerTimerDelayXms(_PANEL_POWER_ON_T1);
            }    

            if(GET_PANELPOWERSTATUS() != _BACKLIGHT_ON_ALREADY)
            {
                // LVDS Power On
                ScalerDisplayLvdsPower(_ON);
                
                ScalerTimerDelayXms(_PANEL_POWER_ON_T2);
                
                // LVDS PLL(Data) On
                ScalerDisplayLvdsPLL(_ON); 

                // Wait Event for Backlight On
                ScalerTimerActiveTimerEvent(_PANEL_POWER_ON_T3, _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);

                SET_PANELPOWERSTATUS(_WAITING_FOR_BACKLIGHT);
            }                        
            
            break;

        case _PANEL_OFF:

            if(GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE)
            {                 
                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);

#if(CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER == ENABLE)
#if(_BACKLIGHT_PWM_INVERSE == _ON)
                PCB_BACKLIGHT_PWM(255);
#else
                PCB_BACKLIGHT_PWM(0);
#endif
                ScalerTimerDelayXms(70);
#endif

#if((_FACTORY_MODE_OWNER == _OWNER_TPV)&&(_PANEL_NORMALLY_STATUS==_PANEL_NORMALLY_WHITE))
                // Ada.chen  20150508_1 add Set Background Color to Black // richer.chen 160223 update
                ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);  
                ScalerDDomainBackgroundEnable(_ENABLE);
#elif ((_FACTORY_MODE_OWNER == _OWNER_TPV)&&(_PANEL_NORMALLY_STATUS==_PANEL_NORMALLY_BLACK))
                // Ada.chen  20150508_1 add Set Background Color to White
                ScalerDDomainBackgroundSetColor(0xFF, 0xFF, 0xFF);  
                ScalerDDomainBackgroundEnable(_ENABLE);
#endif
                ScalerTimerDelayXms(_PANEL_POWER_OFF_T4);

                ScalerDisplayLvdsPLL(_OFF);

                ScalerDisplayLvdsPower(_OFF);
                
                ScalerTimerDelayXms(_PANEL_POWER_OFF_T5);
                
                PCB_PANEL_POWER(_PANEL_CONTROL_OFF);
                
                ScalerTimerActiveTimerEvent(_PANEL_POWER_OFF_T6, _USER_TIMER_EVENT_PANEL_POWER_OFF);

                SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);
            
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);
#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
				// Ada.chen  20150923_1 add Set Background Color to Black
				ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	 
#endif
            }

            break;

        case _BACKLIGHT_ON:
                
            if(GET_PANELPOWERSTATUS() == _PANEL_POWER_OFF_STATE)
            {
                // Check T6
                ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_PANEL_POWER_OFF);
                
                // LCD Power on
                PCB_PANEL_POWER(_PANEL_CONTROL_ON);    

                ScalerTimerDelayXms(_PANEL_POWER_ON_T1);
    
                // LVDS Power On
                ScalerDisplayLvdsPower(_ON);

                ScalerTimerDelayXms(_PANEL_POWER_ON_T2);
                
                // LVDS PLL(Data) On
                ScalerDisplayLvdsPLL(_ON); 

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
				// Ada.chen  20150923_1 add set background
				if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
				{
					// Set Background Color to Black
					ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	
					ScalerDDomainBackgroundEnable(_ENABLE); 			   
				}
#endif                        
                // Wait Delay for Backlight On
                ScalerTimerDelayXms(_PANEL_POWER_ON_T3);

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
				// Ada.chen  20150923_1 add disable background 
				if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
				{
					ScalerDDomainBackgroundEnable(_DISABLE);				
				}
#endif

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

#if(CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER == ENABLE)
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());

                ScalerTimerDelayXms(70);
#endif

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);
            }
            else if(GET_PANELPOWERSTATUS() == _PANEL_BACKLIGHT_OFF)
            {
                // LVDS PLL(Data) On
                ScalerDisplayLvdsPLL(_ON); 

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
				// Ada.chen  20150923_1 add set background
				if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
				{
					// Set Background Color to Black
					ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);	
					ScalerDDomainBackgroundEnable(_ENABLE); 			   
				}	
#endif            
            
                // Wait Delay for Backlight On
                ScalerTimerDelayXms(_PANEL_POWER_ON_T3);

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)								
				// Ada.chen  20150923_1 add disable background
				if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
				{
					ScalerDDomainBackgroundEnable(_DISABLE);				
				}				 
#endif

                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

#if(CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER == ENABLE)
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());

                ScalerTimerDelayXms(70);
#endif

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY); 
            }            
            else
            {   
                ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);
                
                PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_ON);

#if(CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER == ENABLE)
                UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());

                ScalerTimerDelayXms(70);
#endif

                SET_PANELPOWERSTATUS(_BACKLIGHT_ON_ALREADY);
            }            
            
            break;

        case _BACKLIGHT_OFF:
 
            PCB_BACKLIGHT_POWER(_LIGHT_CONTROL_OFF);

#if(CVT_EN_ADJ_CONTROL_BACKLIGHT_POWER == ENABLE)
#if(_BACKLIGHT_PWM_INVERSE == _ON)
            PCB_BACKLIGHT_PWM(255);
#else
            PCB_BACKLIGHT_PWM(0);
#endif
            ScalerTimerDelayXms(70);
#endif

#if((_FACTORY_MODE_OWNER == _OWNER_TPV)&&(_PANEL_NORMALLY_STATUS==_PANEL_NORMALLY_WHITE))
            // Ada.chen  20150508_1 add Set Background Color to Black // richer.chen 160223 update
            ScalerDDomainBackgroundSetColor(0x00, 0x00, 0x00);  
            ScalerDDomainBackgroundEnable(_ENABLE);
#elif ((_FACTORY_MODE_OWNER == _OWNER_TPV)&&(_PANEL_NORMALLY_STATUS==_PANEL_NORMALLY_BLACK))
            // Ada.chen  20150508_1 add Set Background Color to White
            ScalerDDomainBackgroundSetColor(0xFF, 0xFF, 0xFF);  
            ScalerDDomainBackgroundEnable(_ENABLE);
#endif
            ScalerTimerDelayXms(_PANEL_POWER_OFF_T4);

            ScalerDisplayLvdsPLL(_OFF);

            if(GET_PANELPOWERSTATUS() != _PANEL_POWER_OFF_STATE)
            {
                SET_PANELPOWERSTATUS(_PANEL_BACKLIGHT_OFF);
            }

            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_BACKLIGHT_ON);
            
            break;
    
        default:
    
            break;
    }
}

//--------------------------------------------------
// Description  : OSD Power On Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceOsdPowerOnInitial(void)
{

#if(_SIX_COLOR_SUPPORT == _ON)
    BYTE ucIndex = 0;
#endif

    // Adjust Color Palette
//    RTDOsdTableFuncSetColorPalette(_PALETTE_INDEX0, _PALETTE_0);
    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_ENA);//Robert Wang 20140124 for OSD issue

    // Adjust Dither Table
    UserAdjustLoadDitherTable();

    //Adjust YPeaking
#if(_YPEAKING_SUPPORT == _ON)
    UserAdjustYpeaking();
#endif

#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
    {
        UserAdjustPCM(GET_OSD_PCM_STATUS());
    }
    else
#endif

    {
    // Adjust Gamma Table
#if(_GAMMA_FUNCTION == _ON)
        UserAdjustGamma(GET_OSD_GAMMA());
#endif
    }

    // Adjust ICM Table
#if(_ICM_SUPPORT == _ON)
    UserAdjustICM(GET_OSD_COLOR_EFFECT());
#endif

    // Adjust DCC Histogram Settings
#if(_DCC_HISTOGRM_INFO == _ON)
    ScalerColorDCCHistoSetting();
#endif

    // Adjust DCR Threshold
#if(_DCR_SUPPORT == _ON)
    ScalerColorDCRThresholdAdjust(0x08, 0x60);
#endif

    // Adjust Six Color Hue / Saturation
#if(_SIX_COLOR_SUPPORT == _ON)
    if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER)
    {
        for(ucIndex = 0; ucIndex < 6; ucIndex++)
        {
            SET_OSD_SIX_COLOR(ucIndex);
            //RTDOsdDisplaySixColorGetOneColor(ucIndex);
            ScalerColorSixColorAdjust(ucIndex, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION()); 
        }
        
        ScalerColorSixColorEnable();
    }
#endif

    // Adjust Highlight Window Border
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWBorderAdjust((_HLW_BORDER_BOTTOM | _HLW_BORDER_LEFT | _HLW_BORDER_RIGHT | _HLW_BORDER_TOP), _HL_WIN_BORDER_SIZE, 255, 0, 0);
#endif

#if(_OD_SUPPORT == _ON)
    UserAdjustODLoadLUT();
#endif
}

//--------------------------------------------------
// Description  : Set User Required Color Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustColorProc(void)
{    
    if(GET_OSD_STATE() == _MENU_NONE)
    {        
        // Set Color Conversion
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:

                SET_OSD_COLOR_FORMAT(GET_VGA_COLOR_FORMAT_STATUS()); 

                break;
                
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
            case _D0_INPUT_PORT:
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
            case _D1_INPUT_PORT:
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)
            case _D2_INPUT_PORT:
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)
            case _D3_INPUT_PORT:
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || \
    (_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DVI_PORT))
                SET_OSD_COLOR_FORMAT(GET_DVI_COLOR_FORMAT_STATUS()); 
                break;
#endif
                
            default:
                
                if(ScalerColorGetColorSpace() == _COLOR_SPACE_RGB)
                {
                    SET_OSD_COLOR_FORMAT(_COLOR_SPACE_RGB); 
                }
                else
                {
                    SET_OSD_COLOR_FORMAT(_COLOR_SPACE_YPBPR); 
                }
                
                break;
        }
    }
    
    // Adjust Color Space
    if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
    {
        SysModeColorSpaceConvert(_COLOR_SPACE_RGB);
    }
    else
    {
        SysModeColorSpaceConvert(_COLOR_SPACE_YPBPR);
    }

    // Adjust Brightness & Contrast
    RTDNVRamLoadBriCon();

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
    if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
    {
        RTDNVRamLoadColorSetting(_CTLOWBLUELIGHT);
        UserAdjustContrast(_LBL_CONTRAST_DEF);
        UserAdjustBacklightPercent(_LBL_BRIGHTNESS_DEF);
    }
    else if(GET_LOWBLUELIGHT_STATUS() == _DISABLE)
#endif
    {
    	// jimmy 20121011_2 color user dc ac off/on change timing display abnormal	
    	if(GET_COLOR_TEMP_STATUS() == _COLOR_USER)
    	{
    		RTDNVRamLoadColorSetting(_CT_USER);
    	}
    	else
    	{
    		RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
    	}

        if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
        {
            UserAdjustContrast(_OSD_CONTRAST_DEF_VALUE);
            UserAdjustBacklightPercent(_OSD_BRIGHTNESS_DEF_VALUE);
        }
        else
        {
            UserAdjustContrast(GET_OSD_CONTRAST());
            UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
        }
    }
    

    // Adjust Transparency
    ScalerOsdSetTransparency(GET_OSD_TRANSPARENCY_STATUS());

#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
    {
        ScalerColorBriConOff();
        ScalerColorOutputGamma(_ON);
        ScalerColorSRGB(_ON);
        ScalerColorPCMInputGamma(_ON);
    }
    else
#endif   // End of #if(_PCM_FUNCTION == _ON)

    {

#if(_PCM_FUNCTION == _ON)
        ScalerColorPCMInputGamma(_OFF);
#endif

    // Adjust Gamma On/Off
#if(_GAMMA_FUNCTION == _ON)
    if(GET_OSD_GAMMA() == _GAMMA_OFF)
    {
        ScalerColorOutputGamma(_OFF);
    }
    else
    {
        ScalerColorOutputGamma(_ON);
    }
#endif
    
        // Adjust Hue & Saturation
#if(_GLOBAL_HUE_SATURATION == _ON)
        if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_VIVID)
        {
            ScalerColorSRGBSetGlobalHueSat(((SWORD)_DEFAULT_HUE - (SWORD)GET_OSD_HUE()), 140);
        }
        else
        {
            ScalerColorSRGBSetGlobalHueSat(((SWORD)_DEFAULT_HUE - (SWORD)GET_OSD_HUE()), GET_OSD_SATURATION());
        }
    
        ScalerColorSRGB(_ON); 
#endif  // End of #if(_GLOBAL_HUE_SATURATION == _ON)

        //UserAdjustBrightness(GET_OSD_BRIGHTNESS());
        //UserAdjustContrast(GET_OSD_CONTRAST());
    }

    // Adjust ICM On/Off
#if(_ICM_SUPPORT == _ON)
    if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_STANDARD)
    {
        ScalerColorICM(_OFF);
    }
    else
    {
        ScalerColorICM(_ON);
    }
#endif

    // Adjust DCC On/Off
#if(_DCC_FUNCTION == _ON)
    if((GET_OSD_COLOR_EFFECT() == _COLOREFFECT_STANDARD) || (GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER))
    {
        ScalerColorDCC(_OFF);
    }
    else
    {
        ScalerColorDCC(_ON);
    }
#endif

#if(_YPEAKING_SUPPORT == _ON)
    ScalerColorYpeaking(_ON);
#endif

    // Adjust Highlight Window Type & On/Off
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    // Adjust Highlight Window Effect Space
    UserAdjustHighLightWindowEffectSpace();

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    if(GET_OSD_ASPECT_RATIO_TYPE() != _ASPECT_RATIO_ORIGIN)
#endif
    {
        if(GET_OSD_HLWIN_TYPE() == _HL_WIN_OFF)
        {
            ScalerColorHLW(_OFF);
        }
        else
        {
            UserAdjustHLWinType(GET_OSD_HLWIN_TYPE());
            ScalerColorHLW(_ON);
        }
    }
#endif  // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

#if(_OD_SUPPORT == _ON)
    ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());    
#endif // End of #if(_OD_SUPPORT == _ON)

#if(_ENERGY_STAR_SUPPORT == _ON)
     // Adjust Energy stat function On/Off
    UserCommonAdjustESDcrProcess(GET_OSD_ES_STATUS());
#endif
}

//--------------------------------------------------
// Description  : OSD Active Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceOsdActiveProc(void)
{             

    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    {
        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        UserCommonNVRamSaveSystemData();
        SET_SHOW_SOURCE_INFO(_ON);
    } 


#if(_OD_SUPPORT == _ON)
    ScalerODControl(GET_OSD_OD_STATUS()); 
#endif

    // Adjust Sharpness
    UserAdjustSharpness(GET_OSD_SHARPNESS());

    // Adjust UltraVivid
#if(_ULTRA_VIVID_SUPPORT == _ON)

    if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
    {
        UserCommonAdjustUltraVivid(_COLOR_SPACE_RGB);
    }
    else
    {
        UserCommonAdjustUltraVivid(_COLOR_SPACE_YPBPR);
    }

#elif(_2D_TO_3D_FUNCTION == _ON)

    if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)    
    {
        SysModeColorSpaceConvert(_COLOR_SPACE_RGB);
    }
    else
    {
        SysModeColorSpaceConvert(_COLOR_SPACE_YPBPR);
    } 

#endif

    // Adjust DCC Table
#if(_DCC_FUNCTION == _ON)
    UserAdjustDCC(GET_OSD_COLOR_EFFECT());
#endif

    if(UserInterfaceGetActiveByPass() == _FALSE)
    {    
        // DDCCI switch to active port
        ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());    
                
        if(GET_FAIL_SAFE_MODE() == _TRUE)
        {
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG);
        }
        else
        {
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_ACTIVE_DO_ONE_TIME_MSG);
        }
    }

    // jimmy 20120912 update source info osd behavior
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)//DFM do not show input info
	if(TPVDFMAutoConfigByPass()==_TRUE)
    {
    	ScalerDDomainBackgroundEnable(_DISABLE);    
       	return;
    }         
#endif       

/*    // EasonLee Modify
	if(GET_OSD_STATE() == _MENU_NONE)
	{
		if((SysSourceGetSourceType() != _SOURCE_VGA)
		||((SysSourceGetSourceType() == _SOURCE_VGA)&&(GET_FAIL_SAFE_MODE() == _TRUE))
		||((SysSourceGetSourceType() == _SOURCE_VGA)&&(UserInterfaceFirstAutoConfig() == _FALSE)))
		{		
			OsdDispInputInfo();
	        ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);		
		}
	}
*/
    ScalerDDomainBackgroundEnable(_DISABLE);    
}

//--------------------------------------------------
// Description  : OSD Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceOsdResetProc(void)
{    
#if(_AUDIO_SUPPORT == _ON)
    UserInterfaceAudioResetProc();
#endif

    // Turn off backlight
    if(GET_OSD_LOGO_ON() == _OFF)
    {
        OsdDispDisableOsdTimerEvent();
    }

    SET_OSD_LOGO_ON(_OFF);

    // Cancel Timer Events
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_FLY_OSD_TO_POWER_SAVING);//lorimiao 20140609 for FAIL_SAFE_MODE OOR go to Power saving Issue
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GO_TO_POWER_SAVING);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DO_AUTO_COLOR);

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)	
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_HLWIN_TYPE5_MOVE);
#endif

#if(_ENERGY_STAR_SUPPORT == _ON)
    UserCommonAdjustESDcrProcess(_OFF);
#endif

	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_FLYING);
#if 1//Robert Wang 20130219
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SUPPORT);    
	ScalerTimerCancelTimerEvent(_OSDEVENT_SHOW_NOSUPPORT_MSG);    
#endif

#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BURN_IN);//DFM rev02 patch note 7

//DFM rev02 patch note 8>>
    SET_OSD_IN_FACTORY_MENU_STATUS(_OFF);
    if(SysModeGetModeState() == _MODE_STATUS_NOSIGNAL)
    {
		FC_EDID_EEPROM_WP_ENABLE();
    }
#endif

#if (_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BURN_IN);
    ucBurnInStopCount = 0;//lorimiao 20150515
#endif

	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_LOCK);     //Ada.chen   20161123
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DDCCI);
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_LOWBLUELIGHT_HOTKEY);
#endif   

#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_BURN_IN);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LED_FLASH);
	ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_EDIDVERSION_CLEAR);
#endif
}

//--------------------------------------------------
// Description  : User OSD Get LogoOn
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceOsdGetLogoOn(void)
{
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
#if (_DFM_BYPASS_FORCE_PANELOFF == _ON)
	if(GET_OSD_LOGO_ON()==_OFF)
	{
		if(TPVDFMForcePanelOff()== _TRUE)
		{
			UserInterfacePanelPowerAction(_BACKLIGHT_OFF);
			return (_ON);
		}
	}
#endif
#endif
    return (GET_OSD_LOGO_ON());
}

//--------------------------------------------------
// Description  : Check Whther to support this timing
// Input Value  : None
// Output Value : TRUE => Go to No Support State
//--------------------------------------------------
bit UserInterfaceOsdNoSupportCheck(void)
{
    //Add User No Support Check
#if 0//Robert Wang 20140422
    #warning "Some thing is just for test!!"
#else
    if(GET_INPUT_TIMING_VFREQ() < _OOR_V_FREQ_LOWER_BOUND)
    {
        return _TRUE;
    }
    //Eli 20121114 Other source do not support interlace mode except HDMI. 
    if((SysSourceGetSourceType() != _SOURCE_HDMI) && (SysSourceGetSourceType() != _SOURCE_DP) && (GET_INPUT_TIMING_HWIDTH() <= _PANEL_DH_WIDTH) && (GET_INPUT_TIMING_VHEIGHT() <= (_PANEL_DV_HEIGHT)) && (GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE))
    {
        return _TRUE;
    }
    else if(((GET_INPUT_TIMING_HWIDTH() > _PANEL_DH_WIDTH) && (GET_INPUT_TIMING_VHEIGHT() > _PANEL_DV_HEIGHT))
            ||((GET_INPUT_TIMING_HWIDTH() > _PANEL_DH_WIDTH) && (GET_INPUT_TIMING_VHEIGHT() > (_PANEL_DV_HEIGHT/2)) && (GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)))
    {
        SET_FAIL_SAFE_MODE(_TRUE);
    } 
#endif

    return _FALSE;
}


//--------------------------------------------------
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : Current Input Timing Info
// Output Value : Modified Input Timing
//--------------------------------------------------
void UserInterfaceAdjustInputTiming(void)
{
#if(_3D_SUPPORT == _ON)
    if((GET_OSD_3D_STATUS() == _3D_2D_TO_3D) && (Scaler3DTxInputFormat() != _NO_3D_FORMAT))
    {
        SET_OSD_3D_STATUS(_3D_ON); 
    }

    if(Scaler3DTxInputFormat() == _FRAME_PACKING)
    {
        SET_OSD_3D_FORMAT_STATUS(_3D_MODE_FORMAT_AUTO);      
    }

    switch(GET_OSD_3D_STATUS())
    {
        case _3D_OFF:

            pData[0] = _3D_OFF;

            break;

        case _3D_ON:

            pData[0] = _3D_ON;

            break;

        case _3D_2D_TO_3D:

            pData[0] = _3D_2D_TO_3D;

            break;  

        default:

            pData[0] = _3D_OFF;

            break;
    }

    switch(GET_OSD_3D_FORMAT_STATUS())
    {
        case _3D_MODE_FORMAT_AUTO:

            pData[1] = _3D_MODE_FORMAT_AUTO;

            break;

        case _3D_MODE_FORMAT_SBS:

            pData[1] = _3D_MODE_FORMAT_SBS;

            break;

        case _3D_MODE_FORMAT_TNB:

            pData[1] = _3D_MODE_FORMAT_TNB;

            break;

        case _3D_MODE_FORMAT_LINE_INTERLACE:

            pData[1] = _3D_MODE_FORMAT_LINE_INTERLACE;

            break; 

        default:

            pData[1] = _3D_MODE_FORMAT_AUTO;

            break;
    }

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        pData[2] = 0x08;
    }
    else
    {
        pData[2] = 0x3F;
    }
    
    Scaler3DSetInOutFormat((pData[0] & 0x03), (pData[1] & 0x03), GET_OSD_3D_LR_STATUS(), GET_OSD_3D_3DTO2D());
    Scaler3DSetConvEff(pData[2], GET_OSD_3D_EFFECT_REAL_VALUE(), GET_OSD_3D_CONVERGENCE(), GET_OSD_3D_CONVERGENCE_MODE());        

#endif
#if(OOR_DCLK_CHECK == _ON) 

#if(1)//from gray OSD

    //20121112_0 Abel 自動修正DCLK功能 Modify(3%)
	// jimmy 20121023 when dclk over spec calculate DHtotal & V height to adjust DCLK automatically (計算出DCLK)
    PDATA_DWORD(0) = (DWORD)(g_stMDomainOutputData.usHTotal) * (DWORD)g_stMDomainInputData.usHFreq * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight / 10; 
    //ScalerDebugMessage("1. DCLK ",PDATA_DWORD(0));
    //ScalerDebugMessage("DCLK Max (95%DCLK)",(DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000 - _DCLK_SPREAD_RANGE * 5 / 2 - 10));
    //ScalerDebugMessage("DCLK Min (105%DCLK)",(DWORD)_PANEL_PIXEL_CLOCK_MIN * (1000 + _DCLK_SPREAD_RANGE * 5 / 2 + 10));

#if((_PANEL_TYPE == _TPV_LG_LM230WF9_SSA1) || (_PANEL_TYPE == _TPV_LG_LM230WF7_SSB1)) //for T2364p&&T2364t support timing 800*600/72 //richer.chen

	// DCLK over panel max DCLK(Max x 95%)
	if(PDATA_DWORD(0) >= ((DWORD)_PANEL_PIXEL_CLOCK_MAX * 1000 ))  
	{	         
        // Calculate Target DHTotal
        PDATA_DWORD(1) = g_stMDomainOutputData.usHTotal * ((DWORD)_PANEL_PIXEL_CLOCK_MAX * 1000 ) / PDATA_DWORD(0);
        
        // Make Sure DHTotal to be 4's multiple
        PDATA_DWORD(1) -= PDATA_DWORD(1) % 4;        

        if(PDATA_DWORD(1) < _PANEL_DH_TOTAL_MIN)
        {
            PDATA_DWORD(1) = _PANEL_DH_TOTAL_MIN;
        }          
            
        PDATA_DWORD(0) = PDATA_DWORD(0) * PDATA_DWORD(1) / g_stMDomainOutputData.usHTotal;  //修正過後的DCLK
        g_stMDomainOutputData.usHTotal = PDATA_DWORD(1);                                   //修正後的HTotal
        //ScalerDebugMessage("DHTotal Adjust ",PDATA_DWORD(1));   

		// reduce scaling ratio to reduce DCLK
		PDATA_DWORD(0) = (DWORD)(g_stMDomainOutputData.usHTotal) * (DWORD)g_stMDomainInputData.usHFreq * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight / 10; 
        //ScalerDebugMessage("DCLK Adjust (DHTotal)",PDATA_DWORD(0));       
        
        //修正Input VHeight
		if(PDATA_DWORD(0) >= ((DWORD)_PANEL_PIXEL_CLOCK_MAX * 1000 ))
		{		            
			// target height(修正Input VHeight)
			PDATA_DWORD(1) = ((SDWORD)g_stMDomainInputData.usHFreq * g_stMDomainOutputData.usHTotal *g_stMDomainOutputData.usVHeight / 10) /((DWORD)_PANEL_PIXEL_CLOCK_MAX * 1000 );			
            //ScalerDebugMessage("DCLK Adjust ( VHeight)",PDATA_DWORD(1)); 
			if(PDATA_DWORD(1) <= (GET_MDOMAIN_INPUT_VTOTAL() - (GET_MDOMAIN_INPUT_VSYNCWIDTH()+3+2)))
			{
				SET_MDOMAIN_INPUT_VHEIGHT(PDATA_DWORD(1));
				SET_MDOMAIN_INPUT_VSTART(GET_MDOMAIN_INPUT_VSYNCWIDTH() + 3 + (((GET_MDOMAIN_INPUT_VTOTAL() - (GET_MDOMAIN_INPUT_VSYNCWIDTH()+3+2)) - (PDATA_DWORD(1)))/2));			
			}		
		}
	}   

#else

		// DCLK over panel max DCLK(Max x 95%)
		if(PDATA_DWORD(0) >= ((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000 - _DCLK_SPREAD_RANGE * 5 / 2)))  
		{			 
			// Calculate Target DHTotal
			PDATA_DWORD(1) = g_stMDomainOutputData.usHTotal * ((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000 - _DCLK_SPREAD_RANGE * 5 / 2 )) / PDATA_DWORD(0);
			
			// Make Sure DHTotal to be 4's multiple
			PDATA_DWORD(1) -= PDATA_DWORD(1) % 4;		 

			if(PDATA_DWORD(1) < _PANEL_DH_TOTAL_MIN)
			{
				PDATA_DWORD(1) = _PANEL_DH_TOTAL_MIN;
			}		   
				
			PDATA_DWORD(0) = PDATA_DWORD(0) * PDATA_DWORD(1) / g_stMDomainOutputData.usHTotal;	//修正過後的DCLK
			g_stMDomainOutputData.usHTotal = PDATA_DWORD(1);								   //修正後的HTotal
			//ScalerDebugMessage("DHTotal Adjust ",PDATA_DWORD(1));   

			// reduce scaling ratio to reduce DCLK
			PDATA_DWORD(0) = (DWORD)(g_stMDomainOutputData.usHTotal) * (DWORD)g_stMDomainInputData.usHFreq * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight / 10; 
			//ScalerDebugMessage("DCLK Adjust (DHTotal)",PDATA_DWORD(0));		
			
			//修正Input VHeight
			if(PDATA_DWORD(0) >= ((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000 - _DCLK_SPREAD_RANGE * 5 / 2)))
			{					
				// target height(修正Input VHeight)
				PDATA_DWORD(1) = ((SDWORD)g_stMDomainInputData.usHFreq * g_stMDomainOutputData.usHTotal *g_stMDomainOutputData.usVHeight / 10) /((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000 - _DCLK_SPREAD_RANGE * 5 / 2 )); 		
				//ScalerDebugMessage("DCLK Adjust ( VHeight)",PDATA_DWORD(1)); 
				if(PDATA_DWORD(1) <= (GET_MDOMAIN_INPUT_VTOTAL() - (GET_MDOMAIN_INPUT_VSYNCWIDTH()+3+2)))
				{
					SET_MDOMAIN_INPUT_VHEIGHT(PDATA_DWORD(1));
					SET_MDOMAIN_INPUT_VSTART(GET_MDOMAIN_INPUT_VSYNCWIDTH() + 3 + (((GET_MDOMAIN_INPUT_VTOTAL() - (GET_MDOMAIN_INPUT_VSYNCWIDTH()+3+2)) - (PDATA_DWORD(1)))/2));			
				}		
			}
		}	

#endif
//20141217 Abel DVtotal修正   
#if(_FRC_SUPPORT == _OFF)            
    // Calculate frame sync DVtotal
    PDATA_WORD(0) = (DWORD)g_stMDomainInputData.usVTotal * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight;
    //ScalerDebugMessage("DVtotal1",PDATA_WORD(0));     
    
    CLR_DVTotal_OverSpec_FLAG(); //OOR Flag  
    
    if((PDATA_WORD(0) > (_PANEL_DV_TOTAL_MAX - 2)) || (PDATA_WORD(0) < (_PANEL_DV_TOTAL_MIN + 2))) 
    {
        //修正DVtotal為Panel最大小值(計算Input VHeight)
  		if(PDATA_WORD(0) > (_PANEL_DV_TOTAL_MAX - 2))
   		{                           
            PDATA_DWORD(1) = (DWORD)g_stMDomainInputData.usVTotal * g_stMDomainOutputData.usVHeight / (_PANEL_DV_TOTAL_MAX - 2);
   		}    
        else if(PDATA_WORD(0) < (_PANEL_DV_TOTAL_MIN + 2))    
        {            
            PDATA_DWORD(1) = (DWORD)g_stMDomainInputData.usVTotal * g_stMDomainOutputData.usVHeight / (_PANEL_DV_TOTAL_MIN + 2);
        }  
        //ScalerDebugMessage("DVTotal Adjust(VHeight)",PDATA_DWORD(1)); 
        if(PDATA_DWORD(1) <= (GET_MDOMAIN_INPUT_VTOTAL() - (GET_MDOMAIN_INPUT_VSYNCWIDTH()+3+2)))
  		{            
  			SET_MDOMAIN_INPUT_VHEIGHT(PDATA_DWORD(1));
   			SET_MDOMAIN_INPUT_VSTART(GET_MDOMAIN_INPUT_VSYNCWIDTH() + 3 + (((GET_MDOMAIN_INPUT_VTOTAL() - (GET_MDOMAIN_INPUT_VSYNCWIDTH()+3+2)) - (PDATA_DWORD(1)))/2));			
            // Calculate frame sync DVtotal
            PDATA_WORD(0) = (DWORD)g_stMDomainInputData.usVTotal * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight;
            //ScalerDebugMessage("DVtotal2",PDATA_WORD(0));                       
   		}	
        else
        {
            SET_DVTotal_OverSpec_FLAG(); //OOR Flag   
        }              
    } 
#endif        
          
#else//from AOC code
	// Calculate DClk for Frame Sync
	PDATA_DWORD(0) = (DWORD)(_PANEL_DH_TOTAL) * (DWORD)GET_MDOMAIN_INPUT_HFREQ() * (DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() / GET_MDOMAIN_INPUT_VHEIGHT() /	10; 	
	//check DCLK  if it over panel pixel clk Maximum
	if(PDATA_DWORD(0) >= ((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000-(_DCLK_SPREAD_RANGE*10/2))))
	{
		// Calculate Target DHTotal
		PDATA_DWORD(1) = (DWORD)_PANEL_DH_TOTAL * ((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000-(_DCLK_SPREAD_RANGE*10/2))) / PDATA_DWORD(0);		
		if(PDATA_DWORD(1) <= _PANEL_DH_TOTAL_MIN)
		{
			// Calculate Target Capture VHeight
			PDATA_DWORD(0) = (DWORD)_PANEL_DH_TOTAL_MIN * (DWORD)GET_MDOMAIN_INPUT_HFREQ() * (DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() / ((DWORD)_PANEL_PIXEL_CLOCK_MAX * (1000-(_DCLK_SPREAD_RANGE*10/2))) / 10; 
			//check capture
			if ((PDATA_DWORD(0)>(GET_MDOMAIN_INPUT_VHEIGHT()))&&(PDATA_DWORD(0)<(GET_MDOMAIN_INPUT_VTOTAL()-GET_MDOMAIN_INPUT_VSYNCWIDTH()-6)))// 20121030 by jerry, need to confirm)
			{				
				SET_MDOMAIN_INPUT_VSTART(GET_MDOMAIN_INPUT_VSTART() - ((PDATA_DWORD(0)-GET_MDOMAIN_INPUT_VHEIGHT())/ 2));
				SET_MDOMAIN_INPUT_VHEIGHT(PDATA_DWORD(0));
			}
		}
	}
#endif

#endif    

}

//--------------------------------------------------
// Description  : Modify Display Timing Based on User Requirement
// Input Value  : Current Display Timing Info
// Output Value : Modified Display Timing
//--------------------------------------------------
void UserInterfaceAdjustDisplayTiming(void)
{
#if(_ASPECT_RATIO_SUPPORT == _ON)
    UserAdjustSelectAspectRatio();
#endif
}

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
//--------------------------------------------------
// Description  : Decide whether to Enable FREESYNC Function
// Input Value  : None
// Output Value : Ture or False
//--------------------------------------------------
bit UserInterfaceGetFREESYNCEnable_EXINT1(void) using 2
{
    return _TRUE;//GET_OSD_FREE_SYNC_STATUS();
}
#endif


#if((_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))
//--------------------------------------------------
// Description  : Set Embedded EDID Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceSetEmbeddedEDIDData(void)
{
// A0 EDID
#if(_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE)
#if(_EMBEDDED_DDCRAM_A0_LOCATION == _EDID_TABLE_LOCATION_CODE)
    memcpy(MCU_DDCRAM_A0, tEDID_TABLE_A0, _EMBEDDED_DDCRAM_A0_SIZE);
#elif(_EMBEDDED_DDCRAM_A0_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamRead(_EEPROM_EDID_A0_ADDRESS, _EMBEDDED_DDCRAM_A0_SIZE, MCU_DDCRAM_A0);
#elif(_EMBEDDED_DDCRAM_A0_LOCATION == _EDID_TABLE_LOCATION_USER)

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99
	UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, (_VGAEDID_PAGE * _FLASH_PAGE_SIZE) + _VGAEDID_OFFSET, _EMBEDDED_DDCRAM_A0_SIZE, MCU_DDCRAM_A0);
#endif // End of #ifdef _SUPPORT_PC99
//DFM rev07 patch note 3 <<
#endif

#endif // End of #if(_EMBEDDED_DDCRAM_A0_LOCATION == _EDID_TABLE_LOCATION_CODE)
#endif // End of #if(_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE) 

// D0 EDID
#if(_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE)

#if(_EMBEDDED_DDCRAM_D0_LOCATION == _EDID_TABLE_LOCATION_CODE)
    memcpy(MCU_DDCRAM_D0, tEDID_TABLE_D0, _EMBEDDED_DDCRAM_D0_SIZE);
#elif(_EMBEDDED_DDCRAM_D0_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamRead(_EEPROM_EDID_D0_ADDRESS, _EMBEDDED_DDCRAM_D0_SIZE, MCU_DDCRAM_D0);
#elif(_EMBEDDED_DDCRAM_D0_LOCATION == _EDID_TABLE_LOCATION_USER)

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
	UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, (_DVIEDID_PAGE * _FLASH_PAGE_SIZE) + _DVIEDID_OFFSET, _EMBEDDED_DDCRAM_D0_SIZE, MCU_DDCRAM_D0);
#elif(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
	UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, (_HDMIEDID_PAGE * _FLASH_PAGE_SIZE) + _HDMIEDID_OFFSET, _EMBEDDED_DDCRAM_D0_SIZE, MCU_DDCRAM_D0);
#endif
#endif // End of #ifdef _SUPPORT_PC99
//DFM rev07 patch note 3 <<
#endif

#endif // End of #if(_EMBEDDED_DDCRAM_D0_LOCATION == _EDID_TABLE_LOCATION_CODE)
#endif // End of #if(_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE) 

// D1 EDID
#if(_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE)

#if(_EMBEDDED_DDCRAM_D1_LOCATION == _EDID_TABLE_LOCATION_CODE)
    memcpy(MCU_DDCRAM_D1, tEDID_TABLE_D1, _EMBEDDED_DDCRAM_D1_SIZE);
#elif(_EMBEDDED_DDCRAM_D1_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamRead(_EEPROM_EDID_D1_ADDRESS, _EMBEDDED_DDCRAM_D1_SIZE, MCU_DDCRAM_D1);
#elif(_EMBEDDED_DDCRAM_D1_LOCATION == _EDID_TABLE_LOCATION_USER)

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
	UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, (_DVIEDID_PAGE * _FLASH_PAGE_SIZE) + _DVIEDID_OFFSET, _EMBEDDED_DDCRAM_D1_SIZE, MCU_DDCRAM_D1);
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
	UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, (_HDMIEDID_PAGE * _FLASH_PAGE_SIZE) + _HDMIEDID_OFFSET, _EMBEDDED_DDCRAM_D1_SIZE, MCU_DDCRAM_D1);
#endif
#endif // End of #ifdef _SUPPORT_PC99
//DFM rev07 patch note 3 <<
#endif

#endif // End of #if(_EMBEDDED_DDCRAM_D1_LOCATION == _EDID_TABLE_LOCATION_CODE)
#endif // End of #if(_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE) 

#if(_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE)

#if(_EMBEDDED_DDCRAM_D0_MHL_LOCATION == _EDID_TABLE_LOCATION_CODE)
    memcpy(MCU_DDCRAM_MHL, tEDID_TABLE_D0_MHL, _EMBEDDED_DDCRAM_D0_MHL_SIZE);
#elif(_EMBEDDED_DDCRAM_D0_MHL_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamRead(_EEPROM_EDID_D0_MHL_ADDRESS, _EMBEDDED_DDCRAM_D0_MHL_SIZE, MCU_DDCRAM_MHL);
#elif(_EMBEDDED_DDCRAM_D0_MHL_LOCATION == _EDID_TABLE_LOCATION_USER)

#endif // End of #if(_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE)

#elif(_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE)

#if(_EMBEDDED_DDCRAM_D1_MHL_LOCATION == _EDID_TABLE_LOCATION_CODE)
    memcpy(MCU_DDCRAM_MHL, tEDID_TABLE_D1_MHL, _EMBEDDED_DDCRAM_D1_MHL_SIZE);
#elif(_EMBEDDED_DDCRAM_D1_MHL_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamRead(_EEPROM_EDID_D1_MHL_ADDRESS, _EMBEDDED_DDCRAM_D1_MHL_SIZE, MCU_DDCRAM_MHL);
#elif(_EMBEDDED_DDCRAM_D1_MHL_LOCATION == _EDID_TABLE_LOCATION_USER)

#endif // End of #if(_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE)

#endif // End of #if(_D0_INPUT_PORT == _D0_MHL_PORT)

#if((_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))

#if(_EMBEDDED_DDCRAM_D0_MHL_LOCATION == _EDID_TABLE_LOCATION_CODE)
    g_ucD0MHLEDIDDiff[0] = tEDID_TABLE_D0_MHL[_EDID_VENDOR_SPEC_0];
    g_ucD0MHLEDIDDiff[1] = tEDID_TABLE_D0_MHL[_EDID_CHKSUM];
#elif(_EMBEDDED_DDCRAM_D0_MHL_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamRead(_EEPROM_EDID_D0_MHL_ADDRESS + _EDID_VENDOR_SPEC_0, 1, &g_ucD0MHLEDIDDiff[0]);
    UserCommonNVRamRead(_EEPROM_EDID_D0_MHL_ADDRESS + _EDID_CHKSUM, 1, &g_ucD0MHLEDIDDiff[1]);
#elif(_EMBEDDED_DDCRAM_D0_MHL_LOCATION == _EDID_TABLE_LOCATION_USER)

#endif // End of #if(_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE)

#if(_EMBEDDED_DDCRAM_D1_MHL_LOCATION == _EDID_TABLE_LOCATION_CODE)
    g_ucD1MHLEDIDDiff[0] = tEDID_TABLE_D1_MHL[_EDID_VENDOR_SPEC_0];
    g_ucD1MHLEDIDDiff[1] = tEDID_TABLE_D1_MHL[_EDID_CHKSUM];
#elif(_EMBEDDED_DDCRAM_D1_MHL_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamRead(_EEPROM_EDID_D1_MHL_ADDRESS + _EDID_VENDOR_SPEC_0, 1, &g_ucD1MHLEDIDDiff[0]);
    UserCommonNVRamRead(_EEPROM_EDID_D1_MHL_ADDRESS + _EDID_CHKSUM, 1, &g_ucD1MHLEDIDDiff[1]);
#elif(_EMBEDDED_DDCRAM_D1_MHL_LOCATION == _EDID_TABLE_LOCATION_USER)

#endif // End of #if(_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE)

#endif // End of #if((_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE)

}
#endif // End of #if((_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) || (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))

#if((_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE))
//--------------------------------------------------
// Description  : Change MHL EDID Data when 2MHL Port are Supported
// Input Value  : ucInputPort --> D0 or D1
// Output Value : None
//--------------------------------------------------
void UserInterfaceChangeMHLEDIDData(BYTE ucInputPort)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
        MCU_DDCRAM_MHL[_EDID_VENDOR_SPEC_0] = g_ucD0MHLEDIDDiff[0];
        MCU_DDCRAM_MHL[_EDID_CHKSUM] = g_ucD0MHLEDIDDiff[1];
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        MCU_DDCRAM_MHL[_EDID_VENDOR_SPEC_0] = g_ucD1MHLEDIDDiff[0];
        MCU_DDCRAM_MHL[_EDID_CHKSUM] = g_ucD1MHLEDIDDiff[1];
    }
}
#endif // End of #if((_EMBEDDED_DDCRAM_D0_MHL_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_D1_MHL_SIZE != _EDID_SIZE_NONE)

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray)
{
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)

#if(_HDCP_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pReadArray, tHDCP_KEY_BKSV + ucSubAddr, ucLength);

#elif(_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamGetHDCPKeyBKsv(ucSubAddr, ucLength, pReadArray);

#endif

#else

#if 1//Robert Wang 20121129
#if(_HDCP_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pReadArray, tHDCP_KEY_BKSV + ucSubAddr, ucLength);

#elif(_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
    UserCommonNVRamGetHDCPKeyBKsv(ucSubAddr, ucLength, pReadArray);

#else
    #warning "HDCP Key Located in Flash is not implemented yet!!"

#endif

#elif(_HDCP_KEY_LOCATION == _TABLE_LOCATION_USER)

#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _OFF)

    UserCommonEepromRead((_EEPROM_HDCP_KEY_ADDRESS + ucSubAddr), ucLength, pReadArray);
#else
    //ucSubAddr = 0;
    //UserCommonFlashRead(_FLASH_BANK, ((_HDCP_PAGE) * _FLASH_PAGE_SIZE), ucLength, pReadArray);
    //TpvFactHdcpGetFlashHdcpBKsv(ucSubAddr,ucLength,pReadArray); 
	UserCommonFlashRead(_EEPROM_HDCP_KEY_FLASH_BANK,_EEPROM_HDCP_KEY_ADDRESS + ucSubAddr, ucLength, pReadArray);
#endif

#endif
#else
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)	
    if(_HDCP_IN_EEPROM == GET_TPV_HDCP_IN_EEPROM_STATUS())
    {
        UserCommonNVRamGetHDCPKeyBKsv(ucSubAddr, ucLength, pReadArray);
    }
    else
    {
        TpvFactHdcpGetFlashHdcpBKsv(ucSubAddr,ucLength,pReadArray);          
    }
#else

#if(_HDCP_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pReadArray, tHDCP_KEY_BKSV + ucSubAddr, ucLength);

#elif(_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamGetHDCPKeyBKsv(ucSubAddr, ucLength, pReadArray);

#endif

#endif//#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
#endif

#endif

}

//--------------------------------------------------
// Description  : Get HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{
#if(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)

#if(_HDCP_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pReadArray, tHDCP_KEY_TABLE + usSubAddr, usLength);

#elif(_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamGetHDCPKey(usSubAddr, usLength, pReadArray);

#endif

#else

#if 1//Robert Wang 20121129
#if(_HDCP_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pReadArray, tHDCP_KEY_TABLE + usSubAddr, usLength);

#elif(_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
    UserCommonNVRamGetHDCPKey(usSubAddr, usLength, pReadArray);

#else
    #warning "HDCP Key Located in Flash is not implemented yet!!"

#endif

#elif(_HDCP_KEY_LOCATION == _TABLE_LOCATION_USER)

#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _OFF)

    UserCommonEepromRead((_EEPROM_HDCP_KEY_ADDRESS   +5 + usSubAddr), usLength, pReadArray);
#else
    //usSubAddr = 5;
    //UserCommonFlashRead(_FLASH_BANK, ((_HDCP_PAGE) * _FLASH_PAGE_SIZE + 5), usLength, pReadArray);
   // TpvFactHdcpGetFlashHdcpKey(usSubAddr,usLength,pReadArray);
	UserCommonFlashRead(_EEPROM_HDCP_KEY_FLASH_BANK,_EEPROM_HDCP_KEY_ADDRESS +5 + usSubAddr, usLength, pReadArray);
#endif
#endif

#else
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)	
    if(_HDCP_IN_EEPROM == GET_TPV_HDCP_IN_EEPROM_STATUS())
    {
         UserCommonNVRamGetHDCPKey(usSubAddr, usLength, pReadArray);
    }
    else
    {
        TpvFactHdcpGetFlashHdcpKey(usSubAddr,usLength,pReadArray);          
    }

#else

#if(_HDCP_KEY_LOCATION == _TABLE_LOCATION_CODE)
    memcpy(pReadArray, tHDCP_KEY_TABLE + usSubAddr, usLength);

#elif(_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM)
    UserCommonNVRamGetHDCPKey(usSubAddr, usLength, pReadArray);

#endif

#endif//#if(_FACTORY_MODE_OWNER == _OWNER_TPV)
#endif

#endif

}

#if((_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
//--------------------------------------------------
// Description  : Restore default HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceNVRamRestoreHDCP(void)
{
    BYTE ucCount = 0;
    BYTE ucBuffer[16] = {0};

    // Dump BKSV into NVRAM
    memcpy(ucBuffer, tHDCP_KEY_BKSV, sizeof(tHDCP_KEY_BKSV));
    UserCommonNVRamRestoreHDCP(0, sizeof(tHDCP_KEY_BKSV), ucBuffer);

    // Dump HDCP Key into NVRAM
    for(ucCount = 0; ucCount < 20; ucCount++)
    {
        memcpy(ucBuffer, tHDCP_KEY_TABLE + ucCount * sizeof(ucBuffer), sizeof(ucBuffer));
        UserCommonNVRamRestoreHDCP(5 + ucCount * sizeof(ucBuffer), sizeof(ucBuffer), ucBuffer);
    }
}
#endif // #if((_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
#endif // #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Load one iterm from flash
// Input Value  : enumItemID: flash item id
//                pucData: buf to save data loaded
//                ucLength: buf length
// Output Value : return _TRUE if load success, else return _FALSE
//--------------------------------------------------
bit UserInterfaceFlashLoadItem(EnumFlashItemIDType enumItemID, BYTE* pucData, BYTE ucLength)
{
    BYTE ucCnt = 0;
    BYTE ucItemChecksum = 0;
    WORD usAddrIndex = 0;
    WORD usPageAddr = 0;
    WORD usItemAddr = 0;
    BYTE ucDataArry[_DATA_ITEM_LENGTH] = {0};
    BYTE ucPageID = HIBYTE(enumItemID);

    if(ucLength > (_DATA_ITEM_LENGTH - 2))
    {
        return _FALSE;
    }

    usPageAddr = g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE;

    // Find the data item which item index is ucIndex in the ucPage page from bottom to top
    for(usAddrIndex = g_usFlashAddrArr[ucPageID]; usAddrIndex > 0; usAddrIndex--)
    {
        usItemAddr = (usAddrIndex - 1) * _DATA_ITEM_LENGTH;

        // If data item index matches
        UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usItemAddr, 1, ucDataArry);
        if(ucDataArry[0] == LOBYTE(enumItemID))
        {
            ucItemChecksum = 0;

            // Calculate the checksum of the data item
            UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usItemAddr, _DATA_ITEM_LENGTH, ucDataArry);
            for(ucCnt = 0; ucCnt < (_DATA_ITEM_LENGTH - 1); ucCnt++)
            {
                ucItemChecksum = ucItemChecksum ^ ucDataArry[ucCnt];
            }

            // Check checksum value matches or not
            if(ucDataArry[_DATA_ITEM_LENGTH - 1] != ucItemChecksum)
            {
                return _FALSE;
            }

            // Load the found data item to the buffer
            memcpy(pucData, ucDataArry + 1, ucLength);

            return _TRUE;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Save one iterm to flash
// Input Value  : enumItemID: flash item id
//                pucData: data to save
//                ucLength: buf length
// Output Value : return _TRUE if save success, else return _FALSE
//--------------------------------------------------
bit UserInterfaceFlashSaveItem(EnumFlashItemIDType enumItemID, BYTE* pucData, BYTE ucLength)
{
    bit bNeedSave = _TRUE;
    BYTE ucItemIndex = 0;
    BYTE ucChecksum = 0;
    WORD usAddrIndex = 0;
    WORD usPageAddr = 0;
    WORD usItemAddr = 0;
    BYTE ucDataArry[_DATA_ITEM_LENGTH] = {0};
    BYTE ucWholeItem[_DATA_ITEM_LENGTH]= {0};
    BYTE ucPageID = HIBYTE(enumItemID);

    if(ucLength > (_DATA_ITEM_LENGTH - 2))
    {
        return _FALSE;
    }

    usPageAddr = g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE;

    // Check all saved items
    for(usAddrIndex = g_usFlashAddrArr[ucPageID]; usAddrIndex > 0; usAddrIndex--)
    {
        usItemAddr = (usAddrIndex - 1) * _DATA_ITEM_LENGTH;

        // Check item ID index and item checksum to make sure that this item which has the same ID index is valid
        UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usItemAddr, 1, ucDataArry);
        if(ucDataArry[0] == LOBYTE(enumItemID))
        {
            ucChecksum = 0;

            // Calculate the item checksum
            UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usItemAddr, _DATA_ITEM_LENGTH, ucDataArry);
            for(ucItemIndex = 0; ucItemIndex < (_DATA_ITEM_LENGTH - 1); ucItemIndex++)
            {
                ucChecksum = ucChecksum ^ ucDataArry[ucItemIndex];
            }

            // Compare the calculate checksum and flash data
            if(ucChecksum == ucDataArry[_DATA_ITEM_LENGTH - 1])
            {
                // Check data item in buffer is equal to the existed data item in page or not
                for(ucItemIndex = 0; ucItemIndex < ucLength; ucItemIndex++)
                {
                    if(ucDataArry[ucItemIndex + 1] != pucData[ucItemIndex])
                    {
                        break;
                    }
                }

                // Same item has been saved last time
                if(ucItemIndex >= ucLength)
                {
                    bNeedSave = _FALSE;
                }

                break;
            }
        }
    }

    // Same item is saved last time, do not need save again here    
    if(bNeedSave == _FALSE)
    {
        return _TRUE;
    }

    // Get the whole item
    memset(ucWholeItem, 0xFF, _DATA_ITEM_LENGTH);
    ucWholeItem[0] = LOBYTE(enumItemID);
    memcpy(ucWholeItem + 1, pucData, ucLength);
    ucWholeItem[15] = 0x00;

    for(ucItemIndex = 0; ucItemIndex < 15; ucItemIndex++)
    {
        ucWholeItem[15] ^= ucWholeItem[ucItemIndex];
    }

    // Find an available Item space address which is 0xFF for Item all fields
    // Use this mechanism to avoid save Item to the wrong address which update data exception happens
    for(usAddrIndex = g_usFlashAddrArr[ucPageID]; usAddrIndex <= ((_FLASH_PAGE_SIZE - _PAGE_INFO_LENGTH) / _DATA_ITEM_LENGTH); usAddrIndex++)
    {
        if(usAddrIndex == ((_FLASH_PAGE_SIZE - _PAGE_INFO_LENGTH) / _DATA_ITEM_LENGTH))
        {
            RTDFlashMoveData(ucPageID, ucWholeItem);
            return _TRUE;
        }

        usItemAddr = usAddrIndex * _DATA_ITEM_LENGTH;

        UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usItemAddr, _DATA_ITEM_LENGTH, ucDataArry);
        for(ucItemIndex = 0; ucItemIndex < _DATA_ITEM_LENGTH; ucItemIndex++)
        {
            if((ucDataArry[ucItemIndex]) != 0xFF)
            {
                break;
            }
        }

        if(ucItemIndex >= _DATA_ITEM_LENGTH)
        {
            g_usFlashAddrArr[ucPageID] = usAddrIndex;
            break;
        }
    }

    // Write item data
    UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + g_usFlashAddrArr[ucPageID] * _DATA_ITEM_LENGTH, _DATA_ITEM_LENGTH - 1, ucWholeItem);
    // Write checksum
    UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + g_usFlashAddrArr[ucPageID] * _DATA_ITEM_LENGTH + _DATA_ITEM_LENGTH - 1, 1, ucWholeItem + _DATA_ITEM_LENGTH - 1);

    g_usFlashAddrArr[ucPageID]++;

    return _TRUE;
}
#endif // End of #if(_SYSTEM_EEPROM_EMAULTION_SUPPORT == _ON)

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Get DDC-CI Status for Int1
// Input Value  : ucDataType --> Data Type in StructSystemData
// Output Value : ucValue --> Value of the Input Data Type
//--------------------------------------------------
BYTE UserInterfaceGetDdcciStatus_EXINT1(void) using 2
{
	return GET_OSD_DDCCI_STATUS();
}

//--------------------------------------------------
// Description  : Get Data from DDCCI Buffer defined by user
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceGetFactoryCommand_EXINT1(void) using 2
{
    return _FALSE;
}

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
//--------------------------------------------------
// Description  : Get Source Opcode is HDMI freesync
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1(void) using 2
{
    if(g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE] == _DDCCI_OPCODE_VCP_HDMI_FREESYNC_SUPPORT)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}
#endif // #if(_HDMI_FREESYNC_SUPPORT == _ON)


#endif

//--------------------------------------------------
// Description  : Get whether to by pass normal active process
// Input Value  : None
// Output Value : _TRUE => By pass normal active process
//--------------------------------------------------
bit UserInterfaceGetActiveByPass(void)
{
   
    if(GET_OSD_STATE() != _MENU_NONE)
    {
        return _TRUE;
    }
    
    return _FALSE;
}

//--------------------------------------------------
// Description  : User Check Into Power Saving
// Input Value  : None
// Output Value : True --> User Check Ready to Power Saving
//--------------------------------------------------
bit UserInterfaceCheckIntoPS(void)
{
    if(ScalerOsdGetOsdEnable() == _TRUE)
    { 
        return _FALSE;
    }
    
    return _TRUE;
}

// Description  : Keypad Led Control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed)
{
#if (_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    switch(ucKeyPadLed)
	{        
		case _LED_POWER_ON:
		case _LED_POWER_ACTIVE:
		case _LED_POWER_SEARCH:
		case _LED_POWER_NOSUPPORT:

        if(!GET_EDID_VERSIONCODE_STATUS())
        {
            PCB_LED_TYPE1();          
        }
        else
        {
            if (GET_ATE_COMMAND_STATUS())
            { 
                PCB_LED_ACTIVE();
                ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_LED_FLASH);
            }
            else
            {
                 ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LED_FLASH);
    			 PCB_LED_ACTIVE();
            }
        }
        
        return;
    }
#endif

#if (_FACTORY_MODE_OWNER == _OWNER_TPV)
	if(TPVDFMKeyPadLedCheck(ucKeyPadLed)== _TRUE)
	{
		PCB_LED_IDLE();
        return;
	}
#endif

    switch(ucKeyPadLed)
	{        
		case _LED_POWER_ON:
			PCB_LED_ON();
            break;

        case _LED_POWER_ACTIVE:
            PCB_LED_ACTIVE();
            break;
			
        case _LED_POWER_SEARCH:
			//PCB_LED_IDLE();
			PCB_LED_ON();
            break;
			
		case _LED_POWER_SAVING:
            PCB_LED_POWER_SAVING();
            break;
			
		case _LED_POWER_NOSUPPORT:
            PCB_LED_ACTIVE();
            break;

		case _LED_POWER_NOSUPPORT_SAVING:
            PCB_LED_POWER_SAVING();
            break;
			
		case _LED_POWER_OFF:
            PCB_LED_OFF();
            break;
		
		case _LED_ALL_OFF:
            PCB_LED_OFF();
            break;
			
		case _LED_TYPE_1:
            PCB_LED_TYPE1();
            break;
            
		case _LED_TYPE_2:
            PCB_LED_TYPE2();
            break;
            
		case _LED_TYPE_3:
            PCB_LED_TYPE3();
            break;
            
		case _LED_TYPE_4:
            PCB_LED_TYPE4();
            break;
            
		case _LED_TYPE_5:
            PCB_LED_TYPE5();
            break;
            
		case _LED_TYPE_FLASH:
            PCB_LED_TYPE_FLASH();
            break;            

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Check Whther ADC Data is Reasonable
// Input Value  : LOAD or SAVE
// Output Value : _TRUE => Reasonable
//--------------------------------------------------
bit UserInterfaceCheckNVRamData(EnumADCCheckType enumType)
{
#if((_FACTORY_MODE_OWNER == _OWNER_WISTRON) || (_FACTORY_MODE_OWNER == _OWNER_TPV))
    BYTE ucTemp = 0;
    BYTE ucColorTempType = 0;
    
    ucColorTempType = (enumType&0xF0)>>4;
    enumType &= 0x0F;
#endif

    switch(enumType)
    {
#if(_VGA_SUPPORT == _ON)
        case _CHECK_ADC_LOAD:

#if(_FACTORY_MODE_OWNER == _OWNER_TPV)//Robert Wang 20131205

				if((g_stAdcData.ucAdcGainMSB[0]<50)||(g_stAdcData.ucAdcGainMSB[0]>200)||(g_stAdcData.ucAdcGainMSB[1]<50)||(g_stAdcData.ucAdcGainMSB[1]>200)\
				||(g_stAdcData.ucAdcGainMSB[2]<50)||(g_stAdcData.ucAdcGainMSB[2]>200)||(g_stAdcData.ucAdcPGA>12))
				{
					g_stAdcData.ucAdcGainMSB[0]= _ADC_RGB_DEFAULT_RED_GAIN;
					g_stAdcData.ucAdcGainMSB[1]= _ADC_RGB_DEFAULT_GREEN_GAIN;
					g_stAdcData.ucAdcGainMSB[2]= _ADC_RGB_DEFAULT_BLUE_GAIN;
					g_stAdcData.ucAdcPGA= _ADC_RGB_DEFAULT_PGA_VALUE;
				}
				if((g_stAdcData.ucAdcGainLSB[0]!=0)||(g_stAdcData.ucAdcGainLSB[1]!=0)||(g_stAdcData.ucAdcGainLSB[2]!=0))
				{
					g_stAdcData.ucAdcGainLSB[0]=g_stAdcData.ucAdcGainLSB[1]=g_stAdcData.ucAdcGainLSB[2]= 0x00;
				}

				if((g_stAdcData.ucAdcOffsetMSB[0]<50)||(g_stAdcData.ucAdcOffsetMSB[0]>200)||(g_stAdcData.ucAdcOffsetMSB[1]<50)||(g_stAdcData.ucAdcOffsetMSB[1]>200)\
				||(g_stAdcData.ucAdcOffsetMSB[2]<50)||(g_stAdcData.ucAdcOffsetMSB[2]>200))
				{
					g_stAdcData.ucAdcOffsetMSB[0]= _ADC_RGB_DEFAULT_RED_OFFSET;
					g_stAdcData.ucAdcOffsetMSB[1]= _ADC_RGB_DEFAULT_GREEN_OFFSET;
					g_stAdcData.ucAdcOffsetMSB[2]= _ADC_RGB_DEFAULT_BLUE_OFFSET;
				}
				if((g_stAdcData.ucAdcOffsetLSB[0]!=0)||(g_stAdcData.ucAdcOffsetLSB[1]!=0)||(g_stAdcData.ucAdcOffsetLSB[2]!=0))
				{
					g_stAdcData.ucAdcOffsetLSB[0]=g_stAdcData.ucAdcOffsetLSB[1]=g_stAdcData.ucAdcOffsetLSB[2]= 0x00;
				}

#else
				if(g_stAdcData.ucAdcPGA >= 0xF0)
				{
					// Assign Prefered Value
					g_stAdcData.ucAdcPGA = 8;
				}
#endif            
            
#if(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
            for(ucTemp=0; ucTemp<3; ucTemp++)
            {
                if((g_stAdcData.ucAdcGainMSB[ucTemp]<30)||(g_stAdcData.ucAdcGainMSB[ucTemp]>200))
                    g_stAdcData.ucAdcGainMSB[ucTemp] = 0x80;

                if((g_stAdcData.ucAdcOffsetMSB[ucTemp]<30)||(g_stAdcData.ucAdcOffsetMSB[ucTemp]>200))
                    g_stAdcData.ucAdcOffsetMSB[ucTemp] = 0x80;
            }
#endif
            break;
            
        case _CHECK_ADC_SAVE:

            if(g_stAdcData.ucAdcPGA >= 0xF0)
            {
                return _FAIL;
            }
            break;
#endif

        case _CHECK_SYSTEM_DATA_LOAD:
        case _CHECK_SYSTEM_DATA_SAVE:
        case _CHECK_MODE_USER_DATA_LOAD:
        case _CHECK_MODE_USER_DATA_SAVE:

            break;

#if(_FACTORY_MODE_OWNER == _OWNER_TPV) //ada.chen 20150807

		case _CHECK_OSD_DATA_LOAD:
			if(GET_OSD_BACKLIGHT()> 100)
				SET_OSD_BACKLIGHT(_OSD_BRIGHTNESS_DEF_VALUE);
			
			if(GET_OSD_HPOS()> _OSD_H_POS_MAX)
				SET_OSD_HPOS(50);
			
			if(GET_OSD_VPOS()> _OSD_V_POS_MAX)
				SET_OSD_VPOS(50);
			
			if((GET_OSD_TIME_OUT()< _OSD_TIMEOUT_ADJUST_MIN) || (GET_OSD_TIME_OUT()> _OSD_TIMEOUT_ADJUST_MAX))
				SET_OSD_TIME_OUT(5);
			
			if(GET_OSD_LANGUAGE()> _LANGUAGE_AMOUNT)
			{
				SET_OSD_LANGUAGE(_LANGUAGE_DEFAULT);
				SET_OSD_ROTATE_STATUS(_OFF);
				SET_OSD_LOCK_STATUS(_OFF);
				SET_OSD_DCR_STATUS(_OFF);
				SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_FULL);
#if(_OVERSCAN_SUPPORT == _ON)
				SET_OSD_OVERSCAN_STATUS(_OFF);
#endif
				SET_OSD_COLOR_EFFECT(_COLOREFFECT_STANDARD) ;				 
			}
			
			if(GET_COLOR_TEMP_TYPE()> _CT_COLORTEMP_AMOUNT)
			{
				SET_COLOR_TEMP_TYPE(_COLOR_TEMP_DEF);
				SET_VGA_COLOR_FORMAT_STATUS(_COLOR_SPACE_RGB);				  
				SET_DVI_COLOR_FORMAT_STATUS(_COLOR_SPACE_RGB);				  
			}
			
			if(GET_OSD_SHARPNESS()> _SHARPNESS_MAX)
				SET_OSD_SHARPNESS(4);
			
			if(GET_OSD_HUE()> 200)
				SET_OSD_HUE(_DEFAULT_HUE);
			
			if(GET_OSD_SATURATION()> 200)
				SET_OSD_SATURATION(_DEFAULT_SATURATION);
			break;

		case _CHECK_BRICON_DATA_LOAD:
			if(GET_OSD_BRIGHTNESS()> 0xA0)
				SET_OSD_BRIGHTNESS(0x80);
			
			if(GET_OSD_CONTRAST()> 100)
				SET_OSD_CONTRAST(_OSD_CONTRAST_DEF_VALUE);
			break;

		case _CHECK_COLORTEMP_DATA_LOAD:

			if(ucColorTempType> _CT_COLORTEMP_AMOUNT)
			{
				SET_COLOR_TEMP_TYPE(_COLOR_TEMP_DEF);
				ucColorTempType = _COLOR_TEMP_DEF;
			}
/*
			if(ucColorTempType==_CT_USER)
			{
				if((g_stColorProcData.ucColorTempR< 28) || (g_stColorProcData.ucColorTempR> 128))
				
				{
						g_stColorProcData.ucColorTempR = _CTUSER_LenovoPrj_RED;
				}

				if((g_stColorProcData.ucColorTempG< 28) || (g_stColorProcData.ucColorTempG> 128))
				{
						g_stColorProcData.ucColorTempG = _CTUSER_LenovoPrj_GREEN;
				}

				if((g_stColorProcData.ucColorTempB< 28) || (g_stColorProcData.ucColorTempB> 128))
				{
						g_stColorProcData.ucColorTempB = _CTUSER_LenovoPrj_BLUE;
				}

			}
			else
			{

				if((g_stColorProcData.ucColorTempR< 50) || (g_stColorProcData.ucColorTempR> 150))
				
				{
					if(ucColorTempType==_CT_7200)
						g_stColorProcData.ucColorTempR = _CT7200_LenovoPrj_RED;
					else if(ucColorTempType==_CT_SRGB)
						g_stColorProcData.ucColorTempR = _CTSRGB_LenovoPrj_RED;
					else if(ucColorTempType==_CT_6500)
						g_stColorProcData.ucColorTempR = _CT6500_LenovoPrj_RED;
					else if(ucColorTempType==_CT_9300)
						g_stColorProcData.ucColorTempR = _CT9300_LenovoPrj_RED;
				}
				
				if((g_stColorProcData.ucColorTempG< 50) || (g_stColorProcData.ucColorTempG> 150))
				{
					if(ucColorTempType==_CT_7200)
						g_stColorProcData.ucColorTempG = _CT7200_LenovoPrj_GREEN;
					else if(ucColorTempType==_CT_SRGB)
						g_stColorProcData.ucColorTempG = _CTSRGB_LenovoPrj_GREEN;
					else if(ucColorTempType==_CT_6500)
						g_stColorProcData.ucColorTempG = _CT6500_LenovoPrj_GREEN;
					else if(ucColorTempType==_CT_9300)
						g_stColorProcData.ucColorTempG = _CT9300_LenovoPrj_GREEN;
				}
				
				if((g_stColorProcData.ucColorTempB< 50) || (g_stColorProcData.ucColorTempB> 150))
				{
					if(ucColorTempType==_CT_7200)
						g_stColorProcData.ucColorTempB = _CT7200_LenovoPrj_BLUE;
					else if(ucColorTempType==_CT_SRGB)
						g_stColorProcData.ucColorTempB = _CTSRGB_LenovoPrj_BLUE;
					else if(ucColorTempType==_CT_6500)
						g_stColorProcData.ucColorTempB = _CT6500_LenovoPrj_BLUE;
					else if(ucColorTempType==_CT_9300)
						g_stColorProcData.ucColorTempB = _CT9300_LenovoPrj_BLUE;
				}

			}
			*/
			break;

#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON)            

        case _CHECK_OSD_DATA_SAVE:
        case _CHECK_OSD_DATA_LOAD:
            if(GET_OSD_BACKLIGHT()> 100)
                SET_OSD_BACKLIGHT(_OSD_BRIGHTNESS_DEF_VALUE);
            
            if(GET_OSD_HPOS()> 100)
                SET_OSD_HPOS(50);
            
            if(GET_OSD_VPOS()> 100)
                SET_OSD_VPOS(50);
            
            if((GET_OSD_TIME_OUT()< 5) || (GET_OSD_TIME_OUT()> 60))
                SET_OSD_TIME_OUT(5);
            
            if(GET_OSD_LANGUAGE()> _LANGUAGE_AMOUNT)
            {
                SET_OSD_LANGUAGE(_LANGUAGE_DEFAULT);
                SET_OSD_ROTATE_STATUS(_OFF);
                SET_OSD_LOCK_STATUS(_OFF);
                SET_OSD_DCR_STATUS(_OFF);
        		SET_OSD_ASPECT_RATIO_TYPE(_ASPECT_RATIO_FULL);
                SET_OSD_OVERSCAN_STATUS(_OFF);
                SET_OSD_COLOR_EFFECT(_COLOREFFECT_STANDARD) ;                
            }
            
            if(GET_COLOR_TEMP_TYPE()> _CT_COLORTEMP_AMOUNT)
            {
                SET_COLOR_TEMP_TYPE(_CT_7200);
                SET_VGA_COLOR_FORMAT_STATUS(_COLOR_SPACE_RGB);                
                SET_DVI_COLOR_FORMAT_STATUS(_COLOR_SPACE_RGB);                
            }
            
            if(GET_OSD_SHARPNESS()> 4)
                SET_OSD_SHARPNESS(4);
            
            if(GET_OSD_HUE()> 200)
                SET_OSD_HUE(_DEFAULT_HUE);
            
            if(GET_OSD_SATURATION()> 200)
                SET_OSD_SATURATION(_DEFAULT_SATURATION);
            break;

        case _CHECK_BRICON_DATA_SAVE:
        case _CHECK_BRICON_DATA_LOAD:
            if(GET_OSD_BRIGHTNESS()> 0xA0)
                SET_OSD_BRIGHTNESS(0x80);
            
            if(GET_OSD_CONTRAST()> 100)
                SET_OSD_CONTRAST(_OSD_CONTRAST_DEF_VALUE);
            break;

        case _CHECK_COLORTEMP_DATA_SAVE:
        case _CHECK_COLORTEMP_DATA_LOAD:

            if(ucColorTempType> _CT_COLORTEMP_AMOUNT)
            {
                SET_COLOR_TEMP_TYPE(_CT_7200);
                ucColorTempType = _CT_7200;
            }
/*
            if((g_stColorProcData.ucColorTempR< 50) || (g_stColorProcData.ucColorTempR> 100))
            {
                if(ucColorTempType==_CT_7200)
                    g_stColorProcData.ucColorTempR = _CT7200_LenovoPrj_RED;
                else if(ucColorTempType==_CT_SRGB)
                    g_stColorProcData.ucColorTempR = _CTSRGB_LenovoPrj_RED;
                else if(ucColorTempType==_CT_6500)
                    g_stColorProcData.ucColorTempR = _CT6500_LenovoPrj_RED;
                else if(ucColorTempType==_CT_9300)
                    g_stColorProcData.ucColorTempR = _CT9300_LenovoPrj_RED;
                else if((ucColorTempType==_CT_USER)&&(g_stColorProcData.ucColorTempR> 100))
                    g_stColorProcData.ucColorTempR = _CTUSER_LenovoPrj_RED;
            }

            if((g_stColorProcData.ucColorTempG< 50) || (g_stColorProcData.ucColorTempG> 100))
            {
                if(ucColorTempType==_CT_7200)
                    g_stColorProcData.ucColorTempG = _CT7200_LenovoPrj_GREEN;
                else if(ucColorTempType==_CT_SRGB)
                    g_stColorProcData.ucColorTempG = _CTSRGB_LenovoPrj_GREEN;
                else if(ucColorTempType==_CT_6500)
                    g_stColorProcData.ucColorTempG = _CT6500_LenovoPrj_GREEN;
                else if(ucColorTempType==_CT_9300)
                    g_stColorProcData.ucColorTempG = _CT9300_LenovoPrj_GREEN;
                else if((ucColorTempType==_CT_USER)&&(g_stColorProcData.ucColorTempG> 100))
                    g_stColorProcData.ucColorTempG = _CTUSER_LenovoPrj_GREEN;
            }

            if((g_stColorProcData.ucColorTempB< 50) || (g_stColorProcData.ucColorTempB> 100))
            {
                if(ucColorTempType==_CT_7200)
                    g_stColorProcData.ucColorTempB = _CT7200_LenovoPrj_BLUE;
                else if(ucColorTempType==_CT_SRGB)
                    g_stColorProcData.ucColorTempB = _CTSRGB_LenovoPrj_BLUE;
                else if(ucColorTempType==_CT_6500)
                    g_stColorProcData.ucColorTempB = _CT6500_LenovoPrj_BLUE;
                else if(ucColorTempType==_CT_9300)
                    g_stColorProcData.ucColorTempB = _CT9300_LenovoPrj_BLUE;
                else if((ucColorTempType==_CT_USER)&&(g_stColorProcData.ucColorTempB> 100))
                    g_stColorProcData.ucColorTempB = _CTUSER_LenovoPrj_BLUE;
            }
*/            
            break;
#endif

        default:
            break;
    }

    return _SUCCESS;
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check ModeIndex
// Input Value  : System ModeIndex
// Output Value : ModeIndex
//--------------------------------------------------
BYTE UserInterfaceCheckVGAModeSearch(BYTE ucModeIndex)
{
    if((ucModeIndex == _MODE_640x480_60HZ) || (ucModeIndex == _MODE_720x480_60HZ_GTF) || (ucModeIndex == _MODE_720x480p_60HZ)) 
    {
        if(GET_INPUT_TIMING_VSYNCWIDTH() <= 4)
        {
            ucModeIndex = _MODE_640x480_60HZ;

            DebugMessageAnalog("Detected by Special Case to 640x480-60", _MODE_640x480_60HZ);
        }
        else if((GET_INPUT_TIMING_H_POLARITY() == _FALSE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
        {
            ucModeIndex = _MODE_720x480_60HZ_GTF;

            DebugMessageAnalog("Detected by Special Case to 720x480-60_GTF", _MODE_720x480_60HZ_GTF);
        }
        else
        {
            ucModeIndex = _MODE_720x480p_60HZ;

            DebugMessageAnalog("Detected by Special Case to 720x480-60", _MODE_720x480p_60HZ);
        }
    }

    if((ucModeIndex == _MODE_720x400_70HZ) || (ucModeIndex == _MODE_640x400_70HZ))
    {
        if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
        {
            ucModeIndex = _MODE_640x350_70HZ;

            DebugMessageAnalog("Detected by Special Case to _MODE_640x350_70HZ", _MODE_640x350_70HZ);
        }
    }
    
    if((ucModeIndex == _MODE_640x400_85HZ) || (ucModeIndex == _MODE_720x400_85HZ))
    {
        if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
        {
            ucModeIndex = _MODE_640x350_85HZ;
        }

        DebugMessageAnalog("Detected by Special Case to _MODE_640x350_85HZ", _MODE_640x350_85HZ);
    }
   
    return ucModeIndex;
}

//--------------------------------------------------
// Description  : Check Load Mode Table Value
// Input Value  : None
// Output Value : _TURE -> Force Load Mode Table Value
//--------------------------------------------------
bit UserInterfaceLoadModeTableDefault(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : Check VGA First Auto Config
// Input Value  : None
// Output Value : _TRUE => Do Auto Config
//--------------------------------------------------
bit UserInterfaceFirstAutoConfig(void)
{
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)//DFM
	if (TPVDFMAutoConfigByPass()==_TRUE)
		return _FALSE;
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502
	if(GET_FACTORY_MODE()==_ON)
		return _FALSE;
#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON)
    if(GET_ATE_COMMAND_STATUS()||GET_FACTORY_MODE())
		return _FALSE;
#endif
#if(_FACTORY_MODE_OWNER==_OWNER_WISTRON)
    if(GET_VGA_MODE_DO_FIRST_AUTO())
#else
    if(GET_VGA_MODE_DO_FIRST_AUTO() && (GET_INPUT_TIMING_HWIDTH() > 720))
#endif
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Percentage of AutoConfig
// Input Value  : Percentage
// Output Value : None
//--------------------------------------------------
void UserInterfaceAutoConfigPercentage(BYTE ucAutoPercentage)
{
    ucAutoPercentage = ucAutoPercentage;
}

#if(_YPBPR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get color rimetry
// Input Value  : ucModeNumber --> Target Mode Number
// Output Value : _TRUE --> current mode is HD TV Mode
//--------------------------------------------------
bit UserInterfaceCheckHDTVMode(BYTE ucModeNumber)
{
    switch(ucModeNumber)
    {
        case _MODE_720x480p_60HZ:           
        case _MODE_1440x480i_60HZ:    
        case _MODE_720x576p_50HZ:         
        case _MODE_1440x576i_50HZ:           

            return _FALSE;

        case _MODE_1280x720p_60HZ:
        case _MODE_1920x1080i_50HZ:
        case _MODE_1920x1080i_60HZ:
        case _MODE_1920x1080p_50HZ:
        case _MODE_1920x1080p_60HZ:
        case _MODE_1920x1080i_50HZ_2:
        case _MODE_1280x720p_50HZ:

            return _TRUE;  

        default:

            return _FALSE;
    }
}
#endif // End of #if(_YPBPR_SUPPORT == _ON)
#endif // End of #if(_VGA_SUPPORT == _ON)

#if(_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Determine whether to User is Ready to play audio
// Input Value  : None
// Output Value : _TRUE => Free to Play
//--------------------------------------------------
bit UserInterfaceGetAudioReadyToPlay(void)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(UserInterfaceGetAudioMute() != _ON)
    {
        
#if(_SLEEP_AUDIO_SUPPORT == _ON)
        if(UserInterfaceGetAudioStandAlone() == _TRUE)
        {
            if(UserInterfaceGetAudioSource() == _ANALOG_AUDIO)
            {
                if((ScalerAudioDACGetState() == _AUDIO_DAC_READY) && (UserInterfaceGetAudioVolume() > 0))
                {
#if((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN))
                    return _TRUE;
#else
                    if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
                    {
                        return _TRUE;
                    }
#endif
                }
            }
            else
            {
                if((ScalerAudioDACGetState() == _AUDIO_DAC_READY) && (ScalerAudioGetAudioDetected() == _TRUE))
                {              

#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
                    if(ScalerAudioGetDigitalAudioSource() == _DIGITAL_AUDIO_SOURCE_DP)
                    {
                        // When Fixed Port, should not play DP Audio at different port
                        if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetAudioPlaybackPort() == SysSourceGetInputPort()))
                        {
                            return _TRUE;
                        }               
                    }
#endif           
                    if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
                    {
                        return _TRUE;
                    }
                }
            }
        }
        else
#endif  // End of #if(_SLEEP_AUDIO_SUPPORT == _ON)
        {
            if(UserInterfaceGetAudioSource() == _ANALOG_AUDIO)
            {
                if((ScalerAudioDACGetState() == _AUDIO_DAC_READY) && (SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (UserInterfaceGetAudioVolume() > 0))
                {
                    return _TRUE;
                }
            }
            else
            {
                if((ScalerAudioDACGetState() == _AUDIO_DAC_READY) && (ScalerAudioGetAudioDetected() == _TRUE) && (SysModeGetModeState() == _MODE_STATUS_ACTIVE))
                {
                    return _TRUE;
                }            
            }
        }
    }

    // Don't Change Audio Playback Status if Reset to Display Setting
    if((SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK) && (SysModeGetModeState() == _MODE_STATUS_DISPLAY_SETTING))
    {
        return _TRUE;
    }
    
    return _FALSE;
    
#else // Else of #if(_EMBEDDED_DAC_SUPPORT == _ON)

    if(UserInterfaceGetAudioMute() != _ON)
    {
        
#if(_SLEEP_AUDIO_SUPPORT == _ON)
        if(UserInterfaceGetAudioStandAlone() == _TRUE)
        {
            if(ScalerAudioGetAudioDetected() == _TRUE)
            {              

#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
                if((ScalerAudioGetDigitalAudioSource() == _DIGITAL_AUDIO_SOURCE_DP) && (SysSourceGetScanType() == _SOURCE_SWITCH_FIXED_PORT))
                {
                    return _TRUE;
                }
#endif           
                if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
                {
                    return _TRUE;
                }
            }
        }
        else
#endif  // End of #if(_SLEEP_AUDIO_SUPPORT == _ON)
        {
            if((ScalerAudioGetAudioDetected() == _TRUE) && (SysModeGetModeState() == _MODE_STATUS_ACTIVE))
            {
                return _TRUE;
            }            
        }
    }

    // Don't Change Audio Playback Status if Reset to Display Setting
    if((SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK) && (SysModeGetModeState() == _MODE_STATUS_DISPLAY_SETTING))
    {
        return _TRUE;
    }
    
    return _FALSE;
    
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
}

//--------------------------------------------------
// Description  : Get Current Audio Mute Status
// Input Value  : Node
// Output Value : Node
//--------------------------------------------------
bit UserInterfaceGetAudioMute(void)
{
    return GET_OSD_VOLUME_MUTE();
}

//--------------------------------------------------
// Description  : Get Current Audio Volume
// Input Value  : None
// Output Value : Current Volume
//--------------------------------------------------
WORD UserInterfaceGetAudioVolume(void)
{
    return UserAdjustAudioVolumeMapping(GET_OSD_VOLUME());
}

//--------------------------------------------------
// Description  : User OSD Get Audio Source
// Input Value  : None
// Output Value : _DIGITAL_AUDIO or _ANALOG_AUDIO
//--------------------------------------------------
bit UserInterfaceGetAudioSource(void)
{
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)        
    if(ScalerAudioGetInternalAudioGenEnable() == _ENABLE)
    {
        return _DIGITAL_AUDIO;
    }
#endif

#if(_EMBEDDED_DAC_SUPPORT == _ON)
    switch(SysSourceGetInputPort())
    {
        case _A0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
        case _D0_INPUT_PORT:
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
        case _D1_INPUT_PORT:
#endif
            
#if(_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)
        case _D2_INPUT_PORT:
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)
        case _D3_INPUT_PORT:
#endif

#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH)  || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
            if(UserInterfaceGetAudioStandAlone() == _FALSE)
#endif
            {
                // Don't switch audio source if input source is not found
                if(SysSourceGetSourceType() == _SOURCE_NONE)
                {
                    return ScalerAudioDACGetInputSource();
                }
            }

            return _ANALOG_AUDIO;

        default:

#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH)  || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
            // Don't Switch Audio Source if Line In is Currently Playing unless Digital Source is found
            if(UserInterfaceGetAudioStandAlone() == _TRUE)
            {
                if((SysSourceGetSourceType() == _SOURCE_NONE) && (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK) && (ScalerAudioDACGetInputSource() == _ANALOG_AUDIO))
                {
                    return _ANALOG_AUDIO;
                }
            }
#endif
            return GET_OSD_AUDIO_SOURCE();                    

            break;

    }

#else

    return GET_OSD_AUDIO_SOURCE();            

#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
}

//--------------------------------------------------
// Description  : User Audio Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAudioResetProc(void)
{
#if(_SLEEP_AUDIO_SUPPORT == _ON)
    if(UserInterfaceGetAudioStandAlone() == _TRUE)
    {
        // if Currently playing digital audio
        if((SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK) && (UserInterfaceGetAudioSource() == _DIGITAL_AUDIO))            
        {
            if(SysSourceGetAudioPlaybackPort() != SysSourceGetInputPort())
            {
                DebugMessageAudio("User Audio Reset Process", 0x00);

                UserInterfaceAudioAmpMuteProc(_ON);
                
                // Mute both Analog and Digital Audio
                ScalerAudioDigitalVolumeMute(_ON, UserInterfaceGetAudioVolume());        

#if(_EMBEDDED_DAC_SUPPORT == _ON)                
                ScalerAudioAnalogVolumeMute(_ON, (BYTE)UserInterfaceGetAudioVolume());        
#endif
            }
        }
    }
    else
#endif     
    {      
        if(SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK)
        {            
            DebugMessageAudio("User Audio Reset Process", 0x00);

            UserInterfaceAudioAmpMuteProc(_ON);
            
            // Mute both Analog and Digital Audio
            ScalerAudioDigitalVolumeMute(_ON, UserInterfaceGetAudioVolume());        

#if(_EMBEDDED_DAC_SUPPORT == _ON)            
            ScalerAudioAnalogVolumeMute(_ON, (BYTE)UserInterfaceGetAudioVolume());        
#endif
        }
    }
}

//--------------------------------------------------
// Description  : User Decide whether to play non-LPCM Audio
// Input Value  : None
// Output Value : _ON => Mute Audio
//--------------------------------------------------
bit UserInterfaceDecideAudioNonLPCMMute(void)
{
    if(ScalerAudioLPCMCheckData() == _TRUE)
    {
#if(_HDMI_SUPPORT == _ON)        
        if(ScalerAudioGetDigitalAudioSource() == _DIGITAL_AUDIO_SOURCE_HDMI)
        {
            if(ScalerAudioLPCMCheckInfo() == _TRUE)
            {
                return _OFF;
            }
            else
            {
                return _ON;
            }
        }
#endif        

        return _OFF;
    }

    return _ON;
}

//--------------------------------------------------
// Description  : Audio Power Process
// Input Value  : enumPowStatus
// Output Value : Node
//--------------------------------------------------
void UserInterfaceAudioPowerProc(EnumPowerStatus enumPowStatus)
{   
    if(enumPowStatus == _POWER_STATUS_NORMAL)
    {
        // Add User interface function
      
    }
    else if(enumPowStatus == _POWER_STATUS_SAVING)
    {
        // Add User interface function
    }
    else        
    {    
        // Add User interface function
    }   
}

//--------------------------------------------------
// Description  : Control User Audio Mute Process
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void UserInterfaceAudioAmpMuteProc(bit bMute)
{
    bMute = bMute;
    
#if(_EMBEDDED_DAC_SUPPORT == _ON)    
    if(UserInterfaceGetAudioDACOutput() == _AUDIO_DAC_OUTPUT_BOTH) 
    {
        PCB_AMP_MUTE(bMute);
    }
#endif
}

#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DAC Output Switch
// Input Value  : None
// Output Value : EnumAudioDACOutput
//--------------------------------------------------
EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void)
{
    return _AUDIO_DAC_OUTPUT_BOTH;
}
#endif

//--------------------------------------------------
// Description  : Get Current Audio Stand Alone Status
// Input Value  : enumPowStatus
// Output Value : Node
//--------------------------------------------------
#if(_SLEEP_AUDIO_SUPPORT == _ON)
bit UserInterfaceGetAudioStandAlone(void)
{
    return GET_OSD_AUDIO_STAND_ALONE();
}
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

//--------------------------------------------------
// Description  : User Define Whether Cable Status Should Reset
// Input Value  : None
// Output Value : _TRUE => Reset
//--------------------------------------------------
bit UserInterfaceCheckCableReset(void)
{
#if 1//Robert Wang 20130220

    if((SysSourceGetCableStatusChange(_A0_INPUT_PORT) == _TRUE)
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)            
    || (SysSourceGetCableStatusChange(_D0_INPUT_PORT) == _TRUE)
#endif    
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)    
    || (SysSourceGetCableStatusChange(_D1_INPUT_PORT) == _TRUE)
#endif    
    )
    {
        SET_FORCE_POW_SAV_STATUS(_FALSE);    
        if(SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT)
        {
            if((SysSourceGetCableDetect(_A0_INPUT_PORT) == _TRUE) && (SysSourceGetCableStatusChange(_A0_INPUT_PORT) == _TRUE))
            {
                SysSourceSwitchInputPort(_A0_INPUT_PORT);   
            }
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)    
            else if((SysSourceGetCableDetect(_D0_INPUT_PORT) == _TRUE) && (SysSourceGetCableStatusChange(_D0_INPUT_PORT) == _TRUE))
            {
                SysSourceSwitchInputPort(_D0_INPUT_PORT);   
            }
#endif    
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            else if((SysSourceGetCableDetect(_D1_INPUT_PORT) == _TRUE) && (SysSourceGetCableStatusChange(_D1_INPUT_PORT) == _TRUE))
            {
                SysSourceSwitchInputPort(_D1_INPUT_PORT);   
            }
#endif    
            else
            {
                SysSourceSwitchInputPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));
            } 
        }
        return _TRUE;
    }
    return _FALSE;
    
#else    

	if((SysSourceGetCableStatusChange(UserCommonNVRamGetSystemData(_SEARCH_PORT)) == _TRUE) &&
		((!(SysModeGetModeState() == _MODE_STATUS_SEARCH)) || (SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)) == _TRUE)))
    {
        SET_FORCE_POW_SAV_STATUS(_FALSE);
            
        if(SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT)
        {
            SysSourceSwitchInputPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));
        }
            
        return _TRUE;
    }
    
    return _FALSE;
    
#endif    
}


//--------------------------------------------------
// Description  : Uncall Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceUncallFunction(void)
{
    bit bUncall = _FALSE;

    if(bUncall)
    {
#if(_VGA_SUPPORT == _ON)        
        ScalerSyncVgaGetSyncPad();
#endif

#if(_OD_SUPPORT == _ON)
        ScalerODGetEnable();
        ScalerODGetDeltaGain();
#endif

#if(_EMBEDDED_DAC_SUPPORT == _ON)
        UserAdjustAudioSource();
        UserAdjustAudioMuteSwitch();
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
        ScalerSyncHdcpCheckEnabled(0);
#else//Robert Wang 20140429
#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _ON)
        UserCommonFlashErasePage(0, 0);
        UserCommonFlashWrite(0, 0, 0, 0);
        UserCommonFlashRead(0, 0, 0, 0);
#endif
#endif

        ScalerDDomainPatternGenAdjustColor(0,0,0);
    }
}

//--------------------------------------------------
// Description  : Get Forced Power Saving Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetForcePowSavStatus(void)
{
    return (GET_FORCE_POW_SAV_STATUS());
}

//--------------------------------------------------
// Description  : For User to Check Whether to Support Current DCLK
// Input Value  : None
// Output Value : _TRUE => No Support
//--------------------------------------------------
bit UserInterfaceDClkNoSupportCheck(void)
{
    if((GET_D_CLK_FREQ() > ((DWORD)_PANEL_PIXEL_CLOCK_MAX * 1000)) || (GET_D_CLK_FREQ() < ((DWORD)_PANEL_PIXEL_CLOCK_MIN * 1000)))
    {
        DebugMessageScaler("D Clock Exceed Panel Supported Range", GET_D_CLK_FREQ());
        return _TRUE;
    }
#if(OOR_DCLK_CHECK == _ON) //lorimiao 20150122
#if(_FRC_SUPPORT == _OFF) 
        //20141217 Abel123
        if(GET_DVTotal_OverSpec_FLAG() == _TRUE ) //OOR Flag  
        {
            DebugMessageScaler("DVTotal Over Spec", GET_DVTotal_OverSpec_FLAG());
            return _TRUE;
        }
#endif
#endif    
    return _FALSE;
}

#if(_ENERGY_STAR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get OSD Backlight Value
// Input Value  : None
// Output Value : Backlight Value
//--------------------------------------------------
BYTE UserInterfaceGetOSDBackightValue(void)
{
#if(_LENOVO_DPS_SUPPORT == _ON)
    BYTE ucValue;
    
	if(GET_OSD_BACKLIGHT() > _OSD_BRIGHTNESS_DEF_VALUE)
		ucValue = (WORD)((100 - GET_OSD_SUBBRIHTNESS()) * (GET_OSD_BACKLIGHT() - _OSD_BRIGHTNESS_DEF_VALUE)) / (100 - _OSD_BRIGHTNESS_DEF_VALUE) + GET_OSD_SUBBRIHTNESS();
	else
		ucValue = (WORD)(GET_OSD_SUBBRIHTNESS() * GET_OSD_BACKLIGHT()) / _OSD_BRIGHTNESS_DEF_VALUE;

     ucValue = UserCommonAdjustPercentToRealValue(ucValue, _BACKLIGHT_PWM_MAX, _BACKLIGHT_PWM_MIN,_BACKLIGHT_PWM_CENTER);

    return (ucValue);
    
#else
    return (GET_OSD_BACKLIGHT());
#endif
}
#endif

#if(_MHL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User RCP Handler
// Input Value  : RCP Key Code
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceMHLMscRCPProc(BYTE ucKeyCode)
{
    // Check RCP Key Code
    switch(ucKeyCode)
    {

#if(_AUDIO_SUPPORT == _ON)
        case _MHL_RCP_VOLUME_UP:

            if(GET_OSD_VOLUME() < 100)
            {
                SET_OSD_VOLUME(GET_OSD_VOLUME() + 1);
            }

            if(UserInterfaceGetAudioReadyToPlay() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;

        case _MHL_RCP_VOLUME_DOWN:

            if(GET_OSD_VOLUME() > 0)
            {
                SET_OSD_VOLUME(GET_OSD_VOLUME() - 1);
            }

            if(UserInterfaceGetAudioReadyToPlay() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;

        case _MHL_RCP_MUTE:
        case _MHL_RCP_MUTE_FUNCTION:
            
            SET_OSD_VOLUME_MUTE(!GET_OSD_VOLUME_MUTE());
            
            if(UserInterfaceGetAudioReadyToPlay() == _TRUE)
            {
                UserAdjustAudioMuteSwitch();
            }
            break;

        case _MHL_RCP_RESTORE_VOLUME_FUNCTION:

            SET_OSD_VOLUME(50);

            if(UserInterfaceGetAudioReadyToPlay() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;
#endif

        default:
            return _FALSE;
            break;
    }

    return _TRUE;
}
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Judge if RGB Quantization Range is Full or Limited
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceJudgeRGBQuantizationLimitRange(void)
{
    BYTE ucTemp = 0;

    ucTemp = ScalerColorGetRGBQuantizationRange();

    switch(ucTemp)
    {
        case _RGB_QUANTIZATION_FULL_RANGE:
        case _RGB_QUANTIZATION_DEFAULT_RANGE:
        case _RGB_QUANTIZATION_RESERVED:
            return _FALSE;
            break;

        case _RGB_QUANTIZATION_LIMIT_RANGE:
            return _TRUE;
            break;
    }
}
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Judge if YCC Quantization Range is Full or Limited
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceJudgeYCCQuantizationFullRange(void)
{
    return (ScalerColorGetYCCQuantizationRange() == _YCC_QUANTIZATION_FULL_RANGE);
}
#endif

#endif
