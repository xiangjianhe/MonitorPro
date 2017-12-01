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
// ID Code      : UserCommonNVRamSystem.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_NVRAM_SYSTEM__

#include "UserCommonInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _EEPROM_READ_SIZE                           24
#define _EEPROM_TIMEOUT_LIMIT                       50

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#if((_FLASH_ACCESS_FUNCTION_SUPPORT == _ON) || (_FLASH_WR_PROTECT ==_ON))
//--------------------------------------------------
// Definitions of Version Code related Infor.
//--------------------------------------------------
typedef struct
{
    BYTE ucIDCheck1OpCode; // ID check 1 OP code(0x9F/0x90/0xAB)
    BYTE ucIDCheck1_ID0; // ID check 1 ID
    BYTE ucIDCheck1_ID1;
    BYTE ucIDCheck1_ID2;
    BYTE ucIDCheck2OpCode; // ID check 1 OP code(0x90/0xAB)
    BYTE ucIDCheck2_ID0; // ID check 1 ID
    BYTE ucIDCheck2_ID1;
    BYTE ucIDCheck2_ID2;
    BYTE ucWRENOpCode; // WREN OP code
    BYTE ucWRDisOpCode; // WRDis OP code
    BYTE ucPageEraseOpCode; // Page erase OP code
    BYTE ucUnprotectWRSR; // Unprotect status register value
    BYTE ucProtectWRSR; // Protect status register value
}StructFlashInformation;

#endif


//****************************************************************************
// CODE TABLES
//****************************************************************************
StructSystemDataType code g_stSystemDefaultData =
{
    _ON,                               // Monitor Flag
    _ON,                               // DPHotPlugDCOffHigh      
    _INPUT_PORT_SEARCH_PRI_0,          // Search Port
    _SOURCE_SWITCH_AUTO_IN_GROUP,      // Source Scan Type
//--------------------------------------------------------
    0x02,                              // HDMIHotPlugSupportTime       
    _ON,                               // HDMIHotPlugSupport
    0x00,                              // HP User Defautl SearchIndex
    _ON,                               // HP User Auto Search        
    0x00,                              // Mode Slot Index
#if((_FACTORY_MODE_OWNER == _OWNER_WISTRON)&&(_PANEL_EXIST_MULTIPANEL == _ON))
    0x03,//ym20141029 ._DCLK_SPREAD_RANGE define by multi pane, // SSC
#else
    _DCLK_SPREAD_RANGE,                // SSC
#endif                       
    0,                                 // Slp No Cable Detect
};

#if(_VGA_SUPPORT == _ON)
code StructAdcDataType g_stADCRgbDefaultData = 
{
    _ADC_RGB_DEFAULT_PGA_VALUE,
    {  _ADC_RGB_DEFAULT_RED_GAIN,   _ADC_RGB_DEFAULT_GREEN_GAIN,   _ADC_RGB_DEFAULT_BLUE_GAIN}, // Gain MSB
    {                       0x00,                          0x00,                         0x00}, // Gain LSB
    {_ADC_RGB_DEFAULT_RED_OFFSET, _ADC_RGB_DEFAULT_GREEN_OFFSET, _ADC_RGB_DEFAULT_BLUE_OFFSET}, // Offset MSB
    {                       0x00,                          0x00,                         0x00}, // Offset LSB
};


#if(_YPBPR_SUPPORT == _ON)
code StructAdcDataType g_stADCYpbprDefaultData = 
{
    _ADC_YPBPR_DEFAULT_PGA_VALUE,
    {_ADC_YPBPR_DEFAULT_PR_GAIN,     _ADC_YPBPR_DEFAULT_Y_GAIN,   _ADC_YPBPR_DEFAULT_PB_GAIN}, // Gain MSB
    {                       0x00,                         0x00,                         0x00}, // Gain LSB
    {_ADC_YPBPR_DEFAULT_PR_OFFSET, _ADC_YPBPR_DEFAULT_Y_OFFSET, _ADC_YPBPR_DEFAULT_PB_OFFSET}, // Offset MSB
    {                       0x00,                         0x00,                         0x00}, // Offset LSB
};
#endif

#endif  // End of #if(_VGA_SUPPORT == _ON)

