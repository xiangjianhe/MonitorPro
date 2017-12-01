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
//**********************************************************************************************************

//----------------------------------------------------------------------------------------------------
// ID Code      : NoneFactoryFunction.c No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------
#define __FACTORY_FUNCTION__

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


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

#if(_FACTORY_RTD_QC_SUPPORT == _ON)
void NoneFactoryQCFlow(BYTE ucInputPort);
bit NoneFactoryQCNextPort(BYTE ucInputPort);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#if(_FACTORY_RTD_QC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Contain Full QC Main Test Flow
// Input Value  : ucInputPort => Current Test Input Port
// Output Value : None
//--------------------------------------------------
void NoneFactoryQCFlow(BYTE ucInputPort)
{
    static bit bTestFinished;
    static BYTE ucA0PortResult;
    static BYTE ucD0PortResult;
    static BYTE ucD1PortResult;
    static BYTE ucAudioResult;    

    if(bTestFinished == _FALSE)
    {
        ScalerGlobalWatchDog(_DISABLE);

        // Disable All Digital Function
        ScalerQCAllDigitalFunctionDisable();        
        
        switch(ucInputPort)
        {

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
            case _A0_INPUT_PORT:

                ucA0PortResult = ScalerQCA0PortTest();
                DebugMessageOsd("6. A0 Port Test Results", ucA0PortResult);
                
                break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
            case _D0_INPUT_PORT:

                ucD0PortResult = ScalerQCD0PortTest();
                DebugMessageOsd("6. D0 Port Test Results", ucD0PortResult);                

                break;
#endif


#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            case _D1_INPUT_PORT:

                ucD1PortResult = ScalerQCD1PortTest();
                DebugMessageOsd("6. D1 Port Test Results", ucD1PortResult);

#if(_AUDIO_SUPPORT == _ON)
                ucAudioResult = ScalerQCAudioTest();
                DebugMessageOsd("6. Audio Test Results", ucAudioResult);
                break;
#endif

#endif
            default:
                break;
        }
            
        // Finished Show Result
        if(NoneFactoryQCNextPort(ucInputPort) == _FALSE)
        { 
            DebugMessageOsd("6. A0 Port Test Results", ucA0PortResult);            
            DebugMessageOsd("6. D0 Port Test Results", ucD0PortResult);                                
            DebugMessageOsd("6. D1 Port Test Results", ucD1PortResult);
            DebugMessageOsd("6. Audiot Test Results", ucAudioResult);
            
            bTestFinished = _TRUE;

            PCB_LED_ON();

            ScalerTimerDelayXms(300);
            
            PCB_LED_OFF();
            
            ScalerTimerDelayXms(300);
            
            PCB_LED_TYPE5();

            if((bit)ucA0PortResult == _TRUE)
            {
                PCB_LED_TYPE1();
            }
            
            if((bit)ucD0PortResult == _TRUE)
            {
                PCB_LED_TYPE2();
            }
            
            if((bit)ucD1PortResult == _TRUE)
            {
                PCB_LED_TYPE3();
            }        
            
            if((bit)ucAudioResult == _TRUE)
            {
                PCB_LED_TYPE4();
            }                    
        }
    }    
}

//--------------------------------------------------
// Description  : Switch to Next Port for test
// Input Value  : ucInputPort => Current Test Input Port
// Output Value : _FALSE => No Further port should be tested
//--------------------------------------------------
bit NoneFactoryQCNextPort(BYTE ucInputPort)
{
    BYTE ucInitialPort;
    BYTE ucTemp = 0;

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    ucInitialPort = _A0_INPUT_PORT;
#elif(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    ucInitialPort = _D0_INPUT_PORT;
#elif(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    ucInitialPort = _D1_INPUT_PORT;
#else
    ucInitialPort = _A0_INPUT_PORT;
#endif

    DebugMessageOsd("0. Current Port =", ucInputPort);

    for(pData[0] = 1; pData[0] <= 6; pData[0]++)
    {
        ucInputPort = (ucInputPort + 1) % 6;
        switch(ucInputPort)
        {
            case _D0_INPUT_PORT:
                if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                {
                    pData[0] = 7;
                }
                break;
            case _D1_INPUT_PORT:
                if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
                {
                    pData[0] = 7;
                }
                break;
            case _A0_INPUT_PORT:
                if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
                {
                    pData[0] = 7;
                }
                break;
            default:
                break;
        }
    }

    DebugMessageOsd("0. Next Port =", ucInputPort);

    if(ucInputPort == ucInitialPort)
    {
        DebugMessageOsd("0. Test Finished", ucInputPort);
        return _FALSE;
    }

    SysSourceSwitchInputPort(ucInputPort);
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
        
    return _TRUE;
}
#endif
