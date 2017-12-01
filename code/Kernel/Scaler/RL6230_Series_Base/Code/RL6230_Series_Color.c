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
// ID Code      : RL6230_Series_Color.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6230_SERIES_COLOR__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Digital Filter
//--------------------------------------------------
#define _DIG_FILTER_NSMEAR_THD              4 //effective:0~7
#define _DIG_FILTER_NSMEAR_DIV_VALUE        1 //effective:0~3

#define _DIG_FILTER_PSMEAR_THD              4 //effective:0~7
#define _DIG_FILTER_PSMEAR_DIV_VALUE        1 //effective:0~3

#define _DIG_FILTER_NRING_THD               4 //effective:0~7
#define _DIG_FILTER_NRING_DIV_VALUE         1 //effective:0~3

#define _DIG_FILTER_PRING_THD               4 //effective:0~7
#define _DIG_FILTER_PRING_DIV_VALUE         1 //effective:0~3

//--------------------------------------------------
// Definitions of ICM
//--------------------------------------------------
#define _ICM_TABLE_SIZE                     100

//--------------------------------------------------
// Definitions of Six Color
//--------------------------------------------------
#define _SIX_COLOR_RIGHTBUFFER              0
#define _SIX_COLOR_RIGHTWIDTH               1
#define _SIX_COLOR_CENTER                   2
#define _SIX_COLOR_LEFTWIDTH                3
#define _SIX_COLOR_LEFTBUFFER               4

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
BYTE code tCOLOR_CONV_YUV2RGB_ITU601[] =
{
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0x02,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x00, 0x04,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x10, 0xa8,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x20, 0x06,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x30, 0x62,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x40, 0x01,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x50, 0x91,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x60, 0x03,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x70, 0x40,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x80, 0x08,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x90, 0x12,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xA0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xB0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xC0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xD0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xE0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xF0, 0x00,

    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0x82,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x02,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0x92,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x00,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0xA2,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x02,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0xB2,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x00,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0xC2,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x02,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0xD2,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x00, 

    _END
};
 
BYTE code tCOLOR_CONV_YUV2RGB_ITU709[] =
{
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0x02,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x00, 0x04,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x10, 0xa8,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x20, 0x07,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x30, 0x2c,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x40, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x50, 0xda,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x60, 0x02,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x70, 0x22,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x80, 0x08,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0x90, 0x73,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xA0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xB0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xC0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xD0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xE0, 0x00,
    5,  _AUTOINC,       CM_9D_YUV_RGB_ACCESS,         0xF0, 0x00,
    
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0x82,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x02,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0x92,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x00,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0xA2,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x02,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0xB2,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x00,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0xC2,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x02,
    4,  _AUTOINC,       CM_9C_YUV2RGB_CTRL,           0xD2,
    4,  _AUTOINC,       CM_9E_YUV_RGB_COEF_DATA,      0x00, 

    _END
};

#if(_I_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Code Tables of ByPass Dither
//--------------------------------------------------
BYTE code tDITHER_TABLE_ZERO[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};  
#endif // End of #if(_I_DITHER_SUPPORT == _ON)

#if(_SIX_COLOR_SUPPORT == _ON)
//--------------------------------------------------
// Code Tables of SixColor
//--------------------------------------------------
SWORD code tSIX_COLOR_DEFAULT_ANGLE[][5] = 
{
    {587,  0, 135, 482,  603},
    {1191, 0, 135, 260,  419},
    {1611, 0, 437, 884, 1023},
    {2635, 0, 135, 280,  369},
    {3005, 0, 369, 504,  745},
    {3751, 0, 345, 670,  932}
};

SWORD code tSIX_COLOR_U_MAX[][5] = 
{
    {1251, 1251, 1019, 3955, 3562},
    {3562, 3562, 3077, 2861, 2636},
    {2636, 2636, 2056, 2649, 2845},
    {2845, 2845, 3077, 3595, 3886},
    {3886, 3886, 1019, 1251, 1578},
    {1578, 1578, 2040, 1603, 1251},
};

SWORD code tSIX_COLOR_U_MAX_8[][3] = 
{
    { 313,  255,  -35},
    {-134, -255, -310},
    {-366, -512, -363},
    {-313, -255, -125},
    { -52,  255,  313},
    { 396,  512,  402},
};

SWORD code tSIX_COLOR_V_MAX_8[][3] = 
{
    { 396,  512,  512},
    { 512,  512,  403},
    { 290,    0, -297},
    {-396, -512, -512},
    {-512, -512, -396},
    {-231,    0,  219},
};

SWORD code tSIX_COLOR_CTOC_DELTA_UV_DOWN[][2] = 
{
    {-447,    0}, //R-->Y
    {-179, -361}, //Y-->G
    { 226, -449}, //G-->C
    { 348,    0}, //C-->B
    { 193,  390}, //B-->M
    {-226,  449}, //M-->R
};

