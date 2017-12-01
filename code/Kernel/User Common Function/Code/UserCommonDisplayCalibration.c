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
// ID Code      : UserDisplayCalibration.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_DISPLAY_CALIBRATION__

#include "UserCommonInclude.h"

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of OGC/OCC/DICOM
//--------------------------------------------------
#define _OGC_TYPE                   0
#define _OCC_TYPE                   1
#define _DICOM_TYPE                 2
#define _RGB_GAIN_TYPE              3
#define _COLOR_MATRIX_TYPE          4

#define _DISP_CALIB_START           0
#define _DISP_CALIB_PASS            1
#define _DISP_CALIB_ERASE_ERROR     2
#define _DISP_CALIB_FW_ERROR        3
#define _DISP_CALIB_CRC_ERROR       4
#define _DISP_CALIB_FAIL            5

typedef enum
{
#if(_OGC_SUPPORT == _ON)
    _GAMMA1_POSITION,
    _GAMMA2_POSITION,
    _GAMMA3_POSITION,
#if(_OGC_TOTAL_GAMMA == 5)
    _GAMMA4_POSITION,
    _GAMMA5_POSITION,
#endif
#endif
#if(_OCC_SUPPORT == _ON)
    _OCC_POSITION,
#endif
#if(_OGC_DICOM_SUPPORT == _ON)
    _DICOM_POSITION,
#endif
	_NONE_VALUE,
} EnumOGCTypePos;


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// Table of OGC/OCC/DICOM
//--------------------------------------------------
BYTE code tOGC_GRAY_TABLE[] =
{
   240, 224, 208, 
   192, 176, 160,
   144, 128, 112,
    96,  80,  64,
    56,  48,  40,
    32,  24,  16,
     8,   4,   0,
};


BYTE code tSRGBByPass[] =
{
    0,0,0,0,0,0,
    0,0,0,0,0,0,
    0,0,0,0,0,0
};


#if(_OCC_SUPPORT == _ON)
//--------------------------------------------------
// sRGB Table for OCC
//--------------------------------------------------
BYTE code tOCC_SRGB_TABLE[] =
{
    192,  80,  80,
    192, 192,  80,
     96, 192,  96,
     96, 192, 192,
    128, 128, 192,
    192, 128, 192,
    255, 255, 255,
};
#endif

WORD code tGAMMA_INDEX[] = 
{
    
#if(_OGC_SUPPORT == _ON)
    _OGC_GAMMA1_ADDRESS,
    _OGC_GAMMA2_ADDRESS,
    _OGC_GAMMA3_ADDRESS,
    
#if(_OGC_TOTAL_GAMMA == 5)
    _OGC_GAMMA4_ADDRESS,
    _OGC_GAMMA5_ADDRESS,
#endif

#endif

#if(_OCC_SUPPORT == _ON)
    _OCC_GAMMA10_ADDRESS,
#endif

#if(_OGC_DICOM_SUPPORT == _ON)
    _OGC_DICOM_ADDRESS,
#endif

};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE xdata DISP_CALIBRATION_FLASH[_DISP_CALIBRATION_TOTAL_SPACE]      _at_ (_OGC_FLASH_PAGE * _FLASH_PAGE_SIZE);

WORD g_usGammaCount[][3] =
{

#if(_OGC_SUPPORT == _ON)
    {387, 387, 387},
    {387, 387, 387},
    {387, 387, 387},
    
#if(_OGC_TOTAL_GAMMA == 5)
    {387, 387, 387},
    {387, 387, 387},
#endif

#endif  // End of #if(_OGC_SUPPORT == _ON)

#if(_OCC_SUPPORT == _ON)
    {411, 411, 411},
#endif

#if(_OGC_DICOM_SUPPORT == _ON)
    {387, 387, 387},
#endif

};

BYTE g_ucCalibrationType = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserCommonDdcciDispCalibProcess(void);
bit UserCommonDdcciDispCalibOGCStart(void);

#if(_OCC_SUPPORT == _ON)
BYTE UserCommonDdcciDispCalibOCCProcess(BYTE ucStep);
#endif

