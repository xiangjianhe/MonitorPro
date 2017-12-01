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
// ID Code      : UserCommonInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "Global.h"
#include "Project.h"
#include "ScalerFunctionInterface.h"
#include "SysInterface.h"
#include "UserCommonDdcciDefine.h"
#include _USER_FUNCTION_INCLUDE
#include _OSD_INCLUDE
#include _FACTORY_INCLUDE

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Eeprom Page address
//--------------------------------------------------
#define _EEPROM_PAGE0_BANK0                         0    
#define _EEPROM_PAGE0_BANK1                         128
#define _EEPROM_PAGE1_BANK0                         256
#define _EEPROM_PAGE1_BANK1                         384
#define _EEPROM_PAGE2_BANK0                         512
#define _EEPROM_PAGE2_BANK1                         640
#define _EEPROM_PAGE3_BANK0                         768
#define _EEPROM_PAGE3_BANK1                         896
#define _EEPROM_PAGE4_BANK0                         1024
#define _EEPROM_PAGE4_BANK1                         1152
#define _EEPROM_PAGE5_BANK0                         1280
#define _EEPROM_PAGE5_BANK1                         1408
#define _EEPROM_PAGE6_BANK0                         1536
#define _EEPROM_PAGE6_BANK1                         1664
#define _EEPROM_PAGE7_BANK0                         1792
#define _EEPROM_PAGE7_BANK1                         1920
//---------------------------------------------------------------------------------------------------------------------------------------

#define _EEPROM_CHECKSUM_ADDRESS                    (_EEPROM_KERNEL_START_ADDRESS)
#define _EEPROM_VERSION_CODE_ADDRESS                (_EEPROM_CHECKSUM_ADDRESS + 1)
#define _ADC_SETTING_ADDRESS                        (_EEPROM_VERSION_CODE_ADDRESS + 1)
#define _SYSTEM_DATA_ADDRESS                        (_ADC_SETTING_ADDRESS + sizeof(StructAdcDataType) * (_VGA_SUPPORT + _YPBPR_SUPPORT))
#define _SYSTEM_DATA_ADDRESS_END                    (_SYSTEM_DATA_ADDRESS + sizeof(StructSystemDataType))
//---------------------------------------------------------------------------------------------------------------------------------------

#define _MODE_USER_DATA_ADDRESS                     (_SYSTEM_DATA_ADDRESS_END)
#define _VGA_MODE_DATA_ADDRESS_END                  (_MODE_USER_DATA_ADDRESS + sizeof(VGAModeUserDataType) * _MODE_SLOT_AMOUNT * _VGA_SUPPORT)
//---------------------------------------------------------------------------------------------------------------------------------------

#define _MISC_PAGE                                  15

//--------------------------------------------------
// Definitions of Flash Page information
//--------------------------------------------------
#define _FLASH_PAGE_SIZE                            4096

//--------------------------------------------------
// Address for OGC/OCC/DICOM
//--------------------------------------------------
#define _OGC_RGB_GAIN_TOTAL_SPACE                   0x100
#define _OGC_GAMMA_TABLE_SIZE                       0x500
#define _OGC_TOTAL_CT                               6
#define _OGC_RGB_GAIN_ACTUAL_SIZE                   (_OGC_TOTAL_GAMMA * _OGC_TOTAL_CT * 3)

#define _OCC_COLOR_MATRIX_TOTAL_SPACE               0x100
#define _OCC_COLORMATRIX_TABLE_SIZE                 0x12

#define _OGC_RGB_GAIN_ADDRESS                       0
#define _OGC_GAMMA1_ADDRESS                         (_OGC_RGB_GAIN_ADDRESS + _OGC_RGB_GAIN_TOTAL_SPACE * _OGC_SUPPORT)
#define _OGC_GAMMA2_ADDRESS                         (_OGC_GAMMA1_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT)
#define _OGC_GAMMA3_ADDRESS                         (_OGC_GAMMA2_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT)
#define _OGC_GAMMA4_ADDRESS                         (_OGC_GAMMA3_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT * (_OGC_TOTAL_GAMMA == 5 ? 1 : 0)) 
#define _OGC_GAMMA5_ADDRESS                         (_OGC_GAMMA4_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT * (_OGC_TOTAL_GAMMA == 5 ? 1 : 0))

