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
// ID Code      : RL6269_Series_MHL.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6269_SERIES_MHL__

#include "ScalerFunctionInclude.h"

#if(_MHL_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _DDC_PACKET                             0
#define _MSC_PACKET                             2

#define _MSC_SEND_DATA                          0
#define _MSC_SEND_COMMAND                       1
#define _MSC_SEND_COM_DAT                       2
#define _MSC_SEND_COM_OFF_DAT                   3
#define _MSC_SEND_COM_OFF_DAT_COM               4
#define _MSC_SEND_COM_OFF                       5

#define _MSC_WAIT_NULL                          0
#define _MSC_WAIT_COMMAND                       1
#define _MSC_WAIT_DATA                          2
#define _MSC_WAIT_COM_DAT                       3

#define _MSC_ACK_PACKET                         0x33
#define _MSC_NACK_PACKET                        0x34
#define _MSC_ABORT_PACKET                       0x35
#define _MSC_EOF_PACKET                         0x32
#define _MSC_PROTOCOL_ERROR                     0x02

#define _MHL_3D_VIC_HB                          0x00
#define _MHL_3D_VIC_LB                          0x10
#define _MHL_3D_DTD_HB                          0x00
#define _MHL_3D_DTD_LB                          0x11

#define _MSC_NONE                               0xFF

//--------------------------------------------------
// Definitions of MHL Capability Register Required Fields
//--------------------------------------------------
typedef enum
{
    _MSC_DEV_STATE_00,
    _MSC_MHL_VERSION_01,
    _MSC_DEV_CAT_02,
    _MSC_ADOPTER_ID_H_03,
    _MSC_ADOPTER_ID_L_04,
    _MSC_VID_LINK_MODE_05,
    _MSC_AUD_LINK_MODE_06,
    _MSC_VIDEO_TYPE_07,
    _MSC_LOG_DEV_MAP_08,
    _MSC_BANDWIDTH_09,
    _MSC_FEATURE_FLAG_0A,
    _MSC_DEVICE_ID_H_0B,
    _MSC_DEVICE_ID_L_0C,
    _MSC_SCRATCHPAD_SIZE_0D,
    _MSC_INT_STAT_SIZE_0E,
} EnumMHLMscCapRegField;

//--------------------------------------------------
// Definitions of MHL RAP SubCommands
//--------------------------------------------------
typedef enum
{
    _MSC_RAP_NO_ERROR = 0x00,
    _MSC_RAP_UNRECOGNIZE_CODE,
    _MSC_RAP_UNSUPPORT_CODE,
    _MSC_RAP_RESPONDER_BUSY,
} EnumMHLMscRAPErrorCode;

//--------------------------------------------------
// Macros of MHL Adopter ID
//--------------------------------------------------
#if(_MHL_SUPPORT == _ON)
#define GET_D0_MHL_ADOPTER_ID_DONE()            (g_bD0MHLAdopterIDDone)
#define SET_D0_MHL_ADOPTER_ID_DONE()            (g_bD0MHLAdopterIDDone = _TRUE)
#define CLR_D0_MHL_ADOPTER_ID_DONE()            (g_bD0MHLAdopterIDDone = _FALSE)

#define GET_D0_MHL_CBUS_RESET_FOR_HTC_DONE()    (g_bD0MHLCbusResetForHTCDone)
#define SET_D0_MHL_CBUS_RESET_FOR_HTC_DONE()    (g_bD0MHLCbusResetForHTCDone = _TRUE)
#define CLR_D0_MHL_CBUS_RESET_FOR_HTC_DONE()    (g_bD0MHLCbusResetForHTCDone = _FALSE)

#define GET_D1_MHL_ADOPTER_ID_DONE()            (g_bD1MHLAdopterIDDone)
#define SET_D1_MHL_ADOPTER_ID_DONE()            (g_bD1MHLAdopterIDDone = _TRUE)
#define CLR_D1_MHL_ADOPTER_ID_DONE()            (g_bD1MHLAdopterIDDone = _FALSE)

#define GET_D1_MHL_CBUS_RESET_FOR_HTC_DONE()    (g_bD1MHLCbusResetForHTCDone)
#define SET_D1_MHL_CBUS_RESET_FOR_HTC_DONE()    (g_bD1MHLCbusResetForHTCDone = _TRUE)
#define CLR_D1_MHL_CBUS_RESET_FOR_HTC_DONE()    (g_bD1MHLCbusResetForHTCDone = _FALSE)

#define GET_MHL_RX0_MHL_VERSION()                (g_ucMHLRx0MhlVersion)
#define SET_MHL_RX0_MHL_VERSION(x)               (g_ucMHLRx0MhlVersion = (x))
#define CLR_MHL_RX0_MHL_VERSION()                (g_ucMHLRx0MhlVersion = 0x00)

#define GET_MHL_RX1_MHL_VERSION()                (g_ucMHLRx1MhlVersion)
#define SET_MHL_RX1_MHL_VERSION(x)               (g_ucMHLRx1MhlVersion = (x))
#define CLR_MHL_RX1_MHL_VERSION()                (g_ucMHLRx1MhlVersion = 0x00)
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_MHL_SUPPORT == _ON)
BYTE g_ucD0MHLAdopterIDH = 0;
BYTE g_ucD0MHLAdopterIDL = 0;
bit g_bD0MHLAdopterIDDone = _FALSE;
bit g_bD0MHLCbusResetForHTCDone = _FALSE;
BYTE g_ucMHLRx0MhlVersion = 0x00;

BYTE g_ucD1MHLAdopterIDH = 0;
BYTE g_ucD1MHLAdopterIDL = 0;
bit g_bD1MHLAdopterIDDone = _FALSE;
bit g_bD1MHLCbusResetForHTCDone = _FALSE;
BYTE g_ucMHLRx1MhlVersion = 0x00;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerMHLModeMHLSetting(BYTE ucInputPort);
void ScalerMHLModeHdmiSetting(BYTE ucInputPort);
void ScalerMHLCBUSPhySwitch(BYTE ucPortSelect, bit bSelect);
void ScalerMHLCBUSSwitchClk(EnumClkSel enumClockSel);
void ScalerMHLCBUSResetProc(BYTE ucInputPort);
void ScalerMHLInitialSettings(void);
void ScalerMHLPowerOffProc(void);
BYTE ScalerMHLDetectClkMode_EXINT0(void);
void ScalerMHLIntHandler_EXINT0(void);
bit ScalerMHLMscSendCommand(BYTE ucInputPort, EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue);
bit ScalerMHLMscSendWriteBurst(BYTE ucInputPort, BYTE ucOffset, BYTE ucDataLength, BYTE *pucData, EnumMHLWriteBurstMode enumMode);
bit ScalerMHLMscReadDevCapabilities(BYTE ucInputPort, EnumMHLMscCapRegField enumMSCOffset, BYTE *pucData);
BYTE ScalerMHLMscFIFOSendCommand(BYTE ucInputPort, EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue, BYTE ucDataLength, BYTE *pucData);
void ScalerMHLMscCheckDeviceINT(BYTE ucInputPort);
bit ScalerMHLMscHandler(BYTE ucInputPort, BYTE ucActivePort, BYTE ucModeState);
bit ScalerMHLMscRAPHandler(BYTE ucInputPort);
bit ScalerMHLMscRCPGetCommand(BYTE ucInputPort, BYTE *pucKeyCode);

#if(_MHL_UCP_SUPPORT == _ON)
bit ScalerMHLMscUCPGetCommand(BYTE ucInputPort, BYTE *pucKeyCode);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : TMDS Settings when MHL Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLModeMHLSetting(BYTE ucInputPort)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
    
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)    
        CLR_D0_MHL_CBUS_RESET_FOR_HTC_DONE(); 
#endif

        SET_D0_TMDS_SWITCH(_TMDS_SWITCH_CBUS);
        SET_D0_MHL_VBUS_SWITCH(_MHL_VBUS_ON);

        // Port 0 Z0 Disable
        ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        // GPIO Select to CBUS
        ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, 0x00);
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        // GPIO Select to CBUS
        ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, 0x00);
#endif

#if(_D0_DDC_CHANNEL_SEL == _DDC2)
        // Disable DDC Channel
        ScalerSetBit(P10_DF_PIN_SHARE_CTRL3F, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), _BIT7);   

        // Switch DDC Channel To CBUS
        ScalerSetBit(P10_FB_PIN_CBUS_PIN_SELECT, ~(_BIT1 | _BIT0), _BIT0);

        // DDC2 Input Source
        MCU_DDC1_CTRL_DATA_FFB4 &= ~(_BIT1 | _BIT0);
        MCU_DDC1_CTRL_DATA_FFB4 |= _BIT1;

        // DDC2 Disable Force Nack and disable DDC Toggle IRQ
        MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT5 | _BIT3 | _BIT1);
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
        // Disable DDC Channel
        ScalerSetBit(P10_DD_PIN_SHARE_CTRL3D, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), _BIT7);

        // Switch DDC Channel To CBUS
        ScalerSetBit(P10_FB_PIN_CBUS_PIN_SELECT, ~(_BIT3 | _BIT2), _BIT2);

        // DDC3 Input Source
        MCU_DDC2_CTRL_DATA_FFB5 &= ~(_BIT1 | _BIT0);
        MCU_DDC2_CTRL_DATA_FFB5 |= _BIT1;

        // DDC3 Disable Force Nack and disable DDC Toggle IRQ
        MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT5 | _BIT3 | _BIT1);
#endif

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)      
        CLR_D1_MHL_CBUS_RESET_FOR_HTC_DONE(); 
#endif

        SET_D1_TMDS_SWITCH(_TMDS_SWITCH_CBUS);
        SET_D1_MHL_VBUS_SWITCH(_MHL_VBUS_ON);

        // Port 1 Z0 Disable
        ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
  
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        // GPIO Select to CBUS
        ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, 0x00);
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        // GPIO Select to CBUS
        ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, 0x00);
#endif

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
        // Disable DDC Channel
        ScalerSetBit(P10_DF_PIN_SHARE_CTRL3F, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), _BIT7);    

        // Switch DDC Channel To CBUS
        ScalerSetBit(P10_FB_PIN_CBUS_PIN_SELECT, ~(_BIT1 | _BIT0), _BIT0);

        // DDC2 Input Source
        MCU_DDC1_CTRL_DATA_FFB4 &= ~(_BIT1 | _BIT0);
        MCU_DDC1_CTRL_DATA_FFB4 |= _BIT1;

        // DDC2 Disable Force Nack and disable DDC Toggle IRQ
        MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT5 | _BIT3 | _BIT1);
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
        // Disable DDC Channel
        ScalerSetBit(P10_DD_PIN_SHARE_CTRL3D, ~(_BIT7 | _BIT2 | _BIT1 | _BIT0), _BIT7);

        // Switch DDC Channel To CBUS
        ScalerSetBit(P10_FB_PIN_CBUS_PIN_SELECT, ~(_BIT3 | _BIT2), _BIT2);

        // DDC3 Input Source
        MCU_DDC2_CTRL_DATA_FFB5 &= ~(_BIT1 | _BIT0);
        MCU_DDC2_CTRL_DATA_FFB5 |= _BIT1;

        // DDC3 Disable Force Nack and disable DDC Toggle IRQ
        MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT5 | _BIT3 | _BIT1);
#endif

    }
}

//--------------------------------------------------
// Description  : TMDS Settings when HDMI Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLModeHdmiSetting(BYTE ucInputPort)
{
    ScalerMHLCBUSPhySwitch(ucInputPort, _OFF);

    // Disable HDCP Ri IRQ
    ScalerSetBit(P2_AA_TMDS_ABC, ~_BIT3, 0x00);
    
    if(ucInputPort == _D0_INPUT_PORT)
    {
        SET_D0_TMDS_SWITCH(_TMDS_SWITCH_HPD);
        SET_D0_MHL_VBUS_SWITCH(_MHL_VBUS_OFF);

#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        // GPIO Select to Hot Plug
        ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, _BIT4);
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        // GPIO Select to Hot Plug
        ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, _BIT5);
#endif

#if(_D0_DDC_CHANNEL_SEL == _DDC2)
        // Enable DDC Channel
        ScalerSetBit(P10_DF_PIN_SHARE_CTRL3F, ~_BIT7, 0x00);        

        // Switch DDC Channel To HDMI DDC
        ScalerSetBit(P10_FB_PIN_CBUS_PIN_SELECT, ~(_BIT1 | _BIT0), 0x00);

#if(_EMBEDDED_DDCRAM_D0_SIZE == _EDID_SIZE_NONE)
        // DDC2 Enable Force Nack
        MCU_DVI_EDID_IRQ_FFE4 |= _BIT5;
#else
        // DDC2 Input Source
        MCU_DDC1_CTRL_DATA_FFB4 &= ~(_BIT1 | _BIT0);
        MCU_DDC1_CTRL_DATA_FFB4 |= _BIT0;
#endif

#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
        // Enable DDC Channel
        ScalerSetBit(P10_DD_PIN_SHARE_CTRL3D, ~_BIT7, 0x00);

        // Switch DDC Channel To HDMI DDC
        ScalerSetBit(P10_FB_PIN_CBUS_PIN_SELECT, ~(_BIT3 | _BIT2), 0x00);

#if(_EMBEDDED_DDCRAM_D0_SIZE == _EDID_SIZE_NONE)
        // DDC3 Enable Force Nack
        MCU_HDMI_EDID_IRQ_FFE5 |= _BIT5;
#else
        // DDC3 Input Source
        MCU_DDC2_CTRL_DATA_FFB5 &= ~(_BIT1 | _BIT0);
#endif

#endif  // End of #if(_D0_DDC_CHANNEL_SEL == _DDC2)

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        SET_D1_TMDS_SWITCH(_TMDS_SWITCH_HPD);
        SET_D1_MHL_VBUS_SWITCH(_MHL_VBUS_OFF);
        
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        // GPIO Select to Hot Plug
        ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, _BIT4);
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        // GPIO Select to Hot Plug
        ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, _BIT5);
#endif

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
        // Enable DDC Channel
        ScalerSetBit(P10_DF_PIN_SHARE_CTRL3F, ~_BIT7, 0x00);

        // Switch DDC Channel To HDMI DDC
        ScalerSetBit(P10_FB_PIN_CBUS_PIN_SELECT, ~(_BIT1 | _BIT0), 0x00);

#if(_EMBEDDED_DDCRAM_D1_SIZE == _EDID_SIZE_NONE)        
        // DDC2 Enable Force Nack
        MCU_DVI_EDID_IRQ_FFE4 |= _BIT5;