SWORD code tSIX_COLOR_RTOR_DELTA_UV_DOWN[][4] = 
{
    { -58,  116, -390,    0},    
    {-122,    0, -111, -221},		 
    {-145, -291,  198, -396},    
    {  58, -116,  203,    0},	     
    { 309,    0,  140,  280},	
    { 116,  232, -198,  396},		
};

SWORD code tSIX_COLOR_LTOL_DELTA_UV_DOWN[][2] =
{
    {-221,    0},     
    {-202, -404},       
    { 107, -215},	
    { 382,    0},
    { 198,  396},		 
    {-146,  293},		
};

SWORD code tSIX_COLOR_CTOC_DELTA_UV_UP[][2] = 
{
    { 197, -397}, //R-->M
    { 358,    0}, //Y-->R
    { 229,  454}, //G-->Y
    {-177,  358}, //C-->G
    {-444,    0}, //B-->C
    {-227, -450}, //M-->B
};

SWORD code tSIX_COLOR_RTOR_DELTA_UV_UP[][2] = 
{
    { 198, -396},       
    { 390,    0},		     
    { 111,  221},        
    {-198,  396},	     
    {-203,    0},		 
    {-140, -280},		
};

SWORD code tSIX_COLOR_LTOL_DELTA_UV_UP[][4] = 
{
    { 291,    0,  146, -293},   
    {  54,  108,  221,    0},    
    {-149,  297,  202,  404},	
    {-130,    0, -107,  215},	
    { -58, -116, -382,    0},		
    { 110, -219, -198, -396},	
};

//Osd Turning position to next CM
BYTE code tR_TURNING_POSITION_DOWN[] = {61, 66, 71, 68, 75, 69};   
BYTE code tL_TURNING_POSITION_UP[] = {27, 34, 29, 33, 39, 32};                                      
#endif 	//End of #if(_SIX_COLOR_SUPPORT == _ON)

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerColorSpaceConvertLoadTable(void);
void ScalerColorSpaceConvert(EnumColorSpace enumColorFormat);

#if(_VGA_SUPPORT == _ON)
void ScalerColorDigitalFilter(bit bOn);
void ScalerColorDigitalFilterAdjust(void);
#endif

#if(_I_DITHER_SUPPORT == _ON)
bit ScalerColorGetIColorConvertStatus(void);
void ScalerColorIDitherOn(BYTE *pDitherTable, BYTE ucBankNum);
void ScalerColorIDitherOff(void);
#endif // End of #if(_I_DITHER_SUPPORT == _ON)     

#if(_D_DITHER_SUPPORT == _ON)
void ScalerColorDDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE *pThresholdTable, BYTE ucBankNum);
#endif // End of #if(_D_DITHER_SUPPORT == _ON)

#if(_GLOBAL_HUE_SATURATION == _ON)
void ScalerColorSRGBAdjust(BYTE *pSrgbArray);
#endif // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if(_DCR_SUPPORT == _ON)
void ScalerColorDCROnOff(bit bOnOff);
void ScalerColorDCRThresholdAdjust(BYTE ucThreshold1, BYTE ucThreshold2);
DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumAdjustOption);
#endif // End of #if(_DCR_SUPPORT == _ON)

#if(_DCC_HISTOGRM_INFO == _ON)
void ScalerColorDCCGetHistoInfo(BYTE *pucReadArray);
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

#if(_ICM_SUPPORT == _ON)
void ScalerColorICM(bit bOn);
void ScalerColorICMLoadTable(BYTE *pICMTable, BYTE ucBankNum, BYTE ucCMSel);
void ScalerColorICMAdjust(WORD usAdjustOption);
#endif // End of #if(_ICM_SUPPORT == _ON)

#if(_SIX_COLOR_SUPPORT == _ON)
void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition);
void ScalerColorSixColorICMLoad(BYTE *pucICMData, BYTE ucCMSel, BYTE ucLoadSelect);	
void ScalerColorSixColorSetAngleRB(BYTE ucCMSel);
void ScalerColorSixColorEnable(void);
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
void ScalerColorHLW(bit bOn);
void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight);
void ScalerColorHLWBorderAdjust(BYTE ucBorderEn, BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue);
#endif // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Load Table for Color Space Conversion
// Input Value  : Input Color Space
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvertLoadTable(void)
{   
    // Enable Coefficient Access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT1, _BIT1);    
        
    // Load YUV2RGB Table according to Colorimetry
    switch(GET_COLORIMETRY())
    {
        case _COLORIMETRY_ITU601:
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU601, sizeof(tCOLOR_CONV_YUV2RGB_ITU601), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            break;

        case _COLORIMETRY_ITU709:
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709, sizeof(tCOLOR_CONV_YUV2RGB_ITU709), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            break;

        case _COLORIMETRY_EXT:
            if(GET_EXT_COLORIMETRY() == _COLORIMETRY_XVYCC601)
            {
                ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU601, sizeof(tCOLOR_CONV_YUV2RGB_ITU601), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            }
            else
            {
                ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709, sizeof(tCOLOR_CONV_YUV2RGB_ITU709), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            }
            break;

        default:
            ScalerBurstWrite(tCOLOR_CONV_YUV2RGB_ITU709, sizeof(tCOLOR_CONV_YUV2RGB_ITU709), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
            break;
    }
    
    // Disable Coefficient Access
    ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT1, 0x00);            
}

