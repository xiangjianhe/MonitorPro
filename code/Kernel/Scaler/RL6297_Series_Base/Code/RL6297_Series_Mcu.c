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
// ID Code      : RL6297_Series_Mcu.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6297_SERIES_MCU__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions DDCRAM Address
//--------------------------------------------------
#define _DDCRAM_DDC1_MAX_ADDRESS                            0xFD80
#define _DDCRAM_DDC2_MAX_ADDRESS                            0xFE00
#define _DDCRAM_DDC3_MAX_ADDRESS                            0xFE80

#if(_D0_DDC_CHANNEL_SEL == _DDC3)
#define _EMBEDDED_DDCRAM_DDC3_ADDRESS                       (((0xFF00 - _EMBEDDED_DDCRAM_D0_SIZE) > _DDCRAM_DDC3_MAX_ADDRESS) ? (_DDCRAM_DDC3_MAX_ADDRESS) : (0xFF00 - _EMBEDDED_DDCRAM_D0_SIZE))
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
#define _EMBEDDED_DDCRAM_DDC3_ADDRESS                       (((0xFF00 - _EMBEDDED_DDCRAM_D1_SIZE) > _DDCRAM_DDC3_MAX_ADDRESS) ? (_DDCRAM_DDC3_MAX_ADDRESS) : (0xFF00 - _EMBEDDED_DDCRAM_D1_SIZE))
#else
#define _EMBEDDED_DDCRAM_DDC3_ADDRESS                       _DDCRAM_DDC3_MAX_ADDRESS 
#endif

#if(_D0_DDC_CHANNEL_SEL == _DDC2)
#define _EMBEDDED_DDCRAM_DDC2_ADDRESS                       (((_EMBEDDED_DDCRAM_DDC3_ADDRESS - _EMBEDDED_DDCRAM_D0_SIZE) > _DDCRAM_DDC2_MAX_ADDRESS) ? (_DDCRAM_DDC2_MAX_ADDRESS) : (_EMBEDDED_DDCRAM_DDC3_ADDRESS - _EMBEDDED_DDCRAM_D0_SIZE))
#elif(_D1_DDC_CHANNEL_SEL == _DDC2)
#define _EMBEDDED_DDCRAM_DDC2_ADDRESS                       (((_EMBEDDED_DDCRAM_DDC3_ADDRESS - _EMBEDDED_DDCRAM_D1_SIZE) > _DDCRAM_DDC2_MAX_ADDRESS) ? (_DDCRAM_DDC2_MAX_ADDRESS) : (_EMBEDDED_DDCRAM_DDC3_ADDRESS - _EMBEDDED_DDCRAM_D1_SIZE))
#else
#define _EMBEDDED_DDCRAM_DDC2_ADDRESS                       _DDCRAM_DDC2_MAX_ADDRESS 
#endif

#define _EMBEDDED_DDCRAM_DDC1_ADDRESS                       (((_EMBEDDED_DDCRAM_DDC2_ADDRESS - _EMBEDDED_DDCRAM_A0_SIZE) > _DDCRAM_DDC1_MAX_ADDRESS) ? (_DDCRAM_DDC1_MAX_ADDRESS) : (_EMBEDDED_DDCRAM_DDC2_ADDRESS - _EMBEDDED_DDCRAM_A0_SIZE))

//--------------------------------------------------
// Definitions DDCCI Protocol Items
//--------------------------------------------------
#define _DDCCI_BUFFER_SIZE                                  32

// If User Don't Want to Save Tx Buf Size, Reduce the Available DDCCI Buf Size
#if(_DDCCI_TXBUF_LENGTH < _DDCCI_BUFFER_SIZE)
#undef _DDCCI_BUFFER_SIZE
#define _DDCCI_BUFFER_SIZE                                  _DDCCI_TXBUF_LENGTH
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE)
BYTE xdata MCU_DDCRAM_A0[_EMBEDDED_DDCRAM_A0_SIZE]			_at_ _EMBEDDED_DDCRAM_DDC1_ADDRESS;
#endif

#if(_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE)

#if(_D0_DDC_CHANNEL_SEL == _DDC2)
BYTE xdata MCU_DDCRAM_D0[_EMBEDDED_DDCRAM_D0_SIZE]		    _at_ _EMBEDDED_DDCRAM_DDC2_ADDRESS;
#else
BYTE xdata MCU_DDCRAM_D0[_EMBEDDED_DDCRAM_D0_SIZE]		    _at_ _EMBEDDED_DDCRAM_DDC3_ADDRESS;
#endif // End of _DDC_CHANNEL_FOR_D0

#endif // End of #if(_EMBEDDED_DDCRAM_D0_SIZE != _EDID_SIZE_NONE)

