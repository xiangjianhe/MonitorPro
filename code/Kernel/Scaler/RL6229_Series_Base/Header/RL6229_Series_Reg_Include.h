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
// ID Code      : RL6229_Series_Reg_Include.h No.0000
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

#define _CM_25_PT_20_ACTIVE_SPACE_LINE0_M         0x20  
#define _CM_25_PT_21_ACTIVE_SPACE_LINE0_L         0x21
#define _CM_25_PT_22_ACTIVE_SPACE_LEN0_L          0x22
#define _CM_25_PT_23_ACTIVE_SPACE_LINE1_M         0x23  
#define _CM_25_PT_24_ACTIVE_SPACE_LINE1_L         0x24
#define _CM_25_PT_25_ACTIVE_SPACE_LEN1_L          0x25
#define _CM_25_PT_26_ACTIVE_SPACE_LINE2_M         0x26  
#define _CM_25_PT_27_ACTIVE_SPACE_LINE2_L         0x27
#define _CM_25_PT_28_ACTIVE_SPACE_LEN2_L          0x28
#define _CM_25_PT_29_ACTIVE_SPACE_LINE3_M         0x29  
#define _CM_25_PT_2A_ACTIVE_SPACE_LINE3_L         0x2A
#define _CM_25_PT_2B_ACTIVE_SPACE_LEN3_L          0x2B
#define _CM_25_PT_2C_ACTIVE_SPACE_CTRL            0x2C
#define _CM_25_PT_2D_H_SCALE_INIT_EVEN            0x2D
#define _CM_25_PT_2E_H_QUINCUNX_CTRL              0x2E
#define _CM_25_PT_2F_H_SBS_RST_POS_M              0x2F
#define _CM_25_PT_30_H_SBS_RST_POS_L              0x30
#define _CM_25_PT_31_V_INITIAL_RIGHT              0x31
#define _CM_25_PT_32_SD_IN_WID_M                  0x32
#define _CM_25_PT_33_SD_IN_WID_L                  0x33
#define _CM_25_PT_34_SD_IN_LEN_M                  0x34
#define _CM_25_PT_35_SD_IN_LEN_L                  0x35
#define _CM_25_PT_36_SD_OUT_WID_M                 0x36
#define _CM_25_PT_37_SD_OUT_WID_L                 0x37
#define _CM_25_PT_38_SD_OUT_LEN_M                 0x38
#define _CM_25_PT_39_SD_OUT_LEN_L                 0x39


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
#define _CM_2B_PT_25_MN_FRAME_RATE_EN             0x25 // 
#define _CM_2B_PT_26_M_FOR_MN_FRAME_RATE          0x26 // 
#define _CM_2B_PT_27_N_FOR_MN_FRAME_RATE          0x27 // 
#define _CM_2B_PT_28_FREE_RUN_DVS_CNT             0x28 // Counter of free run DVS,for MN frame sync[7:0] 

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
#define _CM_34_PT_12_SU_H_COEF_INI_VALUE_ODD      0x12 // Horizontal Filter Coefficient Initial Value for odd line

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
#define _CM_8C_PT_06_LVDS_CTRL21                  0x06 // LVDS Control 21
#define _CM_8C_PT_07_LVDS_CTRL22                  0x07 // LVDS Control 22
//--------------------------------------------------
// TCON Horizontal/Vertical Timing Setting
//--------------------------------------------------
#define _CM_8C_PT_08_TCON_TCON0_VS_LSB            0x08 // TCON[0] Vertical Start LSB Register
#define _CM_8C_PT_09_TCON_TCON0_VS_MSB            0x09 // TCON[0] Vertical Start/End MSB Register
#define _CM_8C_PT_0A_TCON_TCON0_VE_LSB            0x0A // TCON[0] Vertical End LSB Register
#define _CM_8C_PT_0B_TCON_TCON0_HS_LSB            0x0B // TCON[0] Horizontal Start LSB Register
#define _CM_8C_PT_0C_TCON_TCON0_HS_MSB            0x0C // TCON[0] Horizontal Start/End MSB Register
#define _CM_8C_PT_0D_TCON_TCON0_HE_LSB            0x0D // TCON[0] Horizontal End LSB Register
#define _CM_8C_PT_0E_TCON_TCON0_CTRL              0x0E // TCON[0] Control Register
#define _CM_8C_PT_0F_LVDS_CTRL30                  0x0F // LVDS Control 30
#define _CM_8C_PT_10_LVDS_CTRL31                  0x10 // LVDS Control 31
#define _CM_8C_PT_11_LVDS_CTRL32                  0x11 // LVDS Control 32
#define _CM_8C_PT_12_LVDS_CTRL33                  0x12 // LVDS Control 33
#define _CM_8C_PT_13_LVDS_CTRL34                  0x13 // LVDS Control 34
#define _CM_8C_PT_14_LVDS_CTRL35                  0x14 // LVDS Control 35
#define _CM_8C_PT_15_LVDS_CTRL36                  0x15 // LVDS Control 36
#define _CM_8C_PT_16_LVDS_CTRL37                  0x16 // LVDS Control 37
#define _CM_8C_PT_17_LVDS_CTRL38                  0x17 // LVDS Control 38
#define _CM_8C_PT_18_LVDS_CTRL39                  0x18 // LVDS Control 39
#define _CM_8C_PT_19_LVDS_CTRL40                  0x19 // LVDS Control 40
#define _CM_8C_PT_1A_LVDS_CTRL41                  0x1A // LVDS Control 41
#define _CM_8C_PT_1B_LVDS_CTRL42                  0x1B // LVDS Control 42       
#define _CM_8C_PT_1C_LVDS_CTRL43                  0x1C // LVDS Control 43       
#define _CM_8C_PT_1D_MLVDS_CTRL2                  0x1D // mLVDS Clk
#define _CM_8C_PT_1E_LVDS_CTR                     0x1E // LVDS Clk 
#define _CM_8C_PT_20_DIS_FORMAT1                  0x20 
#define _CM_8C_PT_24_LVDS_CTRL49                  0x24 // LVDS Control 49      
#define _CM_8C_PT_25_LVDS_CTRL50                  0x25 // LVDS Control 50      
#define _CM_8C_PT_26_MLVDS_CTRL0                  0x26 
#define _CM_8C_PT_2B_MLVDS_CTRL3                  0x2B // Data Bit Inversion / Panel Inverse / L type Back Inverse

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
#define _P2_CA_PT_A4_HDMI_PTRSV2                  0xA4
#define _P2_CA_PT_A5_HDMI_PTRSV3                  0xA5
#define _P2_CA_PT_A6_HDMI_PTRSV4                  0xA6
#define _P2_CA_PT_A7_HDMI_GPVS0                   0xA7
#define _P2_CA_PT_A8_HDMI_PVSR3                   0xA8
#define _P2_CA_PT_A9_HDMI_PVSR4                   0xA9
#define _P2_CA_PT_AA_HDMI_PVGCR3                  0xAA
#define _P2_CA_PT_AB_HDMI_PVGCR4                  0xAB

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
#define _P7_D3_PT_53_UV_OFFSET                    0x53 // Addr 33: U Offset 28, -128~127 

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
// CABC Data Port
//--------------------------------------------------
#define _P7_DD_PT_00_NOR_FACTOR_H                 0x00 // Normailized Factor[21:16]
#define _P7_DD_PT_01_NOR_FACTOR_M                 0x01 // Normailized Factor[15:8]
#define _P7_DD_PT_02_NOR_FACTOR_L                 0x02 // Normailized Factor[7:0]

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
#define _PC_B4_PT_09_MN_STRM_ATTR_HWD_L            0x09
#define _PC_B4_PT_0A_MN_STRM_ATTR_HSW_M            0x0A
#define _PC_B4_PT_0B_MN_STRM_ATTR_HSW_L            0x0B
#define _PC_B4_PT_0C_MN_STRM_ATTR_VTTE_M           0x0C
#define _PC_B4_PT_0D_MN_STRM_ATTR_VTTE_L           0x0D
#define _PC_B4_PT_0E_MN_STRM_ATTR_VTTO_M           0x0E
#define _PC_B4_PT_0F_MN_STRM_ATTR_VTTO_L           0x0F
#define _PC_B4_PT_10_MN_STRM_ATTR_VST_M            0x10
#define _PC_B4_PT_11_MN_STRM_ATTR_VST_L            0x11
#define _PC_B4_PT_12_MN_STRM_ATTR_VHT_M            0x12
#define _PC_B4_PT_13_MN_STRM_ATTR_VHT_L            0x13
#define _PC_B4_PT_14_MN_STRM_ATTR_VSW_M            0x14
#define _PC_B4_PT_15_MN_STRM_ATTR_VSW_L            0x15
#define _PC_B4_PT_16_MN_M_VID_H                    0x16
#define _PC_B4_PT_17_MN_M_VID_M                    0x17
#define _PC_B4_PT_18_MN_M_VID_L                    0x18
#define _PC_B4_PT_19_MN_N_VID_H                    0x19
#define _PC_B4_PT_1A_MN_N_VID_M                    0x1A
#define _PC_B4_PT_1B_MN_N_VID_L                    0x1B
#define _PC_B4_PT_1C_MN_AVERAGE                    0x1C
#define _PC_B4_PT_1D_MN_M_AUD_H                    0x1D
#define _PC_B4_PT_1E_MN_M_AUD_M                    0x1E
#define _PC_B4_PT_1F_MN_M_AUD_L                    0x1F
#define _PC_B4_PT_20_MN_N_AUD_H                    0x20
#define _PC_B4_PT_21_MN_N_AUD_M                    0x21
#define _PC_B4_PT_22_MN_N_AUD_L                    0x22
#define _PC_B4_PT_23_DP_AUD_CH_STATUS0             0x23
#define _PC_B4_PT_24_DP_AUD_CH_STATUS1             0x24
#define _PC_B4_PT_25_DP_AUD_CH_STATUS2             0x25
#define _PC_B4_PT_26_DP_AUD_CH_STATUS3             0x26
#define _PC_B4_PT_27_DP_AUD_CH_STATUS4             0x27
#define _PC_B4_PT_30_MN_VFIFO_STATUS               0x30
#define _PC_B4_PT_31_MN_PIX_REG_CTRL               0x31
#define _PC_B4_PT_32_MAX_VFIFO_WL_CLR              0x32
#define _PC_B4_PT_33_MAX_VFIFO_WL                  0x33
#define _PC_B4_PT_34_VFIFO_WL                      0x34
#define _PC_B4_PT_35_MN_DPF_CTRL                   0x35
#define _PC_B4_PT_36_MN_EVBLK2VS_H                 0x36
#define _PC_B4_PT_37_MN_EVBLK2VS_M                 0x37
#define _PC_B4_PT_38_MN_EVBLK2VS_L                 0x38
#define _PC_B4_PT_39_MN_OVBLK2VS_H                 0x39
#define _PC_B4_PT_3A_MN_OVBLK2VS_M                 0x3A
#define _PC_B4_PT_3B_MN_OVBLK2VS_L                 0x3B
#define _PC_B4_PT_3C_MN_HBLK2DE_M                  0x3C
#define _PC_B4_PT_3D_MN_HBLK2DE_L                  0x3D
#define _PC_B4_PT_3E_MN_DPF_HTT_M                  0x3E
#define _PC_B4_PT_3F_MN_DPF_HTT_L                  0x3F
#define _PC_B4_PT_40_MN_DPF_HST_M                  0x40
#define _PC_B4_PT_41_MN_DPF_HST_L                  0x41
#define _PC_B4_PT_42_MN_DPF_HWD_M                  0x42
#define _PC_B4_PT_43_MN_DPF_HWD_L                  0x43
#define _PC_B4_PT_44_MN_DPF_HSW_M                  0x44
#define _PC_B4_PT_45_MN_DPF_HSW_L                  0x45
#define _PC_B4_PT_46_MN_DPF_VTT_M                  0x46
#define _PC_B4_PT_47_MN_DPF_VTT_L                  0x47
#define _PC_B4_PT_48_MN_DPF_VST_M                  0x48
#define _PC_B4_PT_49_MN_DPF_VST_L                  0x49
#define _PC_B4_PT_4A_MN_DPF_VHT_M                  0x4A
#define _PC_B4_PT_4B_MN_DPF_VHT_L                  0x4B
#define _PC_B4_PT_4C_MN_DPF_VSW_M                  0x4C
#define _PC_B4_PT_4D_MN_DPF_VSW_L                  0x4D
#define _PC_B4_PT_4E_MN_DPF_FREERUN                0x4E
#define _PC_B4_PT_50_MN_SCLKG_CTRL                    0x50
#define _PC_B4_PT_51_MN_SCLKG_DIVM                    0x51
#define _PC_B4_PT_52_MN_SCLKG_DIVS                    0x52
#define _PC_B4_PT_53_MN_SCLKG_OFFS_H                0x53
#define _PC_B4_PT_54_MN_SCLKG_OFFS_M                0x54
#define _PC_B4_PT_55_MN_SCLKG_OFFS_L                0x55
#define _PC_B4_PT_56_MN_SCLKG_TRK_CTRL                0x56
#define _PC_B4_PT_57_MN_SCLKG_TRK_MN_I_H            0x57
#define _PC_B4_PT_58_MN_SCLKG_TRK_MN_I_M            0x58
#define _PC_B4_PT_59_MN_SCLKG_TRK_MN_I_L            0x59
#define _PC_B4_PT_5A_MN_SCLKG_TRK_MN_P_H           0x5A
#define _PC_B4_PT_5B_MN_SCLKG_TRK_MN_P_M           0x5B
#define _PC_B4_PT_5C_MN_SCLKG_TRK_MN_P_L           0x5C
#define _PC_B4_PT_5D_MN_SCLKG_TRK_MN_PE            0x5D
#define _PC_B4_PT_5E_MN_SCLKG_TRK_MN_NLOCK         0x5E

