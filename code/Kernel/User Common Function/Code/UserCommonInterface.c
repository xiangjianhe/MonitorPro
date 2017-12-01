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
// ID Code      : UserCommonInterface.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_INTERFACE__

#include "UserCommonInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucDigitalHPosition = 0;
BYTE g_ucDigitalVPosition = 0;
BYTE g_ucPanelPowerInfo = 0;
bit g_bFailSafeMode = 0;
bit g_bRunDdcciCommand = _FAIL;

#if(_VGA_SUPPORT == _ON)
BYTE g_ucVgaCheckCounter = 0;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserCommonInterfaceAdjustColorProc(void);
void UserCommonInterfaceOsdActiveProc(void);
void UserCommonInterfaceOsdResetProc(void);
void UserCommonInterfaceAdjustInputTiming(void);
bit UserCommonInterfaceReadyForActive(void);
    
#if(_VGA_SUPPORT == _ON)
void UserCommonInterfaceAdjustADCData(void);
#endif

bit UserCommonInterfaceCheckNoSupport(void);

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
void UserCommonInterfaceDdcciIntGetData_EXINT1(void);
#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
BYTE UserCommonInterfaceDdcciHDMIFreesyncHandle_EXINT1(void);
#endif
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
bit UserCommonInterfaceGetRunDdcciCommand(void);
#endif

void UserCommonInterfaceInitial(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set User Required Color Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceAdjustColorProc(void)
{
    if(UserInterfaceGetActiveByPass() == _TRUE)
    {
        return;
    }
    
#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(UserInterfaceJudgeRGBQuantizationLimitRange() == _TRUE)
    {
        ScalerColorSpaceConvertSetRGBLimitRange(_ENABLE);
    }
    else
    {
        ScalerColorSpaceConvertSetRGBLimitRange(_DISABLE);                
    }   
#endif    

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(UserInterfaceJudgeYCCQuantizationFullRange() == _TRUE)
    {
        ScalerColorSpaceConvertSetYCCFullRange(_ENABLE);
    }
    else
    {
        ScalerColorSpaceConvertSetYCCFullRange(_DISABLE);
    }
#endif

    // Load Color Convert Table
    ScalerColorSpaceConvertLoadTable();

#if(_DCR_SUPPORT == _ON)        
    // Enable DCR
    ScalerColorDCROnOff(_ON);
#endif

    UserInterfaceAdjustColorProc();

    // Adjust Normalize Factor
#if((_DCC_FUNCTION == _ON) || (_DCC_HISTOGRM_INFO == _ON))
    ScalerColorDCCNormalizeFactorAdjust();
#endif

    // Adjust Digital Filter
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        ScalerColorDigitalFilterAdjust();

#if(_RINGING_FILTER_SUPPORT == _ON)
        UserAdjustRingingFilter();
#endif

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
        UserAdjustDigitalFilterEnhancePhase();
#endif

        ScalerColorDigitalFilter(_ON);
    }
    else
    {

#if(_RINGING_FILTER_SUPPORT == _ON)
        ScalerColorRingingFilterOff();
#endif

        ScalerColorDigitalFilter(_OFF);
    }
#endif  // End of #if(_VGA_SUPPORT == _ON)

#if(_D_DITHER_SUPPORT == _ON)

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER))
    ScalerColorDDither3DSetPRShift();
#endif

    ScalerColorDDither(_ON);
#endif // End of #if(_D_DITHER_SUPPORT == _ON)

}

//--------------------------------------------------
// Description  : OSD Fix Active Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceOsdActiveProc(void)
{
#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        UserCommonAdjustHPosition(GET_VGA_MODE_ADJUST_H_POSITION());
        UserCommonAdjustVPosition(GET_VGA_MODE_ADJUST_V_POSITION());
        UserCommonAdjustClock(GET_VGA_MODE_ADJUST_CLOCK());            
        UserCommonAdjustPhase(GET_VGA_MODE_ADJUST_PHASE());
    }
    else
#endif
    {
        SET_DIGITAL_H_POSITION(50);
        SET_DIGITAL_V_POSITION(50);            

        UserCommonAdjustHPosition(GET_DIGITAL_H_POSITION());
        UserCommonAdjustVPosition(GET_DIGITAL_V_POSITION());
    }

    UserInterfaceOsdActiveProc();
}