#define _OCC_GAMMA10_ADDRESS                        (_OGC_GAMMA5_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_SUPPORT)
#define _OCC_SRGBMATRIX_ADDRESS                     (_OCC_GAMMA10_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OCC_SUPPORT)
#define _OCC_ADOBEMATRIX_ADDRESS                    (_OCC_SRGBMATRIX_ADDRESS + _OCC_COLORMATRIX_TABLE_SIZE * _OCC_SUPPORT)

#define _OGC_DICOM_ADDRESS                          (_OCC_SRGBMATRIX_ADDRESS + _OCC_COLOR_MATRIX_TOTAL_SPACE * _OCC_SUPPORT)

#define _DISP_CALIBRATION_TOTAL_END                 (_OGC_DICOM_ADDRESS + _OGC_GAMMA_TABLE_SIZE * _OGC_DICOM_SUPPORT)
#define _DISP_CALIBRATION_TOTAL_SPACE               (_DISP_CALIBRATION_TOTAL_END - _OGC_RGB_GAIN_ADDRESS)
                 
#define _OGC_CHKSUM_ADDRESS                         (_OCC_GAMMA10_ADDRESS - 1)
#define _OCC_CHKSUM_ADDRESS                         (_OCC_SRGBMATRIX_ADDRESS - 1)
#define _OCC_COLOR_MATRIX_CHKSUM_ADDRESS            (_OCC_ADOBEMATRIX_ADDRESS + _OCC_COLORMATRIX_TABLE_SIZE * 2 - 1) 
#define _OGC_DICOM_CHKSUM_ADDRESS                   (_OGC_DICOM_ADDRESS + _OGC_GAMMA_TABLE_SIZE - 1)

//--------------------------------------------------
// Auto config error status
//--------------------------------------------------
#define _AUTO_CONFIG_MEASURE_ERROR                  _BIT0
#define _AUTO_CONFIG_CLOCK_ABORT                    _BIT1
#define _AUTO_CONFIG_PHASE_ABORT                    _BIT2

//--------------------------------------------------
// Auto config Percentage Stage
//--------------------------------------------------
#define _AUTO_CONFIG_CHECK_MULTITIMES_FINISH        5
#define _AUTO_CONFIG_CLOCK_CHECK_WIDTH_FINISH       10
#define _AUTO_CONFIG_CLOCK_ROUGH_ADJUST_FINISH      20       
#define _AUTO_CONFIG_CLOCK_FINETUNE_FINISH          75
#define _AUTO_CONFIG_CLOCK_FINISH                   80
#define _AUTO_CONFIG_PHASE_FINISH                   90
#define _AUTO_CONFIG_V_POSITION_FINISH              95
#define _AUTO_CONFIG_H_POSITION_FINISH              100

//--------------------------------------------------
// Definitions of Clock Settings Used by COsdFxGetAdcClockRange()
//--------------------------------------------------
#define _CLOCK_BIAS                                 50
#define _GET_CLOCKRANGE_MAX                         0
#define _GET_CLOCKRANGE_MIN                         1

//--------------------------------------------------
// Definitions of Hor. Position Settings Used by COsdFxGetHPositionRange()
//--------------------------------------------------
#define _HPOSITION_BIAS                             (UserCommonAdjustGetHPositionHBiasValue())
#define _GET_HPOSITIONRANGE_MAX                     (0)
#define _GET_HPOSITIONRANGE_MIN                     (1)

//--------------------------------------------------
// Definitions of Ver. Position Settings Used by COsdFxGetVPositionRange()
//--------------------------------------------------
#define _VPOSITION_BIAS                             (UserCommonAdjustGetVPositionVBiasValue())
#define _GET_VPOSITIONRANGE_MAX                     (0)
#define _GET_VPOSITIONRANGE_MIN                     (1)

//--------------------------------------------------
// Definitions of Phase Range
//--------------------------------------------------
#define _ADJUST_PHASE_MAX                           63
#define _ADJUST_PHASE_MIN                           0
#define _ADJUST_PHASE_CENTER                        (((_ADJUST_PHASE_MAX - _ADJUST_PHASE_MIN) / 2) + _ADJUST_PHASE_MIN)

//--------------------------------------------------
// // MACRO for Digital H Position
//--------------------------------------------------
#define GET_DIGITAL_H_POSITION()                    (g_ucDigitalHPosition)
#define SET_DIGITAL_H_POSITION(x)                   (g_ucDigitalHPosition = (x))