#if((_FLASH_ACCESS_FUNCTION_SUPPORT == _ON) || (_FLASH_WR_PROTECT ==_ON))
StructFlashInformation code tFlashInformation[] =
{
    // _FLASH_W25X20A; ucUnprotectWRSR is not used here
    {0x9F, 0xEF, 0x30, 0x12, 0x90, 0xEF, 0x11, 0x00, 0x06, 0x04, 0x20, 0x28, 0xBC},
    // _FLASH_W25X21CL; ucUnprotectWRSR is not used here
    {0x9F, 0xEF, 0x30, 0x12, 0x90, 0xEF, 0x11, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_PM25LV020; ucUnprotectWRSR is not used here
    {0x9F, 0x7F, 0x9D, 0x7D, 0xAB, 0x9D, 0x7D, 0x7F, 0x26, 0x24, 0xD7, 0x00, 0x9C},
    // _FLASH_MX25L2026D; ucUnprotectWRSR is not used here
    {0x9F, 0xC2, 0x20, 0x12, 0x90, 0xC2, 0x03, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_EN25F20; ucUnprotectWRSR is not used here
    {0x9F, 0x1C, 0x31, 0x12, 0x90, 0x1C, 0x11, 0x00, 0x06, 0x04, 0x20, 0x02, 0x9C},
    // _FLASH_PM25LD020; ucUnprotectWRSR is not used here
    {0x9F, 0x7F, 0x9D, 0x22, 0x90, 0x9D, 0x11, 0x7F, 0x26, 0x24, 0xD7, 0x00, 0x9C},
    // _FLASH_MX25L2025; ucUnprotectWRSR is not used here
    {0x9F, 0xC2, 0x20, 0x12, 0x90, 0xC2, 0x11, 0x00, 0x06, 0x04, 0x20, 0x02, 0x8C},
    //_FLASH_MX25L4006E; ucUnprotectWRSR is not used here
    {0X9F, 0xC2, 0x20, 0x13, 0x90, 0xC2, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0x9C},
    // _FLASH_SST25LF020A
    {0x90, 0xBF, 0x43, 0x00, 0x90, 0xBF, 0x43, 0x00, 0x06, 0x04, 0x20, 0x02, 0x9C},
    // _FLASH_W25X41CL; ucUnprotectWRSR is not used here
    {0x9F, 0xEF, 0x30, 0x13, 0x90, 0xEF, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_FM25F04; ucUnprotectWRSR is not used here
    {0x9F, 0xA1, 0x31, 0x13, 0x90, 0xA1, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_N25S40; ucUnprotectWRSR is not used here
    {0x9F, 0xD5, 0x30, 0x13, 0x90, 0xD5, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC}, 
    // _FLASH_A25L040; ucUnprotectWRSR is not used here
    {0x9F, 0x37, 0x30, 0x13, 0x90, 0x37, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0x9C}, 
    // _FLASH_W25Q80BV; ucUnprotectWRSR is not used here
    {0x9F, 0xEF, 0x40, 0x14, 0x90, 0xEF, 0x13, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC}, 
    // _FLASH_PM25LQ020A; ucUnprotectWRSR is not used here
    {0x9F, 0x7F, 0x9D, 0x42, 0x90, 0x9D, 0x11, 0x7F, 0x26, 0x24, 0x20, 0x02, 0x9C}, 
    // _FLASH_MX25L4026D; ucUnprotectWRSR is not used here
    {0x9F, 0xC2, 0x20, 0x13, 0x90, 0xC2, 0x04, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_W25X40CL; ucUnprotectWRSR is not used here
    {0x9F, 0xEF, 0x30, 0x13, 0x90, 0xEF, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xBC},
    // _FLASH_EN25F20A; ucUnprotectWRSR is not used here
    {0x9F, 0x1C, 0x31, 0x12, 0x90, 0x1C, 0x11, 0x00, 0x06, 0x04, 0x20, 0x02, 0xBC},
    // _FLASH_EN25F40A; ucUnprotectWRSR is not used here
    {0x9F, 0x1C, 0x31, 0x13, 0x90, 0x1C, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xBC},
    // _FLASH_EN25Q40A; ucUnprotectWRSR is not used here
    {0x9F, 0x1C, 0x30, 0x13, 0x90, 0x1C, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xBC},
    // _FLASH_EN25Q80; ucUnprotectWRSR is not used here
    {0x9F, 0x1C, 0x30, 0x14, 0x90, 0x1C, 0x13, 0x00, 0x06, 0x04, 0x20, 0x02, 0xBC},
    // _FLASH_GD25Q80B; ucUnprotectWRSR is not used here
    {0x9F, 0xC8, 0x40, 0x14, 0x90, 0xC8, 0x13, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},    
    // _FLASH_GD25M21B; ucUnprotectWRSR and ucProtectWRSR is not used here
    {0x9F, 0xC8, 0x41, 0x12, 0x90, 0xC8, 0x11, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_GD25M41B; ucUnprotectWRSR and ucProtectWRSR is not used here
    {0x9F, 0xC8, 0x41, 0x13, 0x90, 0xC8, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    //_FLASH_MX25L8006E; ucUnprotectWRSR is not used here
    {0X9F, 0xC2, 0x20, 0x14, 0x90, 0xC2, 0x13, 0x00, 0x06, 0x04, 0x20, 0x02, 0x9C},
    // _FLASH_PM25LQ080; ucUnprotectWRSR is not used here
    {0x9F, 0x9D, 0x13, 0x44, 0x90, 0x9D, 0x13, 0x7F, 0x26, 0x24, 0x20, 0x02, 0xBC},
    // _FLASH_GD25Q40B; ucUnprotectWRSR is not used here
    {0x9F, 0xC8, 0x40, 0x13, 0x90, 0xC8, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC}, 
    // _FLASH_PM25LQ040B; ucUnprotectWRSR is not used here
    {0x9F, 0x7F, 0x9D, 0x7E, 0x90, 0x9D, 0x7E, 0x7F, 0x26, 0x24, 0xD7, 0x00, 0x9C}, 
    // _FLASH_GD25Q41; ucUnprotectWRSR is not used here
    {0x9F, 0xC8, 0x40, 0x13, 0x90, 0xC8, 0x12, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_W25Q16DV; ucUnprotectWRSR is not used here
    {0x9F, 0xEF, 0x40, 0x15, 0x90, 0xEF, 0x14, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_GD25Q16C; ucUnprotectWRSR is not used here
    {0x9F, 0xC8, 0x40, 0x15, 0x90, 0xC8, 0x14, 0x00, 0x06, 0x04, 0x20, 0x02, 0xFC},
    // _FLASH_MX25L3233F; ucUnprotectWRSR is not used here
    {0x9F, 0xC2, 0x20, 0x16, 0x90, 0xC2, 0x15, 0x00, 0x06, 0x04, 0x20, 0x02, 0xBC},
    // _FLASH_EN25QH32A; ucUnprotectWRSR is not used here
    {0x9F, 0x1C, 0x70, 0x16, 0x90, 0x1C, 0x15, 0x00, 0x06, 0x04, 0x20, 0x42, 0xBC},
    // _FLASH_MX25V8035F; ucUnprotectWRSR is not used here
    {0x9F, 0xC2, 0x23, 0x14, 0x90, 0xC2, 0x14, 0x00, 0x06, 0x04, 0x20, 0x02, 0xBC},
    // _FLASH_MX25V1635F; ucUnprotectWRSR is not used here
    {0x9F, 0xC2, 0x23, 0x15, 0x90, 0xC2, 0x15, 0x00, 0x06, 0x04, 0x20, 0x02, 0xBC},
};
#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructSystemDataType g_stSystemData;

#if(_VGA_SUPPORT == _ON)
VGAModeUserDataType g_stVGAModeUserData;
StructAdcDataType g_stAdcData;
#endif

#if((_FLASH_ACCESS_FUNCTION_SUPPORT == _ON) || (_FLASH_WR_PROTECT ==_ON))
BYTE g_ucFlashType = _FLASH_UNDETECT;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE UserCommonNVRamGetSystemData(BYTE ucDataType);
void UserCommonNVRamSetSystemData(BYTE ucDataType, BYTE ucValue);

#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
bit UserCommonEepromIICRead(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pReadArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum);
bit UserCommonEepromIICWrite(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pWriteArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum, EnumEepromWriteSize enumWriteSize);
#endif

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
bit UserCommonEepromRead(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
bit UserCommonEepromWrite(WORD usSubAddr, WORD usLength, BYTE *pWriteArray);
void UserCommonEepromSaveSystemData(void);
void UserCommonEepromLoadSystemData(void);
void UserCommonEepromRestoreSystemData(void);

#if(_VGA_SUPPORT == _ON)
void UserCommonEepromLoadModeUserData(BYTE ucSlotIndex);
void UserCommonEepromSaveModeUserData(void);
BYTE UserCommonEepromLoadModeUserModeNumberData(BYTE ucSlotIndex);
void UserCommonEepromRestoreModeUserData(void);
BYTE UserCommonEepromVGAFifoModeIndexOffsetInc(BYTE ucStep);
BYTE UserCommonEepromGetMaxFifoGroupCnt(void);
void UserCommonEepromLoadADCSetting(EnumColorSpace enumColorFormat);
void UserCommonEepromSaveADCSetting(EnumColorSpace enumColorFormat);
void UserCommonEepromRestoreADCSetting(void);
#endif
#if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
void UserCommonEepromGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
void UserCommonEepromGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
void UserCommonEepromRestoreHDCP(WORD usOffset, BYTE ucLength, BYTE* pucBuf);
#endif
#endif

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

void UserCommonFlashSaveSystemData(void);
void UserCommonFlashLoadSystemData(void);
void UserCommonFlashRestoreSystemData(void);

#if(_VGA_SUPPORT == _ON)
void UserCommonFlashLoadModeUserData(BYTE ucSlotIndex);
void UserCommonFlashSaveModeUserData(void);
BYTE UserCommonFlashLoadModeUserModeNumberData(BYTE ucSlotIndex);
void UserCommonFlashRestoreModeUserData(void);
BYTE UserCommonFlashVGAFifoModeIndexOffsetInc(BYTE ucStep);
BYTE UserCommonFlashGetMaxFifoGroupCnt(void);
void UserCommonFlashLoadADCSetting(EnumColorSpace enumColorFormat);
void UserCommonFlashSaveADCSetting(EnumColorSpace enumColorFormat);
void UserCommonFlashRestoreADCSetting(void);
#endif
#if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
void UserCommonFlashGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
void UserCommonFlashGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
void UserCommonFlashRestoreHDCP(WORD usAddr, BYTE ucLength, BYTE* pucBuf);
#endif
#endif

#endif // End of #elif(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)


#if((_FLASH_ACCESS_FUNCTION_SUPPORT == _ON) || (_FLASH_WR_PROTECT ==_ON))
void UserCommonFlashDetectFlashType(void);
bit UserCommonFlashReadFlashIDCode(BYTE ucRDIDOPCode, BYTE *pucIDArry);

#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _ON)
void UserCommonFlashWREN(BYTE ucBank, BYTE ucPage);
void UserCommonFlashWRDis(void);
#endif

void UserCommonFlashSetWREN(BYTE ucOpCode);
void UserCommonFlashSetWRSR(BYTE ucWRSR, bit bIsSST);
void UserCommonFlashSet2ByteWRSR(BYTE ucWRSR1, BYTE ucWRSR2, bit bIsSST);

#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _ON)
bit UserCommonFlashErasePage(BYTE ucBank, BYTE ucPage);
bit UserCommonFlashWrite(BYTE ucBank, WORD usAddr, WORD usLength, BYTE* pucData);
bit UserCommonFlashRead(BYTE ucBank, WORD usAddr, WORD usLength, BYTE* pucData);
#endif

#if(_FLASH_WR_PROTECT ==_ON)
void UserCommonFlashWRProtect(void);
#endif

#endif // End of #if((_FLASH_ACCESS_FUNCTION_SUPPORT == _ON) || (_FLASH_WR_PROTECT ==_ON))

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get System Data Info
// Input Value  : enumDataType --> Data Type in StructSystemData
// Output Value : ucValue --> Value of the Input Data Type
//--------------------------------------------------
BYTE UserCommonNVRamGetSystemData(EnumSystemDataItemDataType enumDataType)
{
    BYTE ucValue = 0;

    switch(enumDataType)
    {
        case _MONITOR_POWER_STATUS:
            ucValue = (bit)(g_stSystemData.b1PowerStatus);
            break;

        case _SEARCH_PORT:
            ucValue = g_stSystemData.b3SearchPort;
            break;

        case _SOURCE_SCAN_TYPE:
            ucValue = g_stSystemData.b3SourceScanType;
            break;

#if(_VGA_SUPPORT == _ON)
        case _MODE_SLOT_INDEX:
            ucValue = g_stSystemData.ucModeSlotIndex;
            break;
#endif

        case _SSC:
            ucValue = g_stSystemData.ucSSC;
            break;

        case _DP_HOT_PLUG_DC_OFF_HIGH:
            ucValue = g_stSystemData.b1DPHotPlugDCOffHigh;
            break;

        case _HDMI_HOT_PLUG_SUPPORT:
            ucValue = g_stSystemData.b1HDMIHotPlugSupport;
            break;

        case _HDMI_HOT_PLUG_SUPPORT_TIME:
            ucValue = g_stSystemData.b3HDMIHotPlugSupportTime;
            break;

        case _SOURCE_HP_DEFAULT_PORT:
            ucValue = g_stSystemData.b3SourceHPDefaultSearchIndex;            
            break;

        case _SOURCE_HP_AUTO_SEARCH:
            ucValue = g_stSystemData.b1SourceHPAutoSearch;
            break;

#if(_SUPER_LOW_POWER_SUPPORT == _ON)
        case _SLP_AC_OFF_DETECT:
            ucValue = g_stSystemData.b1SlpAcOffDetect;
            break;
#endif
//-----------------------------------------------------------------------
        default:
            break;
    }

    return ucValue;
}

//--------------------------------------------------
// Description  : Set System Data Info
// Input Value  : ucDataType --> Data Type in StructSystemData
//                  ucValue --> Value to be set for the Input Data Type
// Output Value : None
//--------------------------------------------------
void UserCommonNVRamSetSystemData(BYTE ucDataType, BYTE ucValue)
{
    switch(ucDataType)
    {
        case _MONITOR_POWER_STATUS:
            g_stSystemData.b1PowerStatus = (bit)ucValue;
            break;

        case _SEARCH_PORT:
            g_stSystemData.b3SearchPort = ucValue;
            break;

        case _SOURCE_SCAN_TYPE:

            if(ucValue == _SOURCE_SWITCH_DELL_HOTKEY_FIXED)
            {
                ucValue = _SOURCE_SWITCH_FIXED_PORT;
            }
            else if(ucValue == _SOURCE_SWITCH_DELL_HOTKEY_AUTO)
            {
                ucValue = _SOURCE_SWITCH_AUTO_IN_GROUP;
            }
            
            g_stSystemData.b3SourceScanType = ucValue;
            break;

#if(_VGA_SUPPORT == _ON)
        case _MODE_SLOT_INDEX:
            g_stSystemData.ucModeSlotIndex = ucValue;
            break;
#endif

        case _SSC:
            g_stSystemData.ucSSC = ucValue ;
            break;

        case _DP_HOT_PLUG_DC_OFF_HIGH:
             g_stSystemData.b1DPHotPlugDCOffHigh = ucValue;
            break;

        case _HDMI_HOT_PLUG_SUPPORT:
            g_stSystemData.b1HDMIHotPlugSupport = ucValue;
            break;

        case _HDMI_HOT_PLUG_SUPPORT_TIME:
            g_stSystemData.b3HDMIHotPlugSupportTime = ucValue;
            break;

        case _SOURCE_HP_DEFAULT_PORT:
            g_stSystemData.b3SourceHPDefaultSearchIndex = ucValue;            
            break;

        case _SOURCE_HP_AUTO_SEARCH:
            g_stSystemData.b1SourceHPAutoSearch = ucValue;
            break;

#if(_SUPER_LOW_POWER_SUPPORT == _ON)
        case _SLP_AC_OFF_DETECT:
            g_stSystemData.b1SlpAcOffDetect = (bit)ucValue;
            break;
#endif

//--------------------------------------------------------------------
        default:
            break;
    }
}

#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Read data to the External EEPROM by IIC
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
//                ucIICStatus   --> SW IIC Applications
//                ucHwIICPinNum --> HW IIC Pin Used
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonEepromIICRead(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pReadArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum)
{
    BYTE ucSlaveAddress = ucSlaveAddr;
    BYTE ucDataCnt = 0;

    ucSWIICStatus = ucSWIICStatus;
    
    if(usLength < 0)
    {
        return _FAIL;
    }
    
    while(usLength > 0)
    {
        if(ucSubAddrLength == 1)
        {
            ucSlaveAddress = ucSlaveAddr + (BYTE)((usSubAddr & 0xFF00) >> 7);
        }
        
        // Receive 24 bytes each time
        ucDataCnt = _EEPROM_READ_SIZE;

        // Check if more than 24 bytes are needed to be received
        if(usLength > ucDataCnt)
        {
            usLength -= ucDataCnt;
        }
        else
        {
            ucDataCnt = usLength;
            usLength = 0;
        }

        // Execute Hardware IIC Read Command
        if(ucHwIICPinNum == _SW_IIC_PIN_GPIO)
        {
            
#if(_SW_IIC_SUPPORT == _ON)
            SET_SW_IIC_STATUS(ucSWIICStatus);

            if(ScalerMcuIICRead(ucSlaveAddress, ucSubAddrLength, usSubAddr, ucDataCnt, pReadArray) == _FAIL)
            {
                return _FAIL;
            }
#endif // End of #if(_SW_IIC_SUPPORT == _ON)

        }
        else if(ucHwIICPinNum != _NO_IIC_PIN)
        {

#if(_HW_IIC_SUPPORT == _ON)
            if(ScalerMcuHwIICRead(ucSlaveAddress, ucSubAddrLength, usSubAddr, ucDataCnt, pReadArray, ucHwIICPinNum) == _FAIL)
            {
                return _FAIL;
            }
#endif // End of #if(_HW_IIC_SUPPORT == _ON)

        }
        
        // Increase data location
        pReadArray += ucDataCnt;

        // Increment Sub-Addr for next Read
        usSubAddr += ucDataCnt;

    }

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Write data to the System EEPROM by IIC
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
//                ucIICStatus   --> SW IIC Applications
//                ucHwIICPinNum --> HW IIC Pin Used
//                enumWriteSize --> 8 or 16
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonEepromIICWrite(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pWriteArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum, EnumEepromWriteSize enumWriteSize)
{
    BYTE ucSlaveAddress = ucSlaveAddr;
    BYTE ucDataCnt = 0;
    BYTE ucTimeOutCnt = _EEPROM_TIMEOUT_LIMIT;

    ucSWIICStatus = ucSWIICStatus;

    if(usLength < 0)
    {
        return _FAIL;
    }

    while(usLength > 0)
    {
        if(ucSubAddrLength == 1)
        {
            ucSlaveAddress = ucSlaveAddr + (BYTE)((usSubAddr & 0xFF00) >> 7);
        }

        // Transmit 8 or 16 bytes each time
        ucDataCnt = enumWriteSize;

        // Check if more than 8 or 16 bytes are needed to be transmitted
        if(enumWriteSize == _WRITE_SIZE_16)
        {
            if(((usSubAddr & 0x000F) + usLength - 1) >= enumWriteSize)
            {
                ucDataCnt = enumWriteSize - (usSubAddr & 0x000F);    
            }
        }
        else if(enumWriteSize == _WRITE_SIZE_8)
        {            
            if(((usSubAddr & 0x0007) + usLength - 1) >= enumWriteSize)
            {
                ucDataCnt = enumWriteSize - (usSubAddr & 0x0007);    
            }
        }

        if(usLength > ucDataCnt)
        {
            usLength -= ucDataCnt;
        }
        else
        {
            ucDataCnt = usLength;
            usLength = 0;
        }

        // Save the data to be transfered to pData to ensure the data is saved in XDATA SPACE
        memcpy(pData, pWriteArray, ucDataCnt);

        // Increase data location
        pWriteArray += ucDataCnt;

        // Disable EEPROM Write Protect
        PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);

        // Execute Hardware IIC Write Command
        if(ucHwIICPinNum == _SW_IIC_PIN_GPIO)
        {
            
#if(_SW_IIC_SUPPORT == _ON)
            SET_SW_IIC_STATUS(ucSWIICStatus);

            if(ScalerMcuIICWrite(ucSlaveAddress, ucSubAddrLength, usSubAddr, ucDataCnt, pData) == _FAIL)
            {
                // Enable EEPROM Write Protect
                PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);

                return _FAIL;
            }
#endif // End of #if(_SW_IIC_SUPPORT == _ON)

        }
        else if(ucHwIICPinNum != _NO_IIC_PIN)
        {

#if(_HW_IIC_SUPPORT == _ON)
            if(ScalerMcuHwIICWrite(ucSlaveAddress, ucSubAddrLength, usSubAddr, ucDataCnt, pData, ucHwIICPinNum) == _FAIL)
            {
                // Enable EEPROM Write Protect
                PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);

                return _FAIL;
            }
#endif // End of #if(_HW_IIC_SUPPORT == _ON)

        }

        // Increment Sub-Addr for next Write
        usSubAddr += ucDataCnt;
        
        // Need to delay until internal write cycle is finished
        if(ucHwIICPinNum == _SW_IIC_PIN_GPIO)
        {
            
#if(_SW_IIC_SUPPORT == _ON)
            SET_SW_IIC_STATUS(ucSWIICStatus);

            while(ScalerMcuIICWritePolling(ucSlaveAddress) == _FAIL)
            {
                ucTimeOutCnt--;

                Delay5us(g_ucDelay5usN);

                if(!ucTimeOutCnt)
                {
                    // Enable EEPROM Write Protect
                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
                    
                    return _FAIL;
                }
            }
#endif // End of #if(_SW_IIC_SUPPORT == _ON)

        }
        else if(ucHwIICPinNum != _NO_IIC_PIN)
        {

#if(_HW_IIC_SUPPORT == _ON)
            while(ScalerMcuHwIICWritePolling(ucSlaveAddress, ucSubAddrLength, ucHwIICPinNum) == _FAIL)
            {
                ucTimeOutCnt--;

                Delay5us(g_ucDelay5usN);

                if(!ucTimeOutCnt)
                {
                    // Enable EEPROM Write Protect
                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
                    
                    return _FAIL;
                }
            }
#endif // End of #if(_HW_IIC_SUPPORT == _ON)

        }

        ucTimeOutCnt = _EEPROM_TIMEOUT_LIMIT;
        
        // Enable EEPROM Write Protect
        PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);

    }
    return _SUCCESS;
}
#endif // End of #if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Read data to the System EEPROM by IIC
// Input Value  : usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonEepromRead(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{
    // Execute Hardware IIC Read Command
#if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

#if(_EEPROM_TYPE == _EEPROM_24LC16)
    if(UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, usSubAddr, 1, usLength, pReadArray, _IIC_SYS_EEPROM, _PCB_SYS_EEPROM_IIC) == _FAIL)
#elif(_EEPROM_TYPE == _EEPROM_24WC64)
    if(UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, usSubAddr, 2, usLength, pReadArray, _IIC_SYS_EEPROM, _PCB_SYS_EEPROM_IIC) == _FAIL)
#endif

    {
        return _FAIL;
    }
    
#elif(_PCB_SYS_EEPROM_IIC != _NO_IIC_PIN)   // Else of #if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

#if(_EEPROM_TYPE == _EEPROM_24LC16)
    if(UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, usSubAddr, 1, usLength, pReadArray, 0x00, _PCB_SYS_EEPROM_IIC) == _FAIL)
#elif(_EEPROM_TYPE == _EEPROM_24WC64)
    if(UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, usSubAddr, 2, usLength, pReadArray, 0x00, _PCB_SYS_EEPROM_IIC) == _FAIL)
#endif

    {
        return _FAIL;
    }
#endif  // End of #if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Write data to the System EEPROM by IIC
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonEepromWrite(WORD usSubAddr, WORD usLength, BYTE *pWriteArray)
{
    // Execute Hardware IIC Write Command
#if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

#if(_EEPROM_TYPE == _EEPROM_24LC16)
    if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, usSubAddr, 1, usLength, pWriteArray, _IIC_SYS_EEPROM, _PCB_SYS_EEPROM_IIC, _WRITE_SIZE_16) == _FAIL)
#elif(_EEPROM_TYPE == _EEPROM_24WC64)
    if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, usSubAddr, 2, usLength, pWriteArray, _IIC_SYS_EEPROM, _PCB_SYS_EEPROM_IIC, _WRITE_SIZE_16) == _FAIL)
