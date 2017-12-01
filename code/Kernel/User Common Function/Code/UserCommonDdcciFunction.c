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
// ID Code      : UserDdcci.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_DDCCI_FUNCTION__

#include "UserCommonInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of DDCCI Capabilities Request
//--------------------------------------------------
#if(_VGA_PORT_EXIST == _ON)
#define _CREQLEN_DSUB       (sizeof(tCP_STRING_DSUB) - 1)
#endif

#if(_DVI_PORT_EXIST == _ON)
#define _CREQLEN_DVI        (sizeof(tCP_STRING_DVI) - 1)
#endif

#if(_HDMI_PORT_EXIST == _ON)
#define _CREQLEN_HDMI       (sizeof(tCP_STRING_HDMI) - 1)
#endif

#if(_DP_PORT_EXIST == _ON)
#define _CREQLEN_DP         (sizeof(tCP_STRING_DP) - 1)
#endif


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_VGA_PORT_EXIST == _ON)
BYTE code tCP_STRING_DSUB[] =
{
    _CAPABILITIES_STRING_VGA
};
#endif

#if(_DVI_PORT_EXIST == _ON)
BYTE code tCP_STRING_DVI[] =
{
    _CAPABILITIES_STRING_DVI
};
#endif

#if(_HDMI_PORT_EXIST == _ON)
BYTE code tCP_STRING_HDMI[] =
{
    _CAPABILITIES_STRING_HDMI
};
#endif

#if(_DP_PORT_EXIST == _ON)
unsigned char code tCP_STRING_DP[] =
{
    _CAPABILITIES_STRING_DP
};
#endif


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucDdcciRxBuf[_DDCCI_RXBUF_LENGTH] = {0};
BYTE g_ucDdcciTxBuf[_DDCCI_TXBUF_LENGTH] = {0};


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserCommonDdcciHandler(void);
void UserCommonDdcciInitTx(void);
void UserCommonDdcciInitRx(void);
BYTE UserCommonDdcciCalCheckSum(void);
void UserCommonDdcciSetVCPReplyValue(BYTE ucTypeOpcode, WORD usMax, WORD usPresent);
void UserCommonDdcciGetTimingReport(void);
void UserCommonDdcciGetCapabilitiesRequest(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : User Common DDC Handler Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciHandler(void)
{
    
#if(_DDCCI_AUTO_SWITCH_SUPPORT == _ON)
    if(GET_RUN_DDCCI_COMMAND() == _FAIL)
    {
        // Enable DDCCI Channel Auto Switch
        if(GET_DDCCI_AUTO_SWITCH() == _FALSE)
        {
            SET_DDCCI_AUTO_SWITCH();
        }
    }
#endif

    UserDdcciHandler();
}
//--------------------------------------------------
// Description  : Initial TX variables and Send Null-Message
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciInitTx(void)
{
    // Send Null-Message
    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG;
    g_ucDdcciTxBuf[_DDCCI_COMMAND] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}

//--------------------------------------------------
// Description  : Initial RX variables
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciInitRx(void)
{
    // Clear buffer for new message
    memset(g_ucDdcciRxBuf, 0, _DDCCI_RXBUF_LENGTH);
}

//--------------------------------------------------
// Description  : Caculate checksum
// Input Value  : None
// Output Value : ucSum --> Checksum value
//--------------------------------------------------
BYTE UserCommonDdcciCalCheckSum(void)
{
    BYTE ucCount = 0;
    BYTE ucCheckLen = 0;
    BYTE ucSum = _DDCCI_VIRTUAL_HOST_ADDRESS;

    ucCheckLen = (g_ucDdcciTxBuf[_DDCCI_LENGTH] & 0x7F) + 2;

    for(ucCount = 0; ucCount < ucCheckLen; ucCount++)
    {
        ucSum = ucSum ^ g_ucDdcciTxBuf[ucCount];
    }

    return ucSum;
}

//--------------------------------------------------
// Description  : DDCCI VCP Feature Reply Max and Present Value
// Input Value  : ucOpcode --> OPCODE
//                  usMax --> Maximum Value
//                  usPresent --> Present Value
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciSetVCPReplyValue(BYTE ucTypeOpcode, WORD usMax, WORD usPresent)
{
    g_ucDdcciTxBuf[_DDCCI_TYPE_CODE] = ucTypeOpcode;
    g_ucDdcciTxBuf[_DDCCI_MAX_HIGH_BYTE] = HIBYTE(usMax);
    g_ucDdcciTxBuf[_DDCCI_MAX_LOW_BYTE] = LOBYTE(usMax);
    g_ucDdcciTxBuf[_DDCCI_PRESENT_HIGH_BYTE] = HIBYTE(usPresent);
    g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE] = LOBYTE(usPresent);
}

