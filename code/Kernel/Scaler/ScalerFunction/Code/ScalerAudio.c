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
// ID Code      : ScalerAudio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_AUDIO__

#include "ScalerFunctionInclude.h"

#if(_AUDIO_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _AUTO_FREQ_DETECT_44K_AND_48K_TH            0x2E
#define _AUTO_FREQ_DETECT_88K_AND_96K_TH            0x5C
#define _AUTO_FREQ_DETECT_176K_AND_192K_TH          0xB6

#define _AUDIO_DYNAMIC_I_CODE_TIMER_MS              100 // Unit: ms

#define GET_AUDIO_ICODE_RELOADED()                  (bit)(g_stAudioDigtalInfo.b1AudioICodeReloaded)
#define SET_AUDIO_ICODE_RELOADED()                  (g_stAudioDigtalInfo.b1AudioICodeReloaded = _TRUE)
#define CLR_AUDIO_ICODE_RELOADED()                  (g_stAudioDigtalInfo.b1AudioICodeReloaded = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

#if(_EMBEDDED_DAC_SUPPORT == _ON)
StructAudioDACInfo g_stAudioDACInfo = {0};
#endif

StructAudioDigitalInfo g_stAudioDigtalInfo = {0};
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerAudioInitial(void);
void ScalerAudioMuteProc(bit bMute, WORD usVolume);
void ScalerAudioDigitalDetect(void);
bit ScalerAudioGetAudioDetected(void);
BYTE ScalerAudioGetDigitalAudioSource(void);
BYTE ScalerAudioSamplingFreqDetect(void);
bit ScalerAudioLPCMCheckData(void);

#if(_HDMI_SUPPORT == _ON)
bit ScalerAudioLPCMCheckInfo(void);
#endif

void ScalerAudioLoadStableICodeEvent(void);

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
void ScalerAudioInternalAudioGenSwitch(bit bOn);
bit ScalerAudioGetInternalAudioGenEnable(void);
#endif

#if(_EMBEDDED_DAC_SUPPORT == _ON)
void ScalerAudioDACSetState(EnumAudioDACState enumTargetState);
EnumAudioDACState ScalerAudioDACGetState(void);
bit ScalerAudioDACGetStateChange(void);
void ScalerAudioDACClrStateChange(void);
void ScalerAudioDACSetVcmReady(bit bReady);
void ScalerAudioDACNormalToDepop(void);
void ScalerAudioDACDepopToNormal(void);
void ScalerAudioDACOutputEnable(void);
EnumAudioDACOutput ScalerAudioDACGetOutput(void);
void ScalerAudioDACRestart(void);
void ScalerAudioAnalogVolumeMute(bit bMute, BYTE ucVolume);
void ScalerAudioAnalogAdjustVolume(WORD usVolume, bit bAudioInputType);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Audio Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioInitial(void)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)        
    ScalerAudioDACSetVcmReady(_ON);
    
    ScalerAudioDACSetState(_AUDIO_DAC_INITIAL); 
#endif

    ScalerAudioDigitalAudioInitial();

    CLR_AUDIO_ICODE_RELOADED();
}

//--------------------------------------------------
// Description  : Audio Mute proc
// Input Value  : bMute, usVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioMuteProc(bit bMute, WORD usVolume)
{
#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(ScalerAudioDACGetInputSource() == _ANALOG_AUDIO)
    {
        DebugMessageAudio("Audio Mute Proc - Analog", bMute);
        ScalerAudioAnalogVolumeMute(bMute, (BYTE) usVolume);
    }
    else
#endif                            
    {
        DebugMessageAudio("Audio Mute Proc - Digital", bMute);        
        ScalerAudioDigitalVolumeMute(bMute, usVolume);
    } 
}

//--------------------------------------------------
// Description  : Detect digital audio for HDMI/DP interface
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDigitalDetect(void)
{
    if(ScalerAudioSamplingFreqDetect() != 0x00)
    {
        // MAC Switch to HDMI or DP
        if(ScalerGetBit(PC_A1_DP_CTL, _BIT5) == _BIT5)
        {
            SET_AUDIO_PACKET_DETECT();
            SET_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_HDMI);
        }
        else
        {
#if(_DP_SUPPORT == _ON)
            if(ScalerGetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_01_DP_VBID, _BIT4) == 0x00)
            {
                SET_AUDIO_PACKET_DETECT();
                SET_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_DP);

                // Set DP Receive Port1 In Sync
                ScalerDpSinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_IN_SYNC);
            }
            else
            {
                CLR_AUDIO_PACKET_DETECT();
                SET_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);

                // Clear DP Receive Port1 In Sync
                ScalerDpSinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_OUT_OF_SYNC);
            }
