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
// ID Code      : RL6336_Series_Reg_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of  Control Register Address
//--------------------------------------------------

//--------------------------------------------------
// Scale Down Port
//--------------------------------------------------
#define _CM_25_PT_00_V_SCALE_INIT                 0x00 // Vertical Scale Down Initial Select
#define _CM_25_PT_01_V_SCALE_DH                   0x01 // Vertical scale down factor register
#define _CM_25_PT_02_V_SCALE_DM                   0x02 // Vertical scale down factor register
#define _CM_25_PT_03_V_SCALE_DL                   0x03 // Vertical scale down factor register
#define _CM_25_PT_04_H_SCALE_INIT                 0x04 // Horizontal Scale Down Initial Select
#define _CM_25_PT_05_H_SCALE_DH                   0x05 // Horizontal Scale Down Factor
#define _CM_25_PT_06_H_SCALE_DM                   0x06 // Horizontal Scale Down Factor
#define _CM_25_PT_07_H_SCALE_DL                   0x07 // Horizontal Scale Down Factor
#define _CM_25_PT_08_H_SCALE_ACCH                 0x08 // Horizontal Scale Down Accumulated Factor
#define _CM_25_PT_09_H_SCALE_ACCL                 0x09 // Horizontal Scale Down Accumulated Factor
#define _CM_25_PT_0A_SD_ACC_WIDTHH                0x0A // Horizontal Scale Down Accumulated Width
#define _CM_25_PT_0B_SD_ACC_WIDTHL                0x0B // Horizontal Scale Down Accumulated Width
#define _CM_25_PT_0C_SD_FLAT_WIDTHH               0x0C // Horizontal Scale Down Flat Width
#define _CM_25_PT_0D_SD_FLAT_WIDTHL               0x0D // Horizontal Scale Down Flat Width
#define _CM_25_PT_10_IPG_CTRL0                    0x10 // Input Pattern Generator Ctrl 0
#define _CM_25_PT_11_IPG_CTRL1                    0x11 // Input Pattern Generator Ctrl 1
#define _CM_25_PT_12_IPG_RED_INIT                 0x12 // Input Pattern Generator RED Initial Value
#define _CM_25_PT_13_IPG_GREEN_INIT               0x13 // Input Pattern Generator GREEN Initial Value
#define _CM_25_PT_14_IPG_BLUE_INIT                0x14 // Input Pattern Generator BLUE Initial Value
#define _CM_25_PT_15_IPG_RGB_INIT                 0x15 // Input Pattern Generator RED/GREEN/BLUE Initial Value

//--------------------------------------------------
// Display Format Port
//--------------------------------------------------
#define _CM_2B_PT_00_DISP_DH_TOTAL_H              0x00 // Display Horizontal Total Pixels HByte
#define _CM_2B_PT_01_DISP_DH_TOTAL_L              0x01 // Display Horizontal Total Pixels LByte
#define _CM_2B_PT_02_DISP_DHS_END                 0x02 // Display Horizontal Sync End Pixels
#define _CM_2B_PT_03_DISP_DH_BKGD_STA_H           0x03 // Display Horizontal Background Start HByte
#define _CM_2B_PT_04_DISP_DH_BKGD_STA_L           0x04 // Display Horizontal Background Start LByte
#define _CM_2B_PT_05_DISP_DH_ACT_STA_H            0x05 // Display Horizontal Active Start HByte
#define _CM_2B_PT_06_DISP_DH_ACT_STA_L            0x06 // Display Horizontal Active Start LByte
#define _CM_2B_PT_07_DISP_DH_ACT_END_H            0x07 // Display Horizontal Active End HByte
#define _CM_2B_PT_08_DISP_DH_ACT_END_L            0x08 // Display Horizontal Active End LByte
#define _CM_2B_PT_09_DISP_DH_BKGD_END_H           0x09 // Display Horizontal Background End HByte
#define _CM_2B_PT_0A_DISP_DH_BKGD_END_L           0x0A // Display Horizontal Background End LByte
#define _CM_2B_PT_0B_DISP_DV_TOTAL_H              0x0B // Display Vertical Total Lines HByte
#define _CM_2B_PT_0C_DISP_DV_TOTAL_L              0x0C // Display Vertical Total Lines LByte
#define _CM_2B_PT_0D_DISP_DVS_END                 0x0D // Display Vertical Sync End Lines
#define _CM_2B_PT_0E_DISP_DV_BKGD_STA_H           0x0E // Display Vertical Background Start HByte
#define _CM_2B_PT_0F_DISP_DV_BKGD_STA_L           0x0F // Display Vertical Background Start LByte
#define _CM_2B_PT_10_DISP_DV_ACT_STA_H            0x10 // Display Vertical Active Start HByte
#define _CM_2B_PT_11_DISP_DV_ACT_STA_L            0x11 // Display Vertical Active Start LByte
#define _CM_2B_PT_12_DISP_DV_ACT_END_H            0x12 // Display Vertical Active End HByte
#define _CM_2B_PT_13_DISP_DV_ACT_END_L            0x13 // Display Vertical Active End LByte
#define _CM_2B_PT_14_DISP_DV_BKGD_END_H           0x14 // Display Vertical Background End HByte
#define _CM_2B_PT_15_DISP_DV_BKGD_END_L           0x15 // Display Vertical Background End LByte
#define _CM_2B_PT_20_DISP_DIS_TIMING              0x20 // Display Clock Fine Tuning Register
#define _CM_2B_PT_21_DISP_OSD_REFERENCE_DEN       0x21 // Position Of Reference DEN for OSD
#define _CM_2B_PT_22_DISP_NEW_DV_CTRL             0x22 // New DV Control Register
#define _CM_2B_PT_23_DISP_NEW_DV_DLY              0x23 // New DV Delay
#define _CM_2B_PT_24_SSCG_NEW_TIMING_MODE         0x24 // SSCG_NEW_Timing_Mode Setting

//--------------------------------------------------
// FIFO Window Port
//--------------------------------------------------
#define _CM_31_PT_00_FIFO_DRL_H_BSU               0x00 // Display Window Read Width/Length HByte Before Scaling Up
#define _CM_31_PT_01_FIFO_DRW_L_BSU               0x01 // Display Window Read Width LByte Before Scaling Up
#define _CM_31_PT_02_FIFO_DRL_L_BSU               0x02 // Display Window Read Length LByte Before Scaling Up

//--------------------------------------------------
// Scale Up Port
//--------------------------------------------------
#define _CM_34_PT_00_SU_HOR_SCA_H                 0x00 // Horizontal Scale Factor High
#define _CM_34_PT_01_SU_HOR_SCA_M                 0x01 // Horizontal Scale Factor Medium
#define _CM_34_PT_02_SU_HOR_SCA_L                 0x02 // Horizontal Scale Factor Low
#define _CM_34_PT_03_SU_VER_SCA_H                 0x03 // Vertical Scale Factor High
#define _CM_34_PT_04_SU_VER_SCA_M                 0x04 // Vertical Scale Factor Medium
#define _CM_34_PT_05_SU_VER_SCA_L                 0x05 // Vertical Scale Factor Low
#define _CM_34_PT_06_SU_H_SF_SEGMENT_1PIXEL_H     0x06 // Horizontal Scale Factor Segment 1 Pixel
#define _CM_34_PT_07_SU_H_SF_SEGMENT_1PIXEL_L     0x07 // Horizontal Scale Factor Segment 1 Pixel
#define _CM_34_PT_08_SU_H_SF_SEGMENT_2PIXEL_H     0x08 // Horizontal Scale Factor Segment 2 Pixel
#define _CM_34_PT_09_SU_H_SF_SEGMENT_2PIXEL_L     0x09 // Horizontal Scale Factor Segment 2 Pixel
#define _CM_34_PT_0A_SU_H_SF_SEGMENT_3PIXEL_H     0x0A // Horizontal Scale Factor Segment 3 Pixel
#define _CM_34_PT_0B_SU_H_SF_SEGMENT_3PIXEL_L     0x0B // Horizontal Scale Factor Segment 3 Pixel
#define _CM_34_PT_0C_SU_H_SF_DELTA_1_H            0x0C // Horizontal Scale Factor Delta 1
#define _CM_34_PT_0D_SU_H_SF_DELTA_1_L            0x0D // Horizontal Scale Factor Delta 1
#define _CM_34_PT_0E_SU_H_SF_DELTA_2_H            0x0E // Horizontal Scale Factor Delta 2
#define _CM_34_PT_0F_SU_H_SF_DELTA_2_L            0x0F // Horizontal Filter Coefficient Initial Value
#define _CM_34_PT_10_SU_H_COEF_INI_VALUE          0x10 // Horizontal Filter Coefficient Initial Value
#define _CM_34_PT_11_SU_V_COEF_INI_VALUE          0x11 // Vertical Filter Coefficient Initial Value

//--------------------------------------------------
// Sync Processor Port (0x5C->Address, 0x5D->Data)
//--------------------------------------------------
#define _CM_5D_PT_00_SYNC_G_CLAMP_START           0x00 // G/Y Channle Clamp Signal Output Start
#define _CM_5D_PT_01_SYNC_G_CLAMP_END             0x01 // G/Y Channle Clamp Signal Output End
#define _CM_5D_PT_02_SYNC_BR_CLAMP_START          0x02 // B/Pb & R/Pr Channle Clamp Signal Output Start
#define _CM_5D_PT_03_SYNC_BR_CLAMP_END            0x03 // B/Pb & R/Pr Channle Clamp Signal Output End
#define _CM_5D_PT_04_SYNC_CLAMP_CTRL0             0x04 // Clamp Signal Control Register 0
#define _CM_5D_PT_05_SYNC_CLAMP_CTRL1             0x05 // Clamp Signal Control Register 1
#define _CM_5D_PT_06_SYNC_CLAMP_CTRL2             0x06 // Clamp Signal Control Register 2
#define _CM_5D_PT_07_SYNC_COAST_CTRL              0x07 // COAST before DeVS Leading Edge Setting
#define _CM_5D_PT_08_CAPTURE_WINDOW_SETTING       0x08 // Capture window setting
#define _CM_5D_PT_09_SYNC_DETECT_TOLERANCE_SET    0x09 // Detection Tolerance Setting
#define _CM_5D_PT_0A_DEVS_CAP_NUM_H               0x0A // The munber of Capture window between DeVs high period: High Byte[11:8]
#define _CM_5D_PT_0B_DEVS_CAP_NUM_L               0x0B // The munber of Capture window between DeVs high period: High Byte[7:0]
#define _CM_5D_PT_0D_G_CLAMP_START_H              0x0D // G/Y Channel Clamp Signal Output Start and End High Buye
#define _CM_5D_PT_0E_BR_CLAMP_START_H             0x0E // B/Pb & R/Pr Channel Clamp Signal Output Start and End High Byte

//--------------------------------------------------
// Macro Vision
//--------------------------------------------------
#define _CM_5D_PT_10_SYNC_MACRO_VISION_CTRL       0x10 // Macro Vision Control Register
#define _CM_5D_PT_11_SYNC_MV_START_LINE_EVEN      0x11 // Macro Vision Start Line in Even Field
#define _CM_5D_PT_12_SYNC_MV_END_LINE_EVEN        0x12 // Macro Vision End Line in Even Field
#define _CM_5D_PT_13_SYNC_MV_START_LINE_ODD       0x13 // Macro Vision Start Line in Odd Field
#define _CM_5D_PT_14_SYNC_MV_END_LINE_ODD         0x14 // Macro Vision End Line in Odd Field
#define _CM_5D_PT_15_MV_DETECT_DEBOUNCE           0x15 // Macro Vision Detect De-bounce
#define _CM_5D_PT_18_SYNC_TEST_MODE               0x18 // Sync Processor Test Mode
#define _CM_5D_PT_19_HS_DETECT_SETTING            0x19 // HS and SOG Detection

//--------------------------------------------------
// Hightlight Window Port
//--------------------------------------------------
#define _CM_61_PT_00_HW_H_START_H                 0x00 // Highlight Window Horizontal Start HByte
#define _CM_61_PT_01_HW_H_START_L                 0x01 // Highlight Window Horizontal Start LByte
#define _CM_61_PT_02_HW_H_END_H                   0x02 // Highlight Window Horizontal End HByte
#define _CM_61_PT_03_HW_H_END_L                   0x03 // Highlight Window Horizontal End LByte
#define _CM_61_PT_04_HW_V_START_H                 0x04 // Highlight Window Vertical Start HByte
#define _CM_61_PT_05_HW_V_START_L                 0x05 // Highlight Window Vertical Start LByte
#define _CM_61_PT_06_HW_V_END_H                   0x06 // Highlight Window Vertical End HByte
#define _CM_61_PT_07_HW_V_END_L                   0x07 // Highlight Window Vertical End LByte
#define _CM_61_PT_08_HW_BORDER_WIDTH              0x08 // Highlight Window Border Width
#define _CM_61_PT_09_HW_BORDER_COLOR_R            0x09 // Highlight Window Border Red Color MSB 6bit (Red Color 2-bit LSB = 00)
#define _CM_61_PT_0A_HW_BORDER_COLOR_G            0x0A // Highlight Window Border Green Color MSB 6bit (Red Color 2-bit LSB = 00)
#define _CM_61_PT_0B_HW_BORDER_COLOR_B            0x0B // Highlight Window Border Blue Color MSB 6bit (Red Color 2-bit LSB = 00)
#define _CM_61_PT_0C_HW_WINDOW_CTRL0              0x0C // Highlight Window Control Register0
#define _CM_61_PT_0D_HW_WINDOW_CTRL1              0x0D // Highlight Window Control Register1

//--------------------------------------------------
// Contrast/Brightness Coefficient Port
//--------------------------------------------------
#define _CM_65_PT_00_CB_BRI_R_COEF_A              0x00 // Brightness Red Coefficient Set.A
#define _CM_65_PT_01_CB_BRI_G_COEF_A              0x01 // Brightness Green Coefficient Set.A
#define _CM_65_PT_02_CB_BRI_B_COEF_A              0x02 // Brightness Blue Coefficient Set.A
#define _CM_65_PT_03_CB_CTS_R_COEF_A              0x03 // Contrast Red Coefficient Set.A
#define _CM_65_PT_04_CB_CTS_G_COEF_A              0x04 // Contrast Green Coefficient Set.A
#define _CM_65_PT_05_CB_CTS_B_COEF_A              0x05 // Contrast Blue Coefficient Set.A
#define _CM_65_PT_06_CB_BRI_R_COEF_B              0x06 // Brightness Red Coefficient Set.B
#define _CM_65_PT_07_CB_BRI_G_COEF_B              0x07 // Brightness Green Coefficient Set.B
#define _CM_65_PT_08_CB_BRI_B_COEF_B              0x08 // Brightness Blue Coefficient Set.B
#define _CM_65_PT_09_CB_CTS_R_COEF_B              0x09 // Contrast Red Coefficient Set.B
#define _CM_65_PT_0A_CB_CTS_G_COEF_B              0x0A // Contrast Green Coefficient Set.B
#define _CM_65_PT_0B_CB_CTS_B_COEF_B              0x0B // Contrast Blue Coefficient Set.B

