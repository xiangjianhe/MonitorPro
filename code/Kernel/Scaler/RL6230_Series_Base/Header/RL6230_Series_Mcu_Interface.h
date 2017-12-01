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
// ID Code      : RL6230_Series_Mcu_Interface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

////////////////////////////////// MCU //////////////////////////////////////
////////////////////////0xFF00~0xFF0F////////////////////////
extern volatile BYTE xdata MCU_TRIPLE_BYTES_OP_FF03;
extern volatile BYTE xdata MCU_SHIFT_BITS_NUM_FF04;
extern volatile BYTE xdata MCU_BYTE_ADDRESS_FF05;
extern volatile BYTE xdata MCU_INPUT_TRIPLE_BYTES_FF06;
extern volatile BYTE xdata MCU_RESULT_TRIPLE_BYTES_FF07;
extern volatile BYTE xdata MCU_ADC0_RESULT_FF09;
extern volatile BYTE xdata MCU_ADC1_RESULT_FF0A;
extern volatile BYTE xdata MCU_ADC2_RESULT_FF0B;
extern volatile BYTE xdata MCU_ADC3_RESULT_FF0C;

////////////////////////0xFF20~0xFF2F////////////////////////
extern volatile BYTE xdata MCU_I2C_SET_SLAVE_FF23;
extern volatile BYTE xdata MCU_I2C_SUB_IN_FF24;
extern volatile BYTE xdata MCU_I2C_DATA_IN_FF25;
extern volatile BYTE xdata MCU_I2C_DATA_OUT_FF26;
extern volatile BYTE xdata MCU_I2C_STATUS_FF27;
extern volatile BYTE xdata MCU_I2C_IRQ_CTRL_FF28;
extern volatile BYTE xdata MCU_I2C_STATUS2_FF29;
extern volatile BYTE xdata MCU_I2C_IRQ_CTRL2_FF2A;
extern volatile BYTE xdata MCU_I2C_CHANNEL_CTRL_FF2B;

////////////////////////0xFF30~0xFF3F////////////////////////
extern volatile BYTE xdata MCU_PWM03_M_FF3B;
extern volatile BYTE xdata MCU_PWM45_M_FF3C;
extern volatile BYTE xdata MCU_PWM01_N_MSB_FF3D;
extern volatile BYTE xdata MCU_PWM0_N_LSB_FF3E;
extern volatile BYTE xdata MCU_PWM1_N_LSB_FF3F;

////////////////////////0xFF40~0xFF4F////////////////////////
extern volatile BYTE xdata MCU_PWM23_N_MSB_FF40;
extern volatile BYTE xdata MCU_PWM2_N_LSB_FF41;
extern volatile BYTE xdata MCU_PWM3_N_LSB_FF42;
extern volatile BYTE xdata MCU_PWM45_N_MSB_FF43;
extern volatile BYTE xdata MCU_PWM4_N_LSB_FF44;
extern volatile BYTE xdata MCU_PWM5_N_LSB_FF45;
extern volatile BYTE xdata MCU_PWML_FF46;
extern volatile BYTE xdata MCU_PWM_VS_CTRL_FF47;
extern volatile BYTE xdata MCU_PWM_EN_FF48;
extern volatile BYTE xdata MCU_PWM_CK_FF49;
extern volatile BYTE xdata MCU_PWM0H_DUT_FF4A;
extern volatile BYTE xdata MCU_PWM1H_DUT_FF4B;
extern volatile BYTE xdata MCU_PWM01L_DUT_FF4C;
extern volatile BYTE xdata MCU_PWM2H_DUT_FF4D;
extern volatile BYTE xdata MCU_PWM3H_DUT_FF4E;
extern volatile BYTE xdata MCU_PWM23L_DUT_FF4F;

////////////////////////0xFF50~0xFF5F////////////////////////
extern volatile BYTE xdata MCU_PWM4H_DUT_FF50;
extern volatile BYTE xdata MCU_PWM5H_DUT_FF51;
extern volatile BYTE xdata MCU_PWM45L_DUT_FF52;
extern volatile BYTE xdata MCU_PWM_DUT_TYPE_FF53;
extern volatile BYTE xdata MCU_PWM_CNT_MODE_FF54;

