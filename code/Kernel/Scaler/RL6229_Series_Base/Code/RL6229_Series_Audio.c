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
// ID Code      : RL6229_Series_Audio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_AUDIO__

#include "ScalerFunctionInclude.h"

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_AUDIO_DVC_SUPPORT == _ON)
#define _DVC_VOLUME_MUTE_TIMER                  400 // ms
#define _DVC_VOLUME_ADJUST_TIMER                20 // ms

#define _DVC_DB_STEP_NUMBER                     64
#define _DVC_ZCD_TIMEOUT_DEFAULT                (0x0030 & 0x0FFF) // 48KHz, Fcut = 500Hz
#endif // End of #if(_AUDIO_DVC_SUPPORT == _ON)

#define _VOLUME_MUTE_TIMER                      200 // unit:ms
#define _ZCD_TIMEOUT_DEFAULT                    0x1F

#define _AUTO_FREQ_DETECT_XTAL_DIV              (BYTE)(((((WORD) _SYS_CLK_KHZ << 1) / 160) + 1) >> 1)

#define _AUDIO_PLL_VCO                          405 //MHz
#define _AUDIO_PLL_K                            2
#define _AUDIO_PLL_M                            (BYTE)((((DWORD) _AUDIO_PLL_VCO * _AUDIO_PLL_K * 1000 * 2 / _GDI_CLK_KHZ) + 1) / 2)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

#if(_EMBEDDED_DAC_SUPPORT == _ON)
void ScalerAudioDACInitial(void);
void ScalerAudioDACInputSwitch(bit bAudioSource);
void ScalerAudioDACOutputSwitch(EnumAudioDACOutput enumDACOutput);
bit ScalerAudioDACGetInputSource(void);
#endif

void ScalerAudioDisable(void);
void ScalerAudioDigitalAudioInitial(void);
void ScalerAudioDigitalAdjustVolume(WORD usVolume);
void ScalerAudioDigitalVolumeMute(bit bMute, WORD usVolume);
void ScalerAudioDigitalOutputMute(bit bMute);
void ScalerAudioWatchDogProc(bit bOn);

#if(_AUDIO_DVC_SUPPORT == _ON)
void ScalerAudioDVCVolumeAdjustType(bit bAdjustType);
void ScalerAudioDVCAdjustVolume(WORD usVolume);
void ScalerAudioDVCVolumeMute(bit bMute, WORD usVolume);
void ScalerAudioDVCSetMuteZCDTimeout(bit bMute, WORD usVolume, bit bAdjustType);
void ScalerAudioDVCSetVolumeZCDTimeout(WORD usVolume);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial Audio DAC
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACInitial(void)
{
    /*-----------------Audio DAC-----------------*/
    // Power on DAC
    ScalerSetByte(P6_B0_BB_POWER0, 0xFF);

    // Power on bias generator and analog ground generator, Enable line in
    ScalerSetBit(P6_B1_BB_POWER1, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // Power on ZCD
    ScalerSetBit(P6_B2_BB_ZCD_ANA, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1));

    // Enable ZCD control
    ScalerSetByte(P6_C2_ZERO_CROSSING_CTRL, 0xFF);

    // Set ZCD timeout
    ScalerSetBit(P6_C3_ZCD_TIMEOUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT0));

    // Set AOUT unmute
    ScalerSetBit(P6_B3_AOUT_CTL, ~(_BIT7 | _BIT6 | _BIT4), (_BIT7 | _BIT6 | _BIT4));

    // Set HPOUT unmute
    ScalerSetBit(P6_B4_HPOUT_CTL, ~(_BIT7 | _BIT6 | _BIT4), (_BIT7 | _BIT6 | _BIT4));

    // Set volume L for DAC
    ScalerSetByte(P6_B8_DAC_VOL_L, 0x27);

    // Set volume R for DAC
    ScalerSetByte(P6_B9_DAC_VOL_R, 0x27);

    // Set volume L for AIN
    ScalerSetByte(P6_BA_AIN_VOL_L, 0x00);

    // Set volume R for AIN
    ScalerSetByte(P6_BB_AIN_VOL_R, 0x00);