//--------------------------------------------------
// Description  : OSD Fix Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceOsdResetProc(void)
{    
    // Turn off backlight
    if(UserInterfaceOsdGetLogoOn() == _OFF)
    {
#if(_PANEL_POW_SEQ_FAST_MODE == _ON)
        UserInterfacePanelPowerAction(_BACKLIGHT_OFF);
#else
        UserInterfacePanelPowerAction(_PANEL_OFF);
#endif
    }

    UserInterfaceOsdResetProc();
        
#if(_VGA_SUPPORT == _ON)
    g_ucVgaCheckCounter = 30;
#endif
        
// Turn Off Color Functions
#if((_GAMMA_FUNCTION == _ON) || (_PCM_FUNCTION == _ON))
    ScalerColorOutputGamma(_OFF);
#endif

#if((_GLOBAL_HUE_SATURATION == _ON) || (_PCM_FUNCTION == _ON))
    ScalerColorSRGB(_OFF);
#endif

#if(_PCM_FUNCTION == _ON)
    ScalerColorPCMInputGamma(_OFF);
#endif

#if(_ICM_SUPPORT == _ON)   
    ScalerColorICM(_OFF);
#endif

#if(_DCC_FUNCTION == _ON)
    ScalerColorDCC(_OFF);
#endif

#if(_YPEAKING_SUPPORT == _ON)
    ScalerColorYpeaking(_OFF);
#endif

#if(_VGA_SUPPORT == _ON)
    ScalerColorDigitalFilter(_OFF);

#if(_RINGING_FILTER_SUPPORT == _ON)
    ScalerColorRingingFilterOff();
#endif

#endif

#if(_DCR_SUPPORT == _ON)
    ScalerColorDCROnOff(_OFF);
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLW(_OFF);
#endif

    ScalerColorBriConOff();

#if(_I_DITHER_SUPPORT == _ON) 
    ScalerColorIDitherOff();
#endif

#if(_D_DITHER_SUPPORT == _ON) 
    ScalerColorDDither(_OFF);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
    ScalerColorUltraVividOff();
#endif

#if(_I_DITHER_SUPPORT == _ON)
    UserCommonAdjustIDither();
#endif
}

//--------------------------------------------------
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : Current Input Timing Info
// Output Value : Modified Input Timing
//--------------------------------------------------
void UserCommonInterfaceAdjustInputTiming(void)
{
    // Modify 640 x 350 to 640 x 418
    if((GET_MDOMAIN_INPUT_HWIDTH() == 640) && (GET_MDOMAIN_INPUT_VHEIGHT() == 350))
    {       
        SET_MDOMAIN_INPUT_VHEIGHT(_640_X_350_V_HEIGHT);
        
        SET_MDOMAIN_INPUT_VSTART(GET_MDOMAIN_INPUT_VSTART() - ((_640_X_350_V_HEIGHT - 350) / 2));
    }

    UserInterfaceAdjustInputTiming();
    
#if(_OVERSCAN_SUPPORT == _ON)
    UserCommonAdjustOverScan();
#endif
}

//--------------------------------------------------
// Description  : User Judge Ready to Active
// Input Value  : None
// Output Value : True --> Ready to Active
//                False --> Not Ready to Active
//--------------------------------------------------
bit UserCommonInterfaceReadyForActive(void)
{    
#if(_PANEL_POW_SEQ_FAST_MODE == _ON)    
    if((GET_PANELPOWERSTATUS() != _READY_FOR_BACKLIGHT) && (GET_PANELPOWERSTATUS() != _BACKLIGHT_ON_ALREADY))
    {
        return _FALSE;
    }        
#endif    

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(UserInterfaceFirstAutoConfig() == _TRUE)
        {       
            if((g_ucVgaCheckCounter > 0) && (UserCommonAutoMeasureMultiTimes() == _FALSE))
            {
                g_ucVgaCheckCounter--;

                return _FALSE;
            }
        }
    }
