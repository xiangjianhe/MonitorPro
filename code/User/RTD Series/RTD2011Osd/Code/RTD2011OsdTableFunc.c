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
// ID Code      : RTD2011OsdTableFunc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDTABLEFUNC__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2011_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
WORD code tRESOLUTION_TABLE[][6]=
{
    {   _,   _,   _,   _,   _,   _},
    { 240, _4_, _8_, _0_, _i_,   _},
    { 480, _4_, _8_, _0_, _p_,   _},
    { 288, _5_, _7_, _6_, _i_,   _},
    { 576, _5_, _7_, _6_, _p_,   _},
    { 720, _7_, _2_, _0_, _p_,   _},
    { 540, _1_, _0_, _8_, _0_, _i_},
    {1080, _1_, _0_, _8_, _0_, _p_},
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE *usShowNumberAddress = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE* RTDOsdTableFuncGetStringTableAddress(BYTE ucString, BYTE ucStringIndex);
void RTDOsdTableFuncShowNumber(BYTE ucRow, BYTE ucCol, DWORD usValue, BYTE ucPar ,BYTE ucFontPoint);
BYTE RTDOsdTableFuncVideoResolution(void);
BYTE* RTDOsdTableFuncGetShowResolutionStringAddress(void);
BYTE* RTDOsdTableFuncGetShowHFreqStringAddress(void);
BYTE* RTDOsdTableFuncGetShowVFreqStringAddress(void);
BYTE* RTDOsdTableFuncGetShowPixelClockStringAddress(void);
void RTDOsdTableFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, BYTE ucLanguage);
void RTDOsdTableFuncPutStringCenter(BYTE ucRow, BYTE ucColStart, BYTE ucColEnd, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, SBYTE ucCenterOffset , BYTE ucLanguage);
BYTE* RTDOsdTableFuncGetWindowTableAddress(BYTE ucWindow);
void RTDOsdTableFuncDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
BYTE* RTDOsdTableFuncGetColorPaletteAddress(ucColorPalette);
void RTDOsdTableFuncSetColorPalette(BYTE ucPaletteIndex, BYTE ucColorPalette);
BYTE* RTDOsdTableFuncGetIconAddress(ucIcon);
void RTDOsdTableFuncPutIcon1BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
void RTDOsdTableFuncPutIcon2BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE* RTDOsdTableFuncGetStringTableAddress(BYTE ucString, BYTE ucStringIndex)
{
    BYTE *pArray = 0;

    switch(ucString)
    {
        case _OSD_STRING_ASPECT_ORIGIN_RATIO:
            pArray = tsOSD_ASPECT_ORIGIN_RATIO_TABLE;
            break;
        
        case _OSD_STRING_TITLE:
            pArray = tOSD_MENU_TITLE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_PICTURE_PAGE:
            pArray = tOSD_PICTURE_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_DISPLAY_PAGE:
            pArray = tOSD_DISPLAY_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_COLOR_PAGE:
            pArray = tOSD_COLOR_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_ADVANCE_PAGE:
            pArray = tOSD_ADVANCE_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_INPUT_PAGE:
            pArray = tOSD_INPUT_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_AUDIO_PAGE:
            pArray = tOSD_AUDIO_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_OTHER_PAGE:
            pArray = tOSD_OTHER_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_GAMMA_SELECT:
            pArray = tOSD_GAMMA_SELECT_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_COLOR_TEMPERATURE:
            pArray = tOSD_COLOR_TEMPERATURE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_COLOR_MODE:
            pArray = tOSD_COLOR_MODE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_COLOR_DEMO_MODE:
            pArray = tOSD_COLOR_DEMO_MODE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_COLOR_FORMAT:
            pArray = tOSD_COLOR_FORMAT_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_PCM:
            pArray = tOSD_COLOR_PCM_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_ASPECT_RATIO:
            if(GET_OSD_DO_ASPECT_RATIO() == _FALSE)
            {
                BYTE ucTemp[12] = {0};
                BYTE i = 0;

                for(i = 0; i < 9; i++)
                {
                    if(*(tOSD_ASPECT_RATIO_TABLE[ucStringIndex] + i) == _END_)
                    {
                        ucTemp[i] = _;
                        ucTemp[i + 1] = _N_;
                        ucTemp[i + 2] = _G_;
                        ucTemp[i + 3] = _END_;
                        break;
                    }
                    ucTemp[i] = *(tOSD_ASPECT_RATIO_TABLE[ucStringIndex] + i);
                }

                pArray = ucTemp;
            }
            else
            {
                pArray = tOSD_ASPECT_RATIO_TABLE[ucStringIndex];
            }

            break;

        case _OSD_STRING_OVER_DRIVE:
            pArray = tOSD_OVER_DRIVE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_ULTRA_VIVID:
            pArray = tOSD_ULTRA_VIVID_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_3D_ITEM:
            pArray = tOSD_3D_ITEM_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_AUDIO_SOURCE:
            pArray = tOSD_AUDIO_SOURCE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_LANGUAGE:
            pArray = tOSD_LANGUAGE_TABLE;
            break;

        case _OSD_STRING_COLOR_SIXCOLOR:
            pArray = tOSD_COLOR_SIXCOLOR_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_3D_LR_SELECT:
            pArray = tOSD_3D_LR_SELECT_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_3D_FORMAT_SELECT:
            pArray = tOSD_3D_FORMAT_SELECT_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_3D_CONVERGENCE:
            pArray = tOSD_3D_CONVERGENCE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_3D_CONVERGENCE_SELECT:
            pArray = tOSD_3D_CONVERGENCE_SELECT_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_R_G_B:
            pArray = tOSD_RGB_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_SIX_COLOR_PAGE:
            pArray = tOSD_SIX_COLOR_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_3D_PAGE:
            pArray = tOSD_3D_PAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_ON_OFF:
            pArray = tOSD_ON_OFF_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_FACTORY:
            pArray = tOSD_FACTORY_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_NO_SIGNAL:
            pArray = tsOSD_NO_SIGNAL;
            break;

        case _OSD_STRING_NO_CABLE:
            pArray = tsOSD_NO_CABLE;
            break;

        case _OSD_STRING_NO_SUPPORT:
            pArray = tsOSD_NO_SUPPORT;
            break;

        case _OSD_STRING_AUTO_ADJUSTMENT:
            pArray = tsOSD_AUTO_ADJUSTMENT;
            break;

        case _OSD_STRING_INPUT_MESSAGE_TABLE:
            pArray = tOSD_INPUT_MESSAGE_TABLE[ucStringIndex];
            break;

        case _OSD_STRING_AUTO_COLOR:
            pArray = tsOSD_AUTO_COLOR;
            break;

        case _OSD_STRING_DDCCI:
            pArray = tsOSD_DDCCI;
            break;

        case _OSD_STRING_GO_TO_POWER_SAVING_MODE:
            pArray = tsOSD_GO_TO_POWER_SAVING_MODE;
            break;

        case _OSD_STRING_HDCPENABLE:
        {
            BYTE ucTemp[14] = {0};

            ucTemp[0] = _H_;    
            ucTemp[1] = _D_;
            ucTemp[2] = _C_;
            ucTemp[3] = _P_;
            ucTemp[4] = _;

            if(ucStringIndex == _TRUE)
            {
                ucTemp[5] = _E_;
                ucTemp[6] = _n_;
                ucTemp[7] = _a_;
                ucTemp[8] = _b_; 
                ucTemp[9] = _l_; 
                ucTemp[10] = _e_;
                ucTemp[11] = _d_;
                ucTemp[12] = _END_;        
            }
            else
            {
                ucTemp[5] = _D_;
                ucTemp[6] = _i_;
                ucTemp[7] = _s_;
                ucTemp[8] = _a_; 
                ucTemp[9] = _b_; 
                ucTemp[10] = _l_;
                ucTemp[11] = _e_;
                ucTemp[12] = _d_;        
                ucTemp[13] = _END_;        
            }
        
            pArray = ucTemp;
            break;
        }

        case _OSD_STRING_NOW_RESOLUTION:
            pArray = RTDOsdTableFuncGetShowResolutionStringAddress();
            break;

        case _OSD_STRING_HFREQUENCY:
            pArray = RTDOsdTableFuncGetShowHFreqStringAddress();
            break;

        case _OSD_STRING_VFREQUENCY:
            pArray = RTDOsdTableFuncGetShowVFreqStringAddress();
            break;

        case _OSD_STRING_PIXELCLOCK:
            pArray = RTDOsdTableFuncGetShowPixelClockStringAddress();
            break;

        case _OSD_STRING_SHOW_NUMBER:
            pArray = usShowNumberAddress;
            break;
    }
    return pArray; 
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdTableFuncShowNumber(BYTE ucRow, BYTE ucCol, DWORD usValue, BYTE ucPar ,BYTE ucFontPoint)
{
	BYTE xdata ucIndex = 0;
	BYTE xdata ucTemp = 0;
	BYTE xdata i = 0;
	BYTE xdata pData[16] = {0};

	pData[5] = (_0_ + (usValue / 100000));
	pData[4] = (_0_ + (usValue % 100000 / 10000));
	pData[3] = (_0_ + (usValue % 10000) / 1000);
	pData[2] = (_0_ + (usValue % 1000) / 100);
	pData[1] = (_0_ + (usValue % 100) / 10);
	pData[0] = (_0_ + (usValue % 10));

	for(ucIndex = 0; ucIndex < 6; ucIndex++)
	{
		if(pData[5 - ucIndex] != ((bit)(ucPar & _BIT1) ? 0x00 : _0_))
		{
			ucIndex = 5 - ucIndex;
			break;
		}
	}

	if(usValue == 0 && !((bit)(ucPar & 0x02)))
	{
		ucIndex = 0;
	}

	if((bit)(ucPar & _BIT1))
	{
		ucTemp = (ucPar & 0x70) >> 4;
		ucIndex = (ucPar & 0x70) >> 4;
	}
	else
	{
		ucTemp = (ucPar & 0x70) >> 4;

		if(ucTemp < ucIndex)
		{
			ucTemp = ucIndex;
		}
	}

	for(i = 0; i <= ucTemp; i++)
	{
		if(ucIndex >= ucTemp)
		{
			pData[i + 8] = pData[ucIndex - i];
		}
		else
		{
			if(i < (ucTemp - ucIndex))
			{
				pData[i + 8] = 0x00;
			}
			else
			{
				pData[i + 8] = pData[ucIndex - (i - (ucTemp - ucIndex))];
			}
		}
	}
	pData[8 + ucTemp + 1] = _END_;
    usShowNumberAddress = &pData[8];
     
	if((ucPar & 0x01) == _ALIGN_RIGHT) 	   // Align Right
	{
		RTDOsdTableFuncPutStringProp(ucRow, ROW(ucCol-ucTemp), ucFontPoint, _OSD_STRING_SHOW_NUMBER, 0, _ENGLISH);		
	}
	else
	{
		RTDOsdTableFuncPutStringProp(ucRow, ucCol, ucFontPoint, _OSD_STRING_SHOW_NUMBER, 0, _ENGLISH);			
	}
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE RTDOsdTableFuncVideoResolution(void)
{
    bit bVideoTiming = _FALSE;
    BYTE ucI = 0;

    if(GET_INPUT_TIMING_VFREQ() > 620)
    {
        return _FALSE;
    }

    if(GET_INPUT_TIMING_INTERLACE_FLG())
    {
        bVideoTiming = _TRUE;
    }
#if(_VGA_SUPPORT == _ON)
    else if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(GET_VGA_COLOR_FORMAT_STATUS() == _COLOR_SPACE_YPBPR)
        {
            bVideoTiming = _TRUE;
        }
    }
#endif
#if(_DVI_SUPPORT == _ON)
    else if(SysSourceGetSourceType() == _SOURCE_DVI)
    {
#if(_DIGITAL_PORT_SUPPORT == _ON)
        bVideoTiming = ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort());
#endif
    }
#endif
#if(_HDMI_SUPPORT == _ON)
    else if(SysSourceGetSourceType() == _SOURCE_HDMI) 
    {
        if(ScalerColorGetColorSpace() != _COLOR_SPACE_RGB)
        {
            bVideoTiming = _TRUE;
        }
    }
#endif
#if(_DP_SUPPORT == _ON)
    else if(SysSourceGetSourceType() == _SOURCE_DP)
    {
        if(ScalerColorGetColorSpace() != _COLOR_SPACE_RGB)
        {
            bVideoTiming = _TRUE;
        }
    }
#endif

    if(bVideoTiming == _TRUE)
    {
        for(ucI = 1; ucI < 8; ucI++)
        {
            if(GET_INPUT_TIMING_VHEIGHT() == tRESOLUTION_TABLE[ucI][0])
            {
                if((tRESOLUTION_TABLE[ucI][0] == 480) && (GET_INPUT_TIMING_HWIDTH() == 848))
                {
                    return _FALSE;
                }

                if(((tRESOLUTION_TABLE[ucI][0] == 240) || (tRESOLUTION_TABLE[ucI][0] == 288)  || (tRESOLUTION_TABLE[ucI][0] == 540))
                    && (GET_INPUT_TIMING_INTERLACE_FLG() == _FALSE))
                {
                    return _FALSE;
                }

                return ucI;
            }
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE* RTDOsdTableFuncGetShowResolutionStringAddress(void)
{
    WORD temp = 0;
    BYTE i = 0;
    BYTE pData[17] = {0};

    i = RTDOsdTableFuncVideoResolution();

    if(i != 0)
    {
        pData[0] = tRESOLUTION_TABLE[i][1];
        pData[1] = tRESOLUTION_TABLE[i][2];
        pData[2] = tRESOLUTION_TABLE[i][3];
        pData[3] = tRESOLUTION_TABLE[i][4];
        pData[4] = tRESOLUTION_TABLE[i][5];
        pData[5] = _END_;
    }
    else
    {
        if(GET_INPUT_TIMING_HWIDTH() >= 1000)
        {
            i = 3;
        }
        else
        {
            i = 2;
        }

        temp = GET_INPUT_TIMING_HWIDTH();

        while(1)
        {
            pData[i] = temp % 10 + _0_;
            temp /= 10;
    
            if(temp <= 0)
            {
                break;
            }
            i--;
        }
    
        if(GET_INPUT_TIMING_HWIDTH() >= 1000)
        {
            pData[4] = _x_;
        }
        else
        {
            pData[3] = _x_;    
        }

        temp = GET_INPUT_TIMING_VHEIGHT();

        if((GET_INPUT_TIMING_HWIDTH() >= 1000) && (GET_INPUT_TIMING_VHEIGHT() >= 1000))
        {
              i = 8;
              pData[9] = _AT_0_;          
        }
        else if((GET_INPUT_TIMING_HWIDTH() < 1000) && (GET_INPUT_TIMING_VHEIGHT() < 1000))
        {
              i = 6;
              pData[7] = _AT_0_;  
        }    
        else
        {
              i = 7;
              pData[8] = _AT_0_;
        }

        while(1)
        {
            pData[i] = temp % 10 + _0_;
            temp /= 10;
    
            if(temp <= 0)
            {
                break;
            }
            i--;
        }

        temp = GET_INPUT_TIMING_VFREQ();
    
        if((GET_INPUT_TIMING_HWIDTH() >= 1000) && (GET_INPUT_TIMING_VHEIGHT() >= 1000))
        {
            i = 11;
            pData[12] = _DOT_;
            pData[13] = temp % 10 + _0_;
            pData[14] = _H_;
            pData[15] = _z_;
            pData[16] = _END_;          
        }
        else if((GET_INPUT_TIMING_HWIDTH() < 1000) && (GET_INPUT_TIMING_VHEIGHT() < 1000))
        {
            i = 9;
            pData[10] = _DOT_;
            pData[11] = temp % 10 + _0_;
            pData[12] = _H_;
            pData[13] = _z_;
            pData[14] = _END_;          
        }    
        else
        {
            i = 10;
            pData[11] = _DOT_;
            pData[12] = temp % 10 + _0_;
            pData[13] = _H_;
            pData[14] = _z_;
            pData[15] = _END_;
        }

        temp /= 10;

        while(1)
        {
            pData[i] = temp % 10 + _0_;
            temp /= 10;
    
            if(temp <= 0)
            {
                break;
            }
            i--;
        }
    }

    return pData;
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE* RTDOsdTableFuncGetShowHFreqStringAddress(void)
{
    WORD usTemp = 0;
    BYTE ucI = 0;
    BYTE pucData[16] = {0};
                       
    usTemp = GET_INPUT_TIMING_HFREQ();

    pucData[0] = _H_;
    pucData[1] = _COLON_;    
    pucData[2] = _;
    
    ucI = 6;
    
    while(1)
    {
        if(ucI == 5)
        {
            pucData[5] = _DOT_;
        }
        else
        {
            pucData[ucI] = usTemp % 10 + _0_;
            usTemp /= 10;
        }

        if(usTemp <= 0)
        {
            break;
        }
        ucI--;
    }
    pucData[7] = _K_;
    pucData[8] = _;    
    pucData[9] = _H_;
    pucData[10] = _z_;
    pucData[11] = _END_;    

    return pucData;
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE* RTDOsdTableFuncGetShowVFreqStringAddress(void)
{
    WORD usTemp = 0;
    BYTE ucI = 0;
    BYTE pucData[16] = {0};

    usTemp = GET_INPUT_TIMING_VFREQ();

    pucData[0] = _V_;
    pucData[1] = _COLON_;    
    pucData[2] = _;
    
    ucI = 6;
    
    while(1)
    {
        if(ucI == 5)
        {
            pucData[5] = _DOT_;
        }
        else
        {
            pucData[ucI] = usTemp % 10 + _0_;
            usTemp /= 10;
        }
         
        if(usTemp <= 0)
        {
            break;
        }
        ucI--;
    }
    pucData[7] = _H_;
    pucData[8] = _z_;
    pucData[9] = _END_;    

    return pucData;
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE* RTDOsdTableFuncGetShowPixelClockStringAddress(void)
{
    BYTE ucI = 0;
    BYTE pucData[15] = {0};
    WORD usFreq = ScalerSyncGetInputPixelClk();

    pucData[0] = _P_;
    pucData[1] = _C_;
    pucData[2] = _L_;    
    pucData[3] = _K_;    
    pucData[4] = _COLON_;    
    pucData[5] = _;
    pucData[6] = _;    
    
    ucI = 10;
    
    while(1)
    {
        if(ucI == 9)
        {
            pucData[ucI] = _DOT_;
        }
        else
        {
            pucData[ucI] = usFreq % 10 + _0_;
            usFreq /= 10;
        }
         
        if(usFreq <= 0)
        {
            break;
        }
        ucI--;
    }
    
    pucData[11] = _M_;
    pucData[12] = _H_;
    pucData[13] = _z_;    
    pucData[14] = _END_;    

    return pucData;
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdTableFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, BYTE ucLanguage)
{
    bit bEndFlag = 0;
    BYTE xdata ucpTemp[27] = {0};
    BYTE *pFontTable = 0;
    BYTE *pArray = 0;    

    pArray = RTDOsdTableFuncGetStringTableAddress(ucString, ucStringIndex);
    
    if(ucLanguage == _CHINESE_T)
    {
        pFontTable = tFONT_CHINESE;
    }                   
    else
    {
        pFontTable = tFONT_EUROPE;
    }
    
    pData[0] = ucLanguage;
    
    while(pData[0] != _ENGLISH)
    {
        if(*pArray == _END_)
        {
            pData[0]--;
        }
        pArray++;
    }

    pData[1] = RTDOsdFuncGetOsdFontPointer(ucFptsSelect);

    // reorder
    SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT6);
    SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() & (~(_BIT7 | _BIT5)));

    pData[2] = 0;
    pData[3] = 0;
    pData[4] = 0;
    pData[5] = 0;
    pData[9] = 0;
    
    while(*(pArray + pData[2]) != _END_)
    {
        switch(*(pArray + pData[2]))
        {
            case _END_:
                bEndFlag = 1;
                break;

            default:
                pData[3] = *(pArray + pData[2]);
        
                if(ucLanguage == _ENGLISH)
                {         
                    pData[4] = tOSD_CHARWIDTH_EUROPE[pData[3]][1];    
                }
                else if(ucLanguage == _CHINESE_T)
                {         
                    pData[4] = tOSD_CHARWIDTH_CHINESE[pData[3]][1];    
                }
                else
                {
                    pData[4] = 12;
                }
                pData[2]++;
                break;
        }

        if(pData[5] == 0)
        {
            pData[5] = pData[4];
        }

        SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT3);    // first bits shift direction: left shift
        SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() & (~_BIT2)); // left bits shift direction: rigth shift
        SCALEROSD_FONT_ROTATE_1_2_BITS_SHIFT_SET(((pData[4] - pData[5]) << 4) | pData[5]); // first bits shift and second bits shift

        pData[6] = pData[2];
        pData[7] = pData[5];

        for(pData[0] = 0; pData[0] < 9; pData[0]++)
        {
            SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT0); // restart from last three bytes

            PDATA_WORD(7) = pData[3] * 27 + pData[0] * 3;

            SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7)));
            SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 1));
            SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 2));

            pData[2] = pData[6];
            pData[5] = pData[7];

            if((pData[5] == 12) || (*(pArray + pData[2]) == _END_))
            {
                SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
            }
            else
            {
                pData[8] = *(pArray + pData[2]);
                
                if(ucLanguage == _CHINESE_T)
                {
                    pData[4] = tOSD_CHARWIDTH_CHINESE[pData[8]][1];
                }
                else
                {
                    pData[4] = tOSD_CHARWIDTH_EUROPE[pData[8]][1];
                }

                pData[2] ++;

                PDATA_WORD(7) = pData[8] * 27 + pData[0] * 3;

                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7)));
                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 1));
                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 2));

                pData[5] += pData[4];
            }

            while((pData[5] < 12) && (*(pArray + pData[2]) != _END_))
            {
                SCALEROSD_FONT_ROTATE_3_L_BITS_SHIFT_SET((pData[5] << 4) | pData[5]); // third bits shift and left bits shift

                switch(*(pArray + pData[2]))
                {
                    case _END_:
                        bEndFlag = 1;
                        break;

                    default:
                        pData[8] = *(pArray + pData[2]);
                            
                        if(ucLanguage == _ENGLISH)
                        {
                            pData[4] = tOSD_CHARWIDTH_EUROPE[pData[8]][1];
                        }
                        else if(ucLanguage == _CHINESE_T)
                        {
                            pData[4] = tOSD_CHARWIDTH_CHINESE[pData[8]][1];
                        }
                        else
                        {
                            pData[4] = 12;
                        }
                        pData[2] ++;
                        break;
                }

                pData[5] += pData[4];

                PDATA_WORD(7) = pData[8] * 27 + pData[0] * 3;

                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7)));
                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 1));
                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 2));
            }

            ucpTemp[pData[0] * 3 + 2] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
            ucpTemp[pData[0] * 3 + 1] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
            ucpTemp[pData[0] * 3] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
        }

        if(pData[5] <= 12)
        {
            pData[5] = 0;
        }
        else
        {
            pData[5] = pData[5] - 12;
            pData[2]--;
        }

        // Write the pro font data to sram
        //COsdFxLoadFontDataAddrCal(ucBankupFontPointer);

        PDATA_WORD(7) = (WORD)pData[1] * 9;
        PDATA_WORD(7) += g_usFontTableStart;
        
