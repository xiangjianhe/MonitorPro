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
// ID Code      : RL6001_Series_Audio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6001_SERIES_AUDIO__

#include "ScalerFunctionInclude.h"

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _VOLUME_MUTE_TIMER                        200 // unit:ms
#define _ZCD_TIMEOUT_DEFAULT                      0x1F

#define _AUTO_FREQ_DETECT_XTAL_DIV                (BYTE)(((((WORD) _SYS_CLK_KHZ << 1) / 160) + 1) >> 1)

#define _AUDIO_PLL_VCO                                  378 //MHz
#define _AUDIO_PLL_K                                    2
#define _AUDIO_PLL_M                                    (BYTE)((((DWORD)_AUDIO_PLL_VCO * _AUDIO_PLL_K * 1000 * 2 / _GDI_CLK_KHZ) + 1) / 2)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_DP_BCH_ERROR_HANDLE == _ON)
bit bAudioNoPeakDetected = _TRUE;
#endif

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

#if(_DP_BCH_ERROR_HANDLE == _ON)
void ScalerAudioDpBchErrorHandle(void);
void ScalerAudioDpBchErrorReset(void);
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

    // Set HP output(L CH : AIN_L, R CH : AIN_R)
    ScalerSetByte(P6_CA_DEPOP_CTRL2, 0xDD);

    // Set AOUT output(L CH : AIN_L, R CH : AIN_R)
    ScalerSetBit(P6_B3_AOUT_CTL, ~_BIT5, _BIT5);
    
    // Select ZCD Reference Input
    ScalerSetBit(P6_B4_HPOUT_CTL, ~_BIT5, _BIT5);
		
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
        // Enable AOUT Output from AIN L/R
        ScalerSetBit(P6_B3_AOUT_CTL, ~_BIT5, _BIT5);

        // Enable HP Output from AIN L/R
        ScalerSetByte(P6_CA_DEPOP_CTRL2, 0xDD);
        
        // Select ZCD Reference Input
        ScalerSetBit(P6_B4_HPOUT_CTL, ~_BIT5, _BIT5);
    }
    else //_DIGITAL_AUDIO
    {
        // Enable AOUT Output from DAC L/R
        ScalerSetBit(P6_B3_AOUT_CTL, ~_BIT5, 0x00);

        // Enable HP Output from DAC L/R
        ScalerSetByte(P6_CA_DEPOP_CTRL2, 0xEE);

        // Select ZCD Reference Input
        ScalerSetBit(P6_B4_HPOUT_CTL, ~_BIT5, 0x00);
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
    return ((ScalerGetBit(P6_B3_AOUT_CTL, _BIT5) == _BIT5) ? _ANALOG_AUDIO : _DIGITAL_AUDIO);
}
#endif