#if(_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE)

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
BYTE xdata MCU_DDCRAM_D1[_EMBEDDED_DDCRAM_D1_SIZE]          _at_ _EMBEDDED_DDCRAM_DDC2_ADDRESS;
#else
BYTE xdata MCU_DDCRAM_D1[_EMBEDDED_DDCRAM_D1_SIZE]          _at_ _EMBEDDED_DDCRAM_DDC3_ADDRESS;
#endif // End of _DDC_CHANNEL_FOR_D1

#endif // End of #if(_EMBEDDED_DDCRAM_D1_SIZE != _EDID_SIZE_NONE)

////////////////////////0xFF00~0xFF0F////////////////////////
volatile BYTE xdata MCU_IRQ_STATUS_FF00          _at_ 0xFF00;
volatile BYTE xdata MCU_IRQ_PRIORITY_FF01        _at_ 0xFF01;
volatile BYTE xdata MCU_VGA_EDID_IRQ_FF02        _at_ 0xFF02;
volatile BYTE xdata MCU_TRIPLE_BYTES_OP_FF03     _at_ 0xFF03;
volatile BYTE xdata MCU_SHIFT_BITS_NUM_FF04      _at_ 0xFF04;
volatile BYTE xdata MCU_BYTE_ADDRESS_FF05        _at_ 0xFF05;
volatile BYTE xdata MCU_INPUT_TRIPLE_BYTES_FF06  _at_ 0xFF06;
volatile BYTE xdata MCU_RESULT_TRIPLE_BYTES_FF07 _at_ 0xFF07;
volatile BYTE xdata MCU_ADC_CTRL_FF08            _at_ 0xFF08;
volatile BYTE xdata MCU_ADC0_RESULT_FF09         _at_ 0xFF09;
volatile BYTE xdata MCU_ADC1_RESULT_FF0A         _at_ 0xFF0A;
volatile BYTE xdata MCU_ADC2_RESULT_FF0B         _at_ 0xFF0B;
volatile BYTE xdata MCU_ADC3_RESULT_FF0C         _at_ 0xFF0C;
volatile BYTE xdata MCU_ADC_CLK_DIV_FF0D         _at_ 0xFF0D;
volatile BYTE xdata MCU_AUTO_MODE_CTRL01_FF0E    _at_ 0xFF0E;
volatile BYTE xdata MCU_ADC0_THRESHOLD_H_FF0F    _at_ 0xFF0F;

////////////////////////0xFF10~0xFF1F////////////////////////
volatile BYTE xdata MCU_ADC0_THRESHOLD_L_FF10    _at_ 0xFF10;
volatile BYTE xdata MCU_ADC1_THRESHOLD_H_FF11    _at_ 0xFF11;
volatile BYTE xdata MCU_ADC1_THRESHOLD_L_FF12    _at_ 0xFF12;
volatile BYTE xdata MCU_ADC2_THRESHOLD_H_FF13    _at_ 0xFF13;
volatile BYTE xdata MCU_ADC2_THRESHOLD_L_FF14    _at_ 0xFF14;
volatile BYTE xdata MCU_ADC3_THRESHOLD_H_FF15    _at_ 0xFF15;
volatile BYTE xdata MCU_ADC3_THRESHOLD_L_FF16    _at_ 0xFF16;
volatile BYTE xdata MCU_CTRL0_WAIT_TIME_VAL_FF17 _at_ 0xFF17;
volatile BYTE xdata MCU_BYTE_ADDR_FF18           _at_ 0xFF18;
volatile BYTE xdata MCU_ADC_DDC_ENA_FF1B         _at_ 0xFF1B;
volatile BYTE xdata MCU_ADC_DDC_CTRL1_FF1C       _at_ 0xFF1C;
volatile BYTE xdata MCU_ADC_DDC_CTRL2_FF1D       _at_ 0xFF1D;
volatile BYTE xdata MCU_DVI_DDC_ENA_FF1E         _at_ 0xFF1E;
volatile BYTE xdata MCU_DVI_DDC_CTRL1_FF1F       _at_ 0xFF1F;

////////////////////////0xFF20~0xFF2F////////////////////////
volatile BYTE xdata MCU_DVI_DDC_CTRL2_FF20       _at_ 0xFF20;
volatile BYTE xdata MCU_DDCRAM_PART_FF21         _at_ 0xFF21;
volatile BYTE xdata MCU_VSYNC_SEL_FF22           _at_ 0xFF22;
volatile BYTE xdata MCU_I2C_SET_SLAVE_FF23       _at_ 0xFF23;
volatile BYTE xdata MCU_I2C_SUB_IN_FF24          _at_ 0xFF24;
volatile BYTE xdata MCU_I2C_DATA_IN_FF25         _at_ 0xFF25;
volatile BYTE xdata MCU_I2C_DATA_OUT_FF26        _at_ 0xFF26;
volatile BYTE xdata MCU_I2C_STATUS_FF27          _at_ 0xFF27;
volatile BYTE xdata MCU_I2C_IRQ_CTRL_FF28        _at_ 0xFF28;
volatile BYTE xdata MCU_I2C_STATUS2_FF29         _at_ 0xFF29;
volatile BYTE xdata MCU_I2C_IRQ_CTRL2_FF2A       _at_ 0xFF2A;
volatile BYTE xdata MCU_I2C_CHANNEL_CTRL_FF2B    _at_ 0xFF2B;
volatile BYTE xdata MCU_HDMI_DDC_ENA_FF2C        _at_ 0xFF2C;
volatile BYTE xdata MCU_HDMI_DDC_CTRL1_FF2D      _at_ 0xFF2D;
volatile BYTE xdata MCU_HDMI_DDC_CTRL2_FF2E      _at_ 0xFF2E;
volatile BYTE xdata MCU_ADC_DDC_INDEX_FF2F       _at_ 0xFF2F;