#if(_HEADPHONE_OUTPUT_LR_SWAP == _OFF)
    // Set HP output(L CH : AIN_L, R CH : AIN_R)
    ScalerSetByte(P6_CA_DEPOP_CTRL2, 0xDD);
#else
    // Set HP output(L CH : AIN_L, R CH : AIN_R)
    ScalerSetByte(P6_CA_DEPOP_CTRL2, 0x77);
#endif

#if(_SPEAKER_OUTPUT_LR_SWAP == _OFF)
	// Set AOUT output(L CH : AIN_L, R CH : AIN_R)
    ScalerSetBit(P6_BC_ANA_RESERVE1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
#else
    // Set AOUT output(L CH : AIN_R, R CH : AIN_L)
    ScalerSetBit(P6_BC_ANA_RESERVE1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif

    /*-----------------Depop Circuit-----------------*/
    // Enable de-pop clock and set divider
    ScalerSetBit(P6_CD_DEPOP_CTRL6, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT3));

    // Analog circuit non-overlap clock generator on
    ScalerSetBit(P6_C8_DEPOP_CTRL0, ~_BIT4, _BIT4);

    // Set de-pop type, the current and the capacitor at charge pump
    ScalerSetByte(P6_CC_DEPOP_CTRL5, 0x56);

    // De-pop circuit power on
    ScalerSetBit(P6_C8_DEPOP_CTRL0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));
}