#define _PC_B4_PT_67_MN_SCLKG_SDM_CTRL                0x67


#define _PC_B4_PT_70_MN_SCLKG_PLL_PWR                0x70 //
#define _PC_B4_PT_71_MN_SCLKG_PLL_CHP                0x71
#define _PC_B4_PT_72_MN_SCLKG_PLL_WD                0x72
#define _PC_B4_PT_73_MN_SCLKG_PLL_INSEL            0x73

#define _PC_B4_PT_75_MN_DPF_BG_RED_M               0x75
#define _PC_B4_PT_76_MN_DPF_BG_RED_L               0x76
#define _PC_B4_PT_77_MN_DPF_BG_GRN_M               0x77
#define _PC_B4_PT_78_MN_DPF_BG_GRN_L               0x78
#define _PC_B4_PT_79_MN_DPF_BG_BLU_M               0x79
#define _PC_B4_PT_7A_MN_DPF_BG_BLU_L               0x7A

#define _PC_B4_PT_80_MN_RS_DEC_CTRL                0x80
#define _PC_B4_PT_81_RS_DEC_ERR_HANDLE             0x81

#define _PC_B4_PT_90_DP_AUD_CTRL                   0x90                
#define _PC_B4_PT_91_AUD_ID                        0x91
#define _PC_B4_PT_92_AUD_BUF_STATUS                0x92
#define _PC_B4_PT_93_DP_AUD_BUF_WL                 0x93
#define _PC_B4_PT_94_DP_BCH_CNT                    0x94

#define _PC_B4_PT_A0_MN_MEAS_CTRL                  0xA0
#define _PC_B4_PT_A1_MN_MEAS_VLN_M                 0xA1
#define _PC_B4_PT_A2_MN_MEAS_VLN_L                 0xA2
#define _PC_B4_PT_A3_MN_MEAS_HLN_M                 0xA3

#define _PC_B4_PT_B3_DP_EQ_CRC_CTRL                0xB3

#define _PC_B4_PT_CA_DP_VWD_CTRL                   0xCA
#define _PC_B4_PT_CC_DP_IRQ_CTRL0                  0xCC
#define _PC_B4_PT_D0_REV_PORT_0                    0xD0 
#define _PC_B4_PT_D1_REV_PORT_1                    0xD1 
#define _PC_B4_PT_D2_REV_PORT_2                    0xD2 
#define _PC_B4_PT_D3_REV_PORT_3                    0xD3 
#define _PC_B4_PT_D4_REV_PORT_4                    0xD4 
#define _PC_B4_PT_D5_REV_PORT_5                    0xD5 


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
#define CM_26_I_YUV444TO422                 0x0026 // I Domain YUV444To422 Control

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
#define CM_37_SU_LINE_INTERLEAVE            0x0037 // SU For Line Interleave
#define CM_3D_IV_DV_DELAY_CLK_FINE          0x003D // Frame Sync Fine Tune Per Pixel
#define CM_3E_IVS2DVS_DEALY_LINES_H         0x003E // IVS2DVS Delay High Byte
//--------------------------------------------------
// Frame Sync Fine Tune
//--------------------------------------------------
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
// Dithering Control (For Input Domain)
//--------------------------------------------------
#define CM_88_I_DITHERING_DATA_ACCESS       0x0088 // Dithering Table DATA ACCESS (I Domain)
#define CM_89_I_DITHERING_CTRL1             0x0089 // Dithering Control Register
#define CM_8A_I_DITHERING_CTRL2             0x008A // Dithering Control Register

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
// Dithering Control(For Memory Domain)
//--------------------------------------------------
#define CM_95_M_DITHERING_DATA_ACCESS       0x0095 // M Dithering Data Access
#define CM_96_M_DITHERING_CTRL1             0x0096 // M Dithering Control Register
#define CM_97_M_DITHERING_CTRL2             0x0097 // M Dithering Table Reference

//--------------------------------------------------
// Digital Filter
//--------------------------------------------------
#define CM_98_DIGITAL_FILTER_CTRL           0x0098 // Digital Filter Control Register
#define CM_99_DIGITAL_FILTER_PORT           0x0099 // Digital Filter Port

//--------------------------------------------------
// Video Color Space Conversion  YUV2RGB
//--------------------------------------------------
#define CM_9C_YUV2RGB_CTRL                  0x009C // YUV to RGB Control Register
#define CM_9D_YUV_RGB_ACCESS                0x009D // YUV to RGB Access
#define CM_9E_YUV_RGB_COEF_DATA             0x009E // YUV to RGB Coefficient Data Port

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
#define P0_DE_TEST_PATTERN_CTRL             0x00DE // Test Pattern Control
#define P0_DF_EBD_REGLATOR_A_CTRL           0x00DF // Test Pattern Control
#define P0_E0_EBD_REGLATOR_DB_CTRL          0x00E0 // Test Pattern Control
#define P0_E1_EBD_REGLATOR_DB_CTRL          0x00E1 // LDO support current for Xtal 

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
#define P0_F4_HS_SCHMITT_TRIGGER_CTRL       0x00F4 // Schmitt Trigger Control Register

//--------------------------------------------------
// Memory PLL (Page0)
//--------------------------------------------------
#define P0_F5_MPLL_M                        0x00F5 // MPLL M Code
#define P0_F6_MPLL_N                        0x00F6 // MPLL N Code
#define P0_F7_MPLL_CRNT                     0x00F7 // MPLL Current Control
#define P0_F8_MPLL_WD                       0x00F8 // MPLL WatchDog Control
#define P0_F9_MPLL_CAL                      0x00F9 // MPLL Calibration

//--------------------------------------------------
// MCLK Spread Spectrum (Page0)
//--------------------------------------------------
#define P0_FA_MCLK_FINE_TUNE_OFFSET_MSB     0x00FA // MCLK Offset MSB
#define P0_FB_MCLK_FINE_TUNE_OFFSET_LSB     0x00FB // MCLK Offset LSB
#define P0_FC_MCLK_SPREAD_SPECTRUM          0x00FC // MCLK Spreading Range
#define P0_FD_MPLL_RESULT                   0x00FD // MPLL Calibration Result


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
// DISPLAY PLLL (Page1)
//--------------------------------------------------
#define P1_BF_DPLL_M                        0x01BF // DPLL M Divider

#define P1_C0_DPLL_N                        0x01C0 // DPLL N Divider
#define P1_C1_DPLL_CRNT                     0x01C1 // DPLL Current/Resistor Register

//--------------------------------------------------
// DCLK Spread Spectrum (Page1)
//--------------------------------------------------
#define P1_C2_DPLL_WD                       0x01C2 // DPLL Watch Dog Register
#define P1_C3_DPLL_CAL                      0x01C3 // DPLL Calibration
#define P1_C4_DCLK_FINE_TUNE_OFFSET_MSB     0x01C4 // Display Clock Fine Tune Offset MSB
#define P1_C5_DCLK_FINE_TUNE_OFFSET_LSB     0x01C5 // Display Clock Fine Tune Offset LSB
#define P1_C6_DCLK_SPREAD_SPECTRUM          0x01C6 // Display Clock Spread Spectrum
#define P1_C7_EVEN_FIX_LASTLINE_DVTOTAL_M   0x01C7 // Even Fixed Last Line MSB
#define P1_C8_EVEN_FIX_LASTLINE_DVTOTAL_L   0x01C8 // Even Fixed Last Line DVTotal LSB
#define P1_C9_EVEN_FIX_LASTLINE_LENGTH_L    0x01C9 // Even Fixed Last Line Length LSB
#define P1_CA_EVEN_FIXED_LAST_LINE_CTRL     0x01CA // Fixed Last Line Control Register
#define P1_CB_ODD_FIX_LASTLINE_DVTOTAL_M    0x01CB // Odd Fixed Last Line MSB
#define P1_CC_ODD_FIX_LASTLINE_DVTOTAL_L    0x01CC // Odd Fixed Last Line DVTotal LSB
#define P1_CD_ODD_FIX_LASTLINE_LENGTH_L     0x01CD // Odd Fixed Last Line Length LSB
#define P1_CE_DCLK_SPREAD_SPECTRUM          0x01CE // Dclk Spread Spectrum
#define P1_CF_PHASE_RESULT_MSB              0x01CF // Phase Result MSB

#define P1_D0_PHASE_LINE_LSB                0x01D0 // Phase Line LSB
#define P1_D1_PHASE_PIXEL_LSB               0x01D1 // Phase Pixel LSB
#define P1_D2_TARGET_DCLK_TUNE_OFFSET_MSB   0x01D2 // Target Dclk Tune Offset MSB
#define P1_D3_TARGET_DCLK_TUNE_OFFSET_LSB   0x01D3 // Target Dclk Tune Offset LSB
#define P1_D4_DPLL_RESULT                   0x01D4 // DPLL Calibration Result

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

//--------------------------------------------------
// Digital BangBang (Page2)
//--------------------------------------------------
#define P2_F0_DIG_BBANG00                  0x02F0 // Digital BangBang Control Register 0
#define P2_F1_DIG_BBANG01                  0x02F1 // Digital BangBang Control Register 1
#define P2_F2_DIG_BBANG02                  0x02F2 // Digital BangBang Control Register 2
#define P2_F3_DIG_BBANG03                  0x02F3 // Digital BangBang Control Register 3
#define P2_F4_DIG_BBANG04                  0x02F4 // Digital BangBang Control Register 4
#define P2_F5_DIG_BBANG05                  0x02F5 // Digital BangBang Control Register 5


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 3: LiveShow Control //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// LiveShow Control (Page3)
//--------------------------------------------------

#define P3_A1_LS_CTRL0                     0x03A1 // Live Show Control Register0
#define P3_A2_LS_CTRL1                     0x03A2 // Live Show Control Register1
#define P3_A3_LS_DELTA_GAIN                0x03A3 // Live Show Detal Gain Setting
#define P3_A4_LS_STATUS0                   0x03A4 // Live Show Status Register0 (Buffer Status)
#define P3_A5_LS_STATUS1                   0x03A5 // Live Show Status Register1 (FIFO Status)
#define P3_A6_LS_WTLVL_W                   0x03A6 // Live Show Water Level Write Register
#define P3_A7_LS_WTLVL_R                   0x03A7 // Live Show Water Level Read Register
#define P3_A8_LS_MEM_FIFO_RW_NUM_H         0x03A8 // The Read/Write Times Of Total Memory Access HByte
#define P3_A9_LS_MEM_FIFO_RW_NUM_L         0x03A9 // The Read/Write Times Of Total Memory Access LByte
#define P3_AA_LS_MEM_FIFO_RW_LEN           0x03AA // The Read/Write Number Of Words In Each Memory Access
#define P3_AB_LS_MEM_FIFO_RW_REMAIN        0x03AB // The Read/Write Number Of Words At The Last Access. This Register Must Be 4X
#define P3_AC_LS_MEM_START_ADDR_H          0x03AC // Start Address Of Live Show Memory Block HByte(Total 22/23 bits)
#define P3_AD_LS_MEM_START_ADDR_M          0x03AD // Start Address Of Live Show Memory Block MByte(Total 22/23 bits)
#define P3_AE_LS_MEM_START_ADDR_L          0x03AE // Start Address Of Live Show Memory Block LByte(Total 22/23 bits)
#define P3_AF_LS_BIST_CTRL                 0x03AF // Live Show BIST Control Register
#define P3_B0_LS_FRAME0                    0x03B0 // Live Show Current Frame Control Register0
#define P3_B1_LS_FRAME1                    0x03B1 // Live Show Current Frame Control Register1
#define P3_B2_LS_FRAME2                    0x03B2 // Live Show Current Frame Control Register2
#define P3_B3_LS_FRAME4                    0x03B3 // Live Show Current Frame Control Register4
#define P3_B4_LS_FRAME5                    0x03B4 // Live Show Current Frame Control Register5
#define P3_B5_LS_BYPOS0                    0x03B5 // Live Show By Position Overdrive Register0
#define P3_B6_LS_BYPOS1                    0x03B6 // Live Show By Position Overdrive Register1
#define P3_B7_LS_BYPOS_GAIN1               0x03B7 // Live Show By Position Gain
#define P3_B8_LS_BYPOS_SLOPE1              0x03B8 // Live Show By Position Slope

#define P3_BF_LS_LUT_CTRL                  0x03BF // Live Show LUT Control
#define P3_C0_LS_LUT_DATA                  0x03C0 // Live Show LUT Data Port
#define P3_C1_LS_LUT_READ                  0x03C1 // Live Show LUT Read
#define P3_C2_LS_LUT_ROW                   0x03C2 // Live Show LUT Row Address
#define P3_C3_LS_LUT_COL                   0x03C3 // Live Show LUT Column Address


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 4: SDRAM Control /////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

#define P4_A1_SDR_CTRL0                    0x04A1 // SDRAM Control Register0
#define P4_A2_SDR_CTRL1                    0x04A2 // SDRAM Control Register1
#define P4_A3_SDR_AREF_TIME                0x04A3 // SDRAM Auto Refresh Time
#define P4_A4_SDR_PRCG                     0x04A4 // SDRAM Precharge Control Register
#define P4_A5_SDR_MEM_TYPE                 0x04A5 // SDRAM Memory Size Select
#define P4_A6_SDR_SLEW_RATE                0x04A6 // SDRAM Slew Rate Control Register
#define P4_A7_SDR_AREF_CNT                 0x04A7 // Number Of Auto Refresh
#define P4_AA_SDR_RSC_AREF                 0x04AA // SDRAM Arbiter Token Ring For Auto Refresh
#define P4_AB_SDR_RSC_MCU                  0x04AB // SDRAM Arbiter Token Ring For MCU
#define P4_AC_SDR_RSC_CAP1                 0x04AC // SDRAM Arbiter Token Ring For CAP1
#define P4_AE_SDR_RSC_MAIN                 0x04AE // SDRAM Arbiter Token Ring For Main

