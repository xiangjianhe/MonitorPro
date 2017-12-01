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
// ID Code      : RTD2011NVRamOsd.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_OSD_TYPE == _REALTEK_2011_OSD)

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
#define _PANEL_INDEX_ADDRESS                        (_VGA_MODE_DATA_ADDRESS_END + 1)
#define _OSD_DATA_ADDRESS                           (_PANEL_INDEX_ADDRESS + 1)
#define _BRICON_DATA_ADDRESS                        (_OSD_DATA_ADDRESS + sizeof(StructOsdUserDataType))
#define _COLORTEMP_DATA_ADDRESS                     (_BRICON_DATA_ADDRESS + (sizeof(StructBriConDataType) * _SOURCE_AMOUNT))
#define _SIXCOLOR_DATA_ADDRESS                      (_COLORTEMP_DATA_ADDRESS + (sizeof(StructColorProcDataType) * _CT_COLORTEMP_AMOUNT))
#define _OSD_DATA_USER_ADDRESS_END                  (_SIXCOLOR_DATA_ADDRESS + sizeof(StructSixColorDataType))
//---------------------------------------------------------------------------------------------------------------------------------------

#define _FACTORY_SETTING_DATA_ADDRESS               (_OSD_DATA_USER_ADDRESS_END)
#define _PANEL_TIME_DATA_ADDRESS                    (_FACTORY_SETTING_DATA_ADDRESS)
#define _PANEL_TIME_DATA_ADDRESS_END                (_PANEL_TIME_DATA_ADDRESS + sizeof(StructTimeType))

//--------------------------------------------------------------------------------------------
#endif

typedef struct
{
    BYTE ucBackLight;           
    BYTE ucOsdHPos;
    BYTE ucOsdVPos;
    BYTE ucOsdTimeout;
    BYTE ucAspectOriginRatio;
//--------------------------------------------------------
    BYTE b4Language : 4;
    BYTE b4ColorEffect : 4;
//--------------------------------------------------------
    BYTE b4ColorTempType : 4;
    BYTE b2VGARGBYUV : 2;
    BYTE b2DVIRGBYUV : 2;
//--------------------------------------------------------
    BYTE b3Sharpness : 3;
    BYTE b3Transparency : 3;
    BYTE b1OsdRotate : 1;       
    BYTE b1OverScan : 1;
//--------------------------------------------------------
    BYTE b3Gamma : 3;
    BYTE b3AspectRatio : 3;     
    BYTE b1DDCCIStatus : 1;     
    BYTE b1OsdESStatus : 1;       
//--------------------------------------------------------
    BYTE ucODGain;              
    BYTE ucHue;
    BYTE ucSaturation;
    BYTE ucHLWinType;
    BYTE uc3DEffect;
    BYTE uc3DConvergence;    
//--------------------------------------------------------
    BYTE b2PCMStatus : 2;
    BYTE b23DStatus : 2;
    BYTE b23DFormatStatus : 2;
    BYTE b13DLRStatus : 1;
    BYTE b13D3DTO2DStatus : 1;
//--------------------------------------------------------
    BYTE b2UltraVividStatus : 2;
    BYTE b1Osd3DOSD : 1;
    BYTE b1VolumeMute : 1;
    BYTE b1AudioStandAloneStatus : 1;
    BYTE b1AudioSourceStatus : 1;
    BYTE b1ODStatus : 1;        
//--------------------------------------------------------
    BYTE ucVolume;
//--------------------------------------------------------
    BYTE b33DConvergenceMode : 3;
    BYTE b1FactoryAutoColorType : 1;
} StructOsdUserDataType;

typedef struct
{
    BYTE ucColorTempR;
    BYTE ucColorTempG;
    BYTE ucColorTempB;
} StructColorProcDataType;

typedef struct
{
    BYTE ucBrightness;
    BYTE ucContrast;

} StructBriConDataType;

typedef struct
{
    WORD usHour;
    BYTE ucMin;
}StructTimeType;

typedef struct
{
    BYTE ucSixColorHueR;
    BYTE ucSixColorSaturationR;
    BYTE ucSixColorHueY;
    BYTE ucSixColorSaturationY;
    BYTE ucSixColorHueG;
    BYTE ucSixColorSaturationG;
    BYTE ucSixColorHueC;
    BYTE ucSixColorSaturationC;
    BYTE ucSixColorHueB;
    BYTE ucSixColorSaturationB;
    BYTE ucSixColorHueM;
    BYTE ucSixColorSaturationM;
} StructSixColorDataType;

//----------------------------------------------------------------------------------------
// Extern functions from RTD2011NVRamOsd.c
//----------------------------------------------------------------------------------------
#ifndef __RTD_NVRAM_OSD__

extern StructOsdUserDataType g_stOSDUserData;
extern StructBriConDataType g_stBriConData;
extern StructColorProcDataType g_stColorProcData;
extern code StructColorProcDataType g_stColorTempDefaultData[]; 
extern StructSixColorDataType g_stSixColorData;
extern StructTimeType g_stPanelTimeData;

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