////////////////////////0xFF30~0xFF3F////////////////////////
volatile BYTE xdata MCU_ADC_DDC_ACCESS_FF30      _at_ 0xFF30;
volatile BYTE xdata MCU_DVI_DDC_INDEX_FF31       _at_ 0xFF31;
volatile BYTE xdata MCU_DVI_DDC_ACCESS_FF32      _at_ 0xFF32;
volatile BYTE xdata MCU_HDMI_DDC_INDEX_FF33      _at_ 0xFF33;
volatile BYTE xdata MCU_HDMI_DDC_ACCESS_FF34     _at_ 0xFF34;
volatile BYTE xdata MCU_DDCCI_REMAIN_FF35        _at_ 0xFF35;
volatile BYTE xdata MCU_PWM_CK_SEL_FF3A          _at_ 0xFF3A;
volatile BYTE xdata MCU_PWM03_M_FF3B             _at_ 0xFF3B;
volatile BYTE xdata MCU_PWM45_M_FF3C             _at_ 0xFF3C;
volatile BYTE xdata MCU_PWM01_N_MSB_FF3D         _at_ 0xFF3D;
volatile BYTE xdata MCU_PWM0_N_LSB_FF3E          _at_ 0xFF3E;
volatile BYTE xdata MCU_PWM1_N_LSB_FF3F          _at_ 0xFF3F;

////////////////////////0xFF40~0xFF4F////////////////////////
volatile BYTE xdata MCU_PWM23_N_MSB_FF40         _at_ 0xFF40;
volatile BYTE xdata MCU_PWM2_N_LSB_FF41          _at_ 0xFF41;
volatile BYTE xdata MCU_PWM3_N_LSB_FF42          _at_ 0xFF42;
volatile BYTE xdata MCU_PWM45_N_MSB_FF43         _at_ 0xFF43;
volatile BYTE xdata MCU_PWM4_N_LSB_FF44          _at_ 0xFF44;
volatile BYTE xdata MCU_PWM5_N_LSB_FF45          _at_ 0xFF45;
volatile BYTE xdata MCU_PWML_FF46                _at_ 0xFF46;
volatile BYTE xdata MCU_PWM_VS_CTRL_FF47         _at_ 0xFF47;
volatile BYTE xdata MCU_PWM_EN_FF48              _at_ 0xFF48;
volatile BYTE xdata MCU_PWM_CK_FF49              _at_ 0xFF49;
volatile BYTE xdata MCU_PWM0H_DUT_FF4A           _at_ 0xFF4A;
volatile BYTE xdata MCU_PWM1H_DUT_FF4B           _at_ 0xFF4B;
volatile BYTE xdata MCU_PWM01L_DUT_FF4C          _at_ 0xFF4C;
volatile BYTE xdata MCU_PWM2H_DUT_FF4D           _at_ 0xFF4D;
volatile BYTE xdata MCU_PWM3H_DUT_FF4E           _at_ 0xFF4E;
volatile BYTE xdata MCU_PWM23L_DUT_FF4F          _at_ 0xFF4F;

////////////////////////0xFF50~0xFF5F////////////////////////
volatile BYTE xdata MCU_PWM4H_DUT_FF50           _at_ 0xFF50;
volatile BYTE xdata MCU_PWM5H_DUT_FF51           _at_ 0xFF51;
volatile BYTE xdata MCU_PWM45L_DUT_FF52          _at_ 0xFF52;
volatile BYTE xdata MCU_PWM_DUT_TYPE_FF53        _at_ 0xFF53;
volatile BYTE xdata MCU_PWM_CNT_MODE_FF54        _at_ 0xFF54;
volatile BYTE xdata MCU_I2C_CR0_FF55             _at_ 0xFF55;
volatile BYTE xdata MCU_I2C_CR1_FF56             _at_ 0xFF56;
volatile BYTE xdata MCU_I2C_CR2_FF57             _at_ 0xFF57;
volatile BYTE xdata MCU_I2C_CR3_FF58             _at_ 0xFF58;
volatile BYTE xdata MCU_I2C_STR0_FF59            _at_ 0xFF59;
volatile BYTE xdata MCU_I2C_STR1_FF5A            _at_ 0xFF5A;
volatile BYTE xdata MCU_I2C_STR2_FF5B            _at_ 0xFF5B;
volatile BYTE xdata MCU_I2C_STR3_FF5C            _at_ 0xFF5C;
volatile BYTE xdata MCU_I2C_SR_FF5D              _at_ 0xFF5D;
volatile BYTE xdata MCU_I2C_TD_FF5E              _at_ 0xFF5E;
volatile BYTE xdata MCU_I2C_CCR_FF5F             _at_ 0xFF5F;