//--------------------------------------------------
// Description  : DDCCI Get and Reply Timing Report
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciGetTimingReport(void)
{
    BYTE ucPolarity = 0;

    ucPolarity = (GET_INPUT_TIMING_H_POLARITY() | (GET_INPUT_TIMING_V_POLARITY() << 1));

    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_TIMING_MSG_COMMAND] = _DDCCI_CMD_REPLY_TIMING_MESSAGE;
    g_ucDdcciTxBuf[_DDCCI_TIMING_MSG_OPCODE] = _DDCCI_OPCODE_TIMING_MSG;
    g_ucDdcciTxBuf[_DDCCI_TIMING_STATUS] = 0x00;

    // H sync pol :Bit 1 = 1:positive H-sync polarity
    if((bit)(ucPolarity & _BIT0))
    {
        g_ucDdcciTxBuf[_DDCCI_TIMING_STATUS] |= _BIT1;                                              
    }
    
    // V sync pol :Bit 0 = 1:positive V-sync polarity
    if((bit)(ucPolarity & _BIT1))
    {
        g_ucDdcciTxBuf[_DDCCI_TIMING_STATUS] |= _BIT0;                                              
    }

    g_ucDdcciTxBuf[_DDCCI_TIMING_HFREQ_HBYTE] = HIBYTE(GET_INPUT_TIMING_HFREQ() * 10);
    g_ucDdcciTxBuf[_DDCCI_TIMING_HFREQ_LBYTE] = LOBYTE(GET_INPUT_TIMING_HFREQ() * 10);
    g_ucDdcciTxBuf[_DDCCI_TIMING_VFREQ_HBYTE] = HIBYTE(GET_INPUT_TIMING_VFREQ() * 10);
    g_ucDdcciTxBuf[_DDCCI_TIMING_VFREQ_LBYTE] = LOBYTE(GET_INPUT_TIMING_VFREQ() * 10);
    g_ucDdcciTxBuf[_DDCCI_TIMING_VFREQ_LBYTE + 1] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}

//--------------------------------------------------
// Description  : DDCCI Capabilities Request & Reply
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDdcciGetCapabilitiesRequest(void)
{
    WORD usOffset = 0;
    BYTE ucSendLen = 0;
    BYTE ucCount = 0;
    BYTE ucInputPort = 0;
    
    usOffset = ((((WORD)g_ucDdcciRxBuf[_DDCCI_OFS_HIGH_BYTE]) << 8) & 0xFF00) | (g_ucDdcciRxBuf[_DDCCI_OFS_LOW_BYTE]);

    switch(GET_DDCCI_ACTIVE_CHANNEL())
    {
        case _DDC1:
            
            ucInputPort = _A0_INPUT_PORT;
            break;
            
        case _DDC2:

#if(_D0_DDC_CHANNEL_SEL == _DDC2)
            ucInputPort = _D0_INPUT_PORT;
#elif(_D1_DDC_CHANNEL_SEL == _DDC2)
            ucInputPort = _D1_INPUT_PORT;
#endif
            break;
            
        case _DDC3:

#if(_D0_DDC_CHANNEL_SEL == _DDC3)
            ucInputPort = _D0_INPUT_PORT;
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
            ucInputPort = _D1_INPUT_PORT;
#endif
            break;

        default:
            
            ucInputPort = _NO_INPUT_PORT;
            break;
    }

#if(_VGA_PORT_EXIST == _ON)
    if(ucInputPort == _A0_INPUT_PORT)
    {
        if(usOffset >= _CREQLEN_DSUB)
        {
            ucSendLen = 0;
        }
        else if(_CREQLEN_DSUB > (usOffset + ScalerMcuDdcciGetBufferSize() - 6))
        {
            ucSendLen = ScalerMcuDdcciGetBufferSize() - 6;
        }
        else
        {
            ucSendLen = _CREQLEN_DSUB - usOffset;
        }
    }
#endif

#if(_DVI_PORT_EXIST == _ON)
    if(((ucInputPort == _D0_INPUT_PORT) && (_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)) || \
        ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)))
    {
        if(usOffset >= _CREQLEN_DVI)
        {
            ucSendLen = 0;
        }
        else if(_CREQLEN_DVI > (usOffset + ScalerMcuDdcciGetBufferSize() - 6))
        {
            ucSendLen = ScalerMcuDdcciGetBufferSize() - 6;
        }
        else
        {
            ucSendLen = _CREQLEN_DVI - usOffset;
        }
    }