#else
        // DDC2 Input Source
        MCU_DDC1_CTRL_DATA_FFB4 &= ~(_BIT1 | _BIT0);
        MCU_DDC1_CTRL_DATA_FFB4 |= _BIT0;
#endif

#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
        // Enable DDC Channel
        ScalerSetBit(P10_DD_PIN_SHARE_CTRL3D, ~_BIT7, 0x00);

        // Switch DDC Channel To HDMI DDC
        ScalerSetBit(P10_FB_PIN_CBUS_PIN_SELECT, ~(_BIT3 | _BIT2), 0x00);

#if(_EMBEDDED_DDCRAM_D1_SIZE == _EDID_SIZE_NONE)
        // DDC3 Enable Force Nack
        MCU_HDMI_EDID_IRQ_FFE5 |= _BIT5;
#else
        // DDC3 Input Source
        MCU_DDC2_CTRL_DATA_FFB5 &= ~(_BIT1 | _BIT0);
#endif

#endif  // End of #if(_D1_DDC_CHANNEL_SEL == _DDC2)

    }
}

//--------------------------------------------------
// Description  : Calibration for 1K/100K and LDO Level Adjust
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLInitialSettings(void)
{    
    // Disable CBUS LDO and Input Comparator
    ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Disable Output Driver
    ScalerSetBit(P27_A1_RES_AUTOK_1, ~(_BIT7 | _BIT6), 0x00);
    
    // Manual Calibration for 1K & 100K
    ScalerSetBit(P27_A2_RES_AUTOK_2, ~(_BIT7 | _BIT6), 0x00);

    // Adjust CBUS Input Comparator VIH = 0.9V and VIL = 0.7V
    ScalerSetByte(P27_A4_INPUT_CONTROL, 0x88);

    // Set CBUS Max Driving Strength
    ScalerSetBit(P27_A6_OUTPUT_CONTROL_2, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT4 | _BIT3));

    // Discovery Function Power Down and System Clk Gated
    ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT6 | _BIT5 | _BIT3 | _BIT2), _BIT6);
    ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT6 | _BIT5 | _BIT3 | _BIT2), _BIT6);

    // Set MHL 1MHz Clk Divider
    ScalerSetBit(P28_A1_CBUS0_CTRL_01, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | _BIT3 | _BIT2));
    ScalerSetBit(P29_A1_CBUS1_CTRL_01, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | _BIT3 | _BIT2));

    // Set MHL 1KHz Clk Divider and Set Stuck Low Time to 150us
    ScalerSetBit(P28_A2_CBUS0_CTRL_02, ~(_BIT4 | _BIT3 | _BIT1 | _BIT0), _BIT0);
    ScalerSetByte(P28_A3_CBUS0_CTRL_03, 0xE2);
    ScalerSetBit(P29_A2_CBUS1_CTRL_02, ~(_BIT4 | _BIT3 | _BIT1 | _BIT0), _BIT0);
    ScalerSetByte(P29_A3_CBUS1_CTRL_03, 0xE2);

    // Set Discovery Upper/Lower Bound
    ScalerSetBit(P28_A5_CBUS0_CTRL_05, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x5A);
    ScalerSetBit(P29_A5_CBUS1_CTRL_05, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x5A);

    // Set Wake Up Pulse Number to 0
    ScalerSetBit(P28_A6_CBUS0_CTRL_06, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
    ScalerSetBit(P29_A6_CBUS1_CTRL_06, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
}

//--------------------------------------------------
// Description  : Power Process for CBUS Phy
// Input Value  : bPortSelect --> _D0_INPUT_PORT / _D1_INPUT_PORT
//                bSelect --> _ON/_OFF
// Output Value : None
//--------------------------------------------------
void ScalerMHLCBUSPhySwitch(BYTE ucPortSelect, bit bSelect)
{
    if(ucPortSelect == _D0_INPUT_PORT)
    {
        if(bSelect == _ON)
        {
            
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
            if(ScalerGetBit(P28_A8_CBUS0_CTRL_08, _BIT5) == 0x00)
            {
                // GPIO Select to CBUS
                ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, 0x00);

                // Enable CBUS Phy, LDO and Input Comparator
                ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT6 | _BIT2 | _BIT0), (_BIT6 | _BIT2 | _BIT0));

                // Enable Output Driver
                ScalerSetBit(P27_A1_RES_AUTOK_1, ~_BIT6, _BIT6);

                // Discovery Function Power On and Enable System Clk
                // Enable Discovery IRQ
                ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT6 | _BIT5 | _BIT0), (_BIT5 | _BIT0));

                // MHL Attached
                ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT5, _BIT5);

                EX0 = 1;
            }
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
            if(ScalerGetBit(P29_A8_CBUS1_CTRL_08, _BIT5) == 0x00)
            {
                // GPIO Select to CBUS
                ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, 0x00);

                // Enable CBUS Phy, LDO and Input Comparator
                ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT7 | _BIT3 | _BIT1), (_BIT7 | _BIT3 | _BIT1));

                // Enable Output Driver
                ScalerSetBit(P27_A1_RES_AUTOK_1, ~_BIT7, _BIT7);

                // Discovery Function Power On and Enable System Clk
                // Enable Discovery IRQ
                ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT6 | _BIT5 | _BIT0), (_BIT5 | _BIT0));

                // MHL Attached
                ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT5, _BIT5);

                EX0 = 1;
            }
#endif                        

        }
        else
        {
            
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
            if(ScalerGetBit(P28_A8_CBUS0_CTRL_08, _BIT5) == _BIT5)
            {
                // Disable CBUS Phy, LDO, Input Comparator
                ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT6 | _BIT2 | _BIT0), 0x00);

                // Disable Output Driver
                ScalerSetBit(P27_A1_RES_AUTOK_1, ~_BIT6, 0x00);

                // Discovery Function Power Down and System Clk Gated
                // Disable Discovery IRQ
                ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT6 | _BIT5 | _BIT0), _BIT6);

                // MHL Unattached
                ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT5, 0x00);
            }
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
            if(ScalerGetBit(P29_A8_CBUS1_CTRL_08, _BIT5) == _BIT5)
            {
                // Disable CBUS Phy, LDO, Input Comparator
                ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT7 | _BIT3 | _BIT1), 0x00);

                // Disable Output Driver
                ScalerSetBit(P27_A1_RES_AUTOK_1, ~_BIT7, 0x00);

                // Discovery Function Power Down and System Clk Gated
                // Disable Discovery IRQ
                ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT6 | _BIT5 | _BIT0), _BIT6);

                // MHL Unattached
                ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT5, 0x00);
            }
#endif   

        }
    }
    else if(ucPortSelect == _D1_INPUT_PORT)
    {
        if(bSelect == _ON)
        {
            
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
            if(ScalerGetBit(P28_A8_CBUS0_CTRL_08, _BIT5) == 0x00)
            {
                // GPIO Select to CBUS
                ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, 0x00);

                // Enable CBUS Phy, LDO and Input Comparator
                ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT6 | _BIT2 | _BIT0), (_BIT6 | _BIT2 | _BIT0));

                // Enable Output Driver
                ScalerSetBit(P27_A1_RES_AUTOK_1, ~_BIT6, _BIT6);

                // Discovery Function Power On and Enable System Clk
                // Enable Discovery IRQ
                ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT6 | _BIT5 | _BIT0), (_BIT5 | _BIT0));

                // MHL Attached
                ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT5, _BIT5);

                EX0 = 1;
            }
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
            if(ScalerGetBit(P29_A8_CBUS1_CTRL_08, _BIT5) == 0x00)
            {
                // GPIO Select to CBUS
                ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, 0x00);

                // Enable CBUS Phy, LDO and Input Comparator
                ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT7 | _BIT3 | _BIT1), (_BIT7 | _BIT3 | _BIT1));

                // Enable Output Driver
                ScalerSetBit(P27_A1_RES_AUTOK_1, ~_BIT7, _BIT7);

                // Discovery Function Power On and Enable System Clk
                // Enable Discovery IRQ
                ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT6 | _BIT5 | _BIT0), (_BIT5 | _BIT0));

                // MHL Attached
                ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT5, _BIT5);

                EX0 = 1;
            }
#endif                        

        }
        else
        {
            
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
            if(ScalerGetBit(P28_A8_CBUS0_CTRL_08, _BIT5) == _BIT5)
            {
                // Disable CBUS Phy, LDO, Input Comparator
                ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT6 | _BIT2 | _BIT0), 0x00);

                // Disable Output Driver
                ScalerSetBit(P27_A1_RES_AUTOK_1, ~_BIT6, 0x00);

                // Discovery Function Power Down and System Clk Gated
                // Disable Discovery IRQ
                ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT6 | _BIT5 | _BIT0), _BIT6);

                // MHL Unattached
                ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT5, 0x00);
            }
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
            if(ScalerGetBit(P29_A8_CBUS1_CTRL_08, _BIT5) == _BIT5)
            {
                // Disable CBUS Phy, LDO, Input Comparator
                ScalerSetBit(P27_A0_CBUS_EN, ~(_BIT7 | _BIT3 | _BIT1), 0x00);

                // Disable Output Driver
                ScalerSetBit(P27_A1_RES_AUTOK_1, ~_BIT7, 0x00);

                // Discovery Function Power Down and System Clk Gated
                // Disable Discovery IRQ
                ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT6 | _BIT5 | _BIT0), _BIT6);

                // MHL Unattached
                ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT5, 0x00);
            }
#endif   

        }
    }
}