////////////////////////0xFF60~0xFF6F////////////////////////
volatile BYTE xdata MCU_COMM_INST_EN_FF60        _at_ 0xFF60;
volatile BYTE xdata MCU_COMM_OP_CODE_FF61        _at_ 0xFF61;
volatile BYTE xdata MCU_WREN_OP_CODE_FF62        _at_ 0xFF62;
volatile BYTE xdata MCU_FLASH_PROG_ISP0_FF64     _at_ 0xFF64;
volatile BYTE xdata MCU_FLASH_PROG_ISP1_FF65     _at_ 0xFF65;
volatile BYTE xdata MCU_FLASH_PROG_ISP2_FF66     _at_ 0xFF66;
volatile BYTE xdata MCU_COMM_INST_READ_P0_FF67   _at_ 0xFF67;
volatile BYTE xdata MCU_COMM_INST_READ_P1_FF68   _at_ 0xFF68;
volatile BYTE xdata MCU_COMM_INST_READ_P2_FF69   _at_ 0xFF69;
volatile BYTE xdata MCU_READ_OP_CODE_FF6A        _at_ 0xFF6A;
volatile BYTE xdata MCU_FAST_READ_OP_CODE_FF6B   _at_ 0xFF6B;
volatile BYTE xdata MCU_READ_INSTRUCTION_FF6C    _at_ 0xFF6C;
volatile BYTE xdata MCU_PROG_OP_CODE_FF6D        _at_ 0xFF6D;
volatile BYTE xdata MCU_READ_STATUS_OP_CODE_FF6E _at_ 0xFF6E;
volatile BYTE xdata MCU_PROG_INSTRUCTION_FF6F    _at_ 0xFF6F;

////////////////////////0xFF70~0xFF7F////////////////////////
volatile BYTE xdata MCU_CEN_CTRL_FF76            _at_ 0xFF76;
volatile BYTE xdata MCU_PORT_PD7_PIN_REG_FF77    _at_ 0xFF77;
volatile BYTE xdata MCU_PORT_PD6_PIN_REG_FF78    _at_ 0xFF78;
volatile BYTE xdata MCU_PORT_PD5_PIN_REG_FF79    _at_ 0xFF79;
volatile BYTE xdata MCU_PORT_PD4_PIN_REG_FF7A    _at_ 0xFF7A;
volatile BYTE xdata MCU_PORT_PD3_PIN_REG_FF7B    _at_ 0xFF7B;
volatile BYTE xdata MCU_PORT_PD2_PIN_REG_FF7C    _at_ 0xFF7C;
volatile BYTE xdata MCU_PORT_PD1_PIN_REG_FF7D    _at_ 0xFF7D;
volatile BYTE xdata MCU_PORT_PD0_PIN_REG_FF7E    _at_ 0xFF7E;
volatile BYTE xdata MCU_PORT_PB7_PIN_REG_FF7F    _at_ 0xFF7F;

////////////////////////0xFF80~0xFF8F////////////////////////
volatile BYTE xdata MCU_AAI_MODE_BYTE_NUM_FF80   _at_ 0xFF80;
volatile BYTE xdata MCU_I2CS_CTRL0_FF83          _at_ 0xFF83;
volatile BYTE xdata MCU_I2CS_CTRL1_FF84          _at_ 0xFF84;
volatile BYTE xdata MCU_I2CS_CTRL2_FF85          _at_ 0xFF85;
volatile BYTE xdata MCU_I2CS_STATUS0_FF86        _at_ 0xFF86;
volatile BYTE xdata MCU_I2CS_STATUS1_FF87        _at_ 0xFF87;
volatile BYTE xdata MCU_I2CS_BUFLEN_FF88         _at_ 0xFF88;
volatile BYTE xdata MCU_PORT_PB6_PIN_REG_FF89    _at_ 0xFF89;
volatile BYTE xdata MCU_PORT_PB5_PIN_REG_FF8A    _at_ 0xFF8A;
volatile BYTE xdata MCU_PORT_PB4_PIN_REG_FF8B    _at_ 0xFF8B;
volatile BYTE xdata MCU_PORT_PB3_PIN_REG_FF8C    _at_ 0xFF8C;
volatile BYTE xdata MCU_PORT_PB2_PIN_REG_FF8D    _at_ 0xFF8D;
volatile BYTE xdata MCU_PORT_PB1_PIN_REG_FF8E    _at_ 0xFF8E;
volatile BYTE xdata MCU_PORT_PB0_PIN_REG_FF8F    _at_ 0xFF8F;

