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
// ID Code      : RTD2011NVRamOsd.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_NVRAM_OSD__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)

//--------------------------------------------------
// Version Code of NVRam
//--------------------------------------------------
#define _CHECKSUM                                   0x14
#define _VERSION_CODE                               0x26 

//--------------------------------------------------
// Brightness/Contrast Default Value
//--------------------------------------------------
#define _BRIGHTNESS_VGA                             0x7E
#define _CONTRAST_VGA                               0x80

#define _BRIGHTNESS_DVI                             0x80
#define _CONTRAST_DVI                               0x80

#define _BRIGHTNESS_VIDEO8                          0x80
#define _CONTRAST_VIDEO8                            0x80

#define _BRIGHTNESS_YPBPR                           0x80
#define _CONTRAST_YPBPR                             0x80

#define _BRIGHTNESS_HDMI                            0x80
#define _CONTRAST_HDMI                              0x80

#define _BRIGHTNESS_DP                              0x80
#define _CONTRAST_DP                                0x80

//--------------------------------------------------
// Six Color Data Default Values
//--------------------------------------------------
#define _SIX_COLOR_HUE_R                            50
#define _SIX_COLOR_SATURATION_R                     100

#define _SIX_COLOR_HUE_Y                            50
#define _SIX_COLOR_SATURATION_Y                     100

#define _SIX_COLOR_HUE_G                            50
#define _SIX_COLOR_SATURATION_G                     100

#define _SIX_COLOR_HUE_C                            50
#define _SIX_COLOR_SATURATION_C                     100

#define _SIX_COLOR_HUE_B                            50
#define _SIX_COLOR_SATURATION_B                     100

#define _SIX_COLOR_HUE_M                            50
#define _SIX_COLOR_SATURATION_M                     100

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
//--------------------------------------------------
// Definitions of PageInfo Address
//--------------------------------------------------
#define _FLASH_FW_CHECKSUM_ADDR                     (_FLASH_PAGE_SIZE - 16)
#define _FLASH_FW_VERSIONCODE_ADDR                  (_FLASH_PAGE_SIZE - 15)
#define _PAGEINFO_CHECKSUM_ADDR                     (_FLASH_PAGE_SIZE - 5)
#define _PAGEINFO_PAGEID_ADDR                       (_FLASH_PAGE_SIZE - 4)
#define _PAGEINFO_MOVECOUNT_ADDR                    (_FLASH_PAGE_SIZE - 3)

// This value is used to indicate the EEPROM emulaiton FW version
#define _EEPROM_EMULATION_VERSION                   0x01
#endif

// Attention: it is necessary for sizeof(StructOsdUserDataType) < ((_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START) * (_DATA_ITEM_LENGTH - 2))
// Please check it when add items in StructOsdUserDataType
code StructOsdUserDataType g_stOSDDefaultData = 
{
    0x80,                     // ucBackLight;           
    100,                      // ucOsdHPos;
    100,                      // ucOsdVPos;
    10,                       // ucOsdTimeout;
    0,                        // ucAspectOriginRatio
//--------------------------------------------------------
    _ENGLISH,                 // b4Language;
    _COLOREFFECT_STANDARD,    // b4ColorEffect;
//--------------------------------------------------------
    _CT_OFF,                  // b4ColorTempType;
    _COLOR_SPACE_RGB,         // b2VGARGBYUV;
    _COLOR_SPACE_RGB,         // b2DVIRGBYUV;
//--------------------------------------------------------
    2,                        // b3Sharpness;
    2,                        // b3Transparency;
    _OFF,                     // b1OsdRotate;       
    _ON,                      // b1OverScan;
//--------------------------------------------------------
    _GAMMA_OFF,               // b3Gamma;
    _ASPECT_RATIO_FULL,       // b3AspectRatio; 
    _ON,                      // b1DDCCIStatus;
    _OFF,                     // b1OsdESStatus;       
//--------------------------------------------------------
    _OD_GAIN_CENTER,          // ucODGain;              
    _DEFAULT_HUE,             // cHue;
    _DEFAULT_SATURATION,      // ucSaturation;
    _HL_WIN_OFF,              // ucHLWinType;
    0x00,                     // uc3DEffect;
    0x00,                     // uc3DConvergence;    
//--------------------------------------------------------
    _PCM_OSD_NATIVE,          // b2PCMStatus : 2;
    _3D_OFF,                  // b23DStatus : 2;
    _3D_MODE_FORMAT_AUTO,     // b23DFormatStatus : 2;
    _3D_DISPLAY_RL,           // b13DLRStatus : 1;
    _OFF,                     // b13D3DTO2DStatus : 1;
//--------------------------------------------------------
    _ULTRA_VIVID_OFF,         // b2UltraVividStatus : 2;
    _OFF,                     // b1Osd3DOSD : 1;
    _OFF,                     // b1VolumeMute : 1;
    _OFF,                     // b1AudioStandAloneStatus : 1;
    0,                        // b1AudioSourceStatus : 1;
    _OFF,                     // b1ODStatus : 1;        
//--------------------------------------------------------
    50,                       // ucVolume;
//--------------------------------------------------------
    0x00,                     // b33DConvergenceMode : 3;
    _AUTO_COLOR_TYPE_EXTERNAL, // b1FactoryAutoColorType : 1;
};

code StructBriConDataType g_stBriConDefaultData[] = 
{
    {
        _BRIGHTNESS_VGA,
        _CONTRAST_VGA,
    },

    {
        _BRIGHTNESS_YPBPR,
        _CONTRAST_YPBPR,
    },

    {
        _BRIGHTNESS_VIDEO8,
        _CONTRAST_VIDEO8,
    },

    {
        _BRIGHTNESS_DVI,
        _CONTRAST_DVI,
    },

    {
        _BRIGHTNESS_HDMI,
        _CONTRAST_HDMI,
    },

    {
        _BRIGHTNESS_DP,
        _CONTRAST_DP,
    },

};