//--------------------------------------------------
// Description  : Switch audio Input (AIN / DAC)
// Input Value  : bAudioSource
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACInputSwitch(bit bAudioSource)
{
    if(bAudioSource == _ANALOG_AUDIO)
    {
#if(_HEADPHONE_OUTPUT_LR_SWAP == _OFF)
        // Set HP output(L CH : AIN_L, R CH : AIN_R)
        ScalerSetByte(P6_CA_DEPOP_CTRL2, 0xDD);
#else
        // Set HP output(L CH : AIN_L, R CH : AIN_R)
        ScalerSetByte(P6_CA_DEPOP_CTRL2, 0x77);
#endif

#if(_SPEAKER_OUTPUT_LR_SWAP == _OFF)
    	// Set AOUT output(L CH : AIN_L, R CH : AIN_R)
        ScalerSetBit(P6_BC_ANA_RESERVE1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
#else
        // Set AOUT output(L CH : AIN_R, R CH : AIN_L)
        ScalerSetBit(P6_BC_ANA_RESERVE1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif
    }
    else //_DIGITAL_AUDIO
    {
#if(_HEADPHONE_OUTPUT_LR_SWAP == _OFF)
        // Set HP output(L CH : DAC_L, R CH : DAC_R)
        ScalerSetByte(P6_CA_DEPOP_CTRL2, 0xEE);
#else
        // Set HP output(L CH : DAC_L, R CH : DAC_R)
        ScalerSetByte(P6_CA_DEPOP_CTRL2, 0xBB);
#endif

#if(_SPEAKER_OUTPUT_LR_SWAP == _OFF)
    	// Set AOUT output(L CH : DAC_L, R CH : DAC_R)
        ScalerSetBit(P6_BC_ANA_RESERVE1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
#else
        // Set AOUT output(L CH : DAC_R, R CH : DAC_L)
        ScalerSetBit(P6_BC_ANA_RESERVE1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
#endif
    }
}

//--------------------------------------------------
// Description  : Switch audio output (AOUT / HPOut)
// Input Value  : enumDACOutput
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACOutputSwitch(EnumAudioDACOutput enumDACOutput)
{
    switch(enumDACOutput)
    {
        case _AUDIO_DAC_OUTPUT_BOTH:
            ScalerSetBit(P6_B3_AOUT_CTL, ~_BIT4, _BIT4);
            ScalerSetBit(P6_B4_HPOUT_CTL, ~_BIT4, _BIT4);
            break;

        case _AUDIO_DAC_OUTPUT_SPEAKER:
            ScalerSetBit(P6_B3_AOUT_CTL, ~_BIT4, _BIT4);
            ScalerSetBit(P6_B4_HPOUT_CTL, ~_BIT4, 0x00);
            break;

        case _AUDIO_DAC_OUTPUT_HEADPHONE:
            ScalerSetBit(P6_B3_AOUT_CTL, ~_BIT4, 0x00);
            ScalerSetBit(P6_B4_HPOUT_CTL, ~_BIT4, _BIT4);
            break;

        default:
            ScalerSetBit(P6_B3_AOUT_CTL, ~_BIT4, 0x00);
            ScalerSetBit(P6_B4_HPOUT_CTL, ~_BIT4, 0x00);
            break;
    }
}

//--------------------------------------------------
// Description  : Get Current DAC Input Source
// Input Value  : None
// Output Value : _ANALOG_AUDIO/ _DIGITAL_AUDIO
//--------------------------------------------------
bit ScalerAudioDACGetInputSource(void)
{
    return ((ScalerGetBit(P6_BC_ANA_RESERVE1, (_BIT7 | _BIT5)) == (_BIT7 | _BIT5)) ? _ANALOG_AUDIO : _DIGITAL_AUDIO);
}

#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Disable audio power for energy-saving
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDisable(void)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)
    ScalerAudioDACNormalToDepop();

    ScalerAudioDACSetVcmReady(_OFF);

    // DAC power down
    ScalerSetByte(P6_B0_BB_POWER0, 0x00);

    // Power down bias generator and analog ground generator, disable line in
    ScalerSetBit(P6_B1_BB_POWER1, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // Power down ZCD
    ScalerSetBit(P6_B2_BB_ZCD_ANA, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

    // Depop CLK power down
    ScalerSetBit(P6_CD_DEPOP_CTRL6, ~_BIT3, 0x00);

    SET_AUDIO_DAC_STATE(_AUDIO_DAC_OFF);
#endif

#if(_AUDIO_DVC_SUPPORT == _ON)
    // Disable DVC counter for power saving
    ScalerSetBit(P8_A0_DVC_0, ~(_BIT6), _BIT6);
#endif

    // Disable FIFO Trend/ Boundary Tracking
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_15_HDMI_PSCR, ~(_BIT3 | _BIT2), 0x00);

    // Disable SDM
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_2D_HDMI_AAPNR, ~_BIT1, 0x00);

    // Disable Audio Freq Detect & Auto Load S Code
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, 0x00);

    // Double Buffer
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~_BIT4, _BIT4);

    // DPLL power down
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Initial HDMI/DP audio setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalAudioInitial(void)
{
    //DPLL power Down
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, ~_BIT7, _BIT7);

    // Set M code
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_11_HDMI_MCAPR, (_AUDIO_PLL_M - 2));

    // Set O code
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, ~(_BIT5 | _BIT4), _BIT4);

    // Set K code and enable double buffer
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | ((_AUDIO_PLL_K - 2) & 0x0F)));

    // VCO Band = 10
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_3A_HDMI_DPCR2, ~(_BIT4 | _BIT3), _BIT4);

    //DPLL power up
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, ~_BIT7, 0x00);

    //Delay 2000us
    ScalerTimerDelayXms(2);

    //DPLL CMP enable
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, ~_BIT0, _BIT0);

    //Delay 1000us
    ScalerTimerDelayXms(1);

    //DPLL latch calibration enable
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, ~_BIT1, _BIT1);

    //Delay 1000us
    ScalerTimerDelayXms(1);

    //DPLL calibration validated
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, ~_BIT2, _BIT2);

    // Set auto gain incremental and delay
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_06_HDMI_MAGCR1, 0x84);