////////////////////////0xFF90~0xFF9F////////////////////////
volatile BYTE xdata MCU_PWM01_TOTALCNT_MSB_FF90  _at_ 0xFF90;
volatile BYTE xdata MCU_PWM0_TOTALCNT_LSB_FF91   _at_ 0xFF91;
volatile BYTE xdata MCU_PWM1_TOTALCNT_LSB_FF92   _at_ 0xFF92;
volatile BYTE xdata MCU_PWM23_TOTALCNT_MSB_FF93  _at_ 0xFF93;
volatile BYTE xdata MCU_PWM2_TOTALCNT_LSB_FF94   _at_ 0xFF94;
volatile BYTE xdata MCU_PWM3_TOTALCNT_LSB_FF95   _at_ 0xFF95;
volatile BYTE xdata MCU_PWM45_TOTALCNT_MSB_FF96  _at_ 0xFF96;
volatile BYTE xdata MCU_PWM4_TOTALCNT_LSB_FF97   _at_ 0xFF97;
volatile BYTE xdata MCU_PWM5_TOTALCNT_LSB_FF98   _at_ 0xFF98;
volatile BYTE xdata MCU_PWM_CK_SEL_HS_FF99       _at_ 0xFF99;
volatile BYTE xdata MCU_PWM01_CYCLE_MAX_FF9A     _at_ 0xFF9A;
volatile BYTE xdata MCU_PWM23_CYCLE_MAX_FF9B     _at_ 0xFF9B;
volatile BYTE xdata MCU_PWM45_CYCLE_MAX_FF9C     _at_ 0xFF9C;
volatile BYTE xdata MCU_SPI_CAL_CTRL_FF9D        _at_ 0xFF9D;
volatile BYTE xdata MCU_SPI_CAL_RESULT_FF9E      _at_ 0xFF9E;
volatile BYTE xdata MCU_SPI_CAL_DATA_00_FF9F     _at_ 0xFF9F;

////////////////////////0xFFA0~0xFFAF////////////////////////
volatile BYTE xdata MCU_PORTC3_PIN_REG_FFA0      _at_ 0xFFA0;
volatile BYTE xdata MCU_PORTC2_PIN_REG_FFA1      _at_ 0xFFA1;
volatile BYTE xdata MCU_PORTC1_PIN_REG_FFA2      _at_ 0xFFA2;
volatile BYTE xdata MCU_PORTC0_PIN_REG_FFA3      _at_ 0xFFA3;
volatile BYTE xdata MCU_PORTC4_PIN_REG_FFA4      _at_ 0xFFA4;
volatile BYTE xdata MCU_SPI_CAL_DATA_01_FFA5     _at_ 0xFFA5;
volatile BYTE xdata MCU_SPI_CAL_DATA_02_FFA6     _at_ 0xFFA6;
volatile BYTE xdata MCU_SPI_CAL_ADR_H_FFA7       _at_ 0xFFA7;
volatile BYTE xdata MCU_SPI_CAL_ADR_M_FFA8       _at_ 0xFFA8;
volatile BYTE xdata MCU_SPI_CAL_ADR_L_FFA9       _at_ 0xFFA9;
volatile BYTE xdata MCU_CEC_CR0_FFAB             _at_ 0xFFAB;

////////////////////////0xFFC0~0xFFCF////////////////////////
volatile BYTE xdata MCU_PORT_READ_CTRL_FFC0      _at_ 0xFFC0;
volatile BYTE xdata MCU_PORT52_PIN_REG_FFC1      _at_ 0xFFC1;
volatile BYTE xdata MCU_PORT53_PIN_REG_FFC2      _at_ 0xFFC2;
volatile BYTE xdata MCU_PORT54_PIN_REG_FFC3      _at_ 0xFFC3;
volatile BYTE xdata MCU_PORT55_PIN_REG_FFC4      _at_ 0xFFC4;
volatile BYTE xdata MCU_PORT56_PIN_REG_FFC5      _at_ 0xFFC5;
volatile BYTE xdata MCU_PORT57_PIN_REG_FFC6      _at_ 0xFFC6;
volatile BYTE xdata MCU_PORT60_PIN_REG_FFC7      _at_ 0xFFC7;
volatile BYTE xdata MCU_PORT61_PIN_REG_FFC8      _at_ 0xFFC8;
volatile BYTE xdata MCU_PORT62_PIN_REG_FFC9      _at_ 0xFFC9;
volatile BYTE xdata MCU_PORT63_PIN_REG_FFCA      _at_ 0xFFCA;
volatile BYTE xdata MCU_PORT64_PIN_REG_FFCB      _at_ 0xFFCB;
volatile BYTE xdata MCU_PORT65_PIN_REG_FFCC      _at_ 0xFFCC;
volatile BYTE xdata MCU_PORT66_PIN_REG_FFCD      _at_ 0xFFCD;
volatile BYTE xdata MCU_PORT67_PIN_REG_FFCE      _at_ 0xFFCE;
volatile BYTE xdata MCU_PORT70_PIN_REG_FFCF      _at_ 0xFFCF;