//--------------------------------------------------
// Description  : Color Space Conversion function.
// Input Value  : Input Color Space
// Output Value : None
//--------------------------------------------------
void ScalerColorSpaceConvert(EnumColorSpace enumColorFormat)
{
    if((enumColorFormat == _COLOR_SPACE_YCBCR422) || (enumColorFormat == _COLOR_SPACE_YCBCR444) || (enumColorFormat == _COLOR_SPACE_YPBPR))
    {
        // Enable YUV2RGB coefficient access
        ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT1, _BIT1);

        // Enable YUV Clamp
        ScalerSetBit(CM_9D_YUV_RGB_ACCESS, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));        
        
        // Enable YUV2RGB conversion
        ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, _BIT0);
    }
    else if(enumColorFormat == _COLOR_SPACE_RGB)
    {
        // Enable YUV2RGB coefficient access
        ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT1, _BIT1);

        // Disable YUV Clamp
        ScalerSetBit(CM_9D_YUV_RGB_ACCESS, ~(_BIT3 | _BIT2), 0x00);        
        
        // Disable YUV2RGB conversion
        ScalerSetBit(CM_9C_YUV2RGB_CTRL, ~_BIT0, 0x00);        
    }
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable digital filter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorDigitalFilter(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        ScalerSetBit(CM_99_DIGITAL_FILTER_PORT, ~(_BIT7 | _BIT6 | _BIT5 ), (_BIT7 | _BIT6 | _BIT5));
    }
    else
    {
        ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        ScalerSetBit(CM_99_DIGITAL_FILTER_PORT, ~(_BIT7 | _BIT6 | _BIT5 ), 0x00);
    }
}

//-------------------------------------------------
// Description  : Set digital filter
// Input Value  : None
// Output Value : None
//-------------------------------------------------
void ScalerColorDigitalFilterAdjust(void)
{
    // Disable NR
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7);
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, 0x00);


#if(_DIG_FILTER_PHASE_ENABLE == _ENABLE)
    // Set phase  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT4);

#if(_DIG_FILTER_PHASE_HIGHFREQ_ADCCLOCKTHD != 0)     
    if((GET_INPUT_PIXEL_CLK() / 10) >= _DIG_FILTER_PHASE_HIGHFREQ_ADCCLOCKTHD)
    {
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_HIGHFREQ_THD << 4) | (_DIG_FILTER_PHASE_HIGHFREQ_DIV_VALUE << 2) | _BIT7));
    }
    else
    {
        ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_THD << 4) | (_DIG_FILTER_PHASE_DIV_VALUE << 2) | _BIT7));
    }
#else
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PHASE_THD << 4) | (_DIG_FILTER_PHASE_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_PHASE_MODIFY_ADCCLOCKTHD != 0)

#endif  // End of #if(_DIG_FILTER_PHASE_ENABLE == _ENABLE)

#if(_DIG_FILTER_NSMEAR_ENABLE == _ENABLE)
    // Set negative smear  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT5);
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_NSMEAR_THD << 4) | (_DIG_FILTER_NSMEAR_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_NSMEAR_ENABLE == _ENABLE)

#if(_DIG_FILTER_PSMEAR_ENABLE == _ENABLE)
    // Set positive smear  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PSMEAR_THD << 4) | (_DIG_FILTER_PSMEAR_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_PSMEAR_ENABLE == _ENABLE)

#if(_DIG_FILTER_NRING_ENABLE == _ENABLE)
    // Set negative ring  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT6);
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_NRING_THD << 4) | (_DIG_FILTER_NRING_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_NRING_ENABLE == _ENABLE)

#if(_DIG_FILTER_PRING_ENABLE == _ENABLE)
    // Set positive ring  parameter
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ScalerSetByte(CM_99_DIGITAL_FILTER_PORT, ((_DIG_FILTER_PRING_THD << 4) | (_DIG_FILTER_PRING_DIV_VALUE << 2) | _BIT7));
#endif  // End of #if(_DIG_FILTER_PRING_ENABLE == _ENABLE)

#if(_DIG_FILTER_EXTENSION_ENABLE == _ENABLE)
    // Use extension data
    ScalerSetBit(CM_98_DIGITAL_FILTER_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
    ScalerSetBit(CM_99_DIGITAL_FILTER_PORT, ~_BIT4, _BIT4);
#endif  // End of #if(_DIG_FILTER_EXTENSION_ENABLE == _ENABLE)

}
#endif // End of #if(_VGA_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)     
//--------------------------------------------------
// Description  : Get I-Domain Color Space Conversion/Ultravivid Status
// Input Value  : None
// Output Value : _ON / _OFF
//--------------------------------------------------
bit ScalerColorGetIColorConvertStatus(void)
{
    return (bit)ScalerGetBit(CM_9C_YUV2RGB_CTRL, _BIT0);
}

