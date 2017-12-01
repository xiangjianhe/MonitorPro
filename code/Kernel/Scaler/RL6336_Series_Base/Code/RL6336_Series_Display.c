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
// ID Code      : RL6336_Series_Audio.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6336_SERIES_DISPLAY__

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
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT1 | _BIT0), _BIT0);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, 0x08);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A2_TCON_LVDS_CTRL2, 0x03);

#if(_DIGITAL_PORT_SUPPORT == _ON)
    // LVDS driving current from GDI bandgap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A2_TCON_LVDS_CTRL2, ~_BIT4, _BIT4);
#else
    // LVDS driving current from POR bandgap
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A2_TCON_LVDS_CTRL2, ~_BIT4, 0x00);
#endif

    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, 0x20);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A4_TCON_LVDS_CTRL4, 0x80);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A5_TCON_LVDS_CTRL5, 0x80);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AF_TCON_LVDS_CTRL15, 0x00);

    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~_BIT7, 0x00);
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_C5_TCON_LVDS_CTRL37, 0xE3);

#if((_LVDS_E0_PHASE + _LVDS_E1_PHASE + _LVDS_E2_PHASE + _LVDS_EC_PHASE + _LVDS_E3_PHASE + _LVDS_O0_PHASE + _LVDS_O1_PHASE + _LVDS_O2_PHASE + _LVDS_O3_PHASE) != 0x00)
    ScalerSetBit(P1_D1_LVDSPLL_1, ~_BIT1, _BIT1);
#else
    ScalerSetBit(P1_D1_LVDSPLL_1, ~_BIT1, 0x00);
#endif

    // LVDS Phase select
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_B5_TCON_LVDS_CTRL21, 0x00, ((_LVDS_E0_PHASE << 5) | _LVDS_E1_PHASE));    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_B6_TCON_LVDS_CTRL22, 0x00, ((_LVDS_E2_PHASE << 5) | _LVDS_EC_PHASE)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_B7_TCON_LVDS_CTRL23, 0x00, (_LVDS_E3_PHASE << 5)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_B8_TCON_LVDS_CTRL24, 0x00, ((_LVDS_O0_PHASE << 5) | _LVDS_O1_PHASE)); 
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_B9_TCON_LVDS_CTRL25, 0x00, ((_LVDS_O2_PHASE << 5) | _LVDS_O3_PHASE));
    
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A3_TCON_LVDS_CTRL3, ~(_BIT7 | _BIT6 | _BIT0), ((_LVDS_PN_SWAP << 7) | (_LVDS_MIRROR << 6) | (_LVDS_TABLE_TYPE)));

    ScalerSetDataPortBit(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_20_DISP_DIS_TIMING, ~_BIT0, _BIT0);
#endif 

    // Display Signal Control Settings
#if(_DISP_BIT_MODE == _DISP_18_BIT)      
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT4, _BIT4);
#else
    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT4, 0x00);    
#endif     

    ScalerSetBit(CM_28_VDISP_CTRL, ~_BIT2, (_DISP_OUTPUT_PORT << 2)); 
    ScalerSetByte(CM_29_VDISP_SIGINV, ((_DHS_MASK << 7) | (_LVDS_EO_SWAP << 6) | (_LVDS_RB_SWAP << 5) | (_LVDS_ML_SWAP << 4) | (_DISP_SKEW << 3) | (_LVDS_DVS_INVERT << 2) | (_LVDS_DHS_INVERT << 1) | (_LVDS_DEN_INVERT)));

    // Set LVDS Driving Control
    ScalerDisplayLvdsDrivingControl(_LVDS_DRIV_CONTROL, _LVDS_DRIV_CONTROL);

    // Set LVDS/mLVDS porch use porch color
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~_BIT0, _BIT0);
    
    // Set LVDS/mLVDS common mode Voltage                                       