extern void RTDEepromStartup(void);
extern void RTDEepromWholeRestore(void);
extern void RTDEepromRestoreBacklight(void);
extern void RTDEepromSaveOSDData(void);
extern void RTDEepromRestoreOSDData(void);
extern void RTDEepromLoadBriCon(BYTE ucSource);
extern void RTDEepromSaveBriCon(BYTE ucSource);
extern void RTDEepromRestoreBriCon(void);
extern void RTDEepromLoadColorSetting(BYTE ucColorTempType);
extern void RTDEepromSaveColorSetting(BYTE ucColorTempType);
extern void RTDEepromRestoreColorSetting(void);
extern void RTDEepromRestoreUserColorSetting(void);
extern void RTDEepromSaveSixColorData(void);
extern void RTDEepromRestoreSixColorData(void);
extern void RTDEepromSavePanelUsedTimeData(void);

#define RTDNVRamStartup()                              RTDEepromStartup()
#define RTDNVRamWholeRestore()                         RTDEepromWholeRestore()
#define RTDNVRamRestoreBacklight()                     RTDEepromRestoreBacklight()
#define RTDNVRamSaveOSDData()                          RTDEepromSaveOSDData()
#define RTDNVRamRestoreOSDData()                       RTDEepromRestoreOSDData()
#define RTDNVRamLoadBriCon(x)                          RTDEepromLoadBriCon(x)
#define RTDNVRamSaveBriCon(x)                          RTDEepromSaveBriCon(x)
#define RTDNVRamRestoreBriCon()                        RTDEepromRestoreBriCon()
#define RTDNVRamLoadColorSetting(x)                    RTDEepromLoadColorSetting(x)
#define RTDNVRamSaveColorSetting(x)                    RTDEepromSaveColorSetting(x)
#define RTDNVRamRestoreColorSetting()                  RTDEepromRestoreColorSetting()
#define RTDNVRamRestoreUserColorSetting()              RTDEepromRestoreUserColorSetting()
#define RTDNVRamSaveSixColorData()                     RTDEepromSaveSixColorData()
#define RTDNVRamRestoreSixColorData()                  RTDEepromRestoreSixColorData()
#define RTDNVRamSavePanelUsedTimeData()                RTDEepromSavePanelUsedTimeData()

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

extern bit RTDFlashMoveData(BYTE ucPageID, BYTE* pucData);
extern void RTDFlashStartup(void);
extern void RTDFlashWholeRestore(void);
extern void RTDFlashRestoreBacklight(void);
extern void RTDFlashSaveOSDData(void);
extern void RTDFlashRestoreOSDData(void);
extern void RTDFlashLoadBriCon(BYTE ucSource);
extern void RTDFlashSaveBriCon(BYTE ucSource);
extern void RTDFlashRestoreBriCon(void);
extern void RTDFlashLoadColorSetting(BYTE ucColorTempType);
extern void RTDFlashSaveColorSetting(BYTE ucColorTempType);
extern void RTDFlashRestoreColorSetting(void);
extern void RTDFlashRestoreUserColorSetting(void);
extern void RTDFlashSaveSixColorData(void);
extern void RTDFlashRestoreSixColorData(void);
extern void RTDFlashSavePanelUsedTimeData(void);

#define RTDNVRamStartup()                              RTDFlashStartup()
#define RTDNVRamWholeRestore()                         RTDFlashWholeRestore()
#define RTDNVRamRestoreBacklight()                     RTDFlashRestoreBacklight()
#define RTDNVRamSaveOSDData()                          RTDFlashSaveOSDData()
#define RTDNVRamRestoreOSDData()                       RTDFlashRestoreOSDData()
#define RTDNVRamLoadBriCon(x)                          RTDFlashLoadBriCon(x)
#define RTDNVRamSaveBriCon(x)                          RTDFlashSaveBriCon(x)
#define RTDNVRamRestoreBriCon()                        RTDFlashRestoreBriCon()
#define RTDNVRamLoadColorSetting(x)                    RTDFlashLoadColorSetting(x)
#define RTDNVRamSaveColorSetting(x)                    RTDFlashSaveColorSetting(x)
#define RTDNVRamRestoreColorSetting()                  RTDFlashRestoreColorSetting()
#define RTDNVRamRestoreUserColorSetting()              RTDFlashRestoreUserColorSetting()
#define RTDNVRamSaveSixColorData()                     RTDFlashSaveSixColorData()
#define RTDNVRamRestoreSixColorData()                  RTDFlashRestoreSixColorData()
#define RTDNVRamSavePanelUsedTimeData()                RTDFlashSavePanelUsedTimeData()

#endif // End of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

#endif // End of #ifndef __RTD_NVRAM_OSD__

#endif // End of #if(_OSD_TYPE == _REALTEK_2011_OSD)