//--------------------------------------------------
// Description  : Clock Select For MHL
// Input Value  : ucClockSel --> System refernce clock select.
// Output Value : None
//--------------------------------------------------
void ScalerMHLCBUSSwitchClk(EnumClkSel enumClockSel)
{
    if(enumClockSel == _M2PLL_CLK)
    {
        // MHL System Clk select to M2PLL
        ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT4 | _BIT3 | _BIT2), 0x00);
        ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT4 | _BIT3 | _BIT2), 0x00);

        // Sys Clk Divider
        ScalerSetBit(P28_A1_CBUS0_CTRL_01, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);
        ScalerSetBit(P29_A1_CBUS1_CTRL_01, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

        // Set Debounce For Core Function Set to 2 cycles
        ScalerSetBit(P28_A2_CBUS0_CTRL_02, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);
        ScalerSetBit(P29_A2_CBUS1_CTRL_02, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

        // Upper Bound of SYNC Pulse Low Time Period
        ScalerSetByte(P28_AF_CBUS0_CTRL_0F, 0xEA);
        ScalerSetByte(P29_AF_CBUS1_CTRL_0F, 0xEA);

        // Lower Bound of SYNC Pulse Low Time Period
        ScalerSetByte(P28_B0_CBUS0_CTRL_10, 0x88);
        ScalerSetByte(P29_B0_CBUS1_CTRL_10, 0x88);

        // Upper Bound of SYNC Pulse High Time Period
        ScalerSetByte(P28_B1_CBUS0_CTRL_11, 0x58);
        ScalerSetByte(P29_B1_CBUS1_CTRL_11, 0x58);

        // Lower Bound of SYNC Pulse High Time Period
        ScalerSetByte(P28_B2_CBUS0_CTRL_12, 0x26);
        ScalerSetByte(P29_B2_CBUS1_CTRL_12, 0x26);
        
        // Absolute Threshold Time
        ScalerSetByte(P28_B4_CBUS0_CTRL_14, 0x5D);
        ScalerSetByte(P29_B4_CBUS1_CTRL_14, 0x5D);

        // Parity Bit Time
        ScalerSetByte(P28_B5_CBUS0_CTRL_15, 0x79);
        ScalerSetByte(P29_B5_CBUS1_CTRL_15, 0x79);

        // Parity Error Limit
        ScalerSetBit(P28_B6_CBUS0_CTRL_16, ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);
        ScalerSetBit(P29_B6_CBUS1_CTRL_16, ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);

        // Ack Bit Initial Falling Edge
        ScalerSetBit(P28_B7_CBUS0_CTRL_17, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);
        ScalerSetBit(P29_B7_CBUS1_CTRL_17, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0F);

        // Ack Bit Drive Low Time
        ScalerSetBit(P28_B8_CBUS0_CTRL_18, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x3C);
        ScalerSetBit(P29_B8_CBUS1_CTRL_18, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x3C);

        // Requester Bit Time
        ScalerSetByte(P28_BA_CBUS0_CTRL_1A, 0x80);
        ScalerSetByte(P29_BA_CBUS1_CTRL_1A, 0x80);

        // Check Received Ack Bit's Falling Edge
        ScalerSetBit(P28_BC_CBUS0_CTRL_1C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x7F);
        ScalerSetBit(P29_BC_CBUS1_CTRL_1C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x7F);

        // Check Received Ack Bit's Driving Low Period Upper Bound
        ScalerSetBit(P28_BD_CBUS0_CTRL_1D, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x4F);
        ScalerSetBit(P29_BD_CBUS1_CTRL_1D, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x4F);

        // Check Received Ack Bit's Driving Low Period Lower Bound
        ScalerSetBit(P28_BE_CBUS0_CTRL_1E, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x25);
        ScalerSetBit(P29_BE_CBUS1_CTRL_1E, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x25);

        // Actively Driving High Time for CBUS
        ScalerSetBit(P28_C0_CBUS0_CTRL_20, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x19);
        ScalerSetBit(P29_C0_CBUS1_CTRL_20, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x19);

        // CBUS Requester Transmit Opportunity after Arbitration
        ScalerSetByte(P28_C2_CBUS0_CTRL_22, 0x79);
        ScalerSetByte(P29_C2_CBUS1_CTRL_22, 0x79);

        // CBUS Requester Continue After Ack
        ScalerSetByte(P28_C3_CBUS0_CTRL_23, 0x3C);
        ScalerSetByte(P29_C3_CBUS1_CTRL_23, 0x3C);

        // Link Layer Timeout
        ScalerSetBit(P28_C5_CBUS0_CTRL_25, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | _BIT3 | _BIT2));
        ScalerSetBit(P29_C5_CBUS1_CTRL_25, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | _BIT3 | _BIT2));

        // Set IIC SCL Clock Frequency
        ScalerSetByte(P28_F9_CBUS0_CTRL_59, 0x12);
        ScalerSetByte(P29_F9_CBUS1_CTRL_59, 0x12); 
    }
    else
    {
        // MHL System Clk select to IOSC
        ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT4 | _BIT3 | _BIT2), _BIT4);
        ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT4 | _BIT3 | _BIT2), _BIT4);

        // Sys Clk Divider
        ScalerSetBit(P28_A1_CBUS0_CTRL_01, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
        ScalerSetBit(P29_A1_CBUS1_CTRL_01, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

        // Disable Debounce For Core Function
        ScalerSetBit(P28_A2_CBUS0_CTRL_02, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
        ScalerSetBit(P29_A2_CBUS1_CTRL_02, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

        // Upper Bound of SYNC Pulse Low Time Period
        ScalerSetByte(P28_AF_CBUS0_CTRL_0F, 0x33);
        ScalerSetByte(P29_AF_CBUS1_CTRL_0F, 0x33);

        // Lower Bound of SYNC Pulse Low Time Period
        ScalerSetByte(P28_B0_CBUS0_CTRL_10, 0x1F);
        ScalerSetByte(P29_B0_CBUS1_CTRL_10, 0x1F);

        // Upper Bound of SYNC Pulse High Time Period
        ScalerSetByte(P28_B1_CBUS0_CTRL_11, 0x13);
        ScalerSetByte(P29_B1_CBUS1_CTRL_11, 0x13);

        // Lower Bound of SYNC Pulse High Time Period
        ScalerSetByte(P28_B2_CBUS0_CTRL_12, 0x09);
        ScalerSetByte(P29_B2_CBUS1_CTRL_12, 0x09);
        
        // Absolute Threshold Time
        ScalerSetByte(P28_B4_CBUS0_CTRL_14, 0x15);
        ScalerSetByte(P29_B4_CBUS1_CTRL_14, 0x15);

        // Parity Bit Time
        ScalerSetByte(P28_B5_CBUS0_CTRL_15, 0x1C);
        ScalerSetByte(P29_B5_CBUS1_CTRL_15, 0x1C);

        // Parity Error Limit
        ScalerSetBit(P28_B6_CBUS0_CTRL_16, ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);
        ScalerSetBit(P29_B6_CBUS1_CTRL_16, ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);

        // Ack Bit Initial Falling Edge
        ScalerSetBit(P28_B7_CBUS0_CTRL_17, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x03);
        ScalerSetBit(P29_B7_CBUS1_CTRL_17, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x03);

        // Ack Bit Drive Low Time
        ScalerSetBit(P28_B8_CBUS0_CTRL_18, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0C);
        ScalerSetBit(P29_B8_CBUS1_CTRL_18, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0C);

        // Requester Bit Time
        ScalerSetByte(P28_BA_CBUS0_CTRL_1A, 0x1C);
        ScalerSetByte(P29_BA_CBUS1_CTRL_1A, 0x1C);

        // Check Received Ack Bit's Falling Edge
        ScalerSetBit(P28_BC_CBUS0_CTRL_1C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x1C);
        ScalerSetBit(P29_BC_CBUS1_CTRL_1C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x1C);

        // Check Received Ack Bit's Driving Low Period Upper Bound
        ScalerSetBit(P28_BD_CBUS0_CTRL_1D, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x11);
        ScalerSetBit(P29_BD_CBUS1_CTRL_1D, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x11);

        // Check Received Ack Bit's Driving Low Period Lower Bound
        ScalerSetBit(P28_BE_CBUS0_CTRL_1E, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x05);
        ScalerSetBit(P29_BE_CBUS1_CTRL_1E, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x05);

        // Actively Driving High Time for CBUS
        ScalerSetBit(P28_C0_CBUS0_CTRL_20, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
        ScalerSetBit(P29_C0_CBUS1_CTRL_20, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

        // CBUS Requester Transmit Opportunity after Arbitration
        ScalerSetByte(P28_C2_CBUS0_CTRL_22, 0x1B);
        ScalerSetByte(P29_C2_CBUS1_CTRL_22, 0x1B);

        // CBUS Requester Continue After Ack
        ScalerSetByte(P28_C3_CBUS0_CTRL_23, 0x0D);
        ScalerSetByte(P29_C3_CBUS1_CTRL_23, 0x0D);

        // Link Layer Timeout
        ScalerSetBit(P28_C5_CBUS0_CTRL_25, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT2 | _BIT1));
        ScalerSetBit(P29_C5_CBUS1_CTRL_25, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

        // Set IIC SCL Clock Frequency
        ScalerSetByte(P28_F9_CBUS0_CTRL_59, 0x03);
        ScalerSetByte(P29_F9_CBUS1_CTRL_59, 0x03); 
    }
}

//--------------------------------------------------
// Description  : MHL Cbus Reset Proc
// Input Value  : ucInputPort --> Input Port
// Output Value : None
//--------------------------------------------------
void ScalerMHLCBUSResetProc(BYTE ucInputPort)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        if(((GET_D0_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_SII_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_SII_ADOPTER_ID_LBYTE)))
        {
            // GPIO Select to Hot Plug
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
            ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, _BIT4);
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
            ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, _BIT5);
#endif

            SET_D0_MHL_VBUS_SWITCH(_MHL_VBUS_OFF);
            ScalerTimerActiveTimerEvent(SEC(0.5), _SCALER_TIMER_EVENT_MHL_D0_ACTIVE_VBUS);
        }

        // Port 0 Z0 Disable
        ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        // Force CBUS Floating
        ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT7, _BIT7);

        // Enable Discovery Debounce
        ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Reset CBUS Core Function
        ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT7), 0x00);

        // Clear Stuck Low Flags and IRQ
        ScalerSetBit(P28_A4_CBUS0_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        // Force CBUS Floating
        ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT7, _BIT7);

        // Enable Discovery Debounce
        ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Reset CBUS Core Function
        ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT7), 0x00);

        // Clear Stuck Low Flags and IRQ
        ScalerSetBit(P29_A4_CBUS1_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);
#endif

        SET_MHL_PROCESS_STATE(0, _MHL_STATE_INITIAL);
        CLR_D0_MHL_ADOPTER_ID_HBYTE();
        CLR_D0_MHL_ADOPTER_ID_LBYTE();
        CLR_D0_MHL_ADOPTER_ID_DONE();
        CLR_D0_MHL_CBUS_RESET_FOR_HTC_DONE();   
        CLR_MHL_RX0_MHL_VERSION();
#endif

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
        if(((GET_D1_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_SII_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_SII_ADOPTER_ID_LBYTE)))
        {
            // GPIO Select to Hot Plug
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
            ScalerSetBit(P27_A0_CBUS_EN, ~_BIT4, _BIT4);
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
            ScalerSetBit(P27_A0_CBUS_EN, ~_BIT5, _BIT5);
#endif
            
            SET_D1_MHL_VBUS_SWITCH(_MHL_VBUS_OFF);
            ScalerTimerActiveTimerEvent(SEC(0.5), _SCALER_TIMER_EVENT_MHL_D1_ACTIVE_VBUS);
        }

        // Port 1 Z0 Disable
        ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        // Force CBUS Floating
        ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~_BIT7, _BIT7);

        // Enable Discovery Debounce
        ScalerSetBit(P28_A8_CBUS0_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Reset CBUS Core Function
        ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit(P28_A0_CBUS0_CTRL_00, ~(_BIT7), 0x00);

        // Clear Stuck Low Flags and IRQ
        ScalerSetBit(P28_A4_CBUS0_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        // Force CBUS Floating
        ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~_BIT7, _BIT7);

        // Enable Discovery Debounce
        ScalerSetBit(P29_A8_CBUS1_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Reset CBUS Core Function
        ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit(P29_A0_CBUS1_CTRL_00, ~(_BIT7), 0x00);

        // Clear Stuck Low Flags and IRQ
        ScalerSetBit(P29_A4_CBUS1_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        SET_MHL_PROCESS_STATE(1, _MHL_STATE_INITIAL);
#else
        SET_MHL_PROCESS_STATE(0, _MHL_STATE_INITIAL);
#endif

        CLR_D1_MHL_ADOPTER_ID_HBYTE();
        CLR_D1_MHL_ADOPTER_ID_LBYTE();
        CLR_D1_MHL_ADOPTER_ID_DONE();
        CLR_D1_MHL_CBUS_RESET_FOR_HTC_DONE();   
        CLR_MHL_RX1_MHL_VERSION();
#endif

    }
    
    MCU_IRQ_STATUS_FF00 &= ~_BIT5;
}

//--------------------------------------------------
// Description  : MHL Power Off Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLPowerOffProc(void)
{
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_D0_READY_TO_TRANSMIT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_D0_RECONNECT_1K);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_D1_READY_TO_TRANSMIT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_D1_RECONNECT_1K);
}

//--------------------------------------------------
// Description  : MHL Detect Clk Mode if 24Bit or PP Mode
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
BYTE ScalerMHLDetectClkMode_EXINT0(void) using 1
{
    WORD usTemp = 250;
    
    // Clear Error Flag and Start Detection
    ScalerSetBit_EXINT0(P26_B3_MHL_CTRL_13, ~(_BIT1 | _BIT0), _BIT0);
    ScalerSetBit_EXINT0(P26_A7_MHL_CTRL_07, ~_BIT0, _BIT0);

    // Wait until detection is done(1ms) or timeout(1.5ms)
    while((ScalerGetBit_EXINT0(P26_A7_MHL_CTRL_07, _BIT0) == _TRUE) && (--usTemp))
    {
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }

    if(((bit)ScalerGetBit_EXINT0(P26_B3_MHL_CTRL_13, _BIT0) == _TRUE) || \
       ((bit)ScalerGetBit_EXINT0(P26_A7_MHL_CTRL_07, _BIT7) != GET_TMDS_CLK_MODE()))
    {
        ScalerSetBit_EXINT0(P26_B3_MHL_CTRL_13, ~(_BIT1 | _BIT0), _BIT0);

        if(GET_TMDS_CLK_MODE() == _TMDS_24BIT_PHY_SETTING)
        {
            usTemp = 500;
            
            // Wait until RGB detection is done or timeout(3ms)
            while((ScalerGetBit_EXINT0(P2_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) != (_BIT7 | _BIT6 | _BIT5)) && \
                   (--usTemp))
            {
                _nop_();
                _nop_();
                _nop_();
                _nop_();
            }

            if(usTemp == 0)
            {
                return _FALSE;
            }
            else
            {
                return _TRUE;
            }
        }
        else
        {
            return _FALSE;
        }
    }
    else
    {
        return _TRUE;
    }
}