////////////////////////0xFFD0~0xFFDF////////////////////////
volatile BYTE xdata MCU_PORT71_PIN_REG_FFD0      _at_ 0xFFD0;
volatile BYTE xdata MCU_PORT72_PIN_REG_FFD1      _at_ 0xFFD1;
volatile BYTE xdata MCU_PORT73_PIN_REG_FFD2      _at_ 0xFFD2;
volatile BYTE xdata MCU_PORT74_PIN_REG_FFD3      _at_ 0xFFD3;
volatile BYTE xdata MCU_PORT75_PIN_REG_FFD4      _at_ 0xFFD4;
volatile BYTE xdata MCU_PORT76_PIN_REG_FFD5      _at_ 0xFFD5;
volatile BYTE xdata MCU_PORT80_PIN_REG_FFD6      _at_ 0xFFD6;
volatile BYTE xdata MCU_PORT81_PIN_REG_FFD7      _at_ 0xFFD7;
volatile BYTE xdata MCU_PORT90_PIN_REG_FFD8      _at_ 0xFFD8;
volatile BYTE xdata MCU_PORT91_PIN_REG_FFD9      _at_ 0xFFD9;
volatile BYTE xdata MCU_PORT92_PIN_REG_FFDA      _at_ 0xFFDA;
volatile BYTE xdata MCU_PORT93_PIN_REG_FFDB      _at_ 0xFFDB;
volatile BYTE xdata MCU_PORT94_PIN_REG_FFDC      _at_ 0xFFDC;
volatile BYTE xdata MCU_PORTA0_PIN_REG_FFDD      _at_ 0xFFDD;
volatile BYTE xdata MCU_PORTA1_PIN_REG_FFDE      _at_ 0xFFDE;
volatile BYTE xdata MCU_PORTA2_PIN_REG_FFDF      _at_ 0xFFDF;

////////////////////////0xFFE0~0xFFEF////////////////////////
volatile BYTE xdata MCU_PORTA3_PIN_REG_FFE0      _at_ 0xFFE0;
volatile BYTE xdata MCU_PORTA4_PIN_REG_FFE1      _at_ 0xFFE1;
volatile BYTE xdata MCU_DVI_EDID_IRQ_FFE4        _at_ 0xFFE4;
volatile BYTE xdata MCU_HDMI_EDID_IRQ_FFE5       _at_ 0xFFE5;
volatile BYTE xdata MCU_PORTC_PIN_REG_FFE6       _at_ 0xFFE6;
volatile BYTE xdata MCU_VGA_EDID_IRQ_FFE7        _at_ 0xFFE7;
volatile BYTE xdata MCU_WATCHDOG_TIMER_FFEA      _at_ 0xFFEA;
volatile BYTE xdata MCU_CTRL_FFED                _at_ 0xFFED;
volatile BYTE xdata MCU_CLOCK_CTRL_FFEE          _at_ 0xFFEE;

////////////////////////0xFFF0~0xFFFF////////////////////////
volatile BYTE xdata MCU_XDATA_SPI_WR_PROT_FFF0   _at_ 0xFFF0;
volatile BYTE xdata MCU_I2C_PWM_CLK_STOP_FFF2    _at_ 0xFFF2;
volatile BYTE xdata MCU_SCA_INF_CTRL_FFF3        _at_ 0xFFF3;
volatile BYTE xdata MCU_SCA_INF_ADDR_FFF4        _at_ 0xFFF4;
volatile BYTE xdata MCU_SCA_INF_DATA_FFF5        _at_ 0xFFF5;
volatile BYTE xdata MCU_SCA_INF_BWR_ADRH_FFF6    _at_ 0xFFF6;
volatile BYTE xdata MCU_SCA_INF_BWR_ADRM_FFF7    _at_ 0xFFF7;
volatile BYTE xdata MCU_SCA_INF_BWR_ADRL_FFF8    _at_ 0xFFF8;
volatile BYTE xdata MCU_SCA_INF_BWR_COUNT_H_FFF9 _at_ 0xFFF9;
volatile BYTE xdata MCU_SCA_INF_BWR_COUNT_L_FFFA _at_ 0xFFFA;
volatile BYTE xdata MCU_SCA_INF_PERIOD_FFFB      _at_ 0xFFFB;
volatile BYTE xdata MCU_BANK_SWITCH_CTRL_FFFC    _at_ 0xFFFC;
volatile BYTE xdata MCU_BANK_START_FFFD          _at_ 0xFFFD;
volatile BYTE xdata MCU_BANK_SEL_FFFE            _at_ 0xFFFE;
volatile BYTE xdata MCU_BANK_SWITCH_FFFF         _at_ 0xFFFF;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerMcuGpioInitial(void);
void ScalerMcuIspInitial(void);
void ScalerMcuDdcInitial(void);
void ScalerMcuDdcRamEnable(void);
void ScalerMcuDdcReset(void);
BYTE ScalerMcuDdcciGetBufferSize(void);
void ScalerMcuPwmControl(EnumPowerStatus enumPowStatus);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : GPIO Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuGpioInitial(void)
{
    // Port_pin_reg_n signal is enabled (P1, P3 GPI->Bus Value)
    MCU_CTRL_FFED |= _BIT7; 
    
    // Source selection for P1, P3, P5, P6, P7, P8, P9, PA read back from bus value (P3 read by register)    
    MCU_PORT_READ_CTRL_FFC0 = 0xFF;

    // Source selection for PB, PC, PD read back from bus value
    MCU_PORTC_PIN_REG_FFE6 |= _BIT7 | _BIT6 | _BIT5;
}