//--------------------------------------------------
// Timing Controller Port
//--------------------------------------------------
#define _CM_8C_PT_00_TCON_CTRL0                   0x00 // Timing Controller Control Register0
#define _CM_8C_PT_01_TCON_CTRL1                   0x01 // Timing Controller Control Register1
#define _CM_8C_PT_02_TCON_LINE_THRESHOLD_MSB      0x02 // Pixel Threshold High Value for Smart Polarity
#define _CM_8C_PT_03_TCON_PIXEL_THRESHOLD1_LSB    0x03 // 2 Line Sum of Difference Threshold 1 Value: bit [7:0], ie:TH1 (Also refer to CR8C-02[7])
#define _CM_8C_PT_04_TCON_PIXEL_THRESHOLD2_LSB    0x04 // 2 Line Sum of Difference Threshold 2 Value: bit [7:0], ie:TH2 (Also refer to CR8C-02[6])
#define _CM_8C_PT_05_TCON_LINE_THRESHOLD          0x05 // Line Threshold Value for Smart Polarity

//--------------------------------------------------
// TCON Horizontal/Vertical Timing Setting
//--------------------------------------------------
#define _CM_8C_PT_08_TCON_TCON0_VS_LSB            0x08 // TCON[0] Vertical Start LSB Register
#define _CM_8C_PT_09_TCON_TCON0_VS_VE_MSB         0x09 // TCON[0] Vertical Start/End MSB Register
#define _CM_8C_PT_0A_TCON_TCON0_VE_LSB            0x0A // TCON[0] Vertical End LSB Register
#define _CM_8C_PT_0B_TCON_TCON0_HS_LSB            0x0B // TCON[0] Horizontal Start LSB Register
#define _CM_8C_PT_0C_TCON_TCON0_HS_HE_MSB         0x0C // TCON[0] Horizontal Start/End MSB Register
#define _CM_8C_PT_0D_TCON_TCON0_HE_LSB            0x0D // TCON[0] Horizontal End LSB Register
#define _CM_8C_PT_0E_TCON_TCON0_CTRL              0x0E // TCON[0] Control Register

#define _CM_8C_PT_48_TCON_TCON8_VS_LSB            0x48 // TCON[8] Vertical Start LSB Register
#define _CM_8C_PT_49_TCON_TCON8_VS_VE_MSB         0x49 // TCON[8] Vertical Start/End MSB Register
#define _CM_8C_PT_4A_TCON_TCON8_VE_LSB            0x4A // TCON[8] Vertical End LSB Register
#define _CM_8C_PT_4B_TCON_TCON8_HS_LSB            0x4B // TCON[8] Horizontal Start LSB Register
#define _CM_8C_PT_4C_TCON_TCON8_HS_HE_MSB         0x4C // TCON[8] Horizontal Start/End MSB Register
#define _CM_8C_PT_4D_TCON_TCON8_HE_LSB            0x4D // TCON[8] Horizontal End LSB Register
#define _CM_8C_PT_4E_TCON_TCON8_CTRL              0x4E // TCON[8] Control Register

//--------------------------------------------------
// Dot Masking
//--------------------------------------------------
#define _CM_8C_PT_5F_TCON_TCON10_DOT_MASK_CTRL    0x5F // TCON[10] Dot Masking Control Register
#define _CM_8C_PT_67_TCON_TCON11_DOT_MASK_CTRL    0x67 // TCON[11] Dot Masking Control Register
#define _CM_8C_PT_6F_TCON_TCON12_DOT_MASK_CTRL    0x6F // TCON[12] Dot Masking Control Register
#define _CM_8C_PT_77_TCON_TCON13_DOT_MASK_CTRL    0x77 // TCON[13] Dot Masking Control Register

//--------------------------------------------------
// Control For LVDS
//--------------------------------------------------
#define _CM_8C_PT_A0_TCON_LVDS_CTRL0              0xA0 // LVDS Control Register0
#define _CM_8C_PT_A1_TCON_LVDS_CTRL1              0xA1 // LVDS Control Register1
#define _CM_8C_PT_A2_TCON_LVDS_CTRL2              0xA2 // LVDS Control Register2
#define _CM_8C_PT_A3_TCON_LVDS_CTRL3              0xA3 // LVDS Control Register3
#define _CM_8C_PT_A4_TCON_LVDS_CTRL4              0xA4 // LVDS Control Register4
#define _CM_8C_PT_A5_TCON_LVDS_CTRL5              0xA5 // LVDS Control Register5
#define _CM_8C_PT_A6_TCON_LVDS_CTRL6              0xA6 // LVDS Control Register6
#define _CM_8C_PT_A7_TCON_LVDS_CTRL7              0xA7 // LVDS Control Register7
#define _CM_8C_PT_A8_TCON_LVDS_CTRL8              0xA8 // LVDS Control Register8
#define _CM_8C_PT_A9_TCON_LVDS_CTRL9              0xA9 // LVDS Control Register9
#define _CM_8C_PT_AA_TCON_LVDS_CTRL10             0xAA // LVDS Control Register10
#define _CM_8C_PT_AB_TCON_LVDS_CTRL11             0xAB // LVDS Control Register11
#define _CM_8C_PT_AC_TCON_LVDS_CTRL12             0xAC // LVDS Control Register12
#define _CM_8C_PT_AD_TCON_LVDS_CTRL13             0xAD // LVDS Control Register13
#define _CM_8C_PT_AE_TCON_LVDS_CTRL14             0xAE // LVDS Control Register14
#define _CM_8C_PT_AF_TCON_LVDS_CTRL15             0xAF // LVDS Control Register15
#define _CM_8C_PT_B0_TCON_LVDS_CTRL16             0xB0 // LVDS Control Register16
#define _CM_8C_PT_B1_TCON_LVDS_CTRL17             0xB1 // LVDS Control Register17
#define _CM_8C_PT_B2_TCON_LVDS_CTRL18             0xB2 // LVDS Control Register18
#define _CM_8C_PT_B3_TCON_LVDS_CTRL19             0xB3 // LVDS Control Register19
#define _CM_8C_PT_B4_TCON_LVDS_CTRL20             0xB4 // LVDS Control Register20
#define _CM_8C_PT_B5_TCON_LVDS_CTRL21             0xB5 // LVDS Control Register21
#define _CM_8C_PT_B6_TCON_LVDS_CTRL22             0xB6 // LVDS Control Register22
#define _CM_8C_PT_B7_TCON_LVDS_CTRL23             0xB7 // LVDS Control Register23
#define _CM_8C_PT_B8_TCON_LVDS_CTRL24             0xB8 // LVDS Control Register24
#define _CM_8C_PT_B9_TCON_LVDS_CTRL25             0xB9 // LVDS Control Register25
#define _CM_8C_PT_BA_TCON_LVDS_CTRL26             0xBA // LVDS Control Register26
#define _CM_8C_PT_BB_TCON_LVDS_CTRL27             0xBB // LVDS Control Register27
#define _CM_8C_PT_BC_TCON_LVDS_CTRL28             0xBC // LVDS Control Register28
#define _CM_8C_PT_BD_TCON_LVDS_CTRL29             0xBD // LVDS Control Register29
#define _CM_8C_PT_BE_TCON_LVDS_CTRL30             0xBE // LVDS Control Register30
#define _CM_8C_PT_BF_TCON_LVDS_CTRL31             0xBF // LVDS Control Register31
#define _CM_8C_PT_C0_TCON_LVDS_CTRL32             0xC0 // LVDS Control Register32
#define _CM_8C_PT_C1_TCON_LVDS_CTRL33             0xC1 // LVDS Control Register33
#define _CM_8C_PT_C2_TCON_LVDS_CTRL34             0xC2 // LVDS Control Register34
#define _CM_8C_PT_C3_TCON_LVDS_CTRL35             0xC3 // LVDS Control Register35
#define _CM_8C_PT_C4_TCON_LVDS_CTRL36             0xC4 // LVDS Control Register36
#define _CM_8C_PT_C5_TCON_LVDS_CTRL37             0xC5 // LVDS Control Register37
#define _CM_8C_PT_C6_LVDSPLL_CTS_FIFO_CTRL1       0xC6 // LVDS PLL Control Register1
#define _CM_8C_PT_C7_LVDSPLL_CTS_FIFO_CTRL2       0xC7 // LVDS PLL Control Register2
#define _CM_8C_PT_C8_LVDSPLL_CTS_FIFO_CTRL3       0xC8 // LVDS PLL Control Register3

//--------------------------------------------------
// Test Function(Port)
//--------------------------------------------------
#define _CM_8E_PT_00_PS_TEST_MODE                 0x00 // Test Mode
#define _CM_8E_PT_01_PS_TST_CLK_CTRL0             0x01 // Test Clock Control Register0
#define _CM_8E_PT_02_PS_TST_CLK_CTRL1             0x02 // Test Clock Control Register1
#define _CM_8E_PT_03_PS_TST_CLK_CTRL2             0x03 // Test Clock Control Register2
#define _CM_8E_PT_04_PS_TST_CLK_CTRL3             0x04 // Test Clock Control Register3
#define _CM_8E_PT_05_PS_SELECT_TST_S1S2           0x05 // Select Test Function Of Test_S1/Test_S2
#define _CM_8E_PT_06_PS_SELECT_TSTINCLOCK         0x06 // Select Test Function In Clock

//--------------------------------------------------
// TEST MODE in FIFO
//--------------------------------------------------
#define _CM_8E_PT_07_PS_ADC_TEST_MODE             0x07 // ADC TEST MODE
#define _CM_8E_PT_08_PS_ADC_TEST_MODE_ADDR_MSB    0x08 // ADC TEST MODE ADDR MSB
#define _CM_8E_PT_09_PS_ADC_TEST_MODE_ADDR_LSB    0x09 // ADC TEST MODE ADDR LSB
#define _CM_8E_PT_0A_PS_ADC_FIFO_CRC_H            0x0A // ADC FIFO CRC[23:16]
#define _CM_8E_PT_0B_PS_ADC_FIFO_CRC_M            0x0B // ADC FIFO CRC[15:8]
#define _CM_8E_PT_0C_PS_ADC_FIFO_CRC_L            0x0C // ADC FIFO CRC[7:0]
#define _CM_8E_PT_0D_PS_AUTO_SOY_TEST             0x0D // Auto SOY Test

//--------------------------------------------------
// {Page2} HDCP Acess Port
//--------------------------------------------------
#define _P2_C4_PT_40_HDCP_BCAPS                   0x40 // HDCP BCAPS Register
#define _P2_C4_PT_C0_HDCP_FRAME_COUNTER           0xC0 // HDCP Frame Counter Register
#define _P2_C4_PT_C1_HDCP_SYS_INFO                0xC1 // HDCP System Information Register

//--------------------------------------------------
// {Page2} HDMI Acess Port
//--------------------------------------------------
// (Page 2-0xC9->Address, Page 2-0xCA->Data)
#define _P2_CA_PT_00_HDMI_SCR                     0x00 // HDMI Switch Control Register
#define _P2_CA_PT_01_HDMI_N_VAL                   0x01 // HDMI N Value Register
#define _P2_CA_PT_02_HDMI_BCHCR                   0x02 // HDMI BCH Control Register
#define _P2_CA_PT_03_HDMI_AFCR                    0x03 // HDMI Audio FIFO Control Register
#define _P2_CA_PT_04_HDMI_AFSR                    0x04 // HDMI Audio FIFO BIST Start Register
#define _P2_CA_PT_05_HDMI_MAGCR0                  0x05 // HDMI Maunal Gain Control Register0
#define _P2_CA_PT_06_HDMI_MAGCR1                  0x06 // HDMI Maunal Gain Control Register1
#define _P2_CA_PT_07_HDMI_MAG_M_FINAL             0x07 // HDMI Final Gain Control
#define _P2_CA_PT_08_HDMI_MAG_L_FINAL             0x08 // HDMI Full Gain (Left)
#define _P2_CA_PT_09_HDMI_MAG_R_FINAL             0x09 // HDMI Full Gain (Right)
#define _P2_CA_PT_0A_AUDIO_LD_P_TIME_M            0x0A // Wait Time for M
#define _P2_CA_PT_0B_AUDIO_LD_P_TIME_N            0x0B // Wait Time for N
#define _P2_CA_PT_0C_ZCD_CTRL                     0x0C // Zero Crossing Detection Control
#define _P2_CA_PT_0D_ZCD_TIMEOUT                  0x0D // ZCD Timeout Control
#define _P2_CA_PT_0E_ZCD_STATUS                   0x0E // ZCD Status