#endif    

    return _TRUE;
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : ADC Parameters Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceAdjustADCData(void)
{
    // Adjust PGA
    ScalerADCPGAAdjust(g_stAdcData.ucAdcPGA);

    // Adjust Gain
    ScalerADCGainAdjust(&g_stAdcData.ucAdcGainMSB, &g_stAdcData.ucAdcGainLSB);

    // Adjust Offset
    ScalerADCOffsetAdjust(&g_stAdcData.ucAdcOffsetMSB, &g_stAdcData.ucAdcOffsetLSB);
}
#endif

//--------------------------------------------------
// Description  : Check Whther to support this timing
// Input Value  : None
// Output Value : TRUE => Go to No Support State
//--------------------------------------------------
bit UserCommonInterfaceCheckNoSupport(void)
{
    SET_FAIL_SAFE_MODE(_FALSE);

    if((GET_INPUT_TIMING_HWIDTH()== 0x00) || (GET_INPUT_TIMING_VHEIGHT()) == 0x00)
    {
        return _TRUE;         
    }

    if((GET_INPUT_TIMING_HFREQ() < _OOR_H_FREQ_LOWER_BOUND) || (GET_INPUT_TIMING_HFREQ() > _OOR_H_FREQ_UPPER_BOUND) || \
       (GET_INPUT_TIMING_VFREQ() > _OOR_V_FREQ_UPPER_BOUND) || \
       (GET_INPUT_TIMING_VHEIGHT() < _OOR_V_HEIGHT_LOWER_BOUND) || (GET_INPUT_TIMING_HWIDTH() > _OOR_H_WIDTH_UPPER_BOUND))
    {
        return _TRUE;
    }

    // Fail Save Mode
    if((GET_INPUT_TIMING_HFREQ() < _FAIL_SAVE_H_FREQ_LOWER_BOUND) || (GET_INPUT_TIMING_HFREQ() > _FAIL_SAVE_H_FREQ_UPPER_BOUND) || \
       (GET_INPUT_TIMING_VFREQ() > _FAIL_SAVE_V_FREQ_UPPER_BOUND))
    {
        SET_FAIL_SAFE_MODE(_TRUE);
    } 
    
#if(_3D_SUPPORT == _ON)

    if(GET_INPUT_TIMING_VFREQ() < ((Scaler3DTxInputFormat() == _NO_3D_FORMAT) ? _OOR_V_FREQ_LOWER_BOUND : 230))
    {
        return _TRUE;
    }

    if(GET_INPUT_TIMING_VFREQ() < ((Scaler3DTxInputFormat() == _NO_3D_FORMAT) ? _FAIL_SAVE_V_FREQ_LOWER_BOUND : 230))
    {
        SET_FAIL_SAFE_MODE(_TRUE);
    } 
    
#else

    if(GET_INPUT_TIMING_VFREQ() < _OOR_V_FREQ_LOWER_BOUND)
    {
        return _TRUE;
    }

    if(GET_INPUT_TIMING_VFREQ() < _FAIL_SAVE_V_FREQ_LOWER_BOUND)
    {
        SET_FAIL_SAFE_MODE(_TRUE);
    } 
    
#endif

    switch(SysSourceGetSourceType())
    {

#if(_VGA_SUPPORT == _ON)

        case _SOURCE_VGA:

            if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_VGA)
            {
                return _TRUE;
            }

            break;

#endif

#if(_DVI_SUPPORT == _ON)

        case _SOURCE_DVI:

            if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_DVI)
            {
                return _TRUE;
            }            

            break;
#endif

#if(_HDMI_SUPPORT == _ON)

        case _SOURCE_HDMI:            

            if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_HDMI)
            {
                return _TRUE;
            }            
            
            break;

#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP: 
            
            if(ScalerSyncGetInputPixelClk() >= _INPUTCLOCK_RANG_DP)
            {
                return _TRUE;
            }     
            
            break;