#define P4_B0_SDR_RSC_RD                   0x04B0 // SDRAM Arbiter Token Ring For RD
#define P4_B1_SDR_RSC_WR                   0x04B1 // SDRAM Arbiter Token Ring For WR
#define P4_B4_SDR_ABTR_STATUS0             0x04B4 // SDRAM Arbiter Status Register0
#define P4_B5_SDR_ABTR_STATUS1             0x04B5 // SDRAM Arbiter Status Register1
#define P4_B7_SDR_POWER_CTRL0              0x04B7 // SDRAM Power Down Mode Control
#define P4_B8_SDR_ADDR_H                   0x04B8 // SDRAM Access Address HByte
#define P4_B9_SDR_ADDR_M                   0x04B9 // SDRAM Access Address MByte
#define P4_BA_SDR_ADDR_L                   0x04BA // SDRAM Access Address LByte
#define P4_BB_SDR_ACCESS_CMD               0x04BB // SDRAM Access Command
#define P4_BC_SDR_DATA_BUF                 0x04BC // SDRAM Data Buffer
#define P4_BD_SDR_MCU_RD_LEN               0x04BD // SDRAM MCU Read SdRAM Lengh
#define P4_BE_SDR_PHASE_CAL                0x04BE // SDRAM Phase Calibration
#define P4_BF_SDR_CAL_RESULT               0x04BF // SDRAM Calibration Result

#define P4_C0_SDR_CLK_DLY1                 0x04C0 // SDRAM Mclk Output
#define P4_C1_SDR_CLK_DLY2                 0x04C1 // SDRAM Mclk Delay Fine Tune
#define P4_C2_DQS0_DLY1                    0x04C2 // SDRAM DQS0 Coarse Delay
#define P4_C3_DQS0_DLY2                    0x04C3 // SDRAM DQS0 Data Fine Delay
#define P4_C4_DQS1_DLY1                    0x04C4 // SDRAM DQS1 Coarse Delay
#define P4_C5_DQS1_DLY2                    0x04C5 // SDRAM DQS1 Data Fine Delay
#define P4_C6_DQS2_DLY1                    0x04C6 // SDRAM DQS2 Coarse Delay
#define P4_C7_DQS2_DLY2                    0x04C7 // SDRAM DQS2 Data Fine Delay
#define P4_C8_DQS3_DLY1                    0x04C8 // SDRAM DQS3 Coarse Delay
#define P4_C9_DQS3_DLY2                    0x04C9 // SDRAM DQS3 Data Fine Delay
#define P4_CA_SEC_DQS0_DLY                 0x04CA // SDRAM DQS0 Second Data Fine Delay
#define P4_CB_SEC_DQS1_DLY                 0x04CB // SDRAM DQS1 Second Data Fine Delay
#define P4_CC_SEC_DQS2_DLY                 0x04CC // SDRAM DQS2 Second Data Fine Delay
#define P4_CD_SEC_DQS3_DLY                 0x04CD // SDRAM DQS3 Second Data Fine Delay

#define P4_FC_EXTENDED_MODE_H              0x04FC // SDRAM Extended Mode Register HByte
#define P4_FD_EXTENDED_MODE_L              0x04FD // SDRAM Extended Mode Register LByte
#define P4_FE_RANDOM_GENERATOR             0x04FE // SDRAM Random Generator
#define P4_FF_CRC_DATA_PORT                0x04FF // SDRAM CRC Data Port


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 5: SDR_FIFO Control //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

#define P5_A1_SDRF_IN1_FIFO_STATUS         0x05A1 // SDRAM IN1 FIFO Status Register
#define P5_A2_SDRF_MAIN_FIFO_STATUS        0x05A2 // SDRAM MAIN FIFO Status Register
#define P5_A3_SDRF_IN1_SFIFO_STATUS        0x05A3 // SDRAM IN1 SFIFO Status Register
#define P5_A4_SDRF_IN1_ONEF_STATUS         0x05A4 // The counter to record the continuous frames not written in capture FIFO
#define P5_A5_SDRF_IN1_3D_FRC_CTL          0x05A5 // 3D Contorl Register
#define P5_A6_SDRF_IN1_PXL_NUM_H           0x05A6 // Pixel Number Of One Line, For FIFO To Fill Dummy. (total 12-bits)
#define P5_A7_SDRF_IN1_PXL_NUM_L		   0x05A7 // Pixel Number Of One Line, For FIFO To Fill Dummy. (total 12-bits)
#define P5_A8_SDRF_IN1_WATER_LEVEL         0x05A8 // SDRAM FIFO IN1 Water Level Register
#define P5_A9_SDRF_IN1_WR_NUM_H            0x05A9 // Number Of Length To Fill In The SDR Memory HByte
#define P5_AA_SDRF_IN1_WR_NUM_L            0x05AA // Number Of Length To Fill In The SDR Memory LByte
#define P5_AB_SDRF_IN1_WR_LEN              0x05AB // Length Of Data To Fill In The SDR Memory Once (unit : 64 bit)
#define P5_AC_SDRF_IN1_WR_REMAIN           0x05AC // The Remained Part That Can't Make A Complete Length (unit : 64 bit)
#define P5_AD_SDRF_IN1_MEM_ADDR_H          0x05AD // The Initial Write Address Of SDR Memory HByte
#define P5_AE_SDRF_IN1_MEM_ADDR_M          0x05AE // The Initial Write Address Of SDR Memory MByte
#define P5_AF_SDRF_IN1_MEM_ADDR_L          0x05AF // The Initial Write Address Of SDR Memory LByte

#define P5_B0_SDRF_IN1_LINE_STEP_H         0x05B0 // The Distance Between Two Lines Of SDR Memory HByte
#define P5_B1_SDRF_IN1_LINE_STEP_L         0x05B1 // The Distance Between Two Lines Of SDR Memory LByte
#define P5_B2_SDRF_IN1_BLOCK_STEP_H        0x05B2 // The Distance Between Two Blocks Of SDR Memory HByte
#define P5_B3_SDRF_IN1_BLOCK_STEP_L        0x05B3 // The Distance Between Two Blocks Of SDR Memory LByte
#define P5_B4_SDRF_IN1_BL2_ADDR_H          0x05B4 // Second Block Of SDR To Progress The Double Buffer. The Given Address Is The Absolute One HByte
#define P5_B5_SDRF_IN1_BL2_ADDR_M          0x05B5 // Second Block Of SDR To Progress The Double Buffer. The Given Address Is The Absolute One MByte
#define P5_B6_SDRF_IN1_BL2_ADDR_L          0x05B6 // Second Block Of SDR To Progress The Double Buffer. The Given Address Is The Absolute One LByte
#define P5_B7_SDRF_IN1_LINE_NUM_H          0x05B7 // The Total Line Number Of One Image HByte (Total 12 bits)
#define P5_B8_SDRF_IN1_LINE_NUM_L          0x05B8 // The Total Line Number Of One Image LByte (Total 12 bits)
#define P5_B9_SDRF_IN1_SDR_CTRL            0x05B9 // SDRAM IN1 FIFO Control Register
#define P5_BA_SDRF_IN1_MADDR_TOG_CTL       0x05BA // Hardware auto toggle M:N double buffer 
#define P5_BB_SDRF_IN1_SDR_STATUS          0x05BB // SDRAM IN1 Status Register
#define P5_BC_SDRF_MN_PRERD_VST_H          0x05BC // Vertical Start Line Of MAIN To Pre-Read Input Data HByte (Total 11-bits)
#define P5_BD_SDRF_MN_PRERD_VST_L          0x05BD // Vertical Start Line Of MAIN To Pre-Read Input Data LByte (Total 11-bits)
#define P5_BE_SDRF_MN_PXL_NUM_H            0x05BE // Pixel Number Of One Line, For FIFO To Clear Garbage From Capture Side HByte (Total 11-bits)
#define P5_BF_SDRF_MN_PXL_NUM_L            0x05BF // Pixel Number Of One Line, For FIFO To Clear Garbage From Capture Side LByte (Total 11-bits)

#define P5_C0_SDRF_MN_WTLVL                0x05C0 // When FIFO Depth Is Under Water Level, FIFO Requests Data
#define P5_C1_SDRF_MN_MADDR_TOG_CTL        0x05C1 // Hardware auto toggle block setting in Display
#define P5_C2_SDRF_MN_READ_NUM_H           0x05C2 // Number Of Length To Read From SDR In One Line HByte
#define P5_C3_SDRF_MN_READ_NUM_L           0x05C3 // Number Of Length To Read From SDR In One Line LByte
#define P5_C4_SDRF_MN_READ_LEN             0x05C4 // The Length Of Data To Read From SDR Once
#define P5_C5_SDRF_MN_READ_REMAIN          0x05C5 // The Remain Part That Can't Be A Complete Length In One Line
#define P5_C6_SDRF_MN_READ_ADDR_H          0x05C6 // The Initial Read Address Of SDR HByte (Total 23-bits)
#define P5_C7_SDRF_MN_READ_ADDR_M          0x05C7 // The Initial Read Address Of SDR MByte (Total 23-bits)
#define P5_C8_SDRF_MN_READ_ADDR_L          0x05C8 // The Initial Read Address Of SDR LByte (Total 23-bits)
#define P5_C9_SDRF_MN_LINE_STEP_H          0x05C9 // Line Step Indicates The Distance Between Two Lines HByte (Total 12 bits)
#define P5_CA_SDRF_MN_LINE_STEP_L          0x05CA // Line Step Indicates The Distance Between Two Lines LByte (Total 12 bits)
#define P5_CB_SDRF_MN_BLOCK_STEP_H         0x05CB // The Distance Between Two Blocks Of SDR HByte (Total 12-bits)
#define P5_CC_SDRF_MN_BLOCK_STEP_L         0x05CC // The Distance Between Two Blocks Of SDR LByte (Total 12-bits)
#define P5_CD_SDRF_MN_LINE_NUM_H           0x05CD // The Total Line Number Of One Image HByte (Total 12 bits)
#define P5_CE_SDRF_MN_LINE_NUM_L           0x05CE // The Total Line Number Of One Image LByte (Total 12 bits)
#define P5_CF_SDRF_MN_DISP_CTRL            0x05CF // SDRAM FIFO MAIN Display Control Register

#define P5_D0_SDRF_MN_SDR_STATUS           0x05D0 // SDRAM Status Register
#define P5_D6_SDRF_ADC_TEST                0x05D6 // For ADC Test Usage

#define P5_E3_SDRF_MN_FIFO_422_SET         0x05E3 // Output 444 Format(Only Work in FIFO 422 In Mode)
#define P5_E4_SDRF_MN_ONEF_DHF_H           0x05E4 // One Frame FRC Control Register & DHF_PRO_LEN[19:16]
#define P5_E5_SDRF_MN_ONEF_DHF_M           0x05E5 // DHF_PRO_LEN[15:8]
#define P5_E6_SDRF_MN_ONEF_DHF_L           0x05E6 // DHF_PRO_LEN[7:0]
#define P5_E7_SDRF_MN_ONEF_IHF             0x05E7 // One Frame FRC IHF_M
#define P5_E8_SDRF_MN_LINE_MAGN_L          0x05E8 // One Frame FRC Line Margin[7:0]
#define P5_E9_SDRF_MN_ONEF_MAGN_H          0x05E9 // Line Margin[11:8] & Pre-Read Margin[11:8]
#define P5_EA_SDRF_MN_PRRD_MAGN_L          0x05EA // Pre-Read Margin[7:0]
#define P5_EB_SDRF_MN_BLOCK_STEP_BANK      0x05EB // MAIN_ BLOCK_STEP [10:8]
#define P5_EC_SDRF_MN_BLOCK_STEP_COL       0x05EC // MAIN_ BLOCK_STEP [7:0]
#define P5_ED_SDRF_MN_3D_FRC_CTL           0x05ED // 3D LR / Field Signal Swap
#define P5_EE_SDRF_IN1_3D_ANAGLYPH_CTL     0x05EE // Anaglyph Glass Mode Setting
#define P5_EF_SDRF_IN1_3D_WR_NUM_H	       0x05EF // IN1_3D_WRITE_NUM[15:8]

#define P5_F0_SDRF_IN1_3D_WR_NUM_L	       0x05F0 // IN1_3D_WRITE_NUM[7:0]
#define P5_F1_SDRF_IN1_3D_WR_LEN           0x05F1 // IN1_3D_WRLEN[7:0]
#define P5_F2_SDRF_IN1_3D_WR_REMAIN        0x05F2 // 3D_WRITE_REMAIN [7:0]
#define P5_F3_SDRF_IN1_3D_LINE_STEP_H      0x05F3 // IN1_3D_LINE_STEP[13:8]
#define P5_F4_SDRF_IN1_3D_LINE_STEP_L      0x05F4 // IN1_3D_LINE_STEP [7:0]
#define P5_F5_SDRF_MN_3D_WTLVL             0x05F5 // MAIN_3D_WTLVL [7:0]
#define P5_F6_SDRF_MN_3D_READ_NUM_H        0x05F6 // MAIN_3D_READ_NUM[15:8]
#define P5_F7_SDRF_MN_3D_READ_NUM_L        0x05F7 // MAIN_3D_READ_NUM[7:0]
#define P5_F8_SDRF_MN_3D_READ_LEN          0x05F8 // MAIN_3D_READ_LEN [7:0]
#define P5_F9_SDRF_MN_3D_READ_REMAIN       0x05F9 // MAIN_3D_READ_REMAIN [7:0]
#define P5_FA_SDRF_MN_3D_READ_ADDR_H       0x05FA // MAIN_ 3D_READ_ADDR [22:16]
#define P5_FB_SDRF_MN_3D_READ_ADDR_M       0x05FB // MN_3D_READ_ADDR_M  
#define P5_FC_SDRF_MN_3D_READ_ADDR_L       0x05FC // MAIN_3D_READ_ADDR [7:0]
#define P5_FD_SDRF_MN_3D_LINE_STEP_H       0x05FD // MAIN_3D_LINE_STEP[13:8]
#define P5_FE_SDRF_MN_3D_LINE_STEP_L       0x05FE // MAIN_3D_LINE_STEP[7:0]
#define P5_FF_SDRF_MN_MADDR_TOG_REM        0x05FF // MAIN_MADR_TOG_REM[7:0]

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// Page 6: Internal OSC & AUDIO DAC //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// Internal OSC (Page 6)
//--------------------------------------------------
#define P6_A0_OSC_TRIM_CTRL0               0x06A0 // OSC Trimming Control Register
#define P6_A1_OSC_TRIM_CTRL1               0x06A1 // OSC Trimming Comparison Target
#define P6_A2_OSC_TRIM_CTRL2               0x06A2 // OSC Trimming Result
#define P6_A3_EMBEDDED_OSC_CTRL            0x06A3 // Embedded OSC Control
#define P6_A4_OSC_TRIM_CNT                 0x06A4 // Embedded OSC Trimming Counter LSB
#define P6_A5_EMB_BGRES                    0x06A5 // Embedded OSC Trimming Counter MSB and Trimming Target MSB
#define P6_A6_EMB_BGRES                    0x06A6 // Embedded OSC Thermal Compensation Factor