bit UserCommonDdcciDispCalibInitialCheck(void);
void UserCommonDdcciDispCalibSaveLUT(BYTE ucTotalLength);
BYTE UserCommonDdcciDispCalibCheckSum(void);
BYTE UserCommonDdcciDispCalibCalCheckSum(BYTE ucCheckType);
void UserCommonDdcciDispCalibShowGamma(void);
void UserCommonDdcciDispCalibReplyResult(BYTE ucType);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Do OGC/OCC/DICOM Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciDispCalibProcess(void)
{
    BYTE ucCalibrationStep = 0;  
    BYTE ucGammaIndex = 0;
    BYTE ucColorTempIndex = 0;
    BYTE ucFlag = 1;
    BYTE ucBriTemp[3] = {0x80, 0x80, 0x80};

    EX1 = 0;

    ucCalibrationStep = g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_STEP];

    if(UserCommonDdcciDispCalibInitialCheck() == _SUCCESS)
    {

//****************************************************************************************//
//                               MEASURE PROCESS                                          //
//****************************************************************************************//
        /////////////////////////////////////////////////////////////////
        /////////////////////TOOL GET FW DEFINE//////////////////////////
        /////////////////////////////////////////////////////////////////
        if(ucCalibrationStep == _DDCCI_DISP_CALIB_GET_DEFINE)
        {      
            UserCommonDdcciDispCalibReplyResult(_DISP_CALIB_START);

            ScalerMcuDdcciReleaseScl();
            return;
        }
        
        /////////////////////////////////////////////////////////////////
        //////////////DISPLAY CALIBRATION: MEASURE START/////////////////
        //////////////DISPLAY CALIBRATION: MEASURE WHITE/////////////////
        /////////////////////////////////////////////////////////////////
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_WHITE) 
        {
            ucFlag = UserCommonDdcciDispCalibOGCStart();
            
            ScalerDDomainBackgroundEnable(_ENABLE); 
            ScalerDDomainBackgroundSetColor(255, 255, 255);

        }

        /////////////////////////////////////////////////////////////////
        //////////////DISPLAY CALIBRATION: MEASURE RED///////////////////
        /////////////////////////////////////////////////////////////////
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_RED)
        {
            ScalerDDomainBackgroundSetColor(255, 0, 0);
            
            ucFlag = UserCommonFlashErasePage(_OGC_FLASH_BANK, _OGC_FLASH_PAGE);

        }

        /////////////////////////////////////////////////////////////////
        //////////////DISPLAY CALIBRATION: MEASURE GREEN/////////////////
        /////////////////////////////////////////////////////////////////
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_GREEN)
        {
            ScalerDDomainBackgroundSetColor(0, 255, 0);
            
            if(_DISP_CALIBRATION_TOTAL_SPACE > _FLASH_PAGE_SIZE)
            {
                ucFlag = UserCommonFlashErasePage(_OGC_FLASH_BANK, _OGC_FLASH_PAGE + 1);
            }
        }

        /////////////////////////////////////////////////////////////////
        //////////////DISPLAY CALIBRATION: MEASURE BLUE//////////////////
        /////////////////////////////////////////////////////////////////
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_BLUE)
        {
            ScalerDDomainBackgroundSetColor(0, 0, 255);
            
            if(_DISP_CALIBRATION_TOTAL_SPACE > _FLASH_PAGE_SIZE * 2)
            {
                ucFlag = UserCommonFlashErasePage(_OGC_FLASH_BANK, _OGC_FLASH_PAGE + 2); 
            }
        }

        /////////////////////////////////////////////////////////////////
        //////////////DISPLAY CALIBRATION: MEASURE BLACK/////////////////
        ///////////////////////SAVE RGB GAIN/////////////////////////////
        /////////////////////////////////////////////////////////////////
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_BLACK)
        {
            ScalerDDomainBackgroundSetColor(0, 0, 0);
            
            // Save RGB Gain to Flash
            // CT/Gamma	 Gamma1  Gamma2  Gamma3 Gamma4  Gamma5
            //    CT1	 R/G/B	  R/G/B	 R/G/B	R/G/B	R/G/B
            //    CT2	 R/G/B	  R/G/B	 R/G/B	R/G/B	R/G/B
            //    CT3    R/G/B	  R/G/B	 R/G/B	R/G/B	R/G/B
            //    CT4	 R/G/B	  R/G/B	 R/G/B	R/G/B	R/G/B
            //    CT5	 R/G/B	  R/G/B	 R/G/B	R/G/B	R/G/B
            //    User   R/G/B	  R/G/B	 R/G/B	R/G/B	R/G/B

#if(_OGC_SUPPORT == _ON)
            UserCommonFlashWrite(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OGC_RGB_GAIN_ADDRESS, _OGC_RGB_GAIN_ACTUAL_SIZE, &g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_RGB_GAIN]);