#if(_LVDS_VCM_CONTROL == _LVDS_VCM_LOW)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_NORMAL)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3));
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_HIGH)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_USER)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_LVDS_VCM_USER_LEVEL & 0xF));
// // odin for EMI seting
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_1_40)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_1_45)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1));
#elif(_LVDS_VCM_CONTROL == _LVDS_VCM_1_50)
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A1_TCON_LVDS_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));
#endif


    // Set LVDS data shape adjustment control
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    // Set LVDS data slew rate control
#if(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_0)     
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_1)   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_2)   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));           
#elif(_LVDS_SR_CONTROL == _LVDS_SR_CONTROL_3)   
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AB_TCON_LVDS_CTRL11, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
#endif         

    // Initial Enable Even/Odd Port Strongly Pull Down
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));
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
        // Disable Even/Odd Port Strongly Pull Down
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~(_BIT3 | _BIT2), 0x00);
      
        // Power Up LVDS Block
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT7 | _BIT5 | _BIT4), (_BIT7 | _BIT5 | _BIT4));

    	// Disable Weakly Pull Down 
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~(_BIT5 | _BIT4), 0x00);
        
    }
    else
    {
#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT) 
        // Enable Even/Odd Port Strongly Pull Down
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

#elif(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT)
#if(_LVDS_EO_SWAP == _DISABLE)
        // Enable Even Port Strongly Pull Down
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~_BIT3, _BIT3);
    	// Enable Even Port Weakly Pull Down
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~_BIT5, _BIT5);

#elif(_LVDS_EO_SWAP == _ENABLE)
        // Enable Odd Port Strongly Pull Down
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~_BIT2, _BIT2);
    	// Enable Odd Port Weakly Pull Down
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BC_TCON_LVDS_CTRL28, ~_BIT4, _BIT4);
#endif
#endif

        // Power Down LVDS Block
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~(_BIT7 | _BIT5 | _BIT4), 0x00);
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
        // Disable TCON8
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_4E_TCON_TCON8_CTRL, ~_BIT7, 0x00);

        // Get DHTotal (12-bit)    
        ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_00_DISP_DH_TOTAL_H, 2, pData, _AUTOINC);


        // Get DV_ACT_End (12-bit)
        ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_12_DISP_DV_ACT_END_H, 2, &pData[2], _AUTOINC);
        

        // Get DV_BK_End (12-bit)
        ScalerGetDataPortByte(CM_2A_DISP_ACCESS_PORT, _CM_2B_PT_14_DISP_DV_BKGD_END_H, 2, &pData[4], _AUTOINC);
        

        // Calculate the larger value between DV_ACT_End & EV_BK_End
        PDATA_WORD(3) = MAXOF(PDATA_WORD(1), PDATA_WORD(2)) + 1;
        PDATA_WORD(4) = PDATA_WORD(3) + 1;

        // Set TCON8 V start & end to [max_DV + 1: max_DV + 2]
        ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_48_TCON_TCON8_VS_LSB, LOBYTE(PDATA_WORD(3)));
        ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_49_TCON_TCON8_VS_VE_MSB, ((HIBYTE(PDATA_WORD(4)) << 4) | HIBYTE(PDATA_WORD(3))));
        ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_4A_TCON_TCON8_VE_LSB, LOBYTE(PDATA_WORD(4)));

        // Set TCON8 H start & end to [DH_total/2 + 2:DH_total/2 + 12]
        PDATA_WORD(3) = (PDATA_WORD(0) >> 1) + 2;
        PDATA_WORD(4) = PDATA_WORD(3) + 10;

        // Set TCON8 H start & end
        ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_4B_TCON_TCON8_HS_LSB, LOBYTE(PDATA_WORD(3)));
        ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_4C_TCON_TCON8_HS_HE_MSB, ((HIBYTE(PDATA_WORD(4)) << 4) | HIBYTE(PDATA_WORD(3))));
        ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_4D_TCON_TCON8_HE_LSB, LOBYTE(PDATA_WORD(4)));

        // TCON Global Enable
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_00_TCON_CTRL0, ~(_BIT7 | _BIT2), (_BIT7 | _BIT2));

        // TCON8 Enable
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_4E_TCON_TCON8_CTRL, ~_BIT7, _BIT7);

        // ctsFIFO reset by TCON8
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_C8_LVDSPLL_CTS_FIFO_CTRL3, ~_BIT0, _BIT0);

        // Power Up LVDS PLL
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~_BIT6, _BIT6);
    }
    else
    {
        // Power Down LVDS PLL
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A0_TCON_LVDS_CTRL0, ~_BIT6, 0x00);

        // ctsFIFO reset by register
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_C8_LVDSPLL_CTS_FIFO_CTRL3, ~_BIT0, 0x00);

        // Disable TCON8
        ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_4E_TCON_TCON8_CTRL, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set LVDS driving control
// Input Value  : Driving current for Data and Clock pair
// Output Value : None
//--------------------------------------------------
void ScalerDisplayLvdsDrivingControl(BYTE ucData, BYTE ucClock)
{
    BYTE ucDriv = ucData;
    ucClock = ucClock;

#if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)

#if(_LVDS_MIRROR == _DISABLE)

    // Set CLK(EC) LVDS Output Current 2X
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~_BIT3, _BIT3);
    