//--------------------------------------------------
// AUDIO DAC (Page 6)
//--------------------------------------------------
#define P6_B0_BB_POWER0                    0x06B0 // DAC Power Control0
#define P6_B1_BB_POWER1                    0x06B1 // DAC Power Control1
#define P6_B2_BB_ZCD_ANA                   0x06B2 // Zero Crossing Comparator Control
#define P6_B3_AOUT_CTL                     0x06B3 // DAC AOUT Control
#define P6_B4_HPOUT_CTL                    0x06B4 // DAC HPOUT Control
#define P6_B5_MBIAS_CTL0                   0x06B5 // DAC Bias Current Control0
#define P6_B6_MBIAS_CTL1                   0x06B6 // DAC Bias Current Control1
#define P6_B7_VREF_CTL                     0x06B7 // DAC Reference Voltage Control
#define P6_B8_DAC_VOL_L                    0x06B8 // Volume Control for DAC Output (Left)
#define P6_B9_DAC_VOL_R                    0x06B9 // Volume Control for DAC Output (Right)
#define P6_BA_AIN_VOL_L                    0x06BA // Volume Control for AIN Output (Left)
#define P6_BB_AIN_VOL_R                    0x06BB // Volume Control for AIN Output (Right)
#define P6_BC_ANA_RESERVE1                 0x06BC // Input Impedance Adjustment
#define P6_BD_ANA_RESERVE2                 0x06BD // Reserved
#define P6_BE_MODULATOR_CTL                0x06BE // DAC Modulator Control
#define P6_BF_BIST_CONTROL                 0x06BF // DAC BIST Control

#define P6_C0_SDM_OUT_VALUE_MSB            0x06C0 // SDM Out Test Value[15:8]
#define P6_C1_SDM_OUT_VALUE_LSB            0x06C1 // SDM Out Test Value[7:0]
#define P6_C2_ZERO_CROSSING_CTRL           0x06C2 // Zero Crossing Control Register
#define P6_C3_ZCD_TIMEOUT                  0x06C3 // ZCD Timeout Target
#define P6_C4_ZCD_STATUS                   0x06C4 // ZCD Status
#define P6_C5_DIG_RESERVE1                 0x06C5 // Reserved
#define P6_C6_DIG_RESERVE2                 0x06C6 // Reserved
#define P6_C7_DIG_RESERVE_RONLY            0x06C7 // Reserved
#define P6_C8_DEPOP_CTRL0                  0x06C8 // De-pop Control Register 0
#define P6_C9_DEPOP_CTRL1                  0x06C9 // De-pop Control Register 1
#define P6_CA_DEPOP_CTRL2                  0x06CA // De-pop Control Register 2
#define P6_CB_DEPOP_CTRL4                  0x06CB // De-pop Control Register 4
#define P6_CC_DEPOP_CTRL5                  0x06CC // De-pop Control Register 5
#define P6_CD_DEPOP_CTRL6                  0x06CD // De-pop Control Register 6
#define P6_CE_LFSR_CTRL                    0x06CE // LFSR Control

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
#define P7_D4_ICM_NEW_MODE                 0x07D4 // New ICM Mode select
#define P7_D6_PKING_ACCESS_PORT            0x07D6 // Y Peaking Coring Access Port
#define P7_D7_PKING_DATA_PORT              0x07D7 // Y Peaking Coring Data Port

//--------------------------------------------------
// DCR (Page7)
//--------------------------------------------------
#define P7_D8_DCR_ACCESS_PORT              0x07D8 // DCR Access Port
#define P7_D9_DCR_DATA_PORT                0x07D9 // DCR Data Port

//--------------------------------------------------
// CABC (Page7)
//--------------------------------------------------
#define P7_DB_CABC_CTRL                    0x07DB // CABC Control
#define P7_DC_CABC_ADDRESS_PORT            0x07DC // CABC Address Port
#define P7_DD_CABC_DATA_PORT               0x07DD // CABC Data Port 

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
#define P7_FC_DISP_PG_INITIAL_LSB          0x07FC // initial Value for RGB LSB 2bits 

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 8: Digital Volume Control //////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// Digital Volume Control (Page 8)
//--------------------------------------------------
#define P8_A0_DVC_0                        0x08A0 // DVC Register 0
#define P8_A1_DVC_1                        0x08A1 // DVC Register 1
#define P8_A2_DVC_VA_DB                    0x08A2 // DVC Valume Double Buffer
#define P8_A3_DVC_WINDOW_CONTROL_0         0x08A3 // DVC Window Control 0
#define P8_A4_DVC_WINDOW_CONTROL_1         0x08A4 // DVC Window Control 1
#define P8_A5_GAIN_0                       0x08A5 // DVC Gain 0
#define P8_A6_GAIN_DB                      0x08A6 // DVC Gain Double Buffer
#define P8_A7_GAIN_1                       0x08A7 // DVC Gain 1
#define P8_A8_GAIN_2                       0x08A8 // DVC Gain 2
#define P8_A9_GAIN_DONE                    0x08A9 // DVC Gain Done
#define P8_AA_DVC_RESERVE1                 0x08AA // DVC Reserve1
#define P8_AB_DVC_RESERVE2                 0x08AB // DVC Reserve2

//--------------------------------------------------
// Peak Detection (Page 8)
//--------------------------------------------------
#define P8_C0_PEAK_CTRL_0                  0x08C0 // Peak Control Register 0
#define P8_C1_PEAK_CTRL_1                  0x08C1 // Peak Control Register 1
#define P8_C2_PEAK_CTRL_L_0                0x08C2 // The overflow threshold of left channel[23:16]
#define P8_C3_PEAK_CTRL_L_1                0x08C3 // The overflow threshold of left channel[15:8]
#define P8_C4_PEAK_CTRL_L_2                0x08C4 // The overflow threshold of left channel[7:0]
#define P8_C5_PEAK_CTRL_L_3                0x08C5 // Monitor period of left channel for peak detection[15:8]
#define P8_C6_PEAK_CTRL_L_4                0x08C6 // Monitor period of left channel for peak detection[7:0]
#define P8_C7_PEAK_CTRL_R_0                0x08C7 // The overflow threshold of right channel[23:16]
#define P8_C8_PEAK_CTRL_R_1                0x08C8 // The overflow threshold of right channel[15:8]
#define P8_C9_PEAK_CTRL_R_2                0x08C9 // The overflow threshold of right channel[7:0]
#define P8_CA_PEAK_CTRL_R_3                0x08CA // Monitor period of right channel for peak detection[15:8]
#define P8_CB_PEAK_CTRL_R_4                0x08CB // Monitor period of right channel for peak detection[7:0]
#define P8_CC_PEAK_RESERVE1                0x08CC // Reserved
#define P8_CD_PEAK_RESERVE2                0x08CD // Reserved

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 9: Input Gamma Control ///////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P9_A0_INPUT_GAMMA_PORT             0x09A0 // Input Gamma Access Port
#define P9_A1_INPUT_GAMMA_CTRL             0x09A1 // Input Gamma Control Register
#define P9_A2_INPUT_GAMMA_LOW_THRE         0x09A2 // Input Gamma Low Threshold Value
#define P9_A3_INPUT_GAMMA_HIGH_THRE        0x09A3 // Input Gamma High Threshold Value


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page A: Reserved //////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define PA_A0_DP_SIG_DET_MEASURE           0x0AA0 // 
#define PA_A1_DP_SIG_DET_EN                0x0AA1 // 
#define PA_A2_DP_SIG_DET_RESULT            0x0AA2 // 
#define PA_A3_DP_SIG_DET_RBR_THL_01        0x0AA3 // 
#define PA_A4_DP_SIG_DET_RBR_THL_02        0x0AA4 // 
#define PA_A5_DP_SIG_DET_RBR_THL_03        0x0AA5 // 
#define PA_A6_DP_SIG_DET_RBR_THL_04        0x0AA6 // 
#define PA_A7_DP_SIG_DET_HBR_THL_01        0x0AA7 // 
#define PA_A8_DP_SIG_DET_HBR_THL_02        0x0AA8 // 
#define PA_A9_DP_SIG_DET_HBR_THL_03        0x0AA9 // 
#define PA_AA_DP_SIG_DET_HBR_THL_04        0x0AAA // 
#define PA_AB_DP_SIG_DET_HBR2_THL_01       0x0AAB // 
#define PA_AC_DP_SIG_DET_HB2R_THL_02       0x0AAC // 
#define PA_AD_DP_SIG_DET_HBR2_THL_03       0x0AAD // 
#define PA_AE_DP_SIG_DET_HBR2_THL_04       0x0AAE // 
#define PA_AF_DP_SIG_DET_COUNTER_0         0x0AAF // 

#define PA_B0_DP_SIG_DET_COUNTER_1	       0x0AB0 // 
#define PA_B1_DP_SIG_DET_COUNTER_2  	   0x0AB1 // 
#define PA_B2_DP_SIG_DET_COUNTER_3   	   0x0AB2 // 
#define PA_B3_DP_SIG_DET_COUNTER_4         0x0AB3 // 
#define PA_B4_DP_SIG_DET_COUNTER_5         0x0AB4 // 
#define PA_B5_DP_SIG_DET_COUNTER_6         0x0AB5 // 
#define PA_B6_DP_SIG_DET_COUNTER_7	       0x0AB6 // 
#define PA_B7_DP_SIG_DET_NO_CLK            0x0AB7 // 
#define PA_B8_DP_SIG_DET_RESERVED          0x0AB8 // 

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page B: DisplayPort PHY ///////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

#define PB_A0_SIG_DET                      0x0BA0 //                     
#define PB_A1_FLD_FSM_0                    0x0BA1 //                     
#define PB_A2_FLD_FSM_1                    0x0BA2 //                     
#define PB_A3_RESERVED_1                   0x0BA3 //                     
#define PB_A4_CDR_2                    	   0x0BA4 //                     
#define PB_A5_CDR_3                    	   0x0BA5 //                     
#define PB_A6_CDR_4                    	   0x0BA6 //                     
#define PB_A7_CDR_5                    	   0x0BA7 //                     
#define PB_A8_CDR_6                    	   0x0BA8 //                     
#define PB_A9_CDR_7                    	   0x0BA9 //                     
#define PB_AA_CDR_8                    	   0x0BAA //                     
#define PB_AB_CDR_9                    	   0x0BAB //                     
#define PB_AC_CDR_A                    	   0x0BAC //                     
#define PB_AD_RXMISC_0                     0x0BAD //                     
#define PB_AE_RXMISC_1                 	   0x0BAE //                     
#define PB_AF_RXMISC_2                 	   0x0BAF //                     
                                                          
#define PB_B0_EQ_0                	       0x0BB0 //          
#define PB_B1_EQ_1              	       0x0BB1 //          
#define PB_B2_EQ_2                    	   0x0BB2 //                  
#define PB_B3_SINGLE_END                   0x0BB3 //                  
#define PB_B4_POWER_0                      0x0BB4 //                  
#define PB_B5_DP_2D_SWITCH                 0x0BB5 //                  
#define PB_B6_Z0_0            		       0x0BB6 //          
#define PB_B7_Z0_1                         0x0BB7 //                  
#define PB_B8_Z0_2                         0x0BB8 //                  
#define PB_B9_RESERVED_3                   0x0BB9 //                  
#define PB_BA_EQ_3               	       0x0BBA //                       
#define PB_BB_BANDGAP               	   0x0BBB //                               
#define PB_BC_EQ_4                 	       0x0BBC //               
#define PB_BD_EQ_5               	       0x0BBD //               
#define PB_BE_EQ_6               	       0x0BBE //               
#define PB_BF_EQ_7               	       0x0BBF //               
                                                     
#define PB_C0_TMDS_CONT_0                  0x0BC0 //                       
#define PB_C1_TMDS_CONT_1                  0x0BC1 //                       
#define PB_C2_TMDS_CONT_2                  0x0BC2 //                       
#define PB_C3_TMDS_CONT_3                  0x0BC3 //                       
#define PB_C4_TMDS_CONT_4                  0x0BC4 //                       
#define PB_C5_TMDS_CONT_5                  0x0BC5 //                       
#define PB_C6_TMDS_CONT_6                  0x0BC6 //                       
#define PB_C7_TMDS_CONT_7                  0x0BC7 //                       
#define PB_C8_FLD_CONT_0                   0x0BC8 //                       
#define PB_C9_FLD_CONT_1                   0x0BC9 //                       
#define PB_CA_FLD_CONT_2                   0x0BCA //                       
#define PB_CB_FLD_CONT_3            	   0x0BCB //                       
#define PB_CC_FLD_CONT_4              	   0x0BCC //                       
#define PB_CD_FLD_CONT_5                   0x0BCD // 
#define PB_CE_FLD_CONT_6                   0x0BCE //                       
#define PB_CF_FLD_CONT_7               	   0x0BCF //                       
                                                     