//--------------------------------------------------
// Description  : ISP Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuIspInitial(void)
{
    // Keep mcu peripheral(timer) running while mcu stopped by spi flash access
    MCU_CLOCK_CTRL_FFEE |= _BIT6; 
}

//--------------------------------------------------
// Description  : DDC Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcInitial(void)
{
	// DDCRAM partition
    MCU_DDCRAM_PART_FF21 = (0x00 | (((DWORD)(_EMBEDDED_DDCRAM_DDC1_ADDRESS - 0xFC00) / 0x80) << 4)
                                 | (((DWORD)(_EMBEDDED_DDCRAM_DDC2_ADDRESS - 0xFC80) / 0x80) << 2)
                                 | (((DWORD)(_EMBEDDED_DDCRAM_DDC3_ADDRESS - 0xFD00) / 0x80) << 0));

    // Disable DDC Segment for DDC1
    MCU_ADC_DDC_CTRL2_FF1D &= ~_BIT2;

    // Disable DDC Segment for DDC2
    MCU_DVI_DDC_CTRL2_FF20 &= ~_BIT2;

    // Disable DDC Segment for DDC3
    MCU_HDMI_DDC_CTRL2_FF2E &= ~_BIT2;

    // Slave address 0xA0 for DDC1
    MCU_ADC_DDC_ENA_FF1B &= ~(_BIT7 | _BIT6 | _BIT5);
    
    // Slave address 0xA0 for DDC2
    MCU_DVI_DDC_ENA_FF1E &= ~(_BIT7 | _BIT6 | _BIT5);
    
    // Slave address 0xA0 for DDC3
    MCU_HDMI_DDC_ENA_FF2C &= ~(_BIT7 | _BIT6 | _BIT5); 

    // Force DDC to DDC2 Mode
    MCU_ADC_DDC_CTRL1_FF1C |= _BIT2;
    MCU_DVI_DDC_CTRL1_FF1F |= _BIT2;
    MCU_HDMI_DDC_CTRL1_FF2D |= _BIT2;

    // DDC1 set to Low Leak Mode
    ScalerSetBit(P10_AF_PIN_SHARE_CTRL0F, ~_BIT0, _BIT0);

    // DDC2 set to Low Leak Mode
    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~_BIT0, _BIT0);

    // DDC3 set to Low Leak Mode
    ScalerSetBit(P10_B2_PIN_SHARE_CTRL12, ~_BIT1, _BIT1);

    // DDC1 Debounce reference clock from Xtal
    MCU_ADC_DDC_CTRL1_FF1C &= ~_BIT3;

    // DDC2 Debounce reference clock from Xtal
    MCU_DVI_DDC_CTRL1_FF1F &= ~_BIT3;

    // DDC3 Debounce reference clock from Xtal
    MCU_HDMI_DDC_CTRL1_FF2D &= ~_BIT3;

    // DDC Debounce Settings
    ScalerMcuDdcDebounceSel(_EXT_XTAL_CLK);

    // DDC force Nack when not embedded EDID
#if(_EMBEDDED_DDCRAM_A0_SIZE == _EDID_SIZE_NONE)
   // DDC1 Force Nack
    MCU_VGA_EDID_IRQ_FFE7 |= _BIT5;
#endif

    //D0 DDC force Nack when not embedded EDID
#if(_EMBEDDED_DDCRAM_D0_SIZE == _EDID_SIZE_NONE)
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
    // DDC2 Force Nack
    MCU_DVI_EDID_IRQ_FFE4 |= _BIT5;
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
    // DDC3 Force Nack
    MCU_HDMI_EDID_IRQ_FFE5 |= _BIT5;
#endif
#endif // End of #if(_EMBEDDED_DDCRAM_D0_SIZE == _EDID_SIZE_NONE)
    
    //D1 DDC force Nack when not embedded EDID
#if(_EMBEDDED_DDCRAM_D1_SIZE == _EDID_SIZE_NONE)
#if(_D1_DDC_CHANNEL_SEL == _DDC2)
    // DDC2 Force Nack
    MCU_DVI_EDID_IRQ_FFE4 |= _BIT5;
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
    // DDC3 Force Nack
    MCU_HDMI_EDID_IRQ_FFE5 |= _BIT5;