//--------------------------------------------------
// Description  : Transfer depop mode to Normal mode
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
    // Set M code
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_11_HDMI_MCAPR, (_AUDIO_PLL_M - 2));

    // Set O code
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_38_HDMI_DPCR0, ~(_BIT5 | _BIT4), _BIT4);

    // Set K code and enable double buffer
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | ((_AUDIO_PLL_K - 2) & 0x0F)));

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

    // Set auto gain delay mode and audio manual gain
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_07_HDMI_MAG_M_FINAL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);

    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, 0x00);
           
    // Disable sine wave generator
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, ~_BIT4, 0x00);

    // Disable AVMUTE function and enable Audio FIFO Tracking main control (I/P code)
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~(_BIT7 | _BIT5), _BIT5);

    // Enable FIFO Trend/ Boundary Tracking
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_15_HDMI_PSCR, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2));

    // Enable SDM
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_2D_HDMI_AAPNR, ~_BIT1, _BIT1);

    // Enable LFSR control (For RL6001)
    ScalerSetByte(P6_C5_DIG_RESERVE1, 0x09);
    
    // Set wait time for load parameter
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0A_AUDIO_LD_P_TIME_M, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0B_AUDIO_LD_P_TIME_N, 0x10);

    // Set ZCD timeout
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_0D_ZCD_TIMEOUT, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _ZCD_TIMEOUT_DEFAULT);
    
    // Set I code of trend
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_20_HDMI_ICTPSR0, 0x00);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_21_HDMI_ICTPSR1, 0x02);
    
    // Set P code of trend
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_22_HDMI_PCTPSR0, 0xFF);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_23_HDMI_PCTPSR1, 0xFF);

    // Set I code of boundary
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_24_HDMI_ICBPSR0, HIBYTE(_INITIAL_I_CODE));
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_25_HDMI_ICBPSR1, LOBYTE(_INITIAL_I_CODE));;
    
    // Set P code of boundary
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_26_HDMI_PCBPSR0, 0xFF);
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_27_HDMI_PCBPSR1, 0xFF);

    // Audio Normal Output
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

    // Set X Value
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_32_HDMI_WDCR1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Set Y Value
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_33_HDMI_WDCR2, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    
    // Auto Load Double Buffer When FIFO is Overflow and Underflow
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_34_HDMI_DBCR, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
    
    // Enable SPDIF/I2S Output
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_62_HDMI_AOCR, 0xFF);

    // Change audio clk divider according to SYSCLK = 24.3MHz
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_93_XTAL_DIV, _AUTO_FREQ_DETECT_XTAL_DIV);

    // Enable Audio Freq Detect & Auto Load S Code
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, 0xC0);

    // Set I2S Output for AVC&EQ Support ([3:2]: 1 -> No Support; 0 -> Support) and Select divider of mclk
    ScalerSetBit(P8_E0_I2S_OUT_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

    // Set SPDIF Output for AVC&EQ Support ([2:1]: 1 -> No Support; 0 -> Support)
    ScalerSetBit(P8_F0_SPDIF_OUT_0, ~(_BIT2 | _BIT1), _BIT1);

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
#endif

#if(_DP_BCH_ERROR_HANDLE == _ON)
    // Enable Peak Detection and Clear L/R overflow flag
    ScalerSetBit(P8_D3_PEAK_CTRL_0, ~(_BIT7 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));

    // Set the Overflow Threshold of Left Channel
    ScalerSetByte(P8_D5_PEAK_CTRL_L_0, 0x00);
    ScalerSetByte(P8_D6_PEAK_CTRL_L_1, 0x00);
    ScalerSetByte(P8_D7_PEAK_CTRL_L_2, 0x01);

    // Set Monitor Period of Left Channel
    ScalerSetByte(P8_D8_PEAK_CTRL_L_3, 0x00);
    ScalerSetByte(P8_D9_PEAK_CTRL_L_4, 0x20);

    // Set the Overflow Threshold of Right Channel
    ScalerSetByte(P8_DA_PEAK_CTRL_R_0, 0x00);
    ScalerSetByte(P8_DB_PEAK_CTRL_R_1, 0x00);
    ScalerSetByte(P8_DC_PEAK_CTRL_R_2, 0x01);

    // Set Monitor Period of Rught Channel
    ScalerSetByte(P8_DD_PEAK_CTRL_R_3, 0x00);
    ScalerSetByte(P8_DE_PEAK_CTRL_R_4, 0x20);
#endif
}

//--------------------------------------------------
// Description  : Adjust Digital volume
// Input Value  : bAudioSource, ucVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalAdjustVolume(WORD usVolume)
{
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
}

//--------------------------------------------------
// Description  : Smooth adjust digital volume for mute/unmute 
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalVolumeMute(bit bMute, WORD usVolume)
{
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

#if(_DP_BCH_ERROR_HANDLE == _ON)
                if(GET_DIGITAL_AUDIO_SOURCE() == _DIGITAL_AUDIO_SOURCE_DP)
                {
                    // Avoid Bch Error Problem
                    ScalerAudioDpBchErrorReset();
                    
                    bAudioNoPeakDetected = _FALSE;    
                }
#endif           

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
#if(_DP_BCH_ERROR_HANDLE == _ON)
        // If output was previously disabled
        if((GET_DIGITAL_AUDIO_SOURCE() == _DIGITAL_AUDIO_SOURCE_DP) && (ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, _BIT5) == 0x00))
        {
            BYTE ucTemp[2];
            
            // Back up Audio Volume
            ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, 1, &ucTemp[0], _NON_AUTOINC);
            ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, 1, &ucTemp[1], _NON_AUTOINC);
            
            // Mute Audio Volume
            ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, 0x00);
            ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, 0x00);

            // Enable Auido Output
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~_BIT5, _BIT5);
                            
            ScalerAudioDpBchErrorReset();
            
            // Reload Audio Volume
            ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, ucTemp[0]);
            ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, ucTemp[1]);
        }
        else