#define _P2_CA_PT_10_HDMI_CMCR                    0x10 // HDMI Input Clock MUX Control Register
#define _P2_CA_PT_11_HDMI_MCAPR                   0x11 // HDMI M code
#define _P2_CA_PT_12_HDMI_SCAPR                   0x12 // HDMI S code
#define _P2_CA_PT_13_HDMI_DCAPR0                  0x13 // HDMI D code HByte
#define _P2_CA_PT_14_HDMI_DCAPR1                  0x14 // HDMI D code LByte
#define _P2_CA_PT_15_HDMI_PSCR                    0x15 // HDMI Phase Tracking Enable Control Register
#define _P2_CA_PT_1A_HDMI_FTR                     0x1A // HDMI Target Time For Summation Of One Trent To Decide The Trent
#define _P2_CA_PT_1B_HDMI_FBR                     0x1B // HDMI Target FIFO Depth and Boundary Address Distance
#define _P2_CA_PT_1C_HDMI_ICPSNCR0                0x1C // HDMI I code of N/CTS
#define _P2_CA_PT_1D_HDMI_ICPSNCR1                0x1D // HDMI I code of N/CTS
#define _P2_CA_PT_1C_HDMI_PCPSNCR0                0x1E // HDMI P code of N/CTS
#define _P2_CA_PT_1D_HDMI_PCPSNCR1                0x1F // HDMI P code of N/CTS
#define _P2_CA_PT_20_HDMI_ICTPSR0                 0x20 // HDMI I Code of Trend
#define _P2_CA_PT_21_HDMI_ICTPSR1                 0x21 // HDMI I Code of Trend
#define _P2_CA_PT_22_HDMI_PCTPSR0                 0x22 // HDMI P Code of Trend
#define _P2_CA_PT_23_HDMI_PCTPSR1                 0x23 // HDMI P Code of Trend
#define _P2_CA_PT_24_HDMI_ICBPSR0                 0x24 // HDMI I Code of Boundary
#define _P2_CA_PT_25_HDMI_ICBPSR1                 0x25 // HDMI I Code of Boundary
#define _P2_CA_PT_26_HDMI_PCBPSR0                 0x26 // HDMI P Code of Boundary HByte
#define _P2_CA_PT_27_HDMI_PCBPSR1                 0x27 // HDMI P Code of Boundary LByte
#define _P2_CA_PT_28_HDMI_NTX1024TR0              0x28 // HDMI Masure the length of 1024 TV by Crystal
#define _P2_CA_PT_29_HDMI_NTX1024TR1              0x29 // HDMI Masure the length of 1024 TV by Crystal
#define _P2_CA_PT_2A_HDMI_STBPR                   0x2A // HDMI Boundary Tracking Update Response Time
#define _P2_CA_PT_2B_HDMI_NCPER                   0x2B // HDMI Phase error equals how many numbers of measuring clock
#define _P2_CA_PT_2C_HDMI_PETR                    0x2C // HDMI Phase error threshold of audio PLL non-lock
#define _P2_CA_PT_2D_HDMI_AAPNR                   0x2D // HDMI Phase Swallow Enable Control Register
#define _P2_CA_PT_2E_HDMI_APDMCR                  0x2E // HDMI Phase Swallow Cycle Register

#define _P2_CA_PT_30_HDMI_AVMCR                   0x30 // HDMI Audio/Video Mute Control Register
#define _P2_CA_PT_31_HDMI_WDCR0                   0x31 // HDMI Watch Dog Control Register0
#define _P2_CA_PT_32_HDMI_WDCR1                   0x32 // HDMI Watch Dog Control Register1
#define _P2_CA_PT_33_HDMI_WDCR2                   0x33 // HDMI Watch Dog Control Register2
#define _P2_CA_PT_34_HDMI_DBCR                    0x34 // HDMI Auto Load Double Buffer Enable
#define _P2_CA_PT_35_HDMI_APTMCR0                 0x35 // HDMI phase shift amount for a step
#define _P2_CA_PT_36_HDMI_APTMCR1                 0x36 // HDMI phase shift direction
#define _P2_CA_PT_38_HDMI_DPCR0                   0x38 // HDMI DPLL Control Register0
#define _P2_CA_PT_39_HDMI_DPCR1                   0x39 // HDMI DPLL Control Register1
#define _P2_CA_PT_3A_HDMI_DPCR2                   0x3A // HDMI DPLL Control Register2
#define _P2_CA_PT_3B_HDMI_DPCR3                   0x3B // HDMI DPLL Control Register3
#define _P2_CA_PT_3C_HDMI_SUMCM                   0x3C // SDM SumC[15:8]
#define _P2_CA_PT_3D_HDMI_SUMCL                   0x3D // SDM SumC[7:0]

#define _P2_CA_PT_40_HDMI_AWDSR                   0x40 // HDMI Audio watch dog for Packet variation status
#define _P2_CA_PT_41_HDMI_VWDSR                   0x41 // HDMI Video Watch Dog For Packet Variation Status
#define _P2_CA_PT_42_HDMI_PAMICR                  0x42 // HDMI IRQ control for Packet variation status
#define _P2_CA_PT_43_HDMI_PTRSV0                  0x43 // HDMI Packet Type of RSV0 packet
#define _P2_CA_PT_44_HDMI_PTRSV1                  0x44 // HDMI Packet Type of RSV1 packet
#define _P2_CA_PT_45_HDMI_PVGCR0                  0x45 // HDMI Packet Variation Status Enable Control Register0
#define _P2_CA_PT_46_HDMI_PVGCR1                  0x46 // HDMI Packet Variation Status Enable Control Register1
#define _P2_CA_PT_47_HDMI_PVGCR2                  0x47 // HDMI Packet Variation Status Enable Control Register2
#define _P2_CA_PT_48_HDMI_PVSR0                   0x48 // HDMI Packet Variation Status Register0
#define _P2_CA_PT_49_HDMI_PVSR1                   0x49 // HDMI Packet Variation Status Register1
#define _P2_CA_PT_4A_HDMI_PVSR2                   0x4A // HDMI Packet Variation Status Register2

#define _P2_CA_PT_50_HDMI_VCR                     0x50 // HDMI Video Mode Control Register
#define _P2_CA_PT_51_HDMI_ACRCR                   0x51 // HDMI Color Space Control Register0
#define _P2_CA_PT_52_HDMI_ACRSR0                  0x52 // HDMI CTS in usage Register(CTS[19:12])
#define _P2_CA_PT_53_HDMI_ACRSR1                  0x53 // HDMI CTS in usage Register(CTS[11:4])
#define _P2_CA_PT_54_HDMI_ACRSR2                  0x54 // HDMI CTS in usage Register(CTS[3:0] N(19:16))
#define _P2_CA_PT_55_HDMI_ACRSR3                  0x55 // HDMI CTS in usage Register(N(15:8))
#define _P2_CA_PT_56_HDMI_ACRSR4                  0x56 // HDMI CTS in usage Register(N(7:0))
#define _P2_CA_PT_57_HDMI_ACS0                    0x57 // HDMI Channel status Register0
#define _P2_CA_PT_58_HDMI_ACS1                    0x58 // HDMI Channel status Register1
#define _P2_CA_PT_59_HDMI_ACS2                    0x59 // HDMI Channel status Register2
#define _P2_CA_PT_5A_HDMI_ACS3                    0x5A // HDMI Channel status Register3
#define _P2_CA_PT_5B_HDMI_ACS4                    0x5B // HDMI Channel status Register4

#define _P2_CA_PT_60_HDMI_INTCR                   0x60 // HDMI Interrupt Control Register
#define _P2_CA_PT_61_HDMI_ALCR                    0x61 // HDMI Speaker location of I2S & SPDIF OUT
#define _P2_CA_PT_62_HDMI_AOCR                    0x62 // HDMI SPDIF/I2S Switch Control Register

#define _P2_CA_PT_70_HDMI_BCSR                    0x70 // HDMI BCSR Register
#define _P2_CA_PT_71_HDMI_ASR0                    0x71 // HDMI ASR0 Register
#define _P2_CA_PT_72_HDMI_ASR1                    0x72 // HDMI ASR1 Register

#define _P2_CA_PT_80_HDMI_DPC_SET0                0x80 // HDMI DPC SET Register0
#define _P2_CA_PT_81_HDMI_DPC_SET1                0x81 // HDMI DPC SET Register1
#define _P2_CA_PT_82_HDMI_DPC_SET2                0x82 // HDMI DPC SET Register2
#define _P2_CA_PT_83_HDMI_DPC_SET3                0x83 // HDMI DPC SET Register3
#define _P2_CA_PT_84_TMDS_DET_0                   0x84 // Decoding Error Control Register 1
#define _P2_CA_PT_85_TMDS_DET_1                   0x85 // Decoding Error Control Register 2
#define _P2_CA_PT_86_TMDS_DET_2                   0x86 // R,G,B Channel DE Period Flag
#define _P2_CA_PT_87_TMDS_DET_3                   0x87 // Error Count Threshold Value Setting
#define _P2_CA_PT_88_TMDS_DET_4                   0x88 // Negative DE Error Count Threshold Value Setting

#define _P2_CA_PT_90_AUDIO_FREQDET                0x90 // Detection of the audio sampling rate
#define _P2_CA_PT_91_AUDIO_FREQDET_RESULT_M       0x91 // The number of audio packets in 1ms MSB
#define _P2_CA_PT_92_AUDIO_FREQDET_RESULT_L       0x92 // The number of audio packets in 1ms LSB
#define _P2_CA_PT_93_XTAL_DIV                     0x93 // Select the most proper divider that the output clock will approximate
#define _P2_CA_PT_94_RANGE0_M                     0x94 // Range 0 and Range 1's Threshold[11:8]
#define _P2_CA_PT_95_RANGE0_L                     0x95 // Range 0 Threshold[7:0]
#define _P2_CA_PT_96_RANGE1_L                     0x96 // Range 1 Threshold[7:0]
#define _P2_CA_PT_97_RANGE2_M                     0x97 // Range 2 and Range 3's Threshold[11:8]
#define _P2_CA_PT_98_RANGE2_L                     0x98 // Range 2 Threshold[7:0]
#define _P2_CA_PT_99_RANGE3_L                     0x99 // Range 3 Threshold[7:0]
#define _P2_CA_PT_9A_RANGE4_M                     0x9A // Range 4 and Range 5's Threshold[11:8]
#define _P2_CA_PT_9B_RANGE4_L                     0x9B // Range 4 Threshold[7:0]
#define _P2_CA_PT_9C_RANGE5_L                     0x9C // Range 5 Threshold[7:0]
#define _P2_CA_PT_9D_PRESET_S_CODE0               0x9D // Pre-set S1 & S Code for Range 0
#define _P2_CA_PT_9E_PRESET_S_CODE1               0x9E // Pre-set S1 & S Code for Range 1
#define _P2_CA_PT_9F_PRESET_S_CODE2               0x9F // Pre-set S1 & S Code for Range 2

#define _P2_CA_PT_A0_PRESET_S_CODE3_A0            0xA0 // Pre-set S1 & S Code for Range 3
#define _P2_CA_PT_A1_PRESET_S_CODE4_A1            0xA1 // Pre-set S1 & S Code for Range 4
#define _P2_CA_PT_A2_PRESET_S2_CODE_A2            0xA2 // Pre-set S1_MSB Code for Range 0~4
#define _P2_CA_PT_A3_AFSM_MOD_A3                  0xA3 // Hardware Control for Audio
#define _P2_CA_PT_A4_HDMI_PTRSV2                  0xA4 // HDMI Packet Type of RSV2 packet
#define _P2_CA_PT_A5_HDMI_PTRSV3                  0xA5 // HDMI Packet Type of RSV3 packet
#define _P2_CA_PT_A7_HDMI_GPVS0                   0xA7 // HDMI Packet Type of RSV2 & RSV3 Variation Status
#define _P2_CA_PT_A8_HDMI_PVSR3                   0xA8 // HDMI Packet Variation Status Register4
#define _P2_CA_PT_A9_HDMI_PVSR4                   0xA9 // HDMI Packet Variation Status Register5
#define _P2_CA_PT_AA_HDMI_PVGCR3                  0xAA // HDMI Packet Variation Status Enable Control Register4
#define _P2_CA_PT_AB_HDMI_PVGCR4                  0xAB // HDMI Packet Variation Status Enable Control Register5

//--------------------------------------------------
// DCC Page Port - P7CA-Page0
//--------------------------------------------------
#define _P7_CA_PT_P0_00_NOR_FACTOR_H              0x00 // Normailized Factor Bit[21:16]
#define _P7_CA_PT_P0_01_NOR_FACTOR_M              0x01 // Normailized Factor Bit[15:8]
#define _P7_CA_PT_P0_02_NOR_FACTOR_L              0x02 // Normailized Factor Bit[7:0]
#define _P7_CA_PT_P0_03_BBE_CTRL                  0x03 // Black-Background Control Register
#define _P7_CA_PT_P0_04_NFTL_CTRL                 0x04 // Noise Filter Control Register
#define _P7_CA_PT_P0_05_HIST_CTRL                 0x05 // Histogram Control Register
#define _P7_CA_PT_P0_06_SOFT_CLAMP                0x06 // Slope of Soft-Clamping
#define _P7_CA_PT_P0_07_Y_MAX_LB                  0x07 // Lower Bound of Y_MAX
#define _P7_CA_PT_P0_08_Y_MIN_HB                  0x08 // Higher Bound of Y_MAX
#define _P7_CA_PT_P0_09_SCG_PERIOD                0x09 // Scene-Change Control Register
#define _P7_CA_PT_P0_0A_SCG_LB                    0x0A // SCG_DIFF Lower Bound
#define _P7_CA_PT_P0_0B_SCG_HB                    0x0B // SCG_DIFF Higher Bound
#define _P7_CA_PT_P0_0C_POPUP_CTRL                0x0C // POPUP Control Register
#define _P7_CA_PT_P0_0D_SCG_DIFF                  0x0D // Histogram Difference
#define _P7_CA_PT_P0_0E_Y_MAX_VAL                 0x0E // Max { Y_MAX_LB, (Y Maximum in Current Frame / 4) }
#define _P7_CA_PT_P0_0F_Y_MIN_VAL                 0x0F // Min { Y_MIN_HB, (Y Minimum in Current Frame / 4

#define _P7_CA_PT_P0_10_S0_VALUE                  0x10 // Normalized Histogram S0 Value
#define _P7_CA_PT_P0_11_S1_VALUE                  0x11 // Normalized Histogram S1 Value
#define _P7_CA_PT_P0_12_S2_VALUE                  0x12 // Normalized Histogram S2 Value
#define _P7_CA_PT_P0_13_S3_VALUE                  0x13 // Normalized Histogram S3 Value
#define _P7_CA_PT_P0_14_S4_VALUE                  0x14 // Normalized Histogram S4 Value
#define _P7_CA_PT_P0_15_S5_VALUE                  0x15 // Normalized Histogram S5 Value
#define _P7_CA_PT_P0_16_S6_VALUE                  0x16 // Normalized Histogram S6 Value
#define _P7_CA_PT_P0_17_YHL_THD                   0x17 // Y_H and Y_L Theshold
#define _P7_CA_PT_P0_18_Y_HISTOGRAM_THD           0x18 // Y Histogram Theshold

