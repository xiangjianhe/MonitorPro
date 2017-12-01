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
// ID Code      : RL6192_Series_Audio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6192_SERIES_DISPLAY__

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
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, 0xA8);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_05_TCON_LINE_THRESHOLD, 0xF0);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, 0x36);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, 0x30);
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, 0x9C);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_10_LVDS_CTRL31, 0x71);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_11_LVDS_CTRL32, 0x49);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_12_LVDS_CTRL33, 0xC0);

    // Set PI Phase 4
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x6F);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x6F);    

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_18_LVDS_CTRL39, 0x00);    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_19_LVDS_CTRL40, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1A_LVDS_CTRL41, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A2_TCON_LVDS_CTRL2, 0x13);
    
#if(_LVDS_TABLE_TYPE == _LVDS_BIT_MAP_TABLE_1)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), (_LVDS_MIRROR << 6));
#elif(_LVDS_TABLE_TYPE == _LVDS_BIT_MAP_TABLE_2)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT6 | _BIT0), ((_LVDS_MIRROR << 6) | _BIT0));
#endif

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A4_TCON_LVDS_CTRL4, 0x80);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A5_TCON_LVDS_CTRL5, 0x80);
    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~_BIT7, (_LVDS_PN_SWAP << 7));    

    ScalerSetDataPortBit(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_20_DISP_DIS_TIMING, ~_BIT0, _BIT0);
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
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), 0x05);
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_HIGH)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), 0x07);
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
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT7 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0), (_BIT7 | _BIT5 | _BIT4 | _BIT3)); 
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
    switch(ucData)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT7 | _BIT6), _BIT6);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT7 | _BIT6), 0x00);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT7 | _BIT6), _BIT6);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT7 | _BIT6), _BIT7);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
            
            break;

        default:

            break;
    }

    switch(ucClock)
    {
#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)
        
#if(_LVDS_EO_CLK_MERGE == _DISABLE)

        case _LVDS_DRIV_CONTROL_2_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT4 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT4 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
            
            break;

        default:

            break;

#elif(_LVDS_EO_CLK_MERGE == _ENABLE) 

        case _LVDS_DRIV_CONTROL_2_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT4 | _BIT3 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT4 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT4 | _BIT3 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3); 
            
            break;

        default:

            break;
#endif

#elif(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT)

        case _LVDS_DRIV_CONTROL_2_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT4 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT4 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
            
            break;

        default:

            break;
#endif
    }
}