//--------------------------------------------------
// // MACRO for Digital H Position
//--------------------------------------------------
#define GET_DIGITAL_V_POSITION()                    (g_ucDigitalVPosition)
#define SET_DIGITAL_V_POSITION(x)                   (g_ucDigitalVPosition = (x))

//--------------------------------------------------
// MACRO of Panel Power Sequence
//--------------------------------------------------
#define GET_PANELPOWERSTATUS()                      (g_ucPanelPowerInfo & (_BIT2 | _BIT1 | _BIT0))
#define SET_PANELPOWERSTATUS(x)                     (g_ucPanelPowerInfo = ((g_ucPanelPowerInfo & ~(_BIT2 | _BIT1 | _BIT0)) | (x)))

//--------------------------------------------------
// MACRO for OSD Fail Safe Mode
//--------------------------------------------------
#define GET_FAIL_SAFE_MODE()                        (g_bFailSafeMode)
#define SET_FAIL_SAFE_MODE(x)                       (g_bFailSafeMode = (x))

//--------------------------------------------------
// // MACRO for VGA Mode Adjust H Position
//--------------------------------------------------
#define GET_VGA_MODE_ADJUST_H_POSITION()            (g_stVGAModeUserData.ucUserHPosition)
#define SET_VGA_MODE_ADJUST_H_POSITION(x)           (g_stVGAModeUserData.ucUserHPosition = (x))

//--------------------------------------------------
// // MACRO for VGA Mode Adjust V Position
//--------------------------------------------------
#define GET_VGA_MODE_ADJUST_V_POSITION()            (g_stVGAModeUserData.ucUserVPosition)
#define SET_VGA_MODE_ADJUST_V_POSITION(x)           (g_stVGAModeUserData.ucUserVPosition = (x))

//--------------------------------------------------
// // MACRO for VGA Mode Adjust Clock
//--------------------------------------------------
#define GET_VGA_MODE_ADJUST_CLOCK()                 (g_stVGAModeUserData.usUserClock)
#define SET_VGA_MODE_ADJUST_CLOCK(x)                (g_stVGAModeUserData.usUserClock = (x))

//--------------------------------------------------
// // MACRO for VGA Mode Adjust Phase
//--------------------------------------------------
#define GET_VGA_MODE_ADJUST_PHASE()                 (g_stVGAModeUserData.ucUserPhase)
#define SET_VGA_MODE_ADJUST_PHASE(x)                (g_stVGAModeUserData.ucUserPhase = (x))

//--------------------------------------------------
// MACRO for VGA Mode Do Auto
//--------------------------------------------------
#define GET_VGA_MODE_DO_FIRST_AUTO()                (g_stVGAModeUserData.b1DoFirstAuto)
#define SET_VGA_MODE_DO_FIRST_AUTO(x)               (g_stVGAModeUserData.b1DoFirstAuto = (x))

//--------------------------------------------------
// MACRO for OSD Fail Safe Mode
//--------------------------------------------------
#define GET_RUN_DDCCI_COMMAND()                     (g_bRunDdcciCommand)
#define SET_RUN_DDCCI_COMMAND(x)                    (g_bRunDdcciCommand = (x))

#if(_ENERGY_STAR_SUPPORT == _ON)
//--------------------------------------------------
// Macro of DCR PWM target value for Energy Star
//--------------------------------------------------
#define GET_ES_DCR_PWM_TARGET_VALUE()               (g_stESDcrInfo.ucESDcrPWMTargetValue)
#define SET_ES_DCR_PWM_TARGET_VALUE(x)              (g_stESDcrInfo.ucESDcrPWMTargetValue = (x))

//--------------------------------------------------
// Macro of Dcr PWM adjust value for Energy Star
//--------------------------------------------------
#define GET_ES_DCR_PWM_ADJUST_VALUE()               (g_stESDcrInfo.ucESDcrPWMAdjustValue)
#define SET_ES_DCR_PWM_ADJUST_VALUE(x)              (g_stESDcrInfo.ucESDcrPWMAdjustValue = (x))
#endif // End of #if(_ENERGY_STAR_SUPPORT == _ON)