//--------------------------------------------------
// DCC Page Port - P7CA-Page1
//--------------------------------------------------
#define _P7_CA_PT_P1_00_DEF_CRV01                 0x00 // Pre-Defined Y-Curve, DEF_CRV[01]
#define _P7_CA_PT_P1_01_DEF_CRV02                 0x01 // Pre-Defined Y-Curve, DEF_CRV[02]
#define _P7_CA_PT_P1_02_DEF_CRV03                 0x02 // Pre-Defined Y-Curve, DEF_CRV[03]
#define _P7_CA_PT_P1_03_DEF_CRV04                 0x03 // Pre-Defined Y-Curve, DEF_CRV[04]
#define _P7_CA_PT_P1_04_DEF_CRV05                 0x04 // Pre-Defined Y-Curve, DEF_CRV[05]
#define _P7_CA_PT_P1_05_DEF_CRV06                 0x05 // Pre-Defined Y-Curve, DEF_CRV[06]
#define _P7_CA_PT_P1_06_DEF_CRV07                 0x06 // Pre-Defined Y-Curve, DEF_CRV[07]
#define _P7_CA_PT_P1_07_DEF_CRV08                 0x07 // Pre-Defined Y-Curve, DEF_CRV[08]
#define _P7_CA_PT_P1_08_DEF_CRV09                 0x08 // Pre-Defined Y-Curve, DEF_CRV[09]
#define _P7_CA_PT_P1_09_DEF_CRV10                 0x09 // Pre-Defined Y-Curve, DEF_CRV[10]
#define _P7_CA_PT_P1_0A_DEF_CRV11                 0x0A // Pre-Defined Y-Curve, DEF_CRV[11]
#define _P7_CA_PT_P1_0B_DEF_CRV12                 0x0B // Pre-Defined Y-Curve, DEF_CRV[12]
#define _P7_CA_PT_P1_0C_DEF_CRV13                 0x0C // Pre-Defined Y-Curve, DEF_CRV[13]
#define _P7_CA_PT_P1_0D_DEF_CRV14                 0x0D // Pre-Defined Y-Curve, DEF_CRV[14]
#define _P7_CA_PT_P1_0E_DEF_CRV15                 0x0E // Pre-Defined Y-Curve, DEF_CRV[15]
#define _P7_CA_PT_P1_0F_DEF_CRV16                 0x0F // Pre-Defined Y-Curve, DEF_CRV[16]

#define _P7_CA_PT_P1_10_Y_BL_BIAS                 0x10 // Y Offset for Black-Level Expansion
#define _P7_CA_PT_P1_11_Y_WL_BIAS                 0x11 // Y Offset for While-Level Expansion
#define _P7_CA_PT_P1_12_SAT_FACTOR                0x12 // Saturation Compensation Factor
#define _P7_CA_PT_P1_13_BLD_UB                    0x13 // Upper Bound of Blending Factor
#define _P7_CA_PT_P1_14_BLD_LB                    0x14 // Lower Bound of Blending Factor
#define _P7_CA_PT_P1_15_DEV_FACTOR                0x15 // Deviation Weighting Factor
#define _P7_CA_PT_P1_16_BLD_VAL_SEL               0x16 // White-Level Blending Control Register
#define _P7_CA_PT_P1_17_BLD_VAL                   0x17 // Max{ BLD_UB - [(DEV_VAL*DEV_FACTOR)/256],  BLD_LB}
#define _P7_CA_PT_P1_18_DEV_VAL_HI                0x18 // Bit[8:1] of Deviation Value
#define _P7_CA_PT_P1_19_DEV_VAL_LO                0x19 // Bit[0] of Deviation Value

//--------------------------------------------------
// DCC Page Port - P7CA-Page2
//--------------------------------------------------
#define _P7_CA_PT_P2_00_SRAM_INIT_VAL             0x00 // Addr 00: SRAM_00
#define _P7_CA_PT_P2_01_SRAM_INIT_VAL             0x01 // Addr 01: SRAM_01
#define _P7_CA_PT_P2_02_SRAM_INIT_VAL             0x02 // Addr 02: SRAM_02
#define _P7_CA_PT_P2_03_SRAM_INIT_VAL             0x03 // Addr 03: SRAM_03
//  ..................
#define _P7_CA_PT_P2_8C_SRAM_INIT_VAL             0x8C // Addr 8C: SRAM_8C
#define _P7_CA_PT_P2_8D_SRAM_INIT_VAL             0x8D // Addr 8D: SRAM_8D
#define _P7_CA_PT_P2_8E_SRAM_INIT_VAL             0x8E // Addr 8E: SRAM_8E
#define _P7_CA_PT_P2_8F_SRAM_INIT_VAL             0x8F // Addr 8F: SRAM_8F

//--------------------------------------------------
// DCC Page Port - P7CA-Page3
//--------------------------------------------------
#define _P7_CA_PT_P3_00_SRAM_BIST                 0x00 // SRAM Bist option

//--------------------------------------------------
// ICM Data Port
//--------------------------------------------------
#define _P7_D3_PT_00_MST_HUE_HB                   0x00 // High Byte[11:8] of Master Hue for Chroma Modifier N
#define _P7_D3_PT_01_MST_HUE_LB                   0x01 // Low Byte[7:0] of Master Hue for Chroma Modifier N
#define _P7_D3_PT_02_HUB_SEL                      0x02 // Hue Selection
#define _P7_D3_PT_03_UV_OFFSET                    0x03 // Addr 03: U Offset 00, -128~127
#define _P7_D3_PT_04_UV_OFFSET                    0x04 // Addr 04: V Offset 00, -128~127
#define _P7_D3_PT_05_UV_OFFSET                    0x05 // Addr 05: U Offset 01, -128~127
#define _P7_D3_PT_06_UV_OFFSET                    0x06 // Addr 06: V Offset 01, -128~127
//  ..................
#define _P7_D3_PT_2F_UV_OFFSET                    0x2F // Addr 2F: U Offset 26, -128~127
#define _P7_D3_PT_30_UV_OFFSET                    0x30 // Addr 30: V Offset 26, -128~127
#define _P7_D3_PT_31_UV_OFFSET                    0x31 // Addr 31: U Offset 27, -128~127
#define _P7_D3_PT_32_UV_OFFSET                    0x32 // Addr 32: V Offset 27, -128~127

//--------------------------------------------------
// Y-Peaking and coring Data Port
//--------------------------------------------------
#define _P7_D7_PT_00_PEAKING_COEF0                0x00 // Coefficient C0 of Peaking filter
#define _P7_D7_PT_01_PEAKING_COEF1                0x01 // Coefficient C1 of Peaking filter
#define _P7_D7_PT_02_PEAKING_COEF2                0x02 // Coefficient C2 of Peaking filter
#define _P7_D7_PT_03_PEAKING_MIN                  0x03 // Coring Minimum value
#define _P7_D7_PT_04_PEAKING_MAX_POS              0x04 // Coring Maximum Positive value
#define _P7_D7_PT_05_PEAKING_MAX_REG              0x05 // Coring Maximum Negitive value

//--------------------------------------------------
// DCR Data Port
//--------------------------------------------------
#define _P7_D9_PT_00_DCR_THRESHOLD1               0x00 // DCR Threshold1
#define _P7_D9_PT_01_DCR_THRESHOLD2               0x01 // DCR Threshold2
#define _P7_D9_PT_02_DCR_ABOVE_TH1_NUM2           0x02 // Total pixel number above threshold1: bit[23:16]
#define _P7_D9_PT_03_DCR_ABOVE_TH1_NUM1           0x03 // Total pixel number above threshold1: bit[15:8]
#define _P7_D9_PT_04_DCR_ABOVE_TH1_NUM0           0x04 // Total pixel number above threshold1: bit[7:0]
#define _P7_D9_PT_05_DCR_ABOVE_TH1_VAL3           0x05 // Total sum (R+G+B) of pixel value above threshold1: bit[31:24]
#define _P7_D9_PT_06_DCR_ABOVE_TH1_VAL2           0x06 // Total sum (R+G+B) of pixel value above threshold1: bit[23:16]
#define _P7_D9_PT_07_DCR_ABOVE_TH1_VAL1           0x07 // Total sum (R+G+B) of pixel value above threshold1: bit[15:8]
#define _P7_D9_PT_08_DCR_ABOVE_TH1_VAL0           0x08 // Total sum (R+G+B) of pixel value above threshold1: bit[7:0]
#define _P7_D9_PT_09_DCR_ABOVE_TH2_NUM2           0x09 // Total pixel number above threshold2: bit[23:16]
#define _P7_D9_PT_0A_DCR_ABOVE_TH2_NUM1           0x0A // Total pixel number above threshold2: bit[15:8]
#define _P7_D9_PT_0B_DCR_ABOVE_TH2_NUM0           0x0B // Total pixel number above threshold2: bit[7:0]
#define _P7_D9_PT_0C_DCR_ABOVE_TH2_VAL3           0x0C // Total sum (R+G+B) of pixel value above threshold2: bit[31:24]
#define _P7_D9_PT_0D_DCR_ABOVE_TH2_VAL2           0x0D // Total sum (R+G+B) of pixel value above threshold2: bit[23:16]
#define _P7_D9_PT_0E_DCR_ABOVE_TH2_VAL1           0x0E // Total sum (R+G+B) of pixel value above threshold2: bit[15:8]
#define _P7_D9_PT_0F_DCR_ABOVE_TH2_VAL0           0x0F // Total sum (R+G+B) of pixel value above threshold2: bit[7:0]

#define _P7_D9_PT_10_DCR_HIGH_LV_NUM_R1           0x10 // The R Highest Level Pixel Number, RMAX_NUM[15:8]
#define _P7_D9_PT_11_DCR_HIGH_LV_NUM_R0           0x11 // The R Highest Level Pixel Number, RMAX_NUM[7:0]
#define _P7_D9_PT_12_DCR_LOW_LV_NUM_R1            0x12 // The R Lowest Level Pixel Number, RMIN_NUM[15:8]
#define _P7_D9_PT_13_DCR_LOW_LV_NUM_R0            0x13 // The R Lowest Level Pixel Number, RMIN_NUM[7:0]
#define _P7_D9_PT_14_DCR_HIGH_LV_VAL_R            0x14 // The R Highest Level Value
#define _P7_D9_PT_15_DCR_LOW_LV_VAL_R             0x15 // The R Lower Level Value
#define _P7_D9_PT_16_DCR_HIGH_LV_NUM_G1           0x16 // The G Highest Level Pixel Number, GMAX_NUM[15:8]
#define _P7_D9_PT_17_DCR_HIGH_LV_NUM_G0           0x17 // The G Highest Level Pixel Number, GMAX_NUM[7:0]
#define _P7_D9_PT_18_DCR_LOW_LV_NUM_G1            0x18 // The G Lowest Level Pixel Number, GMIN_NUM[15:8]
#define _P7_D9_PT_19_DCR_LOW_LV_NUM_G0            0x19 // The G Lowest Level Pixel Number, GMIN_NUM[7:0]
#define _P7_D9_PT_1A_DCR_HIGH_LV_VAL_G            0x1A // The G Highest Level Value
#define _P7_D9_PT_1B_DCR_LOW_LV_VAL_G             0x1B // The G Lower Level Value
#define _P7_D9_PT_1C_DCR_HIGH_LV_NUM_B1           0x1C // The B Highest Level Pixel Number, BMAX_NUM[15:8]
#define _P7_D9_PT_1D_DCR_HIGH_LV_NUM_B0           0x1D // The B Highest Level Pixel Number, BMAX_NUM[7:0]
#define _P7_D9_PT_1E_DCR_LOW_LV_NUM_B1            0x1E // The B Lowest Level Pixel Number, BMIN_NUM[15:8]
#define _P7_D9_PT_1F_DCR_LOW_LV_NUM_B0            0x1F // The B Lowest Level Pixel Number, BMIN_NUM[7:0]

#define _P7_D9_PT_20_DCR_HIGH_LV_VAL_B            0x20 // B Highest Level Value
#define _P7_D9_PT_21_DCR_LOW_LV_VAL_B             0x21 // B Lower Level Value

//--------------------------------------------------
// DP accessing port
//--------------------------------------------------
#define _PC_B4_PT_00_MN_STRM_ATTR_CTRL             0x00 //
#define _PC_B4_PT_01_DP_VBID                       0x01 //
#define _PC_B4_PT_02_MN_STRM_ATTR_MISC             0x02 //
#define _PC_B4_PT_03_MN_STRM_ATTR_MISC1            0x03 //
#define _PC_B4_PT_04_MN_STRM_ATTR_HTT_M            0x04 //
#define _PC_B4_PT_05_MN_STRM_ATTR_HTT_L            0x05 //
#define _PC_B4_PT_06_MN_STRM_ATTR_HST_M            0x06 //
#define _PC_B4_PT_07_MN_STRM_ATTR_HST_L            0x07 //
#define _PC_B4_PT_08_MN_STRM_ATTR_HWD_M            0x08 //
// ...............
#define _PC_B4_PT_50_MN_SCLKG_CTRL                 0x50
#define _PC_B4_PT_51_MN_SCLKG_DIVM                 0x51
#define _PC_B4_PT_52_MN_SCLKG_DIVS                 0x52
#define _PC_B4_PT_53_MN_SCLKG_OFFS_H               0x53
#define _PC_B4_PT_54_MN_SCLKG_OFFS_M               0x54
#define _PC_B4_PT_55_MN_SCLKG_OFFS_L               0x55
#define _PC_B4_PT_56_MN_SCLKG_TRK_CTRL             0x56
#define _PC_B4_PT_57_MN_SCLKG_TRK_MN_I_H           0x57
#define _PC_B4_PT_58_MN_SCLKG_TRK_MN_I_M           0x58
#define _PC_B4_PT_59_MN_SCLKG_TRK_MN_I_L           0x59

#define _PC_B4_PT_67_MN_SCLKG_SDM_CTRL             0x67


#define _PC_B4_PT_70_MN_SCLKG_PLL_PWR              0x70 //
#define _PC_B4_PT_71_MN_SCLKG_PLL_CHP              0x71
#define _PC_B4_PT_72_MN_SCLKG_PLL_WD               0x72

#define _PC_B4_PT_D0_REV_PORT_0                    0xD0 //
#define _PC_B4_PT_D1_REV_PORT_1                    0xD1 //
#define _PC_B4_PT_D2_REV_PORT_2                    0xD2 //
#define _PC_B4_PT_D3_REV_PORT_3                    0xD3 //
#define _PC_B4_PT_D4_REV_PORT_4                    0xD4 //
#define _PC_B4_PT_D5_REV_PORT_5                    0xD5 //


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Common Page ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// Global Event Flag
//--------------------------------------------------
#define CM_00_ID_REG                        0x0000 // ID Code Register
#define CM_01_HOST_CTRL                     0x0001 // Host Control Register
#define CM_02_STATUS0                       0x0002 // Status0 Register
#define CM_03_STATUS1                       0x0003 // Status1 Register
#define CM_04_IRQ_CTRL0                     0x0004 // IRQ Control Register0
#define CM_05_HDMI_STATUS0                  0x0005 // HDMI Status0 Register
#define CM_06_HDMI_STATUS1                  0x0006 // HDMI Status1 Register
#define CM_07_NEW_ADDED_STATUS0             0x0007 // NEW Added Status0 Register
#define CM_08_NEW_ADDED_STATUS1             0x0008 // NEW Added Status1 Register
#define CM_09_POWER_CTRL0                   0x0009 // Power Control Resgister 0
#define CM_0A_POWER_CTRL1                   0x000A // Power Control Resgister 1
#define CM_0B_POWER_CTRL2                   0x000B // Power Control Resgister 2
#define CM_0C_WATCH_DOG_CTRL0               0x000C // Watch Dog Control Register0
#define CM_0D_WATCH_DOG_CTRL1               0x000D // Watch Dog Control Register1
#define CM_0F_ID_REG_02                     0x000F // ID Code Register 2

