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
// ID Code      : RL6297_Series_Power.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6297_SERIES_POWER__

#include "ScalerFunctionInclude.h"


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
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
void ScalerPowerGDIIsolation(BYTE ucOn);
void ScalerPowerTopIsolation(BYTE ucOn);
void ScalerPowerAnalogIsolation(BYTE ucOn);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : GDI/SRAM Power Isolation ON(Low Power) or OFF
// Input Value  : ON --> Power Cut(Low Power) ; OFF --> Normal Operation
// Output Value : None
//--------------------------------------------------
void ScalerPowerGDIIsolation(BYTE ucOn)
{
    BYTE ucCnt = 0x00;
        
    if(ucOn == _ON)
    {           
        // GDI isolation
        ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT1, _BIT1);

        // Weak power off
        ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT4, 0x00);

        // Strong power off
        ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT5, 0x00);
    }
    else        
    {    
        if(ScalerGetBit(CM_0A_POWER_CTRL1, _BIT1) == _BIT1)
        {
            // Weak power on
            ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT4, _BIT4);

            // Wait for weak power on flag
            pData[0] = 200;
            
            while((ScalerGetBit(CM_0A_POWER_CTRL1, _BIT6) != _BIT6) && (pData[0]-- > 0));

            // Strong power on    
            ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT5, _BIT5);

            // Wait for strong power on flag
            pData[0] = 200;
            
            while((ScalerGetBit(CM_0A_POWER_CTRL1, _BIT7) != _BIT7) && (pData[0]-- > 0));              

            // Block Reset
            ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT0, _BIT0);

            // Waiting for GDI put cut reset finish.
            for(ucCnt = 0; ucCnt <= 5; ucCnt++)
            {
                _nop_();    
            }

            // Block Normal
            ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT0, 0x00);

            // GDI Normal Operation mode.
            ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT1, 0x00);
        }        
    }
}

//--------------------------------------------------
// Description  : Power Isolation Setting For Top Module.
// Input Value  : ucOn    --> On/Off Select.
// Output Value : None
//--------------------------------------------------
void ScalerPowerTopIsolation(BYTE ucOn)
{
    BYTE ucCnt = 0;
    
    if(ucOn == _ON)
    {
        // Top Power isolation
        ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT1, _BIT1);

        // Top Weak power off
        ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT4, 0x00);

        // Top Strong power off
        ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT5, 0x00);
    }
    else
    {
        // Top Block Power Cut
        if(ScalerGetBit(CM_09_POWER_CTRL0,  _BIT1) == _BIT1)
        {            
            // Weak power on
            ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT4, _BIT4);

            // Wait for weak power on flag  
            pData[0] = 200;
            
            while((ScalerGetBit(CM_09_POWER_CTRL0, _BIT6) != _BIT6) && (pData[0]-- > 0));    

            // Strong power on
            ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT5, _BIT5);

            // Wait for strong power on flag
            pData[0] = 200;
            
            while((ScalerGetBit(CM_09_POWER_CTRL0, _BIT7) != _BIT7) && (pData[0]-- > 0));

            // Block Reset
            ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT0, _BIT0);

            // Waiting for reset finish.
            for(ucCnt = 0; ucCnt <= 5; ucCnt++)
            {
                _nop_();    
            }

            // Normal Mode
            ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT0, 0x00);

            // Top Normal Operation
            ScalerSetBit(CM_09_POWER_CTRL0, ~_BIT1, 0x00);
        }
    }
}

//--------------------------------------------------
// Description  : Power Isolation Setting For Analog Module.
// Input Value  : ucOn    --> On/Off Select.
// Output Value : None
//--------------------------------------------------
void ScalerPowerAnalogIsolation(BYTE ucOn)
{
    BYTE ucCnt = 0;
    
    if(ucOn == _ON)
    {
        // Analog Block Power Cut
        // Analog block(LVDS PLL only) isolation
        ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT2, _BIT2);
    }
    else
    {
        // Analog Block Power Cut
        if(ScalerGetBit(CM_0A_POWER_CTRL1,  _BIT2) == _BIT2)
        {            
            // Analog Block(LVDS PLL only) Normal Operation
            ScalerSetBit(CM_0A_POWER_CTRL1, ~_BIT2, 0x00);
        }
    }
}