#if(_AUDIO_DVC_SUPPORT == _ON)
    // Enable DVC function and counter
    ScalerSetBit(P8_A0_DVC_0, ~(_BIT7|_BIT6), _BIT7);

    // Set DVC ZCD window size
    ScalerSetBit(P8_A3_DVC_WINDOW_CONTROL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_DVC_ZCD_TIMEOUT_DEFAULT));
    ScalerSetByte(P8_A4_DVC_WINDOW_CONTROL_1, LOBYTE(_DVC_ZCD_TIMEOUT_DEFAULT));

    // Select DVC Volume Adjust Type
    ScalerAudioDVCVolumeAdjustType(_DVC_ADJUST_TYPE);

    // Initial DVC gain = 0
    ScalerSetBit(P8_A5_GAIN_0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetByte(P8_A6_GAIN_DB, 0x00);

    // Set auto gain delay mode and final gain = full gain
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_07_HDMI_MAG_M_FINAL, ~(_BIT3), 0x00);
#else
    // Set auto gain delay mode and audio manual gain
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_07_HDMI_MAG_M_FINAL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);

    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, 0x00);

    // Disable DVC delay mode
    ScalerSetBit(P8_A0_DVC_0, ~_BIT7, 0x00);

    // Initial DVC gain = full gain
    ScalerSetBit(P8_A5_GAIN_0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
    ScalerSetByte(P8_A6_GAIN_DB, 0xFF);

#endif

    // Disable sine wave generator
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, ~_BIT4, 0x00);

    // Disable AVMUTE function and enable Audio FIFO Tracking main control (I/P code)
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~(_BIT7 | _BIT5), _BIT5);

    // Enable FIFO Trend/ Boundary Tracking
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_15_HDMI_PSCR, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2));

    // Enable SDM
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_2D_HDMI_AAPNR, ~_BIT1, _BIT1);

    // Enable LFSR control (For RL6229/RL6192)
    ScalerSetByte(P6_CE_LFSR_CTRL, 0x90);

    // Set wait time for load parameter
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0A_AUDIO_LD_P_TIME_M, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0B_AUDIO_LD_P_TIME_N, 0x10);

    // Set ZCD timeout
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0D_ZCD_TIMEOUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _ZCD_TIMEOUT_DEFAULT);

    // Set Boundary Address = 5 for Boundary Tracking
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_1B_HDMI_FBR, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

    // Set I code of trend
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_20_HDMI_ICTPSR0, 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_21_HDMI_ICTPSR1, 0x02);

    // Set P code of trend
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_22_HDMI_PCTPSR0, 0x7F);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_23_HDMI_PCTPSR1, 0xFF);

    // Set I code of boundary
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_24_HDMI_ICBPSR0, HIBYTE(_INITIAL_I_CODE));
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_25_HDMI_ICBPSR1, LOBYTE(_INITIAL_I_CODE));;

    // Set P code of boundary
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_26_HDMI_PCBPSR0, 0x7F);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_27_HDMI_PCBPSR1, 0xFF);

    // Audio Normal Output
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

    // Disable Audio Watchdog for FIFO Overflow/Underflow
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~(_BIT2 | _BIT1), 0x00);

    // Set X Value
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_32_HDMI_WDCR1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

    // Set Y Value
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_33_HDMI_WDCR2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

    // Bit2: When no audio or changing sampling rate, AFSM load double buffer one more.
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_A3_AFSM_MOD_A3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT2));

    // Enable SPDIF/I2S Output
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_62_HDMI_AOCR, 0xFF);

    // Change audio clk divider according to SYSCLK = 27MHz
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_93_XTAL_DIV, _AUTO_FREQ_DETECT_XTAL_DIV);

    // Enable Audio Freq Detect & Auto Load S Code
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, 0xC0);

    // Double Buffer
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~_BIT4, _BIT4);