#endif
#endif // End of #if(_EMBEDDED_DDCRAM_D1_SIZE == _EDID_SIZE_NONE)

    // DP always uses embedded EDID, so disable Force Nack
#if(_AUX_DDC_CHANNEL == _AUX_MAP_DDC2_PIN)
    // Disable DDC2 Force Nack
    MCU_DVI_EDID_IRQ_FFE4 &= ~_BIT5;   

    // Disable Segment Control for Link Layer CTS 1.1b
    MCU_DVI_DDC_CTRL2_FF20 &= ~_BIT2;  
#endif

#if(_AUX_DDC_CHANNEL == _AUX_MAP_DDC3_PIN)
    // Disable DDC3 Force Nack
    MCU_HDMI_EDID_IRQ_FFE5 &= ~_BIT5;    

    // Disable Segment Control for Link Layer CTS 1.1b
    MCU_HDMI_DDC_CTRL2_FF2E &= ~_BIT2;
#endif
}

//--------------------------------------------------
// Description  : Enable DDC Ram
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcRamEnable(void)
{
    // DDC1 Debounce Enable, ADC DDC channel enable
    MCU_ADC_DDC_ENA_FF1B |= (_BIT1 | _BIT0);

    // DDC2 Debounce Enable, DVI DDC channel enable
    MCU_DVI_DDC_ENA_FF1E |= (_BIT1 | _BIT0);

    // DDC3 Debounce Enable, HDMI DDC channel enable
    MCU_HDMI_DDC_ENA_FF2C |= (_BIT1 | _BIT0);
}

//--------------------------------------------------
// Description  : Reset DDC circuit
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcReset(void)
{
    // Reset DDC Channel
    MCU_ADC_DDC_CTRL1_FF1C |= _BIT1;
    MCU_DVI_DDC_CTRL1_FF1F |= _BIT1;
    MCU_HDMI_DDC_CTRL1_FF2D |= _BIT1;
}

//--------------------------------------------------
// Description  : Get DDC Buffer Size
// Input Value  : None
// Output Value : DDCCI Buffer Size
//--------------------------------------------------
BYTE ScalerMcuDdcciGetBufferSize(void)
{
    return _DDCCI_BUFFER_SIZE;
}

//--------------------------------------------------
// Description  : Low Power Consumption Setting For Mcu Module.
// Input Value  : enumPowAction
// Output Value : None
//--------------------------------------------------
void ScalerMcuPwmControl(EnumPowerStatus enumPowStatus)
{        
    if(enumPowStatus == _POWER_STATUS_NORMAL)
    {   
        // PWM output clock stop disable
        MCU_I2C_PWM_CLK_STOP_FFF2 |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_I2C_PWM_CLK_STOP_FFF2 &= ~(((BYTE)_PWM5_EN << 5) | ((BYTE)_PWM4_EN << 4) | ((BYTE)_PWM3_EN << 3) | ((BYTE)_PWM2_EN << 2) | ((BYTE)_PWM1_EN << 1) | ((BYTE)_PWM0_EN)); 

        // PWM Output Enable
        MCU_PWM_EN_FF48 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_PWM_EN_FF48 |= (((BYTE)_PWM5_EN << 5) | ((BYTE)_PWM4_EN << 4) | ((BYTE)_PWM3_EN << 3) | ((BYTE)_PWM2_EN << 2) | ((BYTE)_PWM1_EN << 1) | ((BYTE)_PWM0_EN));
    }
    else if(enumPowStatus == _POWER_STATUS_SAVING)
    {
        // PWM Output Enable
        MCU_PWM_EN_FF48 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_PWM_EN_FF48 |= (((BYTE)_PWM5_PSAV_EN << 5) | ((BYTE)_PWM4_PSAV_EN << 4) | ((BYTE)_PWM3_PSAV_EN << 3) | ((BYTE)_PWM2_PSAV_EN << 2) | ((BYTE)_PWM1_PSAV_EN << 1) | ((BYTE)_PWM0_PSAV_EN));

        // PWM output clock stop disable
        MCU_I2C_PWM_CLK_STOP_FFF2 |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_I2C_PWM_CLK_STOP_FFF2 &= ~(((BYTE)_PWM5_PSAV_EN << 5) | ((BYTE)_PWM4_PSAV_EN << 4) | ((BYTE)_PWM3_PSAV_EN << 3) | ((BYTE)_PWM2_PSAV_EN << 2) | ((BYTE)_PWM1_PSAV_EN << 1) | ((BYTE)_PWM0_PSAV_EN));  
    }
    else        
    {    
        // PWM Output Disable when Power Down
        MCU_PWM_EN_FF48 &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);

        // PWM Output Clock Stop Enable when Power Down
        MCU_I2C_PWM_CLK_STOP_FFF2 |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
    }
}