//--------------------------------------------------
// Description  : Int Process for MHL
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLIntHandler_EXINT0(void) using 1
{
    // Check Discovery Pulse
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
    if(ScalerGetBit_EXINT0(P28_A0_CBUS0_CTRL_00, (_BIT2 | _BIT0)) == (_BIT2 | _BIT0))
    {
        // Clear Wake Up and Discovery Flags
        ScalerSetBit_EXINT0(P28_A0_CBUS0_CTRL_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

        MCU_IRQ_STATUS_FF00 &= ~_BIT5;

        // Disable Discovery Debounce
        ScalerSetBit_EXINT0(P28_A8_CBUS0_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        // Enable Stuck Low IRQ and Clear Flag
        ScalerSetBit_EXINT0(P28_A4_CBUS0_CTRL_04, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
        
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
        if((ScalerGetBit_EXINT0(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1)) ==  0x00) && 
            (ScalerGetBit_EXINT0(PB_B6_Z0_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00))
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
        if((ScalerGetBit_EXINT0(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1)) ==  _BIT1) && 
            (ScalerGetBit_EXINT0(PB_B6_Z0_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00))
#endif

        {
            // Suspend Key Calculation before load key
            ScalerSetBit_EXINT0(P2_AE_TMDS_RPS, ~_BIT1, 0x00);
        }

        // Enable GDI BandGap
        ScalerSetBit_EXINT0(PB_F4_AUX_5, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

        // Disable GDI Power Saving
        ScalerSetBit_EXINT0(PB_F4_AUX_5, ~_BIT4, 0x00);

        // Enable RX_EN
        ScalerSetBit_EXINT0(PB_B4_POWER_0, ~_BIT3, _BIT3);

        // Port 0 Z0 Enable
        ScalerSetBit_EXINT0(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        CLR_D0_MHL_DDC_EDID_FLAG();
        SET_MHL_PROCESS_STATE(0, _MHL_STATE_DISCOVERY_DONE);
        SET_MHL_READY_TO_TRANSMIT(0, _TRUE);
    }
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
    if(ScalerGetBit_EXINT0(P29_A0_CBUS1_CTRL_00, (_BIT2 | _BIT0)) == (_BIT2 | _BIT0))
    {
        // Clear Wake Up and Discovery Flags
        ScalerSetBit_EXINT0(P29_A0_CBUS1_CTRL_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

        MCU_IRQ_STATUS_FF00 &= ~_BIT5;

        // Disable Discovery Debounce
        ScalerSetBit_EXINT0(P29_A8_CBUS1_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        // Enable Stuck Low IRQ
        ScalerSetBit_EXINT0(P29_A4_CBUS1_CTRL_04, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_D0_DDC_CHANNEL_SEL == _DDC2)
        if((ScalerGetBit_EXINT0(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1)) ==  0x00) && 
            (ScalerGetBit_EXINT0(PB_B6_Z0_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00))
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
        if((ScalerGetBit_EXINT0(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1)) ==  _BIT1) && 
            (ScalerGetBit_EXINT0(PB_B6_Z0_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00))
#endif

        {
            // Suspend Key Calculation before load key
            ScalerSetBit_EXINT0(P2_AE_TMDS_RPS, ~_BIT1, 0x00);
        }

        // Enable GDI BandGap
        ScalerSetBit_EXINT0(PB_F4_AUX_5, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

        // Disable GDI Power Saving
        ScalerSetBit_EXINT0(PB_F4_AUX_5, ~_BIT4, 0x00);

        // Enable RX_EN
        ScalerSetBit_EXINT0(PB_B4_POWER_0, ~_BIT3, _BIT3);

        // Port 0 Z0 Enable
        ScalerSetBit_EXINT0(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        CLR_D0_MHL_DDC_EDID_FLAG();
        SET_MHL_PROCESS_STATE(0, _MHL_STATE_DISCOVERY_DONE);
        SET_MHL_READY_TO_TRANSMIT(0, _TRUE);
    }
#endif
    
#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
    if(ScalerGetBit_EXINT0(P28_A0_CBUS0_CTRL_00, (_BIT2 | _BIT0)) == (_BIT2 | _BIT0))
    {
        // Clear Wake Up and Discovery Flags
        ScalerSetBit_EXINT0(P28_A0_CBUS0_CTRL_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

        MCU_IRQ_STATUS_FF00 &= ~_BIT5;

        // Disable Discovery Debounce
        ScalerSetBit_EXINT0(P28_A8_CBUS0_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        // Enable Stuck Low IRQ and Clear Flag
        ScalerSetBit_EXINT0(P28_A4_CBUS0_CTRL_04, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
        if((ScalerGetBit_EXINT0(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1)) ==  0x00) && 
            (ScalerGetBit_EXINT0(PB_B7_Z0_1, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00))
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
        if((ScalerGetBit_EXINT0(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1)) ==  _BIT1) && 
            (ScalerGetBit_EXINT0(PB_B7_Z0_1, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00))
#endif

        {
            // Suspend Key Calculation before load key
            ScalerSetBit_EXINT0(P2_AE_TMDS_RPS, ~_BIT1, 0x00);
        }

        // Enable GDI BandGap
        ScalerSetBit_EXINT0(PB_F4_AUX_5, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

        // Disable GDI Power Saving
        ScalerSetBit_EXINT0(PB_F4_AUX_5, ~_BIT4, 0x00);

        // Enable RX_EN
        ScalerSetBit_EXINT0(PB_B4_POWER_0, ~_BIT3, _BIT3);

        // Port 1 Z0 Enable
        ScalerSetBit_EXINT0(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        CLR_D1_MHL_DDC_EDID_FLAG();

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        SET_MHL_PROCESS_STATE(1, _MHL_STATE_DISCOVERY_DONE);
        SET_MHL_READY_TO_TRANSMIT(1, _TRUE);
#else
        SET_MHL_PROCESS_STATE(0, _MHL_STATE_DISCOVERY_DONE);
        SET_MHL_READY_TO_TRANSMIT(0, _TRUE);
#endif

    }
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
    if(ScalerGetBit_EXINT0(P29_A0_CBUS1_CTRL_00, (_BIT2 | _BIT0)) == (_BIT2 | _BIT0))
    {
        // Clear Wake Up and Discovery Flags
        ScalerSetBit_EXINT0(P29_A0_CBUS1_CTRL_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

        MCU_IRQ_STATUS_FF00 &= ~_BIT5;

        // Disable Discovery Debounce
        ScalerSetBit_EXINT0(P29_A8_CBUS1_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        // Enable Stuck Low IRQ
        ScalerSetBit_EXINT0(P29_A4_CBUS1_CTRL_04, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
        if((ScalerGetBit_EXINT0(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1)) ==  0x00) && 
            (ScalerGetBit_EXINT0(PB_B7_Z0_1, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00))
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
        if((ScalerGetBit_EXINT0(P2_C2_HDCP_PORT_CTRL, ~(_BIT2 | _BIT1)) ==  _BIT1) && 
            (ScalerGetBit_EXINT0(PB_B7_Z0_1, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == 0x00))
#endif

        {
            // Suspend Key Calculation before load key
            ScalerSetBit_EXINT0(P2_AE_TMDS_RPS, ~_BIT1, 0x00);
        }

        // Enable GDI BandGap
        ScalerSetBit_EXINT0(PB_F4_AUX_5, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

        // Disable GDI Power Saving
        ScalerSetBit_EXINT0(PB_F4_AUX_5, ~_BIT4, 0x00);

        // Enable RX_EN
        ScalerSetBit_EXINT0(PB_B4_POWER_0, ~_BIT3, _BIT3);

        // Port 1 Z0 Enable
        ScalerSetBit_EXINT0(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        CLR_D1_MHL_DDC_EDID_FLAG();

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        SET_MHL_PROCESS_STATE(1, _MHL_STATE_DISCOVERY_DONE);
        SET_MHL_READY_TO_TRANSMIT(1, _TRUE);
#else
        SET_MHL_PROCESS_STATE(0, _MHL_STATE_DISCOVERY_DONE);
        SET_MHL_READY_TO_TRANSMIT(0, _TRUE);
#endif

    }
#endif

#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

    // Check Stuck Low Flag
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
    if(ScalerGetBit_EXINT0(P28_A4_CBUS0_CTRL_04, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
    {
        // Clear Stuck Low Flags and IRQ
        ScalerSetBit_EXINT0(P28_A4_CBUS0_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);

        MCU_IRQ_STATUS_FF00 &= ~_BIT5;

        // Port 0 Z0 Disable
        ScalerSetBit_EXINT0(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

        // Enable Discovery Debounce
        ScalerSetBit_EXINT0(P28_A8_CBUS0_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_MHL_CBUS_CTS_MODE == _ON)
        // Disable DDC Manual
        ScalerSetBit_EXINT0(P28_C8_CBUS0_CTRL_28, ~_BIT6, 0x00);
#endif

        // Reset CBUS Core Function
        ScalerSetBit_EXINT0(P28_A0_CBUS0_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit_EXINT0(P28_A0_CBUS0_CTRL_00, ~(_BIT7), 0x00);

        SET_MHL_PROCESS_STATE(0, _MHL_STATE_INITIAL);

        CLR_D0_MHL_ADOPTER_ID_HBYTE();
        CLR_D0_MHL_ADOPTER_ID_LBYTE();
        CLR_D0_MHL_ADOPTER_ID_DONE();
        CLR_D0_MHL_CBUS_RESET_FOR_HTC_DONE();
        CLR_MHL_RX0_MHL_VERSION();
    }

#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
    if(ScalerGetBit_EXINT0(P29_A4_CBUS1_CTRL_04, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
    {
        // Clear Stuck Low Flags and IRQ
        ScalerSetBit_EXINT0(P29_A4_CBUS1_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);

        MCU_IRQ_STATUS_FF00 &= ~_BIT5;

        // Port 0 Z0 Disable
        ScalerSetBit_EXINT0(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

        // Enable Discovery Debounce
        ScalerSetBit_EXINT0(P29_A8_CBUS1_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_MHL_CBUS_CTS_MODE == _ON)
        // Disable DDC Manual
        ScalerSetBit_EXINT0(P29_C8_CBUS1_CTRL_28, ~_BIT6, 0x00);
#endif
        // Reset CBUS Core Function
        ScalerSetBit_EXINT0(P29_A0_CBUS1_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit_EXINT0(P29_A0_CBUS1_CTRL_00, ~(_BIT7), 0x00);

        SET_MHL_PROCESS_STATE(0, _MHL_STATE_INITIAL);

        CLR_D0_MHL_ADOPTER_ID_HBYTE();
        CLR_D0_MHL_ADOPTER_ID_LBYTE();
        CLR_D0_MHL_ADOPTER_ID_DONE();
        CLR_D0_MHL_CBUS_RESET_FOR_HTC_DONE();
        CLR_MHL_RX0_MHL_VERSION();
    }

#endif

#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
    if(ScalerGetBit_EXINT0(P28_A4_CBUS0_CTRL_04, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
    {
        // Clear Stuck Low Flags and IRQ
        ScalerSetBit_EXINT0(P28_A4_CBUS0_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);

        MCU_IRQ_STATUS_FF00 &= ~_BIT5;

        // Port 1 Z0 Disable
        ScalerSetBit_EXINT0(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

        // Enable Discovery Debounce
        ScalerSetBit_EXINT0(P28_A8_CBUS0_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_MHL_CBUS_CTS_MODE == _ON)
        // Disable DDC Manual
        ScalerSetBit_EXINT0(P28_C8_CBUS0_CTRL_28, ~_BIT6, 0x00);
#endif
        // Reset CBUS Core Function
        ScalerSetBit_EXINT0(P28_A0_CBUS0_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit_EXINT0(P28_A0_CBUS0_CTRL_00, ~(_BIT7), 0x00);

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        SET_MHL_PROCESS_STATE(1, _MHL_STATE_INITIAL);
#else
        SET_MHL_PROCESS_STATE(0, _MHL_STATE_INITIAL);
#endif

        CLR_D1_MHL_ADOPTER_ID_HBYTE();
        CLR_D1_MHL_ADOPTER_ID_LBYTE();
        CLR_D1_MHL_ADOPTER_ID_DONE();
        CLR_D1_MHL_CBUS_RESET_FOR_HTC_DONE(); 
        CLR_MHL_RX1_MHL_VERSION();
    }

#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
    if(ScalerGetBit_EXINT0(P29_A4_CBUS1_CTRL_04, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
    {
        // Clear Stuck Low Flags and IRQ
        ScalerSetBit_EXINT0(P29_A4_CBUS1_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);

        MCU_IRQ_STATUS_FF00 &= ~_BIT5;

        // Port 1 Z0 Disable
        ScalerSetBit_EXINT0(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

        // Enable Discovery Debounce
        ScalerSetBit_EXINT0(P29_A8_CBUS1_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_MHL_CBUS_CTS_MODE == _ON)
        // Disable DDC Manual
        ScalerSetBit_EXINT0(P29_C8_CBUS1_CTRL_28, ~_BIT6, 0x00);
#endif
        // Reset CBUS Core Function
        ScalerSetBit_EXINT0(P29_A0_CBUS1_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit_EXINT0(P29_A0_CBUS1_CTRL_00, ~(_BIT7), 0x00);

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        SET_MHL_PROCESS_STATE(1, _MHL_STATE_INITIAL);
#else
        SET_MHL_PROCESS_STATE(0, _MHL_STATE_INITIAL);
#endif

        CLR_D1_MHL_ADOPTER_ID_HBYTE();
        CLR_D1_MHL_ADOPTER_ID_LBYTE();
        CLR_D1_MHL_ADOPTER_ID_DONE();
        CLR_D1_MHL_CBUS_RESET_FOR_HTC_DONE();
        CLR_MHL_RX1_MHL_VERSION();
    }
    
#endif

#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

}

//--------------------------------------------------
// Description  : Send MSC HPD Operation
// Input Value  : ucInputPort --> D0 or D1
//                enumMSCType --> MSC Command
//                enumMSCOffset --> MSC Device Register
//                enumMSCValue --> MSC Device Register Field
// Output Value : Success or Fail
//--------------------------------------------------
bit ScalerMHLMscSendCommand(BYTE ucInputPort, EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue)
{
    BYTE ucResultPacket = 0;

#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    if(ucInputPort == _D0_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(0);
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(1);
    }
#else
    SET_MHL_PORT_ACTIVE(0);
#endif

    if(GET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE()) == _TRUE)
    {
        ucResultPacket = ScalerMHLMscFIFOSendCommand(ucInputPort, enumMSCCommand, enumMSCOffset, enumMSCValue, 0, _NULL_POINTER);

        switch(ucResultPacket)
        {
            case _MHL_SUCCESS: // Source reply ACK Packet

                SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _TRUE);

                return _SUCCESS;
                
                break;

            case _MHL_ABORT_FAIL: // Source reply ABORT Packet

                SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _FALSE);

                if(ucInputPort == _D0_INPUT_PORT)
                {
                    ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D0_READY_TO_TRANSMIT);
                }
                else if(ucInputPort == _D1_INPUT_PORT)
                {
                    ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D1_READY_TO_TRANSMIT);
                }
                
                return _FAIL;

                break;

            case _MHL_ABORT_REPLY: // Source Reply Data Packet Instead of Control Packet

                ScalerMHLMscFIFOSendCommand(ucInputPort, _MSC_ABORT, _MSC_NULL_ADDRESS, _MSC_NULL_VALUE, 0, _NULL_POINTER);

                return _FAIL;
                
                break;

            default: // Source Reply No Packet(Timeout) or NACK

                return _FAIL;
                
                break;
        }
    }
    else
    {                
        return _FAIL;
    }
}

//--------------------------------------------------
// Description  : Send Write Burst Operation
// Input Value  : ucInputPort --> D0 or D1
//                ucDataLength --> Data Length
//                pucData --> Data
//                ucMode --> Write Burst Mode
// Output Value : Success or Different Fail Situations
//--------------------------------------------------
bit ScalerMHLMscSendWriteBurst(BYTE ucInputPort, BYTE ucOffset, BYTE ucDataLength, BYTE *pucData, EnumMHLWriteBurstMode enumMode)
{
    BYTE ucResultPacket = 0;

#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    if(ucInputPort == _D0_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(0);
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(1);
    }
#else
    SET_MHL_PORT_ACTIVE(0);
#endif

    if(enumMode == _MHL_WRITE_BURST_WITH_REQ)
    {
        if(ucInputPort == _D0_INPUT_PORT)
        {

#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
            // Clear Grant To Write Flag
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT);

            // Send Request to Write
            ScalerMHLMscSendCommand(ucInputPort, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT);

            // Disable Access Port Auto Increase
            ScalerSetBit(P28_AB_CBUS0_CTRL_0B, ~_BIT0, 0x00);

            // Polling Grant to Write
            ScalerSetByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT);
            ScalerTimerPollingFlagProc(100, P28_AD_CBUS0_CTRL_0D, _MSC_GRT_WRT, _TRUE);

            // Enable Access Port Auto Increase
            ScalerSetBit(P28_AB_CBUS0_CTRL_0B, ~_BIT0, _BIT0);        
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
            // Clear Grant To Write Flag
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT);

            // Send Request to Write
            ScalerMHLMscSendCommand(ucInputPort, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT);

            // Disable Access Port Auto Increase
            ScalerSetBit(P29_AB_CBUS1_CTRL_0B, ~_BIT0, 0x00);

            // Polling Grant to Write
            ScalerSetByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT);
            ScalerTimerPollingFlagProc(100, P29_AD_CBUS1_CTRL_0D, _MSC_GRT_WRT, _TRUE);

            // Enable Access Port Auto Increase
            ScalerSetBit(P29_AB_CBUS1_CTRL_0B, ~_BIT0, _BIT0);
#endif

        }
        else if(ucInputPort == _D1_INPUT_PORT)
        {
        
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
            // Clear Grant To Write Flag
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT);

            // Send Request to Write
            ScalerMHLMscSendCommand(ucInputPort, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT);

            // Disable Access Port Auto Increase
            ScalerSetBit(P28_AB_CBUS0_CTRL_0B, ~_BIT0, 0x00);

            // Polling Grant to Write
            ScalerSetByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT);
            ScalerTimerPollingFlagProc(100, P28_AD_CBUS0_CTRL_0D, _MSC_GRT_WRT, _TRUE);

            // Enable Access Port Auto Increase
            ScalerSetBit(P28_AB_CBUS0_CTRL_0B, ~_BIT0, _BIT0);
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
            // Clear Grant To Write Flag
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT);

            // Send Request to Write
            ScalerMHLMscSendCommand(ucInputPort, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT);

            // Disable Access Port Auto Increase
            ScalerSetBit(P29_AB_CBUS1_CTRL_0B, ~_BIT0, 0x00);

            // Polling Grant to Write
            ScalerSetByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT);
            ScalerTimerPollingFlagProc(100, P29_AD_CBUS1_CTRL_0D, _MSC_GRT_WRT, _TRUE);

            // Enable Access Port Auto Increase
            ScalerSetBit(P29_AB_CBUS1_CTRL_0B, ~_BIT0, _BIT0);
#endif

        }
    }

    if(GET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE()) == _TRUE)
    {
        ucResultPacket = ScalerMHLMscFIFOSendCommand(ucInputPort, _MSC_WRITE_BURST, ucOffset, 0x00, ucDataLength, pucData);

        switch(ucResultPacket)
        {
            case _MHL_SUCCESS: // Source reply ACK Packet

                // Send Device Scratchpad Change
                ScalerMHLMscSendCommand(ucInputPort, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_DSCR_CHG);
                
                return _SUCCESS;
                
                break;

            case _MHL_ABORT_FAIL: // Source reply ABORT Packet

                SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _FALSE);

                if(ucInputPort == _D0_INPUT_PORT)
                {
                    ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D0_READY_TO_TRANSMIT);
                }
                else if(ucInputPort == _D1_INPUT_PORT)
                {
                    ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D1_READY_TO_TRANSMIT);
                }
                
                return _FAIL;

                break;

            case _MHL_ABORT_REPLY: // Source Reply Data Packet Instead of Control Packet

                ScalerMHLMscFIFOSendCommand(ucInputPort, _MSC_ABORT, _MSC_NULL_ADDRESS, _MSC_NULL_VALUE, 0, _NULL_POINTER);

                return _FAIL;
                
                break;

            default: // Source Reply No Packet(Timeout) or NACK

                return _FAIL;
                
                break;
        }
    }
    else
    {                
        return _FAIL;
    }
}

//--------------------------------------------------
// Description  : Read Device Capabilities
// Input Value  : ucInputPort --> D0 or D1
//                enumMSCOffset --> Device Capability Offset
//                pucData --> Data to be Read
// Output Value : Success or Different Fail Situations
//--------------------------------------------------
bit ScalerMHLMscReadDevCapabilities(BYTE ucInputPort, EnumMHLMscCapRegField enumMSCOffset, BYTE *pucData)
{
    BYTE ucResultPacket = 0;

#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    if(ucInputPort == _D0_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(0);
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(1);
    }
#else
    SET_MHL_PORT_ACTIVE(0);
#endif

    if(GET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE()) == _TRUE)
    {
        ucResultPacket = ScalerMHLMscFIFOSendCommand(ucInputPort, _MSC_READ_DEVCAP, enumMSCOffset, _MSC_NULL_VALUE, 0, pucData);

        switch(ucResultPacket)
        {
            case _MHL_SUCCESS: // Source reply ACK Packet

                SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _TRUE);

                return _SUCCESS;
                
                break;

            case _MHL_ABORT_FAIL: // Source reply ABORT Packet

                SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _FALSE);

                if(ucInputPort == _D0_INPUT_PORT)
                {
                    ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D0_READY_TO_TRANSMIT);
                }
                else if(ucInputPort == _D1_INPUT_PORT)
                {
                    ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D1_READY_TO_TRANSMIT);
                }
                
                return _FAIL;

                break;

            case _MHL_ABORT_REPLY: // Source Reply Data Packet Instead of Control Packet

                ScalerMHLMscFIFOSendCommand(ucInputPort, _MSC_ABORT, _MSC_NULL_ADDRESS, _MSC_NULL_VALUE, 0, _NULL_POINTER);

                return _FAIL;
                
                break;

            default: // Source Reply No Packet(Timeout) or NACK

                return _FAIL;
                
                break;
        }
    }
    else
    {                
        return _FAIL;
    }
}

//--------------------------------------------------
// Description  : Send MSC HPD Operation
// Input Value  : ucInputPort --> D0 or D1
//                enumMSCType --> MSC Command
//                enumMSCOffset --> MSC Device Register
//                enumMSCValue --> MSC Device Register Field
// Output Value : Success or Different Fail Situations
//--------------------------------------------------
BYTE ScalerMHLMscFIFOSendCommand(BYTE ucInputPort, EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue, BYTE ucDataLength, BYTE *pucData)
{
    BYTE ucTimeOut = 100;
    BYTE ucSendType = 0;
    BYTE ucWaitType = 0;
    BYTE ucI = 0;

    switch(enumMSCCommand)
    {
        case _MSC_SET_INT:
        case _MSC_MSG:
            
            ucSendType = _MSC_SEND_COM_OFF_DAT;
            ucWaitType = _MSC_WAIT_COMMAND;
            break;

        case _MSC_READ_DEVCAP:

            ucSendType = _MSC_SEND_COM_OFF;
            ucWaitType = _MSC_WAIT_COM_DAT;
            break;

        case _MSC_SET_HPD:
            
            ucSendType = _MSC_SEND_COMMAND;
            ucWaitType = _MSC_WAIT_COMMAND;
            break;

        case _MSC_ABORT:
            
            ucSendType = _MSC_SEND_COMMAND;
            ucWaitType = _MSC_WAIT_NULL;
            break;

        case _MSC_WRITE_BURST:

            ucSendType = _MSC_SEND_COM_OFF_DAT_COM;
            ucWaitType = _MSC_WAIT_COMMAND;
            break;

        default:

            break;
    }
    
    if(ucInputPort == _D0_INPUT_PORT)
    {

#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        // Check If Source Has Sent An ABORT Packet
        if(ScalerGetBit(P28_CF_CBUS0_CTRL_2F, _BIT2) == _BIT2)
        {
            ScalerSetByte(P28_CF_CBUS0_CTRL_2F, _BIT2);
            
            ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D0_READY_TO_TRANSMIT);

            SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _FALSE);

            return _MHL_FAIL;
        }

        // Clear FIFO and Send Command Only
        ScalerSetByte(P28_DE_CBUS0_CTRL_3E, (_BIT6 | ucSendType));
        
        // Set MSC Command
        ScalerSetByte(P28_DF_CBUS0_CTRL_3F, enumMSCCommand);

        // Set MSC Offset
        ScalerSetByte(P28_E1_CBUS0_CTRL_41, enumMSCOffset);

        if(enumMSCCommand == _MSC_WRITE_BURST)
        {
            // Set MSC Last Command
            ScalerSetByte(P28_E0_CBUS0_CTRL_40, _MSC_EOF_PACKET);
            
            // Set MSC Data
            for(ucI = 0; ucI < ucDataLength; ucI++)
            {
                ScalerSetByte(P28_E2_CBUS0_CTRL_42, pucData[ucI]);
            }
        }
        else if(enumMSCCommand != _MSC_READ_DEVCAP)
        {
            // Set MSC Value
            ScalerSetByte(P28_E2_CBUS0_CTRL_42, enumMSCValue);
        }
        
        // MSC Packet and Wait Type
        ScalerSetBit(P28_E3_CBUS0_CTRL_43, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), ((_MSC_PACKET << 6) | ucWaitType));

        // Send Request
        ScalerSetBit(P28_DE_CBUS0_CTRL_3E, ~(_BIT7), _BIT7);
        
        // Check if Process is finished
        while(--ucTimeOut != 0)
        {
            if(ScalerGetBit(P28_CF_CBUS0_CTRL_2F, _BIT2) == _BIT2)
            {
                // Clear Flag
                ScalerSetBit(P28_CF_CBUS0_CTRL_2F, _BIT2, _BIT2);

                return _MHL_ABORT_FAIL;
            }
            else if((ScalerGetBit(P28_F6_CBUS0_CTRL_56, _BIT7) == _BIT7) && (ScalerGetBit(P28_F7_CBUS0_CTRL_57, _BIT7) == 0x00))
            {
                // Clear Flag
                ScalerSetBit(P28_F6_CBUS0_CTRL_56, ~_BIT7, _BIT7);

                if(ucWaitType == _MSC_WAIT_NULL)
                {
                    return _MHL_SUCCESS;
                }
                else
                {
                    // Check ACK Packet
                    if(ScalerGetByte(P28_E4_CBUS0_CTRL_44) == _MSC_ACK_PACKET)
                    {
                        if(enumMSCCommand == _MSC_READ_DEVCAP)
                        {
                            *pucData = ScalerGetByte(P28_E5_CBUS0_CTRL_45);
                        }
                        
                        return _MHL_SUCCESS;
                    }
                    else
                    {
                        return _MHL_FAIL;
                    }
                }
            }
            else if((ScalerGetBit(P28_F7_CBUS0_CTRL_57, _BIT7) == _BIT7) && (ScalerGetByte(P28_D2_CBUS0_CTRL_32) == _MSC_PROTOCOL_ERROR))
            {
                // Clear Flags
                ScalerSetBit(P28_F6_CBUS0_CTRL_56, ~_BIT7, _BIT7);
                ScalerSetBit(P28_F7_CBUS0_CTRL_57, ~_BIT7, _BIT7);
                ScalerSetByte(P28_D2_CBUS0_CTRL_32, 0xFF);
                
                return _MHL_ABORT_REPLY;
            }

            ScalerTimerDelayXms(1);
        }

        // Clear Flag
        ScalerSetBit(P28_F6_CBUS0_CTRL_56, ~_BIT7, _BIT7);
        ScalerSetBit(P28_F7_CBUS0_CTRL_57, ~_BIT7, _BIT7);
        ScalerSetByte(P28_D2_CBUS0_CTRL_32, 0xFF);

#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        // Check If Source Has Sent An ABORT Packet
        if(ScalerGetBit(P29_CF_CBUS1_CTRL_2F, _BIT2) == _BIT2)
        {
            ScalerSetByte(P29_CF_CBUS1_CTRL_2F, _BIT2);
            
            ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D0_READY_TO_TRANSMIT);

            SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _FALSE);

            return _MHL_FAIL;
        }

        // Clear FIFO and Send Command Only
        ScalerSetByte(P29_DE_CBUS1_CTRL_3E, (_BIT6 | ucSendType));
        
        // Set MSC Command
        ScalerSetByte(P29_DF_CBUS1_CTRL_3F, enumMSCCommand);        

        // Set MSC Offset
        ScalerSetByte(P29_E1_CBUS1_CTRL_41, enumMSCOffset);

        if(enumMSCCommand == _MSC_WRITE_BURST)
        {
            // Set MSC Last Command
            ScalerSetByte(P29_E0_CBUS1_CTRL_40, _MSC_EOF_PACKET);
            
            // Set MSC Data
            for(ucI = 0; ucI < ucDataLength; ucI++)
            {
                ScalerSetByte(P29_E2_CBUS1_CTRL_42, pucData[ucI]);
            }
        }
        else if(enumMSCCommand != _MSC_READ_DEVCAP)
        {
            // Set MSC Value
            ScalerSetByte(P29_E2_CBUS1_CTRL_42, enumMSCValue);
        }

        // MSC Packet and Wait Type
        ScalerSetBit(P29_E3_CBUS1_CTRL_43, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), ((_MSC_PACKET << 6) | ucWaitType));

        // Set Request
        ScalerSetBit(P29_DE_CBUS1_CTRL_3E, ~(_BIT7), _BIT7);
        
        // Check if Process is finished
        while(--ucTimeOut != 0)
        {
            if(ScalerGetBit(P29_CF_CBUS1_CTRL_2F, _BIT2) == _BIT2)
            {
                // Clear Flag
                ScalerSetBit(P29_CF_CBUS1_CTRL_2F, _BIT2, _BIT2);

                return _MHL_ABORT_FAIL;
            }
            else if((ScalerGetBit(P29_F6_CBUS1_CTRL_56, _BIT7) == _BIT7) && (ScalerGetBit(P29_F7_CBUS1_CTRL_57, _BIT7) == 0x00))
            {
                // Clear Flag
                ScalerSetBit(P29_F6_CBUS1_CTRL_56, ~_BIT7, _BIT7);

                if(ucWaitType == _MSC_WAIT_NULL)
                {
                    return _MHL_SUCCESS;
                }
                else
                {
                    // Check ACK Packet
                    if(ScalerGetByte(P29_E4_CBUS1_CTRL_44) == _MSC_ACK_PACKET)
                    {
                        if(enumMSCCommand == _MSC_READ_DEVCAP)
                        {
                            *pucData = ScalerGetByte(P29_E5_CBUS1_CTRL_45);
                        }
                        
                        return _MHL_SUCCESS;
                    }
                    else
                    {
                        return _MHL_FAIL;
                    }
                }
            }
            else if((ScalerGetBit(P29_F7_CBUS1_CTRL_57, _BIT7) == _BIT7) && (ScalerGetByte(P29_D2_CBUS1_CTRL_32) == _MSC_PROTOCOL_ERROR))
            {
                // Clear Flags
                ScalerSetBit(P29_F6_CBUS1_CTRL_56, ~_BIT7, _BIT7);
                ScalerSetBit(P29_F7_CBUS1_CTRL_57, ~_BIT7, _BIT7);
                ScalerSetByte(P29_D2_CBUS1_CTRL_32, 0xFF);
                
                return _MHL_ABORT_REPLY;
            }

            ScalerTimerDelayXms(1);
        }

        // Clear Flag
        ScalerSetBit(P29_F6_CBUS1_CTRL_56, ~_BIT7, _BIT7);
        ScalerSetBit(P29_F7_CBUS1_CTRL_57, ~_BIT7, _BIT7);
        ScalerSetByte(P29_D2_CBUS1_CTRL_32, 0xFF);
#endif

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        // Check If Source Has Sent An ABORT Packet
        if(ScalerGetBit(P28_CF_CBUS0_CTRL_2F, _BIT2) == _BIT2)
        {
            ScalerSetByte(P28_CF_CBUS0_CTRL_2F, _BIT2);
            
            ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D1_READY_TO_TRANSMIT);

            SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _FALSE);

            return _MHL_FAIL;
        }

        // Clear FIFO and Send Command Only
        ScalerSetByte(P28_DE_CBUS0_CTRL_3E, (_BIT6 | ucSendType));
        
        // Set MSC Command
        ScalerSetByte(P28_DF_CBUS0_CTRL_3F, enumMSCCommand);        

        // Set MSC Offset
        ScalerSetByte(P28_E1_CBUS0_CTRL_41, enumMSCOffset);

        if(enumMSCCommand == _MSC_WRITE_BURST)
        {
            // Set MSC Last Command
            ScalerSetByte(P28_E0_CBUS0_CTRL_40, _MSC_EOF_PACKET);
            
            // Set MSC Data
            for(ucI = 0; ucI < ucDataLength; ucI++)
            {
                ScalerSetByte(P28_E2_CBUS0_CTRL_42, pucData[ucI]);
            }
        }
        else if(enumMSCCommand != _MSC_READ_DEVCAP)
        {
            // Set MSC Value
            ScalerSetByte(P28_E2_CBUS0_CTRL_42, enumMSCValue);
        }

        // MSC Packet and Wait Type
        ScalerSetBit(P28_E3_CBUS0_CTRL_43, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), ((_MSC_PACKET << 6) | ucWaitType));

        // Set Request
        ScalerSetBit(P28_DE_CBUS0_CTRL_3E, ~(_BIT7), _BIT7);
        
        // Check if Process is finished (Spec Time out min = 100ms)
        while(--ucTimeOut != 0)
        {
            if(ScalerGetBit(P28_CF_CBUS0_CTRL_2F, _BIT2) == _BIT2)
            {
                // Clear Flag
                ScalerSetBit(P28_CF_CBUS0_CTRL_2F, _BIT2, _BIT2);

                return _MHL_ABORT_FAIL;
            }
            else if((ScalerGetBit(P28_F6_CBUS0_CTRL_56, _BIT7) == _BIT7) && (ScalerGetBit(P28_F7_CBUS0_CTRL_57, _BIT7) == 0x00))
            {
                // Clear Flag
                ScalerSetBit(P28_F6_CBUS0_CTRL_56, ~_BIT7, _BIT7);

                if(ucWaitType == _MSC_WAIT_NULL)
                {
                    return _MHL_SUCCESS;
                }
                else
                {
                    // Check ACK Packet
                    if(ScalerGetByte(P28_E4_CBUS0_CTRL_44) == _MSC_ACK_PACKET)
                    {
                        if(enumMSCCommand == _MSC_READ_DEVCAP)
                        {
                            *pucData = ScalerGetByte(P28_E5_CBUS0_CTRL_45);
                        }
                        
                        return _MHL_SUCCESS;
                    }
                    else
                    {
                        return _MHL_FAIL;
                    }
                }
            }
            else if((ScalerGetBit(P28_F7_CBUS0_CTRL_57, _BIT7) == _BIT7) && (ScalerGetByte(P28_D2_CBUS0_CTRL_32) == _MSC_PROTOCOL_ERROR))
            {
                // Clear Flags
                ScalerSetBit(P28_F6_CBUS0_CTRL_56, ~_BIT7, _BIT7);
                ScalerSetBit(P28_F7_CBUS0_CTRL_57, ~_BIT7, _BIT7);
                ScalerSetByte(P28_D2_CBUS0_CTRL_32, 0xFF);
                
                return _MHL_ABORT_REPLY;
            }

            ScalerTimerDelayXms(1);
        }

        // Clear Flag
        ScalerSetBit(P28_F6_CBUS0_CTRL_56, ~_BIT7, _BIT7);
        ScalerSetBit(P28_F7_CBUS0_CTRL_57, ~_BIT7, _BIT7);
        ScalerSetByte(P28_D2_CBUS0_CTRL_32, 0xFF);
        
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        // Check If Source Has Sent An ABORT Packet
        if(ScalerGetBit(P29_CF_CBUS1_CTRL_2F, _BIT2) == _BIT2)
        {
            ScalerSetByte(P29_CF_CBUS1_CTRL_2F, _BIT2);
            
            ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_D1_READY_TO_TRANSMIT);

            SET_MHL_READY_TO_TRANSMIT(GET_MHL_PORT_ACTIVE(), _FALSE);

            return _MHL_FAIL;
        }

        // Clear FIFO and Send Command Only
        ScalerSetByte(P29_DE_CBUS1_CTRL_3E, (_BIT6 | ucSendType));
        
        // Set MSC Command
        ScalerSetByte(P29_DF_CBUS1_CTRL_3F, enumMSCCommand);        

        // Set MSC Offset
        ScalerSetByte(P29_E1_CBUS1_CTRL_41, enumMSCOffset);

        if(enumMSCCommand == _MSC_WRITE_BURST)
        {
            // Set MSC Last Command
            ScalerSetByte(P29_E0_CBUS1_CTRL_40, _MSC_EOF_PACKET);
            
            // Set MSC Data
            for(ucI = 0; ucI < ucDataLength; ucI++)
            {
                ScalerSetByte(P29_E2_CBUS1_CTRL_42, pucData[ucI]);
            }
        }
        else if(enumMSCCommand != _MSC_READ_DEVCAP)
        {
            // Set MSC Value
            ScalerSetByte(P29_E2_CBUS1_CTRL_42, enumMSCValue);
        }

        // MSC Packet and Wait Type
        ScalerSetBit(P29_E3_CBUS1_CTRL_43, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), ((_MSC_PACKET << 6) | ucWaitType));

        // Set Request
        ScalerSetBit(P29_DE_CBUS1_CTRL_3E, ~(_BIT7), _BIT7);
        
        // Check if Process is finished
        while(--ucTimeOut != 0)
        {
            if(ScalerGetBit(P29_CF_CBUS1_CTRL_2F, _BIT2) == _BIT2)
            {
                // Clear Flag
                ScalerSetBit(P29_CF_CBUS1_CTRL_2F, _BIT2, _BIT2);

                return _MHL_ABORT_FAIL;
            }
            else if((ScalerGetBit(P29_F6_CBUS1_CTRL_56, _BIT7) == _BIT7) && (ScalerGetBit(P29_F7_CBUS1_CTRL_57, _BIT7) == 0x00))
            {
                // Clear Flag
                ScalerSetBit(P29_F6_CBUS1_CTRL_56, ~_BIT7, _BIT7);

                if(ucWaitType == _MSC_WAIT_NULL)
                {
                    return _MHL_SUCCESS;
                }
                else
                {
                    // Check ACK Packet
                    if(ScalerGetByte(P29_E4_CBUS1_CTRL_44) == _MSC_ACK_PACKET)
                    {
                        if(enumMSCCommand == _MSC_READ_DEVCAP)
                        {
                            *pucData = ScalerGetByte(P29_E5_CBUS1_CTRL_45);
                        }
                        
                        return _MHL_SUCCESS;
                    }
                    else
                    {
                        return _MHL_FAIL;
                    }
                }
            }
            else if((ScalerGetBit(P29_F7_CBUS1_CTRL_57, _BIT7) == _BIT7) && (ScalerGetByte(P29_D2_CBUS1_CTRL_32) == _MSC_PROTOCOL_ERROR))
            {
                // Clear Flags
                ScalerSetBit(P29_F6_CBUS1_CTRL_56, ~_BIT7, _BIT7);
                ScalerSetBit(P29_F7_CBUS1_CTRL_57, ~_BIT7, _BIT7);
                ScalerSetByte(P29_D2_CBUS1_CTRL_32, 0xFF);
                
                return _MHL_ABORT_REPLY;
            }

            ScalerTimerDelayXms(1);
        }

        // Clear Flag
        ScalerSetBit(P29_F6_CBUS1_CTRL_56, ~_BIT7, _BIT7);
        ScalerSetBit(P29_F7_CBUS1_CTRL_57, ~_BIT7, _BIT7);
        ScalerSetByte(P29_D2_CBUS1_CTRL_32, 0xFF);
#endif

    }  

    return _MHL_FAIL;
}