#if(_DP_SUPPORT == _ON)
    // Modify for DP/HDMI Audio interface bug
    ScalerSetBit(P2_AB_TMDS_ACC2, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));

    // Enable RS Decode
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_80_MN_RS_DEC_CTRL, ~(_BIT7 | _BIT3 | _BIT2), (_BIT7 | _BIT3 | _BIT2));

    // Enable RS Error Handle
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_81_RS_DEC_ERR_HANDLE, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // Enable Audio Buffer
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_90_DP_AUD_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    // Set AUD PKT ID
    ScalerSetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_91_AUD_ID, 0x00);

    // Enable Auto Reset BCH Counter
    ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_92_AUD_BUF_STATUS, ~_BIT3, _BIT3);
#endif
}

//--------------------------------------------------
// Description  : Adjust Digital volume
// Input Value  : ucVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalAdjustVolume(WORD usVolume)
{
#if(_AUDIO_DVC_SUPPORT == _ON)
        ScalerAudioDVCSetVolumeZCDTimeout(usVolume);

        ScalerAudioDVCAdjustVolume(usVolume);
#else
        // Set ZCD timeout
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0D_ZCD_TIMEOUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _ZCD_TIMEOUT_DEFAULT);

        // Final gain = 0~255
        usVolume &= 0x00FF;

        // Set audio manual gain
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_07_HDMI_MAG_M_FINAL, ~(_BIT1 | _BIT0), 0x00);

        // L channel
        ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, (BYTE) usVolume);

        // R channel (double buffer)
        ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, (BYTE) usVolume);
#endif
}

//--------------------------------------------------
// Description  : Smooth adjust digital volume for mute/unmute
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalVolumeMute(bit bMute, WORD usVolume)
{
#if(_AUDIO_DVC_SUPPORT == _ON)
    ScalerAudioDVCVolumeMute(bMute, usVolume);
#else
    if(usVolume != 0)
    {
        PDATA_DWORD(0) = ((DWORD)_VOLUME_MUTE_TIMER << 8) / usVolume;

        pData[0] = (((((DWORD)PDATA_DWORD(0) * _SYS_CLK_KHZ ) >> 19) + 1) / 2 - 1) & 0x7F;

        // Set ZCD timeout
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0D_ZCD_TIMEOUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), pData[0]);

        if(bMute == _ON)
        {
            // Get Current Volume
            ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, 1, pData, _AUTOINC);

            if(pData[0] != 0x00)
            {
                do
                {
                    pData[1] = 2;

                    usVolume--;

                    // L channel
                    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, (BYTE) usVolume);

                    // R channel (double buffer)
                    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, (BYTE) usVolume);

                    do
                    {
                        if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0E_ZCD_STATUS, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
                        {
                            break;
                        }
                        ScalerTimerDelayXms(1);
                    }
                    while(--pData[1]);

                }
                while(usVolume != 0);
            }

            // Set the default ZCD timeout
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0D_ZCD_TIMEOUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _ZCD_TIMEOUT_DEFAULT);
        }
        else // Unmute
        {
            // Get Current Volume
            ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, 1, pData, _AUTOINC);

            if(pData[0] != usVolume)
            {
                // Volume temp
                pData[0] = 0;

                do
                {
                    pData[1] = 2;
                    pData[0]++;

                    // L channel
                    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, pData[0]);

                    // R channel (double buffer)
                    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, pData[0]);

                    do
                    {
                        if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0E_ZCD_STATUS, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
                        {
                            break;
                        }
                        ScalerTimerDelayXms(1);
                    }
                    while(--pData[1]);
                }
                while(pData[0] != usVolume);
            }

            // Set the default ZCD timeout
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0D_ZCD_TIMEOUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _ZCD_TIMEOUT_DEFAULT);
        }
    }
#endif
}

//--------------------------------------------------
// Description  : Switch Digital Audio Output Mute
// Input Value  : _ON => Mute On
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalOutputMute(bit bMute)
{
    if(bMute == _ON)
    {
        // Disable Auido Output
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~_BIT5, 0x00);
    }
    else
    {
        // Enable Auido Output
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~_BIT5, _BIT5);
    }
}