//--------------------------------------------------
// Input Video Capture
//--------------------------------------------------
#define CM_10_VGIP_CTRL                     0x0010 // Video Graphic Input Port(VGIP) Control Register
#define CM_11_VGIP_SIGINV                   0x0011 // Input Control Signal Inverted Register
#define CM_12_VGIP_DELAY_CTRL               0x0012 // VGIP Delay Control Register
#define CM_13_VGIP_ODD_CTRL                 0x0013 // VGIP Odd Control Register

//--------------------------------------------------
// Input Frame Window
//--------------------------------------------------
#define CM_14_IPH_ACT_STA_H                 0x0014 // Input Horizontal Active Start HByte
#define CM_15_IPH_ACT_STA_L                 0x0015 // Input Horizontal Active Start LByte
#define CM_16_IPH_ACT_WID_H                 0x0016 // Input Horizontal Active Width HByte
#define CM_17_IPH_ACT_WID_L                 0x0017 // Input Horizontal Active Width LByte
#define CM_18_IPV_ACT_STA_H                 0x0018 // Input Vertical Active Start HByte
#define CM_19_IPV_ACT_STA_L                 0x0019 // Input Vertical Active Start LByte
#define CM_1A_IPV_ACT_LEN_H                 0x001A // Input Vertical Active Length HByte
#define CM_1B_IPV_ACT_LEN_L                 0x001B // Input Vertical Active Length LByte
#define CM_1C_IVS_DELAY                     0x001C // Internal Input Vertical Sync(VS) Delay Control Register
#define CM_1D_IHS_DELAY                     0x001D // Internal Input Horizontal Sync(HS) Delay Control Register
#define CM_1E_VGIP_HV_DELAY                 0x001E // VGIP HS/VS Delay
#define CM_1F_V8_YUV_CONVERSION             0x001F // V8 Source Select and YUV 422 to 444 Conversion
#define CM_20_V8CLK_SEL                     0x0020 // V8clk Selection Setting

//--------------------------------------------------
// FIFO Frequency
//--------------------------------------------------
#define CM_22_FIFO_FREQUENCY                0x0022 // FIFO Frequency

//--------------------------------------------------
// Scaling Down Control
//--------------------------------------------------
#define CM_23_SCALE_DOWN_CTRL               0x0023 // Scale Down Control Register
#define CM_24_SCALE_DOWN_ACCESS_PORT        0x0024 // Scaling Down Access Port
#define CM_25_SCALE_DOWN_DATA_PORT          0x0025 // Scaling Down Data Port

//--------------------------------------------------
// Display Format(Port)
//--------------------------------------------------
#define CM_28_VDISP_CTRL                    0x0028 // Video Display Control Register
#define CM_29_VDISP_SIGINV                  0x0029 // Display Control Signal Inverted
#define CM_2A_DISP_ACCESS_PORT              0x002A // Display Format Address Port
#define CM_2B_DISP_DATA_PORT                0x002B // Display Format Data Port

//--------------------------------------------------
// Cyclic Redundant Check
//--------------------------------------------------
#define CM_2C_OP_CRC_CTRL                   0x002C // Output CRC Control Register
#define CM_2D_OP_CRC_CKSM                   0x002D // Output CRC Checksum

//--------------------------------------------------
// FIFO Window(Port)
//--------------------------------------------------
#define CM_30_FIFO_ACCESS_PORT              0x0030 // FIFO Window Address Port
#define CM_31_FIFO_DATA_PORT                0x0031 // FIFO Window Data Port

//--------------------------------------------------
// Scale Up Function(Port)
//--------------------------------------------------
#define CM_32_SCALE_CTRL                    0x0032 // Scale Control Register
#define CM_33_SU_ACCESS_PORT                0x0033 // Scale Up Factor Access Port
#define CM_34_SU_DATA_PORT                  0x0034 // Scale Up Factor Data Port
#define CM_35_FILTER_CTRL                   0x0035 // Filter Control Register
#define CM_36_FILTER_PORT                   0x0036 // User Defined Filter Access Port

//--------------------------------------------------
// Frame Sync Fine Tune
//--------------------------------------------------
#define CM_3D_IV_DV_DELAY_CLK_FINE          0X003D // Frame Sync Delay Fine Tuning (pixels)
#define CM_3E_IVS2DVS_DELAY_LINES_H         0x003E // IVS to DVS Lines, high byte
#define CM_40_IVS2DVS_DEALY_LINES           0x0040 // IVS to DVS Lines
#define CM_41_IV_DV_DELAY_CLK_ODD           0x0041 // Frame Sync Delay Fine Tuning
#define CM_42_IV_DV_DELAY_CLK_EVEN          0x0042 // Frame Sync Delay Fine Tuning
#define CM_43_FS_DELAY_FINE_TUNING          0x0043 // Frame Sync Delay Fine Tuning Control Register
#define CM_44_LAST_LINE_H                   0x0044 // Last Line H_Byte
#define CM_45_LAST_LINE_L                   0x0045 // Last Line L_Byte

//--------------------------------------------------
// Sync Processor(Port)
//--------------------------------------------------
#define CM_47_SYNC_SELECT                   0x0047 // Sync Select Control Register
#define CM_48_SYNC_INVERT                   0x0048 // Sync Invert Control Register
#define CM_49_SYNC_CTRL                     0x0049 // Sync Processor Control Register
#define CM_4A_STABLE_HIGH_PERIOD_H          0x004A // Stable High Period H_Byte
#define CM_4B_STABLE_HIGH_PERIOD_L          0x004B // Stable High Period L_Byte
#define CM_4C_VSYNC_COUNTER_LEVEL_MSB       0x004C // Vertical Sync Counter Level MSB
#define CM_4D_VSYNC_COUNTER_LEVEL_LSB       0x004D // Vertical Sync Counter Level LSB
#define CM_4E_HSYNC_TYPE_DETECTION_FLAG     0x004E // Hsync Type Detection Flag
#define CM_4F_STABLE_MEASURE                0x004F // Stable Measure
#define CM_50_STABLE_PERIOD_H               0x0050 // Stable Period HByte
#define CM_51_STABLE_PERIOD_L               0x0051 // Stable Period LByte
#define CM_52_MEAS_HS_PER_H                 0x0052 // HSync Period Measured Result HByte
#define CM_53_MEAS_HS_PER_L                 0x0053 // HSync Period Measured Result LByte
#define CM_54_MEAS_VS_PER_H                 0x0054 // VSYNC Period Measured Result
#define CM_55_MEAS_VS_PER_L                 0x0055 // VSYNC Period Measured Result
#define CM_56_MEAS_HS_VS_HI_H               0x0056 // HSync and VSync High Period Measured Results HByte
#define CM_57_MEAS_HS_VS_HI_L               0x0057 // HSync and VSync High Period Measured Results LByte
#define CM_58_MEAS_HS_VS_HI_SEL             0x0058 // HSync and VSync High Period Measured Select
#define CM_59_MEAS_ACTIVE_REGION_H          0x0059 // Active Region Measured by Crystal Clock
#define CM_5A_SYNC_TEST_MISC                0x005A // Sync Test MISC Register
#define CM_5B_HS_DETECT                     0x005B // HS and SOG detected flag
#define CM_5C_SYNC_PROC_ACCESS_PORT         0x005C // Sync Processor Access Port Address
#define CM_5D_SYNC_PROC_DATA_PORT           0x005D // Sync Processor Access Port Data

//--------------------------------------------------
// Hightlight Window(Port)
//--------------------------------------------------
#define CM_60_HW_ACCESS_PORT                0x0060 // Highlight Window Access Port
#define CM_61_HW_DATA_PORT                  0x0061 // Highlight Window Data Port

//--------------------------------------------------
// Color Processor Control(Port)
//--------------------------------------------------
#define CM_62_COLOR_CTRL                    0x0062 // Color Processor Control Register
#define CM_63_SRGB_ACCESS_PORT              0x0063 // sRGB Access Port

//--------------------------------------------------
// Contrast/Brightness Coefficient(Port)
//--------------------------------------------------
#define CM_64_CB_ACCESS_PORT                0x0064 // Contrast/Brightness Access Port
#define CM_65_CB_DATA_PORT                  0x0065 // Contrast/Brightness Data Port

//--------------------------------------------------
// Gamma Control
//--------------------------------------------------
#define CM_66_GAMMA_PORT                    0x0066 // Gamma Access Port
#define CM_67_GAMMA_CTRL                    0x0067 // Gamma Control Register
#define CM_68_GAMMA_BIST                    0x0068 // Gamma BIST Control Register

//--------------------------------------------------
// Dithering Control (D domain)
//--------------------------------------------------
#define CM_69_DITHERING_DATA_ACCESS         0x0069 // Dithering Table DATA ACCESS (D Domain)
#define CM_6A_DITHERING_CTRL1               0x006A // Dithering Control Register
#define CM_6B_DITHERING_CTRL2               0x006B // Dithering Table Reference

//--------------------------------------------------
// Overlay/Color Palette/Background Color Control
//--------------------------------------------------
#define CM_6C_OVERLAY_CTRL                  0x006C // Overlay Display Control Register
#define CM_6D_BGND_COLOR_CTRL               0x006D // Background Color Control Register
#define CM_6E_OVERLAY_LUT_ADDR              0x006E // Overlay Look Up Table (LUT) Address
#define CM_6F_COLOR_LUT_PORT                0x006F // Color LUT Access Port

//--------------------------------------------------
// Image Auto Function
//--------------------------------------------------
#define CM_70_H_BOUNDARY_H                  0x0070 // Horizontal Start/End Boundary HByte
#define CM_71_H_BOUNDARY_STA_L              0x0071 // Horizontal Start Boundary HByte
#define CM_72_H_BOUNDARY_END_L              0x0072 // Horizontal End Boundary HByte
#define CM_73_V_BOUNDARY_H                  0x0073 // Vertical Start/End Boundary HByte
#define CM_74_V_BOUNDARY_STA_L              0x0074 // Vertical Start Boundary LByte
#define CM_75_V_BOUNDARY_END_L              0x0075 // Vertical End Boundary LByte
#define CM_76_RED_NOISE_MARGIN              0x0076 // Red Noise Margin Control Register
#define CM_77_GRN_NOISE_MARGIN              0x0077 // Green Noise Margin Control Register
#define CM_78_BLU_NOISE_MARGIN              0x0078 // Blue Noise Margin Control Register
#define CM_79_DIFF_THRESHOLD                0x0079 // Difference Threshold
#define CM_7A_AUTO_ADJ_CTRL0                0x007A // Auto Adjusting Control Register 0
#define CM_7B_HW_AUTO_PHASE_CTRL0           0x007B // Hardware Auto Phase Control Register 0
#define CM_7C_HW_AUTO_PHASE_CTRL1           0x007C // Hardware Auto Phase Control Register 1
#define CM_7D_AUTO_ADJ_CTRL1                0x007D // Auto Adjusting Control Register 1
#define CM_7E_V_START_END_H                 0x007E // Active Region Vertical Start/End HByte
#define CM_7F_V_START_L                     0x007F // Active Region Vertical Start LByte
#define CM_80_V_END_L                       0x0080 // Active Region Vertical End LByte
#define CM_81_H_START_END_H                 0x0081 // Active Region Horizontal Start/End HByte
#define CM_82_H_START_L                     0x0082 // Active Region Horizontal Start LByte
#define CM_83_H_END_L                       0x0083 // Active Region Horizontal End LByte
#define CM_84_AUTO_PHASE_3                  0x0084 // Auto Phase Result Register Byte 3
#define CM_85_AUTO_PHASE_2                  0x0085 // Auto Phase Result Register Byte 2
#define CM_86_AUTO_PHASE_1                  0x0086 // Auto Phase Result Register Byte 1
#define CM_87_AUTO_PHASE_0                  0x0087 // Auto Phase Result Register Byte 0

//--------------------------------------------------
// Embedded Timing Controller(Port)
//--------------------------------------------------
#define CM_8B_TCON_ADDR_PORT                0x008B // TCON Address Port for Embedded TCON Access
#define CM_8C_TCON_DATA_PORT                0x008C // TCON Data Port for Embedded TCON Access

//--------------------------------------------------
// Pin Configuration & Test Function(Port)
//--------------------------------------------------
#define CM_8D_PS_ACCESS_PORT                0x008D // Pin Share Access Port
#define CM_8E_PS_DATA_PORT                  0x008E // Pin Share Data Port

//--------------------------------------------------
// Embedded OSD
//--------------------------------------------------
#define CM_90_OSD_ADDR_MSB                  0x0090 // OSD Address MSB
#define CM_91_OSD_ADDR_LSB                  0x0091 // OSD Address LSB
#define CM_92_OSD_DATA_PORT                 0x0092 // OSD Data Port
#define CM_93_OSD_SCRAMBLE                  0x0093 // OSD Scramble
#define CM_94_OSD_TEST                      0x0094 // OSD Test

//--------------------------------------------------
// Digital Filter
//--------------------------------------------------
#define CM_98_DIGITAL_FILTER_CTRL           0x0098 // Digital Filter Control Register
#define CM_99_DIGITAL_FILTER_PORT           0x0099 // Digital Filter Port

//--------------------------------------------------
// Paged Control Register
//--------------------------------------------------
#define CM_9F_PAGE_SEL                      0x009F // Page Selector (CR[A0] ~ CR[FF])

///////////////////////////////////////////////////////// ////////////////////////////////
///////////////////////////////////// Page 0: Embedded AD C //////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// Embedded ADC(Page0)
//--------------------------------------------------
#define P0_B7_REV_REG3                      0x00B7 // Reserved reg 3
#define P0_B8_REV_REG4                      0x00B8 // Reserved reg 4
#define P0_B9_REV_REG5                      0x00B9 // Reserved reg 5
#define P0_BA_ADC_POWER_SOG_SOY_CTRL        0x00BA // ADC Power for SOG /SOY
#define P0_BB_ADC_2X_SAMPLE                 0x00BB // ADC 2X Sample Clock Select
#define P0_BC_ADC_CLOCK                     0x00BC // ADC Clock Output Select
#define P0_BD_ADC_TEST                      0x00BD // ADC Test Function
#define P0_BE_ADC_RGB_GAIN_LSB              0x00BE // ADC RGB Gain LSB
#define P0_BF_ADC_RGB_OFFSET_LSB            0x00BF // ADC RGB Offset LSB