code StructColorProcDataType g_stColorTempDefaultData[] = 
{
    {
        _CT9300_RED,
        _CT9300_GREEN,
        _CT9300_BLUE,
    },

    {
        _CT7500_RED,
        _CT7500_GREEN,
        _CT7500_BLUE,
    },

    {
        _CT6500_RED,
        _CT6500_GREEN,
        _CT6500_BLUE,
    },

    {
        _CT5800_RED,
        _CT5800_GREEN,
        _CT5800_BLUE,
    },

    {
        _CTSRGB_RED,
        _CTSRGB_GREEN,
        _CTSRGB_BLUE,
    },

    {
        _CTUSER_RED,
        _CTUSER_GREEN,
        _CTUSER_BLUE,
    },
};

code StructSixColorDataType g_stSixColorDefaultData =
{
    _SIX_COLOR_HUE_R,
    _SIX_COLOR_SATURATION_R,
    _SIX_COLOR_HUE_Y,
    _SIX_COLOR_SATURATION_Y,
    _SIX_COLOR_HUE_G,
    _SIX_COLOR_SATURATION_G,
    _SIX_COLOR_HUE_C,
    _SIX_COLOR_SATURATION_C,
    _SIX_COLOR_HUE_B,
    _SIX_COLOR_SATURATION_B,
    _SIX_COLOR_HUE_M,
    _SIX_COLOR_SATURATION_M,
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructOsdUserDataType g_stOSDUserData;
StructBriConDataType g_stBriConData;
StructColorProcDataType g_stColorProcData;
StructSixColorDataType g_stSixColorData;
StructTimeType g_stPanelTimeData;
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)
DWORD g_ulFlashMoveCount = 0;
BYTE g_ucFlashLastPage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
WORD g_usFlashAddrArr[_END_OF_PAGEID - _START_OF_PAGEID + 1] = {0};
BYTE g_ucFlashPageArr[_END_OF_PAGEID - _START_OF_PAGEID + 1] = {0};
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
void RTDEepromStartup(void);
void RTDEepromWholeRestore(void);
void RTDEepromLoadOSDData(void);
void RTDEepromSaveOSDData(void);
void RTDEepromRestoreOSDData(void);
void RTDEepromSaveBriCon(BYTE ucSource);
void RTDEepromLoadBriCon(BYTE ucSource);
void RTDEepromRestoreBriCon(void);
void RTDEepromLoadColorSetting(BYTE ucColorTempType);
void RTDEepromSaveColorSetting(BYTE ucColorTempType);
void RTDEepromRestoreColorSetting(void);
void RTDEepromRestoreUserColorSetting(void);
void RTDEepromLoadSixColorData(void);
void RTDEepromSaveSixColorData(void);
void RTDEepromRestoreSixColorData(void);
void RTDEepromLoadPanelUsedTimeData(void);
void RTDEepromSavePanelUsedTimeData(void);
void RTDEepromRestorePanelUsedTimeData(void);

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

BYTE RTDFlashGetFreePage();
bit RTDFlashIsPageInfoValid(BYTE ucPage);
void RTDFlashInitialDataPage(BYTE ucPageID);
WORD RTDFlashSearchPageAddr(BYTE ucPageID);
void RTDFlashInitialAddr(void);
void RTDFlashLoadChecksumVersioncode(BYTE* pucChecksum, BYTE* pucVersionCode);
void RTDFlashSaveChecksumVersionCode(BYTE ucChecksum, BYTE ucVersionCode);
bit RTDFlashMoveData(BYTE ucPageID, BYTE* pucData);

void RTDFlashStartup(void);
void RTDFlashWholeRestore(void);
void RTDFlashLoadOSDData(void);
void RTDFlashSaveOSDData(void);
void RTDFlashRestoreOSDData(void);
void RTDFlashSaveBriCon(BYTE ucSource);
void RTDFlashLoadBriCon(BYTE ucSource);
void RTDFlashRestoreBriCon(void);
void RTDFlashLoadColorSetting(BYTE ucColorTempType);
void RTDFlashSaveColorSetting(BYTE ucColorTempType);
void RTDFlashRestoreColorSetting(void);
void RTDFlashRestoreUserColorSetting(void);
void RTDFlashLoadSixColorData(void);
void RTDFlashSaveSixColorData(void);
void RTDFlashRestoreSixColorData(void);
void RTDFlashLoadPanelUsedTimeData(void);
void RTDFlashSavePanelUsedTimeData(void);
void RTDFlashRestorePanelUsedTimeData(void);
#if(_PANEL_EXIST_MULTIPANEL == _ON)
void RTDFlashLoadPanelIndex(void);
void RTDFlashSavePanelIndex(void);
void RTDFlashRestorePanelIndex(void);
#endif // End of #if(_PANEL_EXIST_MULTIPANEL == _ON)

#endif // End of #elif(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)

#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Eeprom check at firmware startup
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromStartup(void)
{
    BYTE ucCnt = 0;

    // Check twice if VERSION CODE matches
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        pData[0] = _CHECKSUM ^ 0xFF;
        pData[1] = _VERSION_CODE ^ 0xFF;
        UserCommonEepromRead(_EEPROM_CHECKSUM_ADDRESS, 2, pData);

        if((pData[0] == _CHECKSUM) && (pData[1] == _VERSION_CODE))
        {
            break;
        }
    }

    if(pData[0] != _CHECKSUM)
    {
        // Load default value and save to EEPROM
        RTDEepromWholeRestore();

        // Save VERSION CODE to EEPROM
        pData[0] = _CHECKSUM;
        pData[1] = _VERSION_CODE;
        pData[2] = 0; // _PANEL_INDEX_ADDRESS

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        SET_MDOMAIN_PANEL_INDEX(0);
#endif        

        UserCommonEepromWrite(_EEPROM_CHECKSUM_ADDRESS, 2, pData);  
        UserCommonEepromWrite(_PANEL_INDEX_ADDRESS, 1, &pData[2]);  
    }
    else if(pData[1] != _VERSION_CODE)
    {
        g_stColorProcData = g_stColorTempDefaultData[_CT_USER];
        RTDEepromSaveColorSetting(_CT_USER);

        UserCommonEepromRestoreSystemData();
        RTDEepromRestoreOSDData();
        
#if(_VGA_SUPPORT == _ON)
        UserCommonEepromRestoreModeUserData();
#endif

        RTDEepromRestoreBriCon();
        RTDEepromRestoreSixColorData();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        UserCommonEepromRead(_PANEL_INDEX_ADDRESS, 1, pData);
        SET_MDOMAIN_PANEL_INDEX(pData[0]);
#endif

        pData[1] = _VERSION_CODE;
        UserCommonEepromWrite(_EEPROM_VERSION_CODE_ADDRESS, 1, &pData[1]);  
    }
    else
    {
        UserCommonEepromLoadSystemData();
        RTDEepromLoadOSDData();
        RTDEepromLoadSixColorData();
        RTDEepromLoadPanelUsedTimeData();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        UserCommonEepromRead(_PANEL_INDEX_ADDRESS, 1, pData);
        SET_MDOMAIN_PANEL_INDEX(pData[0]);
#endif        

        // Check PCM Flag
        if(GET_OSD_PCM_STATUS() > _PCM_OSD_AMOUNT)
        {
            SET_OSD_PCM_STATUS(_PCM_OSD_NATIVE);
            RTDEepromSaveOSDData();
        }

#if(_OSD_3D_FUNCTION == _ON)
        if((GET_OSD_3DOSD_STATUS() == _ON) && (GET_OSD_ROTATE_STATUS() == _ON))
        {
            SET_OSD_ROTATE_STATUS(_OFF);
            RTDEepromSaveOSDData();
        }
#endif

    }

    RTDEepromLoadColorSetting(GET_COLOR_TEMP_TYPE());
}