//--------------------------------------------------
// Flash Support List
//--------------------------------------------------
#define _FLASH_W25X20A                              0
#define _FLASH_W25X21CL                             1
#define _FLASH_PM25LV020                            2
// This is MX25L2026D, it is not same with MX25L2026E
#define _FLASH_MX25L2026D                           3
#define _FLASH_EN25F20                              4
#define _FLASH_PM25LD020                            5
// It is the same with MX25L2026E and KH25L2026E
#define _FLASH_MX25L2025                            6
// It is the same with MX25L4026E and KH25L4026E
#define _FLASH_MX25L4006E                           7
#define _FLASH_SST25LF020A                          8
#define _FLASH_W25X41CL                             9
#define _FLASH_FM25F04                              10
#define _FLASH_N25S40                               11
#define _FLASH_A25L040                              12
//W25Q80DV use the same _FLASH_W25Q80BV
#define _FLASH_W25Q80BV                             13
//PM25LQ020B use the same _FLASH_PM25LQ020A
#define _FLASH_PM25LQ020A                           14
#define _FLASH_MX25L4026D                           15
#define _FLASH_W25X40CL                             16
#define _FLASH_EN25F20A                             17
#define _FLASH_EN25F40A                             18
#define _FLASH_EN25Q40A                             19
//EN25Q80A and EN25Q80B use the same _FLASH_EN25Q80
#define _FLASH_EN25Q80                              20
#define _FLASH_GD25Q80B                             21
#define _FLASH_GD25M21B                             22
#define _FLASH_GD25M41B                             23
#define _FLASH_MX25L8006E                           24
#define _FLASH_PM25LQ080                            25
#define _FLASH_GD25Q40B                             26
#define _FLASH_PM25LQ040B                           27
#define _FLASH_GD25Q41                              28
//W25Q16JV use the same _FLASH_W25Q16DV
#define _FLASH_W25Q16DV                             29
#define _FLASH_GD25Q16C                             30
#define _FLASH_MX25L3233F                           31
#define _FLASH_EN25QH32A                            32
#define _FLASH_MX25V8035F                           33
#define _FLASH_MX25V1635F                           34
#define _FLASH_TYPE_END                             35
#define _FLASH_TOTAL_COUNT                          _FLASH_TYPE_END
#define _FLASH_DEFAULT_TYPE                         _FLASH_W25X20A
#define _FLASH_UNDETECT                             0xFE


typedef enum
{
    _WRITE_SIZE_8 = 8,
    _WRITE_SIZE_16 = 16,
} EnumEepromWriteSize;

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
    BYTE b1IsPresetMode : 1;
    BYTE b1DoFirstAuto : 1;
    BYTE ucModeNumber;
    BYTE ucUserHPosition;
    BYTE ucUserVPosition;
    WORD usUserClock;
    BYTE ucUserPhase;
    WORD usCenterHPosition;
    WORD usCenterVPosition;
    WORD usCenterClock;
    BYTE ucCenterPhase;
} VGAModeUserDataType;

typedef struct
{
    BYTE b1PowerStatus : 1;                     // Monitor Power Status
    BYTE b1DPHotPlugDCOffHigh : 1;              // DPHotPlugDCOffHigh    
    BYTE b3SearchPort : 3;                      // Search Port
    BYTE b3SourceScanType : 3;                  // Source Scan Type    
//--------------------------------------------------------
    BYTE b3HDMIHotPlugSupportTime : 3;          // HDMIHotPlugSupportTime(Unit : 100ms)
    BYTE b1HDMIHotPlugSupport : 1;              // HDMIHotPlugSupport
    BYTE b3SourceHPDefaultSearchIndex : 3;      // HP User Defautl SearchIndex
    BYTE b1SourceHPAutoSearch : 1;              // HP User Auto Search
    BYTE ucModeSlotIndex;                       // Mode Slot Index
    BYTE ucSSC;                                 // SSC
    BYTE b1SlpAcOffDetect : 1;                  // Slp No Cable Detect
}StructSystemDataType;