#define P0_C0_RED_GAIN_MSG                  0x00C0 // ADC Red Channel Gain Adjust
#define P0_C1_GRN_GAIN_MSG                  0x00C1 // ADC Green Channel Gain Adjust
#define P0_C2_BLU_GAIN_MSG                  0x00C2 // ADC Blue Channel Gain Adjust
#define P0_C3_RED_OFFSET_MSG                0x00C3 // ADC Red Channel Offset Adjust
#define P0_C4_GRN_OFFSET_MSG                0x00C4 // ADC Green Channel Offset Adjust
#define P0_C5_BLU_OFFSET_MSG                0x00C5 // ADC Blue Channel Offset Adjust
#define P0_C6_ADC_POWER                     0x00C6 // ADC Power Control Register
#define P0_C7_ADC_I_BAIS0                   0x00C7 // ADC Bais Current Control Register0
#define P0_C8_ADC_I_BAIS1                   0x00C8 // ADC Bais Current Control Register1
#define P0_C9_ADC_I_BAIS2                   0x00C9 // ADC Bais Current Control Register2
#define P0_CA_ADC_I_BAIS3                   0x00CA // ADC Bais Current Control Register3
#define P0_CB_ADC_I_BAIS4                   0x00CB // ADC Bais Current Control Register4
#define P0_CC_ADC_V_BIAS0                   0x00CC // ADC Bais Voltage Control Register0
#define P0_CD_ADC_V_BIAS1                   0x00CD // ADC Bais Voltage Control Register1
#define P0_CE_ADC_CTL_RGB                   0x00CE // ADC RGB Control Register
#define P0_CF_ADC_CTL_RED                   0x00CF // ADC Red Channel Control Register

#define P0_D0_ADC_CTL_GRN                   0x00D0 // ADC Green Channel Control Register
#define P0_D1_ADC_CTL_BLU                   0x00D1 // ADC Blue Channel Control Register
#define P0_D2_ADC_SOG_CMP                   0x00D2 // ADC SOG Input Mux Select
#define P0_D3_ADC_DCR_CTRL                  0x00D3 // ADC DCR Reference Control Register
#define P0_D4_ADC_CLAMP_CTRL0               0x00D4 // ADC Clamp Control Register0
#define P0_D5_ADC_CLAMP_CTRL1               0x00D5 // ADC Clamp Control Register1
#define P0_D6_ADC_CLAMP_CTRL2               0x00D6 // ADC Clamp Control Register2
#define P0_D7_ADC_SOG_DAC_SOY_CONTROL       0x00D7 // ADC SOG0 DAC Control
#define P0_D8_TEST_PTN_POS_H                0x00D8 // Test Pattern H/V Position HByte
#define P0_D9_TEST_PTN_VPOS_L               0x00D9 // Assign the test pattern digitized position(LByte) in line after V_Start.
#define P0_DA_TEST_PTN_HPOS_L               0x00DA // Assign the test pattern digitized position(LByte) in line after H_Start.
#define P0_DB_TEST_PTN_RD                   0x00DB // Test Pattern Red Channel Digitized Result
#define P0_DC_TEST_PTN_GD                   0x00DC // Test Pattern Green Channel Digitized Result
#define P0_DD_TEST_PTN_BD                   0x00DD // Test Pattern Blue Channel Digitized Result

#define P0_DF_EBD_REGLATOR_A_CTRL           0x00DF // Test Pattern Control
#define P0_E0_EBD_REGLATOR_DB_CTRL          0x00E0 // Test Pattern Control

//--------------------------------------------------
// Auto Black Level (Page0)
//--------------------------------------------------
#define P0_E2_ABL_CTRL1                     0x00E2 // Auto Black Level Control Register1
#define P0_E3_ABL_CTRL2                     0x00E3 // Auto Black Level Control Register2
#define P0_E4_ABL_CTRL3                     0x00E4 // Auto Black Level Control Register3
#define P0_E5_ABL_CTRL4                     0x00E5 // Auto Black Level Control Register4
#define P0_E6_ABL_CTRL5                     0x00E6 // Auto Black Level Control Register5
#define P0_E7_ABL_CTRL6                     0x00E7 // Auto Black Level Control Register6
#define P0_E8_ABL_CTRL7                     0x00E8 // Auto Black Level Control Register7
#define P0_E9_ABL_R_VALUE                   0x00E9 // Auto Black Level Value of Red Channel in Test Mode
#define P0_EA_ABL_G_VALUE                   0x00EA // Auto Black Level Value of Green Channel in Test Mode
#define P0_EB_ABL_B_VALUE                   0x00EB // Auto Black Level Value of Blue Channel in Test Mode
#define P0_EC_ABL_R_NOISE_VALUE             0x00EC // Auto Black Level Noise Value of Red Channel in Test Mode
#define P0_ED_ABL_G_NOISE_VALUE             0x00ED // Auto Black Level Noise Value of Green Channel in Test Mode
#define P0_EE_ABL_B_NOISE_VALUE             0x00EE // Auto Black Level Noise Value of Blue Channel in Test Mode
#define P0_EF_ABL_CTRL8                     0x00EF // Auto Black Level Control Register8

//--------------------------------------------------
// Low Voltage Reset (Page0)
//--------------------------------------------------
#define P0_F3_POWER_ON_RESET                0x00F3 // Negative Threshold Value For Power On Reset

//--------------------------------------------------
// Schmitt Trigger Control (Page0)
//--------------------------------------------------
#define P0_F2_HS_SCHMITT_TRIGGE_CTRL2       0x00F2 // Schmitt Trigger New 2 Mode Control Register
#define P0_F4_HS_SCHMITT_TRIGGER_CTRL       0x00F4 // Schmitt Trigger Control Register


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 1: PLL ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// DDS Setting For ADC PLL (Page1)
//--------------------------------------------------
#define P1_A0_PLL_DIV_CTRL                  0x01A0 // PLL DIV Control Register
#define P1_A1_I_CODE_M                      0x01A1 // I Code MByte
#define P1_A2_I_CODE_L                      0x01A2 // I Code LByte
#define P1_A3_P_CODE                        0x01A3 // P Code
#define P1_A4_PFD_CALIBRATED_RESULTS_H      0x01A4 // PFD Calibrated Result HByte
#define P1_A5_PFD_CALIBRATED_RESULTS_L      0x01A5 // PFD Calibrated Result LByte
#define P1_A6_PE_MEASURE_H                  0x01A6 // Phase Error Measure HByte
#define P1_A7_PE_MEASURE_L                  0x01A7 // Phase Error Measure LByte
#define P1_A8_PE_MAX_MEASURE_H              0x01A8 // Phase Error Max MEasure HByte
#define P1_A9_PE_MAX_MEASURE_L              0x01A9 // Phase Error Max MEasure LByte
#define P1_AA_FAST_PLL_CTRL                 0x01AA // Fast PLL Control Register
#define P1_AB_FAST_PLL_SUM_I                0x01AB // Fast PLL SUM_I

//--------------------------------------------------
// ADC PLL (Page1)
//--------------------------------------------------
#define P1_AC_PLL_M                         0x01AC // PLL M code
#define P1_AD_PLL_N                         0x01AD // PLL N Code
#define P1_AE_PLL_CRNT                      0x01AE // PLL Current/Resistor Register
#define P1_AF_PLL_WD                        0x01AF // PLL Watch Dog Register

#define P1_B0_MIX                           0x01B0 // PLL Mix Register
#define P1_B1_PLLDIV_H                      0x01B1 // PLL DIV HByte
#define P1_B2_PLLDIV_L                      0x01B2 // PLL DIV LByte
#define P1_B3_PLLPHASE_CTRL0                0x01B3 // PLL Phase Control Register0 (Select Phase to A/D)
#define P1_B4_PLLPHASE_CTRL1                0x01B4 // PLL Phase Control Register1 (Select Phase to A/D)
#define P1_B5_PLL_PHASE_INTERPOLATION       0x01B5 // PLL Phase Interpolation
#define P1_B6_P_CODE_MAPPING_METHOD         0x01B6 // P Code Mapping Method
#define P1_B7_PE_TRACKING_METHOD            0x01B7 // PE Tracking Method
#define P1_B8_DDS_MIX_1                     0x01B8 // DDS Mix 1
#define P1_B9_DDS_MIX_2                     0x01B9 // DDS Mix 2
#define P1_BA_DDS_MIX_3                     0x01BA // DDS Mix 3
#define P1_BB_DDS_MIX_4                     0x01BB // DDS Mix 4
#define P1_BC_DDS_MIX_5                     0x01BC // DDS Mix 5
#define P1_BD_DDS_MIX_6                     0x01BD // DDS Mix 6
#define P1_BE_DDS_MIX_7                     0x01BE // DDS Mix 7

//--------------------------------------------------
// DPLL/ LVDS PLL combine(Page1)
//--------------------------------------------------
#define P1_C0_DPLL_NF_0                     0x01C0 // DPLL N.F[27:24]
#define P1_C1_DPLL_NF_1                     0x01C1 // DPLL N.F[23:16]
#define P1_C2_DPLL_NF_2                     0x01C2 // DPLL N.F[15:8]
#define P1_C3_DPLL_NF_3                     0x01C3 // DPLL N.F[7:0]

#define P1_C4_SDM_0                         0x01C4
#define P1_C5_SDM_1                         0x01C5
#define P1_C6_SDM_2                         0x01C6

#define P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M   0x01C7 // Even Fixed Last Line MSB
#define P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L   0x01C8 // Even Fixed Last Line DVTotal LSB
#define P1_C9_EVEN_FIX_LASTLINE_LENGTH_L    0x01C9 // Even Fixed Last Line Length LSB

#define P1_CA_SSCG_0                        0x01CA // SSCG setting
#define P1_CB_SSCG_1                        0x01CB // SSCG setting
#define P1_CC_SSCG_2                        0x01CC // SSCG setting
#define P1_CD_SSCG_3                        0x01CD // SSCG setting
#define P1_CE_SSCG_4                        0x01CE // SSCG setting
#define P1_CF_SSCG_5                        0x01CF // SSCG setting

#define P1_D0_LVDSPLL_0                     0x01D0 // LVDSPLL_0
#define P1_D1_LVDSPLL_1                     0x01D1 // LVDSPLL_1
#define P1_D2_LVDSPLL_2                     0x01D2 // LVDSPLL_2
#define P1_D3_LVDSPLL_3                     0x01D3 // [7:3]:PLL Icp   [2:0]: PLL Rs

#define P1_D4_WD_0                          0x01D4 // PLL watch dog
#define P1_D5_PLL_OUT                       0x01D5

#define P1_D6_PLL_LINEAR_CG_0               0x01D6 // PLL linear change frequency
#define P1_D7_PLL_LINEAR_CG_1               0x01D7 // PLL linear change frequency
#define P1_D8_PLL_LINEAR_CG_2               0x01D8 // PLL linear change frequency
#define P1_D9_PLL_LINEAR_CG_3               0x01D9 // PLL linear change frequency
#define P1_DA_PLL_LINEAR_CG_4               0x01DA // PLL linear change frequency

#define P1_DB_SSCG_6                        0x01DB
#define P1_DC_SSCG_7                        0x01DC
#define P1_DD_SSCG_8                        0x01DD
#define P1_DE_SSCG_9                        0x01DE
#define P1_DF_DPLL_RSV_0                    0x01DF

//--------------------------------------------------
// Multiply PLL For Input Crystal (Page1)
//--------------------------------------------------
#define P1_E0_M2PLL_M                       0x01E0 // M2PLL M Code
#define P1_E1_M2PLL_N                       0x01E1 // M2PLL N Code
#define P1_E4_M2PLL_CRNT                    0x01E4 // M2PLL Curent Control
#define P1_E5_M2PLL_WD                      0x01E5 // M2PLL Watch Dog

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 2: TMDS/HDCP/HDMI ////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// TMDS Receiver (Page2)
//--------------------------------------------------
#define P2_A1_TMDS_MEAS_SELECT             0x02A1 // TMDS Measure Select
#define P2_A2_TMDS_MEAS_RESULT0            0x02A2 // TMDS Measure Result0
#define P2_A3_TMDS_MEAS_RESULT1            0x02A3 // TMDS Measure Result1
#define P2_A4_TMDS_CTRL                    0x02A4 // TMDS Control Register
#define P2_A5_CRC_OUTPUT_BYTE_2            0x02A5 // CRC Output Byte2
#define P2_A6_TMDS_OUTPUT_CTRL             0x02A6 // TMDS Output Control Register
#define P2_A7_POWER_ON_OFF_CTRL            0x02A7 // TMDS Power On/Off Control Register
#define P2_A8_TMDS_ACC0                    0x02A8 // AVMUTE Window Range Control
#define P2_A9_TMDS_ACC1                    0x02A9 // HDCP Flag
#define P2_AA_TMDS_ABC                     0x02AA // HDCP IRQ Control
#define P2_AB_TMDS_ACC2                    0x02AB // TMDS ACC2
#define P2_AC_Z0CC2                        0x02AC // TMDS Z0 CC2
#define P2_AD_CPS                          0x02AD // TMDS CPS
#define P2_AE_TMDS_RPS                     0x02AE // TMDS RPS
#define P2_AF_TMDS_WDC                     0x02AF // TMDS WDC