//--------------------------------------------------
// Description  : Enable IDither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherOn(BYTE *pDitherTable, BYTE ucBankNum)
{
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(pDitherTable, 24, ucBankNum, CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), 0x00);
}

//--------------------------------------------------
// Description  : Disable IDither
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorIDitherOff(void)
{      
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tDITHER_TABLE_ZERO, 24, GET_CURRENT_BANK_NUMBER(), CM_88_I_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(CM_89_I_DITHERING_CTRL1, ~(_BIT7 | _BIT6), 0x00);
}
#endif // End of #if(_I_DITHER_SUPPORT == _ON)     

#if(_D_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust D dither 
// Input Value  : Dithering Tables
// Output Value : None
//--------------------------------------------------
void ScalerColorDDitherAdjust(BYTE *pDitherTable, BYTE *pDitherSeqTable, BYTE *pDitherTempoffsetTable, BYTE *pThresholdTable, BYTE ucBankNum)
{
    // Set D-Dither Table
    if(pDitherTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT7);
        ScalerBurstWrite(pDitherTable, 24, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }

    // Set D-Dither Seq Table
    if(pDitherSeqTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), _BIT6);
        ScalerBurstWrite(pDitherSeqTable, 24, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
    
#if(_D_DITHER_TEMP == _ENABLE)
    // Set D-Dither Temporal Offset Table
    if(pDitherTempoffsetTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
        ScalerBurstWrite(pDitherTempoffsetTable, 4, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
#else
    if(pDitherTempoffsetTable != _NULL_POINTER)
    {
    
    }
#endif

    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6), 0x00);

#if(_D_DITHER_THRESHOLD_EN == _ENABLE)
    // Set D-Dither Threshold table
    if(pThresholdTable != _NULL_POINTER)
    {
        ScalerSetBit(CM_6B_DITHERING_CTRL2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT7);
        ScalerBurstWrite(pThresholdTable, 6, ucBankNum, CM_69_DITHERING_DATA_ACCESS, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    }
#else
    if(pThresholdTable != _NULL_POINTER)
    {

    }
#endif

    ScalerSetBit(CM_6B_DITHERING_CTRL2, ~(_BIT7 | _BIT2 | _BIT0), (_D_DITHER_THRESHOLD_EN << 2) | _BIT0);

    // Enable D-Dither Function and Temporal Dither
    ScalerSetBit(CM_6A_DITHERING_CTRL1, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((_D_DITHER_TEMP << 4) | (_D_DITHER_VALUE_SIGN << 3) | (_D_DITHER_V_FRAME_MOD << 1) | ( _D_DITHER_H_FRAME_MOD)));
}
#endif // End of #if(_D_DITHER_SUPPORT == _ON)

#if(_GLOBAL_HUE_SATURATION == _ON)
//--------------------------------------------------
// Description  : Adjust sRGB function
// Input Value  : sRGB Matrix
//                sRGB Precision Type
// Output Value : None
//--------------------------------------------------
void ScalerColorSRGBAdjust(BYTE *pSrgbArray)
{
    pData[0] = 0;
    pData[1] = 0;

    ScalerSetBit(CM_64_CB_ACCESS_PORT, ~_BIT6, 0x00);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    // R Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT5); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);

    // G Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT3); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);

    // B Offset
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 2, pData, _NON_AUTOINC);
    
    // RR, RG, RB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT3);  
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &pSrgbArray[0], _NON_AUTOINC);
       
    // GR, GG, GB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT4); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &pSrgbArray[6], _NON_AUTOINC);

    // BR, BG, BB
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), _BIT4 | _BIT3); 
    ScalerWrite(CM_63_SRGB_ACCESS_PORT, 6, &pSrgbArray[12], _NON_AUTOINC);

    // Use 3bit shift for Hue adjust 
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT6, _BIT6);
    ScalerSetBit(CM_68_GAMMA_BIST, ~(_BIT6 | _BIT5), _BIT5);
    
    ScalerSetBit(CM_62_COLOR_CTRL, ~_BIT7, _BIT7);

    // Disable Access Port
    ScalerSetBit(CM_62_COLOR_CTRL, ~(_BIT5 | _BIT4 | _BIT3), 0x00);
}
#endif  // End of #if(_GLOBAL_HUE_SATURATION == _ON)

#if(_DCR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DCR ON or OFF
// Input Value  : _ON/ _OFF
// Output Value : None
//--------------------------------------------------
void ScalerColorDCROnOff(bit bOnOff)
{
    if(bOnOff == _OFF)
    {        
        ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT1 | _BIT0), 0x00);
    }
    else
    {
        if(ScalerGetBit(P7_D8_DCR_ACCESS_PORT, _BIT0) == 0x00)
        {
            // Set DCR enable
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT0), _BIT0);

		    // Wait DCR Measure Finish.
            ScalerTimerWaitForEvent(_EVENT_DVS);
            ScalerTimerWaitForEvent(_EVENT_DVS);
        }
    }
}