////////////////////////0xFF60~0xFF6F////////////////////////
extern volatile BYTE xdata MCU_COMM_INST_EN_FF60;
extern volatile BYTE xdata MCU_COMM_OP_CODE_FF61;
extern volatile BYTE xdata MCU_WREN_OP_CODE_FF62;
extern volatile BYTE xdata MCU_EWSR_OP_CODE_FF63;
extern volatile BYTE xdata MCU_FLASH_PROG_ISP0_FF64;
extern volatile BYTE xdata MCU_FLASH_PROG_ISP1_FF65;
extern volatile BYTE xdata MCU_FLASH_PROG_ISP2_FF66;
extern volatile BYTE xdata MCU_COMM_INST_READ_P0_FF67;
extern volatile BYTE xdata MCU_COMM_INST_READ_P1_FF68;
extern volatile BYTE xdata MCU_COMM_INST_READ_P2_FF69;
extern volatile BYTE xdata MCU_READ_OP_CODE_FF6A;
extern volatile BYTE xdata MCU_FAST_READ_OP_CODE_FF6B;
extern volatile BYTE xdata MCU_READ_INSTRUCTION_FF6C;
extern volatile BYTE xdata MCU_PROG_OP_CODE_FF6D;
extern volatile BYTE xdata MCU_READ_STATUS_OP_CODE_FF6E;
extern volatile BYTE xdata MCU_PROG_INSTRUCTION_FF6F;

////////////////////////0xFF70~0xFF7F////////////////////////
extern volatile BYTE xdata MCU_CEN_CTRL_FF76;
extern volatile BYTE xdata MCU_PORT_PD7_PIN_REG_FF77;
extern volatile BYTE xdata MCU_PORT_PD6_PIN_REG_FF78;
extern volatile BYTE xdata MCU_PORT_PD5_PIN_REG_FF79;
extern volatile BYTE xdata MCU_PORT_PD4_PIN_REG_FF7A;
extern volatile BYTE xdata MCU_PORT_PD3_PIN_REG_FF7B;
extern volatile BYTE xdata MCU_PORT_PD2_PIN_REG_FF7C;
extern volatile BYTE xdata MCU_PORT_PD1_PIN_REG_FF7D;
extern volatile BYTE xdata MCU_PORT_PD0_PIN_REG_FF7E;
extern volatile BYTE xdata MCU_PORT_PB7_PIN_REG_FF7F;

////////////////////////0xFF80~0xFF8F////////////////////////
extern volatile BYTE xdata MCU_AAI_MODE_BYTE_NUM_FF80;
extern volatile BYTE xdata MCU_PORT_PB6_PIN_REG_FF89;
extern volatile BYTE xdata MCU_PORT_PB5_PIN_REG_FF8A;
extern volatile BYTE xdata MCU_PORT_PB4_PIN_REG_FF8B;
extern volatile BYTE xdata MCU_PORT_PB3_PIN_REG_FF8C;
extern volatile BYTE xdata MCU_PORT_PB2_PIN_REG_FF8D;
extern volatile BYTE xdata MCU_PORT_PB1_PIN_REG_FF8E;
extern volatile BYTE xdata MCU_PORT_PB0_PIN_REG_FF8F;

////////////////////////0xFF90~0xFF9F////////////////////////
extern volatile BYTE xdata MCU_PWM01_TOTALCNT_MSB_FF90;
extern volatile BYTE xdata MCU_PWM0_TOTALCNT_LSB_FF91;
extern volatile BYTE xdata MCU_PWM1_TOTALCNT_LSB_FF92;
extern volatile BYTE xdata MCU_PWM23_TOTALCNT_MSB_FF93;
extern volatile BYTE xdata MCU_PWM2_TOTALCNT_LSB_FF94;
extern volatile BYTE xdata MCU_PWM3_TOTALCNT_LSB_FF95;
extern volatile BYTE xdata MCU_PWM45_TOTALCNT_MSB_FF96;
extern volatile BYTE xdata MCU_PWM4_TOTALCNT_LSB_FF97;
extern volatile BYTE xdata MCU_PWM5_TOTALCNT_LSB_FF98;
extern volatile BYTE xdata MCU_PWM_CK_SEL_HS_FF99;
extern volatile BYTE xdata MCU_PWM01_CYCLE_MAX_FF9A;
extern volatile BYTE xdata MCU_PWM23_CYCLE_MAX_FF9B;
extern volatile BYTE xdata MCU_PWM45_CYCLE_MAX_FF9C;
extern volatile BYTE xdata MCU_SPI_CAL_CTRL_FF9D;
extern volatile BYTE xdata MCU_SPI_CAL_RESULT_FF9E;
extern volatile BYTE xdata MCU_SPI_CAL_DATA_00_FF9F;