#else
            CLR_AUDIO_PACKET_DETECT();
            SET_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);            
#endif
        }
    
            
        if(GET_AUDIO_ICODE_RELOADED() == _FALSE)
        {            
            ScalerTimerReactiveTimerEvent(_AUDIO_DYNAMIC_I_CODE_TIMER_MS, _SCALER_TIMER_EVENT_AUDIO_LOAD_STABLE_I_CODE);

            SET_AUDIO_ICODE_RELOADED();
        }                
    }
    else
    {
#if(_DP_SUPPORT == _ON)
        if(GET_DIGITAL_AUDIO_SOURCE() == _DIGITAL_AUDIO_SOURCE_DP)
        {
            // Clear DP Receive Port1 In Sync
            ScalerDpSinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_OUT_OF_SYNC);
        }
#endif        
        CLR_AUDIO_PACKET_DETECT();
        SET_DIGITAL_AUDIO_SOURCE(_DIGITAL_AUDIO_SOURCE_NONE);

        if(GET_AUDIO_ICODE_RELOADED() == _TRUE)
        {                        
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_AUDIO_LOAD_STABLE_I_CODE);
            
            // Set high byte of I code for boundary tracking
            ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_24_HDMI_ICBPSR0, HIBYTE(_INITIAL_I_CODE));

            // Set low byte of I code for boundary tracking
            ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_25_HDMI_ICBPSR1, LOBYTE(_INITIAL_I_CODE));

            DebugMessageAudio("Load initial I code", _INITIAL_I_CODE);

            CLR_AUDIO_ICODE_RELOADED();
        }           
    }

#if(_DP_BCH_ERROR_HANDLE == _ON)
    ScalerAudioDpBchErrorHandle();
#endif
}

//--------------------------------------------------
// Description  : Get Audio Detected 
// Input Value  : None
// Output Value : TRUE => Audio Detected
//--------------------------------------------------
bit ScalerAudioGetAudioDetected(void)
{
    // Check audio packet
    if(GET_AUDIO_PACKET_DETECT() == _FALSE)
    {
        DebugMessageAudio("False : Audio Packet", 0);
        return _FALSE;
    }
    
    // Check audio FIFO overflow and underflow
    if(ScalerGetBit(P2_CB_HDMI_SR, (_BIT2 | _BIT1)) != 0x00)
    {
        // Clear audio FIFO overflow and underflow status
        ScalerSetBit(P2_CB_HDMI_SR, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

        DebugMessageAudio("False : Audio FIFO", 0);
        return _FALSE;
    }
    
    return _TRUE;    
}

//--------------------------------------------------
// Description  : Get Current Digital Audio Source
// Input Value  : None
// Output Value : Digital Audio Source
//--------------------------------------------------
BYTE ScalerAudioGetDigitalAudioSource(void)
{
    return GET_DIGITAL_AUDIO_SOURCE();
}

//--------------------------------------------------
// Description  : Detect Audio Sampling Freq
// Input Value  : None
// Output Value : Audio Sampling Freq
//--------------------------------------------------
BYTE ScalerAudioSamplingFreqDetect(void)
{  
    WORD usAudioPacketNum = 0;
    BYTE ucCounter = 0;
    
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioGetInternalAudioGenEnable() == _ENABLE)
    {
        //For Audio test pattern
        SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_48K);
        return 48;
    }