#endif

        }

        /////////////////////////////////////////////////////////////////
        ////////////DISPLAY CALIBRATION: MEASURE GRAY1 / GRAY2///////////
        /////////////////////////////////////////////////////////////////
        else if((ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY1) || (ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY2))
        {
            ScalerDDomainBackgroundSetColor(tOGC_GRAY_TABLE[ucCalibrationStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY1], tOGC_GRAY_TABLE[ucCalibrationStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY1], tOGC_GRAY_TABLE[ucCalibrationStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY1]);
        }

        /////////////////////////////////////////////////////////////////
        ////////////DISPLAY CALIBRATION: MEASURE GRAY3 ~ GRAY20//////////
        //////////////////////////SAVE LUT///////////////////////////////
        /////////////////////////////////////////////////////////////////
        else if((ucCalibrationStep >= _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY3) && (ucCalibrationStep <= _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY20))
        {
            if((g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_LUT_LENGTH] == 2) && (g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_LUT_ID] == 0xFF))
            {
                ScalerDDomainBackgroundSetColor(tOGC_GRAY_TABLE[ucCalibrationStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY1], tOGC_GRAY_TABLE[ucCalibrationStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY1], tOGC_GRAY_TABLE[ucCalibrationStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY1]);
            }
            else
            {
                UserCommonDdcciDispCalibSaveLUT((g_ucDdcciRxBuf[_DDCCI_LENGTH] & 0x7F) - 3);
            }
        }

        /////////////////////////////////////////////////////////////////
        //////////////DISPLAY CALIBRATION: MEASURE END///////////////////
        /////////////////////////////////////////////////////////////////
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_END) 
        {
            ucFlag = UserCommonDdcciDispCalibCheckSum();

            UserCommonDdcciDispCalibShowGamma();
        }

        /////////////////////////////////////////////////////////////////
        ////////////////////////OCC PROCESS//////////////////////////////
        /////////////////////////////////////////////////////////////////
#if(_OCC_SUPPORT == _ON)
        if(((g_ucCalibrationType >> _OCC_TYPE) & 0x01) == _TRUE)
        {
            ucFlag = UserCommonDdcciDispCalibOCCProcess(ucCalibrationStep);
        }
#endif


//****************************************************************************************//
//                               VERIFICATION PROCESS                                     //
//****************************************************************************************//
        /////////////////////////////////////////////////////////////////
        //////////////////////////VERIFICATION///////////////////////////
        /////////////////////////////////////////////////////////////////
        if(ucCalibrationStep == _DDCCI_DISP_CALIB_VERIFICATION)
        {
            ScalerDDomainPatternGenAdjustColor(g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_VERIFY_RED], g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_VERIFY_GREEN], g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_VERIFY_BLUE]);
            ScalerDDomainPatternGenEnable(_ENABLE);
        }   

        /////////////////////////////////////////////////////////////////
        ///////////////////////SET GAMMA PROCESS/////////////////////////
        /////////////////////////////////////////////////////////////////
#if(_OGC_SUPPORT == _ON)
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_SET_GAMMA)
        {
            ucGammaIndex = (g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_INDEX] >> 4) & 0x0F;
            ucColorTempIndex = g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_INDEX] & 0x0F;

            // Set Output Gamma
            ScalerColorOutputGamma(_OFF);
            ScalerColorOutputGammaAdjust(&DISP_CALIBRATION_FLASH[tGAMMA_INDEX[ucGammaIndex]], _OGC_FLASH_BANK);                     
            ScalerColorOutputGamma(_ON);

            ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_A, ucBriTemp);

            UserCommonFlashRead(_OGC_FLASH_BANK, ((WORD)_OGC_FLASH_PAGE << 12) | (ucColorTempIndex * _OGC_TOTAL_GAMMA * 3 + ucGammaIndex * 3), 3, pData);
            ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);

#if(_PCM_FUNCTION == _ON)              
            ScalerColorPCMInputGamma(_OFF);
#endif

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))
            ScalerColorSRGB(_OFF);            
#endif

        }
#endif  // End of #if(_OGC_SUPPORT == _ON)

        /////////////////////////////////////////////////////////////////
        ////////////////////////SET PCM PROCESS//////////////////////////
        /////////////////////////////////////////////////////////////////
#if(_OCC_SUPPORT == _ON)  
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_SET_PCM)
        {
            // Set PCM Input Gamma
            ScalerColorPCMInputGammaLoadTable((bit)g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_PCM_COLOR_DOMAIN]); 
            ScalerColorPCMInputGamma(_ON);

            // Set PCM Output Gamma
            ScalerColorOutputGamma(_OFF);
            ScalerColorPCMOutputGammaAdjust(&DISP_CALIBRATION_FLASH[_OCC_GAMMA10_ADDRESS], _OGC_FLASH_BANK);                                                               
            ScalerColorOutputGamma(_ON);
            
            // Set PCM Color Matrix
            if(g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_PCM_COLOR_DOMAIN] == _PCM_SRGB)
            {
                ScalerColorPCMSRGBAdjust(&DISP_CALIBRATION_FLASH[_OCC_SRGBMATRIX_ADDRESS], _OGC_FLASH_BANK);     
            }
            else
            {
                ScalerColorPCMSRGBAdjust(&DISP_CALIBRATION_FLASH[_OCC_ADOBEMATRIX_ADDRESS], _OGC_FLASH_BANK);
            }
            
            ScalerColorSRGB(_ON);

            ScalerColorBriConOff();
        }
