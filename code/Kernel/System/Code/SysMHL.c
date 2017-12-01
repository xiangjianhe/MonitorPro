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
// ID Code      : SysMHL.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_MHL__

#include "SysInclude.h"

#if(_MHL_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of MHL RAP SubCommands
//--------------------------------------------------
typedef enum
{
    _MSC_RCP_NO_ERROR = 0x00,
    _MSC_RCP_INEFFECTIVE_CODE,
    _MSC_RCP_RESPONDER_BUSY,
} EnumMHLMscErrorCode;

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysMHLMscHandler(void);

//--------------------------------------------------
// Description  : MHL Handler Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysMHLMscHandler(void)
{
    BYTE pucKeyCode = 0;

    if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        ScalerMHLCBUSPhySwitch(_D0_INPUT_PORT, _ON);
    }

    if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        ScalerMHLCBUSPhySwitch(_D1_INPUT_PORT, _ON);
    }
    
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)    
    if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        if(ScalerMHLMscHandler(_D0_INPUT_PORT, SysSourceGetInputPort(), GET_MODE_STATE()) == _TRUE)
        {
            ///////////////
            //RAP Handler//
            ///////////////
            if(ScalerMHLMscRAPHandler(_D0_INPUT_PORT) == _FALSE)
            {
                if(SysSourceGetSourceType() != _SOURCE_NONE)
                {
                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);
                }
            }

            ///////////////
            //RCP Handler//
            ///////////////
            if(ScalerMHLMscRCPGetCommand(_D0_INPUT_PORT, &pucKeyCode) == _TRUE)
            {
                if(UserInterfaceMHLMscRCPProc(pucKeyCode) == _FALSE)
                {
                    ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_RCPE, _MSC_RCP_INEFFECTIVE_CODE);
                }

                ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_RCPK, pucKeyCode);
            }

            ///////////////
            //UCP Handler//
            ///////////////
#if(_MHL_UCP_SUPPORT == _ON)
            if(ScalerMHLMscUCPGetCommand(_D0_INPUT_PORT, &pucKeyCode) == _TRUE)
            {
                pucKeyCode[1] = 0;
                DebugMessageSystem(pucKeyCode, pucKeyCode[0]);
                ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_UCPK, pucKeyCode);
            }
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)
        }

        /////////////////////////
        //Check SET_INT Process//
        /////////////////////////
        ScalerMHLMscCheckDeviceINT(_D0_INPUT_PORT);
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)    
    if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        if(ScalerMHLMscHandler(_D1_INPUT_PORT, SysSourceGetInputPort(), GET_MODE_STATE()) == _TRUE)
        {
            ///////////////
            //RAP Handler//
            ///////////////
            if(ScalerMHLMscRAPHandler(_D1_INPUT_PORT) == _FALSE)
            {
                if(SysSourceGetSourceType() != _SOURCE_NONE)
                {
                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);
                }
            }

            ///////////////
            //RCP Handler//
            ///////////////
            if(ScalerMHLMscRCPGetCommand(_D1_INPUT_PORT, &pucKeyCode) == _TRUE)
            {
                if(UserInterfaceMHLMscRCPProc(pucKeyCode) == _FALSE)
                {
                    ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_RCPE, _MSC_RCP_INEFFECTIVE_CODE);
                }

                ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_RCPK, pucKeyCode);
            }

#if(_MHL_UCP_SUPPORT == _ON)
            ///////////////
            //UCP Handler//
            ///////////////
            if(ScalerMHLMscUCPGetCommand(_D1_INPUT_PORT, &pucKeyCode) == _TRUE)
            {
                pucKeyCode[1] = 0;
                DebugMessageSystem(pucKeyCode, pucKeyCode[0]);
                ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_UCPK, pucKeyCode);
            }
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)
        }
        
        /////////////////////////
        //Check SET_INT Process//
        /////////////////////////
        ScalerMHLMscCheckDeviceINT(_D1_INPUT_PORT);
    }
#endif

}

#endif // End of #if(_MHL_SUPPORT == _ON)