//--------------------------------------------------
// Description  : Load default data and save to EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromWholeRestore(void)
{
    UserCommonEepromRestoreSystemData();
    RTDEepromRestoreOSDData();

#if(_VGA_SUPPORT == _ON)    
    UserCommonEepromRestoreModeUserData();
    UserCommonEepromRestoreADCSetting();
#endif

    RTDEepromRestoreBriCon();
    RTDEepromRestoreColorSetting();
    RTDEepromRestoreSixColorData();
    RTDEepromRestorePanelUsedTimeData();

#if((_DIGITAL_PORT_SUPPORT == _ON) && (_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
    UserInterfaceNVRamRestoreHDCP();
#endif

}

//--------------------------------------------------
// Description  : Restore default backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreBacklight(void)
{
    SET_OSD_BACKLIGHT(g_stOSDDefaultData.ucBackLight);
    RTDEepromSaveOSDData();
}

//--------------------------------------------------
// Description  : Load OSD data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadOSDData(void)
{
    UserCommonEepromRead(_OSD_DATA_ADDRESS, sizeof(StructOsdUserDataType), (BYTE *)(&g_stOSDUserData));
}

//--------------------------------------------------
// Description  : Save OSD data to EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromSaveOSDData(void)
{
    UserCommonEepromWrite(_OSD_DATA_ADDRESS, sizeof(StructOsdUserDataType), (BYTE *)(&g_stOSDUserData));
}

//--------------------------------------------------
// Description  : Restore default OSD data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreOSDData(void)
{
    g_stOSDUserData = g_stOSDDefaultData;
    RTDEepromSaveOSDData();
}

//--------------------------------------------------
// Description  : Load brightness/contrast from EEPROM
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadBriCon(BYTE ucSource)
{
    UserCommonEepromRead(_BRICON_DATA_ADDRESS + ucSource * sizeof(StructBriConDataType), sizeof(StructBriConDataType), (BYTE *)(&g_stBriConData));
}

//--------------------------------------------------
// Description  : Save brightness/contrast to EEPROM
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDEepromSaveBriCon(BYTE ucSource)
{
    UserCommonEepromWrite(_BRICON_DATA_ADDRESS + ucSource * sizeof(StructBriConDataType), sizeof(StructBriConDataType), (BYTE *)(&g_stBriConData));
}

//--------------------------------------------------
// Description  : Restore default brightness/contrast
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreBriCon(void)
{
    BYTE ucTemp = 0;
    
    for(ucTemp = 0; ucTemp < _SOURCE_AMOUNT; ucTemp++)
    {
        g_stBriConData = g_stBriConDefaultData[ucTemp];
        RTDEepromSaveBriCon(ucTemp);
    }
}

//--------------------------------------------------
// Description  : Load color settings from EEPROM
// Input Value  : ucSource --> Source Type
//                ucColorTempType --> Color Temp Type
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadColorSetting(BYTE ucColorTempType)
{
    if(ucColorTempType != _CT_OFF)
    {

#if(_OGC_SUPPORT == _ON)
        if(GET_OSD_GAMMA() != _GAMMA_OFF)
        {
            UserCommonFlashRead(_OGC_FLASH_BANK, ((WORD)_OGC_FLASH_PAGE << 12) | (ucColorTempType * _OGC_TOTAL_GAMMA * 3 + GET_OSD_GAMMA() * 3), 3, pData);
            SET_COLOR_TEMP_TYPE_USER_R(pData[0]);
            SET_COLOR_TEMP_TYPE_USER_G(pData[1]);
            SET_COLOR_TEMP_TYPE_USER_B(pData[2]);
        }
        else
#endif
        {
            UserCommonEepromRead(_COLORTEMP_DATA_ADDRESS + ucColorTempType * sizeof(StructColorProcDataType), sizeof(StructColorProcDataType), (BYTE *)(&g_stColorProcData.ucColorTempR));
        }
    }
    else
    {
        g_stColorProcData.ucColorTempR = 0x80;
        g_stColorProcData.ucColorTempG = 0x80;
        g_stColorProcData.ucColorTempB = 0x80;
    }
}

//--------------------------------------------------
// Description  : Save color settings to EEPROM
// Input Value  : ucSource --> Source Type
//                ucColorTempType --> Color Temp Type
// Output Value : None
//--------------------------------------------------
void RTDEepromSaveColorSetting(BYTE ucColorTempType)
{
    if(ucColorTempType != _CT_OFF)
    {
        UserCommonEepromWrite(_COLORTEMP_DATA_ADDRESS + ucColorTempType * sizeof(StructColorProcDataType), sizeof(StructColorProcDataType), (BYTE *)(&g_stColorProcData.ucColorTempR));
    }
}

//--------------------------------------------------
// Description  : Restore default color settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreColorSetting(void)
{
    BYTE ucTemp = 0;

    for(ucTemp = 0; ucTemp < _CT_COLORTEMP_AMOUNT; ucTemp++)
    {
        g_stColorProcData = g_stColorTempDefaultData[ucTemp];
        RTDEepromSaveColorSetting(ucTemp);
    }
}