#endif  // End of #if(_OCC_SUPPORT == _ON)

        /////////////////////////////////////////////////////////////////
        ///////////////////////SET DICOM PROCESS/////////////////////////
        /////////////////////////////////////////////////////////////////
#if(_OGC_DICOM_SUPPORT == _ON)
        else if(ucCalibrationStep == _DDCCI_DISP_CALIB_SET_DICOM)
        {
            // Set DICOM
            ScalerColorOutputGamma(_OFF);
            ScalerColorOutputGammaAdjust(&DISP_CALIBRATION_FLASH[_OGC_DICOM_ADDRESS], _OGC_FLASH_BANK);                                       
            ScalerColorOutputGamma(_ON);
            
#if(_PCM_FUNCTION == _ON)  
            ScalerColorPCMInputGamma(_OFF);
#endif

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))
            ScalerColorSRGB(_OFF);
#endif

        }
#endif  // End of #if(_OGC_DICOM_SUPPORT == _ON)


        /////////////////////////////////////////////////////////////////
        ///////////////////////VERIFICATION END//////////////////////////
        /////////////////////////////////////////////////////////////////
        else if((ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_VERIFY_END) || (ucCalibrationStep == _DDCCI_DISP_CALIB_OCC_VERIFY_END))
        {
            ScalerDDomainPatternGenEnable(_DISABLE);
            ScalerDDomainPatternGenAdjustColor(0, 0, 0);
        }   


//****************************************************************************************//
//                               FINAL PROCESS                                            //
//****************************************************************************************//
        /////////////////////////////////////////////////////////////////
        ///////////////////////REPLY RESULTS/////////////////////////////
        /////////////////////////////////////////////////////////////////
        if(ucCalibrationStep == _DDCCI_DISP_CALIB_VERIFICATION)
        {
            UserCommonDdcciDispCalibReplyResult(_DISP_CALIB_PASS);
        }        
        else  
        {
            if(ucFlag == 1)
            {           
                UserCommonDdcciDispCalibReplyResult(_DISP_CALIB_PASS);
            }
            else
            {
                if((ucCalibrationStep >= _DDCCI_DISP_CALIB_OGC_MEASURE_RED) && (ucCalibrationStep <= _DDCCI_DISP_CALIB_OGC_MEASURE_BLUE))
                {
                    UserCommonDdcciDispCalibReplyResult(_DISP_CALIB_ERASE_ERROR);  
                }
                else if(ucCalibrationStep == _DDCCI_DISP_CALIB_OGC_MEASURE_WHITE) 
                {
                    UserCommonDdcciDispCalibReplyResult(_DISP_CALIB_FW_ERROR);
                }
                else
                {
                    UserCommonDdcciDispCalibReplyResult(_DISP_CALIB_CRC_ERROR);
                }
            }
        }
    }
    else    // else of if(UserCommonDdcciDispCalibInitialCheck() == _SUCCESS)
    {
        UserCommonDdcciDispCalibReplyResult(_DISP_CALIB_FAIL);
    }

    ScalerMcuDdcciReleaseScl();
}

//--------------------------------------------------
// Description  : OGC Measure Start Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserCommonDdcciDispCalibOGCStart(void)
{
    BYTE ucCnt = 0;
    BYTE ucFlag = 1;

    // Get Counter Start
#if(_OGC_SUPPORT == _ON)    
    for(ucCnt = 0; ucCnt < _OGC_TOTAL_GAMMA; ucCnt++)
    {
        g_usGammaCount[ucCnt][0] = 387;
        g_usGammaCount[ucCnt][1] = 387;
        g_usGammaCount[ucCnt][2] = 387;
    }
#endif  // End of #if(_OGC_SUPPORT == _ON)

#if(_OCC_SUPPORT == _ON)
    g_usGammaCount[ucCnt][0] = 411;
    g_usGammaCount[ucCnt][1] = 411;
    g_usGammaCount[ucCnt][2] = 411;
    ucCnt++;
#endif  // End of #if(_OCC_SUPPORT == _ON)

#if(_OGC_DICOM_SUPPORT == _ON)
    g_usGammaCount[ucCnt][0] = 387;
    g_usGammaCount[ucCnt][1] = 387;
    g_usGammaCount[ucCnt][2] = 387;
#endif  // End of #if(_OGC_DICOM_SUPPORT == _ON)

    // Get Counter End      
    g_ucCalibrationType = g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_TYPE];