//--------------------------------------------------
// Description  : Set DCR TH1 & TH2
// Input Value  : TH1 & TH2
// Output Value : None
//--------------------------------------------------
void ScalerColorDCRThresholdAdjust(BYTE ucThreshold1, BYTE ucThreshold2)
{
    // Force ucThreshold2 to an even value due to DCR bug
    ucThreshold2 = ((ucThreshold2 % 2) == 0) ? ucThreshold2 : ucThreshold2 + 1;
    
    ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_P7_D9_PT_00_DCR_THRESHOLD1 << 2));
    ScalerSetByte(P7_D9_DCR_DATA_PORT, ucThreshold1);
    ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_P7_D9_PT_01_DCR_THRESHOLD2 << 2));
    ScalerSetByte(P7_D9_DCR_DATA_PORT, ucThreshold2);
}

//--------------------------------------------------
// Description  : Read DCR Histogram Result
// Input Value  : DCR Histogram Information Option
// Output Value : DCR Histogram Information 
//--------------------------------------------------
DWORD ScalerColorDCRReadResult(EnumDCRAdjOption enumAdjustOption)
{
    switch(enumAdjustOption)
    {
        case _DCR_ABOVE_TH1_NUM:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_02_DCR_ABOVE_TH1_NUM2 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 3, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 8;
            break;

        case _DCR_ABOVE_TH1_VAL:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_05_DCR_ABOVE_TH1_VAL3 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 4, pData, _NON_AUTOINC);
            break;

        case _DCR_ABOVE_TH2_NUM:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_09_DCR_ABOVE_TH2_NUM2 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 3, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 8;
            break;

        case _DCR_ABOVE_TH2_VAL:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_0C_DCR_ABOVE_TH2_VAL3 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 4, pData, _NON_AUTOINC);
            break;

        case _HIGH_LV_NUM_R:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_10_DCR_HIGH_LV_NUM_R1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _LOW_LV_NUM_R:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_12_DCR_LOW_LV_NUM_R1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _HIGH_LV_VAL_R:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_14_DCR_HIGH_LV_VAL_R << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _LOW_LV_VAL_R:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_15_DCR_LOW_LV_VAL_R << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _HIGH_LV_NUM_G:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_16_DCR_HIGH_LV_NUM_G1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _LOW_LV_NUM_G:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_18_DCR_LOW_LV_NUM_G1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _HIGH_LV_VAL_G:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_1A_DCR_HIGH_LV_VAL_G << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _LOW_LV_VAL_G:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_1B_DCR_LOW_LV_VAL_G << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _HIGH_LV_NUM_B:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_1C_DCR_HIGH_LV_NUM_B1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _LOW_LV_NUM_B:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_1E_DCR_LOW_LV_NUM_B1 << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 2, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 16;
            break;

        case _HIGH_LV_VAL_B:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_20_DCR_HIGH_LV_VAL_B << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;

        case _LOW_LV_VAL_B:
            ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_P7_D9_PT_21_DCR_LOW_LV_VAL_B << 2) | _BIT1);
            ScalerRead(P7_D9_DCR_DATA_PORT, 1, pData, _NON_AUTOINC);
            PDATA_DWORD(0) = PDATA_DWORD(0) >> 24;
            break;
    }

    ScalerSetBit(P7_D8_DCR_ACCESS_PORT, ~_BIT1, 0x00);

    return PDATA_DWORD(0);
}
#endif // End of #if(_DCR_SUPPORT == _ON)

#if(_DCC_HISTOGRM_INFO == _ON)
//--------------------------------------------------
// Description  : Get DCC S0~S6 Histogram infomation
// Input Value  : Pointer to get Ymax/Ymin/S0~S6
// Output Value : None
//--------------------------------------------------
void ScalerColorDCCGetHistoInfo(BYTE *pucReadArray)
{
    BYTE ucI = 0;

    ScalerSetBit(P7_C7_DCC_CTRL0, ~(_BIT1 | _BIT0), _PAGE0);

    // Pop out result
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_0C_POPUP_CTRL);
    ScalerGetByte(P7_CA_DCC_DATA_PORT);

    // Get Histogram Info
    ScalerSetByte(P7_C9_DCC_ACCESS_PORT, _P7_CA_PT_P0_0E_Y_MAX_VAL);

    for(ucI = 0; ucI < 9; ucI++)
    {
        pucReadArray[ucI] = ScalerGetByte(P7_CA_DCC_DATA_PORT);
    }
}
#endif // End of #if(_DCC_HISTOGRM_INFO == _ON)

#if(_ICM_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable ICM
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorICM(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(P7_D0_ICM_CTRL, ~_BIT7, _BIT7);
    }
    else
    {
        ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT7), 0x00);
    }
}