//--------------------------------------------------
// Description  : Check Write Status
// Input Value  : ucInputPort --> _D0_INPUT_PORT/_D1_INPUT_PORT
// Output Value : None
//--------------------------------------------------
void ScalerMHLMscCheckDeviceINT(BYTE ucInputPort)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
    
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        if((bit)ScalerGetBit(P28_CE_CBUS0_CTRL_2E, _BIT7) == _TRUE)
        {
            //----------------------------------------------------------//
            //-------- Check DevCap Ready (DCAP_RDY, DCAP_CHG) ---------//
            //----------------------------------------------------------//
            if((((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY) == _TRUE) ||
                ((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)))
            {

                if(GET_MHL_RX0_MHL_VERSION() == _MHL_VERSION_NULL)
                {
                    // Read Source Device MHL Version
                    if(ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_MHL_VERSION_01, &g_ucMHLRx0MhlVersion) == _TRUE)
                    {
                        if((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                        {
                            // Write 1 Clear DevCap_Chg Flag
                            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                        }

                        // Clear Flag
                        ScalerSetBit(P28_CE_CBUS0_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
                    }
                }

                // Read Source Adopter ID
                if((GET_D0_MHL_ADOPTER_ID_DONE() == _FALSE) && (GET_MHL_READY_TO_TRANSMIT(0) == _TRUE))
                {
                    if((ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_ADOPTER_ID_H_03, &g_ucD0MHLAdopterIDH) == _TRUE) &&
                        (ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_ADOPTER_ID_L_04, &g_ucD0MHLAdopterIDL) == _TRUE))
                    {
                        DebugMessageDigital("D0 MHL Adopter IDH", g_ucD0MHLAdopterIDH);
                        DebugMessageDigital("D0 MHL Adopter IDL", g_ucD0MHLAdopterIDL);

                        SET_D0_MHL_ADOPTER_ID_DONE();

                        if((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                        {
                            // Write 1 Clear DevCap_Chg Flag
                            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                        }
                        
                        // Clear Flag
                        ScalerSetBit(P28_CE_CBUS0_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7| _BIT6));
                    }
                }
            }    

            // Check Request To Write
            if((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _TRUE)
            {
                if(ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_GRT_WRT) == _SUCCESS)
                {
                    ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT);
                }
            }

            // Check 3D Request and Reply No Support For All Timings
            if((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _BIT4) == _TRUE)
            {
                // 3D_VIC Header
                pData[0] = _MHL_3D_VIC_HB;
                pData[1] = _MHL_3D_VIC_LB;

                // Total Entries -> 0
                pData[3] = 0x00;

                // Checksum -> pData[0] ^ pData[1] ^ pData[3]
                pData[2] = 0x10;

                // 3D_DTD Header
                pData[4] = _MHL_3D_DTD_HB;
                pData[5] = _MHL_3D_DTD_LB;

                // Total Entries -> 0
                pData[7] = 0x00;

                // Checksum -> pData[0] ^ pData[1] ^ pData[3]
                pData[6] = 0x01;

                if(ScalerMHLMscSendWriteBurst(_D0_INPUT_PORT, 0x40, 4, pData, _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                {
                    ScalerTimerDelayXms(30);

                    if(ScalerMHLMscSendWriteBurst(_D0_INPUT_PORT, 0x40, 4, &pData[4], _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                    {
                        ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _BIT4);
                    }
                    
                }
            }

            // Clear Flag
            ScalerSetByte(P28_CE_CBUS0_CTRL_2E, (BYTE)_BIT7);
        }
        
        // Read Device Capabilities
        if((bit)ScalerGetBit(P28_CE_CBUS0_CTRL_2E, _BIT6) == _TRUE)
        {
            if(GET_D0_MHL_ADOPTER_ID_DONE() == _FALSE)
            {
                ScalerTimerDelayXms(50);
                ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_ADOPTER_ID_H_03, &g_ucD0MHLAdopterIDH);
                ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_ADOPTER_ID_L_04, &g_ucD0MHLAdopterIDL);

                SET_D0_MHL_ADOPTER_ID_DONE();
            }
            // Clear Flag
            ScalerSetByte(P28_CE_CBUS0_CTRL_2E, (BYTE)_BIT6);
        }

        // Reset CBUS for HTC Butterfly Bug
        if(((GET_D0_MHL_ADOPTER_ID_HBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_LBYTE)) && 
            (GET_D0_MHL_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
        {
            ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
            DebugMessageDigital("D0 MHL CBUS Reset for HTC", 0);
            SET_D0_MHL_CBUS_RESET_FOR_HTC_DONE();        
        }

        // MHL Version Switch to 1.2 For Samsung Note4
        if(((GET_D0_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)) &&
            (GET_MHL_RX0_MHL_VERSION() >= _MHL_VERSION_3_0) && (GET_D0_MHL_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
        {
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_MHL_VERSION_01, _MHL_VERSION_1_2);
            
            ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_WRITE_STAT, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY);

            SET_D0_MHL_CBUS_RESET_FOR_HTC_DONE();
        }

#if(_MHL_CBUS_CTS_MODE == _ON)

        if(ScalerGetBit(P28_CE_CBUS0_CTRL_2E, _BIT5) == _BIT5)
        {
            ScalerSetBit(P28_C8_CBUS0_CTRL_28, ~_BIT6, _BIT6);

            ScalerSetBit(P28_CE_CBUS0_CTRL_2E, ~_BIT5, _BIT5);
        }

        if(ScalerGetBit(P28_CE_CBUS0_CTRL_2E, _BIT4) == _BIT4)
        {
            ScalerSetBit(P28_C8_CBUS0_CTRL_28, ~_BIT6, 0x00);

            ScalerSetBit(P28_CE_CBUS0_CTRL_2E, ~_BIT4, _BIT4);
        }                
            
#endif // Enf of #if(_MHL_CBUS_CTS_MODE == _ON)        
        
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        if((bit)ScalerGetBit(P29_CE_CBUS1_CTRL_2E, _BIT7) == _TRUE)
        {
            //----------------------------------------------------------//
            //-------- Check DevCap Ready (DCAP_RDY, DCAP_CHG) ---------//
            //----------------------------------------------------------//
            if((((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY) == _TRUE) ||
                ((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)))
            {

                if(GET_MHL_RX0_MHL_VERSION() == _MHL_VERSION_NULL)
                {
                    // Read Source Device MHL Version
                    if(ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_MHL_VERSION_01, &g_ucMHLRx0MhlVersion) == _TRUE)
                    {
                        if((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                        {
                            // Write 1 Clear DevCap_Chg Flag
                            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                        }

                        // Clear Flag
                        ScalerSetBit(P29_CE_CBUS1_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
                    }
                }

                // Read Source Adopter ID
                if((GET_D0_MHL_ADOPTER_ID_DONE() == _FALSE) && (GET_MHL_READY_TO_TRANSMIT(0) == _TRUE))
                {
                    if((ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_ADOPTER_ID_H_03, &g_ucD0MHLAdopterIDH) == _TRUE) &&
                        (ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_ADOPTER_ID_L_04, &g_ucD0MHLAdopterIDL) == _TRUE))
                    {
                        DebugMessageDigital("D0 MHL Adopter IDH", g_ucD0MHLAdopterIDH);
                        DebugMessageDigital("D0 MHL Adopter IDL", g_ucD0MHLAdopterIDL);

                        SET_D0_MHL_ADOPTER_ID_DONE();

                        if((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                        {
                            // Write 1 Clear DevCap_Chg Flag
                            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                        }
                        
                        // Clear Flag
                        ScalerSetBit(P29_CE_CBUS1_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7| _BIT6));
                    }
                }
            }    

            // Check Request To Write
            if((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _TRUE)
            {
                if(ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_GRT_WRT) == _SUCCESS)
                {
                    ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT);
                }
            }

            // Check 3D Request and Reply No Support For All Timings
            if((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _BIT4) == _TRUE)
            {
                // 3D_VIC Header
                pData[0] = _MHL_3D_VIC_HB;
                pData[1] = _MHL_3D_VIC_LB;

                // Total Entries -> 0
                pData[3] = 0x00;

                // Checksum -> pData[0] ^ pData[1] ^ pData[3]
                pData[2] = 0x10;

                // 3D_DTD Header
                pData[4] = _MHL_3D_DTD_HB;
                pData[5] = _MHL_3D_DTD_LB;

                // Total Entries -> 0
                pData[7] = 0x00;

                // Checksum -> pData[0] ^ pData[1] ^ pData[3]
                pData[6] = 0x01;

                if(ScalerMHLMscSendWriteBurst(_D0_INPUT_PORT, 0x40, 4, pData, _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                {
                    ScalerTimerDelayXms(30);

                    if(ScalerMHLMscSendWriteBurst(_D0_INPUT_PORT, 0x40, 4, &pData[4], _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                    {
                        ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _BIT4);
                    }
                    
                }
            }

            // Clear Flag
            ScalerSetByte(P29_CE_CBUS1_CTRL_2E, (BYTE)_BIT7);
        }

        // Read Device Capabilities
        if((bit)ScalerGetBit(P29_CE_CBUS1_CTRL_2E, _BIT6) == _TRUE)
        {
            if(GET_D0_MHL_ADOPTER_ID_DONE() == _FALSE)
            {
                ScalerTimerDelayXms(50);
                ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_ADOPTER_ID_H_03, &g_ucD0MHLAdopterIDH);
                ScalerMHLMscReadDevCapabilities(_D0_INPUT_PORT, _MSC_ADOPTER_ID_L_04, &g_ucD0MHLAdopterIDL);

                SET_D0_MHL_ADOPTER_ID_DONE();
            }
            
            // Clear Flag
            ScalerSetByte(P29_CE_CBUS1_CTRL_2E, (BYTE)_BIT6);
        }
        
        // Reset CBUS for HTC Butterfly Bug
        if(((GET_D0_MHL_ADOPTER_ID_HBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_LBYTE)) && 
            (GET_D0_MHL_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
        {
            ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
            DebugMessageDigital("D0 MHL CBUS Reset for HTC", 0);
            SET_D0_MHL_CBUS_RESET_FOR_HTC_DONE();        
        }

        // MHL Version Switch to 1.2 For Samsung Note4
        if(((GET_D0_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)) &&
            (GET_MHL_RX0_MHL_VERSION() >= _MHL_VERSION_3_0) && (GET_D0_MHL_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
        {
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_MHL_VERSION_01, _MHL_VERSION_1_2);
            
            ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_WRITE_STAT, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY);

            SET_D0_MHL_CBUS_RESET_FOR_HTC_DONE();
        }

#if(_MHL_CBUS_CTS_MODE == _ON)

        if(ScalerGetBit(P29_CE_CBUS1_CTRL_2E, _BIT5) == _BIT5)
        {
            ScalerSetBit(P29_C8_CBUS1_CTRL_28, ~_BIT6, _BIT6);

            ScalerSetBit(P29_CE_CBUS1_CTRL_2E, ~_BIT5, _BIT5);
        }

        if(ScalerGetBit(P29_CE_CBUS1_CTRL_2E, _BIT4) == _BIT4)
        {
            ScalerSetBit(P29_C8_CBUS1_CTRL_28, ~_BIT6, 0x00);

            ScalerSetBit(P29_CE_CBUS1_CTRL_2E, ~_BIT4, _BIT4);
        }                
            
#endif // Enf of #if(_MHL_CBUS_CTS_MODE == _ON)
        
#endif

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        if((bit)ScalerGetBit(P28_CE_CBUS0_CTRL_2E, _BIT7) == _TRUE)
        {
            //----------------------------------------------------------//
            //-------- Check DevCap Ready (DCAP_RDY, DCAP_CHG) ---------//
            //----------------------------------------------------------//
            if((((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY) == _TRUE) ||
                ((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)))
            {

                if(GET_MHL_RX1_MHL_VERSION() == _MHL_VERSION_NULL)
                {
                    // Read Source Device MHL Version
                    if(ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_MHL_VERSION_01, &g_ucMHLRx1MhlVersion) == _TRUE)
                    {
                        if((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                        {
                            // Write 1 Clear DevCap_Chg Flag
                            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                        }

                        // Clear Flag
                        ScalerSetBit(P28_CE_CBUS0_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
                    }
                }

                // Read Source Adopter ID
                if((GET_D1_MHL_ADOPTER_ID_DONE() == _FALSE) && (GET_MHL_READY_TO_TRANSMIT(1) == _TRUE))
                {
                    if((ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_ADOPTER_ID_H_03, &g_ucD1MHLAdopterIDH) == _TRUE) &&
                        (ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_ADOPTER_ID_L_04, &g_ucD1MHLAdopterIDL) == _TRUE))
                    {
                        DebugMessageDigital("D1 MHL Adopter IDH", g_ucD1MHLAdopterIDH);
                        DebugMessageDigital("D1 MHL Adopter IDL", g_ucD1MHLAdopterIDL);

                        SET_D1_MHL_ADOPTER_ID_DONE();

                        if((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                        {
                            // Write 1 Clear DevCap_Chg Flag
                            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                        }
                        
                        // Clear Flag
                        ScalerSetBit(P28_CE_CBUS0_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7| _BIT6));
                    }
                }
            }    

            // Check Request To Write
            if((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _TRUE)
            {
                if(ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_GRT_WRT) == _SUCCESS)
                {
                    ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT);
                }
            }

            // Check 3D Request and Reply No Support For All Timings
            if((bit)ScalerGetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _BIT4) == _TRUE)
            {
                // 3D_VIC Header
                pData[0] = _MHL_3D_VIC_HB;
                pData[1] = _MHL_3D_VIC_LB;

                // Total Entries -> 0
                pData[3] = 0x00;

                // Checksum -> pData[0] ^ pData[1] ^ pData[3]
                pData[2] = 0x10;

                // 3D_DTD Header
                pData[4] = _MHL_3D_DTD_HB;
                pData[5] = _MHL_3D_DTD_LB;

                // Total Entries -> 0
                pData[7] = 0x00;

                // Checksum -> pData[0] ^ pData[1] ^ pData[3]
                pData[6] = 0x01;

                if(ScalerMHLMscSendWriteBurst(_D1_INPUT_PORT, 0x40, 4, pData, _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                {
                    ScalerTimerDelayXms(30);

                    if(ScalerMHLMscSendWriteBurst(_D1_INPUT_PORT, 0x40, 4, &pData[4], _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                    {
                        ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_RCHANGE_INT, _BIT4);
                    }
                    
                }
            }

            // Clear Flag
            ScalerSetByte(P28_CE_CBUS0_CTRL_2E, (BYTE)_BIT7);
        }

        // Read Device Capabilities
        if((bit)ScalerGetBit(P28_CE_CBUS0_CTRL_2E, _BIT6) == _TRUE)
        {
            if(GET_D1_MHL_ADOPTER_ID_DONE() == _FALSE)
            {
                ScalerTimerDelayXms(50);
                ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_ADOPTER_ID_H_03, &g_ucD1MHLAdopterIDH);
                ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_ADOPTER_ID_L_04, &g_ucD1MHLAdopterIDL);

                SET_D1_MHL_ADOPTER_ID_DONE();
            }
            
            // Clear Flag
            ScalerSetByte(P28_CE_CBUS0_CTRL_2E, (BYTE)_BIT6);
        }
        
        // Reset CBUS for HTC Butterfly Bug        
        if(((GET_D1_MHL_ADOPTER_ID_HBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_LBYTE)) && 
            (GET_D1_MHL_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
        {
            ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
            DebugMessageDigital("D1 MHL CBUS Reset for HTC", 0);
            SET_D1_MHL_CBUS_RESET_FOR_HTC_DONE();        
        }

        // MHL Version Switch to 1.2 For Samsung Note4
        if(((GET_D1_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)) &&
            (GET_MHL_RX1_MHL_VERSION() >= _MHL_VERSION_3_0) && (GET_D1_MHL_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
        {
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_MHL_VERSION_01, _MHL_VERSION_1_2);
            
            ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_WRITE_STAT, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY);

            SET_D1_MHL_CBUS_RESET_FOR_HTC_DONE();
        }

#if(_MHL_CBUS_CTS_MODE == _ON)

        if(ScalerGetBit(P28_CE_CBUS0_CTRL_2E, _BIT5) == _BIT5)
        {
            ScalerSetBit(P28_C8_CBUS0_CTRL_28, ~_BIT6, _BIT6);

            ScalerSetBit(P28_CE_CBUS0_CTRL_2E, ~_BIT5, _BIT5);
        }

        if(ScalerGetBit(P28_CE_CBUS0_CTRL_2E, _BIT4) == _BIT4)
        {
            ScalerSetBit(P28_C8_CBUS0_CTRL_28, ~_BIT6, 0x00);

            ScalerSetBit(P28_CE_CBUS0_CTRL_2E, ~_BIT4, _BIT4);
        }                
            
#endif // Enf of #if(_MHL_CBUS_CTS_MODE == _ON)

#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        if((bit)ScalerGetBit(P29_CE_CBUS1_CTRL_2E, _BIT7) == _TRUE)
        {
            //----------------------------------------------------------//
            //-------- Check DevCap Ready (DCAP_RDY, DCAP_CHG) ---------//
            //----------------------------------------------------------//
            if((((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY) == _TRUE) ||
                ((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)))
            {

                if(GET_MHL_RX1_MHL_VERSION() == _MHL_VERSION_NULL)
                {
                    // Read Source Device MHL Version
                    if(ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_MHL_VERSION_01, &g_ucMHLRx1MhlVersion) == _TRUE)
                    {
                        if((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                        {
                            // Write 1 Clear DevCap_Chg Flag
                            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                        }

                        // Clear Flag
                        ScalerSetBit(P29_CE_CBUS1_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
                    }
                }

                // Read Source Adopter ID
                if((GET_D1_MHL_ADOPTER_ID_DONE() == _FALSE) && (GET_MHL_READY_TO_TRANSMIT(1) == _TRUE))
                {
                    if((ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_ADOPTER_ID_H_03, &g_ucD1MHLAdopterIDH) == _TRUE) &&
                        (ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_ADOPTER_ID_L_04, &g_ucD1MHLAdopterIDL) == _TRUE))
                    {
                        DebugMessageDigital("D1 MHL Adopter IDH", g_ucD1MHLAdopterIDH);
                        DebugMessageDigital("D1 MHL Adopter IDL", g_ucD1MHLAdopterIDL);

                        SET_D1_MHL_ADOPTER_ID_DONE();

                        if((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                        {
                            // Write 1 Clear DevCap_Chg Flag
                            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                        }
                        
                        // Clear Flag
                        ScalerSetBit(P29_CE_CBUS1_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7| _BIT6));
                    }
                }
            }    

            // Check Request To Write
            if((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _TRUE)
            {
                if(ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_GRT_WRT) == _SUCCESS)
                {
                    ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT);
                }
            }

            // Check 3D Request and Reply No Support For All Timings
            if((bit)ScalerGetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _BIT4) == _TRUE)
            {
                // 3D_VIC Header
                pData[0] = _MHL_3D_VIC_HB;
                pData[1] = _MHL_3D_VIC_LB;

                // Total Entries -> 0
                pData[3] = 0x00;

                // Checksum -> pData[0] ^ pData[1] ^ pData[3]
                pData[2] = 0x10;

                // 3D_DTD Header
                pData[4] = _MHL_3D_DTD_HB;
                pData[5] = _MHL_3D_DTD_LB;

                // Total Entries -> 0
                pData[7] = 0x00;

                // Checksum -> pData[0] ^ pData[1] ^ pData[3]
                pData[6] = 0x01;

                if(ScalerMHLMscSendWriteBurst(_D1_INPUT_PORT, 0x40, 4, pData, _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                {
                    ScalerTimerDelayXms(30);

                    if(ScalerMHLMscSendWriteBurst(_D1_INPUT_PORT, 0x40, 4, &pData[4], _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                    {
                        ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_RCHANGE_INT, _BIT4);
                    }
                    
                }
            }

            // Clear Flag
            ScalerSetByte(P29_CE_CBUS1_CTRL_2E, (BYTE)_BIT7);
        }

        // Read Device Capabilities
        if((bit)ScalerGetBit(P29_CE_CBUS1_CTRL_2E, _BIT6) == _TRUE)
        {
            if(GET_D1_MHL_ADOPTER_ID_DONE() == _FALSE)
            {
                ScalerTimerDelayXms(50);
                ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_ADOPTER_ID_H_03, &g_ucD1MHLAdopterIDH);
                ScalerMHLMscReadDevCapabilities(_D1_INPUT_PORT, _MSC_ADOPTER_ID_L_04, &g_ucD1MHLAdopterIDL);

                SET_D1_MHL_ADOPTER_ID_DONE();
            }

            // Clear Flag
            ScalerSetByte(P29_CE_CBUS1_CTRL_2E, (BYTE)_BIT6);
        }

        // Reset CBUS for HTC Butterfly Bug
        if(((GET_D1_MHL_ADOPTER_ID_HBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_LBYTE)) && 
            (GET_D1_MHL_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
        {
            ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
            DebugMessageDigital("D1 MHL CBUS Reset for HTC", 0);
            SET_D1_MHL_CBUS_RESET_FOR_HTC_DONE();
        }        

        // MHL Version Switch to 1.2 For Samsung Note4
        if(((GET_D1_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)) &&
            (GET_MHL_RX1_MHL_VERSION() >= _MHL_VERSION_3_0) && (GET_D1_MHL_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
        {
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_MHL_VERSION_01, _MHL_VERSION_1_2);
            
            ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_WRITE_STAT, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY);

            SET_D1_MHL_CBUS_RESET_FOR_HTC_DONE();
        }

#if(_MHL_CBUS_CTS_MODE == _ON)

        if(ScalerGetBit(P29_CE_CBUS1_CTRL_2E, _BIT5) == _BIT5)
        {
            ScalerSetBit(P29_C8_CBUS1_CTRL_28, ~_BIT6, _BIT6);

            ScalerSetBit(P29_CE_CBUS1_CTRL_2E, ~_BIT5, _BIT5);
        }

        if(ScalerGetBit(P29_CE_CBUS1_CTRL_2E, _BIT4) == _BIT4)
        {
            ScalerSetBit(P29_C8_CBUS1_CTRL_28, ~_BIT6, 0x00);

            ScalerSetBit(P29_CE_CBUS1_CTRL_2E, ~_BIT4, _BIT4);
        }                
            
#endif // Enf of #if(_MHL_CBUS_CTS_MODE == _ON)

#endif

    }
}

//--------------------------------------------------
// Description  : MSC Handler
// Input Value  : ucInputPort --> _D0_INPUT_PORT/_D1_INPUT_PORT
//                ucActivePort --> Current Active Port
// Output Value : None
//--------------------------------------------------
bit ScalerMHLMscHandler(BYTE ucInputPort, BYTE ucActivePort, BYTE ucModeState)
{
    BYTE bMHLActive = _FALSE;

    if(((ucInputPort == _D0_INPUT_PORT) && (ucActivePort == _D0_INPUT_PORT)) || \
       ((ucInputPort == _D1_INPUT_PORT) && (ucActivePort == _D1_INPUT_PORT)))
    {
        bMHLActive = _TRUE;
    }
    
#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    if(ucInputPort == _D0_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(0);
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(1);
    }
#else
    SET_MHL_PORT_ACTIVE(0);
#endif

    // Check if Discovery State is done and send HPD & Device Capabilities Ready
    switch(GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()))
    {
        case _MHL_STATE_INITIAL:

            if(ucInputPort == _D0_INPUT_PORT)
            {
                ScalerTimerActiveTimerEvent(SEC(5), _SCALER_TIMER_EVENT_MHL_D0_RECONNECT_1K);
            }
            else
            {
                ScalerTimerActiveTimerEvent(SEC(5), _SCALER_TIMER_EVENT_MHL_D1_RECONNECT_1K);
            }

            return _FALSE;
            break;
            
        case _MHL_STATE_DISCOVERY_DONE:

            if(ucInputPort == _D0_INPUT_PORT)
            {
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_D0_RECONNECT_1K);
            }
            else if(ucInputPort == _D1_INPUT_PORT)
            {
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_D1_RECONNECT_1K);
            }

            // MHL Version
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_MHL_VERSION_01, _MHL_VERSION);
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_MHL_VERSION_01, _MHL_VERSION);

            // Modify RAP/RCP/UCP Support according to MHL Version
#if(_MHL_VERSION == _MHL_VERSION_1_2)
            ScalerSetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_FEATURE_FLAG_0A, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_FEATURE_FLAG_0A, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
#else
            ScalerSetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_FEATURE_FLAG_0A, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (((BYTE)_MHL_UCP_SUPPORT << 4) | (_MHL_UCP_SUPPORT << 3) | (_BIT2 | _BIT1 | _BIT0)));
            ScalerSetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_FEATURE_FLAG_0A, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (((BYTE)_MHL_UCP_SUPPORT << 4) | (_MHL_UCP_SUPPORT << 3) | (_BIT2 | _BIT1 | _BIT0)));
#endif

            // Adopter ID
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_ADOPTER_ID_H_03, (BYTE)((_MHL_ADOPTER_ID >> 8) & 0x00FF));
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_ADOPTER_ID_H_03, (BYTE)((_MHL_ADOPTER_ID >> 8) & 0x00FF));
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_ADOPTER_ID_L_04, (BYTE)(_MHL_ADOPTER_ID & 0x00FF));
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_ADOPTER_ID_L_04, (BYTE)(_MHL_ADOPTER_ID & 0x00FF));

            // Packed Pixel Mode Support
            ScalerSetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_VID_LINK_MODE_05, ~_BIT3, (BYTE)_MHL_PP_MODE_SUPPORT << 3);
            ScalerSetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_VID_LINK_MODE_05, ~_BIT3, (BYTE)_MHL_PP_MODE_SUPPORT << 3);

            // Audio Link Mode Support
            ScalerSetDataPortBit(P28_AC_CBUS0_CTRL_0C, _MSC_AUD_LINK_MODE_06, ~(_BIT1 | _BIT0), _MHL_AUD_CHANNEL);
            ScalerSetDataPortBit(P29_AC_CBUS1_CTRL_0C, _MSC_AUD_LINK_MODE_06, ~(_BIT1 | _BIT0), _MHL_AUD_CHANNEL);

            // Display Support
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_LOG_DEV_MAP_08, 0x01);
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_LOG_DEV_MAP_08, 0x01);

            // Device ID
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_DEVICE_ID_H_0B, (BYTE)((_MHL_DEVICE_ID >> 8) & 0x00FF));
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_DEVICE_ID_H_0B, (BYTE)((_MHL_DEVICE_ID >> 8) & 0x00FF));
            ScalerSetDataPortByte(P28_AC_CBUS0_CTRL_0C, _MSC_DEVICE_ID_L_0C, (BYTE)(_MHL_DEVICE_ID & 0x00FF));
            ScalerSetDataPortByte(P29_AC_CBUS1_CTRL_0C, _MSC_DEVICE_ID_L_0C, (BYTE)(_MHL_DEVICE_ID & 0x00FF));

            if(ScalerMHLMscSendCommand(ucInputPort, _MSC_WRITE_STAT, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY) == _SUCCESS)
            {
                DebugMessageDigital("MHL Dev Cap RDY", 0x01);
                SET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE(), _MHL_STATE_DEV_CAP_RDY);               
            }

            break;

        default:
            break;
    }

    // Send HPD, PATH_EN and Device Capabilities Ready For Source
    if((bMHLActive == _TRUE) && (ucModeState != _MODE_STATUS_INITIAL) && (ucModeState != _MODE_STATUS_POWER_OFF))
    {
        switch(GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()))
        {
            case _MHL_STATE_DEV_CAP_RDY:      

                ScalerTimerDelayXms(150);

                if(ScalerMHLMscSendCommand(ucInputPort, _MSC_SET_HPD, _MSC_NULL_VALUE, _MSC_NULL_VALUE) == _SUCCESS)
                {                    
                    DebugMessageDigital("MHL HPD Done", 0x01);
                    SET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE(), _MHL_STATE_HPD_DONE);
                }

                return _TRUE;
                break;

            case _MHL_STATE_HPD_DONE:

                if(ScalerMHLMscSendCommand(ucInputPort, _MSC_WRITE_STAT, _MSC_LINK_MODE, _MSC_PATH_EN) == _SUCCESS)
                {
                    DebugMessageDigital("MHL Path Enabled", 0x01);
                    SET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE(), _MHL_STATE_PATH_EN_DONE);
                    SET_MHL_READY_TO_RESEND(GET_MHL_PORT_ACTIVE(), _TRUE);
                }

                return _TRUE;
                break;

            case _MHL_STATE_PATH_EN_DONE:

                DebugMessageDigital("MHL CBUS Done", 0x01);

                return _TRUE;
                break;

            case _MHL_STATE_DONE:
            default:

                return _TRUE;
                break;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : RAP Process
