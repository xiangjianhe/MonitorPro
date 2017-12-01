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
// ID Code      : RL6229_Series_Audio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6229_SERIES_DISPLAY__

#include "ScalerFunctionInclude.h"

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
void ScalerDisplayInitialTable(void);
void ScalerDisplayLvdsPower(bit bOn);
void ScalerDisplayLvdsPLL(bit bOn);
void ScalerDisplayLvdsDrivingControl(BYTE ucData, BYTE ucClock);

#if(((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON)) || (_OD_SUPPORT == _ON))
void ScalerDisplaySelectDVFMode(void);
#endif

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
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, 0x56);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_05_TCON_LINE_THRESHOLD, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, 0x36);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, 0x30);
    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, 0x84);

#if((_LVDS_EA_PHASE + _LVDS_EB_PHASE + _LVDS_EC_PHASE + _LVDS_ED_PHASE + _LVDS_EE_PHASE + _LVDS_EF_PHASE + _LVDS_EG_PHASE + _LVDS_OA_PHASE + _LVDS_OB_PHASE + _LVDS_OC_PHASE + _LVDS_OD_PHASE + _LVDS_OE_PHASE) != 0x00)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
#else
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0F_LVDS_CTRL30, ~(_BIT4 | _BIT3), 0x00);
#endif

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_10_LVDS_CTRL31, 0x71);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_11_LVDS_CTRL32, 0x49);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_12_LVDS_CTRL33, 0xC0);

#if(_LVDS_PHASE_SELECT == _LVDS_PHASE0)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x30);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x30);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE1)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x31);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x31);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE2)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x33);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x33);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE3)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x37);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x37);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE4)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x6F);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x6F);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE5)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x6E);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x6E);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE6)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x6C);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x6C);
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE7)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x68);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x68);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE8)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0xC0);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0xC0);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE9)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0xC1);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0xC1);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE10)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0xC3);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0xC3);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE11)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0xC7);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0xC7);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE12)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x8F);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x8F);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE13)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x8E);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x8E);    
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE14)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x8C);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x8C);
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE15)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x88);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x88);
#elif(_LVDS_PHASE_SELECT == _LVDS_PHASE16)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x03);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36, 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x03);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x00);
#else
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_14_LVDS_CTRL35, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_15_LVDS_CTRL36,   0x30);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_16_LVDS_CTRL37, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);    
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_17_LVDS_CTRL38, 0x30);
#endif

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_18_LVDS_CTRL39, 0x00);    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_19_LVDS_CTRL40, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), ((_LVDS_EA_PHASE << 7) | (_LVDS_EB_PHASE << 6) | (_LVDS_EC_PHASE << 5) | (_LVDS_ED_PHASE << 4) | (_LVDS_EE_PHASE << 3)| (_LVDS_EF_PHASE << 2)| (_LVDS_EG_PHASE << 1)));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1A_LVDS_CTRL41, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), ((_LVDS_OA_PHASE << 7) | (_LVDS_OB_PHASE << 6) | (_LVDS_OC_PHASE << 5) | (_LVDS_OD_PHASE << 4) | (_LVDS_OE_PHASE << 3)));

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
#if(_DISP_BIT_MODE == _DISP_30_BIT)
    ScalerDisplayLvdsDrivingControl(_LVDS_DATA_DRIV_CONTROL, _LVDS_DATA_DRIV_CONTROL);
#elif((_DISP_BIT_MODE == _DISP_18_BIT) || (_DISP_BIT_MODE == _DISP_24_BIT))
    ScalerDisplayLvdsDrivingControl(_LVDS_DATA_DRIV_CONTROL, _LVDS_CLK_DRIV_CONTROL);
#endif

    // Set LVDS/mLVDS common mode Voltage
#if(_LVDS_VCM_CONTROL == _LVDS_VCM_LOW)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_NORMAL)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), 0x04);
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_HIGH)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT2 | _BIT1 | _BIT0), 0x07);
#endif

    // Set LVDS/mLVDS capacitor slew rate control
#if(_LVDS_CAP_CONTROL == _DISABLE)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0D_TCON_TCON0_HE_LSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0E_TCON_TCON0_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#elif(_LVDS_CAP_CONTROL == _ENABLE)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0D_TCON_TCON0_HE_LSB, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_0E_TCON_TCON0_CTRL, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
#endif

    // Set LVDS data slew rate control
#if(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_0)     
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_24_LVDS_CTRL49, 0x00, 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_25_LVDS_CTRL50, 0x00, 0x00);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1C_LVDS_CTRL43, 0x00, 0xFF);
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_1)   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_24_LVDS_CTRL49, 0x00, 0xFF);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_25_LVDS_CTRL50, 0x00, 0xFF);    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1C_LVDS_CTRL43, 0x00, 0x00);
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_2)   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_24_LVDS_CTRL49, 0x00, 0x55);           
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_25_LVDS_CTRL50, 0x00, 0x55);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1C_LVDS_CTRL43, 0x00, 0x00);
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_3)   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_24_LVDS_CTRL49, 0x00, 0xAA);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_25_LVDS_CTRL50, 0x00, 0xAA);
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1C_LVDS_CTRL43, 0x00, 0x00);
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
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

    	// Disable Weakly Pull Down
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A9_TCON_LVDS_CTRL9, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
        
    }
    else
    {
    	// Enable Weakly Pull Down
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A9_TCON_LVDS_CTRL9, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

        // Power Down LVDS Block
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0), 0x00);
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
#if(_LVDS_TERMINATION_CONTROL == _ENABLE)