#if(_OSD_ROTATE_FUNCTION == _ON)
        if(GET_OSD_ROTATE_STATUS() == _TRUE)
        {
            ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x85);
            ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x03);
        }
        else
#endif            
        {
            ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x00);
            ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x00);
        }
        
        if(PDATA_WORD(7) > 4095)
        {
            ScalerOsdScrambleLoadFontAddrHsbSet();
        }
        else
        {
            ScalerOsdScrambleLoadFontAddrHsbClr();
        }

        ScalerOsdAddrMsb((HIBYTE(PDATA_WORD(7)) & 0x000f) | 0xd0);
        ScalerOsdAddrLsb(LOBYTE(PDATA_WORD(7)));
        for(pData[0] = 0; pData[0] < 27; pData[0]++)
        {
            ScalerOsdDataPort(ucpTemp[pData[0]]);
        }

        ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x00);
        
#if(_OSD_ROTATE_FUNCTION == _ON)
        if(GET_OSD_ROTATE_STATUS() == _TRUE)
        {
            ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x01);
        }
#endif
        ScalerOsdScrambleLoadFontAddrHsbClr();

#if(_OSD_ROTATE_FUNCTION == _ON)
        if(GET_OSD_ROTATE_STATUS() == _TRUE)
        {
            PDATA_WORD(7) = (WORD)(g_ucOsdHeight - 1 - ucCol - pData[9]) * g_ucOsdWidth + ucRow;
        }
        else