// Input Value  : None
// Output Value : True or False (False if Content Off)
//--------------------------------------------------
bit ScalerMHLMscRAPHandler(BYTE ucInputPort)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        // Check RAP Command
        if((bit)ScalerGetBit(P28_D4_CBUS0_CTRL_34, _BIT3) == _TRUE)
        {
            if((ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_POLL) ||
               (ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_ON) ||
               (ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_OFF))
            {
                // Reply RAPK and No Error
                ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_RAPK, _MSC_RAP_NO_ERROR);
            }
            else
            {
                // Reply RAPK and Ineffective Code
                ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_RAPK, _MSC_RAP_UNRECOGNIZE_CODE);
            }

            // Clear Flag
            ScalerSetByte(P28_D4_CBUS0_CTRL_34, (BYTE)_BIT3);

            if(ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
            {
                return _FALSE;
            }
        }
        
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        // Check RAP Command
        if((bit)ScalerGetBit(P29_D4_CBUS1_CTRL_34, _BIT3) == _TRUE)
        {
            if((ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_POLL) ||
               (ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_ON) ||
               (ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_OFF))
            {
                // Reply RAPK and No Error
                ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_RAPK, _MSC_RAP_NO_ERROR);
            }
            else
            {
                // Reply RAPK and Ineffective Code
                ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_RAPK, _MSC_RAP_UNRECOGNIZE_CODE);
            }

            // Clear Flag
            ScalerSetByte(P29_D4_CBUS1_CTRL_34, (BYTE)_BIT3);

            if(ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
            {
                return _FALSE;
            }
        }    