#endif

    {
        return _FAIL;
    }

#elif(_PCB_SYS_EEPROM_IIC != _NO_IIC_PIN)   // Else of #if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

#if(_EEPROM_TYPE == _EEPROM_24LC16)
    if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, usSubAddr, 1, usLength, pWriteArray, 0x00, _PCB_SYS_EEPROM_IIC, _WRITE_SIZE_16) == _FAIL)
#elif(_EEPROM_TYPE == _EEPROM_24WC64)
    if(UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, usSubAddr, 2, usLength, pWriteArray, 0x00, _PCB_SYS_EEPROM_IIC, _WRITE_SIZE_16) == _FAIL)
#endif
    {
        return _FAIL;
    }
#endif  // End of #if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)
   
    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Save system data to EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromSaveSystemData(void)
{
    if(UserInterfaceCheckNVRamData(_CHECK_SYSTEM_DATA_SAVE) == _FAIL)
    {
        return;
    }
    
    UserCommonEepromWrite(_SYSTEM_DATA_ADDRESS, sizeof(StructSystemDataType), (BYTE *)(&g_stSystemData));
}

//--------------------------------------------------
// Description  : Load system data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromLoadSystemData(void)
{
    UserCommonEepromRead(_SYSTEM_DATA_ADDRESS, sizeof(StructSystemDataType), (BYTE *)(&g_stSystemData));

    UserInterfaceCheckNVRamData(_CHECK_SYSTEM_DATA_LOAD);
}

//--------------------------------------------------
// Description  : Restore default system data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromRestoreSystemData(void)
{
    g_stSystemData = g_stSystemDefaultData;
    UserCommonEepromSaveSystemData();
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Load mode user data from EEPROM
// Input Value  : ucSlotIndex
// Output Value : None
//--------------------------------------------------
void UserCommonEepromLoadModeUserData(BYTE ucSlotIndex)
{
    UserCommonEepromRead(_MODE_USER_DATA_ADDRESS + (ucSlotIndex % _MODE_SLOT_AMOUNT) * sizeof(VGAModeUserDataType),
                         sizeof(VGAModeUserDataType),
                         (BYTE *)(&g_stVGAModeUserData));

    UserInterfaceCheckNVRamData(_CHECK_MODE_USER_DATA_LOAD);
}

//--------------------------------------------------
// Description  : Save mode user data to EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromSaveModeUserData(void)
{
    BYTE ucFIFOInx = 0;
    BYTE ucSlotIndex = UserCommonEepromGetMaxFifoGroupCnt() + 1;

    if(UserInterfaceCheckNVRamData(_CHECK_MODE_USER_DATA_SAVE) == _FAIL)
    {
        return;
    }
    
    for(ucFIFOInx = 0; ucFIFOInx < UserCommonEepromGetMaxFifoGroupCnt(); ucFIFOInx++)
    {      
        if(UserCommonEepromLoadModeUserModeNumberData(ucFIFOInx) == g_stVGAModeUserData.ucModeNumber)        
        {
            ucSlotIndex = ucFIFOInx;
            break;
        }  
    }

    if(ucSlotIndex == (UserCommonEepromGetMaxFifoGroupCnt() + 1))
    {
        // Add FIFO mode index number by step
        ucSlotIndex = UserCommonEepromVGAFifoModeIndexOffsetInc(1);
    }

    UserCommonEepromWrite(_MODE_USER_DATA_ADDRESS + (ucSlotIndex % _MODE_SLOT_AMOUNT) * sizeof(VGAModeUserDataType),
                          sizeof(VGAModeUserDataType),
                          (BYTE *)(&g_stVGAModeUserData));
}

//--------------------------------------------------
// Description  : Load mode user Mode Number data from EEPROM
// Input Value  : ucSlotIndex
// Output Value : Mode Number
//--------------------------------------------------
BYTE UserCommonEepromLoadModeUserModeNumberData(BYTE ucSlotIndex)
{
    BYTE ucModeNumber = 0xFF;

    UserCommonEepromRead(_MODE_USER_DATA_ADDRESS + (ucSlotIndex % _MODE_SLOT_AMOUNT) * sizeof(VGAModeUserDataType) + 1,
                         1, (BYTE *)(&ucModeNumber));

    return ucModeNumber;
}
//--------------------------------------------------
// Description  : Restore default mode user data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromRestoreModeUserData(void)
{
    VGAModeUserDataType stVGAModeUserData;
    
    // g_stVGAModeUserData will be clear
    memset(&stVGAModeUserData, 0xFF, sizeof(VGAModeUserDataType));

    for(g_stSystemData.ucModeSlotIndex = 0; g_stSystemData.ucModeSlotIndex < _MODE_SLOT_AMOUNT; g_stSystemData.ucModeSlotIndex++)
    {
        UserCommonEepromWrite(_MODE_USER_DATA_ADDRESS + (g_stSystemData.ucModeSlotIndex * sizeof(VGAModeUserDataType)),
                    sizeof(VGAModeUserDataType), (BYTE *)(&stVGAModeUserData));
    }

    g_stSystemData.ucModeSlotIndex = 0;
}

//--------------------------------------------------
// Description  : Increase VGA Fifo mode index
// Input Value  : None
// Output Value : FIFO Mode Current Index
//--------------------------------------------------
BYTE UserCommonEepromVGAFifoModeIndexOffsetInc(BYTE ucStep)
{
	VGAModeUserDataType stVGAModeUserData;
	BYTE ucMNumber = 0xFF;
    BYTE ucInx = 0;

	// g_stVGAModeUserData will be clear
	memset(&stVGAModeUserData, 0xFF, sizeof(VGAModeUserDataType));

	for(ucInx = 0; ucInx < _MODE_SLOT_AMOUNT; ucInx++)
	{
		g_stSystemData.ucModeSlotIndex = (g_stSystemData.ucModeSlotIndex + ucStep) % _MODE_SLOT_AMOUNT;

		ucMNumber= UserCommonEepromLoadModeUserModeNumberData(g_stSystemData.ucModeSlotIndex);

		if((UserCommonModeSearchCheckPresetModeTable(ucMNumber)== _TRUE))
		{
			UserCommonEepromRead(_MODE_USER_DATA_ADDRESS + (g_stSystemData.ucModeSlotIndex) * sizeof(VGAModeUserDataType),
						   1,(BYTE *)(&stVGAModeUserData));
		
			if((stVGAModeUserData.b1IsPresetMode==_PRESET_MODE_TYPE))
			{
				DebugMessageAnalog("4. Match presetmode", ucMNumber);
				
				continue;
			}
			else
			{
				break;		
		    }
		}
		else
		{
			break;
		}
	}	

    return g_stSystemData.ucModeSlotIndex;
}

//--------------------------------------------------
// Description  : Get VGA FIFO Mode Maximum No. 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserCommonEepromGetMaxFifoGroupCnt(void)
{
    return _MODE_SLOT_AMOUNT;
}

//--------------------------------------------------
// Description  : Load adc settings from EEPROM
// Input Value  : ucADCConfig
// Output Value : None
//--------------------------------------------------
void UserCommonEepromLoadADCSetting(EnumColorSpace enumColorFormat)
{
    if(enumColorFormat == _COLOR_SPACE_RGB)
    
    {
        UserCommonEepromRead(_ADC_SETTING_ADDRESS, sizeof(StructAdcDataType),
                       &g_stAdcData.ucAdcPGA);
    }
#if(_YPBPR_SUPPORT == _ON)
    else if(enumColorFormat == _COLOR_SPACE_YPBPR)
    {
        UserCommonEepromRead(_ADC_SETTING_ADDRESS + sizeof(StructAdcDataType),
                       sizeof(StructAdcDataType),
                       &g_stAdcData.ucAdcPGA);
    }
#endif    

    UserInterfaceCheckNVRamData(_CHECK_ADC_LOAD);
}

//--------------------------------------------------
// Description  : Save adc settings to EEPROM
// Input Value  : ucADCConfig
// Output Value : None
//--------------------------------------------------
void UserCommonEepromSaveADCSetting(EnumColorSpace enumColorFormat)
{
    if(UserInterfaceCheckNVRamData(_CHECK_ADC_SAVE) == _FAIL)
    {
        return;
    }
        
    if(enumColorFormat == _COLOR_SPACE_RGB)
    {
        UserCommonEepromWrite(_ADC_SETTING_ADDRESS, sizeof(StructAdcDataType),
                        &g_stAdcData.ucAdcPGA);
    }
#if(_YPBPR_SUPPORT == _ON)
    else if(enumColorFormat == _COLOR_SPACE_YPBPR)
    {
        UserCommonEepromWrite(_ADC_SETTING_ADDRESS + sizeof(StructAdcDataType),
                        sizeof(StructAdcDataType),
                        &g_stAdcData.ucAdcPGA);
    }
#endif    
}

//--------------------------------------------------
// Description  : Restore default adc settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromRestoreADCSetting(void)
{
    g_stAdcData = g_stADCRgbDefaultData;
    
    UserCommonEepromSaveADCSetting(_COLOR_SPACE_RGB);
    
#if(_YPBPR_SUPPORT == _ON)
    g_stAdcData = g_stADCYpbprDefaultData;
    UserCommonEepromSaveADCSetting(_COLOR_SPACE_YPBPR);
#endif

}
#endif // End of #if(_VGA_SUPPORT == _ON)

#if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray)
{
    UserCommonEepromRead((_EEPROM_HDCP_KEY_ADDRESS + ucSubAddr), ucLength, pReadArray);
}

//--------------------------------------------------
// Description  : Get HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{
    UserCommonEepromRead((_EEPROM_HDCP_KEY_ADDRESS + 5 + (usSubAddr)), usLength, pReadArray);
}