#define PB_D0_RXMISC_3                     0x0BD0 //                       
#define PB_D1_RXMISC_4                     0x0BD1 //                       
#define PB_D2_RESERVED_4                   0x0BD2 //                       
#define PB_D3_RESERVED_5                   0x0BD3 //                       
#define PB_D4_RESERVED_6                   0x0BD4 //                       
#define PB_D5_RESERVED_7                   0x0BD5 //                       
#define PB_D6_RESERVED_8                   0x0BD6 //                       
#define PB_D7_RESERVED_9                   0x0BD7 //                       
#define PB_D8_VCO_0                   	   0x0BD8 //                       
#define PB_D9_VCO_1                        0x0BD9 //                       
#define PB_DA_VCO_2                        0x0BDA //                       
#define PB_DB_VCO_3                   	   0x0BDB //                       
#define PB_DC_VCO_4                   	   0x0BDC //                       
#define PB_DD_VCO_5                   	   0x0BDD //                       
#define PB_DE_VCO_6                   	   0x0BDE //                       
#define PB_DF_VCO_7                   	   0x0BDF //                       
                                                     
#define PB_E0_DIG00                        0x0BE0 //                       
#define PB_E1_DIG01                        0x0BE1 //                       
#define PB_E2_DIG02                        0x0BE2 //                       
#define PB_E3_DIG03                        0x0BE3 //                       
#define PB_E4_DIG04                        0x0BE4 //                       
#define PB_E5_DIG05                        0x0BE5 //                       
#define PB_E6_DIG06                        0x0BE6 //                       
#define PB_E7_DIG07                        0x0BE7 //                       
#define PB_E8_DIG08                        0x0BE8 //                       
#define PB_E9_SSCG_DIG                     0x0BE9 //                       
#define PB_EA_DIG_TX_00                    0x0BEA //                       
#define PB_EB_DIG_TX_01                    0x0BEB //                       
#define PB_EC_DIG_TX_02                    0x0BEC //                       
#define PB_ED_DIG_TX_03                    0x0BED //                       
#define PB_EE_RESERVED_A               	   0x0BEE //                       
#define PB_EF_DIG_TX_04               	   0x0BEF //                       
                                                     
#define PB_F0_AUX_1                        0x0BF0 //                       
#define PB_F1_AUX_2                        0x0BF1 //                       
#define PB_F2_AUX_3                        0x0BF2 //                       
#define PB_F3_AUX_4                        0x0BF3 //                       
#define PB_F4_AUX_5                        0x0BF4 //                       
#define PB_F5_HW_AUTO_PS                   0x0BF5 //                       
#define PB_F6_TXBIST_00                    0x0BF6 //                       
#define PB_F7_TXBIST_01                    0x0BF7 //                       
#define PB_F8_TXBIST_02                    0x0BF8 //                       
#define PB_F9_TXBIST_03                    0x0BF9 //                       
#define PB_FA_TXBIST_04                    0x0BFA //                       
#define PB_FB_TXBIST_05                    0x0BFB //                       
#define PB_FC_TXBIST_06                    0x0BFC //                       
#define PB_FD_TXBIST_07                    0x0BFD //                       
#define PB_FE_TXBIST_08                    0x0BFE //                       
#define PB_FF_RXBIST_0			           0x0BFF //
/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page C: DisplayPort MAC ///////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// DisplayPort - MAC Control (PageC)
//--------------------------------------------------
#define PC_A1_DP_CTL                       0x0CA1 // DP General Control
#define PC_A2_DP_OUTPUT_CTL                0x0CA2 // DP General Output Control
#define PC_A3_DP_OUTPUT_CLK_CTL            0x0CA3 // DP Output Clock Control
#define PC_A4_LANE_SWAP                    0x0CA4 // DP Lane Swap
#define PC_A5_DP_LANE_VALID                0x0CA5 // DP Lane Valid Control(write 1 clear)
#define PC_A6_DP_LANE_LOCK                 0x0CA6 // DP Lane Lock Control (write 1 clear)
#define PC_A7_DP_LANE_CLK_INV              0x0CA7 // DP Lane Clock Inverse Control
#define PC_A8_MIN_DE_SKEW                  0x0CA8 // Minimize The De-Skew Between Lanes
#define PC_A9_MN_ERRC                      0x0CA9 // Video/ Audio Error Correction
#define PC_AA_MN_ERRC_CTL                  0x0CAA // Video/ Audio Error Correction Control
#define PC_AB_DP_CRC                       0x0CAB // CRC Control Register
#define PC_AC_DP_CRC_R_H                   0x0CAC // CRC Result High Byte for R channel
#define PC_AD_DP_CRC_R_L                   0x0CAD // CRC Result Low Byte for R channel
#define PC_AE_DP_CRC_G_H                   0x0CAE // CRC Result High Byte for G channel
#define PC_AF_DP_CRC_G_L                   0x0CAF // CRC Result Low Byte for G channel

#define PC_B0_DP_CRC_B_H                   0x0CB0 // CRC Result High Byte for B channel
#define PC_B1_DP_CRC_B_L                   0x0CB1 // CRC Result Low Byte for B channel
#define PC_B2_DP_MEM_BIST                  0x0CB2 // Memory Bist Control Register
#define PC_B3_DP_ACCESS_PORT               0x0CB3 // DP Access Port
#define PC_B4_DP_DATA_PORT                 0x0CB4 // DP Data Port
#define PC_B5_DP_DEBUG_SEL0                0x0CB5 // Debug Output Selector
#define PC_B6_DP_DEBUG_SEL1                0x0CB6 // AUX-CH/Display Format Debug Output Selector
#define PC_B7_DP_DEBUG_SEL2                0x0CB7 // SCK Gen./Channel Recovery Debug Output Selector
#define PC_B8_DP_INFO_FM_ADR               0x0CB8 // Info-Frame Memory Address Port
#define PC_B9_DP_INFO_FM_DAT               0x0CB9 // Info // -Frame Memory Data Port
#define PC_BA_DP_GPI_FUNCTION              0x0CBA // DP G // PI Function Control
#define PC_BB_DP_RESERVE1                  0x0CBB // DP Reserve 1
#define PC_BC_DP_RESERVE2                  0x0CBC // DP Reserve 2
#define PC_BD_DPCD_600_CTRL                0x0CBD // DPCD 0x00600 Control Register
#define PC_BE_CRC_CB_M                     0x0CBE // CRC_CB Value When 422[15:8]
#define PC_BF_CRC_CB_L                     0x0CBF // CRC_CB Value When 422[7:0]

#define PC_C0_DPCD_CTL                     0x0CC0 // DPCD Control Register
#define PC_C1_DPCD_ACCESS_PORT_H           0x0CC1 // DPCD Access Port High Byte
#define PC_C2_DPCD_ACCESS_PORT_M           0x0CC2 // DPCD Access Port Middle Byte
#define PC_C3_DPCD_ACCESS_PORT_L           0x0CC3 // DPCD Access Port Low Byte
#define PC_C4_DPCD_DATA_PORT_L             0x0CC4 // DPCD Data Port Low Byte
#define PC_C5_AUX_PHY_DIG1                 0x0CC5 // DP AUX PHY_DIG1
#define PC_C6_AUX_PHY_DIG2                 0x0CC6 // DP AUX PHY_DIG2
#define PC_C7_AUX_RESERVE2                 0x0CC7 // DP AUX Reserve 2
#define PC_C8_AUX_PHY_DIG3                 0x0CC8 // DP AUX Reserve 3
#define PC_C9_AUX_RESERVE4                 0x0CC9 // DP AUX Reserve 4
#define PC_CA_READ_RESERVE0                0x0CCA // DP Read Reserve 0
#define PC_CB_READ_RESERVE1                0x0CCB // DP Read Reserve 1
#define PC_CC_LANE0_OUT                    0x0CCC // DP Lane0 Data
#define PC_CD_LANE1_OUT                    0x0CCD // DP Lane1 Data
#define PC_CE_LANE2_OUT                    0x0CCE // DP Lane2 Data
#define PC_CF_LANE3_OUT                    0x0CCF // DP Lane3 Data

#define PC_D0_AUX_MODE_SET                 0x0CD0 // AUX Channel Control Register
#define PC_D1_AUX_IIC_SET                  0x0CD1 // IIC Setting for AUX Channel
#define PC_D2_AUX_RX_CMD                   0x0CD2 // RX Command for AUX Channel and Reveived Address High Byte
#define PC_D3_AUX_RX_ADDR_M                0x0CD3 // RX AUX Channel Reveived Address Middle Byte
#define PC_D4_AUX_RX_ADDR_L                0x0CD4 // RX AUX Channel Reveived Address Low Byte
#define PC_D5_AUX_RX_LEN                   0x0CD5 // RX AUX Channel Reveived Length
#define PC_D6_AUX_RX_DATA                  0x0CD6 // RX AUX Channel Reveived Data Port
#define PC_D7_AUX_TX_CMD                   0x0CD7 // TX Command for AUX Channel
#define PC_D8_AUX_TX_LEN                   0x0CD8 // TX AUX Channel Reveived Length
#define PC_D9_AUX_TX_DATA                  0x0CD9 // TX AUX Channel Reveived Data Port
#define PC_DA_AUX_FIFO_RST                 0x0CDA // FIFO ResetRegister
#define PC_DB_AUX_STATUS                   0x0CDB // AUX Channel Status Register
#define PC_DC_AUX_IRQ_STATUS               0x0CDC // AUX Channel IRQ Status Register
#define PC_DD_AUX_DPCD_IRQ                 0x0CDD // DPCD IRQ Control Register
#define PC_DE_AUX_DPCD_IRQ_EN              0x0CDE // DPCD IRQ Enable Control Register
#define PC_DF_AUX_IIC_MASTER_CTRL          0x0CDF // AUX IIC Master Control Register

//--------------------------------------------------
// DisplayPort - HDCP1.3(PageC)
//--------------------------------------------------
#define PC_E0_DP_HDCP_CONTROL              0x0CE0 // HDCP Control Register
#define PC_E1_DP_HDCP_KEY_DOWNLOAD_PORT    0x0CE1 // HDCP Key Download Port
#define PC_E2_DP_HDCP_KEY_OUTPUT           0x0CE2 // HDCP Key Output
#define PC_E3_HDCP_IRQ                     0x0CE3 // HDCP IRQ Control
#define PC_E4_HDCP_INTGT_VRF               0x0CE4 // HDCP Link Integrity
#define PC_E5_HDCP_INTGT_VRF_PAT_MSB       0x0CE5 // Setting of Integrity Pattern(MSB)
#define PC_E6_HDCP_INTGT_VRF_PAT_LSB       0x0CE6 // Setting of Integrity Pattern(LSB)
#define PC_E7_HDCP_INTGT_VRF_ANS_MSB       0x0CE7 // Real Calculation Result of Integrity Pattern(MSB)
#define PC_E8_HDCP_INTGT_VRF_ANS_LSB       0x0CE8 // Real Calculation Result of Integrity Pattern(LSB)
#define PC_E9_DP_HDCP_BIST                 0x0CE9 // HDCP BIST Control
#define PC_EA_HDCP_DEBUG                   0x0CEA // HDCP Debug Mode Control
#define PC_EB_RI_BYTE_MSB                  0x0CEB // Ri MSB
#define PC_EC_RI_BYTE_LSB                  0x0CEC // Ri LSB
#define PC_ED_KM_BYTE_6                    0x0CED // Km[55:48] Value
#define PC_EE_KM_BYTE_5                    0x0CEE // Km[47:40] Value
#define PC_EF_KM_BYTE_4                    0x0CEF // Km[39:32] Value

#define PC_F0_KM_BYTE_3                    0x0CF0 // Km[31:24] Value
#define PC_F1_KM_BYTE_2                    0x0CF1 // Km[23:16] Value
#define PC_F2_KM_BYTE_1                    0x0CF2 // Km[15:8] Value
#define PC_F3_KM_BYTE_0                    0x0CF3 // Km[7:0] Value
#define PC_F4_AUX_TX_TIMER                 0x0CF4 // AUX Tx Timer Control Register
#define PC_F5_AUX_ERROR_HANDLE             0x0CF5 // AUX Error Handle Control Register 1
#define PC_F6_AUX_ERROR_HANDLE2            0x0CF6 // AUX Error Handle Control Register 2
#define PC_F7_W_RESERVE2                   0x0CF7 // Reserve
#define PC_F8_W_RESERVE3                   0x0CF8 // Reserve
#define PC_F9_W_RESERVE4                   0x0CF9 // Reserve
#define PC_FA_R_RESERVE0                   0x0CFA // Record AUX Chaneel MAC State Machine State
#define PC_FB_R_RESERVE1                   0x0CFB // Reserve
#define PC_FC_R_RESERVE2                   0x0CFC // Reserve
#define PC_FD_R_RESERVE3                   0x0CFD // Reserve
#define PC_FE_R_RESERVE4                   0x0CFE // Reserve


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 10: Register4 ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------
// Pin Share(Page 10)
//--------------------------------------------------
#define P10_A0_PIN_SHARE_CTRL00            0x10A0 
#define P10_A1_PIN_SHARE_CTRL01            0x10A1 
#define P10_A2_PIN_SHARE_CTRL02            0x10A2 
#define P10_A3_PIN_SHARE_CTRL03            0x10A3 
#define P10_A4_PIN_SHARE_CTRL04            0x10A4 
#define P10_A5_PIN_SHARE_CTRL05            0x10A5 
#define P10_A6_PIN_SHARE_CTRL06            0x10A6 
#define P10_A7_PIN_SHARE_CTRL07            0x10A7 
#define P10_A8_PIN_SHARE_CTRL08            0x10A8 
#define P10_A9_PIN_SHARE_CTRL09            0x10A9 
#define P10_AA_PIN_SHARE_CTRL0A            0x10AA 
#define P10_AB_PIN_SHARE_CTRL0B            0x10AB 
#define P10_AC_PIN_SHARE_CTRL0C            0x10AC 
#define P10_AD_PIN_SHARE_CTRL0D            0x10AD 
#define P10_AE_PIN_SHARE_CTRL0E            0x10AE 
#define P10_AF_PIN_SHARE_CTRL0F            0x10AF 