#if(_OGC_SUPPORT == _OFF)
    if(((g_ucCalibrationType >> _OGC_TYPE) & _BIT0) == _TRUE)
    {
        ucFlag = 0;
    }
#endif  // End of #if(_OGC_SUPPORT == _OFF)

#if(_OCC_SUPPORT == _OFF)
    if(((g_ucCalibrationType >> _OCC_TYPE) & _BIT0) == _TRUE)
    {
        ucFlag = 0;
    }
#endif  // End of #if(_OCC_SUPPORT == _OFF)

#if(_OGC_DICOM_SUPPORT == _OFF)
    if(((g_ucCalibrationType >> _DICOM_TYPE) & _BIT0) == _TRUE)
    {
        ucFlag = 0;
    }
#endif  // End of #if(_OGC_DICOM_SUPPORT == _OFF)

#if(_OGC_TOTAL_GAMMA == 3)
    if(((g_ucCalibrationType >> (_DICOM_TYPE + 1)) & _BIT0) == _TRUE)
    {
        ucFlag = 0;
    }
#endif  // End of #if(_OGC_TOTAL_GAMMA == 3)
   
#if(_OCC_SUPPORT == _ON)
    if(((g_ucCalibrationType >> _OCC_TYPE) & _BIT0) == _TRUE) 
    {
        ScalerColorPCMInputGammaLoadTable((bit)g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_OCC_COLORSPACE]);                                
        ScalerColorPCMInputGamma(_ON);       
        ScalerDDomainPatternGenShowBatch7Pattern(tOCC_SRGB_TABLE[0], tOCC_SRGB_TABLE[1], tOCC_SRGB_TABLE[2]);
    }
    else
#endif  // End of #if(_OCC_SUPPORT == _ON)
    {

#if(_PCM_FUNCTION == _ON)
        ScalerColorPCMInputGamma(_OFF); 
#endif

    }

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))    
    ScalerColorSRGB(_OFF);
#endif

    ScalerColorBriConOff();

#if(_DDOMAIN_COLORSPACECONVERT == _ON)	
    ScalerColorSpaceConvertDDomainDisable();
#endif
    
#if(_DCC_FUNCTION == _ON)
    ScalerColorDCC(_OFF);
#endif

#if(_ICM_SUPPORT == _ON)
    ScalerColorICM(_OFF); 
#endif

#if(_YPEAKING_SUPPORT == _ON)    
    ScalerColorYpeaking(_OFF);    
#endif

    return ucFlag;
}

#if(_OCC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Display Calibration OCC Process
// Input Value  : Calibration Step
// Output Value : ucFlag
//--------------------------------------------------
BYTE UserCommonDdcciDispCalibOCCProcess(BYTE ucStep)
{
    BYTE ucFlag = 1;
    
    if((ucStep >= _DDCCI_DISP_CALIB_OCC_MEASURE_SRGB1) && (ucStep < _DDCCI_DISP_CALIB_OCC_MEASURE_SRGB7))
    {
        ScalerDDomainPatternGenShowBatch7Pattern(tOCC_SRGB_TABLE[(ucStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY20) * 3], 
                                                 tOCC_SRGB_TABLE[(ucStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY20) * 3 + 1],
                                                 tOCC_SRGB_TABLE[(ucStep - _DDCCI_DISP_CALIB_OGC_MEASURE_GRAY20) * 3 + 2]);           
    }
    else if(ucStep == _DDCCI_DISP_CALIB_OCC_MEASURE_SRGB7)
    {
        UserCommonFlashWrite(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OCC_SRGBMATRIX_ADDRESS, 36, &g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_OCC_MATRIX]);
        
        pData[0] = UserCommonDdcciDispCalibCalCheckSum(_COLOR_MATRIX_TYPE);                

        if(g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_OCC_MATRIX + 36] == pData[0]) 
        {
            ucFlag = 1;
            
            UserCommonFlashWrite(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OCC_COLOR_MATRIX_CHKSUM_ADDRESS, 4, pData);
        }
        else
        {
            ucFlag = 0;                     
        }

        // Set PCM Color Matrix
        if(g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_PCM_COLOR_DOMAIN] == _PCM_SRGB)
        {
            ScalerColorPCMSRGBAdjust(&DISP_CALIBRATION_FLASH[_OCC_SRGBMATRIX_ADDRESS], _OGC_FLASH_BANK);     
        }
        else
        {
            ScalerColorPCMSRGBAdjust(&DISP_CALIBRATION_FLASH[_OCC_ADOBEMATRIX_ADDRESS], _OGC_FLASH_BANK);
        }
        
        ScalerColorSRGB(_ON);

        // Disable Display Pattern Gen. & set (0,0,0)
        ScalerDDomainPatternGenEnable(_DISABLE);
        ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    }

    return ucFlag;
}
#endif // End of #if(_OCC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Check if the checksum from Tool is equal to DDCCI data
// Input Value  : None
// Output Value : _SUCCESS/_FAIL
//--------------------------------------------------
bit UserCommonDdcciDispCalibInitialCheck(void)
{
    BYTE ucSum = 0;
    BYTE ucChecksum = 0;
    BYTE ucLength = 0; 
    BYTE ucI = 0;

    ucLength = g_ucDdcciRxBuf[_DDCCI_LENGTH] & 0x7F;
    
    for(ucI = 2; ucI < (ucLength + 1); ucI++)
    {
        ucSum += g_ucDdcciRxBuf[ucI];    
    }
    
    ucChecksum = g_ucDdcciRxBuf[ucLength + 1];
   
    if(ucSum == ucChecksum)
    {
        return _SUCCESS;
    }
    else
    {
        return _FAIL;
    }
}