//--------------------------------------------------
// Description   : Fill ICM table, Enable Local CM, Set adjust option
// Input Value   : None
// Output Value  : None
//--------------------------------------------------
void ScalerColorICMLoadTable(BYTE *pICMTable, BYTE ucBankNum, BYTE ucCMSel)
{
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), ucCMSel);
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _P7_D3_PT_03_UV_OFFSET);
    ScalerBurstWrite(pICMTable, _ICM_TABLE_SIZE, ucBankNum, P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);	
}

//--------------------------------------------------
// Description  : Adjust ICM Function
// Input Value  : Adjust Option
// Output Value : None
//--------------------------------------------------
void ScalerColorICMAdjust(WORD usAdjustOption)
{
    ScalerSetBit(P7_D0_ICM_CTRL, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (((BYTE)((bit)(usAdjustOption & _Y_CORRECTION_MODE)) << 6) |
                ((BYTE)((bit)(usAdjustOption & _UV_DELTA_RANGE)) << 5) | ((BYTE)((bit)(usAdjustOption & _CM0_ENABLE)) << 4) | ((BYTE)((bit)(usAdjustOption & _CM1_ENABLE)) << 3) | 
                ((BYTE)((bit)(usAdjustOption & _CM2_ENABLE)) << 2) | ((BYTE)((bit)(usAdjustOption & _CM3_ENABLE)) << 1) | ((BYTE)((bit)(usAdjustOption & _CM4_ENABLE)))));

    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT4 | _BIT3), (((BYTE)((bit)(usAdjustOption & _UV_DELTA_RANGE_EXTEND)) << 4) | ((BYTE)((bit)(usAdjustOption & _CM5_ENABLE)) << 3)));

    // Disable Negative Compensate
    ScalerSetBit(P7_D2_ICM_ACCESS_PORT, ~(_BIT7), 0x00);

    // Enable ICM New Mode and UV Offset on Right/Left Buffer
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
}
#endif // End of #if(_ICM_SUPPORT == _ON)