#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
//--------------------------------------------------
// Description  : Restore HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonEepromRestoreHDCP(WORD usOffset, BYTE ucLength, BYTE* pucBuf)
{
    UserCommonEepromWrite(_EEPROM_HDCP_KEY_ADDRESS + usOffset, ucLength, pucBuf);
}
#endif
#endif

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

void UserCommonFlashSaveSystemData(void)
{
    UserInterfaceFlashSaveItem(_FLASH_ITEMID_SYSTEM_DATA, (BYTE*)(&g_stSystemData), sizeof(StructSystemDataType));
}

void UserCommonFlashLoadSystemData(void)
{
    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_SYSTEM_DATA, pData, sizeof(StructSystemDataType)) == _TRUE)
    {
        memcpy(&g_stSystemData, pData, sizeof(StructSystemDataType));
    }
    else
    {
        g_stSystemData = g_stSystemDefaultData;
    }    
}

void UserCommonFlashRestoreSystemData(void)
{
    g_stSystemData = g_stSystemDefaultData;

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_SYSTEM_DATA, pData, 1) == _TRUE)
    {
        UserCommonFlashSaveSystemData();
    }
}

#if(_VGA_SUPPORT == _ON)
void UserCommonFlashLoadModeUserData(BYTE ucSlotIndex)
{
    ucSlotIndex = ucSlotIndex % _MODE_SLOT_AMOUNT;

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_MODE_USER_DATA + ucSlotIndex, pData, sizeof(VGAModeUserDataType)) == _TRUE)
    {
        memcpy(&g_stVGAModeUserData, pData, sizeof(VGAModeUserDataType));
    }
    else
    {
        memset(&g_stVGAModeUserData, 0xFF, sizeof(VGAModeUserDataType));
    }
}

void UserCommonFlashSaveModeUserData(void)
{
    BYTE ucFifoIndex = 0;
    BYTE ucSlotIndex = 0;

    for(ucFifoIndex = 0; ucFifoIndex < UserCommonFlashGetMaxFifoGroupCnt(); ucFifoIndex++)
    {
        if(UserCommonFlashLoadModeUserModeNumberData(ucFifoIndex) == g_stVGAModeUserData.ucModeNumber)
        {
            ucSlotIndex = ucFifoIndex;
            break;
        }
    }

    if(ucFifoIndex >= UserCommonFlashGetMaxFifoGroupCnt())
    {
        ucSlotIndex = UserCommonFlashVGAFifoModeIndexOffsetInc(1);
    }

    // Save mode user data
    UserInterfaceFlashSaveItem(_FLASH_ITEMID_MODE_USER_DATA + ucSlotIndex, (BYTE*)(&g_stVGAModeUserData), sizeof(VGAModeUserDataType));
}

BYTE UserCommonFlashLoadModeUserModeNumberData(BYTE ucSlotIndex)
{
    BYTE ucModeNumber = 0xFF;

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_MODE_USER_DATA + ucSlotIndex, pData, sizeof(VGAModeUserDataType)) == _TRUE)
    {
        ucModeNumber = ((VGAModeUserDataType*)pData)->ucModeNumber;
    }

    return ucModeNumber;
}

void UserCommonFlashRestoreModeUserData(void)
{
    VGAModeUserDataType stModeData = {0};

    // Default mode user data is all 0xFF
    for(g_stSystemData.ucModeSlotIndex = 0; g_stSystemData.ucModeSlotIndex < _MODE_SLOT_AMOUNT; g_stSystemData.ucModeSlotIndex++)
    {
        if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_MODE_USER_DATA + g_stSystemData.ucModeSlotIndex, pData, 1) == _TRUE)
        {
            memset(&stModeData, 0xFF, _DATA_ITEM_LENGTH - 2);
            UserInterfaceFlashSaveItem(_FLASH_ITEMID_MODE_USER_DATA + g_stSystemData.ucModeSlotIndex, (BYTE*)(&stModeData), sizeof(VGAModeUserDataType)) ;
        }
    }

    // Restore slot index
    g_stSystemData.ucModeSlotIndex = 0;
}

BYTE UserCommonFlashVGAFifoModeIndexOffsetInc(BYTE ucStep)
{
	BYTE ucMNumber = 0xFF;
    BYTE ucInx = 0;

	// g_stVGAModeUserData will be clear
	memset(&pData, 0xFF, _DATA_ITEM_LENGTH);

	for(ucInx = 0; ucInx < _MODE_SLOT_AMOUNT; ucInx++)
	{
		g_stSystemData.ucModeSlotIndex = (g_stSystemData.ucModeSlotIndex + ucStep) % _MODE_SLOT_AMOUNT;

		ucMNumber= UserCommonFlashLoadModeUserModeNumberData(g_stSystemData.ucModeSlotIndex);

		if((UserCommonModeSearchCheckPresetModeTable(ucMNumber)== _TRUE))
		{
		    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_MODE_USER_DATA + g_stSystemData.ucModeSlotIndex, pData, sizeof(VGAModeUserDataType)) == _TRUE)
		    {
    			if((((VGAModeUserDataType*)pData)->b1IsPresetMode == _PRESET_MODE_TYPE))
    			{
    				DebugMessageAnalog("4. Match presetmode", ucMNumber);
    				continue;
    			}
    			else
    			{
    				break;		
    		    }
		    }		
		}
		else
		{
			break;
		}
	}	

    return g_stSystemData.ucModeSlotIndex;
}

BYTE UserCommonFlashGetMaxFifoGroupCnt(void)
{
    return _MODE_SLOT_AMOUNT;
}

void UserCommonFlashLoadADCSetting(EnumColorSpace enumColorFormat)
{
    if(enumColorFormat == _COLOR_SPACE_RGB)
    {
        if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_VGA_ADC_DATA, pData, sizeof(StructAdcDataType)) == _TRUE)
        {
            memcpy(&g_stAdcData, pData, sizeof(StructAdcDataType));
        }
        else
        {
            g_stAdcData = g_stADCRgbDefaultData;
        }
    }
#if(_YPBPR_SUPPORT == _ON)
    else if(enumColorFormat == _COLOR_SPACE_YPBPR)
    {
        if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_YPBPR_ADC_DATA, pData, sizeof(StructAdcDataType)) == _TRUE)
        {
            memcpy(&g_stAdcData, pData, sizeof(StructAdcDataType));
        }
        else
        {
            g_stAdcData = g_stADCYpbprDefaultData;
        }
    }
#endif    

    UserInterfaceCheckNVRamData(_CHECK_ADC_LOAD);
}

void UserCommonFlashSaveADCSetting(EnumColorSpace enumColorFormat)
{
    if(UserInterfaceCheckNVRamData(_CHECK_ADC_SAVE) == _FAIL)
    {
        return;
    }
        
    if(enumColorFormat == _COLOR_SPACE_RGB)
    {
        UserInterfaceFlashSaveItem(_FLASH_ITEMID_VGA_ADC_DATA, (BYTE*)(&g_stAdcData), sizeof(StructAdcDataType));
    }
#if(_YPBPR_SUPPORT == _ON)
    else if(enumColorFormat == _COLOR_SPACE_YPBPR)
    {
        UserInterfaceFlashSaveItem(_FLASH_ITEMID_YPBPR_ADC_DATA, (BYTE*)(&g_stAdcData), sizeof(StructAdcDataType));
    }
#endif    
}

void UserCommonFlashRestoreADCSetting(void)
{
    g_stAdcData = g_stADCRgbDefaultData;

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_VGA_ADC_DATA, pData, 1) == _TRUE)
    {
        UserCommonFlashSaveADCSetting(_COLOR_SPACE_RGB);
    }

#if(_YPBPR_SUPPORT == _ON)
    g_stAdcData = g_stADCYpbprDefaultData;

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_YPBPR_ADC_DATA, pData, 1) == _TRUE)
    {
        UserCommonFlashSaveADCSetting(_COLOR_SPACE_YPBPR);
    }
#endif
}
#endif

#if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
//--------------------------------------------------
// Description  : Get HDCP Bksv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonFlashGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray)
{
    UserCommonFlashRead(_EEPROM_HDCP_KEY_FLASH_BANK, (_EEPROM_HDCP_KEY_ADDRESS + ucSubAddr), ucLength, pReadArray);
}

//--------------------------------------------------
// Description  : Get HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonFlashGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{
    UserCommonFlashRead(_EEPROM_HDCP_KEY_FLASH_BANK, (_EEPROM_HDCP_KEY_ADDRESS + 5 + (usSubAddr)), usLength, pReadArray);
}

#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
void UserCommonFlashRestoreHDCP(WORD usAddr, BYTE ucLength, BYTE* pucBuf)
{
    BYTE ucIndex = 0;
    BYTE ucDataArry[16] = {0};

    if(usAddr == 0)
    {
        UserCommonFlashErasePage(_EEPROM_HDCP_KEY_FLASH_BANK, _MISC_PAGE);

#if(_EMBEDDED_DDCRAM_A0_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonFlashWrite(_EEPROM_HDCP_KEY_FLASH_BANK, _EEPROM_EDID_A0_ADDRESS, _EMBEDDED_DDCRAM_A0_SIZE, MCU_DDCRAM_A0);
#endif

#if(_EMBEDDED_DDCRAM_D0_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonFlashWrite(_EEPROM_HDCP_KEY_FLASH_BANK, _EEPROM_EDID_D0_ADDRESS, _EMBEDDED_DDCRAM_D0_SIZE, MCU_DDCRAM_D0);
#endif

#if(_EMBEDDED_DDCRAM_D1_LOCATION == _EDID_TABLE_LOCATION_SYSTEM_EEPROM)
        UserCommonFlashWrite(_EEPROM_HDCP_KEY_FLASH_BANK, _EEPROM_EDID_D1_ADDRESS, _EMBEDDED_DDCRAM_D1_SIZE, MCU_DDCRAM_D1);
#endif
    }

    UserCommonFlashWrite(_EEPROM_HDCP_KEY_FLASH_BANK, _EEPROM_HDCP_KEY_ADDRESS + usAddr, ucLength, pucBuf);
}
#endif // End of #if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
#endif // End of #if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)

#endif // End of #elif(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)