//--------------------------------------------------
// Description  : Restore default color settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreUserColorSetting(void)
{
    StructColorProcDataType stUserColorTemp;
    
    stUserColorTemp = g_stColorTempDefaultData[_CT_USER];

    UserCommonEepromWrite(_COLORTEMP_DATA_ADDRESS + _CT_USER * sizeof(StructColorProcDataType), sizeof(StructColorProcDataType), (BYTE *)(&stUserColorTemp));
}

//--------------------------------------------------
// Description  : Load six color data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadSixColorData(void)
{
    UserCommonEepromRead(_SIXCOLOR_DATA_ADDRESS, sizeof(StructSixColorDataType), (BYTE *)(&g_stSixColorData));
}

//--------------------------------------------------
// Description  : Save six color data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromSaveSixColorData(void)
{
    UserCommonEepromWrite(_SIXCOLOR_DATA_ADDRESS, sizeof(StructSixColorDataType), (BYTE *)(&g_stSixColorData));
}

//--------------------------------------------------
// Description  : Restore default six color data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestoreSixColorData(void)
{
    g_stSixColorData = g_stSixColorDefaultData;
    RTDEepromSaveSixColorData();
}

//--------------------------------------------------
// Description  : Load Panel Used Time Data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromLoadPanelUsedTimeData(void)
{
    UserCommonEepromRead(_PANEL_TIME_DATA_ADDRESS, sizeof(StructTimeType), (BYTE *)(&g_stPanelTimeData));
}

//--------------------------------------------------
// Description  : Save Panel Used Time Data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromSavePanelUsedTimeData(void)
{
    UserCommonEepromWrite(_PANEL_TIME_DATA_ADDRESS, sizeof(StructTimeType), (BYTE *)(&g_stPanelTimeData));
}

//--------------------------------------------------
// Description  : Restore Panel Used Time Data from EEPROM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDEepromRestorePanelUsedTimeData(void)
{
    SET_PANEL_TIME_HOUR(0);
    SET_PANEL_TIME_MIN(0);
    RTDEepromSavePanelUsedTimeData();
}

#else // Else of #if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)

//--------------------------------------------------
// Description  : Get the free page number of flash
// Input Value  : None
// Output Value : Free page index
//--------------------------------------------------
BYTE RTDFlashGetFreePage()
{
	BYTE ucPageID = _START_OF_PAGEID;
	BYTE ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;

    // If the _END_PAGE page has the biggest move count, suppose first page is free page
    if(g_ulFlashMoveCount > 0)
    {
        if(g_ucFlashLastPage >= _SYSTEM_EEPROM_EMULATION_END_PAGE)
        {
            ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
        }
        else
        {
            ucFreePage = g_ucFlashLastPage + 1;
        }
    }

    // Check the supposed free page is actual free page which has not been used ever
    do
    {
        if(ucFreePage == g_ucFlashPageArr[ucPageID])
        {
            if(ucFreePage >= _SYSTEM_EEPROM_EMULATION_END_PAGE)
            {
                ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
            }
            else
            {
                ucFreePage += 1;
            }

            ucPageID = _START_OF_PAGEID;
        }
    	else
    	{
			ucPageID++;
    	}
    }
    while(ucPageID <= _END_OF_PAGEID);

    return ucFreePage;
}

//--------------------------------------------------
// Description  : Check the page is vaild or not
// Input Value  : ucPage: The page to be check, must between 0 and (_END_PAGE - _START_PAGE)
// Output Value : _TRUE means the page is valid, _FLASE is invalid
//--------------------------------------------------
bit RTDFlashIsPageInfoValid(BYTE ucPage)
{
    WORD usPageInfoAddr = ucPage * _FLASH_PAGE_SIZE;
    BYTE ucPageInfoChecksum = 0;
    BYTE ucPageInfo[5] = {0};

    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageInfoAddr + _PAGEINFO_CHECKSUM_ADDR, 5, ucPageInfo);
    ucPageInfoChecksum = ucPageInfo[1] ^ ucPageInfo[2] ^ ucPageInfo[3] ^ ucPageInfo[4];

    if(ucPageInfoChecksum == ucPageInfo[0])
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Initial data page
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashInitialDataPage(BYTE ucPageID)
{
    WORD usAddr = _SYSTEM_EEPROM_EMULATION_START_PAGE * _FLASH_PAGE_SIZE;
    BYTE ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;

	ucFreePage = RTDFlashGetFreePage();
    // Initial page index
    g_ucFlashPageArr[ucPageID] = ucFreePage;
    // Initial address
    g_usFlashAddrArr[ucPageID] = 0;
    // Initial move count
    g_ulFlashMoveCount++;
    g_ucFlashLastPage = ucFreePage;

    usAddr = g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE;
    UserCommonFlashErasePage(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[ucPageID]);

    pData[0] = ucPageID;
    pData[1] = (BYTE)(g_ulFlashMoveCount >> 16);
    pData[2] = (BYTE)(g_ulFlashMoveCount >> 8);
    pData[3] = (BYTE)g_ulFlashMoveCount;
    pData[4] = pData[0] ^ pData[1] ^ pData[2] ^ pData[3];
    UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usAddr + _PAGEINFO_PAGEID_ADDR, 4, pData);
    UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usAddr + _PAGEINFO_CHECKSUM_ADDR, 1, &pData[4]);
}

//--------------------------------------------------
// Description  : Search the last saved item address, and next new item position
// Input Value  :
// Output Value : 
//--------------------------------------------------
WORD RTDFlashSearchPageAddr(BYTE ucPageID)
{
    WORD usItemAddr = 0;
    WORD usPageAddr = 0;

    usPageAddr = g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE;

    // Find the last data item address
    for(usItemAddr = ((_FLASH_PAGE_SIZE - _PAGE_INFO_LENGTH) / _DATA_ITEM_LENGTH); usItemAddr > 0; usItemAddr--)
    {
        UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + (usItemAddr - 1) * _DATA_ITEM_LENGTH, 1, pData);
        if(pData[0] != 0xFF)
        {
            return usItemAddr;
        }
    }

    return 0;
}