typedef struct
{
    BYTE ucESDcrCurRGBAvgValue;
    BYTE ucESDcrPreRGBAvgValue;
    BYTE ucESDcrPWMTargetValue;
    BYTE ucESDcrPWMAdjustValue;
}StructESDcrInfo;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
//----------------------------------------------------------------------------------------
// Extern functions from UserCommonAdjust.c
//----------------------------------------------------------------------------------------
#if(_ENERGY_STAR_SUPPORT == _ON)
extern StructESDcrInfo g_stESDcrInfo;
#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonInterface.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_INTERFACE__
extern BYTE g_ucDigitalHPosition;
extern BYTE g_ucDigitalVPosition;
extern BYTE g_ucPanelPowerInfo;
extern bit g_bFailSafeMode;
extern bit g_bRunDdcciCommand;
#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonAuto.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_AUTO__
#if(_VGA_SUPPORT == _ON)
extern BYTE g_ucAutoConfigStatus;
#endif
#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonDdcciFunction.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_DDCCI_FUNCTION__
extern BYTE g_ucDdcciRxBuf[_DDCCI_RXBUF_LENGTH];
extern BYTE g_ucDdcciTxBuf[_DDCCI_TXBUF_LENGTH];

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
extern BYTE xdata DISP_CALIBRATION_FLASH[_DISP_CALIBRATION_TOTAL_SPACE]; 
#endif

#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonNVRamSystem.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_NVRAM_SYSTEM__
extern StructSystemDataType g_stSystemData;

#if(_VGA_SUPPORT == _ON)
extern VGAModeUserDataType g_stVGAModeUserData;
extern StructAdcDataType g_stAdcData;
#endif

#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
//----------------------------------------------------------------------------------------
// UserCommonInterface.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_INTERFACE__

extern void UserCommonInterfaceOsdResetProc(void);

#if(_VGA_SUPPORT == _ON)
extern void UserCommonInterfaceAdjustADCData(void);
#endif

#endif

//----------------------------------------------------------------------------------------
// UserCommonAuto.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_AUTO__
#if(_VGA_SUPPORT == _ON)
extern void UserCommonAutoConfig(void);
extern bit UserCommonAutoMeasureMultiTimes(void);
#endif
#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonAdjust.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_ADJUST__

#if(_VGA_SUPPORT == _ON)
extern WORD UserCommonAdjustGetAdcClockRange(BYTE ucPar);
#endif

extern WORD UserCommonAdjustGetHPositionRange(BYTE ucPar);
extern WORD UserCommonAdjustGetHPositionHBiasValue(void);
extern WORD UserCommonAdjustGetVPositionRange(BYTE ucPar);
extern WORD UserCommonAdjustGetVPositionVBiasValue(void);
extern void UserCommonAdjustHPosition(BYTE ucUserHPosition);
extern void UserCommonAdjustVPosition(BYTE ucUserVPosition);

#if(_VGA_SUPPORT == _ON)
extern void UserCommonAdjustClock(WORD usUserIHTotal);
extern void UserCommonAdjustPhase(BYTE ucPhase);
#endif

extern BYTE UserCommonAdjustRealValueToPercent(WORD usRealValue, WORD usMax, WORD usMin, WORD usCenter);
extern WORD UserCommonAdjustPercentToRealValue(BYTE ucPercentValue, WORD usMax, WORD usMin, WORD usCenter);

#if(_OVERSCAN_SUPPORT == _ON)
extern void UserCommonAdjustOverScan(void);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
extern void UserCommonAdjustUltraVivid(EnumColorSpace enumColorFormat);
#endif

#if(_I_DITHER_SUPPORT == _ON)
extern void UserCommonAdjustIDither(void);
#endif

#if(_ENERGY_STAR_SUPPORT == _ON)
extern void UserCommonAdjustESDcrAdjust(void);
extern void UserCommonAdjustESDcrAdjustPWM(void);
extern void UserCommonAdjustESDcrProcess(bit bOnOff);
extern void UserCommonAdjustESDcrSearchTargetPWM(void);
#endif

#endif

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
extern bit UserInterfaceGetFREESYNCEnable_EXINT1(void);
#endif
//----------------------------------------------------------------------------------------
// Extern functions from UserCommonNVRamSystem.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_NVRAM_SYSTEM__
extern BYTE UserCommonNVRamGetSystemData(BYTE ucDataType);
extern void UserCommonNVRamSetSystemData(BYTE ucDataType, BYTE ucValue);