#endif            
        {
            PDATA_WORD(7) = (WORD)ucRow * g_ucOsdWidth + ucCol + pData[9];
        }

        ScalerOsdCommandByte(PDATA_WORD(7) + g_usFontSelectStart, _OSD_BYTE1, pData[1]);
        pData[9]++; // Record the length of prop string
        
        // Increase the sram address pointer        
        pData[1] = RTDOsdFuncSetOsdFontPointer(ucFptsSelect,pData[1]);
        
    }// End of while(*(pArray + stringcnt) != _END_)

    if(ucFptsSelect == _PFONT_PAGE_0)
    {
        g_ucFontPointer0 = pData[1];
    }
    else if(ucFptsSelect == _PFONT_PAGE_1)
    {
        g_ucFontPointer1 = pData[1];
    }
    else if((ucFptsSelect == _PFONT_PAGE_2) || ((ucFptsSelect >= _PFONT_PAGE_ITEM_1) && (ucFptsSelect <= _PFONT_PAGE_ITEM_8)))
    {
        g_ucFontPointer2 = pData[1];
    }
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdTableFuncPutStringCenter(BYTE ucRow, BYTE ucColStart, BYTE ucColEnd, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, SBYTE ucCenterOffset , BYTE ucLanguage)
{
    bit bEndFlag = 0;
    BYTE xdata ucpTemp[27] = {0};
    bit bMode = _CENTER;
    BYTE *pFontTable = 0;
    BYTE *pArray = 0;    

    pArray = RTDOsdTableFuncGetStringTableAddress(ucString, ucStringIndex);

    if(ucLanguage == _CHINESE_T)
    {
        pFontTable = tFONT_CHINESE;
    }                   
    else
    {
        pFontTable = tFONT_EUROPE;
    }
    
    pData[0] = ucLanguage;
    
    while(pData[0] != _ENGLISH)
    {
        if(*pArray == _END_)
        {
            pData[0]--;
        }
        pArray++;
    }
    
    pData[1] = RTDOsdFuncGetOsdFontPointer(ucFptsSelect);
    
    // reorder
    SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT6);
    SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() & (~(_BIT7 | _BIT5)));

    pData[2] = 0;
    pData[3] = 0;
    pData[4] = 0;
    pData[7] = 0;
    pData[10] = 0;
    
    while(*(pArray + pData[2]) != _END_)
    {
        switch(*(pArray + pData[2]))
        {
            case _END_:

                break;

            default:
                    
                pData[3] = *(pArray + pData[2]);
                    
                if(ucLanguage == _ENGLISH)
                {
                    pData[4] = pData[4] + tOSD_CHARWIDTH_EUROPE[pData[3]][1];                  
                }
                else if(ucLanguage == _CHINESE_T)
                {
                    pData[4] = pData[4] + tOSD_CHARWIDTH_CHINESE[pData[3]][1];         
                }
                else
                {
                    pData[4] = pData[4] + 12;
                }
                pData[2] ++;
                break;
        }
    }
    pData[5] = ucColStart + (((((WORD)((ucColEnd - ucColStart) * 12 ) - pData[4]) / 2) + ucCenterOffset) / 12);
    pData[0] = ((((WORD)((ucColEnd - ucColStart) * 12 ) - pData[4]) / 2) + ucCenterOffset) % 12;