//--------------------------------------------------
// Description  : Flash address initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashInitialAddr(void)
{
    BYTE ucCnt = 0;
    WORD usAddr = 0;
    DWORD ulMoveCount = 0;
    BYTE ucPageID = 0;

    g_ulFlashMoveCount = 0;
    g_ucFlashLastPage = _SYSTEM_EEPROM_EMULATION_START_PAGE;

    for(ucPageID = _START_OF_PAGEID; ucPageID <= _END_OF_PAGEID; ucPageID++)
    {
        g_ucFlashPageArr[ucPageID] = 0xFF;
    }
 	
    // Find the page whose move count is the biggest and get the max move count
    for(ucCnt = _SYSTEM_EEPROM_EMULATION_START_PAGE; ucCnt < (_SYSTEM_EEPROM_EMULATION_END_PAGE + 1); ucCnt++)
    {
        // Check the page is valid or not
        if(RTDFlashIsPageInfoValid(ucCnt) == _TRUE)
        {
            usAddr = ucCnt * _FLASH_PAGE_SIZE + _PAGEINFO_PAGEID_ADDR;

            // Get the move count of current page
            UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usAddr, 4, pData);
            ulMoveCount = ((DWORD)(pData[1]) << 16) | ((DWORD)(pData[2]) << 8) | ((DWORD)(pData[3]));

            // Get the max move count and its page index
            if(ulMoveCount >= g_ulFlashMoveCount)
            {
                g_ucFlashPageArr[pData[0]] = ucCnt;
                g_ulFlashMoveCount = ulMoveCount;
                g_ucFlashLastPage = ucCnt;
            }
            // Check Other vaild page index
    		else
    		{
    			if(g_ucFlashPageArr[pData[0]] == 0xFF)
    			{
    				g_ucFlashPageArr[pData[0]] = ucCnt;
    			}
    			else // Check which page have begger Movecount
    			{
    				usAddr = g_ucFlashPageArr[pData[0]] * _FLASH_PAGE_SIZE + _PAGEINFO_MOVECOUNT_ADDR;
    				UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usAddr, 3, &pData[1]);											
    				if(ulMoveCount > (((DWORD)(pData[1]) << 16) | ((DWORD)(pData[2]) << 8) | ((DWORD)(pData[3]))))
    				{
    					g_ucFlashPageArr[pData[0]] = ucCnt;
    				}
    			}
    		}
        }
    }

    // If this page is missing, intial this single page
    for(ucPageID = _START_OF_PAGEID; ucPageID <= _END_OF_PAGEID; ucPageID++)
    {
        if(g_ucFlashPageArr[ucPageID] == 0xFF)
        {
            // This function will increase g_ulFlashMovePage,and now g_ucFlashLastPage is the page index which has the biggest move count value
            RTDFlashInitialDataPage(ucPageID);
            RTDFlashSaveChecksumVersionCode(_CHECKSUM, _VERSION_CODE);
        }
        else
        {
            // Initial g_usFlashAddrArr
            g_usFlashAddrArr[ucPageID] = RTDFlashSearchPageAddr(ucPageID);
        }
    }
}

//--------------------------------------------------
// Description  : Get the checksum and version code from flash
// Input Value  : pucChecksum: the checksum get from flash
//                pucVersionCode: the version code get from flash
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadChecksumVersioncode(BYTE* pucChecksum, BYTE* pucVersionCode)
{
    // Get the checksum and version code
    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, pucChecksum);
    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, pucVersionCode);
}

//--------------------------------------------------
// Description  : Save the checksum & version code to flash
// Input Value  : ucChecksum, checksum value
//                ucVersionCode, version code value
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveChecksumVersionCode(BYTE ucChecksum, BYTE ucVersionCode)
{
    BYTE ucVersionCodeRead = 0;
    BYTE ucChecksumRead = 0;

    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCodeRead);
    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksumRead);

    // Do not need save checksum or version code
    if((ucVersionCode == ucVersionCodeRead) && (ucChecksum == ucChecksumRead))
    {
        return;
    }
    // Need to save version code and checksum in current page
    else if((ucVersionCode != ucVersionCodeRead) && (ucVersionCodeRead == 0xFF) && (ucChecksum != ucChecksumRead) && (ucChecksumRead == 0xFF))
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCode);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
    }
    // Need to save version code in current page
    else if((ucVersionCode != ucVersionCodeRead) && (ucVersionCodeRead == 0xFF) && (ucChecksum == ucChecksumRead))
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCode);
    }
    // Need to save checksum in current page
    else if((ucChecksum != ucChecksumRead) && (ucChecksumRead == 0xFF) && (ucVersionCode == ucVersionCodeRead))
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
    }
    // Need to save checksum and version code to free page
    else
    {
        memset(pData, 0xFF, _DATA_ITEM_LENGTH);
        RTDFlashMoveData(_CHECKSUM_VERSIONCODE_ID, pData);

        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersionCode);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[_CHECKSUM_VERSIONCODE_ID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
    }    
}