#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)
extern bit UserCommonEepromIICRead(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pReadArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum);
extern bit UserCommonEepromIICWrite(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pWriteArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum, EnumEepromWriteSize enumWriteSize);
#endif

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
extern bit UserCommonEepromRead(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
extern bit UserCommonEepromWrite(WORD usSubAddr, WORD usLength, BYTE *pWriteArray);
extern void UserCommonEepromSaveSystemData(void);
extern void UserCommonEepromLoadSystemData(void);
extern void UserCommonEepromRestoreSystemData(void);
#if(_VGA_SUPPORT == _ON)
extern void UserCommonEepromLoadModeUserData(BYTE ucSlotIndex);
extern void UserCommonEepromSaveModeUserData(void);
extern BYTE UserCommonEepromLoadModeUserModeNumberData(BYTE ucSlotIndex);
extern void UserCommonEepromRestoreModeUserData(void);
extern BYTE UserCommonEepromVGAFifoModeIndexOffsetInc(BYTE ucStep);
extern BYTE UserCommonEepromGetMaxFifoGroupCnt(void);
extern void UserCommonEepromLoadADCSetting(EnumColorSpace enumColorFormat);
extern void UserCommonEepromSaveADCSetting(EnumColorSpace enumColorFormat);
extern void UserCommonEepromRestoreADCSetting(void);
#endif
#if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
extern void UserCommonEepromGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
extern void UserCommonEepromGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
extern void UserCommonEepromRestoreHDCP(WORD usOffset, BYTE ucLength, BYTE* pucBuf);
#endif
#endif

#define UserCommonNVRamRead(x, y, z)                   UserCommonEepromRead(x, y, z)
#define UserCommonNVRamSaveSystemData()                UserCommonEepromSaveSystemData()
#define UserCommonNVRamLoadSystemData()                UserCommonEepromLoadSystemData()
#define UserCommonNVRamRestoreSystemData()             UserCommonEepromRestoreSystemData()
#if(_VGA_SUPPORT == _ON)
#define UserCommonNVRamLoadModeUserData(x)             UserCommonEepromLoadModeUserData(x)
#define UserCommonNVRamSaveModeUserData()              UserCommonEepromSaveModeUserData()
#define UserCommonNVRamLoadModeUserModeNumberData(x)   UserCommonEepromLoadModeUserModeNumberData(x)
#define UserCommonNVRamRestoreModeUserData()           UserCommonEepromRestoreModeUserData()
#define UserCommonNVRamVGAFifoModeIndexOffsetInc()     UserCommonEepromVGAFifoModeIndexOffsetInc()
#define UserCommonNVRamGetMaxFifoGroupCnt()            UserCommonEepromGetMaxFifoGroupCnt()
#define UserCommonNVRamSaveADCSetting(x)               UserCommonEepromSaveADCSetting(x)
#define UserCommonNVRamLoadADCSetting(x)               UserCommonEepromLoadADCSetting(x)
#define UserCommonNVRamRestoreADCSetting()             UserCommonEepromRestoreADCSetting()
#endif
#if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
#define UserCommonNVRamGetHDCPKeyBKsv(x, y, z)         UserCommonEepromGetHDCPKeyBKsv(x, y, z)
#define UserCommonNVRamGetHDCPKey(x, y, z)             UserCommonEepromGetHDCPKey(x, y, z)
#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
#define UserCommonNVRamRestoreHDCP(x, y, z)            UserCommonEepromRestoreHDCP(x, y, z)
#endif
#endif

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

extern void UserCommonFlashSaveSystemData(void);
extern void UserCommonFlashLoadSystemData(void);
extern void UserCommonFlashRestoreSystemData(void);
#if(_VGA_SUPPORT == _ON)
extern void UserCommonFlashLoadModeUserData(BYTE ucSlotIndex);
extern void UserCommonFlashSaveModeUserData(void);
extern BYTE UserCommonFlashLoadModeUserModeNumberData(BYTE ucSlotIndex);
extern void UserCommonFlashRestoreModeUserData(void);
extern BYTE UserCommonFlashVGAFifoModeIndexOffsetInc(BYTE ucStep);
extern BYTE UserCommonFlashGetMaxFifoGroupCnt(void);
extern void UserCommonFlashLoadADCSetting(EnumColorSpace enumColorFormat);
extern void UserCommonFlashSaveADCSetting(EnumColorSpace enumColorFormat);
extern void UserCommonFlashRestoreADCSetting(void);
#endif
#if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
extern void UserCommonFlashGetHDCPKeyBKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
extern void UserCommonFlashGetHDCPKey(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
extern void UserCommonFlashRestoreHDCP(WORD usAddr, BYTE ucLength, BYTE* pucBuf);
#endif
#endif

#define UserCommonNVRamRead(x, y, z)                   UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, x, y, z)
#define UserCommonNVRamSaveSystemData()                UserCommonFlashSaveSystemData()
#define UserCommonNVRamLoadSystemData()                UserCommonFlashLoadSystemData()
#define UserCommonNVRamRestoreSystemData()             UserCommonFlashRestoreSystemData()
#if(_VGA_SUPPORT == _ON)
#define UserCommonNVRamLoadModeUserData(x)             UserCommonFlashLoadModeUserData(x)
#define UserCommonNVRamSaveModeUserData()              UserCommonFlashSaveModeUserData()
#define UserCommonNVRamLoadModeUserModeNumberData(x)   UserCommonFlashLoadModeUserModeNumberData(x)
#define UserCommonNVRamRestoreModeUserData()           UserCommonFlashRestoreModeUserData()
#define UserCommonNVRamVGAFifoModeIndexOffsetInc()     UserCommonFlashVGAFifoModeIndexOffsetInc()
#define UserCommonNVRamGetMaxFifoGroupCnt()            UserCommonFlashGetMaxFifoGroupCnt()
#define UserCommonNVRamSaveADCSetting(x)               UserCommonFlashSaveADCSetting(x)
#define UserCommonNVRamLoadADCSetting(x)               UserCommonFlashLoadADCSetting(x)
#define UserCommonNVRamRestoreADCSetting()             UserCommonFlashRestoreADCSetting()
#endif
#if((_DIGITAL_PORT_SUPPORT == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
#define UserCommonNVRamGetHDCPKeyBKsv(x, y, z)         UserCommonFlashGetHDCPKeyBKsv(x, y, z)
#define UserCommonNVRamGetHDCPKey(x, y, z)             UserCommonFlashGetHDCPKey(x, y, z)
#if(_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON)
#define UserCommonNVRamRestoreHDCP(x, y, z)            UserCommonFlashRestoreHDCP(x, y, z)
#endif
#endif

#endif // Else of #elif(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)

#if(_FLASH_ACCESS_FUNCTION_SUPPORT == _ON)
extern bit UserCommonFlashErasePage(BYTE ucBank, BYTE ucPage);
extern bit UserCommonFlashWrite(BYTE ucBank, WORD usAddr, WORD usLength, BYTE* pucData);
extern bit UserCommonFlashRead(BYTE ucBank, WORD usAddr, WORD usLength, BYTE* pucData);

#endif

#if(_FLASH_WR_PROTECT ==_ON)
extern void UserCommonFlashWRProtect(void);
#endif

#endif // End of #ifndef __USER_COMMON_NVRAM_SYSTEM__

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonDdcciFunction.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_DDCCI_FUNCTION__
extern void UserCommonDdcciInitTx(void);
extern void UserCommonDdcciInitRx(void);
extern BYTE UserCommonDdcciCalCheckSum(void);
extern void UserCommonDdcciSetVCPReplyValue(BYTE ucTypeOpcode, WORD usMax, WORD usPresent);
extern void UserCommonDdcciGetTimingReport(void);
extern void UserCommonDdcciGetCapabilitiesRequest(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserCommonDisplayCalibration.c
//----------------------------------------------------------------------------------------
#ifndef __USER_COMMON_DISPLAY_CALIBRATION__

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
extern void UserCommonDdcciDispCalibProcess(void);
#endif

#endif

//----------------------------------------------------------------------------------------
// Extern functions from UserModeSearch.c
//----------------------------------------------------------------------------------------
#ifndef __USER_MODESEARCH__
#if(_VGA_SUPPORT == _ON)
extern BYTE UserCommonModeSearchCheckFIFOModeSaved(BYTE ucModeIndex);
extern void UserCommonModeSearchInitalUserAndCenterData(BYTE ucIndex);
extern WORD UserCommonModeSearchGetModetableTimingDataItem(BYTE ucModeNumber, EnumTimingInfoSelect enumTimingInfo);
extern bit UserCommonModeSearchCheckPresetModeTable(BYTE ucModeNumber);
#endif
#endif