#endif

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        
#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        // Check RAP Command
        if((bit)ScalerGetBit(P28_D4_CBUS0_CTRL_34, _BIT3) == _TRUE)
        {
            if((ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_POLL) ||
               (ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_ON) ||
               (ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_OFF))
            {
                // Reply RAPK and No Error
                ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_RAPK, _MSC_RAP_NO_ERROR);
            }
            else
            {
                // Reply RAPK and Ineffective Code
                ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_RAPK, _MSC_RAP_UNRECOGNIZE_CODE);
            }

            // Clear Flag
            ScalerSetByte(P28_D4_CBUS0_CTRL_34, (BYTE)_BIT3);

            if(ScalerGetByte(P28_DC_CBUS0_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
            {
                return _FALSE;
            }
        }

#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        // Check RAP Command
        if((bit)ScalerGetBit(P29_D4_CBUS1_CTRL_34, _BIT3) == _TRUE)
        {
            if((ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_POLL) ||
               (ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_ON) ||
               (ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_OFF))
            {
                // Reply RAPK and No Error
                ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_RAPK, _MSC_RAP_NO_ERROR);
            }
            else
            {
                // Reply RAPK and Ineffective Code
                ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_RAPK, _MSC_RAP_UNRECOGNIZE_CODE);
            }

            // Clear Flag
            ScalerSetByte(P29_D4_CBUS1_CTRL_34, (BYTE)_BIT3);

            if(ScalerGetByte(P29_DC_CBUS1_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
            {
                return _FALSE;
            }
        }
#endif
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Get RCP Key Code
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit ScalerMHLMscRCPGetCommand(BYTE ucInputPort, BYTE *pucKeyCode)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        // Check RCP Command
        if((bit)ScalerGetBit(P28_D4_CBUS0_CTRL_34, _BIT6) == _TRUE)
        {
            // Clear Flag
            ScalerSetByte(P28_D4_CBUS0_CTRL_34, (BYTE)_BIT6);

            pucKeyCode[0] = ScalerGetByte(P28_D9_CBUS0_CTRL_39);

            return _TRUE;
        }
#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        // Check RCP Command
        if((bit)ScalerGetBit(P29_D4_CBUS1_CTRL_34, _BIT6) == _TRUE)
        {
            // Clear Flag
            ScalerSetByte(P29_D4_CBUS1_CTRL_34, (BYTE)_BIT6);

            pucKeyCode[0] = ScalerGetByte(P29_D9_CBUS1_CTRL_39);

            return _TRUE;
        }
#endif
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        // Check RCP Command
        if((bit)ScalerGetBit(P28_D4_CBUS0_CTRL_34, _BIT6) == _TRUE)
        {
            // Clear Flag
            ScalerSetByte(P28_D4_CBUS0_CTRL_34, (BYTE)_BIT6);

            pucKeyCode[0] = ScalerGetByte(P28_D9_CBUS0_CTRL_39);

            return _TRUE;
        }
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        // Check RCP Command
        if((bit)ScalerGetBit(P29_D4_CBUS1_CTRL_34, _BIT6) == _TRUE)
        {
            // Clear Flag
            ScalerSetByte(P29_D4_CBUS1_CTRL_34, (BYTE)_BIT6);

            pucKeyCode[0] = ScalerGetByte(P29_D9_CBUS1_CTRL_39);
            
            return _TRUE;
        }
#endif

    }

    return _FALSE;
}