//--------------------------------------------------
// Description  : Move data to another page of flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit RTDFlashMoveData(BYTE ucPageID, BYTE* pucData)
{
    BYTE ucPrevPage = g_ucFlashPageArr[ucPageID];
    BYTE ucFreePage = _SYSTEM_EEPROM_EMULATION_START_PAGE;
    BYTE ucItemIndex = 0;
    WORD usAddrIndex = 0;
    WORD usPageAddr = 0;
    WORD usPrevPageAddr = 0;
    WORD usMovedItemCount = 0;
    WORD usMovedAddrIndex = 0;
    BYTE ucItemID = 0;
    BYTE ucIndex = 0;
    BYTE ucChecksum = 0xFF;
    BYTE ucVersioncode = 0xFF;

    // Load checksum and version code
    if(pucData[0] != 0xFF)
    {
        RTDFlashLoadChecksumVersioncode(&ucChecksum, &ucVersioncode);
    }

    // Get free page data will move to
    ucFreePage = RTDFlashGetFreePage();

    // First sector erase the free page specified by g_ucFlashFreePage
    if(UserCommonFlashErasePage(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, ucFreePage) == _FALSE)
    {
        return _FALSE;
    }

    // Save the latest data item to the new page if need, when save checksum and version, it is not necessary
    // We do not save the item id at last because page info has not been saved
    if(pucData[0] != 0xFF)
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, ucFreePage * _FLASH_PAGE_SIZE + ucItemIndex, _DATA_ITEM_LENGTH, pucData);

        // Clear Buffer
        memset(pucData, 0xFF, _DATA_ITEM_LENGTH);

        // And then load the latest data items which saved in the old full page to the new page from bottom to top
        usMovedItemCount = 1;
    }
    else
    {
        usMovedItemCount = 0;
    }

    // Update ucFlashPage
    g_ucFlashPageArr[ucPageID] = ucFreePage;
    // Update move count value
    g_ulFlashMoveCount += 1;
    g_ucFlashLastPage = ucFreePage;

    usPrevPageAddr = ucPrevPage * _FLASH_PAGE_SIZE;
    usPageAddr = g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE;

    // Find the valid item and move to new free page
    for(usAddrIndex = ((_FLASH_PAGE_SIZE - _PAGE_INFO_LENGTH) / _DATA_ITEM_LENGTH); usAddrIndex > 0; usAddrIndex--)
    {
        UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPrevPageAddr + (usAddrIndex - 1) * _DATA_ITEM_LENGTH, 1, &ucItemID);

        if(ucItemID != 0xFF)
        {
            // Check the item has been moved or not by item ID
            for(usMovedAddrIndex = 0; usMovedAddrIndex < usMovedItemCount; usMovedAddrIndex++)
            {
                UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usMovedAddrIndex * _DATA_ITEM_LENGTH, 1, pData);
                if(pData[0] == ucItemID)
                {
                    break;
                }
            }

            if(usMovedAddrIndex >= usMovedItemCount)
            {
                // The item has not been moved, then check the item is valid or not
                pucData[15] = 0;
                for(ucIndex = 0; ucIndex < (_DATA_ITEM_LENGTH - 1); ucIndex++)
                {
                    UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPrevPageAddr + (usAddrIndex - 1) * _DATA_ITEM_LENGTH + ucIndex, 1, pData);
                    pucData[15] = pucData[15] ^ pData[0];
                }

                // Check the checksum
                UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPrevPageAddr + usAddrIndex * _DATA_ITEM_LENGTH - 1, 1, pData);
                if(pucData[15] != pData[0])
                {
                    // Checksum check fail, the item is invalid
                    continue;
                }

                // Move the item to new free page
                UserCommonFlashRead(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPrevPageAddr + (usAddrIndex - 1) * _DATA_ITEM_LENGTH + ucItemIndex, _DATA_ITEM_LENGTH, pData);
                UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, usPageAddr + usMovedItemCount * _DATA_ITEM_LENGTH + ucItemIndex, _DATA_ITEM_LENGTH, pData);

                usMovedItemCount++;
            }
        }
    }

    // Update the data item address in the new page
    g_usFlashAddrArr[ucPageID] = usMovedItemCount;

    // Last update the new moved page info fields
    // Save checksum & version code
    if(ucPageID == _CHECKSUM_VERSIONCODE_ID)
    {
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE + _FLASH_FW_VERSIONCODE_ADDR, 1, &ucVersioncode);
        UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE + _FLASH_FW_CHECKSUM_ADDR, 1, &ucChecksum);
    }

    // Save page info
    pData[0] = ucPageID;
    pData[1] = (BYTE)(g_ulFlashMoveCount >> 16);
    pData[2] = (BYTE)(g_ulFlashMoveCount >> 8);
    pData[3] = (BYTE)g_ulFlashMoveCount;
    pData[4] = pData[0] ^ pData[1] ^ pData[2] ^ pData[3];
    UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE + _PAGEINFO_PAGEID_ADDR, 4, pData);
    UserCommonFlashWrite(_SYSTEM_EEPROM_EMULATION_FLASH_BANK, g_ucFlashPageArr[ucPageID] * _FLASH_PAGE_SIZE + _PAGEINFO_CHECKSUM_ADDR, 1, &pData[4]);

    return _TRUE;
}

//--------------------------------------------------
// Description  : Flash check at firmware startup
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashStartup(void)
{
    BYTE ucChecksum = 0;
    BYTE ucVersionCode = 0;
    BYTE ucPageID = 0;

    RTDFlashInitialAddr();

    // Get FW checksum and version code
    RTDFlashLoadChecksumVersioncode(&ucChecksum, &ucVersionCode);

    if(ucChecksum != _CHECKSUM)
    {
        // Checksum is changed, load default value and save to flash
        for(ucPageID = _START_OF_PAGEID; ucPageID <= _END_OF_PAGEID; ucPageID++)
        {
            RTDFlashInitialDataPage(ucPageID);
        }

        RTDFlashWholeRestore();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        RTDFlashRestorePanelIndex();
#endif        

        RTDFlashSaveChecksumVersionCode(_CHECKSUM, _VERSION_CODE);
    }
    else if(ucVersionCode != _VERSION_CODE)
    {
        // Restore CT User color setting
        g_stColorProcData = g_stColorTempDefaultData[_CT_USER];
        if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_COLORPROC0_9300 + _CT_USER, pData, 1) == _TRUE)
        {
            RTDFlashSaveColorSetting(_CT_USER);
        }

        UserCommonFlashRestoreSystemData();
        RTDFlashRestoreOSDData();
        
#if(_VGA_SUPPORT == _ON)
        UserCommonFlashRestoreModeUserData();
#endif

        RTDFlashRestoreBriCon();
        RTDFlashRestoreSixColorData();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        RTDFlashLoadPanelIndex();
#endif

        RTDFlashSaveChecksumVersionCode(_CHECKSUM, _VERSION_CODE);
    }
    else
    {
        UserCommonFlashLoadSystemData();
        RTDFlashLoadOSDData();
        RTDFlashLoadSixColorData();
        RTDFlashLoadPanelUsedTimeData();

#if(_PANEL_EXIST_MULTIPANEL == _ON)
        RTDFlashLoadPanelIndex();
#endif    

        // Check PCM Flag
        if(GET_OSD_PCM_STATUS() > _PCM_OSD_AMOUNT)
        {
            SET_OSD_PCM_STATUS(_PCM_OSD_NATIVE);
            RTDFlashSaveOSDData();
        }

#if(_OSD_3D_FUNCTION == _ON)
        if((GET_OSD_3DOSD_STATUS() == _ON) && (GET_OSD_ROTATE_STATUS() == _ON))
        {
            SET_OSD_ROTATE_STATUS(_OFF);
            RTDFlashSaveOSDData();
        }
#endif

    }

    RTDFlashLoadColorSetting(GET_COLOR_TEMP_TYPE());
}

