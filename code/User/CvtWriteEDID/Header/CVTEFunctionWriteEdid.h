/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("CVTE").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  cvte,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2017> - <2017>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : CVTEFunctionWriteEdid.h No.0000
// Update Note  :
// Author       :xiangjianhe@20170523
//----------------------------------------------------------------------------------------------------
#ifndef _CVTE_FUNCTION_WRITER_EDID_H
#define _CVTE_FUNCTION_WRITER_EDID_H

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
enum FactoryOnLineEdidDef
{
    _ON_LINE_EDID_NON,          // --- _Non    
    _ON_LINE_EDID_VGA,          // --- _IIC_VGA_DDC
    _ON_LINE_EDID_DVI,          // --- _Not USE
    _ON_LINE_EDID_HDMI1,        // --- _IIC_DDC1
    _ON_LINE_EDID_HDMI2,        // --- _IIC_DDC2
    _ON_LINE_EDID_HDMI3,        // --- _Not USE
};

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#define EDID_SN_LEN				13
#define EDID_HEAD_LEN           8
#define EDID_HEAD_ADDR          0x00
#define EDID_WEEK_ADDR          0x10
#define EDID_YEAR_ADDR          0x11
#define EDID_HSIZE_ADDR         0x15
#define EDID_VSIZE_ADDR         0x16

#define EDID_SN_SIZE_ADDR       1
#define EDID_SN_YEAR_ADDR       4
#define EDID_SN_WEEK_HIGH_ADDR  5
#define EDID_SN_WEEK_LOW_ADDR   6

#define ASCLL_0                 0x30
#define ASCLL_8                 0x38
#define ASCLL_9                 0x39
#define ASCLL_A                 0x41
#define ASCLL_B                 0x42
#define ASCLL_C                 0x43
#define ASCLL_D                 0x44
#define ASCLL_E                 0x45
#define ASCLL_F                 0x46
#define ASCLL_G                 0x47
#define ASCLL_H                 0x48
#define ASCLL_I                 0x49
#define ASCLL_J                 0x4A
#define ASCLL_K                 0x4B
#define ASCLL_L                 0x4C
#define ASCLL_M                 0x4D
#define ASCLL_N                 0x4E
#define ASCLL_P                 0x50
#define ASCLL_Q                 0x51
#define ASCLL_R                 0x52
#define ASCLL_S                 0x53

#define EDID_VGA_LEN            128
#define EDID_DVI_LEN            128
#define EDID_HDMI_LEN           256
#define EDID_MHL_LEN            256
#define EDID_DP_LEN             256

#define EDID_DEFAULT_MFG_YEAR 	2017

//...
#define EDID_DEFAULT_SYNC_PORT  _ON_LINE_EDID_VGA
#define EDID_DEFAULT_SYNC_LEN   128
//---------------------------------------------------

#define EDID_AOC_MODE           1
#define EDID_NORMAL_MODE        2
#define EDID_SYNC_MODE          EDID_NORMAL_MODE

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern BYTE *EDIDBuffer;
extern bit GetEdidSN(BYTE Port);
extern bit CVTEEDIDCheck(void);
extern void SyncEdidWeek(void);
extern void SyncEdidYear(void);
extern void SyncEdidSNNum(void);
extern void EDIDSyncProcess(void);
extern void COsdFactoryCheckEdidProcess(void);
extern void COsdEEPROMLoadDefualtEdid(void);
extern bit TPVEDIDCheck(void);
extern bit CEepromEdidWrite(WORD usSubAddr, WORD usLength, BYTE *pWriteArray,BYTE usEdidType);
extern bit CEepromEdidRead(WORD usSubAddr, WORD usLength, BYTE *pReadArray,BYTE usEdidType);
extern void SetAllDDCPortInitialDDC(void);
#if(CVT_EN_SYNC_EDID_SUPPORT == ENABLE)
extern void CosdFactoryEdidSyncSouce(void);
#endif
#endif//_CVTE_FUNCTION_WRITER_EDID_H