#if((_FLASH_ACCESS_FUNCTION_SUPPORT == _ON) || (_FLASH_WR_PROTECT ==_ON))
//--------------------------------------------------
// Description  : Auto detect current flash type
// Input Value  : None
// Output Value : Detected flash type index
//--------------------------------------------------
void UserCommonFlashDetectFlashType(void)
{
    bit bMatchedFlashType = _FALSE;
    BYTE ucIndex = 0;
    BYTE ucIDCheck1PassFlashCount = 0;
    BYTE pucIDArry[3] = {0};

    // ID check 1, use 0x9F/0x90/0xAB op code base on flash spec
    for(ucIndex = 0; ucIndex < _FLASH_TOTAL_COUNT; ucIndex++)
    {
        if(UserCommonFlashReadFlashIDCode(tFlashInformation[ucIndex].ucIDCheck1OpCode, pucIDArry))
        {
            // ID = 0 means ignore
            if((tFlashInformation[ucIndex].ucIDCheck1_ID0 == 0x00) || (pucIDArry[0] == tFlashInformation[ucIndex].ucIDCheck1_ID0))
            {
                if((tFlashInformation[ucIndex].ucIDCheck1_ID1 == 0x00) || (pucIDArry[1] == tFlashInformation[ucIndex].ucIDCheck1_ID1))
                {
                    if((tFlashInformation[ucIndex].ucIDCheck1_ID2 == 0x00) || (pucIDArry[2] == tFlashInformation[ucIndex].ucIDCheck1_ID2))
                    {
                        // Save matched flash type index to buffer
                        pData[ucIDCheck1PassFlashCount] = ucIndex;
                        ucIDCheck1PassFlashCount++;
                    }
                }
            }
        }
        else
        {
            // Read ID code failed
            g_ucFlashType = _FLASH_DEFAULT_TYPE;
            return;
        }
    }

    // Find only one matched flash type in ID check 1
    if(ucIDCheck1PassFlashCount == 1)
    {
        g_ucFlashType = pData[0];
        return;
    }
    // Find more than one flash type in ID check 1
    else if(ucIDCheck1PassFlashCount > 1)
    {
        // Find more than 1 types in ID check 1, use ID check 2 to choose
        for(ucIndex = 0; ucIndex < ucIDCheck1PassFlashCount; ucIndex++)
        {
            // ID check 2
            if(UserCommonFlashReadFlashIDCode(tFlashInformation[pData[ucIndex]].ucIDCheck2OpCode, pucIDArry))
            {
                // ID = 0 means ignore
                if((tFlashInformation[pData[ucIndex]].ucIDCheck2_ID0 != 0x00) && (pucIDArry[0] != tFlashInformation[pData[ucIndex]].ucIDCheck2_ID0))
                {
                    continue;
                }

                if((tFlashInformation[pData[ucIndex]].ucIDCheck2_ID1 != 0x00) && (pucIDArry[1] != tFlashInformation[pData[ucIndex]].ucIDCheck2_ID1))
                {
                    continue;
                }

                if((tFlashInformation[pData[ucIndex]].ucIDCheck2_ID2 != 0x00) && (pucIDArry[2] != tFlashInformation[pData[ucIndex]].ucIDCheck2_ID2))
                {
                    continue;
                }

                break;
            }
        }

        if(ucIndex >= ucIDCheck1PassFlashCount)
        {
            g_ucFlashType = pData[0];
            return;
        }
        else
        {
            g_ucFlashType = pData[ucIndex];

#if(_FLASH_TYPE_W25X20A_OR_W25X21CL == _FLASH_W25X20A)   
            if(g_ucFlashType == _FLASH_W25X21CL)
            {
                g_ucFlashType = _FLASH_W25X20A;
            }
#else
            if(g_ucFlashType == _FLASH_W25X20A)
            {
                g_ucFlashType = _FLASH_W25X21CL;
            }
#endif

#if(_FLASH_TYPE_W25X40CL_OR_W25X41CL == _FLASH_W25X40CL)   
            if(g_ucFlashType == _FLASH_W25X41CL)
            {
                g_ucFlashType = _FLASH_W25X40CL;
            }
#else
            if(g_ucFlashType == _FLASH_W25X40CL)
            {
                g_ucFlashType = _FLASH_W25X41CL;
            }
#endif

#if(_FLASH_TYPE_EN25F20A_OR_EN25F20 == _FLASH_EN25F20A)   
            if(g_ucFlashType == _FLASH_EN25F20)
            {
                g_ucFlashType = _FLASH_EN25F20A;
            }
#else
            if(g_ucFlashType == _FLASH_EN25F20A)
            {
                g_ucFlashType = _FLASH_EN25F20;
            }
#endif

#if(_FLASH_TYPE_GD25Q40B_OR_GD25Q41 ==_FLASH_GD25Q41)

            if(g_ucFlashType == _FLASH_GD25Q40B)
            {
                g_ucFlashType = _FLASH_GD25Q41;
            }
#else
            if(g_ucFlashType == _FLASH_GD25Q41)
            {
                g_ucFlashType = _FLASH_GD25Q40B;
            }
#endif
            return;
        }
    }
    else
    {
        // Do not find 1 type in ID check 1
        g_ucFlashType = _FLASH_DEFAULT_TYPE;
        return;
    }

    g_ucFlashType = _FLASH_DEFAULT_TYPE;
}

//--------------------------------------------------
// Description  : Read flash ID code
// Input Value  : ucRDIDOPCode: Read ID code op code
//                pucIDArry: Saved the ID code read from flash
// Output Value : _TRUE for read success, else return _FALSE
//--------------------------------------------------
bit UserCommonFlashReadFlashIDCode(BYTE ucRDIDOPCode, BYTE *pucIDArry)
{
    BYTE ucIndex = 0;
    BYTE ucTryCount = 10;
    BYTE ucID0 = 0;
    BYTE ucID1 = 0;
    BYTE ucID2 = 0;

    switch(ucRDIDOPCode)
    {
        case 0x9F:

            //////////////////////////////////////////////////////////////////////////
            // Use JEDECID Instruction to get Flash Manufacture ID, Device ID       //
            //////////////////////////////////////////////////////////////////////////
            MCU_COMM_INST_EN_FF60 = 0x46;
            MCU_COMM_OP_CODE_FF61 = ucRDIDOPCode;
            MCU_COMM_INST_EN_FF60 = 0x47;
            pucIDArry[0] = MCU_COMM_INST_READ_P0_FF67;
            pucIDArry[1] = MCU_COMM_INST_READ_P1_FF68;
            pucIDArry[2] = MCU_COMM_INST_READ_P2_FF69;

            // Repeatedly read flash ID code and check flash ID code data between twice RDID instructions
            for(ucIndex = 0; ucIndex < ucTryCount; ucIndex++)
            {
                MCU_COMM_INST_EN_FF60 = 0x46;
                MCU_COMM_OP_CODE_FF61 = ucRDIDOPCode;
                MCU_COMM_INST_EN_FF60 = 0x47;
                ucID0 = MCU_COMM_INST_READ_P0_FF67;
                ucID1 = MCU_COMM_INST_READ_P1_FF68;
                ucID2 = MCU_COMM_INST_READ_P2_FF69;

                if((pucIDArry[0] == ucID0) && (pucIDArry[1] == ucID1) && (pucIDArry[2] == ucID2))
                {
                    break;
                }
                else
                {
                    pucIDArry[0] = ucID0;
                    pucIDArry[1] = ucID1;
                    pucIDArry[2] = ucID2;
                }
            }

            if(ucIndex >= ucTryCount)
            {
                return _FALSE;
            }

            break;

        case 0x90:
        case 0xAB:

            //////////////////////////////////////////////////////////////////////////////////
            // Use RDID(0x90/0xAB) Instruction first to get Flash Manufacture ID, Device ID //
            //////////////////////////////////////////////////////////////////////////////////
            MCU_COMM_INST_EN_FF60 = 0x5E;
            MCU_COMM_OP_CODE_FF61 = ucRDIDOPCode;
            MCU_FLASH_PROG_ISP0_FF64 = 0x00;
            MCU_FLASH_PROG_ISP1_FF65 = 0x00;
            MCU_FLASH_PROG_ISP2_FF66 = 0x00;
            MCU_COMM_INST_EN_FF60 = 0x5F;

            pucIDArry[0] = MCU_COMM_INST_READ_P0_FF67;
            pucIDArry[1] = MCU_COMM_INST_READ_P1_FF68;
            pucIDArry[2] = MCU_COMM_INST_READ_P2_FF69;

            for(ucIndex = 0; ucIndex < ucTryCount; ucIndex++)
            {
                MCU_COMM_INST_EN_FF60 = 0x5E;
                MCU_COMM_OP_CODE_FF61 = ucRDIDOPCode;
                MCU_FLASH_PROG_ISP0_FF64 = 0x00;
                MCU_FLASH_PROG_ISP1_FF65 = 0x00;
                MCU_FLASH_PROG_ISP2_FF66 = 0x00;
                MCU_COMM_INST_EN_FF60 = 0x5F;

                ucID0 = MCU_COMM_INST_READ_P0_FF67;
                ucID1 = MCU_COMM_INST_READ_P1_FF68;
                ucID2 = MCU_COMM_INST_READ_P2_FF69;

                if((pucIDArry[0] == ucID0) && (pucIDArry[1] == ucID1) && (pucIDArry[2] == ucID2))
                {
                    break;
                }
                else
                {
                    pucIDArry[0] = ucID0;
                    pucIDArry[1] = ucID1;
                    pucIDArry[2] = ucID2;
                }
            }

            if(ucIndex >= ucTryCount)
            {
                return _FALSE;
            }

            break;

        default:
            break;
    }

    return _TRUE;
}