#if(_SIX_COLOR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : 6 Color ICM adjust
// Input Value  : ucColorIndex --> Color Adjusted Now 
//                ucHuePosition --> Hue position after mapping 
//                ucSatPosition --> Sat position after mapping
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorAdjust(BYTE ucColorIndex, BYTE ucHuePosition, BYTE ucSatPosition) 
{
    BYTE pucCentDeltaUV[16];
    BYTE ucLastIndex = 0;
    BYTE ucAxis = 0;
    BYTE ucPointIndex = 0;
    SWORD shDeltaSat = 0;
    SWORD shDeltaUmax1 = 0;
    SWORD shDeltaVmax1 = 0;
    SWORD shDeltaUmax = 0;
    SWORD shDeltaVmax = 0;
    SWORD shDeltaU = 0;
    SWORD shDeltaV = 0;
    BYTE ucTurningPositiongUp = 0;
    BYTE ucTurningPositiongDown = 0;
       
    ucLastIndex = (ucColorIndex == 0)? 5 : (ucColorIndex - 1);
    ucTurningPositiongUp = tL_TURNING_POSITION_UP[ucColorIndex];
    ucTurningPositiongDown = tR_TURNING_POSITION_DOWN[ucColorIndex];

    // Delta Saturation = (-512 * 200 + ((512 - (-512)) * ucSatPosition)) / 200
    shDeltaSat = ((SDWORD)-102400 + ((SDWORD)ucSatPosition << 10)) / 200;

    for(ucAxis = 1; ucAxis < 4; ucAxis++)
    {
        //Calculate Delta Hue of one Axis

        if(ucAxis == _SIX_COLOR_RIGHTWIDTH) 
        {
            if((ucHuePosition > 50) && (ucHuePosition <= ucTurningPositiongDown))
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][0] * (ucHuePosition - 50) / (ucTurningPositiongDown - 50);
                shDeltaVmax = (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][1] * (ucHuePosition - 50) / (ucTurningPositiongDown - 50);
            }
            else if(ucHuePosition > ucTurningPositiongDown)
            {
                shDeltaUmax = tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][0] + (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][2] * (ucHuePosition - ucTurningPositiongDown) / (100 - ucTurningPositiongDown);
                shDeltaVmax = tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][1] + (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_DOWN[ucColorIndex][3] * (ucHuePosition - ucTurningPositiongDown) / (100 - ucTurningPositiongDown);
            }
            else if(ucHuePosition < 50)
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_UP[ucColorIndex][0] * (50 - ucHuePosition) / 50;
                shDeltaVmax = (SDWORD)tSIX_COLOR_RTOR_DELTA_UV_UP[ucColorIndex][1] * (50 - ucHuePosition) / 50;					
            }
            else
            {
                shDeltaUmax = 0;
                shDeltaVmax = 0;	
            }
        }
        else if(ucAxis == _SIX_COLOR_CENTER)
        {
            if(ucHuePosition > 50)
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_CTOC_DELTA_UV_DOWN[ucColorIndex][0] * (ucHuePosition - 50) / 50;
                shDeltaVmax = (SDWORD)tSIX_COLOR_CTOC_DELTA_UV_DOWN[ucColorIndex][1] * (ucHuePosition - 50) / 50;
            }
            else if(ucHuePosition < 50)
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_CTOC_DELTA_UV_UP[ucColorIndex][0] * (50 - ucHuePosition) / 50;
                shDeltaVmax = (SDWORD)tSIX_COLOR_CTOC_DELTA_UV_UP[ucColorIndex][1] * (50 - ucHuePosition) / 50;					
            }
            else
            {
                shDeltaUmax = 0;
                shDeltaVmax = 0;	
            }
        }
        else
        {
            if(ucHuePosition > 50)
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_DOWN[ucColorIndex][0] * (ucHuePosition - 50) / 50;
                shDeltaVmax = (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_DOWN[ucColorIndex][1] * (ucHuePosition - 50) / 50;
            }
            else if((ucHuePosition< 50) && (ucHuePosition >= ucTurningPositiongUp))
            {
                shDeltaUmax = (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][0] * (50 - ucHuePosition) / (50 - ucTurningPositiongUp);
                shDeltaVmax = (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][1] * (50 - ucHuePosition) / (50 - ucTurningPositiongUp);					
            }
            else if(ucHuePosition < ucTurningPositiongUp)
            {
                shDeltaUmax = tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][0] + (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][2] * (ucTurningPositiongUp - ucHuePosition) / ucTurningPositiongUp;
                shDeltaVmax = tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][1] + (SDWORD)tSIX_COLOR_LTOL_DELTA_UV_UP[ucColorIndex][3] * (ucTurningPositiongUp - ucHuePosition) / ucTurningPositiongUp;
            }
            else
            {
                shDeltaUmax = 0;
                shDeltaVmax = 0;	
            }				
        }

        shDeltaUmax1 = tSIX_COLOR_U_MAX_8[ucColorIndex][ucAxis - 1] + shDeltaUmax;
        shDeltaVmax1 = tSIX_COLOR_V_MAX_8[ucColorIndex][ucAxis - 1] + shDeltaVmax; 
        
        shDeltaUmax1 = (SDWORD)shDeltaSat * shDeltaUmax1 >> 9;
        shDeltaVmax1 = (SDWORD)shDeltaSat * shDeltaVmax1 >> 9; 
        
        shDeltaUmax = (shDeltaUmax1 + shDeltaUmax) >> 3;
        shDeltaVmax = (shDeltaVmax1 + shDeltaVmax) >> 3;			

        for(ucPointIndex = 0; ucPointIndex < 8; ucPointIndex++)
        {
            shDeltaU = (shDeltaUmax * (ucPointIndex + 1)) >> 3;
            shDeltaV = (shDeltaVmax * (ucPointIndex + 1)) >> 3;

            shDeltaU = MAXOF(-128, MINOF(127, shDeltaU));
            shDeltaV = MAXOF(-128, MINOF(127, shDeltaV));

            pucCentDeltaUV[ucPointIndex << 1] = shDeltaU & 0xFF;
            pucCentDeltaUV[(ucPointIndex << 1) + 1] = shDeltaV & 0xFF; 
        }

        ScalerColorSixColorICMLoad(pucCentDeltaUV, ucColorIndex, ucAxis);
		
        if(ucAxis == _SIX_COLOR_RIGHTWIDTH)
        {
            ScalerColorSixColorICMLoad(pucCentDeltaUV, ucColorIndex, _SIX_COLOR_RIGHTBUFFER);
            ScalerColorSixColorICMLoad(pucCentDeltaUV, ucLastIndex, _SIX_COLOR_LEFTBUFFER);
        }
    }
}

//--------------------------------------------------
// Description   : Fill 6 Color ICM Data
// Input Value   : pucICMData --> Point to ICM uvoffset  
//                 ucCMSel --> Color selected
//            	   ucLoadSelect --> Axis selected
// Output Value  : None
//--------------------------------------------------
void ScalerColorSixColorICMLoad(BYTE *pucICMData, BYTE ucCMSel, BYTE ucLoadSelect)	
{
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), ucCMSel);

    switch(ucLoadSelect)
    {
        // Rightbuffer
        case 0:	  
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x33);
            break;	

        // Rightwidth    
        case 1:	  
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x13);
            break;	

        // Center    
        case 2:	  
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x03);
            break;	

        // Leftwidth        
        case 3:	  
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x23);
            break;	

        // Leftbuffer    
        case 4:	  
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x43);
            break;	
            
        default:
            ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x33);
            break;		
    }

    ScalerBurstWrite(pucICMData, 16, GET_CURRENT_BANK_NUMBER(), P7_D3_ICM_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_XRAM);  
}