#define P10_B0_PIN_SHARE_CTRL10            0x10B0
#define P10_B1_PIN_SHARE_CTRL11            0x10B1 
#define P10_B2_PIN_SHARE_CTRL12            0x10B2 
#define P10_B3_PIN_DRIVING_CTRL1           0x10B3 
#define P10_B4_PIN_DRIVING_CTRL2           0x10B4 
#define P10_B5_PIN_DRIVING_CTRL3           0x10B5 
#define P10_B6_PIN_SHARE_CTRL13            0x10B6 
#define P10_B7_PIN_SHARE_CTRL14            0x10B7 
#define P10_B8_PIN_SHARE_CTRL15            0x10B8 
#define P10_B9_PIN_SHARE_CTRL16            0x10B9 
#define P10_BA_DVI_CTRL_OUT_SEL            0x10BA // DVI Output Control Register
#define P10_BB_PIN_PULLUP_CTRL4            0x10BB // Pull up Control Register 4
#define P10_BC_PIN_PULLUP_CTRL5            0x10BC // Pull up Control Register 5
#define P10_BD_IICAUX_DDC2P_CTRL0          0x10BD

#define P10_C0_PIN_SHARE_SDRAM_CTRL0       0x10C0 // Pin Share SDRAM Control Register 0
#define P10_C1_PIN_SHARE_SDRAM_CTRL1       0x10C1 // Pin Share SDRAM Control Register 1
#define P10_C2_PIN_SHARE_SDRAM_CTRL2       0x10C2 // Pin Share SDRAM Control Register 2
#define P10_C3_PIN_SHARE_SDRAM_CTRL3       0x10C3 // Pin Share SDRAM Control Register 3
#define P10_C4_PIN_SHARE_SDRAM_CTRL4       0x10C4 // Pin Share SDRAM Control Register 4
#define P10_C5_PIN_SHARE_SDRAM_CTRL5       0x10C5 // Pin Share SDRAM Control Register 5

#define P10_D0_PIN_SHARE_CTRL13            0x10D0 
#define P10_D1_PIN_SHARE_CTRL14            0x10D1 
#define P10_D2_PIN_SHARE_CTRL15            0x10D2 
#define P10_D3_PIN_SHARE_CTRL16            0x10D3 
#define P10_D4_PIN_SHARE_CTRL17            0x10D4 
#define P10_D5_PIN_SHARE_CTRL18            0x10D5 
#define P10_D6_PIN_SHARE_CTRL19            0x10D6 
#define P10_D7_PIN_SHARE_CTRL1A            0x10D7 
#define P10_D8_PIN_SHARE_CTRL1B            0x10D8 
#define P10_D9_PIN_SHARE_CTRL1C            0x10D9 
#define P10_DA_PIN_SHARE_CTRL1D            0x10DA 
#define P10_DB_PIN_SHARE_CTRL1E            0x10DB 
#define P10_DC_PIN_SHARE_CTRL1F            0x10DC 
#define P10_DD_PIN_SHARE_CTRL20            0x10DD 
#define P10_DE_PIN_SHARE_CTRL21            0x10DE
#define P10_DF_PIN_SHARE_CTRL22            0x10DF 
#define P10_E0_PIN_SHARE_CTRL23            0x10E0 
#define P10_E1_PIN_SHARE_CTRL24            0x10E1 
#define P10_E2_PIN_SHARE_CTRL25            0x10E2 
#define P10_E3_PIN_SHARE_CTRL26            0x10E3 
#define P10_E4_PIN_SHARE_CTRL27            0x10E4 
#define P10_E5_PIN_SHARE_CTRL28            0x10E5 
#define P10_E6_PIN_SHARE_CTRL29            0x10E6 
#define P10_E7_PIN_SHARE_CTRL2A            0x10E7 
#define P10_E8_PIN_SHARE_CTRL2B            0x10E8 
#define P10_E9_PIN_SHARE_CTRL2C            0x10E9 
#define P10_EA_PIN_SHARE_CTRL2D            0x10EA 
#define P10_EB_PIN_SHARE_CTRL2E            0x10EB 
#define P10_EC_PIN_SHARE_CTRL2F            0x10EC 
#define P10_ED_PIN_SHARE_CTRL30            0x10ED 
#define P10_EE_PIN_SHARE_CTRL31            0x10EE 
#define P10_EF_PIN_SHARE_CTRL32            0x10EF 
#define P10_F0_PIN_SHARE_CTRL33            0x10F0 
#define P10_F1_PIN_SHARE_CTRL34            0x10F1 
#define P10_F2_PIN_SHARE_CTRL35            0x10F2
#define P10_F3_PIN_SHARE_CTRL36            0x10F3 
#define P10_F4_PIN_SHARE_CTRL37            0x10F4
#define P10_F5_PIN_SHARE_CTRL38            0x10F5 
#define P10_F6_PIN_SHARE_CTRL39            0x10F6 
#define P10_F7_PIN_SHARE_CTRL3A            0x10F7
#define P10_F8_PIN_SHARE_CTRL3B            0x10F8
#define P10_F9_PIN_SHARE_CTRL3C            0x10F9 
#define P10_FA_PIN_SHARE_CTRL3D            0x10FA

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 11: ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------
// Super Resolution(Page 11)
//--------------------------------------------------
#define P11_A1_I_DLTI_CTRL_0               0x11A1 //I_DLTI  
#define P11_A2_I_DLTI_CTRL_1               0x11A2                             
#define P11_A3_I_DLTI_CTRL_2               0x11A3              
#define P11_A4_I_DLTI_UPPER_TH_HSB         0x11A4                          
#define P11_A5_I_DLTI_UPPER_TH_LSB         0x11A5                   
#define P11_A6_I_DLTI_LOWER_TH_HSB         0x11A6                   
#define P11_A7_I_DLTI_LOWER_TH_LSB         0x11A7                  
#define P11_A8_I_DLTI_C0_HSB               0x11A8             
#define P11_A9_I_DLTI_C0_LSB               0x11A9             
#define P11_AA_I_DLTI_C1_HSB               0x11AA             
#define P11_AB_I_DLTI_C1_LSB               0x11AB          
#define P11_AC_I_DLTI_C2_HSB               0x11AC              
#define P11_AD_I_DLTI_C2_LSB               0x11AD             
#define P11_AE_I_DLTI_C3_HSB               0x11AE              
#define P11_AF_I_DLTI_C3_LSB               0x11AF             
#define P11_B0_I_DLTI_C4_HSB               0x11B0              
#define P11_B1_I_DLTI_C4_LSB               0x11B1             
#define P11_B3_I_DCTI_CTRL                 0x11B3 //I_DCTI
#define P11_B4_I_DCTI_1ST_TH_VALUE         0x11B4
#define P11_B5_I_DCTI_1ST_GAIN_VALUE       0x11B5                      
#define P11_B6_I_DCTI_2ND_TH_VALUE         0x11B6                    
#define P11_B7_I_DCTI_2ND_GAIN_VALUE       0x11B7                    
#define P11_B9_SCALER_PEAKING_C0           0x11B9 //VPK                        
#define P11_BA_SCALER_PEAKING_CC2          0x11BA 
#define P11_BB_SCALER_PEAKING_C3           0x11BB  
#define P11_BC_SCALER_PEAKING_CORING       0x11BC          
#define P11_BD_SCALER_PEAKING_X1           0x11BD      
#define P11_BE_SCALER_PEAKING_OFFSET       0x11BE 
#define P11_BF_SCALER_PEAKING_LIMIT        0x11BF 
#define P11_C0_SCALER_PEAKING_GAIN         0x11C0

#define P11_C1_SR_VCTI_CTRL                0x11C1 //VCTI  
#define P11_C2_SR_VCTI_TYPE3_THD           0x11C2
#define P11_C3_SR_VCTI_GAIN                0x11C3     
#define P11_C4_SR_VCTI_LPF_LBOUND2_HSB     0x11C4      
#define P11_C5_SR_VCTI_LPF_LBOUND2_LSB     0x11C5     
#define P11_C6_SR_VCTI_LPF_HBOUND2_HSB     0x11C6   
#define P11_C7_SR_VCTI_LPF_HBOUND2_LSB     0x11C7
#define P11_C8_SR_VCTI_LPF_LBOUND1_HSB     0x11C8      
#define P11_C9_SR_VCTI_LPF_LBOUND1_LSB     0x11C9     
#define P11_CA_SR_VCTI_LPF_HBOUND1_HSB     0x11CA   
#define P11_CB_SR_VCTI_LPF_HBOUND1_LSB     0x11CB

#define P11_CC_VPK_VCTI_HLW_H_START_HIGH   0x11CC //VPK_VCTI_HLW
#define P11_CD_VPK_VCTI_HLW_H_START_LOW    0x11CD
#define P11_CE_VPK_VCTI_HLW_H_END_HIGH     0x11CE 
#define P11_CF_VPK_VCTI_HLW_H_END_LOW      0x11CF
#define P11_D0_VPK_VCTI_HLW_V_START_HIGH   0x11D0   
#define P11_D1_VPK_VCTI_HLW_V_START_LOW    0x11D1  
#define P11_D2_VPK_VCTI_HLW_V_END_HIGH     0x11D2 
#define P11_D3_VPK_VCTI_HLW_V_END_LOW      0x11D3

#define P11_D4_IDCLTI_HLW_HOR_START_H      0x11D4 //IDLCTI_HLW
#define P11_D5_IDCLTI_HLW_HOR_START_L      0x11D5       
#define P11_D6_IDCLTI_HLW_HOR_END_H        0x11D6
#define P11_D7_IDCLTI_HLW_HOR_END_L        0x11D7
#define P11_D8_IDCLTI_HLW_VER_START_H      0x11D8 
#define P11_D9_IDCLTI_HLW_VER_START_L      0x11D9  
#define P11_DA_IDCLTI_HLW_VER_END_H        0x11DA
#define P11_DB_IDCLTI_HLW_VER_END_L        0x11DB
#define P11_DC_IDCLTI_HLW_CTRL             0x11DC

#define P11_F0_D_DLTI_OPTIONS              0x11F0 //D_DLTI
#define P11_F1_D_DLTI_VALUE_0              0x11F1     
#define P11_F2_D_DLTI_VALUE_1              0x11F2                
#define P11_F3_D_DLTI_VALUE_2              0x11F3  

#define P11_F4_D_DCTI_CTRL                 0x11F4 //D_DCTI
#define P11_F5_D_DCTI_1ST_TH_VALUE         0x11F5   
#define P11_F6_D_DCTI_1ST_GAIN_VALUE       0x11F6   
#define P11_F7_D_DCTI_2ND_TH_VALUE         0x11F7   
#define P11_F8_D_DCTI_2ND_GAIN_VALUE       0x11F8

#define P11_F9_UV_DELAY                    0x11F9

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 12: ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------
// Super Resolution(Page 12)
//--------------------------------------------------
#define P12_A0_SR_SHP_CTRL                 0x12A0 //SHP
#define P12_A1_SR_SHP_BIST_CTRL            0x12A1
#define P12_A2_SR_PEAKING_FILTER_0         0x12A2
#define P12_A3_SR_PEAKING_FILTER_C0_HSB    0x12A3     
#define P12_A4_SR_PEAKING_FILTER_C0_LSB    0x12A4   
#define P12_A5_SR_PEAKING_FILTER_C1_HSB    0x12A5  
#define P12_A6_SR_PEAKING_FILTER_C1_LSB    0x12A6   
#define P12_A7_SR_PEAKING_FILTER_C2        0x12A7  
#define P12_A8_SR_PEAKING_FILTER_C3        0x12A8  
#define P12_A9_SR_PEAKING_FILTER_C4        0x12A9  
#define P12_AA_SR_PEAKING_FILTER_C5        0x12AA  
#define P12_AB_SR_PEAKING_GAIN_BLR         0x12AB 
#define P12_AC_SR_PEAKING_GAIN_POS         0x12AC 
#define P12_AD_SR_PEAKING_GAIN_NEG         0x12AD        
#define P12_AE_SR_PEAKING_BOUND_HV_POS_HSB 0x12AE         
#define P12_AF_SR_PEAKING_BOUND_HV_POS_LSB 0x12AF         
#define P12_B0_SR_PEAKING_BOUND_HV_NEG_HSB 0x12B0         
#define P12_B1_SR_PEAKING_BOUND_HV_NEG_LSB 0x12B1  
#define P12_B2_SR_PEAKING_BOUND_LV         0x12B2

#define P12_B4_SR_PEAKING_EMF_OFFSET_HSB   0x12B4 //ENF
#define P12_B5_SR_PEAKING_EMF_OFFSET_LSB   0x12B5
#define P12_B6_SR_PEAKING_EMF_RANGE        0x12B6
#define P12_B7_SR_PEAKING_EMF_GAIN         0x12B7
#define P12_B8_SR_PEAKING_EMF_OFFSET_0     0x12B8
#define P12_B9_SR_PEAKING_EMF_OFFSET_1_HSB 0x12B9
#define P12_BA_SR_PEAKING_EMF_OFFSET_1_LSB 0x12BA
#define P12_BB_SR_PEAKING_EMF_OFFSET_2_HSB 0x12BB
#define P12_BC_SR_PEAKING_EMF_OFFSET_2_LSB 0x12BC
#define P12_BD_DM_EMFMK2_CTRL_0            0x12BD //EMF_MKII
#define P12_BE_DM_EMFMK2_CTRL_1            0x12BE
#define P12_BF_DM_EMFMK2_CTRL_2            0x12BF