#endif               
        {
            // Enable Auido Output
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~_BIT5, _BIT5);
        }
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

            // Clear audio FIFO overflow and underflow status
            ScalerSetBit(P2_CB_HDMI_SR, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

            // Enable Audio Watch Dog for FIFO Overflow/Underflow
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));
        }
        else
        {
            DebugMessageAudio("Audio WatchDog Off", ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, _BIT5));

            // Disable Audio Watch Dog for FIFO Overflow/Underflow
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_31_HDMI_WDCR0, ~(_BIT2 | _BIT1), 0x00);

            // Enable Audio Output
            ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_30_HDMI_AVMCR, ~_BIT5, _BIT5);
        }
    }
}

#if(_DP_BCH_ERROR_HANDLE == _ON)
//--------------------------------------------------
// Description  : Solved the buzzing created by the wrong BCH_counter for DP source
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDpBchErrorHandle(void)
{
    if(GET_DIGITAL_AUDIO_SOURCE() == _DIGITAL_AUDIO_SOURCE_DP)
    {
        // Audio Detected
        if(GET_AUDIO_PACKET_DETECT() == _TRUE)
    	{
            // Check Peak Detection
            if(ScalerGetBit(P8_D3_PEAK_CTRL_0, (_BIT1 | _BIT0)) != 0x00)
            {
                // Clear Peak Detection Flag
                ScalerSetBit(P8_D3_PEAK_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
                
                if(bAudioNoPeakDetected == _TRUE)
                {
                    DebugMessageAudio("DP BCH Error Do Reset", 0x00);
                    
                    bAudioNoPeakDetected = _FALSE;                                         
                    
                    // Back up Audio Volume
                    ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, 1, &pData[3], _NON_AUTOINC);
                    ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, 1, &pData[4], _NON_AUTOINC);
                    
                    // Mute Audio Volume
                    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, 0x00);
                    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, 0x00);
                                    
                    ScalerAudioDpBchErrorReset();
                    
                    // Reload Audio Volume
                    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_08_HDMI_MAG_L_FINAL, pData[3]);
                    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_09_HDMI_MAG_R_FINAL, pData[4]);
                                                  
                }
            }
            else
            {
                bAudioNoPeakDetected = _TRUE;           
            }                  
    	}          
        else
        {
            bAudioNoPeakDetected = _TRUE;
            
            // Clear Peak Detection Flag
            ScalerSetBit(P8_D3_PEAK_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
        }
    }
    else
    {
            bAudioNoPeakDetected = _TRUE;
            
            // Clear Peak Detection Flag
            ScalerSetBit(P8_D3_PEAK_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
    }
}

//--------------------------------------------------
// Description  : Reset Bch Error Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDpBchErrorReset(void)
{
    // Clear FIFO Full flag
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_04_HDMI_AFSR, ~_BIT3, _BIT3);

    // Set Target Level to Make FIFO Overflow
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_1B_HDMI_FBR, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), 0xF0);

    // Set Manual Mode for FIFO
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), _BIT2);
    
    pData[1] = 0;

    do
    {   
        ScalerTimerDelayXms(1);
        
        // Get FIFO Full Flag
        ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_04_HDMI_AFSR, 1, pData, _NON_AUTOINC);
        
        if((pData[0] & _BIT3) == _BIT3)
        {                                                
            // Disable DP Buffer
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_90_DP_AUD_CTRL, ~_BIT7, 0x00);

            // Enable DP Buffer
            ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_90_DP_AUD_CTRL, ~_BIT7, _BIT7);
            
            break;
        }
        
        pData[1]++;
    }
    while(pData[1] < 10);

    // Set Target Level to Make FIFO Normal
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_1B_HDMI_FBR, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), 0x70);

    // Set Auto Mode for FIFO
    ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, ~(_BIT6 | _BIT2 | _BIT1 | _BIT0), _BIT6);
}
#endif // End of #if(_DP_BCH_ERROR_HANDLE == _ON)

#endif // End of #if(_AUDIO_SUPPORT == _ON)