#define P2_B0_CDR0                         0x02B0 // TMDS CDR Control Register 0
#define P2_B1_CDR1                         0x02B1 // TMDS CDR Control Register 1
#define P2_B2_CDR2                         0x02B2 // TMDS CDR Control Register 2
#define P2_B3_CDR2                         0x02B3 // TMDS CDR Control Register 3
#define P2_B4_TMDS_DPC0                    0x02B4 // PP & CD Value of Deep Color Mode
#define P2_B5_UP_DOWN_CTRL0                0x02B5 // Up/Down Control Register 0
#define P2_B6_UP_DOWN_CTRL1                0x02B6 // Up/Down Control Register 1
#define P2_B7_UP_DOWN_CTRL2                0x02B7 // Up/Down Control Register 2
#define P2_B8_TMDS_DPC1                    0x02B8 // Phase Select of Deep Coloe Mode
#define P2_B9_TMDS_OUT_CTRL                0x02B9 // TMDS Bypass Control
#define P2_BA_TMDS_ROUT_HIGH_BYTE          0x02BA // TMDS Rout High Byte Register Value
#define P2_BB_TMDS_ROUT_LOW_BYTE           0x02BB // TMDS Rout Low Byte Register Value
#define P2_BC_TMDS_GOUT_HIGH_BYTE          0x02BC // TMDS Gout High Byte Register Value
#define P2_BD_TMDS_GOUT_LOW_BYTE           0x02BD // TMDS Gout Low Byte Register Value
#define P2_BE_TMDS_BOUT_HIGH_BYTE          0x02BE // TMDS Bout High Byte Register Value
#define P2_BF_TMDS_BOUT_LOW_BYTE           0x02BF // TMDS Bout Low Byte Register Value

//--------------------------------------------------
// HDCP1.3(Port) (Page2)
//--------------------------------------------------
#define P2_C0_HDCP_CTRL                    0x02C0 // HDCP Control Register
#define P2_C1_DEVICE_KEY_ACCESS_PORT       0x02C1 // Device Key Access Port
#define P2_C2_HDCP_PORT_CTRL               0x02C2 // HDCP Port Control Register
#define P2_C3_HDCP_ADDR_PORT               0x02C3 // HDCP Address Port
#define P2_C4_HDCP_DATA_PORT               0x02C4 // HDCP Data Port

//--------------------------------------------------
// HDMI(Port) (Page2)
//--------------------------------------------------
#define P2_C8_HDMI_APC                     0x02C8 // HDMI APC
#define P2_C9_HDMI_ADDR_PORT               0x02C9 // HDMI Address Port
#define P2_CA_HDMI_DATA_PORT               0x02CA // HDMI Data Port
#define P2_CB_HDMI_SR                      0x02CB // HDMI Status Register
#define P2_CC_HDMI_GPVS                    0x02CC // HDMI Packet Variation Status Register
#define P2_CD_HDMI_PSAP                    0x02CD // HDMI Address For Packet Storage SRAM
#define P2_CE_HDMI_DSDP                    0x02CE // HDMI Data For Packet Storage SRAM

//--------------------------------------------------
// AUX Power Saving Mode (Page2)
//--------------------------------------------------
#define P2_E0_AUX_PS_CTRL                  0x02E0 // AUX Power Saving Control
#define P2_E1_AUX_PS_REPLY                 0x02E1 // AUX Power Saving Reply
#define P2_E2_AUX_PS_DUMMY1                0x02E2 // AUX Power Saving Dummy1 Register
#define P2_E3_AUX_PS_DUMMY1                0x02E3 // AUX Power Saving Mode Timeout Target
#define P2_E4_AUX_PS_RX_SIGNAL1            0x02E4 // AUX Rx Command
#define P2_E5_AUX_PS_RX_SIGNAL2            0x02E5 // AUX Receive 20 bits address[15:8] & [3:0]
#define P2_E6_HDMI_FREQDET_CTRL            0x02E6 // HDMI Frequency Detect For Power Saving Mode
#define P2_E7_HDMI_FREQDET_OFFSET          0x02E7 // Determine the pre-set threshold, within which means the frequency is still stable
#define P2_E8_HDMI_FREQDET_UPPER_M         0x02E8 // Unstable Upper Bound[14:8]
#define P2_E9_HDMI_FREQDET_UPPER_L         0x02E9 // Unstable Upper Bound[7:0]
#define P2_EA_HDMI_FREQDET_LOWER_M         0x02EA // Unstable Lower Bound[14:8]
#define P2_EB_HDMI_FREQDET_LOWER_L         0x02EB // Unstable Lower Bound[7:0]
#define P2_EC_HDMI_FREQDET_STABLE          0x02EC // Determine Times Threshold For The Frequency that Can Be Regarded as Stable
#define P2_ED_HDMI_FREQDET_RESULT_M        0x02ED // The result of frequency counter[14:8]
#define P2_EE_HDMI_FREQDET_RESULT_L        0x02EE // The result of frequency counter[7:0]
#define P2_EF_HDMI_FREQDET_RESERVED        0x02EF // HDMI Frequency Reserved Register


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Page 6: Internal OSC //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// Internal OSC (Page 6)
//--------------------------------------------------
#define P6_A0_OSC_TRIM_CTRL0               0x06A0 // OSC Trimming Control Register
#define P6_A1_OSC_TRIM_CTRL1               0x06A1 // OSC Trimming Comparison Target
#define P6_A2_OSC_TRIM_CTRL2               0x06A2 // OSC Trimming Result
#define P6_A3_EMBEDDED_OSC_CTRL            0x06A3 // Embedded OSC Control
#define P6_A4_OSC_TRIM_CNT                 0x06A4 // OSC Trimming Counter
#define P6_A5_EMB_BGRES                    0x06A5 // Embedded OSC Thermal Compensation


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 7: Vivid Color ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// Vivid Color - DCC (Page7)
//--------------------------------------------------
#define P7_C7_DCC_CTRL0                    0x07C7 // DCC Control Register 0
#define P7_C8_DCC_CTRL1                    0x07C8 // DCC Control Register 1
#define P7_C9_DCC_ACCESS_PORT              0x07C9 // DCC Access Port
#define P7_CA_DCC_DATA_PORT                0x07CA // DCC Data Port

//--------------------------------------------------
// Vivid Color - ICM (Page7)
//--------------------------------------------------
#define P7_D0_ICM_CTRL                     0x07D0 // ICM Control Register
#define P7_D1_ICM_SEL                      0x07D1 // ICM Accessing Through Data Port Select
#define P7_D2_ICM_ACCESS_PORT              0x07D2 // ICM Access Port
#define P7_D3_ICM_DATA_PORT                0x07D3 // ICM Data Port
#define P7_D6_PKING_ACCESS_PORT            0x07D6 // Y Peaking Coring Access Port
#define P7_D7_PKING_DATA_PORT              0x07D7 // Y Peaking Coring Data Port

//--------------------------------------------------
// DCR (Page7)
//--------------------------------------------------
#define P7_D8_DCR_ACCESS_PORT              0x07D8 // DCR Access Port
#define P7_D9_DCR_DATA_PORT                0x07D9 // DCR Data Port
#define P7_DB_DCR_DATA_CTRL                0x07D8

//--------------------------------------------------
// Vivid Color - Pattern Gen. in D Domain (Page7)
//--------------------------------------------------
#define P7_F0_DISP_PG_R_CTRL               0x07F0 // Display Pattern Gen. R Control
#define P7_F1_DISP_PG_G_CTRL               0x07F1 // Display Pattern Gen. G Control
#define P7_F2_DISP_PG_B_CTRL               0x07F2 // Display Pattern Gen. B Control
#define P7_F3_DISP_PG_R_INITIAL            0x07F3 // Display Pattern Gen. R Initial Value
#define P7_F4_DISP_PG_G_INITIAL            0x07F4 // Display Pattern Gen. G Initial Value
#define P7_F5_DISP_PG_B_INITIAL            0x07F5 // Display Pattern Gen. B Initial Value
#define P7_F6_DISP_PG_PIXEL_DELTA          0x07F6 // Pixel Delta Value for Incremental
#define P7_F7_DISP_PG_LINE_DELTA           0x07F7 // Line Delta Value for Incremental
#define P7_F8_DISP_PG_PIXEL_STEP_MSB       0x07F8 // Pixel Step for Toggle/Incremental(MSB)
#define P7_F9_DISP_PG_LINE_STEP_MSB        0x07F9 // Line Step for Toggle/Incremental(MSB)
#define P7_FA_DISP_PG_STEP_LSB             0x07FA // Pixel/Line Step for Toggle/Incremental(LSB)
#define P7_FB_DISP_PG_RANDOM_CTRL          0x07FB // Control byte for random PG
#define P7_FC_DISP_PG_INITIAL_LSB          0x07FC // initial Value for RGB LSB 2bits


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page A: Reserved //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
// Reserved Page (Page A)


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page B: DisplayPort PHY ///////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define PB_A0_CMU_0                        0x0BA0 //
#define PB_A1_CMU_1                        0x0BA1 //
#define PB_A2_CMU_2                        0x0BA2 //
#define PB_A3_CMU_3                        0x0BA3 //
#define PB_A4_CMU_4                        0x0BA4 //
#define PB_A5_CMU_5                        0x0BA5 //
#define PB_A6_CMU_6                        0x0BA6 //
#define PB_A7_CMU_7                        0x0BA7 //
#define PB_A8_CDR_0                        0x0BA8 //
#define PB_A9_CDR_1                        0x0BA9 //
#define PB_AA_CDR_2                        0x0BAA //
#define PB_AB_CDR_3                        0x0BAB //
#define PB_AC_CDR_A                        0x0BAC //
#define PB_AD_RXMISC_0                     0x0BAD //
#define PB_AE_LDO_0                        0x0BAE //
#define PB_AF_LDO_1                        0x0BAF //

#define PB_B0_EQ_0                         0x0BB0 //
#define PB_B1_EQ_1                         0x0BB1 //
#define PB_B2_EQ_2                         0x0BB2 //
#define PB_B3_SINGLE_END                   0x0BB3 //
#define PB_B4_POWER_0                      0x0BB4 //
#define PB_B5_Z0_0                         0x0BB5 //
#define PB_B6_Z0_1                         0x0BB6 //
#define PB_B7_Z0_2                         0x0BB7 //
#define PB_B8_Z0_3                         0x0BB8 //
#define PB_B9_OFFCAL_0                     0x0BB9 //
#define PB_BA_OFFCAL_1                     0x0BBA //
#define PB_BB_BANDGAP                      0x0BBB //
#define PB_BC_OFFCAL_2                     0x0BBC //
#define PB_BD_OFFCAL_3                     0x0BBD //
#define PB_BE_OFFCAL_4                     0x0BBE //
#define PB_BF_OFFCAL_5                     0x0BBF //

#define PB_C0_TMDS_CONT_0                  0x0BC0 //
#define PB_C1_TMDS_CONT_1                  0x0BC1 //
#define PB_C2_TMDS_CONT_2                  0x0BC2 //
#define PB_C3_TMDS_CONT_3                  0x0BC3 //
#define PB_C4_L0_CDR_0                     0x0BC4 //
#define PB_C5_L0_CDR_1                     0x0BC5 //

#define PB_C7_L0_CDR_3                     0x0BC7 //
#define PB_C8_L0_CDR_4                     0x0BC8 //
#define PB_C9_B_CDR_5                      0x0BC9 //
#define PB_CA_L1_CDR_0                     0x0BCA //
#define PB_CB_L1_CDR_1                     0x0BCB //
#define PB_CC_L1_CDR_3                     0x0BCC //
#define PB_CD_L1_CDR_4                     0x0BCD //
#define PB_CE_L1_CDR_5                     0x0BCE //
#define PB_CF_CDR_RESERVED                 0x0BCF //

#define PB_D0_RXMISC_3                     0x0BD0 //
#define PB_D1_RXMISC_4                     0x0BD1 //
#define PB_D2_RESERVED_4                   0x0BD2 //
#define PB_D3_L2_CDR_0                     0x0BD3 //
#define PB_D4_L2_CDR_1                     0x0BD4 //
#define PB_D5_L2_CDR_3                     0x0BD5 //
#define PB_D6_L2_CDR_4                     0x0BD6 //
#define PB_D7_L2_CDR_5                     0x0BD7 //
#define PB_D8_CDR_DEBUG                    0x0BD8 //
#define PB_D9_PI_0                         0x0BD9 //
#define PB_DA_PI_1                         0x0BDA //
#define PB_DB_PI_2                         0x0BDB //
#define PB_DC_PI_3                         0x0BDC //
#define PB_DD_VCO_2                        0x0BDD //
#define PB_DE_PI_4                         0x0BDE //
#define PB_DF_PI_5                         0x0BDF //

#define PB_E0_DIG_0                        0x0BE0 //
#define PB_E1_DIG_1                        0x0BE1 //
#define PB_E2_DIG_2                        0x0BE2 //
#define PB_E3_DIG_3                        0x0BE3 //
#define PB_E4_WD_0                         0x0BE4 //
#define PB_E5_DIG_5                        0x0BE5 //
#define PB_E6_DIG_6                        0x0BE6 //
#define PB_E7_DIG_7                        0x0BE7 //
#define PB_E8_DIG_8                        0x0BE8 //
#define PB_E9_SSCG_DIG                     0x0BE9 //
#define PB_EA_DIG_RESERVED                 0x0BEA //
#define PB_EB_SDM_0                        0x0BEB //
#define PB_EC_SDM_1                        0x0BEC //
#define PB_ED_SDM_2                        0x0BED //
#define PB_EE_WD_1                         0x0BEE //
#define PB_EF_WD_2                         0x0BEF //

#define PB_F8_CLK_TIMER                    0x0BF8 //
#define PB_F9_EQEN_TIMER                   0x0BF9 //
#define PB_FA_DATA_TIMER                   0x0BFA //
#define PB_FB_OTHERS                       0x0BFB //
#define PB_FC_CDR_KI_FILTER                0x0BFC //
#define PB_FD_CDR_KI_0                     0x0BFD //
#define PB_FE_CDR_KI_1                     0x0BFE //
#define PB_FF_CDR_KI_2                     0x0BFF //


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page C: DisplayPort MAC ///////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// DisplayPort - MAC Control (PageC)
//--------------------------------------------------
#define PC_A1_DP_CTL                       0x0CA1 // DP General Control

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 10: Register4 ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------
// Pin Share(Page 10)
//--------------------------------------------------
#define P10_A0_PIN_SHARE_CTRL00            0x10A0 // Pin 41~54 of QFP 128
#define P10_A1_PIN_SHARE_CTRL01            0x10A1 // Pin 45, 119, 126 of QFP 128
#define P10_A2_PIN_SHARE_CTRL02            0x10A2 // Pin 58~59 of QFP 128
#define P10_A3_PIN_SHARE_CTRL03            0x10A3 // Pin 46, 51, 64 of QFP 128
#define P10_A4_PIN_SHARE_CTRL04            0x10A4 // Pin 52, 66, 67 of QFP 128
#define P10_A5_PIN_SHARE_CTRL05            0x10A5 // Pin 53, Pin 69~70 of QFP 128
#define P10_A6_PIN_SHARE_CTRL06            0x10A6 // Pin 47, 55, 63 of QFP 128
#define P10_A7_PIN_SHARE_CTRL07            0x10A7 // Pin 48, 68, 71 of QFP 128
#define P10_A8_PIN_SHARE_CTRL08            0x10A8 // Pin 44, 96, 97 of QFP 128
#define P10_A9_PIN_SHARE_CTRL09            0x10A9 // Pin 73~84, Pin 99~100 of QFP 128
#define P10_AA_PIN_SHARE_CTRL0A            0x10AA // Pin 98, 102, 105 QFP 128
#define P10_AB_PIN_SHARE_CTRL0B            0x10AB // Pin 50, 101, 108 of QFP 128
#define P10_AC_PIN_SHARE_CTRL0C            0x10AC // Pin 103~104 of QFP 128
#define P10_AD_PIN_SHARE_CTRL0D            0x10AD // Pin 110~104, Pin 109~110 of QFP 128
#define P10_AE_PIN_SHARE_CTRL0E            0x10AE // Pin 111~112 of QFP 128
#define P10_AF_PIN_SHARE_CTRL0F            0x10AF // Pin 56~59 of QFP 128