//--------------------------------------------------
// Description  : Save LUT Data from DDCCI Rx
// Input Value  : nAddress: address in DISP_CALIBRATION_FLASH; 
//                nLength: Data Length
//                ucBuffer: pointer of databuffer
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciDispCalibSaveLUT(BYTE ucTotalLength)
{
    BYTE ucLUTLength = 0;
    BYTE ucPointer = 0;
    BYTE ucGammaIndex = 0; 
    BYTE ucRGB = 0;              
    WORD usStartAddr = _OGC_GAMMA1_ADDRESS;

    // ucTotalLength - 1: exclude checksum
    while(ucPointer < (ucTotalLength - 1)) 
    {
        // LUT Length (exclude ID and Length Bytes)
        ucLUTLength = g_ucDdcciRxBuf[ucPointer + _DDCCI_DISP_CALIB_LUT_LENGTH] - 2;
        
        ucGammaIndex = (g_ucDdcciRxBuf[ucPointer + _DDCCI_DISP_CALIB_LUT_ID] >> 4) & 0x0F;
        ucRGB = g_ucDdcciRxBuf[ucPointer + _DDCCI_DISP_CALIB_LUT_ID] & 0x0F;

        ucPointer += 2;

#if(_OCC_SUPPORT == _ON)    
        if(ucGammaIndex == _OCC_POSITION)
        {
            usStartAddr = tGAMMA_INDEX[_OCC_POSITION] + (WORD)(ucRGB) * 411;
        }
        else
#endif

        {       
            usStartAddr = tGAMMA_INDEX[ucGammaIndex] + (WORD)(ucRGB) * 387;
        }    
      
        UserCommonFlashWrite(_OGC_FLASH_BANK, ((WORD)_OGC_FLASH_PAGE << 12) + (usStartAddr + g_usGammaCount[ucGammaIndex][ucRGB] - ucLUTLength), ucLUTLength, &g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_LUT_LENGTH + ucPointer]); 
        g_usGammaCount[ucGammaIndex][ucRGB] = g_usGammaCount[ucGammaIndex][ucRGB] - ucLUTLength;

        ucPointer += ucLUTLength;
    }
} 