#endif

    do
    {
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_91_AUDIO_FREQDET_RESULT_M, ~_BIT4, _BIT4);
        ScalerGetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_91_AUDIO_FREQDET_RESULT_M, 2, pData, _AUTOINC);
        
        usAudioPacketNum += (((WORD)(pData[0] & 0x0F) << 8) | pData[1]); 
        ucCounter++;
    }
    while(ucCounter < 2);
    
    usAudioPacketNum /= ucCounter;
    
    switch((pData[0] & (_BIT7 | _BIT6 | _BIT5)))
    {
        case 0x20: // Range 1
            SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_32K);
            return 32;
            
        case 0x40: // Range 2
            if(usAudioPacketNum < _AUTO_FREQ_DETECT_44K_AND_48K_TH)
            {
                SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_44_1K);
                return 44;
            }
            else
            {
                SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_48K);
                return 48;
            }
            
        case 0x60: // Range 3
            if(usAudioPacketNum < _AUTO_FREQ_DETECT_88K_AND_96K_TH)
            {
                SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_88_2K);
                return 88;
            }
            else
            {
                SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_96K);
                return 96;
            }        
            
        case 0x80: // Range 4
            if(usAudioPacketNum < _AUTO_FREQ_DETECT_176K_AND_192K_TH)
            {
                SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_176_4K);
                return 176;
            }
            else
            {
                SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_192K);
                return 192;
            }                

        case 0xA0: // Range 5
            SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_NO_SUPPORT);
            return 0;
        default: // Range0 and Range 5
            SET_AUDIO_SAMPLING_FREQ(_AUDIO_FREQ_NONE);
            return 0;
    }
}

//--------------------------------------------------
// Description  : Check Audio whether Audio LPCM By Audio Data
// Input Value  : ucSourceType
// Output Value : _TRUE => LPCM
//--------------------------------------------------
bit ScalerAudioLPCMCheckData(void)
{
    switch(ScalerAudioGetDigitalAudioSource())
    {
#if(_DP_SUPPORT == _ON)
        case _DIGITAL_AUDIO_SOURCE_DP:
            
            ScalerGetDataPortByte(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_90_DP_AUD_CTRL, 1, pData, _NON_AUTOINC);
            
            if((((pData[0] & _BIT5) == 0x00) && ((pData[0] & _BIT4) == 0x00)) ||
               (((pData[0] & _BIT5) == _BIT5) && ((pData[0] & _BIT4) == _BIT4)))
            {
                return _TRUE;
            }
            
            break;
#endif            

#if(_HDMI_SUPPORT == _ON)            
        case _DIGITAL_AUDIO_SOURCE_HDMI:
            
            if(ScalerGetBit(P2_CB_HDMI_SR, _BIT4) == 0x00)
            {
                return _TRUE;
            }
            
            break;
#endif

        default:
            
            break;
    }
    
    return _FALSE;
}

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check Audio whether Audio LPCM By Info Frame
// Input Value  : ucSourceType
// Output Value : _TRUE => LPCM
//--------------------------------------------------
bit ScalerAudioLPCMCheckInfo(void)
{
    ScalerGetDataPortByte(P2_CD_HDMI_PSAP, 0x15, 1, pData, _NON_AUTOINC);

    if(((pData[0] & 0xF0) == 0x00) || ((pData[0] & 0xF0) == 0x10))
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}
#endif

//--------------------------------------------------
// Description  : Timer Event to Load Stable I Code
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioLoadStableICodeEvent(void)
{
    // Set high byte of I code for boundary tracking
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_24_HDMI_ICBPSR0, HIBYTE(_STABLE_I_CODE));

    // Set low byte of I code for boundary tracking
    ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_25_HDMI_ICBPSR1, LOBYTE(_STABLE_I_CODE));

    DebugMessageAudio("Load stable I code", _STABLE_I_CODE);
}

#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Auido Speaker Testing Process
// Input Value  : Enable or Disable
// Output Value : None
//--------------------------------------------------
void ScalerAudioInternalAudioGenSwitch(bit bOn)
{
    if(bOn == _ON)
    {       
        DebugMessageAudio("Audio Test On", ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, _BIT4));
        
#if(_DP_SUPPORT == _ON)
        // Disable DP Buffer
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_90_DP_AUD_CTRL, ~_BIT7, 0x00);
#endif

        // Disable audio FIFO and Enable audio internal generator
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, ~(_BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);

        // Disbale DPLL Freq. Tuning
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_3A_HDMI_DPCR2, ~_BIT1, 0x00);
        
        // Set S1_MSB code
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_28_HDMI_NTX1024TR0, ~_BIT4, _BIT4);
        
        // Set S code
        ScalerSetDataPortByte(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_12_HDMI_SCAPR, 0x03);

        // Disable sample freq. detection and auto load S code
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, ~(_BIT7 | _BIT6), 0x00);
        
        // Enable double buffer
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~_BIT4, _BIT4);

		ScalerAudioDigitalOutputMute(_OFF);

    }
    else
    {
        DebugMessageAudio("Aduio Test Off", ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, _BIT4));

		ScalerAudioDigitalOutputMute(_ON);
        
        // Enable sample freq. detection and auto load S code
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_90_AUDIO_FREQDET, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
        
        // Enable double buffer
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_10_HDMI_CMCR, ~_BIT4, _BIT4);

        // Enable DPLL Freq. Tuning
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_3A_HDMI_DPCR2, ~_BIT1, _BIT1);
                
        // Enable audio FIFO and Disable audio internal generator
        ScalerSetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, ~(_BIT6 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT6 | _BIT2 | _BIT1));
    