#endif

        default:
            break;
    }

    return (UserInterfaceOsdNoSupportCheck());
}

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Get DDC-CI Data in Interrupt Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceDdcciIntGetData_EXINT1(void) using 2
{
    BYTE ucTemp = 0;
    
    // Clear Unused DDCCI IRQ Flag
    SET_DDCCI_STATUS2(GET_DDCCI_STATUS2() & ~(_BIT5 | _BIT4));

    if(GET_RUN_DDCCI_COMMAND() == _SUCCESS)
    {
        // Clear Flags
        if((GET_DDCCI_STATUS1() & _BIT1) == _BIT1)
        {
            CLR_DDCCI_STATUS1(_BIT1);
        }

        if((GET_DDCCI_STATUS1() & _BIT2) == _BIT2)
        {
            ucTemp = GET_DDCCI_DATA_IN();
        }
    }
    else
    {
        if(GET_DDCCI_SLAVE_ADDRESS() == _DDCCI_DEST_ADDRESS)
        {
            SET_RUN_DDCCI_COMMAND((bit)ScalerMcuDdcciIntGetData_EXINT1(g_ucDdcciRxBuf));

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
            if(GET_RUN_DDCCI_COMMAND() == _SUCCESS)
            {
                if(UserCommonInterfaceDdcciHDMIFreesyncHandle_EXINT1() == _TRUE)
                {
                    SET_RUN_DDCCI_COMMAND(_FAIL);
                }
            }
#endif
        }
        else
        {
            SET_RUN_DDCCI_COMMAND((bit)UserInterfaceGetFactoryCommand_EXINT1());
        }
    }
}

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
//--------------------------------------------------
// Description  : Get HDMI Freesync support
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserCommonInterfaceDdcciHDMIFreesyncHandle_EXINT1(void) using 2
{
    BYTE ucDdcciCount = 0;

    if(UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1() == _TRUE)
    {
        if(g_ucDdcciRxBuf[_DDCCI_COMMAND] == _DDCCI_CMD_SET_VCP_FEATURE)
        {
            ScalerSyncSetHDMIFREESYNCVcp_EXINT1(g_ucDdcciRxBuf[_DDCCI_SET_HIGH_BYTE]);
        }

        if(g_ucDdcciRxBuf[_DDCCI_COMMAND] == _DDCCI_CMD_GET_VCP_FEATURE)
        {
            g_ucDdcciTxBuf[_DDCCI_SOURCE] = 0x6E;
            g_ucDdcciTxBuf[_DDCCI_LENGTH] = 0x88;
            g_ucDdcciTxBuf[_DDCCI_COMMAND] = 0x02;
            g_ucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
            g_ucDdcciTxBuf[_DDCCI_SINK_OPCODE] = g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE];
            g_ucDdcciTxBuf[_DDCCI_TYPE_CODE] = 0x00;
            g_ucDdcciTxBuf[_DDCCI_MAX_HIGH_BYTE] = 0x00;
            g_ucDdcciTxBuf[_DDCCI_MAX_LOW_BYTE] = 0x00;
            g_ucDdcciTxBuf[_DDCCI_PRESENT_HIGH_BYTE] = ScalerSyncGetHDMIFREESYNCVcp_EXINT1();
            g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE] = UserInterfaceGetFREESYNCEnable_EXINT1();

            g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = (((0xB4 ^ g_ucDdcciTxBuf[_DDCCI_SINK_OPCODE]) ^ g_ucDdcciTxBuf[_DDCCI_PRESENT_HIGH_BYTE]) ^ g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE]);

            // Enable mcu write
            MCU_I2C_IRQ_CTRL2_FF2A |= (_BIT6 | _BIT5);

            while(ucDdcciCount < 11)
            {
                // Load data to DDC-CI buffer
                MCU_I2C_DATA_OUT_FF26 = g_ucDdcciTxBuf[ucDdcciCount++];
            }

            // Disable mcu write
            MCU_I2C_IRQ_CTRL2_FF2A &= ~_BIT5;

            // Clear buffer for new message
            memset(g_ucDdcciRxBuf, 0, _DDCCI_RXBUF_LENGTH);
        }

        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}
#endif

#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _OFF)
bit UserCommonInterfaceGetRunDdcciCommand(void)
{
    return GET_RUN_DDCCI_COMMAND();
}
#endif

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonInterfaceInitial(void)
{
  // Flash write protect
#if(_FLASH_WR_PROTECT ==_ON)
    UserCommonFlashWRProtect();
#endif

    UserInterfaceInitial();
}