/*//for Right mode
    ucCol = (ucColEnd - (ucCharWidth/12) -1);
    ucBlinking = 12 - (ucCharWidth % 12);
*/  

    pData[4] = 0;
    pData[2] = 0;    


    if(pData[0] == 0)
    {
        bMode = _NORMAL;
    }
    else
    {    
        bMode = _CENTER;
    }

    while(*(pArray + pData[2]) != _END_)
    {
        switch(*(pArray + pData[2]))
        {
            case _END_:
                bEndFlag = 1;
                break;

            default:
                    
                if(bMode == _CENTER)
                {
                    pData[6] = _;
                }
                else
                {
                    pData[6] = *(pArray + pData[2]);
                }

                if(ucLanguage == _ENGLISH)
                {
                    if(bMode == _CENTER)
                    {
                        pData[4] = pData[0];
                    }
                    else
                    {                    
                        pData[4] = tOSD_CHARWIDTH_EUROPE[pData[6]][1];    
                    }
                }
                else if(ucLanguage == _CHINESE_T)
                {
                    if(bMode == _CENTER)
                    {
                        pData[4] = pData[0];
                    }
                    else
                    {                    
                        pData[4] = tOSD_CHARWIDTH_CHINESE[pData[6]][1];    
                    }
                }
                else
                {
                    pData[4] = 12;
                }
                pData[2] ++;
                break;
        }

        if(pData[7] == 0)
        {
            pData[7] = pData[4];
        }

        SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT3);    // first bits shift direction: left shift
        SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() & (~_BIT2)); // left bits shift direction: rigth shift
        SCALEROSD_FONT_ROTATE_1_2_BITS_SHIFT_SET(((pData[4] - pData[7]) << 4) | pData[7]); // first bits shift and second bits shift

        pData[8] = pData[2];
        pData[9] = pData[7];

        if(bMode == _CENTER)
        {
            pData[8] = 0;
            pData[6] =0;
            pData[2] = 0;
            bMode = _NORMAL;
        }

        for(pData[0] = 0; pData[0] < 9; pData[0]++)
        {
            SCALEROSD_FONT_ROTATE_SETTING_SET(SCALEROSD_FONT_ROTATE_SETTING_GET() | _BIT0);  // restart from last three bytes
            PDATA_WORD(7)= pData[6] * 27 + pData[0] * 3;

            SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7)));
            SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 1));
            SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 2));

            pData[2] = pData[8];
            pData[7] = pData[9];


            if((pData[7] == 12) || (*(pArray + pData[2]) == _END_))
            {
                SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
                SCALEROSD_FONT_ROTATE_INPUT_SET(0x00);
            }
            else
            {
                pData[3] = *(pArray + pData[2]);
                if(ucLanguage == _CHINESE_T)
                {
                    pData[4] = tOSD_CHARWIDTH_CHINESE[pData[3]][1];
                }
                else
                {
                    pData[4] = tOSD_CHARWIDTH_EUROPE[pData[3]][1];
                }
                pData[2] ++;

                PDATA_WORD(7) = pData[3] * 27 + pData[0] * 3;

                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7)));
                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 1));
                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 2));

                pData[7] += pData[4];
            }

            while((pData[7] < 12) && (*(pArray + pData[2]) != _END_))
            {
                SCALEROSD_FONT_ROTATE_3_L_BITS_SHIFT_SET((pData[7] << 4) | pData[7]); // third bits shift and left bits shift

                switch(*(pArray + pData[2]))
                {
                    case _END_:
                        bEndFlag = 1;
                        break;

                    default:
                        pData[3] = *(pArray + pData[2]);
                            
                        if(ucLanguage == _ENGLISH)
                        {
                            pData[4] = tOSD_CHARWIDTH_EUROPE[pData[3]][1];
                        }
                        else if(ucLanguage == _CHINESE_T)
                        {
                            pData[4] = tOSD_CHARWIDTH_CHINESE[pData[3]][1];
                        }
                        else
                        {
                            pData[4] = 12;
                        }
                        pData[2] ++;
                        break;
                }

                pData[7] += pData[4];

                PDATA_WORD(7) = pData[3] * 27 + pData[0] * 3;

                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7)));
                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 1));
                SCALEROSD_FONT_ROTATE_INPUT_SET(*(pFontTable + PDATA_WORD(7) + 2));
            }

            ucpTemp[pData[0] * 3 + 2] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
            ucpTemp[pData[0] * 3 + 1] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
            ucpTemp[pData[0] * 3] = SCALEROSD_FONT_ROTATE_ONPUT_GET();
        }

        if(pData[7] <= 12)
        {
            pData[7] = 0;
        }
        else
        {
            pData[7] = pData[7] - 12;
            pData[2] --;
        }

        // Write the pro font data to sram
        //COsdFxLoadFontDataAddrCal(ucBankupFontPointer);

        PDATA_WORD(7) = (WORD)pData[1] * 9;
        PDATA_WORD(7) += g_usFontTableStart;
        