#if(_DP_SUPPORT == _ON)
        // Enable DP Buffer
        ScalerSetDataPortBit(PC_B3_DP_ACCESS_PORT, _PC_B4_PT_90_DP_AUD_CTRL, ~_BIT7, _BIT7);
#endif
    }
}

//--------------------------------------------------
// Description  : Get Whether Internal Audio Pattern Gen is Enabled
// Input Value  : None
// Output Value : _ENABLE or _DISABLE
//--------------------------------------------------
bit ScalerAudioGetInternalAudioGenEnable(void)
{
    if(ScalerGetDataPortBit(P2_C9_HDMI_ADDR_PORT, _P2_CA_PT_03_HDMI_AFCR, _BIT4) == _BIT4)
    {
        return _ENABLE;
    }
    else
    {
        return _DISABLE;
    }
}

#endif // End of #if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)


#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Change Auido DAC State
// Input Value  : Target Audio DAC State
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACSetState(EnumAudioDACState enumTargetState)
{
    SET_AUDIO_DAC_STATE(enumTargetState);
    SET_AUDIO_DAC_STATE_CHANGE();
}

//--------------------------------------------------
// Description  : Get Curretn DAC State
// Input Value  : None
// Output Value : Current DAC State
//--------------------------------------------------
EnumAudioDACState ScalerAudioDACGetState(void)
{
    return GET_AUDIO_DAC_STATE();
}

//--------------------------------------------------
// Description  : Get Curretn DAC State Change
// Input Value  : None
// Output Value : TRUE => State Changed
//--------------------------------------------------
bit ScalerAudioDACGetStateChange(void)
{
    return GET_AUDIO_DAC_STATE_CHANGE();
}

//--------------------------------------------------
// Description  : Clear DAC State Change
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACClrStateChange(void)
{
    CLR_AUDIO_DAC_STATE_CHANGE();
}

//--------------------------------------------------
// Description  : When Vcm already charge to AVDD/2, Vo(Output Voltage) should charge as Vcm
// Input Value  : bReady
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACSetVcmReady(bit bReady)
{
    ScalerSetBit(P6_CB_DEPOP_CTRL4, ~_BIT1, ((BYTE) bReady << 1));
}