#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Write enable process for serial flash
// Input Value  : ucBank: bank index
//                ucPage: page index (0 ~ 15)
// Output Value : Return _TURE if succeed, else return _FALSE
//--------------------------------------------------
void UserCommonFlashWREN(BYTE ucBank, BYTE ucPage)
{
    BYTE ucWRSR = 0x00;
    BYTE ucWRSR1 = 0x00;

    // Clear watch dog
    MCU_WATCHDOG_TIMER_FFEA |= 0x40;

    switch(g_ucFlashType)
    {
        case _FLASH_PM25LV020:
        case _FLASH_PM25LD020:
	    case _FLASH_PM25LQ020A:
        case _FLASH_PM25LQ040B:
        case _FLASH_PM25LQ080:
            // Unprotect Enable
            MCU_COMM_INST_EN_FF60 = 0x78;
            MCU_COMM_OP_CODE_FF61 = tFlashInformation[g_ucFlashType].ucWRENOpCode;
            MCU_FLASH_PROG_ISP0_FF64 = ucBank;
            MCU_FLASH_PROG_ISP1_FF65 = (BYTE)((ucPage << 4) & 0xF0);
            MCU_FLASH_PROG_ISP2_FF66 = 0x00;
            MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;
            break;

        case _FLASH_W25X20A:
            switch(ucBank)
            {
                case 0:
                case 1:
                    ucWRSR = 0x0A;
                    break;

                case 2:
                case 3:
                    ucWRSR = 0x2A;
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }
            
            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_FM25F04:
            switch(ucBank)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    ucWRSR = 0x02;
                    break;

                case 4:
                case 5:
                    ucWRSR = 0x1A;
                    break;

                case 6:
                    ucWRSR = 0x16;
                    break;
                    
                case 7:
                    ucWRSR = 0x12;
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }
            
            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_N25S40:
            switch(ucBank)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    ucWRSR = 0x0E;
                    break;

                case 4:
                case 5:
                    ucWRSR = 0x3A;
                    break;

                case 6:
                    ucWRSR = 0x36;
                    break;
                    
                case 7:
                    ucWRSR = 0x32;
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }
            
            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_MX25L2025:
            switch(ucBank)
            {
                case 0:
                case 1:
                    ucWRSR = 0x0A;
                    break;

                case 2:
                    ucWRSR = 0x06;
                    break;

                case 3:
                    ucWRSR = 0x02;
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

    	case _FLASH_MX25L4006E:
    	case _FLASH_A25L040:
    		switch(ucBank)
    		{
    			case 0:
    			case 1:
    			case 2:
    			case 3:
    				ucWRSR = 0x0E;
    				break;
    			case 4:
    			case 5:
    				ucWRSR = 0x0A;
    				break;
    			case 6:
    				ucWRSR = 0x06;
    				break;
    			case 7:
    				ucWRSR = 0x02;
    				break;
    			default:
    				ucWRSR = 0x02;
    				break;
    		}
    		
            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_W25Q80BV:
            switch(ucBank)
            {
                case 0:
                    if(ucPage == 0)
                    {
                        ucWRSR = 0x66;
                    }
                    else if(ucPage == 1)
                    {
                        ucWRSR = 0x6A;
                    }
                    else if((ucPage == 2) || (ucPage == 3))
                    {
                        ucWRSR = 0x6E;
                    }
                    else if((ucPage >= 4) && (ucPage <= 7))
                    {
                        ucWRSR = 0x72;
                    }
                    else
                    {
                        ucWRSR = 0x26;
                    }
                    ucWRSR1 = 0x40;                    
                    break;
                case 1:
                    ucWRSR = 0x2A;
                    ucWRSR1 = 0x40;                    
                    break;
                case 2:
                case 3:
                    ucWRSR = 0x2E;
                    ucWRSR1 = 0x40;
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    ucWRSR = 0x32;
                    ucWRSR1 = 0x40;
                    break;
                case 8:
                case 9:
                case 10:
                case 11:
                    ucWRSR = 0x12;
                    ucWRSR1 = 0x40;
                    break;
                case 12:
                case 13:
                    ucWRSR = 0x0E;
                    ucWRSR1 = 0x40;
                    break;
                case 14:
                    ucWRSR = 0x0A;
                    ucWRSR1 = 0x40;                    
                    break;
                case 15:
                    if(ucPage == 15)
                    {
                        ucWRSR = 0x46;
                    }
                    else if(ucPage == 14)
                    {
                        ucWRSR = 0x4A;
                    }
                    else if((ucPage == 12) || (ucPage == 13))
                    {
                        ucWRSR = 0x4E;
                    }
                    else if((ucPage >= 8) && (ucPage <= 11))
                    {
                        ucWRSR = 0x52;
                    }
                    else
                    {
                        ucWRSR = 0x06;
                    }
                    ucWRSR1 = 0x40;                    
                    break;
                default:
                    ucWRSR = 0x02;
                    ucWRSR1 = 0x00;                    
                    break;
            }
            // Set unprotect status register
            UserCommonFlashSet2ByteWRSR(ucWRSR, ucWRSR1, _FALSE);
            break;
            
        case _FLASH_EN25F20:
            switch(ucBank)
            {
                case 0:
                case 1:
                    ucWRSR = 0x0A;
                    break;

                case 2:
                    ucWRSR = 0x06;
                    break;

                case 3:
                    if((ucPage == 12) || (ucPage == 13))
                    {
                        ucWRSR = 0x16;
                    }
                    else if((ucPage == 14) || (ucPage == 15))
                    {
                        ucWRSR = 0x1A;
                    }
                    else
                    {
                        ucWRSR = 0x12;
                    }
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_W25X21CL:
            switch(ucBank)
            {
                case 0:
                case 1:
                case 2:
                    ucWRSR = 0x3E;
                    break;

                case 3:
                    if(ucPage < 10)
                    {
                        ucWRSR = 0x3E;
                    }
                    else if((ucPage >= 10) && (ucPage <= 11))
                    {
                        ucWRSR = 0x5E;
                    }
                    else if((ucPage >= 12) && (ucPage <= 13))
                    {
                        ucWRSR = 0x6E;
                    }
                    else if(ucPage == 14)
                    {
                        ucWRSR = 0x76;
                    }
                    else if(ucPage == 15)
                    {
                        ucWRSR = 0x7A;
                    }
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Use general unprotect if BP4(bit6) do not need unlock, else use burst write to unlock BP4
            if((ucWRSR & _BIT6) == _BIT6)
            {
                // Set SRWD = 0
                UserCommonFlashSetWRSR(ucWRSR & 0x7F, _FALSE);
                // Set unprotect register
                UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            }
            else
            {
                // Special unprotect area is not supported
            }
            break;
        
        case _FLASH_MX25L2026D:
            switch(ucBank)
            {
                case 0:
                case 1:
                case 2:
                    ucWRSR = 0x3E;
                    break;

                case 3:
                    if(ucPage < 10)
                    {
                        ucWRSR = 0x3E;
                    }
                    else if((ucPage >= 10) && (ucPage <= 11))
                    {
                        ucWRSR = 0x5E;
                    }
                    else if((ucPage >= 12) && (ucPage <= 13))
                    {
                        ucWRSR = 0x6E;
                    }
                    else if(ucPage == 14)
                    {
                        ucWRSR = 0x76;
                    }
                    else if(ucPage == 15)
                    {
                        ucWRSR = 0x7A;
                    }
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Use general unprotect if BP4(bit6) do not need unlock, else use burst write to unlock BP4
            if((ucWRSR & _BIT6) == _BIT6)
            {
                // Set SRWD = 0
                UserCommonFlashSetWRSR(ucWRSR & 0x7F, _FALSE);
                // Set unprotect register
                UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            }
            else
            {
                // Special unprotect area is not supported
            }
            break;

        case _FLASH_MX25L4026D:
            switch(ucBank)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    ucWRSR = 0x3E;
                    break;

                case 7:
                    if(ucPage < 10)
                    {
                        ucWRSR = 0x3E;
                    }
                    else if((ucPage >= 10) && (ucPage <= 11))
                    {
                        ucWRSR = 0x5E;
                    }
                    else if((ucPage >= 12) && (ucPage <= 13))
                    {
                        ucWRSR = 0x6E;
                    }
                    else if(ucPage == 14)
                    {
                        ucWRSR = 0x76;
                    }
                    else if(ucPage == 15)
                    {
                        ucWRSR = 0x7A;
                    }
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Use general unprotect if BP4(bit6) do not need unlock, else use burst write to unlock BP4
            if((ucWRSR & _BIT6) == _BIT6)
            {
                // Set SRWD = 0
                UserCommonFlashSetWRSR(ucWRSR & 0x7F, _FALSE);
                // Set unprotect register
                UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            }
            else
            {
                // Special unprotect area is not supported
            }
            break;

        case _FLASH_SST25LF020A:
            UserCommonFlashSetWRSR(tFlashInformation[g_ucFlashType].ucUnprotectWRSR, _FALSE);
            break;

        case _FLASH_W25X41CL:
            if((ucBank < 7) || ((ucBank == 7) && (ucPage < 10)))
            {
                ucWRSR = 0x3E;
            }
            else if(ucBank == 7)
            {
                if((ucPage >= 10) && (ucPage <= 11))
                {
                    ucWRSR = 0x5E;
                }
                else if((ucPage >= 12) && (ucPage <= 13))
                {
                    ucWRSR = 0x6E;
                }
                else if(ucPage == 14)
                {
                    ucWRSR = 0x76;
                }
                else if(ucPage == 15)
                {
                    ucWRSR = 0x7A;
                }
            }
            else
            {
                ucWRSR = 0x02;
            }

            // Use general unprotect if BP4(bit6) do not need unlock, else use burst write to unlock BP4
            if((ucWRSR & _BIT6) == _BIT6)
            {
                // Set SRWD = 0
                UserCommonFlashSetWRSR(ucWRSR & 0x7F, _FALSE);
                // Set unprotect register
                UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            }
            else
            {
                // Special unprotect area is not supported
            }
            break;

        case _FLASH_W25X40CL:
            switch(ucBank)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    ucWRSR = 0x0E;
                    break;

                case 4:
                case 5:
                case 6:
                case 7:
                    ucWRSR = 0x2E;
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }
            
            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_EN25F20A:
            switch(ucBank)
            {
                case 0:
                    // Protect Bank 1~3
                    ucWRSR = 0x0E; 
                    break;
                    
                case 1:
                    // Protect Bank 2~3
                    ucWRSR = 0x0A; 
                    break;
                    
                case 2:
                    // Protect Bank 0~1
                    ucWRSR = 0x2A; 
                    break;

                case 3:
                    // Protect Bank 0~2
                    ucWRSR = 0x2E; 
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }
                    
            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;
            
        case _FLASH_EN25F40A:
            switch(ucBank)
            {
                case 0:
                    // Protect Bank 1~7
                    ucWRSR = 0x16; 
                    break;
                    
                case 1:
                    // Protect Bank 2~7
                    ucWRSR = 0x12; 
                    break;
                    
                case 2:
                case 3:
                    // Protect Bank 4~7
                    ucWRSR = 0x0E; 
                    break;

                case 4:
                case 5:
                    // Protect Bank 0~3
                    ucWRSR = 0x2E; 
                    break;
                    
                case 6:
                    // Protect Bank 0~5
                    ucWRSR = 0x32; 
                    break;

                case 7:
                    // Protect Bank 0~6
                    ucWRSR = 0x36; 
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_EN25Q40A:
            switch(ucBank)
            {
                case 0:
                    // Protect Bank 1~7
                    ucWRSR = 0x16; 
                    break;
                    
                case 1:
                    // Protect Bank 2~7
                    ucWRSR = 0x12; 
                    break;
                    
                case 2:
                case 3:
                    // Protect Bank 4~7
                    ucWRSR = 0x0E; 
                    break;

                case 4:
                case 5:
                    // Protect Bank 0~3
                    ucWRSR = 0x2E; 
                    break;
                    
                case 6:
                    // Protect Bank 0~5
                    ucWRSR = 0x32; 
                    break;

                case 7:
                    // Protect Bank 0~6
                    ucWRSR = 0x36; 
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_EN25Q80:
            switch(ucBank)
            {
                case 0:
                case 1:                    
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    // Protect Bank None
                    ucWRSR = 0x02; 
                    break;

                case 12:
                case 13:
                    // Protect Bank 0~11
                    ucWRSR = 0x1A; 
                    break;

                case 14:
                    // Protect Bank 0~13
                    ucWRSR = 0x16; 
                    break;

                case 15:
                    if((ucPage >= 0) && (ucPage <= 7))
                    {
                        // Protect Sector 0~239
                        ucWRSR = 0x12; 
                    }
                    else if((ucPage > 7) && (ucPage <=11))
                    {
                        // Protect Sector 0~247
                        ucWRSR = 0x0E; 
                    }
                    else if((ucPage > 11) && (ucPage <=13))
                    {
                        // Protect Sector 0~251
                        ucWRSR = 0x0A; 
                    }
                    else if((ucPage > 13) && (ucPage <=15))
                    {
                        // Protect Sector 0~253
                        ucWRSR = 0x06; 
                    }                    
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;

        case _FLASH_GD25Q80B:
            switch(ucBank)
            {
                case 0:
                    if(ucPage == 0)
                    {
                        // Protect Sector 1~255
                        ucWRSR = 0x66; 
                    }
                    else if(ucPage == 1)
                    {
                        // Protect Sector 2~255
                        ucWRSR = 0x6A; 
                    }
                    else if((ucPage == 2) || (ucPage == 3))
                    {
                        // Protect Sector 4~255
                        ucWRSR = 0x6E; 
                    }
                    else if((ucPage >= 4) && (ucPage <= 7))
                    {
                        // Protect Sector 8~255
                        ucWRSR = 0x72; 
                    }
                    else
                    {
                        // Protect Sector 16~255
                        ucWRSR = 0x26; 
                    }
                    ucWRSR1 = 0x40;                    
                    break;
                case 1:
                    // Protect Bank 2~15
                    ucWRSR = 0x2A; 
                    ucWRSR1 = 0x40;                    
                    break;
                case 2:
                case 3:
                    // Protect Bank 4~15
                    ucWRSR = 0x2E; 
                    ucWRSR1 = 0x40;
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    // Protect Bank 8~15
                    ucWRSR = 0x32; 
                    ucWRSR1 = 0x40;
                    break;
                case 8:
                case 9:
                case 10:
                case 11:
                    // Protect Bank 0~7
                    ucWRSR = 0x12; 
                    ucWRSR1 = 0x40;
                    break;
                case 12:
                case 13:
                    // Protect Bank 0~11
                    ucWRSR = 0x0E; 
                    ucWRSR1 = 0x40;
                    break;
                case 14:
                    // Protect Bank 0~13
                    ucWRSR = 0x0A; 
                    ucWRSR1 = 0x40;                    
                    break;
                case 15:
                    if(ucPage == 15)
                    {
                        // Protect Sector 0~254
                        ucWRSR = 0x46; 
                    }
                    else if(ucPage == 14)
                    {
                        // Protect Sector 0~253
                        ucWRSR = 0x4A; 
                    }
                    else if((ucPage == 12) || (ucPage == 13))
                    {
                        // Protect Sector 0~251
                        ucWRSR = 0x4E; 
                    }
                    else if((ucPage >= 8) && (ucPage <= 11))
                    {
                        // Protect Sector 0~247
                        ucWRSR = 0x52; 
                    }
                    else
                    {
                        // Protect Sector 0~239
                        ucWRSR = 0x06; 
                    }
                    ucWRSR1 = 0x40;                    
                    break;
                default:
                    ucWRSR = 0x02;
                    ucWRSR1 = 0x00;                    
                    break;
            }
            // Set unprotect status register
            UserCommonFlashSet2ByteWRSR(ucWRSR, ucWRSR1, _FALSE);
            break;

        case _FLASH_GD25M21B:
        case _FLASH_GD25M41B:
            //Sector Unlock Enable
            MCU_COMM_INST_EN_FF60 = 0x78;
            MCU_COMM_OP_CODE_FF61 = 0x4C;
            MCU_FLASH_PROG_ISP0_FF64 = ucBank;
            MCU_FLASH_PROG_ISP1_FF65 = (BYTE)((ucPage << 4) & 0xF0);
            MCU_FLASH_PROG_ISP2_FF66 = 0x00;
            MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;
            break;

    	case _FLASH_MX25L8006E:
    	case _FLASH_MX25V8035F:
    		switch(ucBank)
    		{
    			case 0:
    			case 1:
    			case 2:
    			case 3:
    			case 4:
    			case 5:
    			case 6:
    			case 7:
    			    // Protect Bank 8~15
    				ucWRSR = 0x12; 
    				break;
    			case 8:
    			case 9:
    			case 10:
    			case 11:
    			    // Protect Bank 12~15
    				ucWRSR = 0x0E; 
    				break;
    			case 12:
    			case 13:
    			    // Protect Bank 14~15
    				ucWRSR = 0x0A; 
    				break;
    			case 14:
    			    // Protect Bank 15
    				ucWRSR = 0x06; 
    				break;
    			case 15:
    			    // Protect Bank None
    				ucWRSR = 0x02; 
    				break; 				
    			default:
    				ucWRSR = 0x02;
    				break;
    		}
    		
            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;


        case _FLASH_GD25Q40B:
        case _FLASH_GD25Q41:
            switch(ucBank)
            {
                case 0:
                    if(ucPage == 0)
                    {
                        // Protect Sector 1~127
                        ucWRSR = 0x66; 
                    }
                    else if(ucPage == 1)
                    {
                        // Protect Sector 2~127
                        ucWRSR = 0x6A; 
                    }
                    else if((ucPage == 2) || (ucPage == 3))
                    {
                        // Protect Sector 4~127
                        ucWRSR = 0x6E; 
                    }
                    else if((ucPage >= 4) && (ucPage <= 7))
                    {
                        // Protect Sector 8~127
                        ucWRSR = 0x72; 
                    }
                    else
                    {
                        // Protect Sector 16~127
                        ucWRSR = 0x26; 
                    }
                    ucWRSR1 = 0x40;                    
                    break;
                case 1:
                    // Protect Bank 2~7
                    ucWRSR = 0x2A; 
                    ucWRSR1 = 0x40;                    
                    break;
                case 2:
                case 3:
                    // Protect Bank 4~7
                    ucWRSR = 0x2E; 
                    ucWRSR1 = 0x40;
                    break;
                case 4:
                case 5:
                    // Protect Bank 0~3
                    ucWRSR = 0x0E; 
                    ucWRSR1 = 0x40;
                    break;
                case 6:
                    // Protect Bank 0~5
                    ucWRSR = 0x0A; 
                    ucWRSR1 = 0x40;                    
                    break;
                case 7:
                    if(ucPage == 15)
                    {
                        // Protect Sector 0~126
                        ucWRSR = 0x46; 
                    }
                    else if(ucPage == 14)
                    {
                        // Protect Sector 0~125
                        ucWRSR = 0x4A; 
                    }
                    else if((ucPage == 12) || (ucPage == 13))
                    {
                        // Protect Sector 0~123
                        ucWRSR = 0x4E; 
                    }
                    else if((ucPage >= 8) && (ucPage <= 11))
                    {
                        // Protect Sector 0~119
                        ucWRSR = 0x52; 
                    }
                    else
                    {
                        // Protect Sector 0~111
                        ucWRSR = 0x06; 
                    }
                    ucWRSR1 = 0x40;                    
                    break;
                default:
                    ucWRSR = 0x02;
                    ucWRSR1 = 0x00;                    
                    break;
            }
            // Set unprotect status register
            UserCommonFlashSet2ByteWRSR(ucWRSR, ucWRSR1, _FALSE);
            break;
            
        case _FLASH_W25Q16DV:
        case _FLASH_GD25Q16C:
            switch(ucBank)
            {
                case 0:
                    if(ucPage == 0)
                    {
                        // Protect Sector 1~511
                        ucWRSR = 0x66;
                    }
                    else if(ucPage == 1)
                    {
                        // Protect Sector 2~511
                        ucWRSR = 0x6A;
                    }
                    else if((ucPage == 2) || (ucPage == 3))
                    {
                        // Protect Sector 4~511
                        ucWRSR = 0x6E;
                    }
                    else if((ucPage >= 4) && (ucPage <= 7))
                    {
                        // Protect Sector 8~511
                        ucWRSR = 0x72;
                    }
                    else
                    {
                        // Protect Sector 16~511
                        ucWRSR = 0x26; 
                    }
                    ucWRSR1 = 0x40;                    
                    break;
                    
                case 1:
                    // Protect Bank 2~31
                    ucWRSR = 0x2A; 
                    ucWRSR1 = 0x40;                   
                    break;
                    
                case 2:
                case 3:
                    // Protect Bank 4~31
                    ucWRSR = 0x2E; 
                    ucWRSR1 = 0x40;
                    break;
                    
                case 4:
                case 5:
                case 6:
                case 7:
                    // Protect Bank 8~31
                    ucWRSR = 0x32; 
                    ucWRSR1 = 0x40;
                    break;
                    
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                    // Protect Bank 16~31
                    ucWRSR = 0x36; 
                    ucWRSR1 = 0x40;
                    break;

                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                    // Protect Bank 0~15
                    ucWRSR = 0x16; 
                    ucWRSR1 = 0x40;
                    break;
                    
                case 24:
                case 25:
                case 26:
                case 27:
                    // Protect Bank 0~23
                    ucWRSR = 0x12; 
                    ucWRSR1 = 0x40;
                    break;
                    
                case 28:
                case 29:
                    // Protect Bank 0~27
                    ucWRSR = 0x0E; 
                    ucWRSR1 = 0x40;
                    break;
                    
                case 30:
                    // Protect Bank 0~29
                    ucWRSR = 0x0A; 
                    ucWRSR1 = 0x40;                    
                    break;
                    
                case 31:
                    if(ucPage == 15)
                    {
                        // Protect Sector 0~510
                        ucWRSR = 0x46;
                    }
                    else if(ucPage == 14)
                    {
                        // Protect Sector 0~509
                        ucWRSR = 0x4A;
                    }
                    else if((ucPage == 12) || (ucPage == 13))
                    {
                        // Protect Sector 0~507
                        ucWRSR = 0x4E;
                    }
                    else if((ucPage >= 8) && (ucPage <= 11))
                    {
                        // Protect Sector 0~503
                        ucWRSR = 0x52;
                    }
                    else
                    {
                        // Protect Sector 0~495
                        ucWRSR = 0x06; 
                    }
                    ucWRSR1 = 0x40;                    
                    break;
                    
                default:
                    ucWRSR = 0x02;
                    ucWRSR1 = 0x00;                    
                    break;
            }
            
            // Set unprotect status register
            UserCommonFlashSet2ByteWRSR(ucWRSR, ucWRSR1, _FALSE);
            break;
            
        case _FLASH_MX25L3233F:
            switch(ucBank)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                case 31:
                    // Protect Bank 32~63
                    ucWRSR = 0x1A; 
                    break;
                    
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                case 41:
                case 42:
                case 43:
                case 44:
                case 45:
                case 46:
                case 47:
                    // Protect Bank 48~63
                    ucWRSR = 0x16; 
                    break;
                    
                case 48:
                case 49:
                case 50:
                case 51:
                case 52: 
                case 53:
                case 54:
                case 55:
                    // Protect Bank 56~63
                    ucWRSR = 0x12; 
                    break;
                    
                case 56: 
                case 57:
                case 58:
                case 59:                    
                    // Protect Bank 60~63
                    ucWRSR = 0x0E; 
                    break;
                    
                case 60: 
                case 61:
                    // Protect Bank 62~63
                    ucWRSR = 0x0A; 
                    break;
                    
                case 62:    
                    // Protect Bank 63
                    ucWRSR = 0x06; 
                    break;
                
                default:
                    ucWRSR = 0x02;
                    break;                 
            }

            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;
            
        case _FLASH_EN25QH32A:    
            if((ucBank >= 0) && (ucBank <= 31))
            {
                // Protect Bank 32~63
                ucWRSR = 0x5A;                 
            }
            else if((ucBank >= 32) && (ucBank <= 63))
            {
                // Protect Bank 0~31
                ucWRSR = 0x7A;  
            }                    
            else
            {
                ucWRSR = 0x42;        
            }           
            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;
            
     case _FLASH_MX25V1635F:
            switch(ucBank)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                    // Protect Bank 16~31
                    ucWRSR = 0x16;
                    break;

                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                    // Protect Bank 0~15
                    ucWRSR = 0x2A;
                    break;

                case 24:
                case 25:
                case 26:
                case 27:
                    // Protect Bank 0~23
                    ucWRSR = 0x2E;
                    break;

                case 28:
                case 29:
                    // Protect Bank 0~27
                    ucWRSR = 0x32;
                    break;

                case 30:
                    // Protect Bank 0~29
                    ucWRSR = 0x36;
                    break;

                case 31:
                    // Protect Bank 0~30
                    ucWRSR = 0x3A;
                    break;

                default:
                    ucWRSR = 0x02;
                    break;
            }

            // Set unprotect status register
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break;
            
        default:
            UserCommonFlashSetWRSR(ucWRSR, _FALSE);
            break; 
            
    }

    // Program OP Code
    MCU_PROG_OP_CODE_FF6D = 0x02;
    // Disable Command OP code
    MCU_COMM_OP_CODE_FF61 = 0xFF;
}

//--------------------------------------------------
// Description  : Write disable process for serial flash
// Input Value  : None
// Output Value : Return _TURE if succeed, else return _FALSE
//--------------------------------------------------
void UserCommonFlashWRDis(void)
{
    // Clear watch dog
    MCU_WATCHDOG_TIMER_FFEA |= 0x40;

    if((g_ucFlashType == _FLASH_PM25LV020) || (g_ucFlashType == _FLASH_PM25LD020)
    || (g_ucFlashType == _FLASH_PM25LQ020A) || (g_ucFlashType == _FLASH_PM25LQ040B)
    || (g_ucFlashType == _FLASH_PM25LQ080))
    {
        // Sector Unprotect Disable
        UserCommonFlashSetWREN(tFlashInformation[g_ucFlashType].ucWRDisOpCode);
    }
    else if((g_ucFlashType == _FLASH_W25X20A) || (g_ucFlashType == _FLASH_MX25L2026D)
         || (g_ucFlashType == _FLASH_EN25F20) || (g_ucFlashType == _FLASH_MX25L2025)
         || (g_ucFlashType == _FLASH_MX25L4006E) || (g_ucFlashType == _FLASH_W25X21CL)
         || (g_ucFlashType == _FLASH_W25X41CL) || (g_ucFlashType == _FLASH_FM25F04)
         || (g_ucFlashType == _FLASH_N25S40) || (g_ucFlashType == _FLASH_A25L040)
         || (g_ucFlashType == _FLASH_W25Q80BV) || (g_ucFlashType == _FLASH_MX25L4026D) 
         || (g_ucFlashType == _FLASH_W25X40CL)|| (g_ucFlashType == _FLASH_EN25F20A)
         || (g_ucFlashType == _FLASH_EN25F40A) || (g_ucFlashType == _FLASH_EN25Q40A)
         || (g_ucFlashType == _FLASH_EN25Q80) || (g_ucFlashType == _FLASH_GD25Q80B) 
         || (g_ucFlashType == _FLASH_MX25L8006E) || (g_ucFlashType == _FLASH_GD25Q40B)
         || (g_ucFlashType == _FLASH_W25Q16DV) || (g_ucFlashType == _FLASH_GD25Q16C)
         || (g_ucFlashType == _FLASH_MX25L3233F) || (g_ucFlashType == _FLASH_EN25QH32A)
         || (g_ucFlashType ==_FLASH_MX25V8035F) || (g_ucFlashType ==_FLASH_MX25V1635F))

    {
        UserCommonFlashSetWRSR(tFlashInformation[g_ucFlashType].ucProtectWRSR, _FALSE);

        UserCommonFlashSetWREN(tFlashInformation[g_ucFlashType].ucWRDisOpCode);
    }
    else if(g_ucFlashType == _FLASH_SST25LF020A)
    {
        UserCommonFlashSetWRSR(tFlashInformation[g_ucFlashType].ucProtectWRSR, _TRUE);

        UserCommonFlashSetWREN(tFlashInformation[g_ucFlashType].ucWRDisOpCode);
    }
    else if((g_ucFlashType == _FLASH_GD25M21B) || (g_ucFlashType == _FLASH_GD25M41B))
    {
        //Sector Unlock Disable
        MCU_COMM_INST_EN_FF60 = 0x20;
        MCU_COMM_OP_CODE_FF61 = 0x4D;
        MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;

        UserCommonFlashSetWREN(tFlashInformation[g_ucFlashType].ucWRDisOpCode);    
    }

    else if (g_ucFlashType == _FLASH_GD25Q41)
    {
         UserCommonFlashSet2ByteWRSR(tFlashInformation[g_ucFlashType].ucProtectWRSR, 0x00, _FALSE);

         UserCommonFlashSetWREN(tFlashInformation[g_ucFlashType].ucWRDisOpCode);
    }
    else
    {
        UserCommonFlashSetWRSR(0xFF, _FALSE);
        UserCommonFlashSetWREN(0x04);        
    }

    // Disable Program OP code
    MCU_PROG_OP_CODE_FF6D = 0xFF;

    // Disable Command OP code
    MCU_COMM_OP_CODE_FF61 = 0xFF;
}
#endif


//--------------------------------------------------
// Description  : WREN instructions for serial flash
// Input Value  : ucOpCode: WREN instruction op code
// Output Value : None
//--------------------------------------------------
void UserCommonFlashSetWREN(BYTE ucOpCode)
{
    // WREN instructions
    MCU_COMM_INST_EN_FF60 = 0x20;
    MCU_COMM_OP_CODE_FF61 = ucOpCode;
    MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;

    // No need to polling, 8051 will halt when common instruction executes
}

//--------------------------------------------------
// Description  : WRSR instructions for Serial Flash
// Input Value  : ucWRSR: value written to Flash Status Reg
//                ucIsSST: _TRUE for SST Flash, _FALSE for other flash
// Output Value : None
//--------------------------------------------------
void UserCommonFlashSetWRSR(BYTE ucWRSR, bit bIsSST)
{
    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_DISABLE);

    //WRSR
    if(bIsSST == _TRUE)
    {
        MCU_COMM_INST_EN_FF60 = 0x88;
    }
    else
    {
        MCU_COMM_INST_EN_FF60 = 0x68;
    }

    MCU_COMM_OP_CODE_FF61 = 0x01;
    MCU_FLASH_PROG_ISP0_FF64 = ucWRSR;
    MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;

    // No need to polling, 8051 will halt when common instruction executes

    // Disable Command OP code
    MCU_COMM_OP_CODE_FF61 = 0xFF;

    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE);
}