////////////////////////0xFFA0~0xFFAF////////////////////////
extern volatile BYTE xdata MCU_PORTC3_PIN_REG_FFA0;
extern volatile BYTE xdata MCU_PORTC2_PIN_REG_FFA1;
extern volatile BYTE xdata MCU_PORTC1_PIN_REG_FFA2;
extern volatile BYTE xdata MCU_PORTC0_PIN_REG_FFA3;
extern volatile BYTE xdata MCU_PORTC4_PIN_REG_FFA4;
extern volatile BYTE xdata MCU_SPI_CAL_DATA_01_FFA5;
extern volatile BYTE xdata MCU_SPI_CAL_DATA_02_FFA6;
extern volatile BYTE xdata MCU_SPI_CAL_ADR_H_FFA7;
extern volatile BYTE xdata MCU_SPI_CAL_ADR_M_FFA8;
extern volatile BYTE xdata MCU_SPI_CAL_ADR_L_FFA9;
extern volatile BYTE xdata MCU_CEC_CR0_FFAB;

////////////////////////0xFFC0~0xFFCF////////////////////////
extern volatile BYTE xdata MCU_PORT52_PIN_REG_FFC1;
extern volatile BYTE xdata MCU_PORT53_PIN_REG_FFC2;
extern volatile BYTE xdata MCU_PORT54_PIN_REG_FFC3;
extern volatile BYTE xdata MCU_PORT55_PIN_REG_FFC4;
extern volatile BYTE xdata MCU_PORT50_PIN_REG_FFC5;
extern volatile BYTE xdata MCU_PORT51_PIN_REG_FFC6;
extern volatile BYTE xdata MCU_PORT60_PIN_REG_FFC7;
extern volatile BYTE xdata MCU_PORT61_PIN_REG_FFC8;
extern volatile BYTE xdata MCU_PORT62_PIN_REG_FFC9;
extern volatile BYTE xdata MCU_PORT63_PIN_REG_FFCA;

////////////////////////0xFFD0~0xFFDF////////////////////////
extern volatile BYTE xdata MCU_PORT80_PIN_REG_FFD6;
extern volatile BYTE xdata MCU_PORT81_PIN_REG_FFD7;
extern volatile BYTE xdata MCU_PORT82_PIN_REG_FFD8;
extern volatile BYTE xdata MCU_PORT83_PIN_REG_FFD9;
extern volatile BYTE xdata MCU_PORT84_PIN_REG_FFDA;
extern volatile BYTE xdata MCU_PORT85_PIN_REG_FFDB;
extern volatile BYTE xdata MCU_PORT86_PIN_REG_FFDC;
extern volatile BYTE xdata MCU_PORT87_PIN_REG_FFDD;

////////////////////////0xFFE0~0xFFEF////////////////////////
extern volatile BYTE xdata MCU_VGA_EDID_IRQ_FFE7;
extern volatile BYTE xdata MCU_WATCHDOG_TIMER_FFEA;
extern volatile BYTE xdata MCU_CTRL_FFED;
extern volatile BYTE xdata MCU_CLOCK_CTRL_FFEE;

////////////////////////0xFFF0~0xFFFF////////////////////////
extern volatile BYTE xdata MCU_XDATA_SPI_WR_PROT_FFF0;
extern volatile BYTE xdata MCU_PWM_I2C_CLOCK_STOP_FFF1;
extern volatile BYTE xdata MCU_SCA_INF_CTRL_FFF3;
extern volatile BYTE xdata MCU_SCA_INF_BWR_ADRH_FFF6;
extern volatile BYTE xdata MCU_SCA_INF_BWR_ADRM_FFF7;
extern volatile BYTE xdata MCU_SCA_INF_BWR_ADRL_FFF8;
extern volatile BYTE xdata MCU_SCA_INF_BWR_COUNT_H_FFF9;
extern volatile BYTE xdata MCU_SCA_INF_BWR_COUNT_L_FFFA;
extern volatile BYTE xdata MCU_BANK_SWITCH_CTRL_FFFC;
extern volatile BYTE xdata MCU_BANK_START_FFFD;
extern volatile BYTE xdata MCU_BANK_SEL_FFFE;
extern volatile BYTE xdata MCU_BANK_SWITCH_FFFF;

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerMcuDdcRamEnable(void);
extern BYTE ScalerMcuDdcciGetBufferSize(void);
extern void ScalerMcuPwmControl(EnumPowerStatus enumPowStatus);
