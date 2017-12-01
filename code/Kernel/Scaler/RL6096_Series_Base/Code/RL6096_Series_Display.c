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
// ID Code      : RL6096_Series_Audio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6096_SERIES_DISPLAY__

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
void ScalerDisplayInitialTable(void);
void ScalerDisplayLvdsPower(bit bOn);
void ScalerDisplayLvdsPLL(bit bOn);
void ScalerDisplayLvdsDrivingControl(BYTE ucData, BYTE ucClock);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Initial Settings for Display Interface
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDisplayInitialTable(void)
{    
#if(_PANEL_STYLE == _PANEL_LVDS)
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, 0x01);

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A2_TCON_LVDS_CTRL2, 0x43);
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, 0x9C);
    
#if(_LVDS_TABLE_TYPE == _LVDS_BIT_MAP_TABLE_1)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), (_LVDS_MIRROR << 6));
#elif(_LVDS_TABLE_TYPE == _LVDS_BIT_MAP_TABLE_2)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), ((_LVDS_MIRROR << 6) | _BIT0));
#endif

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A4_TCON_LVDS_CTRL4, 0x80);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A5_TCON_LVDS_CTRL5, 0x80);
    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT7, (_LVDS_PN_SWAP << 7));    
#endif    

    // Display Signal Control Settings
#if(_DISP_BIT_MODE == _DISP_18_BIT)      
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT4, _BIT4);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~_BIT1, 0x00);    
#elif(_DISP_BIT_MODE == _DISP_24_BIT)
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT4, 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~_BIT1, 0x00);
#elif(_DISP_BIT_MODE == _DISP_30_BIT)
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT4, 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~_BIT1, _BIT1);
#endif

    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, (_DISP_OUTPUT_PORT << 2));    
    ScalerSetByte(CM_29_VDISP_SIGINV, ((_DHS_MASK << 7) | (_LVDS_EO_SWAP << 6) | (_LVDS_RB_SWAP << 5) | (_LVDS_ML_SWAP << 4) | (_DISP_SKEW << 3) | (_LVDS_DVS_INVERT << 2) | (_LVDS_DHS_INVERT << 1) | (_LVDS_DEN_INVERT)));
    
    // Set LVDS Driving Control
    ScalerDisplayLvdsDrivingControl(_LVDS_DATA_DRIV_CONTROL, _LVDS_CLK_DRIV_CONTROL);

    // Set LVDS/mLVDS common mode Voltage
#if(_LVDS_VCM_CONTROL == _LVDS_VCM_LOW)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_NORMAL)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), 0x03);
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_HIGH)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), 0x07);
#endif 

    // Set LVDS/mLVDS capacitor slew rate control
#if(_LVDS_CAP_CONTROL == _DISABLE)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#elif(_LVDS_CAP_CONTROL == _ENABLE)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x1E);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x1E);
#endif

    // Set LVDS/mLVDS resistor slew rate control
#if(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_0)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT6 | _BIT5), _LVDS_SR_CONTROL_0 << 5);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~(_BIT6 | _BIT5), _LVDS_SR_CONTROL_0 << 5);
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_1)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT6 | _BIT5), _LVDS_SR_CONTROL_1 << 5);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~(_BIT6 | _BIT5), _LVDS_SR_CONTROL_1 << 5);
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_2)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT6 | _BIT5), _LVDS_SR_CONTROL_2 << 5);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~(_BIT6 | _BIT5), _LVDS_SR_CONTROL_2 << 5);
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_3)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT6 | _BIT5), _LVDS_SR_CONTROL_3 << 5);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~(_BIT6 | _BIT5), _LVDS_SR_CONTROL_3 << 5);
#endif
}

//--------------------------------------------------
// Description  : LVDS Power Control
// Input Value  : _ON or _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPower(bit bOn)
{
    if(bOn == _ON)
    {
        // Power Up LVDS Block       
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0), (_BIT7 | _BIT5 | _BIT4));
    }
    else
    {
        // Power Down LVDS Block
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0), 0x00);
    }
}

//--------------------------------------------------
// Description  : LVDS PLL(Data) Power Control
// Input Value  : _ON or _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsPLL(bit bOn)
{
    if(bOn == _ON)
    {
        // Power Up LVDS PLL
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT0, _BIT0);      
    }
    else
    {
        // Power Down LVDS PLL
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT0, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set LVDS driving control
// Input Value  : Driving current for Data and Clock pair
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsDrivingControl(BYTE ucData, BYTE ucClock)
{
#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)

#if(_LVDS_EO_CLK_MERGE == _DISABLE)

    // Disable LVDS CLK double current
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT1, 0x00);

#elif(_LVDS_EO_CLK_MERGE == _ENABLE) 

    // Enable LVDS CLK double current
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT1, _BIT1);

#endif

#elif(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT)

    // Disable LVDS CLK double current
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT1, 0x00);

#endif

    ScalerSetBit(P10_B3_PIN_DRIVING_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((BYTE)ucData << 2) | (BYTE)ucClock);
}