//--------------------------------------------------
// Description  : Audio Watch Dog Proc
// Input Value  : bOn
// Output Value : None
//--------------------------------------------------
void ScalerAudioWatchDogProc(bit bOn)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(ScalerAudioDACGetInputSource() == _DIGITAL_AUDIO)
#endif
    {
        if(bOn == _ON)
        {
            DebugMessageAudio("Audio WatchDog On", ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, _BIT5));

            // Clear No Audio Flag and Sampling Frequency Changed Flag
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Clear audio FIFO overflow and underflow status
            ScalerSetBit(P2_CB_HDMI_SR, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

            // Enable Audio Watch Dog for FIFO Overflow/Underflow
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
        }
        else
        {
            DebugMessageAudio("Audio WatchDog Off", ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, _BIT5));

            ScalerTimerDelayXms(2);

            if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, (_BIT1 | _BIT0)) != 0x00)
            {
                DebugMessageAudio("Sampling Freq Changed", ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, (_BIT1 | _BIT0)));

                // Clear No Audio Flag and Sampling Frequency Changed Flag
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

                // Disable FIFO Trend/ Boundary Tracking
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_15_HDMI_PSCR, ~(_BIT3 | _BIT2), 0x00);

                // Double Buffer
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~_BIT4, _BIT4);

                // Reset D code(48KHz)
                ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_13_HDMI_DCAPR0, 0x1F);
                ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_14_HDMI_DCAPR1, 0x74);

                // Double Buffer
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~_BIT4, _BIT4);

                // Load D code
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~_BIT6, _BIT6);
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~_BIT6, 0x00);

                ScalerTimerDelayXms(2);

                // Enable FIFO Trend/ Boundary Tracking
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_15_HDMI_PSCR, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

                // Double Buffer
                ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~_BIT4, _BIT4);
            }

            // Disable Audio Watch Dog for FIFO Overflow/Underflow
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~(_BIT2 | _BIT1), 0x00);

            // Enable Audio Output
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~_BIT5, _BIT5);
        }
    }
}

#if(_AUDIO_DVC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Select DVC Volume Adjust Type
// Input Value  : _DB_GAIN, _VOLUME_STEP_SIZE
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCVolumeAdjustType(bit bAdjustType)
{
    if(bAdjustType == _DB_GAIN)
    {
        // Select value mode and set DB gain setp
        ScalerSetBit(P8_A0_DVC_0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), ((_DB_GAIN_DOWN_VALUE << 2) | _DB_GAIN_UP_VALUE));

        // Initial volume step size for DB gain mode
        ScalerSetBit(P8_A1_DVC_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
        ScalerSetByte(P8_A2_DVC_VA_DB, 0x01);
    }
    else // _VOLUME_STEP_SIZE
    {
        // Select value mode
        ScalerSetBit(P8_A0_DVC_0, ~(_BIT4), _BIT4);

        // Set volume step size
        ScalerSetBit(P8_A1_DVC_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(_VOLUME_STEP_SIZE_VALUE));
        ScalerSetByte(P8_A2_DVC_VA_DB, LOBYTE(_VOLUME_STEP_SIZE_VALUE));
    }
}

//--------------------------------------------------
// Description  : Adjust digital volume for DVC function
// Input Value  : ucVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCAdjustVolume(WORD usVolume)
{
    // DVC gain MSB
    ScalerSetByte(P8_A5_GAIN_0, (HIBYTE(usVolume) & 0x3F));

    // DVC gain LSB  (double buffer)
    ScalerSetByte(P8_A6_GAIN_DB, LOBYTE(usVolume));
 }