#endif

#if(_HDMI_PORT_EXIST == _ON)
    if(((ucInputPort == _D0_INPUT_PORT) && (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)) || \
        ((ucInputPort == _D0_INPUT_PORT) && (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) || \    
        ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)) || \
        ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) || \
        ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)))
    {
        if(usOffset >= _CREQLEN_HDMI)
        {
            ucSendLen = 0;
        }
        else if(_CREQLEN_HDMI > (usOffset + ScalerMcuDdcciGetBufferSize() - 6))
        {
            ucSendLen = ScalerMcuDdcciGetBufferSize() - 6;
        }
        else
        {
            ucSendLen = _CREQLEN_HDMI - usOffset;
        }
    }
#endif

#if(_DP_PORT_EXIST == _ON)
    if(((ucInputPort == _D0_INPUT_PORT) && (_D0_INPUT_PORT_TYPE == _D0_DP_PORT)) || \
        ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DP_PORT)) || \ 
        ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_DP))) 
    {
        if(usOffset >= _CREQLEN_DP)
        {
            ucSendLen = 0;
        }
        else if(_CREQLEN_DP > (usOffset + ScalerMcuDdcciGetBufferSize() - 6))
        {
            ucSendLen = ScalerMcuDdcciGetBufferSize() - 6;
        }

        else
        {
            ucSendLen = _CREQLEN_DP - usOffset;
        }
    }
#endif

    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | (ucSendLen + 3);
    g_ucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_CAPABILITIES_REQUEST_REPLY;
    g_ucDdcciTxBuf[_DDCCI_OFS_HIGH_BYTE] = g_ucDdcciRxBuf[_DDCCI_OFS_HIGH_BYTE];
    g_ucDdcciTxBuf[_DDCCI_OFS_LOW_BYTE] = g_ucDdcciRxBuf[_DDCCI_OFS_LOW_BYTE];

    for(ucCount = 0; ucCount < ucSendLen; ucCount++)
    {

#if(_VGA_PORT_EXIST == _ON)
        if(ucInputPort == _A0_INPUT_PORT)
        {
            g_ucDdcciTxBuf[_DDCCI_OFS_LOW_BYTE + 1 + ucCount] = tCP_STRING_DSUB[ucCount + usOffset];
        }
#endif

#if(_DVI_PORT_EXIST == _ON)
        if(((ucInputPort == _D0_INPUT_PORT) && (_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)) || \
            ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)))
        {
            g_ucDdcciTxBuf[_DDCCI_OFS_LOW_BYTE + 1 + ucCount] = tCP_STRING_DVI[ucCount + usOffset];
        }
#endif

#if(_HDMI_PORT_EXIST == _ON)
        if(((ucInputPort == _D0_INPUT_PORT) && (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)) || \
            ((ucInputPort == _D0_INPUT_PORT) && (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) || \    
            ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)) || \
            ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) || \
            ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_TMDS)))
        {
            g_ucDdcciTxBuf[_DDCCI_OFS_LOW_BYTE + 1 + ucCount] = tCP_STRING_HDMI[ucCount + usOffset];
        }
#endif

#if(_DP_PORT_EXIST == _ON)
        if(((ucInputPort == _D0_INPUT_PORT) && (_D0_INPUT_PORT_TYPE == _D0_DP_PORT)) || \
            ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DP_PORT)) || \ 
            ((ucInputPort == _D1_INPUT_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT) && (GET_D1_DP_DUAL_STATUS() == _DP_DUAL_MODE_DP))) 
        {
            g_ucDdcciTxBuf[_DDCCI_OFS_LOW_BYTE + 1 + ucCount] = tCP_STRING_DP[ucCount + usOffset];
        }
#endif

    }

    g_ucDdcciTxBuf[_DDCCI_OFS_LOW_BYTE + 1 + ucSendLen] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}