//--------------------------------------------------
// Description  : Load default data and save to Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashWholeRestore(void)
{
    UserCommonFlashRestoreSystemData();
    RTDFlashRestoreOSDData();

#if(_VGA_SUPPORT == _ON)    
    UserCommonFlashRestoreModeUserData();
    UserCommonFlashRestoreADCSetting();
#endif

    RTDFlashRestoreBriCon();
    RTDFlashRestoreColorSetting();
    RTDFlashRestoreSixColorData();
    RTDFlashRestorePanelUsedTimeData();

#if((_DIGITAL_PORT_SUPPORT == _ON) && (_WRITE_HDCP_TO_SYSTEM_EEPROM == _ON) && (_HDCP_KEY_LOCATION == _TABLE_LOCATION_SYSTEM_EEPROM))
    UserInterfaceNVRamRestoreHDCP();
#endif
}

//--------------------------------------------------
// Description  : Restore default backlight
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreBacklight(void)
{
    BYTE ucItemOffset = 0;

    SET_OSD_BACKLIGHT(g_stOSDDefaultData.ucBackLight);

    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructOsdUserDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START + 1))
        {
            break;
        }

        if(UserInterfaceFlashLoadItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), pData, 1) == _FALSE)
        {
            return;
        }
    }

    RTDFlashSaveOSDData();
}

//--------------------------------------------------
// Description  : Load OSD data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadOSDData(void)
{
    BYTE ucItemOffset = 0;
    BYTE ucStructLen = sizeof(StructOsdUserDataType);
        
    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructOsdUserDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++) 
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START + 1))
        {
            break;
        }

        if(UserInterfaceFlashLoadItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), pData, _DATA_ITEM_LENGTH - 2) == _FALSE)
        {
            g_stOSDUserData = g_stOSDDefaultData;
            return;
        }

        if(ucStructLen > (_DATA_ITEM_LENGTH - 2))
        {
            memcpy((((BYTE*)(&g_stOSDUserData)) + (ucItemOffset * (_DATA_ITEM_LENGTH - 2))), pData, (_DATA_ITEM_LENGTH - 2));
            ucStructLen = ucStructLen - (_DATA_ITEM_LENGTH - 2);
        }
        else
        {
            memcpy((((BYTE*)(&g_stOSDUserData)) + (ucItemOffset * (_DATA_ITEM_LENGTH - 2))), pData, ucStructLen);
            break;
        }
    }
}


//--------------------------------------------------
// Description  : Save OSD data to Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveOSDData(void)
{
    BYTE ucItemOffset = 0;
    BYTE ucStructLen = sizeof(StructOsdUserDataType);

    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructOsdUserDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START + 1))
        {
            break;
        }

        if(ucStructLen > (_DATA_ITEM_LENGTH - 2))
        {
            UserInterfaceFlashSaveItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), (((BYTE*)(&g_stOSDUserData)) + ucItemOffset * (_DATA_ITEM_LENGTH - 2)), _DATA_ITEM_LENGTH - 2);    
            ucStructLen -= (_DATA_ITEM_LENGTH - 2);
        }
        else
        {
            UserInterfaceFlashSaveItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), (((BYTE*)(&g_stOSDUserData)) + ucItemOffset * (_DATA_ITEM_LENGTH - 2)), ucStructLen);
            break;
        }
    }
}

//--------------------------------------------------
// Description  : Restore default OSD data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreOSDData(void)
{
    BYTE ucItemOffset = 0;
  
    g_stOSDUserData = g_stOSDDefaultData;
    
    for(ucItemOffset = 0; ucItemOffset < ((sizeof(StructOsdUserDataType) + (_DATA_ITEM_LENGTH - 2) - 1) / (_DATA_ITEM_LENGTH - 2)); ucItemOffset++)
    {
        // Here we check the total item number, it could not be smaller than the osd structure
        if(ucItemOffset > (_FLASH_ITEMID_OSD_DATA_END - _FLASH_ITEMID_OSD_DATA_START + 1))
        {
            break;
        }

        if(UserInterfaceFlashLoadItem((_FLASH_ITEMID_OSD_DATA_START + ucItemOffset), pData, 1) == _FALSE)
        {
            return;
        }
    }

    RTDFlashSaveOSDData();
}

//--------------------------------------------------
// Description  : Load brightness/contrast from Flash
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadBriCon(BYTE ucSource)
{
    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_BRICON_SRC0_VGA + ucSource, pData, sizeof(StructBriConDataType)) == _TRUE)
    {
        memcpy(&g_stBriConData, pData, sizeof(StructBriConDataType));
    }
    else
    {
        g_stBriConData = g_stBriConDefaultData[ucSource];
    }
}

//--------------------------------------------------
// Description  : Save brightness/contrast to Flash
// Input Value  : ucSource --> Source Type
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveBriCon(BYTE ucSource)
{
    UserInterfaceFlashSaveItem(_FLASH_ITEMID_BRICON_SRC0_VGA + ucSource, (BYTE *)(&g_stBriConData), sizeof(StructBriConDataType));
}

//--------------------------------------------------
// Description  : Restore default brightness/contrast
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreBriCon(void)
{
    BYTE ucSourceIndex = 0;
    
    for(ucSourceIndex = 0; ucSourceIndex < _SOURCE_AMOUNT; ucSourceIndex++)
    {
        g_stBriConData = g_stBriConDefaultData[ucSourceIndex];

        if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_BRICON_SRC0_VGA + ucSourceIndex, pData, 1) == _TRUE)
        {
            RTDFlashSaveBriCon(ucSourceIndex);
        }
    }
}