#define P12_C0_SR_ECS_CTRL_0               0x12C0 //ECS
#define P12_C1_SR_ECS_CTRL_1               0x12C1   
#define P12_C2_SR_ECS_THL_NOISE_HSB        0x12C2          
#define P12_C3_SR_ECS_THL_NOISE_LSB        0x12C3          
#define P12_C4_SR_ECS_THL_CONTOUR_HSB      0x12C4            
#define P12_C5_SR_ECS_THL_CONTOUR_LSB      0x12C5
#define P12_C6_SR_ECS_THL_SAWTOOTH_HSB     0x12C6
#define P12_C7_SR_ECS_THL_SAWTOOTH_LSB     0x12C7

#define P12_C8_SR_RIPV_DATA                0x12C8 //RIPV
#define P12_C9_SR_RIPV_THD                 0x12C9

#define P12_CA_SR_CHROMA_LOWPASS           0x12CA //Chroma Lowpass

#define P12_CB_SR_AUTO_SHP_CTRL            0x12CB //Auto Sharpness
#define P12_D4_SR_AUTO_SHP_FIR_COUNT_01_L  0x12D4


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 13: ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------
// Super Resolution(Page 13)
//--------------------------------------------------
#define P13_A0_SR_CDS_CTRL                 0x13A0 //CDS
#define P13_A1_SR_CDS_CM1_CONTI_CTRL       0x13A1
#define P13_A2_SR_CDS_CM1_U_BOUND_U_0_HSB  0x13A2
#define P13_A3_SR_CDS_CM1_U_BOUND_U_0_LSB  0x13A3
#define P13_A4_SR_CDS_CM1_L_BOUND_U_0_HSB  0x13A4
#define P13_A5_SR_CDS_CM1_L_BOUND_U_0_LSB  0x13A5
#define P13_A6_SR_CDS_CM1_U_BOUND_V_0_HSB  0x13A6
#define P13_A7_SR_CDS_CM1_U_BOUND_V_0_LSB  0x13A7
#define P13_A8_SR_CDS_CM1_L_BOUND_V_0_HSB  0x13A8
#define P13_A9_SR_CDS_CM1_L_BOUND_V_0_LSB  0x13A9
#define P13_AA_SR_CDS_CM5_U_BOUND_U_0_HSB  0x13AA
#define P13_AB_SR_CDS_CM5_U_BOUND_U_0_LSB  0x13AB
#define P13_AC_SR_CDS_CM5_L_BOUND_U_0_HSB  0x13AC
#define P13_AD_SR_CDS_CM5_L_BOUND_U_0_LSB  0x13AD
#define P13_AE_SR_CDS_CM5_U_BOUND_V_0_HSB  0x13AE
#define P13_AF_SR_CDS_CM5_U_BOUND_V_0_LSB  0x13AF
#define P13_B0_SR_CDS_CM5_L_BOUND_V_0_HSB  0x13B0
#define P13_B1_SR_CDS_CM5_L_BOUND_V_0_LSB  0x13B1

#define P13_B2_SR_CDS_PEAKING_GAIN_BLR_CM1   0x13B2
#define P13_B3_SR_CDS_PEAKING_GAIN_POS_CM1   0x13B3
#define P13_B4_SR_CDS_PEAKING_GAIN_NEG_CM1   0x13B4
#define P13_B5_SR_CDS_PEAKING_HV_POS_CM1_HSB 0x13B5
#define P13_B6_SR_CDS_PEAKING_HV_POS_CM1_LSB 0x13B6
#define P13_B7_SR_CDS_PEAKING_HV_NEG_CM1_HSB 0x13B7
#define P13_B8_SR_CDS_PEAKING_HV_NEG_CM1_LSB 0x13B8
#define P13_B9_SR_CDS_PEAKING_LV_CM1         0x13B9

#define P13_BA_SR_CDS_PEAKING_GAIN_BLR_CM5   0x13BA
#define P13_BB_SR_CDS_PEAKING_GAIN_POS_CM5   0x13BB
#define P13_BC_SR_CDS_PEAKING_GAIN_NEG_CM5   0x13BC
#define P13_BD_SR_CDS_PEAKING_HV_POS_CM5_HSB 0x13BD
#define P13_BE_SR_CDS_PEAKING_HV_POS_CM5_LSB 0x13BE
#define P13_BF_SR_CDS_PEAKING_HV_NEG_CM5_HSB 0x13BF
#define P13_C0_SR_CDS_PEAKING_HV_NEG_CM5_LSB 0x13C0
#define P13_C1_SR_CDS_PEAKING_LV_CM5         0x13C1

#define P13_C2_SR_CDS_CM1_U_BOUND_U_1_HSB  0x13C2
#define P13_C3_SR_CDS_CM1_U_BOUND_U_1_LSB  0x13C3
#define P13_C4_SR_CDS_CM1_L_BOUND_U_1_HSB  0x13C4
#define P13_C5_SR_CDS_CM1_L_BOUND_U_1_LSB  0x13C5
#define P13_C6_SR_CDS_CM1_U_BOUND_V_1_HSB  0x13C6
#define P13_C7_SR_CDS_CM1_U_BOUND_V_1_LSB  0x13C7
#define P13_C8_SR_CDS_CM1_L_BOUND_V_1_HSB  0x13C8
#define P13_C9_SR_CDS_CM1_L_BOUND_V_1_LSB  0x13C9
#define P13_CA_SR_CDS_CM5_U_BOUND_U_1_HSB  0x13CA
#define P13_CB_SR_CDS_CM5_U_BOUND_U_1_LSB  0x13CB
#define P13_CC_SR_CDS_CM5_L_BOUND_U_1_HSB  0x13CC
#define P13_CD_SR_CDS_CM5_L_BOUND_U_1_LSB  0x13CD
#define P13_CE_SR_CDS_CM5_U_BOUND_V_1_HSB  0x13CE
#define P13_CF_SR_CDS_CM5_U_BOUND_V_1_LSB  0x13CF
#define P13_D0_SR_CDS_CM5_L_BOUND_V_1_HSB  0x13D0
#define P13_D1_SR_CDS_CM5_L_BOUND_V_1_LSB  0x13D1


#define P13_D4_SR_SKIPIR_CTRL1             0x13D4 //skipir
#define P13_D5_SR_SKIPIR_CTRL2             0x13D5
#define P13_D6_SR_SKIPIR_CTRL3             0x13D6
#define P13_D7_SR_SKIPIR_CTRL4             0x13D7
#define P13_D8_SR_SKIPIR_CTRL5             0x13D8
#define P13_D9_SR_SKIPIR_CTRL6             0x13D9
#define P13_DA_SR_SKIPIR_ISLETLV_U         0x13DA
#define P13_DB_SR_SKIPIR_ISLETGAIN_U       0x13DB
#define P13_DC_SR_SKIPIR_REVLV_U           0x13DC
#define P13_DD_SR_SKIPIR_REVGAIN_U         0x13DD
#define P13_DE_SR_SKIPIR_DEBUG             0x13DE

#define P13_DF_SR_DNoise_CTRL              0x13DF //DNoise
#define P13_E0_SR_DNoise_GAIN_LV           0x13E0   
#define P13_E1_SR_DNoise_GAIN_U_BAND       0x13E1       
#define P13_E2_SR_DNoise_LV_U_BAND         0x13E2     
#define P13_E3_SR_DNoise_NOISE_GAIN_TH     0x13E3         
#define P13_E4_SR_DNoise_NOISE_LV_TH       0x13E4


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 14: //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------
// ADC Noise Reduction
//--------------------------------------------------
#define P14_A0_SR_RGB2YCC_CTRL             0x14A0
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
///////////////////////////////////// Page 15: //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------
// Cyclic Redundant Check
//--------------------------------------------------
#define P15_B0_OP_CRC_CTRL                  0x15B0
#define P15_B2_OP_CRC_RESULT0               0x15B2
#define P15_B3_OP_CRC_RESULT1               0x15B3
#define P15_B4_OP_CRC_RESULT2               0x15B4
#define P15_B5_OP_CRC_RESULT3               0x15B5
#define P15_B6_OP_CRC_RESULT4               0x15B6
#define P15_B7_OP_CRC_RESULT5               0x15B7
#define P15_B8_OP_CRC_RESULT6               0x15B8
#define P15_B9_OP_CRC_RESULT7               0x15B9
#define P15_BA_OP_CRC_RESULT8               0x15BA
#define P15_BB_OP_CRC_RESULT9               0x15BB
#define P15_BC_OP_CRC_RESULT10              0x15BC
#define P15_BD_OP_CRC_RESULT11              0x15BD
#define P15_BE_OP_CRC_RESULT12              0x15BE
#define P15_BF_OP_CRC_RESULT13              0x15BF
#define P15_C0_OP_CRC_RESULT14              0x15C0
#define P15_C1_OP_CRC_RESULT15              0x15C1
#define P15_C2_OP_CRC_RESULT16              0x15C2
#define P15_C3_OP_CRC_RESULT17              0x15C3
#define P15_C4_OP_CRC_RESULT18              0x15C4
#define P15_C5_OP_CRC_RESULT19              0x15C5
#define P15_C6_OP_CRC_RESULT110             0x15C6
#define P15_C7_OP_CRC_RESULT111             0x15C7
#define P15_C8_OP_CRC_RESULT112             0x15C8
#define P15_C9_OP_CRC_RESULT113             0x15C9

//--------------------------------------------------
// TCON
//--------------------------------------------------
#define P15_D0_PIXEL_DETECT_CTRL           0x15D0 // 
#define P15_D8_ACCUMULATIVE_COUNT          0x15D8 // 

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// Page 1A: Input 3D Detection Register //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P1A_A0_IFC_GENERAL                 0x1AA0
#define P1A_A1_SR_YCC2RGB_CTRL             0x1AA1
#define P1A_A2_YUV_RGB_COEF_K11_HSB        0x1AA2
#define P1A_A3_YUV_RGB_COEF_K11_LSB        0x1AA3
#define P1A_A4_YUV_RGB_COEF_K13_HSB        0x1AA4
#define P1A_A5_YUV_RGB_COEF_K13_LSB        0x1AA5
#define P1A_A6_YUV_RGB_COEF_K22_HSB        0x1AA6
#define P1A_A7_YUV_RGB_COEF_K22_LSB        0x1AA7
#define P1A_A8_YUV_RGB_COEF_K23_HSB        0x1AA8
#define P1A_A9_YUV_RGB_COEF_K23_LSB        0x1AA9
#define P1A_AA_YUV_RGB_COEF_K32_HSB        0x1AAA
#define P1A_AB_YUV_RGB_COEF_K32_LSB        0x1AAB
#define P1A_AC_YUV_RGB_R_OFFSET_HSB        0x1AAC
#define P1A_AD_YUV_RGB_R_OFFSET_LSB        0x1AAD
#define P1A_AE_YUV_RGB_G_OFFSET_HSB        0x1AAE
#define P1A_AF_YUV_RGB_G_OFFSET_LSB        0x1AAF
#define P1A_B0_YUV_RGB_B_OFFSET_HSB        0x1AB0
#define P1A_B1_YUV_RGB_B_OFFSET_LSB        0x1AB1
#define P1A_B2_YUV_RGB_R_GAIN_HSB          0x1AB2
#define P1A_B3_YUV_RGB_R_GAIN_LSB          0x1AB3
#define P1A_B4_YUV_RGB_G_GAIN_HSB          0x1AB4
#define P1A_B5_YUV_RGB_G_GAIN_LSB          0x1AB5
#define P1A_B6_YUV_RGB_B_GAIN_HSB          0x1AB6
#define P1A_B7_YUV_RGB_B_GAIN_LSB          0x1AB7

#define P1A_C0_IFC_CYBER_THRE              0x1AC0
#define P1A_C1_IFC_CYBER_MAKEUP            0x1AC1
#define P1A_C2_IFC_CYBER_START             0x1AC2
#define P1A_C3_IFC_CYBER_DATA              0x1AC3
#define P1A_C4_IFC_CYBER_DYNAMIC           0x1AC4
#define P1A_C5_IFC_CYBER_RESULT0           0x1AC5
#define P1A_C6_IFC_CYBER_RESULT1           0x1AC6
#define P1A_C7_IFC_CYBER_RESULT2           0x1AC7
#define P1A_C8_IFC_CYBER_RESULT3           0x1AC8
#define P1A_C9_IFC_CYBER_RESULT4           0x1AC9
#define P1A_CA_IFC_CYBER_RESULT5           0x1ACA
#define P1A_CB_IFC_CYBER_RESULT6           0x1ACB
#define P1A_CC_IFC_CYBER_RESULT7           0x1ACC
#define P1A_CD_IFC_CYBER_RESULT8           0x1ACD
#define P1A_CE_IFC_CYBER_RESULT9           0x1ACE
#define P1A_CF_IFC_CYBER_RESULT10          0x1ACF
#define P1A_D0_IFC_CYBER_BACKGROUND0       0x1AD0
#define P1A_D1_IFC_CYBER_BACKGROUND1       0x1AD1
#define P1A_D2_IFC_CYBER_BACKGROUND2       0x1AD2
#define P1A_D3_IFC_CYBER_BACKGROUND3       0x1AD3
#define P1A_D4_IFC_CYBER_ANSWER0           0x1AD4
#define P1A_D5_IFC_CYBER_ANSWER1           0x1AD5
#define P1A_D6_IFC_CYBER_ANSWER2           0x1AD6
#define P1A_D7_IFC_CYBER_ANSWER3           0x1AD7
#define P1A_D8_IFC_CYBER_ANSWER4           0x1AD8
#define P1A_D9_IFC_CYBER_SETTING0          0x1AD9
#define P1A_DA_IFC_CYBER_SETTING           0x1ADA