//--------------------------------------------------
// Description  : Transfer depop mode to Normal mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACNormalToDepop(void)
{
    ScalerAudioDACSetVcmReady(_OFF);

    // Disable driving current for HPOUT
    ScalerSetBit(P6_C9_DEPOP_CTRL1, ~_BIT7, 0x00);
        
    // Transfer normal to depop operation for AOUT
    ScalerSetBit(P6_C8_DEPOP_CTRL0, ~_BIT3, 0x00);

    // Transfer normal to depop operation for HP output
    ScalerSetBit(P6_C9_DEPOP_CTRL1, ~_BIT6, 0x00);
    
    // Disable AOUT
    ScalerSetBit(P6_B3_AOUT_CTL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    
    // Disable HP output
    ScalerSetBit(P6_B4_HPOUT_CTL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    ScalerAudioDACSetVcmReady(_ON);
    
    ScalerAudioDACSetState(_AUDIO_DAC_DEPOP);
}

//--------------------------------------------------
// Description  : Transfer depop mode to normal mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACDepopToNormal(void)
{
    // Transfer depop to normal operation for AOUT
    ScalerSetBit(P6_C8_DEPOP_CTRL0, ~_BIT3, _BIT3);

    // Transfer depop to normal operation and enable driving current for HP output
    ScalerSetBit(P6_C9_DEPOP_CTRL1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Disable Vcm ready
    ScalerAudioDACSetVcmReady(_OFF);
            
    ScalerAudioDACSetState(_AUDIO_DAC_READY); 
}

//--------------------------------------------------
// Description  : Switch AOUT/HPOUT to Normal Output
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACOutputEnable(void)
{
    ScalerAudioDACSetVcmReady(_OFF);

    // Enable AOUT
    ScalerSetBit(P6_B3_AOUT_CTL, ~(_BIT7 | _BIT6), 0x00);

    // Enable HP Output
    ScalerSetBit(P6_B4_HPOUT_CTL, ~(_BIT7 | _BIT6), 0x00);
    
    ScalerAudioDACSetVcmReady(_ON);
}

//--------------------------------------------------
// Description  : Get Current DAC Output Channel
// Input Value  : None
// Output Value : EnumAudioDACOutput
//--------------------------------------------------
EnumAudioDACOutput ScalerAudioDACGetOutput(void)
{
    if((ScalerGetBit(P6_B3_AOUT_CTL, _BIT4) == _BIT4) && (ScalerGetBit(P6_B4_HPOUT_CTL, _BIT4) == _BIT4))
    {
        return _AUDIO_DAC_OUTPUT_BOTH;
    }
    else if(ScalerGetBit(P6_B3_AOUT_CTL, _BIT4) == _BIT4)
    {
        return _AUDIO_DAC_OUTPUT_SPEAKER;
    }
    else if(ScalerGetBit(P6_B4_HPOUT_CTL, _BIT4) == _BIT4) 
    {
        return _AUDIO_DAC_OUTPUT_HEADPHONE;        
    }

    return _AUDIO_DAC_OUTPUT_NONE;    
}

//--------------------------------------------------
// Description  : Audio DAC Restart
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerAudioDACRestart(void)
{
    ScalerAudioDACOutputEnable();
    
    ScalerTimerDelayXms(120);
    
    ScalerAudioDACDepopToNormal();
}

//--------------------------------------------------
// Description  : Adjust analog volume for mute/unmute 
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void ScalerAudioAnalogVolumeMute(bit bMute, BYTE ucVolume)
{   
    if(bMute == _ON)
    {  
        // Only Switch ot Depop when in normal mode
        if(GET_AUDIO_DAC_STATE() == _AUDIO_DAC_READY)
        {
            // Transfer depop mode to Normal output
            ScalerAudioDACNormalToDepop();

            // Volume Control of AIN L
            ScalerSetByte(P6_BA_AIN_VOL_L, 0x00);

            // Volume Control of AIN R (Double buffer)
            ScalerSetByte(P6_BB_AIN_VOL_R, 0x00);
        }
    }
    else // Unmute
    {
        // AIN gain step from 0~63
        ucVolume &= 0x3F;
                
        // Volume Control of AIN L
        ScalerSetByte(P6_BA_AIN_VOL_L, ucVolume);

        // Volume Control of AIN R (Double buffer)
        ScalerSetByte(P6_BB_AIN_VOL_R, ucVolume);
        
        // Transfer depop mode to normal mode
        ScalerAudioDACRestart();        
    }
}

//--------------------------------------------------
// Description  : Adjust Analog volume
// Input Value  : bAudioSource, ucVolume
// Output Value : None
//--------------------------------------------------
void ScalerAudioAnalogAdjustVolume(WORD usVolume, bit bAudioInputType)
{
    // Volume gain step: 0~63
    usVolume &= 0x003F;

    if(bAudioInputType == _AUDIO_FROM_AIN)
    {
        // Left Channel From AIN
        ScalerSetByte(P6_BA_AIN_VOL_L, (BYTE) usVolume);

        // Right Channel From AIN (Double buffer)
        ScalerSetByte(P6_BB_AIN_VOL_R, (BYTE) usVolume);     
    }
    else // bAudioInputType == _AUDIO_FROM_DAC
    {
        // Left Channel From DAC
        ScalerSetByte(P6_B8_DAC_VOL_L, (BYTE) usVolume);

        // Right Channel From DAC (Double buffer)
        ScalerSetByte(P6_B9_DAC_VOL_R, (BYTE) usVolume);     
    }
}
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)

#endif // End of #if(_AUDIO_SUPPORT == _ON)