//--------------------------------------------------
// Description  : Load color settings from Flash
// Input Value  : ucSource --> Source Type
//                ucColorTempType --> Color Temp Type
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadColorSetting(BYTE ucColorTempType)
{
    if(ucColorTempType != _CT_OFF)
    {
        
#if(_OGC_SUPPORT == _ON)
        if(GET_OSD_GAMMA() != _GAMMA_OFF)
        {
            UserCommonFlashRead(_OGC_FLASH_BANK, ((WORD)_OGC_FLASH_PAGE << 12) | (ucColorTempType * _OGC_TOTAL_GAMMA * 3 + GET_OSD_GAMMA() * 3), 3, pData);
            SET_COLOR_TEMP_TYPE_USER_R(pData[0]);
            SET_COLOR_TEMP_TYPE_USER_G(pData[1]);
            SET_COLOR_TEMP_TYPE_USER_B(pData[2]);
        }
        else
#endif

        {
            if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_COLORPROC0_9300 + ucColorTempType, pData, sizeof(StructColorProcDataType)) == _TRUE)
            {
                memcpy(&g_stColorProcData, pData, sizeof(StructColorProcDataType));
            }
            else
            {
                g_stColorProcData = g_stColorTempDefaultData[ucColorTempType];
            }
        }
    }
    else
    {
        g_stColorProcData.ucColorTempR = 0x80;
        g_stColorProcData.ucColorTempG = 0x80;
        g_stColorProcData.ucColorTempB = 0x80;
    }
}

//--------------------------------------------------
// Description  : Save color settings to Flash
// Input Value  : ucSource --> Source Type
//                ucColorTempType --> Color Temp Type
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveColorSetting(BYTE ucColorTempType)
{
    if(ucColorTempType != _CT_OFF)
    {
        UserInterfaceFlashSaveItem(_FLASH_ITEMID_COLORPROC0_9300 + ucColorTempType, (BYTE*)(&g_stColorProcData), sizeof(StructColorProcDataType));
    }
}

//--------------------------------------------------
// Description  : Restore default color settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreColorSetting(void)
{
    BYTE ucColorTempIndex = 0;

    for(ucColorTempIndex = 0; ucColorTempIndex < _CT_COLORTEMP_AMOUNT; ucColorTempIndex++)
    {
        g_stColorProcData = g_stColorTempDefaultData[ucColorTempIndex];

        if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_COLORPROC0_9300 + ucColorTempIndex, pData, 1) == _TRUE)
        {
            RTDFlashSaveColorSetting(ucColorTempIndex);
        }
    }
}

//--------------------------------------------------
// Description  : Restore default color settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreUserColorSetting(void)
{
    StructColorProcDataType stUserColorTemp = {0};

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_COLORPROC5_USER, pData, 1) == _TRUE)
    {
        stUserColorTemp = g_stColorProcData;
        g_stColorProcData = g_stColorTempDefaultData[_CT_USER];
        RTDFlashSaveColorSetting(_CT_USER);
        g_stColorProcData = stUserColorTemp;
    }
}

//--------------------------------------------------
// Description  : Load six color data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadSixColorData(void)
{
    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_SIXCOLOR_DATA, pData, sizeof(StructSixColorDataType)) == _TRUE)
    {
        memcpy((BYTE *)(&g_stSixColorData), pData, sizeof(StructSixColorDataType));
    }
    else
    {
        g_stSixColorData = g_stSixColorDefaultData;
    }
}

//--------------------------------------------------
// Description  : Save six color data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashSaveSixColorData(void)
{
    UserInterfaceFlashSaveItem(_FLASH_ITEMID_SIXCOLOR_DATA, (BYTE *)(&g_stSixColorData), sizeof(StructSixColorDataType));
}

//--------------------------------------------------
// Description  : Restore default six color data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestoreSixColorData(void)
{
    g_stSixColorData = g_stSixColorDefaultData;

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_SIXCOLOR_DATA, pData, 1) == _TRUE)
    {
        RTDFlashSaveSixColorData();
    }
}

//--------------------------------------------------
// Description  : Load Panel Used Time Data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadPanelUsedTimeData(void)
{
    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_PANEL_DATA, pData, sizeof(StructTimeType)) == _TRUE)
    {
        memcpy((BYTE *)(&g_stPanelTimeData), pData, sizeof(StructTimeType));
    }
    else
    {
        SET_PANEL_TIME_HOUR(0);
        SET_PANEL_TIME_MIN(0);
    }
}

//--------------------------------------------------
// Description  : Save Panel Used Time Data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashSavePanelUsedTimeData(void)
{
    UserInterfaceFlashSaveItem(_FLASH_ITEMID_PANEL_DATA, (BYTE *)(&g_stPanelTimeData), sizeof(StructTimeType));
}

//--------------------------------------------------
// Description  : Restore Panel Used Time Data from Flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestorePanelUsedTimeData(void)
{
    SET_PANEL_TIME_HOUR(0);
    SET_PANEL_TIME_MIN(0);

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_PANEL_DATA, pData, 1) == _TRUE)
    {
        RTDFlashSavePanelUsedTimeData();
    }
}

#if(_PANEL_EXIST_MULTIPANEL == _ON)
//--------------------------------------------------
// Description  : Load panel index from flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashLoadPanelIndex(void)
{
    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_PANEL_INDEX, pData, 1) == _TRUE)
    {
        SET_MDOMAIN_PANEL_INDEX(pData[0]);
    }
    else
    {
        SET_MDOMAIN_PANEL_INDEX(0);
    }
}

//--------------------------------------------------
// Description  : Save panel index to flash
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashSavePanelIndex(void)
{
    BYTE ucPanelIndex = 0;

    ucPanelIndex = GET_MDOMAIN_PANEL_INDEX();

    UserInterfaceFlashSaveItem(_FLASH_ITEMID_PANEL_INDEX, &ucPanelIndex, 1);
}

//--------------------------------------------------
// Description  : Restore panel index
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDFlashRestorePanelIndex(void)
{
    SET_MDOMAIN_PANEL_INDEX(0);

    if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_PANEL_INDEX, pData, 1) == _TRUE)
    {
        RTDFlashSavePanelIndex();
    }
}
#endif // End of #if(_PANEL_EXIST_MULTIPANEL == _ON)

#endif // End of #elif(_SYSTEM_EEPROM_EMULATION_SUPPORT == _ON)

#endif // #if(_OSD_TYPE == _REALTEK_2011_OSD)