#define P1A_DC_IFC_PID_WHITE               0x1ADC
#define P1A_DD_IFC_PID_BLACK               0x1ADD
#define P1A_DE_IFC_PID_SETTING0            0x1ADE
#define P1A_DF_IFC_PID_SETTING             0x1ADF

#define P1A_E0_REALD_MODE                  0x1AE0
#define P1A_E1_REAL_LINE_H                 0x1AE1
#define P1A_E2_REAL_LINE_L                 0x1AE2
#define P1A_E3_REAL_GROUP                  0x1AE3
#define P1A_E4_REAL_BLOCK0_PIXEL_NUM       0x1AE4
#define P1A_E5_REAL_BLOCK1_PIXEL_NUM       0x1AE5
#define P1A_E6_REAL_BLOCK2_PIXEL_NUM       0x1AE6
#define P1A_E7_REAL_LEFT_EXPECTED          0x1AE7
#define P1A_E8_REAL_RIGHT_EXPECTED         0x1AE8
#define P1A_E9_REAL_3D_PXL_THRESHOLD       0x1AE9
#define P1A_EA_REAL_3D_FRAME_THRESHOLD     0x1AEA
#define P1A_EB_REAL_3D_VALID_THRESHOLD     0x1AEB
#define P1A_EC_REAL_2D_PXL_THRESHOLD       0x1AEC
#define P1A_ED_REAL_2D_FRAME_THRESHOLD     0x1AED
#define P1A_EE_REAL_2D_VALID_THRESHOLD     0x1AEE
#define P1A_F0_REAL_VALID_COUNTER0         0x1AF0
#define P1A_F1_REAL_VALID_COUNTER1         0x1AF1
#define P1A_F2_WATCH_DOG                   0x1AF2
#define P1A_F3_OUTPUT_SELECT               0x1AF3
#define P1A_F4_REAL_RESERVED0              0x1AF4
#define P1A_F5_REAL_RESERVED1              0x1AF5

#define P1A_F6_DEBUG_V                     0x1AF6
#define P1A_F7_DEBUG_VH                    0x1AF7
#define P1A_F8_DEBUG_H0                    0x1AF8
#define P1A_F9_DEBUG_TEST                  0x1AF9
#define P1A_FA_DEBUG_READ00                0x1AFA
#define P1A_FB_DEBUG_READ01                0x1AFB
#define P1A_FC_DEBUG_READ02                0x1AFC
#define P1A_FD_DEBUG_READ10                0x1AFD
#define P1A_FE_DEBUG_READ11                0x1AFE
#define P1A_FF_DEBUG_READ12                0x1AFF

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 1B: Register4 ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------
// HDMI/DP 3D Format Detection (Page 1B)
//--------------------------------------------------
#define P1B_A0_HDMI_VIDEO_FORMAT           0x1BA0 // HDMI video format
#define P1B_A1_HDMI_VIC   				   0x1BA1 // HDMI VIC
#define P1B_A2_HDMI_3D_FORMAT0             0x1BA2 // HDMI 3D format0
#define P1B_A3_HDMI_3D_FORMAT1             0x1BA3 // HDMI 3D format1

#define P1B_D0_DP3D_INFO0				   0x1BD0 // DP 3D info 
#define P1B_D1_DP3D_INFO1				   0x1BD1 // DP 3D info
#define P1B_D2_DP3D_IRQ_FLAG0			   0x1BD2 // DP 3D IRQ flag0	 
#define P1B_D3_DP3D_IRQ_FLAG1			   0x1BD3 // DP 3D IRQ flag1
#define P1B_D4_DP3D_IRQ_FLAG2			   0x1BD4 // DP 3D IRQ flag2
#define P1B_D5_DP3D_IRQ_CTRL0			   0x1BD5 // DP 3D IRQ ctrl0	
#define P1B_D6_DP3D_IRQ_CTRL1			   0x1BD6 // DP 3D IRQ ctrl1
#define P1B_D7_DP3D_IRQ_CTRL2			   0x1BD7 // DP 3D IRQ ctrl2
#define P1B_D8_DP3D_VWD_CTRL0              0x1BD8 // DP 3D VWD ctrl0
#define P1B_D9_DP3D_VWD_CTRL1              0x1BD9 // DP 3D VWD ctrl1
#define P1B_DA_DP3D_VWD_CTRL2              0x1BDA // DP 3D VWD ctrl2
#define P1B_DB_DP_LR_SEL                   0x1BDB // DP LR select

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 1C: 2D to 3D /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P1C_A0_2D_TO_3D_CTL1               0x1CA0
#define P1C_A1_2D_TO_3D_CTL2               0x1CA1
#define P1C_A2_2D_TO_3D_CTL3               0x1CA2
#define P1C_A3_2D_TO_3D_CTL4               0x1CA3
#define P1C_A4_2D_TO_3D_CTL5               0x1CA4
#define P1C_A5_2D_TO_3D_CTL6               0x1CA5
#define P1C_A6_2D_TO_3D_CTL7               0x1CA6
#define P1C_A7_2D_TO_3D_CTL8               0x1CA7
#define P1C_A8_2D_TO_3D_CTL9               0x1CA8
#define P1C_A9_2D_TO_3D_CTL10              0x1CA9
#define P1C_AA_2D_TO_3D_CTL11              0x1CAA
#define P1C_AB_2D_TO_3D_CTL12              0x1CAB
#define P1C_AC_2D_TO_3D_CTL13              0x1CAC
#define P1C_AD_2D_TO_3D_CTL14              0x1CAD
#define P1C_AE_2D_TO_3D_CTL15              0x1CAE
#define P1C_AF_2D_TO_3D_CTL16              0x1CAF
#define P1C_B0_2D_TO_3D_CTL17              0x1CB0

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 1D: //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P1D_A0_L0_DFE_EN_1                 0x1DA0 //                     
#define P1D_A1_L0_DFE_EN_2                 0x1DA1 //                     
#define P1D_A2_L0_LIMIT_INIT               0x1DA2 //                     
#define P1D_A3_L0_INIT_1                   0x1DA3 //                     
#define P1D_A4_L0_INIT_2                   0x1DA4 //                     
#define P1D_A5_L0_INIT_3                   0x1DA5 //                     
#define P1D_A6_L0_INIT_4                   0x1DA6 //                     
#define P1D_A7_L0_INIT_5                   0x1DA7 //                     
#define P1D_A8_L0_INIT_6                   0x1DA8 //                     
#define P1D_A9_L0_INIT_7                   0x1DA9 //                     
#define P1D_AA_L0_INIT_8                   0x1DAA //                     
#define P1D_AB_L0_STABLE_FLAG              0x1DAB //                        
                                                          
#define P1D_B0_L1_DFE_EN_1                 0x1DB0 //          
#define P1D_B1_L1_DFE_EN_2             	   0x1DB1 //          
#define P1D_B2_L1_LIMIT_INIT               0x1DB2 //                  
#define P1D_B3_L1_INIT_1                   0x1DB3 //                  
#define P1D_B4_L1_INIT_2                   0x1DB4 //                  
#define P1D_B5_L1_INIT_3                   0x1DB5 //                  
#define P1D_B6_L1_INIT_4                   0x1DB6 //          
#define P1D_B7_L1_INIT_5                   0x1DB7 //                  
#define P1D_B8_L1_INIT_6                   0x1DB8 //                  
#define P1D_B9_L1_INIT_7                   0x1DB9 //                  
#define P1D_BA_L1_INIT_8                   0x1DBA //                       
#define P1D_BB_L1_STABLE_FLAG              0x1DBB //                                 
                                                     
#define P1D_C0_L2_DFE_EN_1                 0x1DC0 //                       
#define P1D_C1_L2_DFE_EN_2                 0x1DC1 //                       
#define P1D_C2_L2_LIMIT_INIT               0x1DC2 //                       
#define P1D_C3_L2_INIT_1                   0x1DC3 //                       
#define P1D_C4_L2_INIT_2                   0x1DC4 //                       
#define P1D_C5_L2_INIT_3                   0x1DC5 //                       
#define P1D_C6_L2_INIT_4                   0x1DC6 //                       
#define P1D_C7_L2_INIT_5                   0x1DC7 //                       
#define P1D_C8_L2_INIT_6                   0x1DC8 //                       
#define P1D_C9_L2_INIT_7                   0x1DC9 //                       
#define P1D_CA_L2_INIT_8                   0x1DCA //                       
#define P1D_CB_L2_STABLE_FLAG              0x1DCB //
                                                     
#define P1D_D0_L3_DFE_EN_1                 0x1DD0 //                       
#define P1D_D1_L3_DFE_EN_2                 0x1DD1 //                       
#define P1D_D2_L3_LIMIT_INIT               0x1DD2 //                       
#define P1D_D3_L3_INIT_1                   0x1DD3 //                       
#define P1D_D4_L3_INIT_2                   0x1DD4 //                       
#define P1D_D5_L3_INIT_3                   0x1DD5 //                       
#define P1D_D6_L3_INIT_4                   0x1DD6 //                       
#define P1D_D7_L3_INIT_5                   0x1DD7 //                       
#define P1D_D8_L3_INIT_6              	   0x1DD8 //                       
#define P1D_D9_L3_INIT_7                   0x1DD9 //                       
#define P1D_DA_L3_INIT_8                   0x1DDA //                       
#define P1D_DB_L3_STABLE_FLAG          	   0x1DDB //                        
                                                     
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
#define P1D_EA_LIMIT_5                     0x1DEA //                       
#define P1D_EB_LIMIT_6                     0x1DEB //                       
#define P1D_EC_LOOP_DIV_1                  0x1DEC //                       
#define P1D_ED_LOOP_DIV_2                  0x1DED //                       
#define P1D_EE_RESERVED                    0x1DEE //                       
#define P1D_EF_RESET_1               	   0x1DEF //                       
                                                     
#define P1D_F0_COEF_1                      0x1DF0 //                       
#define P1D_F1_COEF_2                      0x1DF1 //          

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 1E: //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P1E_A0_HIST_BON_WIDTH_H            0x1EA0
#define P1E_A1_HIST_BON_WIDTH_L            0x1EA1                       
#define P1E_A2_HIST_BON_HEIGHT_H           0x1EA2                 
#define P1E_A3_HIST_BON_HEIGHT_L           0x1EA3                           
#define P1E_A4_HIST_HOR_START_H            0x1EA4                       
#define P1E_A5_HIST_HOR_START_L            0x1EA5                                             
#define P1E_A6_HIST_VER_START_H            0x1EA6              
#define P1E_A7_HIST_VER_START_L            0x1EA7          
#define P1E_A8_DET_ROW_H                   0x1EA8   
#define P1E_A9_DET_ROW_L                   0x1EA9   
#define P1E_AA_DET_COLUMN_H                0x1EAA      
#define P1E_AB_DET_COLUMN_L                0x1EAB      
#define P1E_AC_START_HIST_FUNC             0x1EAC         
#define P1E_AD_FUNC1_CTRL1                 0x1EAD     
#define P1E_AE_FUNC1_CTRL2                 0x1EAE     
#define P1E_AF_FUNC1_CTRL3                 0x1EAF     
#define P1E_B0_FUNC1_CTRL4                 0x1EB0     
#define P1E_B1_FUNC1_RESULT1               0x1EB1       
#define P1E_B2_FUNC1_RESULT2               0x1EB2       
#define P1E_B3_MONO_REF_VALUE              0x1EB3                
#define P1E_B4_STEP_H                      0x1EB4      
#define P1E_B5_STEP_1                      0x1EB5      
#define P1E_B6_STEP_2                      0x1EB6      
#define P1E_B7_STEP_3                      0x1EB7        
#define P1E_B8_A_1_H                       0x1EB8       
#define P1E_B9_A_1_L                       0x1EB9       
#define P1E_BA_A_2_H                       0x1EBA       
#define P1E_BB_A_2_L                       0x1EBB       
#define P1E_BC_A_3_H                       0x1EBC       
#define P1E_BD_A_3_L                       0x1EBD       
#define P1E_BE_COUNTER_1                   0x1EBE           
#define P1E_BF_COUNTER_2                   0x1EBF           
#define P1E_C0_COUNTER_3                   0x1EC0           
#define P1E_C1_FUNC2_CTRL1                 0x1EC1             
#define P1E_C2_FUNC2_CTRL2                 0x1EC2             
#define P1E_C3_FUNC2_CTRL3                 0x1EC3             
#define P1E_C4_FUNC2_CTRL4                 0x1EC4             
#define P1E_C5_SHIFT_A_H                   0x1EC5           
#define P1E_C6_SHIFT_A_L                   0x1EC6           
#define P1E_C7_TONE1_NUM_H                 0x1EC7             
#define P1E_C8_TONE1_NUM_L                 0x1EC8             
#define P1E_C9_TONE2_NUM_H                 0x1EC9             
#define P1E_CA_TONE2_NUM_L                 0x1ECA             
#define P1E_CB_TONE3_NUM_H                 0x1ECB             
#define P1E_CC_TONE3_NUM_L                 0x1ECC             
#define P1E_CD_TONE4_NUM_H                 0x1ECD             
#define P1E_CE_TONE4_NUM_L                 0x1ECE             
#define P1E_CF_HIST_SCORE1                 0x1ECF             
#define P1E_D0_HIST_SCORE2                 0x1ED0             
#define P1E_D1_RSV_DUMMY_1ECD              0x1ED1       

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// Page 20: //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
#define P20_A0_3D_IVS_DB_CTRL              0X20A0
#define P20_A1_3D_DVS_DB_CTRL              0X20A1
#define P20_A2_3D_DDEA_DB_CTRL             0X20A2
#define P20_A3_3D_L_R_STATUS0              0X20A3
#define P20_A4_3D_L_R_STATUS1              0X20A4

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


#ifndef __RL6229_SERIES_REG__
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

#endif // End of #ifndef __RL6229_SERIES_REG__