#if(_MHL_UCP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get UCP Key Code
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit ScalerMHLMscUCPGetCommand(BYTE ucInputPort, BYTE *pucKeyCode)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
    
#if(_D0_CBUS_CHANNEL_SEL == _CBUS0)
        // Check UCP Command
        if(((bit)ScalerGetBit(P28_D4_CBUS0_CTRL_34, _BIT1) == _TRUE) && (ScalerGetByte(P28_D6_CBUS0_CTRL_36) == _MSC_UCP))
        {
            // Clear Flag
            ScalerSetByte(P28_D4_CBUS0_CTRL_34, (BYTE)_BIT1);

            pucKeyCode[0] = ScalerGetByte(P28_D7_CBUS0_CTRL_37);

            return _TRUE;
        }

#elif(_D0_CBUS_CHANNEL_SEL == _CBUS1)
        // Check UCP Command
        if(((bit)ScalerGetBit(P29_D4_CBUS1_CTRL_34, _BIT1) == _TRUE) && (ScalerGetByte(P29_D6_CBUS1_CTRL_36) == _MSC_UCP))
        {
            // Clear Flag
            ScalerSetByte(P29_D4_CBUS1_CTRL_34, (BYTE)_BIT1);

            pucKeyCode[0] = ScalerGetByte(P29_D7_CBUS1_CTRL_37);

            return _TRUE;
        }
#endif

    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {

#if(_D1_CBUS_CHANNEL_SEL == _CBUS0)
        // Check UCP Command
        if(((bit)ScalerGetBit(P28_D4_CBUS0_CTRL_34, _BIT1) == _TRUE) && (ScalerGetByte(P28_D6_CBUS0_CTRL_36) == _MSC_UCP))
        {
            // Clear Flag
            ScalerSetByte(P28_D4_CBUS0_CTRL_34, (BYTE)_BIT1);

            pucKeyCode[0] = ScalerGetByte(P28_D7_CBUS0_CTRL_37);

            return _TRUE;
        }
#elif(_D1_CBUS_CHANNEL_SEL == _CBUS1)
        // Check UCP Command
        if(((bit)ScalerGetBit(P29_D4_CBUS1_CTRL_34, _BIT1) == _TRUE) && (ScalerGetByte(P29_D6_CBUS1_CTRL_36) == _MSC_UCP))
        {
            // Clear Flag
            ScalerSetByte(P29_D4_CBUS1_CTRL_34, (BYTE)_BIT1);

            pucKeyCode[0] = ScalerGetByte(P29_D7_CBUS1_CTRL_37);

            return _TRUE;
        }
#endif

    }

    return _FALSE;
}
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)

#endif  // End of #if(_MHL_SUPPORT == _ON)