//--------------------------------------------------
// Description  : Calculate the checksum of data in Flash
// Input Value  : ucCheckType: 0- OGC, 1-OCC, 2-DICOM, 3-RGB gain, other- color Matrix, 
// Output Value : Checksum
//--------------------------------------------------
BYTE UserCommonDdcciDispCalibCalCheckSum(BYTE ucCheckType) 
{
    WORD usI = 0;
    BYTE xdata *pucXData = 0x0000;    

    if(_OGC_FLASH_BANK < MCU_BANK_START_FFFD)
    {
        return _FALSE;
    }

    pData[1] = MCU_BANK_SEL_FFFE;
    MCU_BANK_SEL_FFFE = _OGC_FLASH_BANK - MCU_BANK_START_FFFD;

    pData[0] = 0;

    switch(ucCheckType)
    {
        case _OGC_TYPE:

            for(usI = _OGC_GAMMA1_ADDRESS; usI < (_OGC_GAMMA1_ADDRESS + 387 * 3); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }  
            
            for(usI = _OGC_GAMMA2_ADDRESS; usI < (_OGC_GAMMA2_ADDRESS + 387 * 3); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }
            
            for(usI = _OGC_GAMMA3_ADDRESS; usI < (_OGC_GAMMA3_ADDRESS + 387 * 3); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }

#if(_OGC_TOTAL_GAMMA == 3)
            return pData[0];
#endif

            for(usI = _OGC_GAMMA4_ADDRESS; usI < (_OGC_GAMMA4_ADDRESS + 387 * 3); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }

            for(usI = _OGC_GAMMA5_ADDRESS; usI < (_OGC_GAMMA5_ADDRESS + 387 * 3); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }
            
            break;

        case _OCC_TYPE:
            
            for(usI = _OCC_GAMMA10_ADDRESS; usI < (_OCC_GAMMA10_ADDRESS + 411 * 3); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }

            break;

        case _DICOM_TYPE:

            for(usI = _OGC_DICOM_ADDRESS; usI < (_OGC_DICOM_ADDRESS + 387 * 3); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }

            break;

        case _RGB_GAIN_TYPE:

            for(usI = _OGC_RGB_GAIN_ADDRESS; usI < (_OGC_RGB_GAIN_ADDRESS + _OGC_RGB_GAIN_ACTUAL_SIZE); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }

            break;

        case _COLOR_MATRIX_TYPE:

            for(usI = _OCC_SRGBMATRIX_ADDRESS; usI < (_OCC_SRGBMATRIX_ADDRESS + 36); usI++)
            {
                pData[0] += *(pucXData + ((((WORD)_OGC_FLASH_PAGE) << 12) + usI));
            }
            
            break;

         default:

            break;
    }

    MCU_BANK_SEL_FFFE = pData[1];
    
    return pData[0];
}

//--------------------------------------------------
// Description  : Measure End --> Show Gamma
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciDispCalibShowGamma(void)
{
    BYTE ucGammaIndex = 0;
    BYTE ucColorTempIndex = 0;
    BYTE ucBriTemp[3]= {0x80, 0x80, 0x80};

    ScalerColorOutputGamma(_OFF);

#if(_OGC_SUPPORT == _ON)
    if(g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_TYPE] == _OGC_TYPE)
    {
        ucGammaIndex = (g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_OGC_GAMMA_CT_INFO] >> 4) & 0x0F;
        ucColorTempIndex = g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_OGC_GAMMA_CT_INFO] & 0x0F;

        ScalerColorOutputGammaAdjust(&DISP_CALIBRATION_FLASH[tGAMMA_INDEX[ucGammaIndex]], _OGC_FLASH_BANK);

        ScalerColorBriConSetCoef(_BRIGHTNESS_COEF_A, ucBriTemp); 

        UserCommonFlashRead(_OGC_FLASH_BANK, ((WORD)_OGC_FLASH_PAGE << 12) | (ucColorTempIndex * _OGC_TOTAL_GAMMA * 3 + ucGammaIndex * 3), 3, pData);
        ScalerColorBriConSetCoef(_CONTRAST_COEF_A, pData);

#if(_PCM_FUNCTION == _ON)                
        ScalerColorPCMInputGamma(_OFF);
#endif

    }
#endif  // End of #if(_OGC_SUPPORT == _ON)            

#if(_OCC_SUPPORT == _ON)   
    if(g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_TYPE] == _OCC_TYPE)
    {
        ScalerColorPCMOutputGammaAdjust(&DISP_CALIBRATION_FLASH[_OCC_GAMMA10_ADDRESS], _OGC_FLASH_BANK); 

        ScalerColorPCMSRGBAdjust(tSRGBByPass, GET_CURRENT_BANK_NUMBER());

        ScalerColorPCMInputGamma(_ON);

        ScalerColorBriConOff();

        ScalerColorSRGB(_OFF);
    }
#endif  // End of #if(_OCC_SUPPORT == _ON)     

#if(_OGC_DICOM_SUPPORT == _ON)            
    if(g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_TYPE] == _DICOM_TYPE)
    {
        ScalerColorOutputGammaAdjust(&DISP_CALIBRATION_FLASH[_OGC_DICOM_ADDRESS], _OGC_FLASH_BANK);
        
#if(_PCM_FUNCTION == _ON)
        ScalerColorPCMInputGamma(_OFF);   
#endif

        ScalerColorBriConOff();

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))
        ScalerColorSRGB(_OFF);
#endif
    }   
#endif  // End of #if(_OGC_DICOM_SUPPORT == _ON)

    ScalerColorOutputGamma(_ON);

    ScalerDDomainBackgroundEnable(_DISABLE);
    ScalerDDomainBackgroundSetColor(0, 0, 0);
}