//--------------------------------------------------
// Description  : WRSR instructions for Serial Flash
// Input Value  : ucWRSR1: value written to Flash Status Register-1
//              : ucWRSR2: value written to Flash Status Register-2
//                ucIsSST: _TRUE for SST Flash, _FALSE for other flash
// Output Value : None
//--------------------------------------------------
void UserCommonFlashSet2ByteWRSR(BYTE ucWRSR1, BYTE ucWRSR2, bit bIsSST)
{
    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_DISABLE);

    //WRSR
    if(bIsSST == _TRUE)
    {
        MCU_COMM_INST_EN_FF60 = 0x90;
    }
    else
    {
        MCU_COMM_INST_EN_FF60 = 0x70;
    }

    MCU_COMM_OP_CODE_FF61 = 0x01;
    MCU_FLASH_PROG_ISP0_FF64 = ucWRSR1;
    MCU_FLASH_PROG_ISP1_FF65 = ucWRSR2;
    MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;

    // No need to polling, 8051 will halt when common instruction executes

    // Disable Command OP code
    MCU_COMM_OP_CODE_FF61 = 0xFF;

    PCB_FLASH_WRITE_PROTECT(_FLASH_WRITE_PROTECT_ENABLE);
}


#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Erase page
// Input Value  : ucBank: bank index
//                ucPage: page index (0 ~ 15)
// Output Value : _TRUE for erase success and _FALSE for erase fail
//--------------------------------------------------
bit UserCommonFlashErasePage(BYTE ucBank, BYTE ucPage)
{
    BYTE ucBankBackup = 0;

    // The access bank is smaller than than the start bank
    if(ucBank < MCU_BANK_START_FFFD)
    {
        return _FALSE;
    }

    if(g_ucFlashType == _FLASH_UNDETECT)
    {
        UserCommonFlashDetectFlashType();
    }

    // Backup the current xdata bank index
    ucBankBackup = MCU_BANK_SEL_FFFE;
    // Change to the target xdata bank
    MCU_BANK_SEL_FFFE = ucBank - MCU_BANK_START_FFFD;

    UserCommonFlashWREN(ucBank, ucPage);

    // Sector Erase
    MCU_COMM_INST_EN_FF60 = 0xB8;
    MCU_COMM_OP_CODE_FF61 = tFlashInformation[g_ucFlashType].ucPageEraseOpCode;
    // Set WR address
    MCU_FLASH_PROG_ISP0_FF64 = ucBank;
    MCU_FLASH_PROG_ISP1_FF65 = (BYTE)((ucPage << 4) & 0xF0);
    MCU_FLASH_PROG_ISP2_FF66 = 0x00;
    // Start Bit0
    MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;

    // No need to polling, 8051 will halt when common instruction executes

    MCU_COMM_OP_CODE_FF61 = 0xFF;

    UserCommonFlashWRDis();

    // Restore the xdata bank
    MCU_BANK_SEL_FFFE = ucBankBackup;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Save data to flash
// Input Value  : ucBank: bank index
//                usAddr: address in ucBank
//                ucLength: the data length to save
//                pucData: data buffer to save
// Output Value : _TRUE for save success and _FALSE for save fail
//--------------------------------------------------
bit UserCommonFlashWrite(BYTE ucBank, WORD usAddr, WORD usLength, BYTE* pucData)
{
    BYTE ucPage = 0;
    BYTE ucBankBackup = 0;
    BYTE xdata *pucXData = 0x0000;
    WORD usIndex = 0;

    BYTE ucStartPage = 0;
    BYTE ucEndPage = 0;
    WORD usCurrentAddr = 0;
    WORD usLeftLength = 0;
    WORD usCurrentLength = 0;

    // The access bank is smaller than than the start bank or across bank
    if((ucBank < MCU_BANK_START_FFFD) || (((DWORD)usAddr + usLength) > 0x10000))
    {
        return _FALSE;
    }

    // Need detect flash type when never detected
    if(g_ucFlashType == _FLASH_UNDETECT)
    {
        UserCommonFlashDetectFlashType();
    }

    // Backup the current xdata bank index
    ucBankBackup = MCU_BANK_SEL_FFFE;
    // Change to the target xdata bank
    MCU_BANK_SEL_FFFE = ucBank - MCU_BANK_START_FFFD;

    ///////////////////////////////////
    //Avoid Write Across Page(Sector)//
    ///////////////////////////////////
    
    ucStartPage = usAddr / _FLASH_PAGE_SIZE;
    ucEndPage = ((DWORD)usAddr + usLength) / _FLASH_PAGE_SIZE;
    usCurrentAddr = usAddr;
    usLeftLength = usLength;
    
    for(ucPage = ucStartPage; ucPage <= ucEndPage; ucPage++)
    {
        // Assign usCurrentLength
        if(((DWORD)_FLASH_PAGE_SIZE * (ucPage + 1)) <= (usCurrentAddr + usLeftLength))
        {
            usCurrentLength = ((DWORD)_FLASH_PAGE_SIZE * (ucPage+1)) - usCurrentAddr;
        }
        else
        {
            usCurrentLength = usLeftLength;
        }

        // Write usCurrentLength Bytes Data From usCurrentAddr            
        if((g_ucFlashType == _FLASH_MX25L2026D) || (g_ucFlashType == _FLASH_MX25L4026D))
        {
            for(usIndex = usCurrentAddr - usAddr; usIndex < (usCurrentAddr - usAddr) + usCurrentLength; usIndex++)
            {
                UserCommonFlashWREN(ucBank, ucPage);
                pucXData[usAddr + usIndex] = pucData[usIndex];
            }
            UserCommonFlashWRDis();
        }
        else
        {
            UserCommonFlashWREN(ucBank, ucPage);
            memcpy(pucXData + usCurrentAddr, &pucData[usCurrentAddr - usAddr], usCurrentLength);
            UserCommonFlashWRDis();
        }

        // Assign New usCurrentLength and usLeftLength
        usCurrentAddr = usCurrentAddr + usCurrentLength;
        usLeftLength = usLeftLength - usCurrentLength;        
    }

    // Restore the xdata bank
    MCU_BANK_SEL_FFFE = ucBankBackup;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Load data from flash
// Input Value  : ucBank: bank index
//                usAddr: address in ucBank
//                ucLength: the data length to load
//                pucData: data buffer to save the load data
// Output Value : _TRUE for load success and _FALSE for load fail
//--------------------------------------------------
bit UserCommonFlashRead(BYTE ucBank, WORD usAddr, WORD usLength, BYTE* pucData)
{
    BYTE ucPage = 0;
    BYTE ucBankBackup = 0;
    BYTE xdata *pucXData = 0x0000;

    // The access bank is smaller than than the start bank
    if(ucBank < MCU_BANK_START_FFFD)
    {
        return _FALSE;
    }

    // Need detect flash type when never detected
    if(g_ucFlashType == _FLASH_UNDETECT)
    {
        UserCommonFlashDetectFlashType();
    }

    // Backup the current xdata bank index
    ucBankBackup = MCU_BANK_SEL_FFFE;
    // Change to the target xdata bank
    MCU_BANK_SEL_FFFE = ucBank - MCU_BANK_START_FFFD;

    memcpy(pucData, pucXData + usAddr, usLength);

    // Restore the xdata bank
    MCU_BANK_SEL_FFFE = ucBankBackup;

    return _TRUE;
}

#endif // End of #if(_FLASH_ACCESS_FUNCTION_SUPPORT == _ON)

#if(_FLASH_WR_PROTECT ==_ON)
//--------------------------------------------------
// Description  : Set SR to protect flash
// Input Value  : None              
// Output Value : Return _TURE if succeed, else return _FALSE
//--------------------------------------------------
void UserCommonFlashWRProtect(void)
{
    BYTE ucRDSR = 0;
    
    // Clear watch dog
    MCU_WATCHDOG_TIMER_FFEA |= 0x40;
    
    // Detect flash type first
    if(g_ucFlashType == _FLASH_UNDETECT)
    {
        UserCommonFlashDetectFlashType();
    } 

    if((g_ucFlashType == _FLASH_PM25LV020) || (g_ucFlashType == _FLASH_PM25LD020)
    || (g_ucFlashType == _FLASH_PM25LQ020A) || (g_ucFlashType == _FLASH_PM25LQ040B)
    || (g_ucFlashType == _FLASH_PM25LQ080) || (g_ucFlashType == _FLASH_W25X20A) 
    || (g_ucFlashType == _FLASH_MX25L2026D) || (g_ucFlashType == _FLASH_EN25F20) 
    || (g_ucFlashType == _FLASH_MX25L2025) || (g_ucFlashType == _FLASH_MX25L4006E) 
    || (g_ucFlashType == _FLASH_W25X21CL) || (g_ucFlashType == _FLASH_W25X41CL) 
    || (g_ucFlashType == _FLASH_FM25F04) || (g_ucFlashType == _FLASH_N25S40) 
    || (g_ucFlashType == _FLASH_A25L040) || (g_ucFlashType == _FLASH_W25Q80BV) 
    || (g_ucFlashType == _FLASH_MX25L4026D) || (g_ucFlashType == _FLASH_W25X40CL)
    || (g_ucFlashType == _FLASH_EN25F20A) || (g_ucFlashType == _FLASH_EN25F40A) 
    || (g_ucFlashType == _FLASH_EN25Q40A) || (g_ucFlashType == _FLASH_EN25Q80) 
    || (g_ucFlashType == _FLASH_GD25Q80B) || (g_ucFlashType == _FLASH_MX25L8006E)
    || (g_ucFlashType == _FLASH_GD25Q40B) || (g_ucFlashType == _FLASH_GD25M21B)
    || (g_ucFlashType == _FLASH_GD25M41B) || (g_ucFlashType == _FLASH_GD25Q16C)
    || (g_ucFlashType == _FLASH_MX25L3233F) || (g_ucFlashType == _FLASH_EN25QH32A)
    || (g_ucFlashType == _FLASH_MX25V8035F) ||(g_ucFlashType == _FLASH_MX25V1635F))
    
    {
        // Read SR
        MCU_COMM_INST_EN_FF60  = 0x42;
        MCU_COMM_OP_CODE_FF61 = 0x05;
        MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;
        ucRDSR = MCU_COMM_INST_READ_P0_FF67;
      
        
        if(ucRDSR != tFlashInformation[g_ucFlashType].ucProtectWRSR)
        {
	        UserCommonFlashSetWRSR(tFlashInformation[g_ucFlashType].ucProtectWRSR, _FALSE);
	        UserCommonFlashSetWREN(tFlashInformation[g_ucFlashType].ucWRDisOpCode);
        }
    }
    else if(g_ucFlashType == _FLASH_SST25LF020A)
    {
        // Read SR
        MCU_COMM_INST_EN_FF60  = 0x42;
        MCU_COMM_OP_CODE_FF61 = 0x05;
        MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;
        ucRDSR = MCU_COMM_INST_READ_P0_FF67;
        
        if(ucRDSR != tFlashInformation[g_ucFlashType].ucProtectWRSR)
        {
	        UserCommonFlashSetWRSR(tFlashInformation[g_ucFlashType].ucProtectWRSR, _TRUE);
	        UserCommonFlashSetWREN(tFlashInformation[g_ucFlashType].ucWRDisOpCode);
        }
    }
    

    else if (g_ucFlashType == _FLASH_GD25Q41)
    {
        // Read SR
        MCU_COMM_INST_EN_FF60  = 0x42;
        MCU_COMM_OP_CODE_FF61 = 0x05;
        MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;
        ucRDSR = MCU_COMM_INST_READ_P0_FF67;
        
        if(ucRDSR != tFlashInformation[g_ucFlashType].ucProtectWRSR)
        {
	        UserCommonFlashSet2ByteWRSR(tFlashInformation[g_ucFlashType].ucProtectWRSR, 0x00, _FALSE);
	        UserCommonFlashSetWREN(tFlashInformation[g_ucFlashType].ucWRDisOpCode);
        }
    }
    else
    {
         // Read SR
        MCU_COMM_INST_EN_FF60  = 0x42;
        MCU_COMM_OP_CODE_FF61 = 0x05;
        MCU_COMM_INST_EN_FF60 = MCU_COMM_INST_EN_FF60 | _BIT0;
        ucRDSR = MCU_COMM_INST_READ_P0_FF67;
        
        if(ucRDSR != 0xFF)
        {
	        UserCommonFlashSetWRSR(0xFF, _FALSE);
	        UserCommonFlashSetWREN(0x04); 
        }
    }
 
    // Disable Program OP code
    MCU_PROG_OP_CODE_FF6D = 0xFF;

    // Disable Command OP code
    MCU_COMM_OP_CODE_FF61 = 0xFF;
}
#endif // End of #if(_FLASH_WR_PROTECT ==_ON)
#endif // End of #if((_FLASH_ACCESS_FUNCTION_SUPPORT == _ON) || (_FLASH_WR_PROTECT ==_ON))
