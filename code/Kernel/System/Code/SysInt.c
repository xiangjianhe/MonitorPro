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
// ID Code      : SysInt.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define __SYSTEM_INT__

#include "SysInclude.h"

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void SysEXINT0(void);
void SysEXINT1(void);
void SysUartSerialPortIntProc(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Interrupt 0 Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysEXINT0(void)    interrupt 0 using 1
{
#if(_PANEL_EMBEDDED_LED_DRIVER_SUPPORT == _ON)
    ScalerELEDIntHandler_EXINT0();
#endif

#if(_DP_SUPPORT == _ON)
    ScalerDpIntHandler_EXINT0();
#endif

#if(_DISPLAY_PREVENT_GARBAGE_METHOD == _GARBAGE_PREVENT_BY_BACKLIGHT)
    ScalerGlobalPreventGarbageByBacklight_EXINT0();
#endif

#if(_MHL_SUPPORT == _ON)
    ScalerMHLIntHandler_EXINT0();
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
    ScalerTmdsIntHandler_EXINT0();
#endif

#if((_OD_SUPPORT == _ON) && ((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON)))
    ScalerODIntHandler_EXINT0();
#endif

#if((_3D_SUPPORT == _ON) && (_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES))
    Scaler3DIntHandler_EXINT0();
#endif

}

//--------------------------------------------------
// Description  : Interrupt 1 Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysEXINT1(void)    interrupt 2 using 2
{
#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))    
    if(((bit)ScalerTmdsDdcDetect_EXINT1() == _TRUE))
    {
        if(GET_POWER_STATUS() == _POWER_STATUS_SAVING)
        {
            if((bit)ScalerSyncPSRecover_EXINT1() == _TRUE)
            {
                g_bSysPSIntDetect = _TRUE;
            }
        }       
    }
#endif    

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
    ScalerDebugIntProc_EXINT1();
#else
    if((bit)UserInterfaceGetDdcciStatus_EXINT1() == _ON)
    {
        UserCommonInterfaceDdcciIntGetData_EXINT1();
    }
    else
    {
        ScalerDebugIntProc_EXINT1();
    }
#endif
}

//--------------------------------------------------
// Description  : Serial Port0 Interrupt Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysUartSerialPortIntProc(void)    interrupt 4
{
#if(_UART_SUPPORT == _ON)
    if(GET_UART_TRANSMIT_STATUS() == _TRUE)
    {
        CLR_UART_TRANSMIT_STATUS();
    }
    
    UserInterfaceUartIntHandler_SERIALPORT();
#endif
}