#define P10_B0_PIN_SHARE_CTRL10            0x10B0 // Pin 113, Pin 121~122 of QFP 128
#define P10_B1_PIN_SHARE_CTRL11            0x10B1 // Pin 65, Pin 123~124 of QFP 128
#define P10_B2_PIN_SHARE_CTRL12            0x10B2 // Pin 72, 114, Pin 121~124 of QFP 128
#define P10_B3_PIN_SHARE_CTRL13            0x10B3 // Pin Driving Control Register 1
#define P10_B4_PIN_SHARE_CTRL14            0x10B4 // Pin Driving Control Register 2
#define P10_B5_PIN_SHARE_CTRL15            0x10B5 // Pin Driving Control Register 3
#define P10_B6_PIN_SHARE_CTRL16            0x10B6 // Pin 74~79 of QFP 128
#define P10_B7_PIN_SHARE_CTRL17            0x10B7 // Pin 31~34 of QFP 128
#define P10_B8_PIN_SHARE_CTRL18            0x10B8 // Pin 35~37, 39 of QFP 128
#define P10_B9_PIN_SHARE_CTRL19            0x10B9 // Pin 40
#define P10_BA_PIN_SHARE_CTRL1A            0x10BA // Pin 40
#define P10_BB_PIN_SHARE_CTRL1B            0x10BB // Pin 40
#define P10_BC_PIN_SHARE_CTRL1C            0x10BC // Pin 40
#define P10_BD_PIN_SHARE_CTRL1D            0x10BD // Pin 40
#define P10_BE_PIN_SHARE_CTRL1E            0x10BE // Pin 40
#define P10_BF_PIN_SHARE_CTRL1F            0x10BF // Pin 40
#define P10_C0_PIN_SHARE_CTRL20            0x10C0 // Pin 40
#define P10_C1_PIN_SHARE_CTRL21            0x10C1 // Pin 40
#define P10_C2_PIN_DRIVING_CTRL0           0x10C2 // Pin 40
#define P10_C3_PIN_DRIVING_CTRL1           0x10C3 // Pin 40
#define P10_C4_PIN_SLEW_RATE_CTRL          0x10C4 // Pin 40
#define P10_C5_PIN_SCHMITT_CTRL            0x10C5 // Pin 40
#define P10_C6_XTAL_SPREAD_CTRL0           0x10C6 // Pin 40
#define P10_C7_PIN_PULLUP_CTRL0            0x10C7 // Pin 40
#define P10_C8_PIN_PULLUP_CTRL1            0x10C8 // Pin 40
#define P10_C9_PIN_PULLUP_CTRL2            0x10C9 // Pin 40
#define P10_CA_PIN_PULLUP_CTRL3            0x10CA // Pin 40
#define P10_CB_PIN_PULLUP_CTRL4            0x10CB // Pin 40
#define P10_CC_PIN_PULLUP_CTRL5            0x10CC // Pin 40
#define P10_CD_PIN_PULLUP_CTRL6            0x10CD // Pin 40
#define P10_CE_DVI_CTRL_OUT_SEL            0x10CE // Pin 40
#define P10_CF_PANEL_SWITCH_CTRL0          0x10CF // Pin 40


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Page 14: YUV to RGB////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P14_A1_SR_YCC2RGB_CTRL             0x14A1
#define P14_A2_YUB_RGB_COEF_K11_HSB        0x14A2
#define P14_A3_YUV_RGB_COEF_K11_LSB        0x14A3
#define P14_A4_YUV_RGB_COEF_K13_HSB        0x14A4
#define P14_A5_YUV_RGB_COEF_K13_LSB        0x14A5
#define P14_A6_YUV_RGB_COEF_K22_HSB        0x14A6
#define P14_A7_YUV_RGB_COEF_K22_LSB        0x14A7
#define P14_A8_YUV_RGB_COEF_K23_HSB        0x14A8
#define P14_A9_YUV_RGB_COEF_K23_LSB        0x14A9
#define P14_AA_YUV_RGB_COEF_K32_HSB        0x14AA
#define P14_AB_YUV_RGB_COEF_K32_LSB        0x14AB
#define P14_AC_YUV_RGB_R_OFFSET_HSB        0x14AC
#define P14_AD_YUV_RGB_R_OFFSET_LSB        0x14AD
#define P14_AE_YUV_RGB_G_OFFSET_HSB        0x14AE
#define P14_AF_YUV_RGB_G_OFFSET_LSB        0x14AF
#define P14_B0_YUV_RGB_B_OFFSET_HSB        0x14B0
#define P14_B1_YUV_RGB_B_OFFSET_LSB        0x14B1
#define P14_B2_YUV_RGB_R_GAIN_HSB          0x14B2
#define P14_B3_YUV_RGB_R_GAIN_LSB          0x14B3
#define P14_B4_YUV_RGB_G_GAIN_HSB          0x14B4
#define P14_B5_YUV_RGB_G_GAIN_LSB          0x14B5
#define P14_B6_YUV_RGB_B_GAIN_HSB          0x14B6
#define P14_B7_YUV_RGB_B_GAIN_LSB          0x14B7

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 1D: //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P1D_A0_DFE_EN_1                    0x1DA0 //
#define P1D_A1_DFE_EN_2                    0x1DA1 //
#define P1D_A2_LIMIT_INIT                  0x1DA2 //
#define P1D_A3_INIT_1                      0x1DA3 //
#define P1D_A4_INIT_2                      0x1DA4 //
#define P1D_A5_INIT_3                      0x1DA5 //
#define P1D_A6_INIT_4                      0x1DA6 //
#define P1D_A7_INIT_5                      0x1DA7 //
#define P1D_A8_INIT_6                      0x1DA8 //
#define P1D_A9_INIT_7                      0x1DA9 //
#define P1D_AA_INIT_8                      0x1DAA //
#define P1D_AB_STABLE_FLAG                 0x1DAB //

#define P1D_B0_DFE_TIME_SHARING_EN         0x1DB0 //

#define P1D_E0_MODE_TIMER                  0x1DE0 //
#define P1D_E1_TIMER                       0x1DE1 //
#define P1D_E2_GAIN_1                      0x1DE2 //
#define P1D_E3_GAIN_2                      0x1DE3 //
#define P1D_E4_GAIN_3                      0x1DE4 //
#define P1D_E5_GAIN_4                      0x1DE5 //
#define P1D_E6_LIMIT_1                     0x1DE6 //
#define P1D_E7_LIMIT_2                     0x1DE7 //
#define P1D_E8_LIMIT_3                     0x1DE8 //
#define P1D_E9_LIMIT_4                     0x1DE9 //
#define P1D_EA_COEF_APPLY_1                0x1DEA //
#define P1D_EB_COEF_APPLY_2                0x1DEB //
#define P1D_EC_LOOP_DIV_1                  0x1DEC //
#define P1D_ED_LOOP_DIV_2                  0x1DED //
#define P1D_EE_GRAY_DEC                    0x1DEE //
#define P1D_EF_RESET_1                     0x1DEF //

#define P1D_F0_COEF_1                      0x1DF0 //
#define P1D_F1_COEF_2                      0x1DF1 //
#define P1D_F2_COEF_3                      0x1DF2 //
#define P1D_F3_COEF_4                      0x1DF3 //

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 24: e-fuse Data //////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P24_A0_EFUSE_LOCK                  0x24A0
#define P24_A1_EFUSE_ADDR                  0x24A1
#define P24_A2_EFUSE_CTRL                  0x24A2
#define P24_A2_EFUSE_RD_ADDR               0x24A4
#define P24_A2_EFUSE_RD_DATA               0x24A5
#define P24_A6_EFUSE_DATA0                 0x24A6
#define P24_A7_EFUSE_DATA1                 0x24A7
#define P24_A8_EFUSE_DATA2                 0x24A8
#define P24_A9_EFUSE_DATA3                 0x24A9
#define P24_AA_EFUSE_DATA4                 0x24AA
#define P24_AB_EFUSE_DATA5                 0x24AB
#define P24_AC_EFUSE_DATA6                 0x24AC
#define P24_AD_EFUSE_DATA7                 0x24AD
#define P24_A6_EFUSE_DATA8                 0x24AE
#define P24_A7_EFUSE_DATA9                 0x24AF
#define P24_A8_EFUSE_DATA10                0x24B0
#define P24_A9_EFUSE_DATA11                0x24B1
#define P24_AA_EFUSE_DATA12                0x24B2
#define P24_AB_EFUSE_DATA13                0x24B3
#define P24_AC_EFUSE_DATA14                0x24B4
#define P24_AD_EFUSE_DATA15                0x24B5


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 2B: Register4 ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------
// PC99 LDO (Page 2B)
//--------------------------------------------------
#define P2B_A0_PC99_CTRL1                  0x2BA0
#define P2B_A1_PC99_CTRL2                  0x2BA1
#define P2B_A2_PC99_CTRL3                  0x2BA2
#define P2B_A3_PC99_CTRL4                  0x2BA3
#define P2B_A4_PC99_CTRL5                  0x2BA4
#define P2B_A5_PC99_CTRL6                  0x2BA5
#define P2B_A6_PC99_CTRL7                  0x2BA6
#define P2B_A7_PC99_CTRL8                  0x2BA7
#define P2B_A8_PC99_CTRL9                  0x2BA8


//--------------------------------------------------
// Macros of controlling the scaler registers
//--------------------------------------------------
#define ScalerSetBit(pucAddr, ucAnd, ucOr)          (*((volatile BYTE xdata *)(pucAddr)) = (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit(pucAddr, ucAnd)                (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd))
#define ScalerGetByte(pucAddr)                      (*((volatile BYTE xdata *)(pucAddr)))
#define ScalerSetByte(pucAddr, ucValue)             (*((volatile BYTE xdata *)(pucAddr)) = (ucValue))
#define ScalerGetWord(pusAddr)                      (*((volatile WORD xdata *)(pusAddr)))
#define ScalerSetWord(pusAddr, usValue)             (*((volatile WORD xdata *)(pusAddr)) = (usValue))

//--------------------------------------------------
// Macros of controlling the scaler registers for EXINT0
//--------------------------------------------------
#define ScalerSetBit_EXINT0(pucAddr, ucAnd, ucOr)   (*((volatile BYTE xdata *)(pucAddr)) = (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit_EXINT0(pucAddr, ucAnd)         (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd))
#define ScalerGetByte_EXINT0(pucAddr)               (*((volatile BYTE xdata *)(pucAddr)))
#define ScalerSetByte_EXINT0(pucAddr, ucValue)      (*((volatile BYTE xdata *)(pucAddr)) = (ucValue))
#define ScalerGetWord_EXINT0(pusAddr)               (*((volatile WORD xdata *)(pusAddr)))
#define ScalerSetWord_EXINT0(pusAddr, usValue)      (*((volatile WORD xdata *)(pusAddr)) = (usValue))

//--------------------------------------------------
// Macros of controlling the scaler registers for EXINT1
//--------------------------------------------------
#define ScalerSetBit_EXINT1(pucAddr, ucAnd, ucOr)   (*((volatile BYTE xdata *)(pucAddr)) = (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit_EXINT1(pucAddr, ucAnd)         (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd))
#define ScalerGetByte_EXINT1(pucAddr)               (*((volatile BYTE xdata *)(pucAddr)))
#define ScalerSetByte_EXINT1(pucAddr, ucValue)      (*((volatile BYTE xdata *)(pucAddr)) = (ucValue))
#define ScalerGetWord_EXINT1(pusAddr)               (*((volatile WORD xdata *)(pusAddr)))
#define ScalerSetWord_EXINT1(pusAddr, usValue)      (*((volatile WORD xdata *)(pusAddr)) = (usValue))

//--------------------------------------------------
// Macros of controlling the scaler registers for Timer
//--------------------------------------------------
#define ScalerSetBit_TIMER(pucAddr, ucAnd, ucOr)    (*((volatile BYTE xdata *)(pucAddr)) = (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd)) | (ucOr))
#define ScalerGetBit_TIMER(pucAddr, ucAnd)          (*((volatile BYTE xdata *)(pucAddr)) & (ucAnd))
#define ScalerGetByte_TIMER(pucAddr)                (*((volatile BYTE xdata *)(pucAddr)))
#define ScalerSetByte_TIMER(pucAddr, ucValue)       (*((volatile BYTE xdata *)(pucAddr)) = (ucValue))
#define ScalerGetWord_TIMER(pusAddr)                (*((volatile WORD xdata *)(pusAddr)))
#define ScalerSetWord_TIMER(pusAddr, usValue)       (*((volatile WORD xdata *)(pusAddr)) = (usValue))

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


#ifndef __RL6336_SERIES_REG__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern BYTE ScalerEnableAccessPort(WORD usAddr, BYTE ucValue);
extern void ScalerDisableAccessPort(WORD usAddr);
extern void ScalerWrite(WORD usAddr, WORD usLength, BYTE *pArray, bit bAutoInc);
extern void ScalerRead(WORD usAddr, WORD usLength, BYTE *pArray, bit bAutoInc);
extern void ScalerSetDataPortByte(WORD usAddr, BYTE ucValue1, BYTE ucValue2);
extern void ScalerGetDataPortByte(WORD usAddr, BYTE ucValue, WORD usLength, BYTE *pArray, bit bAutoInc);
extern void ScalerSetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd, BYTE ucOr);
extern BYTE ScalerGetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd);
extern void ScalerBurstWrite(BYTE *pAddress, WORD usWriteLength, BYTE ucBankNum, WORD usHostAddr, BYTE ucTableType, bit bTableLocation);

#endif // End of #ifndef __RL6336_SERIES_REG__