#if(_OSD_ROTATE_FUNCTION == _ON)
        if(GET_OSD_ROTATE_STATUS() == _TRUE)
        {
            ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x85);
            ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x03);
        }
        else
#endif            
        {
            ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x00);
            ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x00);
        }
        
        if(PDATA_WORD(7) > 4095)
        {
            ScalerOsdScrambleLoadFontAddrHsbSet();
        }
        else
        {
            ScalerOsdScrambleLoadFontAddrHsbClr();
        }

        ScalerOsdAddrMsb((HIBYTE(PDATA_WORD(7)) & 0x000f) | 0xd0);
        ScalerOsdAddrLsb(LOBYTE(PDATA_WORD(7)));
        for(pData[0] = 0; pData[0] < 27; pData[0]++)
        {
            ScalerOsdDataPort(ucpTemp[pData[0]]);
        }
        
        ScalerOsdFrameControlByte(0x007, _OSD_BYTE2, 0x00);
        
#if(_OSD_ROTATE_FUNCTION == _ON)
        if(GET_OSD_ROTATE_STATUS() == _TRUE)
        {
            ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x01);
        }
#endif
        ScalerOsdScrambleLoadFontAddrHsbClr();

#if(_OSD_ROTATE_FUNCTION == _ON)
        if(GET_OSD_ROTATE_STATUS() == _TRUE)
        {
            PDATA_WORD(7) = (WORD)(g_ucOsdHeight - 1 - pData[5] - pData[10]) * g_ucOsdWidth + ucRow;
        }
        else
