/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6269_Series_MHL_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of MHL Adopter ID
//--------------------------------------------------
#define _HTC_BUTTERFLY_ADOPTER_ID_HBYTE             0x01
#define _HTC_BUTTERFLY_ADOPTER_ID_LBYTE             0x6F

#define _SAMSUNG_SII_ADOPTER_ID_HBYTE               0x00
#define _SAMSUNG_SII_ADOPTER_ID_LBYTE               0x00

#define _HUAWEI_D2_ADOPTER_ID_HBYTE                 0x01
#define _HUAWEI_D2_ADOPTER_ID_LBYTE                 0x42

#define _ASUS_PADFONE2_ADOPTER_ID_HBYTE             0x05
#define _ASUS_PADFONE2_ADOPTER_ID_LBYTE             0x2C

#define _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE             0x01
#define _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE             0x41

//--------------------------------------------------
// Macros of MHL Adopter ID
//--------------------------------------------------
#if(_MHL_SUPPORT == _ON)
#define GET_D0_MHL_ADOPTER_ID_HBYTE()               (g_ucD0MHLAdopterIDH)
#define GET_D0_MHL_ADOPTER_ID_LBYTE()               (g_ucD0MHLAdopterIDL)
#define CLR_D0_MHL_ADOPTER_ID_HBYTE()               (g_ucD0MHLAdopterIDH = 0)
#define CLR_D0_MHL_ADOPTER_ID_LBYTE()               (g_ucD0MHLAdopterIDL = 0)

#define GET_D1_MHL_ADOPTER_ID_HBYTE()               (g_ucD1MHLAdopterIDH)
#define GET_D1_MHL_ADOPTER_ID_LBYTE()               (g_ucD1MHLAdopterIDL)
#define CLR_D1_MHL_ADOPTER_ID_HBYTE()               (g_ucD1MHLAdopterIDH = 0)
#define CLR_D1_MHL_ADOPTER_ID_LBYTE()               (g_ucD1MHLAdopterIDL = 0)
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
#define GET_D0_MHL_DDC_EDID_FLAG()                          ((bit)(MCU_DVI_EDID_IRQ_FFE4 & _BIT0))
#define CLR_D0_MHL_DDC_EDID_FLAG()                          (MCU_DVI_EDID_IRQ_FFE4 |= _BIT0)
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
#define GET_D0_MHL_DDC_EDID_FLAG()                          ((bit)(MCU_HDMI_EDID_IRQ_FFE5 & _BIT0))
#define CLR_D0_MHL_DDC_EDID_FLAG()                          (MCU_HDMI_EDID_IRQ_FFE5 |= _BIT0)
#endif
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
#if(_D1_DDC_CHANNEL_SEL == _DDC2)
#define GET_D1_MHL_DDC_EDID_FLAG()                          ((bit)(MCU_DVI_EDID_IRQ_FFE4 & _BIT0))
#define CLR_D1_MHL_DDC_EDID_FLAG()                          (MCU_DVI_EDID_IRQ_FFE4 |= _BIT0)
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
#define GET_D1_MHL_DDC_EDID_FLAG()                          ((bit)(MCU_HDMI_EDID_IRQ_FFE5 & _BIT0))
#define CLR_D1_MHL_DDC_EDID_FLAG()                          (MCU_HDMI_EDID_IRQ_FFE5 |= _BIT0)
#endif
#endif

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Definitions of MHL RAP SubCommands
//--------------------------------------------------
typedef enum
{
    _MSC_RAP_POLL = 0x00,
    _MSC_RAP_CONTENT_ON = 0x10,
    _MSC_RAP_CONTENT_OFF = 0x11,
} EnumMHLMscRAPSubComm;

#ifndef __RL6269_SERIES_MHL__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_MHL_SUPPORT == _ON)
extern BYTE g_ucD0MHLAdopterIDH;
extern BYTE g_ucD0MHLAdopterIDL;

extern BYTE g_ucD1MHLAdopterIDH;
extern BYTE g_ucD1MHLAdopterIDL;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_MHL_SUPPORT == _ON)
extern void ScalerMHLCBUSPhySwitch(BYTE ucPortSelect, bit bSelect); 
extern void ScalerMHLCBUSResetProc(BYTE ucInputPort);
extern void ScalerMHLPowerOffProc(void);
extern BYTE ScalerMHLDetectClkMode_EXINT0(void);
extern bit ScalerMHLMscSendCommand(BYTE ucInputPort, EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue);
#endif // End of #if(_MHL_SUPPORT == _ON)

#endif // End of #ifndef __RL6269_SERIES_MHL__