//--------------------------------------------------
// Description  : Mute/Unmute for DVC function
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCVolumeMute(bit bMute, WORD usVolume)
{
    ScalerAudioDVCVolumeAdjustType(_DVC_ADJUST_TYPE);

    ScalerAudioDVCSetMuteZCDTimeout(bMute, usVolume, _DVC_ADJUST_TYPE);

    PDATA_WORD(0) = (((WORD) ScalerGetByte(P8_A7_GAIN_1) << 8) | ScalerGetByte(P8_A8_GAIN_2));

    if(bMute == _ON)
    {
        if(PDATA_WORD(0) != 0)
        {
            ScalerAudioDVCAdjustVolume(0);

            PDATA_WORD(1) = 0;

            do
            {
                ScalerTimerDelayXms(1);
                PDATA_WORD(1)++;
            }
            while((ScalerGetBit(P8_A9_GAIN_DONE, _BIT7) != _BIT7) && (PDATA_WORD(1) < _DVC_VOLUME_MUTE_TIMER));
        }
    }
    else // Unmute
    {
        if(PDATA_WORD(0) != usVolume)
        {
            ScalerAudioDVCAdjustVolume(usVolume);
        }
    }
}

//--------------------------------------------------
// Description  : Set ZCD Timeout
// Input Value  : bMute, usVolume, bAdjustType
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCSetMuteZCDTimeout(bit bMute, WORD usVolume, bit bAdjustType)
{
    // Get Sampling Rate
    pData[2] = ScalerAudioSamplingFreqDetect();

    if(bAdjustType == _DB_GAIN)
    {
        // Get down or up step
        pData[0] = (bMute == _ON) ? (ScalerGetBit(P8_A0_DVC_0, (_BIT3 | _BIT2)) >> 2) : ScalerGetBit(P8_A0_DVC_0, (_BIT1 | _BIT0));

        // Get numbers of the volume step for mute or unmute
        PDATA_WORD(0) = _DVC_DB_STEP_NUMBER << pData[0];
    }
    else
    {
        PDATA_WORD(0) = usVolume / _VOLUME_STEP_SIZE_VALUE + usVolume % _VOLUME_STEP_SIZE_VALUE;
    }

    // Calculate samples of ZCD timeout
    PDATA_WORD(0) = ((DWORD)pData[2] * _DVC_VOLUME_MUTE_TIMER / PDATA_WORD(0)) & 0x0FFF;

    // Set DVC ZCD window size
    ScalerSetBit(P8_A3_DVC_WINDOW_CONTROL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(PDATA_WORD(0)));
    ScalerSetByte(P8_A4_DVC_WINDOW_CONTROL_1, LOBYTE(PDATA_WORD(0)));
}

//--------------------------------------------------
// Description  : Set ZCD Timeout, only use the type "_VOLUME_STEP_SIZE"
// Input Value  : usVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioDVCSetVolumeZCDTimeout(WORD usVolume)
{
    ScalerAudioDVCVolumeAdjustType(_VOLUME_STEP_SIZE);

    // Get Sampling Rate
    pData[2] = ScalerAudioSamplingFreqDetect();

    // Get Current Volume
    PDATA_WORD(0) = ((WORD)(ScalerGetByte(P8_A5_GAIN_0) & 0x3F) << 8) | ((WORD)ScalerGetByte(P8_A6_GAIN_DB));

    PDATA_WORD(0) = (PDATA_WORD(0) > usVolume) ? (PDATA_WORD(0) - usVolume):(usVolume - PDATA_WORD(0));

    PDATA_WORD(0) = PDATA_WORD(0) / _VOLUME_STEP_SIZE_VALUE + PDATA_WORD(0) % _VOLUME_STEP_SIZE_VALUE;

    // Calculate samples of ZCD timeout
    PDATA_WORD(0) = ((DWORD)pData[2] * _DVC_VOLUME_ADJUST_TIMER / PDATA_WORD(0)) & 0x0FFF;

    // Set DVC ZCD window size
    ScalerSetBit(P8_A3_DVC_WINDOW_CONTROL_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), HIBYTE(PDATA_WORD(0)));
    ScalerSetByte(P8_A4_DVC_WINDOW_CONTROL_1, LOBYTE(PDATA_WORD(0)));
}
#endif // End of #if(_AUDIO_DVC_SUPPORT == _ON)

#endif // End of #if(_AUDIO_SUPPORT == _ON)