//--------------------------------------------------
// Description  : Display Calibration Measure End CheckSum
// Input Value  : None
// Output Value : _SUCCESS/_FAIL
//--------------------------------------------------
BYTE UserCommonDdcciDispCalibCheckSum(void)
{
    BYTE ucFlag = 1;
    BYTE ucChkSumTemp[2];
    
#if(_OGC_SUPPORT == _ON)
    if(((g_ucCalibrationType >> _OGC_TYPE) & 0x01) == _TRUE) 
    {   
        ucChkSumTemp[0] = g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_OGC_CHKSUM];  
        UserCommonFlashWrite(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OGC_CHKSUM_ADDRESS, 1, &ucChkSumTemp[0]); 
        UserCommonFlashRead(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OGC_CHKSUM_ADDRESS, 1, &ucChkSumTemp[1]);
        
        if((UserCommonDdcciDispCalibCalCheckSum(_OGC_TYPE) != ucChkSumTemp[0]) || (ucChkSumTemp[0] != ucChkSumTemp[1]))
        {
            ucFlag = _BIT1;   
        }
    }
#endif  // End of #if(_OGC_SUPPORT == _ON)
    
#if(_OCC_SUPPORT == _ON)
    if(((g_ucCalibrationType >> _OCC_TYPE) & 0x01) == _TRUE)
    {
        ucChkSumTemp[0] = g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_OCC_CHKSUM];  
        UserCommonFlashWrite(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OCC_CHKSUM_ADDRESS, 1, &ucChkSumTemp[0]);
        UserCommonFlashRead(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OCC_CHKSUM_ADDRESS, 1, &ucChkSumTemp[1]);
        
        if((UserCommonDdcciDispCalibCalCheckSum(_OCC_TYPE) != ucChkSumTemp[0]) || (ucChkSumTemp[0] != ucChkSumTemp[1]))
        {
            ucFlag |= _BIT2;
        }
    }
#endif  // End of #if(_OCC_SUPPORT == _ON)
    
#if(_OGC_DICOM_SUPPORT == _ON)
    if(((g_ucCalibrationType >> _DICOM_TYPE) & 0x01) == _TRUE)
    {
        ucChkSumTemp[0] = g_ucDdcciRxBuf[_DDCCI_DISP_CALIB_DICOM_CHKSUM];     
        UserCommonFlashWrite(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OGC_DICOM_CHKSUM_ADDRESS, 1, &ucChkSumTemp[0]);
        UserCommonFlashRead(_OGC_FLASH_BANK, (((WORD)_OGC_FLASH_PAGE) << 12) + _OGC_DICOM_CHKSUM_ADDRESS, 1, &ucChkSumTemp[1]);
        
        if((UserCommonDdcciDispCalibCalCheckSum(_DICOM_TYPE) != ucChkSumTemp[0]) || (ucChkSumTemp[0] != ucChkSumTemp[1]))
        {
            ucFlag |= _BIT3;
        }
    }
#endif  // End of #if(_OGC_DICOM_SUPPORT == _ON)     

    return ucFlag;
}

//--------------------------------------------------
// Description  : Display Calibration Reply Results
// Input Value  : ucType --> Pass or other Fail Errors
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciDispCalibReplyResult(BYTE ucType)
{
    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x04; 

    switch(ucType)
    {
        case _DISP_CALIB_START:

            g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
            g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x04;
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_OGC_SUPPORT] = _OGC_SUPPORT;
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_OCC_SUPPORT] = _OCC_SUPPORT;
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_DICOM_SUPPORT] = _OGC_DICOM_SUPPORT;
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_OGC_TOTAL_GAMMA] = _OGC_TOTAL_GAMMA;
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_OGC_TOTAL_GAMMA + 1] = UserCommonDdcciCalCheckSum();

            break;
            
        case _DISP_CALIB_PASS:
            
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_1] = 'P';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_2] = 'A';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_3] = 'S';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_4] = 'S';
            
            break;

        case _DISP_CALIB_ERASE_ERROR:
            
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_1] = 'E';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_2] = 'R';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_3] = 'A';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_4] = 'S';
            
            break;

        case _DISP_CALIB_FW_ERROR:
            
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_1] = 'F';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_2] = 'W';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_3] = 'E';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_4] = g_ucCalibrationType;
                    
            break;

        case _DISP_CALIB_CRC_ERROR:
            
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_1] = 'C';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_2] = 'R';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_3] = 'C';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_4] = 'E';
            
            break;

        case _DISP_CALIB_FAIL:

        default:

            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_1] = 'F';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_2] = 'A';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_3] = 'I';
            g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_4] = 'L';

            break;
    }
    
    g_ucDdcciTxBuf[_DDCCI_DISP_CALIB_STRING_4 + 1] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);

    EX1 = 1;
}
#endif // End of #if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON))