//--------------------------------------------------
// Description  : Set range for one CM 
// Input Value  : ucCMSel --> Color selected
//                shRBuffer --> Right buffer hue
//          	  shRWidth --> Right range
//                shAngle --> Master Range
//                shLWidth --> Left Range
//                shLBuffer --> Left Buffer Range
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorSetAngleRB(BYTE ucCMSel)
{
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT2 | _BIT1 | _BIT0), ucCMSel);
    ScalerSetByte(P7_D2_ICM_ACCESS_PORT, 0x53);

    //Master Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_CENTER]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_CENTER]) & 0xFF));
    
    //Rightwidth Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_RIGHTWIDTH]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_RIGHTWIDTH]) & 0xFF));
    
    //Leftwidth Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_LEFTWIDTH]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_LEFTWIDTH]) & 0xFF));
    
    //Rightbuffer Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_RIGHTBUFFER]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_RIGHTBUFFER]) & 0xFF));
    
    //Leftbuffer Umax
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_LEFTBUFFER]) >> 8));
    ScalerSetByte(P7_D3_ICM_DATA_PORT, ((tSIX_COLOR_U_MAX[ucCMSel][_SIX_COLOR_LEFTBUFFER]) & 0xFF));

    //Right Buffer Hue
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_RIGHTBUFFER] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_RIGHTBUFFER] & 0xFF);
    
    //Right Width Range
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_RIGHTWIDTH] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_RIGHTWIDTH] & 0xFF);
    
    //Master Range
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_CENTER] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_CENTER] & 0xFF);
    
    //Left Width Range
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_LEFTWIDTH] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_LEFTWIDTH] & 0xFF);
    
    //Left Buffer Range
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_LEFTBUFFER] >> 8);
    ScalerSetByte(P7_D3_ICM_DATA_PORT, tSIX_COLOR_DEFAULT_ANGLE[ucCMSel][_SIX_COLOR_LEFTBUFFER] & 0xFF);
}

//--------------------------------------------------
// Description  : Enable ICM function 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorSixColorEnable(void)
{
    BYTE ucCmIndex = 0;

    //Enable x4、CM5
    ScalerSetBit(P7_D1_ICM_SEL, ~(_BIT4 | _BIT3), _BIT4 | _BIT3);
    
    //Enable New ICM mode、buf_uvoffset
    ScalerSetBit(P7_D4_ICM_NEW_MODE, ~(_BIT2 | _BIT1), _BIT2 | _BIT1);
    
    //Enable ICM function、CM0~CM4、x2
    ScalerSetByte(P7_D0_ICM_CTRL, 0xBF);

    for(ucCmIndex = 0; ucCmIndex < 6; ucCmIndex++)
    {
        ScalerColorSixColorSetAngleRB(ucCmIndex);
    }
}
#endif	//#if(_SIX_COLOR_SUPPORT == _ON)

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerColorHLW(bit bOn)
{
    if(bOn == _ON)
    {
        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~_BIT6, _BIT6);
    }
    else
    {
        ScalerSetBit(CM_60_HW_ACCESS_PORT, ~_BIT6, 0x00);
    }
}

//--------------------------------------------------
// Description  : Adjust highlight window region
// Input Value  : usHPos, usHWidth, usVPos, usVHeight
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWAdjust(WORD usHPos, WORD usHWidth, WORD usVPos, WORD usVHeight)
{
    if((usHWidth == 0) || (usVHeight == 0))
    {
        return;
    }

    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _CM_61_PT_00_HW_H_START_H);

    pData[0] = (BYTE)((usHPos >> 8) & 0x0F);
    pData[1] = (BYTE)(usHPos & 0xFF);
    pData[2] = (BYTE)(((usHPos + usHWidth) >> 8) & 0x0F);
    pData[3] = (BYTE)((usHPos + usHWidth) & 0xFF);
    pData[4] = (BYTE)((usVPos >> 8) & 0x0F);
    pData[5] = (BYTE)(usVPos & 0xFF);
    pData[6] = (BYTE)(((usVPos + usVHeight) >> 8) & 0x0F);
    pData[7] = (BYTE)((usVPos + usVHeight) & 0xFF);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    ScalerWrite(CM_61_HW_DATA_PORT, 8, pData, _NON_AUTOINC);

    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), 0x00);
}
//--------------------------------------------------
// Description  : Adjust Border Window Size
// Input Value  : ucBorderWidth, ucRed, ucGreen, ucBlue
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWBorderAdjust(BYTE ucBorderEn, BYTE ucBorderWidth, BYTE ucRed, BYTE ucGreen, BYTE ucBlue)
{
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _CM_61_PT_08_HW_BORDER_WIDTH);

    ScalerSetByte(CM_61_HW_DATA_PORT, ((~ucBorderEn & 0xF0) | (ucBorderWidth & 0x0F)));
    ScalerSetByte(CM_61_HW_DATA_PORT, (ucRed & 0x3F));
    ScalerSetByte(CM_61_HW_DATA_PORT, (ucGreen & 0x3F));
    ScalerSetByte(CM_61_HW_DATA_PORT, (ucBlue & 0x3F));    

    ScalerSetBit(CM_60_HW_ACCESS_PORT, ~(_BIT7), 0x00);
}

#endif // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)