#else 

    // Set CLK(E1) LVDS Output Current 2X
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~_BIT1, _BIT1);
    
#endif // End of #if(_LVDS_MIRROR == _DISABLE)
    
#if(_LVDS_TERMINATION_CONTROL == _ENABLE)

    // Set LVDS Even/Odd Port Output Termination Enable
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BB_TCON_LVDS_CTRL27, 0x50);

    switch(ucDriv)
    {
#if(_LVDS_MIRROR == _DISABLE)

        case _LVDS_DRIV_CONTROL_2_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT7);            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT3);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), 0x00);           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), 0x00);           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            // Set LVDS CLK(EC) Output Current 1X
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~_BIT3, 0x00);
            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));            

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT3);

            // Set LVDS CLK(EC) Output Current 1X
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~_BIT3, 0x00);
            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));
            
            break;

        default:

            break;

#else //#if(_LVDS_MIRROR == _DISABLE)

        case _LVDS_DRIV_CONTROL_2_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT7);            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT5);

            // Set LVDS CLK(E1) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), 0x00);           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

            // Set LVDS CLK(E1) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), 0x00);           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            // Set LVDS CLK(E1) Output Current 1X
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~_BIT1, 0x00);
            // Set LVDS CLK(E1) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));            

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT5);

            // Set LVDS CLK(E1) Output Current 1X
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~_BIT1, 0x00);
            // Set LVDS CLK(E1) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));
            
            break;

        default:

            break;

#endif
    }
    
#elif(_LVDS_TERMINATION_CONTROL == _DISABLE)

    // Disable Output Termination
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BB_TCON_LVDS_CTRL27, 0x00, 0x00);

    switch(ucDriv)
    {
#if(_LVDS_MIRROR == _DISABLE)

        case _LVDS_DRIV_CONTROL_2_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), 0x00);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), 0x00);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        default:

            break;

#else //#if(_LVDS_MIRROR == _DISABLE)

        case _LVDS_DRIV_CONTROL_2_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            // Set LVDS CLK(E1) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            // Set LVDS CLK(E1) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), 0x00);

            // Set LVDS CLK(E1) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), 0x00);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            // Set LVDS CLK(E1) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        default:

            break;

#endif
    }

#endif // End of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)

#elif(_DISP_OUTPUT_PORT == _DISP_SINGLE_PORT) // Else of #if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)

    // Set CLK(EC) LVDS Output Current 1X
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_AC_TCON_LVDS_CTRL12, ~_BIT3, 0x00);

#if(_LVDS_TERMINATION_CONTROL == _ENABLE)

#if(_LVDS_EO_SWAP == _DISABLE)

    // Set LVDS Even Port Output Termination Enable
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BB_TCON_LVDS_CTRL27, 0x40);

#elif(_LVDS_EO_SWAP == _ENABLE)

    // Set LVDS Even/Odd Port Output Termination Enable
    ScalerSetDataPortByte(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BB_TCON_LVDS_CTRL27, 0x50);

#endif
 
    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT7);            
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT3);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT5);           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);            

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT3);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT5);           

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4 | _BIT3));
            
            break;

        default:

            break;
    }

#elif(_LVDS_TERMINATION_CONTROL == _DISABLE)

    // Disable Output Termination
    ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_BB_TCON_LVDS_CTRL27, 0x00, 0x00);

    switch(ucDriv)
    {
        case _LVDS_DRIV_CONTROL_2_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_2_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT3));
            
            break;

        case _LVDS_DRIV_CONTROL_3_0:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), 0x00);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), 0x00);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        case _LVDS_DRIV_CONTROL_3_5:
            
            // Set LVDS Data Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT3 | _BIT2), _BIT2);

            // Set LVDS CLK(EC) Drinving Current
            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A6_TCON_LVDS_CTRL6, ~(_BIT5 | _BIT4), _BIT4);

            ScalerSetDataPortBit(CM_8B_TCON_ADDR_PORT, _CM_8C_PT_A7_TCON_LVDS_CTRL7, ~(_BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
            
            break;

        default:

            break;
    }

#endif // End of #if(_LVDS_TERMINATION_CONTROL == _ENABLE)

#endif // End of #if(_DISP_OUTPUT_PORT == _DISP_DOUBLE_PORT)
}