#if(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT)

#if(_LVDS_EO_SWAP == _DISABLE)

    // Set LVDS Even Port Output Termination Enable
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1B_LVDS_CTRL42, 0x44);

#elif(_LVDS_EO_SWAP == _ENABLE)

    // Set LVDS Odd Port Output Termination Enable
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1B_LVDS_CTRL42, 0x11);

#endif

#elif(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)

    // Set LVDS Even/Odd Port Output Termination Enable
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1B_LVDS_CTRL42, 0x55);

#endif
    
    switch(ucData)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT7 | _BIT6), _BIT7);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT7 | _BIT6), _BIT7 | _BIT6);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT7 | _BIT6), _BIT6);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3);
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT7 | _BIT6), _BIT7);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3);
            
            break;

        default:

            break;
    }

    switch(ucClock)
    {
#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)
        
#if(_LVDS_EO_CLK_MERGE == _DISABLE)

        case _LVDS_DRIV_CONTROL_2_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT4 | _BIT3 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT4 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3); 
            
            break;

        default:

            break;

#elif(_LVDS_EO_CLK_MERGE == _ENABLE)

        case _LVDS_DRIV_CONTROL_2_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3);
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT4 | _BIT3 | _BIT2);

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
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4);
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT4 | _BIT3 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT4 | _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3); 
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT5 | _BIT3);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_06_LVDS_CTRL21, ~(_BIT2 | _BIT1 | _BIT0), _BIT2 | _BIT1 | _BIT0);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_07_LVDS_CTRL22, ~(_BIT5 | _BIT4 | _BIT3), _BIT5 | _BIT4 | _BIT3); 
            
            break;

        default:

            break;
#endif
    }

#elif(_LVDS_TERMINATION_CONTROL == _DISABLE)

    // Disable Output Termination
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_1B_LVDS_CTRL42, 0x00, 0x00);

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
            
#endif // End of #if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)
    }
#endif // End of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)
}

#if(((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON)) || (_OD_SUPPORT == _ON))
//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
void ScalerDisplaySelectDVFMode(void)
{ 
#if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))
#if(_3D_SUPPORT == _ON)
    if(GET_3D_INPUT_FORMAT() == _NO_3D_FORMAT)    
#endif
    {
        // For 1080p25
        if((g_stMDomainInputData.usVFreq <= (_PANEL_MAX_FRAME_RATE * 2 / 5)) && 
            (g_stMDomainInputData.usVFreq >= (_PANEL_MIN_FRAME_RATE * 2 / 5))) // DVF = 2.5 * IVF 
        {
            SET_MEMORY_DVF_SELECT(_2_5_IVF);
            g_usDVFreq = 5 * g_stMDomainInputData.usVFreq / 2;   

            return;
        }
    }

    // For 1080p24
    if(g_stMDomainInputData.usVFreq < 247)
    {
        SET_MEMORY_DVF_SELECT(_2_5_IVF);
        g_usDVFreq = 600;        
    }
    else if((g_stMDomainInputData.usVFreq <= (_PANEL_MAX_FRAME_RATE / 2)) && 
        (g_stMDomainInputData.usVFreq >= (_PANEL_MIN_FRAME_RATE / 2))) // DVF = 2 * IVF 
    {
        SET_MEMORY_DVF_SELECT(_2_IVF);            
        g_usDVFreq = 2 * g_stMDomainInputData.usVFreq;
    }
    else if((g_stMDomainInputData.usVFreq <= (_PANEL_MAX_FRAME_RATE / 3)) && 
        (g_stMDomainInputData.usVFreq >= (_PANEL_MIN_FRAME_RATE / 3))) // DVF = 3 * IVF 
    {
        SET_MEMORY_DVF_SELECT(_3_IVF);            
        g_usDVFreq = 3 * g_stMDomainInputData.usVFreq;
    }    
    else if((g_stMDomainInputData.usVFreq < _PANEL_MIN_FRAME_RATE) || 
        (g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE)) // DVF = 60Hz display
    {
        SET_MEMORY_DVF_SELECT(_60HZ_DISPLAY);
        g_usDVFreq = 600;
    }	
    else
#endif // End of #if((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON))        
    {
        SET_MEMORY_DVF_SELECT(_1_IVF);        
        g_usDVFreq = g_stMDomainInputData.usVFreq;
    }  
}
#endif // End of #if(((_FRC_SUPPORT == _ON) || (_3D_SUPPORT == _ON)) || (_OD_SUPPORT == _ON))