#endif            
        {
            PDATA_WORD(7) = (WORD)ucRow * g_ucOsdWidth + pData[5] + pData[10];
        }

        ScalerOsdCommandByte(PDATA_WORD(7) + g_usFontSelectStart, _OSD_BYTE1, pData[1]);
        pData[10] ++; // Record the length of prop string

        // Increase the sram address pointer
        pData[1] = RTDOsdFuncSetOsdFontPointer(ucFptsSelect,pData[1]);
        
    }// End of while(*(pArray + stringcnt) != _END_)

    if(ucFptsSelect == _PFONT_PAGE_0)
    {
        g_ucFontPointer0 = pData[1];
    }
    else if(ucFptsSelect == _PFONT_PAGE_1)
    {
        g_ucFontPointer1 = pData[1];
    }
    else if((ucFptsSelect == _PFONT_PAGE_2) || ((ucFptsSelect >= _PFONT_PAGE_ITEM_1) && (ucFptsSelect  <= _PFONT_PAGE_ITEM_8)))
    {
        g_ucFontPointer2 = pData[1];
    }
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE* RTDOsdTableFuncGetWindowTableAddress(BYTE ucWindow)
{
    BYTE *pAddress = 0;

    switch(ucWindow)
    {
        case _WIN_0:
            pAddress = twOSD_WIN0;
            break;

        case _WIN_1:
            pAddress = twOSD_WIN1;
            break;

        case _WIN_2:
            pAddress = twOSD_WIN2;
            break;

        case _WIN_3:
            pAddress = twOSD_WIN3;
            break;

#if(_OSD_3D_FUNCTION == _ON)
        case _WIN_5:
            pAddress = twOSD_WIN5;
            break;

        case _WIN_6:
            pAddress = twOSD_WIN6;
            break;
#endif            

        case _WIN_7:
            pAddress = twOSD_WIN7;
            break;

        case _WIN_0_TRANS:
            pAddress = twOSD_WIN0_TRANS;
            break;

        case _WIN_1_TRANS:
            pAddress = twOSD_WIN1_TRANS;
            break;

        case _WIN_2_TRANS:
            pAddress = twOSD_WIN2_TRANS;
            break;

        case _WIN_3_TRANS:
            pAddress = twOSD_WIN3_TRANS;
            break;

        case _WIN_4_TRANS:
            pAddress = twOSD_WIN4_TRANS;
            break;

        case _WIN_5_TRANS:
            pAddress = twOSD_WIN5_TRANS;
            break;

        case _WIN_6_TRANS:
            pAddress = twOSD_WIN6_TRANS;
            break;

        case _WIN_7_TRANS:
            pAddress = twOSD_WIN7_TRANS;
            break;
    }

    return pAddress;
}
//--------------------------------------------------
// Description	: 
// Input Value	:
// ucBorderPixel		bit5~3 shadow/border width or 3D button thickness in pixel unit:0~7 1~8 pixel.
//                 		bit2~0 shadow/border height  in line unit:0~7 1~8 line.
//
// ucBorderColor 		bit7~4 shadow/border/3D button left-top/botton border color
//                 		bit3~0 shadow/border/3D button right-botton/top border color
//
// ucWinFuncControl: 	bit7: blend  0:disable, 1:enable
//             			bit6: gradient 0:disable, 1:enable
//            			bit5: gradient direction  0:H, 1:V
//             			bit4: shadow/border/3D button 0:disable, 1:enable
//           			bit3~1:0~3: shadow type 1~4,  4~5: 3D button1~2, 6:reserved, 7:border.
//
// ucGradientCon0:		bit7: R gradient polarity 0:decrease, 1:increase
//         				bit6: G gradient polarity 0:decrease, 1:increase
//          			bit5: B gradient polarity 0:decrease, 1:increase
//            			bit3~4: gradient level 0~3
//             			bit2: R gradient 0:disable, 1:enable
//             			bit1: G gradient 0:disable, 1:enable
//            			bit0: B gradient 0:disable, 1:enable
//
// ucGradientCon0:		bit7~5 0: 8 level per gradient
//          			1~7: 1~7 level per gradient
// Output Value : 		None
//--------------------------------------------------
void RTDOsdTableFuncDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor)
{
    BYTE ucIndex = 0;
    BYTE ucBorderPixel = 0;
    BYTE ucBorderColor = 0;
    BYTE ucWinFuncControl = 0;
    BYTE ucGradientCon0 = 0;
    BYTE ucGradientCon1 = 0;
    BYTE *pArray = 0;

    pArray = RTDOsdTableFuncGetWindowTableAddress(ucWindow);


    ucIndex = (*(pArray + 0));
    ucBorderPixel = (*(pArray + 1));
    ucBorderColor = (*(pArray + 2));
    ucWinFuncControl = (*(pArray + 3));
    ucGradientCon0 = (*(pArray + 4));
    ucGradientCon1 = (*(pArray + 5));

    if(((ucWinFuncControl & _GRADIENT_ENABLE) == _GRADIENT_DISABLE) || (((ucWinFuncControl & _GRADIENT_ENABLE) == _GRADIENT_ENABLE) && ((ucIndex == _WIN0) || (ucIndex == _WIN5) || (ucIndex == _WIN6) || (ucIndex == _WIN7) || (ucIndex == _WIN8) || (ucIndex == _WIN9))))
    {//Windows0,5,6,7,8,9 support gradient function.
        ScalerTimerWaitForEvent(_EVENT_DVS);    
        ScalerOsdFrameControlAllByte((0x100 + (((ucIndex & 0x80) >> 7) * 0x100) + ((ucIndex& 0x0f) * 4) + 0), _OSD_WITHOUT_DB, ucBorderPixel, ucBorderColor, ucGradientCon0);
        ScalerOsdFrameControlAllByte((0x100 + (((ucIndex & 0x80) >> 7) * 0x100) + ((ucIndex& 0x0f) * 4) + 1), _OSD_WITHOUT_DB, (((usXStart & 0x0f00) >> 4) | ((usYStart & 0x0f00) >> 8)), (usXStart & 0xff), (usYStart & 0xff));
        ScalerOsdFrameControlAllByte((0x100 + (((ucIndex & 0x80) >> 7) * 0x100) + ((ucIndex& 0x0f) * 4) + 2), _OSD_WITHOUT_DB, (((usXEnd & 0x0f00) >> 4) | ((usYEnd & 0x0f00) >> 8)), (usXEnd & 0xff), (usYEnd & 0xff));
        ScalerOsdFrameControlAllByte((0x100 + (((ucIndex & 0x80) >> 7) * 0x100) + ((ucIndex& 0x0f) * 4) + 3), _OSD_WITHOUT_DB, (ucColor & _BIT5), (ucGradientCon1 | (ucColor & 0x1f)), (ucWinFuncControl | _BIT0));
    }
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE* RTDOsdTableFuncGetColorPaletteAddress(ucColorPalette)
{
    BYTE *pAddress = 0;

    switch(ucColorPalette)
    {
        case _PALETTE_0:
            pAddress = tPALETTE_0;
            break;
    }

    return pAddress;
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdTableFuncSetColorPalette(BYTE ucPaletteIndex, BYTE ucColorPalette)
{
    BYTE ucAddr = ucPaletteIndex * 16;
    BYTE ucI = 0;
    BYTE *pAddress = 0;

    pAddress = RTDOsdTableFuncGetColorPaletteAddress(ucColorPalette);
/*
    if(ScalerOsdGetOsdEnable() == _FALSE)
    {
        // OSD circuit is activated
        ScalerOsdFrameControlByte(0x000, _OSD_BYTE2, 0x00);
        ScalerTimerDelayXms(20);
    }
*/
    for(ucI = 0; ucI < 16; ucI++)
    {
        ScalerOsdSetColorPalette(ucAddr + ucI, *(pAddress + (ucI * 3)), *(pAddress + (ucI * 3) + 1), *(pAddress + (ucI * 3) + 2));
    }

}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE* RTDOsdTableFuncGetIconAddress(ucIcon)
{
    BYTE *pAddress = 0;

    switch(ucIcon)
    {
        case _ICON_1BIT_UP:
            pAddress = tiOSD_UP_ICON;
            break;

        case _ICON_1BIT_DOWN:
            pAddress = tiOSD_DOWN_ICON;
            break;

        case _ICON_1BIT_LEFT:
            pAddress = tiOSD_LEFT_ICON;
            break;

        case _ICON_1BIT_RIGHT:
            pAddress = tiOSD_RIGHT_ICON;
            break;

        case _ICON_1BIT_MENU:
            pAddress = tiOSD_MENU_ICON;
            break;

        case _ICON_1BIT_EXIT:
            pAddress = tiOSD_EXIT_ICON;
            break;

        case _ICON_1BIT_LOGO_0:
            pAddress = tiOSD_REALTEK_1BIT_LOGO0;
            break;

        case _ICON_1BIT_LOGO_1:
            pAddress = tiOSD_REALTEK_1BIT_LOGO1;
            break;

        case _ICON_2BIT_PICTURE:
            pAddress = tiOSD_PICTURE_ICON;
            break;

        case _ICON_2BIT_DISPLAY:
            pAddress = tiOSD_DISPLAY_ICON;
            break;

        case _ICON_2BIT_COLOR:
            pAddress = tiOSD_COLOR_ICON;
            break;

        case _ICON_2BIT_ADVANCE:
            pAddress = tiOSD_ADVANCE_ICON;
            break;

        case _ICON_2BIT_INPUT:
            pAddress = tiOSD_INPUT_ICON;
            break;

        case _ICON_2BIT_AUDIO:
            pAddress = tiOSD_AUDIO_ICON;
            break;

        case _ICON_2BIT_OTHER:
            pAddress = tiOSD_OTHER_ICON;
            break;

        case _ICON_2BIT_INFORMATION:
            pAddress = tiOSD_INFORMATION_ICON;
            break;

        case _ICON_2BIT_REALTEK:
            pAddress = tiOSD_REALTEK_ICON;
            break;
    }

    return pAddress;
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdTableFuncPutIcon1BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground)
{       
    BYTE ucOsdWidth = 0; 
    BYTE ucCount = 0; 
    BYTE ucHTemp = ucCol;
    BYTE *pArray = 0;

    pArray = RTDOsdTableFuncGetIconAddress(ucIcon);

#if(_OSD_ROTATE_FUNCTION == _ON)
    if(GET_OSD_ROTATE_STATUS() == _ON)
    {
        ucOsdWidth = g_ucOsdHeight;
    }
    else
#endif        
    {
        ucOsdWidth = g_ucOsdWidth;
    }

    while(*pArray != _END_)
    {
        if(*pArray == _NEXT_)
        {
            ucRow++;
            ucHTemp =ucCol;
            pArray++;
        }
        else if(*pArray == _SPACE_)
        {
            ucHTemp++;
            pArray++;
        }
        else if(*pArray == _REPEAT_)
        {
            ucCount =*(pArray + 1) - 1;
            
            while(ucCount > 0)
            {
                if(*(pArray - 1) != _SPACE_)
                {
                    RTDOsdFuncPutIcon1Bit( ucRow,  ucHTemp, *(pArray - 1), ucForeground, ucBackground);
                }
            
                ucHTemp++;
    
                if(ucHTemp == ucOsdWidth && (*(pArray + 1) != _NEXT_))
                {
                    ucRow++;
                    ucHTemp =ucCol;  
                }
                ucCount--;
            }
            pArray += 2;
        }
        else
        {            
            RTDOsdFuncPutIcon1Bit( ucRow,  ucHTemp, *pArray, ucForeground, ucBackground);    
            ucHTemp++;

            if((ucHTemp == ucOsdWidth) && (*(pArray + 1) != _NEXT_))
            {
                ucRow++;
                ucHTemp =ucCol;  
            }
            pArray++;
        }
    }
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void RTDOsdTableFuncPutIcon2BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3)
{       
    BYTE ucOsdWidth = 0; 
    BYTE ucCount = 0; 
    BYTE ucHTemp = ucCol;
    BYTE *pArray = 0;

#if(_OSD_3D_FUNCTION == _ON)
    BYTE tempRow = ucRow;
    BYTE tempCol = ucCol;
#endif // End of#if(_OSD_3D_FUNCTION == _ON)
    
    pArray = RTDOsdTableFuncGetIconAddress(ucIcon);

#if(_OSD_ROTATE_FUNCTION == _ON)
    if(GET_OSD_ROTATE_STATUS() == _ON)
    {
        ucOsdWidth = g_ucOsdHeight;
    }
    else
#endif        
    {
        ucOsdWidth = g_ucOsdWidth;
    }

    while(*pArray != _END_)
    {
        if(*pArray == _NEXT_)
        {
            ucRow++;
            ucHTemp =ucCol;
            pArray++;
        }
        else if(*pArray == _SPACE_)
        {
            ucHTemp++;
            pArray++;
        }
        else if(*pArray == _REPEAT_)
        {
            ucCount =*(pArray + 1 )- 1;
            
            while(ucCount > 0)
            {
                if(*(pArray - 1) != _SPACE_)
                {
                    RTDOsdFuncPutIcon2Bit(ucRow, ucHTemp, *(pArray - 1), ucColor0, ucColor1, ucColor2, ucColor3);
                }
            
                ucHTemp++;
    
                if(ucHTemp == ucOsdWidth && (*(pArray + 1) != _NEXT_))
                {
                    ucRow++;
                    ucHTemp =ucCol;  
                }
                ucCount--;
            }
            pArray += 2;
        }
        else
        {            
            RTDOsdFuncPutIcon2Bit(ucRow, ucHTemp, *pArray, ucColor0, ucColor1, ucColor2, ucColor3);
            ucHTemp++;

            if((ucHTemp == ucOsdWidth) && (*(pArray + 1) != _NEXT_))
            {
                ucRow++;
                ucHTemp = ucCol;  
            }
            pArray++;
        }
        
    }

#if(_OSD_3D_FUNCTION == _ON)
    if(GET_OSD_3DOSD_STATUS())
    {
        if(!GET_OSD_ROTATE_STATUS())
        {
            for(ucOsdWidth = 0; ucOsdWidth < 3; ucOsdWidth++)
            {
                RTDOsdFuncHLine(ROW(tempRow + ucOsdWidth), COL(tempCol - 1), _OSD_BYTE0, 0x12);
                RTDOsdFuncHLine(ROW(tempRow + ucOsdWidth), COL(tempCol - 1), _OSD_BYTE1, 0x11);
                RTDOsdFuncHLine(ROW(tempRow + ucOsdWidth), COL(tempCol - 1), _OSD_BYTE2, 0x00);
            }
        }
    }
#endif // End of #if(_OSD_3D_FUNCTION == _ON)
}

#endif//#if(_OSD_TYPE == _REALTEK_2011_OSD)
