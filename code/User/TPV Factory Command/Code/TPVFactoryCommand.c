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
// ID Code      : TPVFactoryCommand.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define __FACTORY_COMMAND__

#include "UserCommonInclude.h"

#if (_FACTORY_MODE_OWNER == _OWNER_TPV)


#if((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
BYTE code tEDID_TABLE_A0[] =
{
#if(_PROJECT == _RL6297_AOC2011_E2460SHE_M240HTN01_2)
	0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x05,0xE3,0x60,0x24,0x00,0x00,0x00,0x00,
	0x00,0x16,0x01,0x03,0x68,0x35,0x1E,0x78,0x2A,0xA2,0x65,0xA6,0x55,0x55,0x9F,0x28,
	0x0D,0x50,0x54,0xBF,0xEF,0x00,0xD1,0xC0,0xB3,0x00,0x95,0x00,0x81,0x80,0x81,0x40,
	0x81,0xC0,0x01,0x01,0x01,0x01,0x02,0x3A,0x80,0x18,0x71,0x38,0x2D,0x40,0x58,0x2C,
	0x45,0x00,0x13,0x2B,0x21,0x00,0x00,0x1E,0x00,0x00,0x00,0xFD,0x00,0x32,0x4C,0x1E,
	0x53,0x11,0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFC,0x00,0x32,
	0x34,0x36,0x30,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFF,
	0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x74,
#else
#warning "tEDID_TABLE have to define" 
#endif
};
#endif

#if((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
BYTE code tEDID_TABLE_D0[] =
{
#if(_PROJECT == _RL6297_AOC2011_E2460SHE_M240HTN01_2)
    0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x05,0xE3,0x60,0x24,0x00,0x00,0x00,0x00,
    0x00,0x16,0x01,0x03,0x80,0x35,0x1E,0x78,0x2A,0xA2,0x65,0xA6,0x55,0x55,0x9F,0x28,
    0x0D,0x50,0x54,0xBF,0xEF,0x00,0xD1,0xC0,0xB3,0x00,0x95,0x00,0x81,0x80,0x81,0x40,
    0x81,0xC0,0x01,0x01,0x01,0x01,0x02,0x3A,0x80,0x18,0x71,0x38,0x2D,0x40,0x58,0x2C,
    0x45,0x00,0x13,0x2B,0x21,0x00,0x00,0x1E,0x00,0x00,0x00,0xFD,0x00,0x32,0x4C,0x1E,
    0x53,0x11,0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFC,0x00,0x32,
    0x34,0x36,0x30,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFF,
    0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x01,0x5B,
    0x02,0x03,0x1E,0xF1,0x4B,0x05,0x14,0x10,0x1F,0x04,0x13,0x03,0x12,0x02,0x11,0x01,
    0x23,0x09,0x07,0x01,0x83,0x01,0x00,0x00,0x65,0x03,0x0C,0x00,0x10,0x00,0x8C,0x0A,
    0xD0,0x8A,0x20,0xE0,0x2D,0x10,0x10,0x3E,0x96,0x00,0x13,0x2B,0x21,0x00,0x00,0x18,
    0x01,0x1D,0x00,0x72,0x51,0xD0,0x1E,0x20,0x6E,0x28,0x55,0x00,0x13,0x2B,0x21,0x00,
    0x00,0x1E,0x8C,0x0A,0xD0,0x8A,0x20,0xE0,0x2D,0x10,0x10,0x3E,0x96,0x00,0x13,0x2B,
    0x21,0x00,0x00,0x18,0x8C,0x0A,0xD0,0x90,0x20,0x40,0x31,0x20,0x0C,0x40,0x55,0x00,
    0x13,0x2B,0x21,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,
#else
#warning "tEDID_TABLE have to define" 
#endif
};
#endif

#if((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
BYTE code tEDID_TABLE_D1[] =
{
#if(_PROJECT == _RL6297_AOC2011_E2460SHE_M240HTN01_2)
    0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x05,0xE3,0x60,0x24,0x00,0x00,0x00,0x00,
    0x00,0x16,0x01,0x03,0x80,0x35,0x1E,0x78,0x2A,0xA2,0x65,0xA6,0x55,0x55,0x9F,0x28,
    0x0D,0x50,0x54,0xBF,0xEF,0x00,0xD1,0xC0,0xB3,0x00,0x95,0x00,0x81,0x80,0x81,0x40,
    0x81,0xC0,0x01,0x01,0x01,0x01,0x02,0x3A,0x80,0x18,0x71,0x38,0x2D,0x40,0x58,0x2C,
    0x45,0x00,0x13,0x2B,0x21,0x00,0x00,0x1E,0x00,0x00,0x00,0xFD,0x00,0x32,0x4C,0x1E,
    0x53,0x11,0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFC,0x00,0x32,
    0x34,0x36,0x30,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0xFF,
    0x00,0x0A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x5C,
#else
#warning "tEDID_TABLE have to define" 
#endif
};
#endif

//--------------------------------------------------
// Definitions of Panel VCOM Function
//--------------------------------------------------
#define _PANEL_VCOM_I2C_ADDRESS                 0x50



//-----------------------------------------------------
//DFM MODE
//-----------------------------------------------------
#define _PRODUCT_ON                             0x55aa
#define _PRODUCT_OFF                            0xaa55
//-----------------------------------------------------
#define _DDC_SOURCE								0
#define _DDC_LENGTH								1
#define _FC_BYTE2								2
#define _FC_BYTE3                              	3
#define _FC_BYTE4								4
#define _FC_BYTE5								5
#define _FC_BYTE6								6
#define _FC_BYTE7								7
#define _FC_BYTE8								8
//===========================================
// Definitions of Factory Command
//===========================================
#define CMD_FC_TPVFactory						0xFE
//===========AOC  Factory Command===============
#define VCP_FC_ADJUST_R_GAIN					0x16	
//===========================================
#define VCP_FC_ADJUST_G_GAIN					0x18
//===========================================
#define VCP_FC_ADJUST_B_GAIN					0x1a
//===========================================
#define VCP_FC_ADJUST_CONTRAST      			0x12
//===========================================
#define VCP_FC_ADJUST_BL_BRIGHTNESS	    		0x10
//===========================================
#define VCP_FC_SAVE_COLORTEMP                   0x14

#define VCP_FC_RANGE_GAIN                       0x16

//-----Sub Item of VCP_FC_SAVE_COLORTEMP (_FC_BYTE5)
#if (_TPV_FACTORY_SELECT == _TPV_WH_FACTORY)
#define SUB_VCP_FC_SAVE_COLORTEMP_All   		0x81
#else
#define SUB_VCP_FC_SAVE_COLORTEMP_All           0x00
#endif
#define SUB_VCP_FC_SAVE_COLORTEMP_sRGB  		0x01
#define SUB_VCP_FC_SAVE_COLORTEMP_Native    	0x02
#define SUB_VCP_FC_SAVE_COLORTEMP_4000  		0x03
#define SUB_VCP_FC_SAVE_COLORTEMP_5000  		0x04
#define SUB_VCP_FC_SAVE_COLORTEMP_6500  		0x05
#define SUB_VCP_FC_SAVE_COLORTEMP_7200  		0x06
#define SUB_VCP_FC_SAVE_COLORTEMP_8200  		0x07
#define SUB_VCP_FC_SAVE_COLORTEMP_9300  		0x08
#define SUB_VCP_FC_SAVE_COLORTEMP_10000 		0x09
#define SUB_VCP_FC_SAVE_COLORTEMP_11500 		0x0a
#define SUB_VCP_FC_SAVE_COLORTEMP_User  		0x0b
#define SUB_VCP_FC_SAVE__ECO_TEXT_MODE               0x10//DELL only

//===========================================   _FC_BYTE4
#define VCP_FC_AUTO_ADJUST						0x1E
//===========================================
#define VCP_FC_AUTO_LEVEL						0x1F
//===========================================
#define VCP_FC_RESET                            0x04
//-----------------------------------------------------
#define VCP_FC_SET_LANGUAGE                     0xCC
//===========================================
#define VCP_FC_SET_SOURCE                       0x60
//===========================================
#define VCP_FC_ENTER_POWERSAVING				0xD6  
//===========================================
#define VCP_FC_DC_FUNC                     		0xDC//DFM rev05 patch note 1
//===========================================
#define VCP_FC_Code01                           0xe1

//-----------------------------------------------------(_FC_BYTE5)
#define SUB_VCP_FC_FACTORY_MODE_A0      		0xa0
#define SUB1_VCP_FC_ENTER_FACTORY_MODE          0x01
#define SUB1_VCP_FC_EXIT_FACTORY_MODE        	0x00
//DFM rev05 patch note 5>>
//-----------------------------------------------------
#define SUB_VCP_FC_NVRAW_RESTORE_A1      		0xa1
#define SUB1_VCP_FC_NVRAW_RESTORE_A1_ON         0x00
//DFM rev05 patch note 5>>
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A2      		0xa2
#define SUB1_VCP_FC_SET_BURNIN_OFF              0x00
#define SUB1_VCP_FC_SET_BURNIN_ON               0x01
#define SUB1_VCP_FC_SET_WR_START				0x01
#define SUB1_VCP_FC_SET_WR_END		    		0x00
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A3      		0xa3
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A4      		0xa4//for WH MANUFACTORY only
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A5      		0xa5
#define SUB1_VCP_FC_ENTER_DFM                   0x01
#define SUB1_VCP_FC_EXIT_DFM                    0x00
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A6      		0xa6
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A7      		0xa7
#define VCP_FC_FACTORY_LOGO_OFF       			0x06//DFM rev04 patch note 2
#define VCP_FC_FACTORY_LOGO_OFF_ENABLE        	0x00//DFM rev04 patch note 2
#define VCP_FC_FACTORY_LOGO_OFF_DISABLE         0x01//DFM rev04 patch note 2
#define VCP_FC_FACTORY_DCR_MODE       			0x03  // DCR Mode
#define VCP_FC_FACTORY_DCR_OFF         			0x00  
#define VCP_FC_FACTORY_DCR_ON          			0x01  
//-----------------------------------------------------
#define SUB_VCP_FC_FACTORY_MODE_A9				0xa9
//-----------------------------------------------------
#define SUB_VCP_FC_SET_HDCP_WRITE_START         0xe0
//-----------------------------------------------------
#define SUB_VCP_FC_READ_HDCP_CRC				0xe2

#define SUB_VCP_FC_READ_DEVICE_ID				0xe6
//===========================================
#define VCP_FC_Code02                           0xe2
#define SUB_VCP_FC_ADJUST_ADC_R_GAIN        	0x01
#define SUB_VCP_FC_ADJUST_ADC_G_GAIN        	0x02
#define SUB_VCP_FC_ADJUST_ADC_B_GAIN        	0x03
#define SUB_VCP_FC_ADJUST_ADC_R_OFFSET  		0x04
#define SUB_VCP_FC_ADJUST_ADC_G_OFFSET  		0x05
#define SUB_VCP_FC_ADJUST_ADC_B_OFFSET  		0x06
#define SUB_VCP_FC_COLORTMP_GAIN_MAX			0x02

//===========================================
#define VCP_FC_Code09							0xe9

//===========================================
#define VCP_FC_Code02                           0xe2
#define SUB_VCP_FC_ADJUST_ADC_R_GAIN        	0x01
#define SUB_VCP_FC_ADJUST_ADC_G_GAIN        	0x02
#define SUB_VCP_FC_ADJUST_ADC_B_GAIN        	0x03
#define SUB_VCP_FC_ADJUST_ADC_R_OFFSET  		0x04
#define SUB_VCP_FC_ADJUST_ADC_G_OFFSET  		0x05
#define SUB_VCP_FC_ADJUST_ADC_B_OFFSET  		0x06
//===========================================
#define VCP_FC_Code0A							0xea
//===========================================
#define VCP_FC_Code0F                   		0xef
#define SUB_VCP_FC_VGA1_EDID         			0x00
#define SUB_VCP_FC_DVI1_EDID         			0x01
#define SUB_VCP_FC_HDMI1_EDID        			0x02
#define SUB_VCP_FC_DP1_EDID          			0x03
#define SUB_VCP_FC_VGA2_EDID         			0x04
#define SUB_VCP_FC_DVI2_EDID         			0x05
#define SUB_VCP_FC_HDMI2_EDID        			0x06
#define SUB_VCP_FC_DP2_EDID          			0x07
#define SUB_VCP_FC_HDMI3_EDID        			0x08//DFM rev05 patch note 3
#define SUB_VCP_FC_HDMI4_EDID        			0x09//DFM rev05 patch note 3
#define SUB_VCP_FC_MHL1_EDID        			0x0A//DFM rev05 patch note 3
#define SUB_VCP_FC_MHL2_EDID        			0x0B//DFM rev05 patch note 3
#define SUB_VCP_FC_EEPROM           			0x10
#define SUB_VCP_FC_HDCP1            			0x11
#define SUB_VCP_FC_HDCP2            			0x12
#define SUB_VCP_FC_OSDSN            			0x13
#define SUB_VCP_FC_OSDMODELNAME     			0x14
//===========================================
//===========================================

#define _AWB_COMMAND_LEN_CRC            		4
#define _REPLY_RESULT_00                		0x00
#define _REPLY_RESULT_02                		0x02//PASS
#define _REPLY_RESULT_04                		0x04//Fail

//-----------------------------------------------------
//Sigle Port Write
//-----------------------------------------------------
//##Notice##
//You have to modify following macro in PCB file
//#define PCB_SW_IIC_SDA_SET()
//#define PCB_SW_IIC_SDA_CLR()
//#define PCB_SW_IIC_SDA_CHK(x)
//#define PCB_SW_IIC_SCL_SET()
//#define PCB_SW_IIC_SCL_CLR()
//#define PCB_SW_IIC_SCL_CHK(x)

#define _I2C_LINE_NVRAM							_IIC_SYS_EEPROM
#define _I2C_LINE_DDC1							_IIC_FOR_DDC1
#define _I2C_LINE_DDC2							_IIC_FOR_DDC2
#define _I2C_LINE_DDC3							_IIC_FOR_DDC3
#define _I2C_LINE_PANEL							_IIC_FOR_MISC


//-----------------------------------------------------
//HDCP Key Writeing Size one Times
//-----------------------------------------------------
#define _HDCP_BLOCK_SIZE                		20

//--------------------------------------------------
// Local Variables
//--------------------------------------------------
// 20111109 by jerry,  for TPV factory data
code StructFactoryType g_stFactoryDataDefault= 
{
    _ON,					// b1BurnIn : 1;
	_FORCE_LOGO_OFF,   		// b1LogoOff :1;//DFM rev04 patch note 2
	_OFF,					// b1FactoryMode :1;
	_OFF,					// b1EnergyLogo :1;
	_FAIL,                  // b1InternalAutoColor :1; //DFM rev05 patch note 2  
#if(_AUTO_POWER_DOWN == _ON)
	_AUTO_POWER_DOWN_DEF,	//b1FactoryAutoPowerDown
#endif
#if((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
	_FALSE,					//BYTE b1VGAEdidCheck :1;
	_FALSE,					//BYTE b1DVIEdidCheck :1;
	_FALSE,					//BYTE b1HDMIEdidCheck :1;
#endif
    100,					// ucsRGBBacklight;
    64,						// ucVcomValue
	_PRODUCT_ON,			// usDFMProductMode;
	_ENGLISH,				// ucLanguage

	0xFF,					//ucDummy1
	0xFF,					//ucDummy2
};

StructFactoryType g_stFactoryData;
bit bProductModeFlag=_OFF;
bit bTpvDfmLedNotice=_LOW;
bit bAocFactoryHdcpWriteStart = _FALSE;
BYTE xdata ucFCI2cLine = _I2C_LINE_NVRAM;
#if ((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
bit bEDID2EEPROM_VGA_Fail=_FALSE;
bit bEDID2EEPROM_DVI_Fail=_FALSE;
bit bEDID2EEPROM_HDMI_Fail=_FALSE;
bit bEDID2EEPROM_OVERWRITE=_FALSE;
#endif
//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void TPVNVRamSaveFactoryDate(void);
void TPVNVRamLoadFactoryDate(void);
void TPVNVRamRestoreFactoryDate(void);

//===factory command====
void TPVFCAdjustGain(BYTE ucGain,BYTE ucValue);

void TPVFCmdGetText(BYTE StringItem);
void TPVFCmdGetValue(BYTE ucTypeOpcode, WORD usPresent1, WORD usPresent2);

void TPVFCSetSaveColorTemp(void);
void TPVFCReplyEDIDPortData(void);
void TPVFCReplyCommand(BYTE ucResult, BYTE ucLength);
void TPVFCSetLanguage(void);
void TPVFCHdcpStart(void);
void TPVFCHdcpWriteData(void);
void TPVFCHdcpCrcCheck(void);
WORD TPVFCCrc16(BYTE nData, WORD nCRC);
void TPVFCReplyEDIDStatus(void);
void TPVFCForcePowerSaving(void);
void TPVFCEnterDFM(void);
void TPVFCExitDFM(void);  
//void TPVFC24C02EEPROMWriteData(BYTE ucSlaveAddr, WORD usSubAddr, WORD usLength, BYTE *pWriteArray);///DFM rev02 patch note 6
void TPVFCEDIDWriteData(void);
void TPVFCEDIDReadData(void);
BYTE TPVFCCalCheckSum(BYTE ucSum);
//===DFM function====
void TPVDFMInitial(void);
bit TPVDFMModeFlag(void);
bit TPVDFMCableWPCheck(void);//DFM rev02 patch note 7
void TPVDFMFactoryRest(void);
void TPVDFMPowerRecall(void);
bit TPVDFMLogoOnCheck(void);
bit TPVDFMKeyPadLedCheck(BYTE ucKeyPadLed);
bit TPVDFMAutoConfigByPass(void);
//bit TPVDFMMsgTimeAcceleration(void);
void TPVDFMSet( bit bOnOff);// 20120528 by jerry, 
#if (_PANEL_VCOM_ADJUST_FUNCTION == _ON)
void TPVFCCheckPanelVcom(void);
#if(0)
BYTE TPVFCGetPanelVcom(void);
#endif
void TPVFCSetPanelVcom(BYTE setPanelVcom);
#endif
void TPVFactFuncBurnInPattern(void);//DFM rev02 patch note 7
#if((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
void CTPVFCReloadEdid(void);
#endif
void TPVDFMInternalADCCheck(void); //DFM rev05 patch note 2

//----------------------------------------------------------------------------------------------------
// OSD Factory Data Function
//----------------------------------------------------------------------------------------------------
void TPVNVRamSaveFactoryDate(void)
{
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
    //UserCommonEepromWrite(_PANEL_TIME_DATA_ADDRESS_END, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));
    UserCommonEepromWrite(_FACTORY_SETTING_DATA_ADDRESS, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));    
#else
	UserInterfaceFlashSaveItem(_FLASH_ITEMID_FACTORY_DATA, (BYTE *)(&g_stFactoryData), sizeof(StructFactoryType));
#endif
}
void TPVNVRamLoadFactoryDate(void)
{
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)
    //UserCommonEepromRead(_PANEL_TIME_DATA_ADDRESS_END, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));
    UserCommonEepromRead(_FACTORY_SETTING_DATA_ADDRESS, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));
	//UserNVRamCheckRange(g_stFactoryData);
#else
	if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_FACTORY_DATA, pData, sizeof(StructFactoryType)) == _TRUE)
	{
		memcpy(&g_stFactoryData, pData, sizeof(StructFactoryType));
	}
	else
	{
		g_stFactoryData = g_stFactoryDataDefault;
	}
#endif

}
void TPVNVRamRestoreFactoryDate(void)
{
	g_stFactoryData = g_stFactoryDataDefault;
    
#if(_SYSTEM_EEPROM_EMULATION_SUPPORT == _OFF)    
	//UserCommonEepromWrite(_PANEL_TIME_DATA_ADDRESS_END, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));
	UserCommonEepromWrite(_FACTORY_SETTING_DATA_ADDRESS, sizeof(StructFactoryType), (BYTE *)(&g_stFactoryData));
#else
	if(UserInterfaceFlashLoadItem(_FLASH_ITEMID_FACTORY_DATA, pData, 1) == _TRUE)
	{
		TPVNVRamSaveFactoryDate();
	}
#endif

}


//--------------------------------------------------
// Description  : TPV Factory Command DDCCI process
// Input Value  : None
// Output Value : TRUE: do Factory Command, FALSE: do nothing
//--------------------------------------------------
bit TPVFCmdFactoryCommand(void)
{  
	if(g_ucDdcciRxBuf[_FC_BYTE3] != CMD_FC_TPVFactory)
		return _FALSE;
// TPV	factory command 
	
	if(g_ucDdcciRxBuf[_FC_BYTE2] == _DDCCI_CMD_SET_VCP_FEATURE)
	{  
		switch(g_ucDdcciRxBuf[_FC_BYTE4]) 
		{
//--------0x16
			case VCP_FC_ADJUST_R_GAIN: 
				COLORTEMP_RGAIN();
				TPVFCReplyCommand(_REPLY_RESULT_02 ,_AWB_COMMAND_LEN_CRC);
				break;	
//--------0x18
			case VCP_FC_ADJUST_G_GAIN:
				COLORTEMP_GGAIN();
				TPVFCReplyCommand(_REPLY_RESULT_02 ,_AWB_COMMAND_LEN_CRC);
				break;				
//--------0x1A
			case VCP_FC_ADJUST_B_GAIN:
				COLORTEMP_BGAIN();
				TPVFCReplyCommand(_REPLY_RESULT_02 ,_AWB_COMMAND_LEN_CRC);
				break;
//--------0x12
			case VCP_FC_ADJUST_CONTRAST:
				FC_CONTRAST();
				break;	
//--------0x10			
			case VCP_FC_ADJUST_BL_BRIGHTNESS:
				FC_BRIGHTNESS();
				break;
//--------0x14			
			case VCP_FC_SAVE_COLORTEMP:
				TPVFCSetSaveColorTemp();
				TPVFCReplyCommand(_REPLY_RESULT_02 ,_AWB_COMMAND_LEN_CRC);
				break;
//--------0x04
	    	case VCP_FC_RESET:
				if((g_ucDdcciRxBuf[_FC_BYTE5]== 0x00)&&(g_ucDdcciRxBuf[_FC_BYTE6] == 0x00)&&(g_ucDdcciRxBuf[_FC_BYTE7] == 0x00))
				{
					if (TPVDFMModeFlag()==_ON)
                    {
						bTpvDfmLedNotice = _HIGH;
                    }
					FC_RESET();
					TPVFCReplyCommand(_REPLY_RESULT_02 ,_AWB_COMMAND_LEN_CRC);
				}
				break;
//--------0x1F
			case VCP_FC_AUTO_LEVEL:
#if (_VGA_SUPPORT == _ON)
                TPVAutoDoWhiteBalance();
#endif
				break;
//--------0x1E	            
			case VCP_FC_AUTO_ADJUST:
#if (_VGA_SUPPORT == _ON)
            	if(SysSourceGetSourceType() == _SOURCE_VGA)
                {
				    UserCommonAutoConfig(); 
                    //20130424 Abel Reset Image VPos Modify
                    SET_VGA_MODE_ADJUST_H_POSITION(50);
                    SET_VGA_MODE_ADJUST_V_POSITION(50);
            	}
#endif // End of #if(_VGA_SUPPORT == _ON)
			   TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);	

				break;
//--------0xCC			
			case VCP_FC_SET_LANGUAGE:
				TPVFCSetLanguage();
				TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);		
				break;
//--------0x60
			case VCP_FC_SET_SOURCE:
				switch (g_ucDdcciRxBuf[_FC_BYTE6])
				{
					case 0x01:						
						SWITCH_VGA();
						break;
					case 0x03:						
						SWITCH_DVI();
						break;
					case 0x11:						
						SWITCH_HDMI();
						break;
					case 0x12:						
						SWITCH_HDMI2();
						break;
					case 0x0F:						
						SWITCH_DP();
						break;
				}

				TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);
				break;
//--------0xD6		
			case VCP_FC_ENTER_POWERSAVING:
				TPVFCForcePowerSaving();
				break;	
//DFM rev05 patch note 1>>
			case VCP_FC_DC_FUNC:
				if(g_ucDdcciRxBuf[_FC_BYTE5]==0x00)
				{
					FC_DC_COLOR_MODE_SWITCH(g_ucDdcciRxBuf[_FC_BYTE6],g_ucDdcciRxBuf[_FC_BYTE7]);
				}
				break;	
//DFM rev05 patch note 1<<
//--------0xE2			
			case VCP_FC_Code02://ADC gain/offset
#if(_VGA_SUPPORT == _ON)
				switch(g_ucDdcciRxBuf[_FC_BYTE5]) 
				{
//--------0xE2	-[0x01~0x06]
					case SUB_VCP_FC_ADJUST_ADC_R_GAIN:
						ADC_RGAIN();			
						break;
					case SUB_VCP_FC_ADJUST_ADC_G_GAIN:
						ADC_GGAIN();			
						break;
					case SUB_VCP_FC_ADJUST_ADC_B_GAIN:
						ADC_BGAIN();			
						break;
					case SUB_VCP_FC_ADJUST_ADC_R_OFFSET:
						ADC_ROFFSET();			
						break;
					case SUB_VCP_FC_ADJUST_ADC_G_OFFSET:
						ADC_GOFFSET();			
						break;
					case SUB_VCP_FC_ADJUST_ADC_B_OFFSET:
						ADC_BOFFSET();			
						break;

					default:
						break;
				}
#endif // End of #if(_VGA_SUPPORT == _ON)
				break;
//--------0xE1	
			case VCP_FC_Code01:
				switch(g_ucDdcciRxBuf[_FC_BYTE5]) 
				{
//--------0xE1-[0xA0]
					case SUB_VCP_FC_FACTORY_MODE_A0:
						if(g_ucDdcciRxBuf[_FC_BYTE6]==0x00) 
						{
							if(g_ucDdcciRxBuf[_FC_BYTE7]==SUB1_VCP_FC_EXIT_FACTORY_MODE)
							{ 
								ExitFactroyMode();
							}					
							else if(g_ucDdcciRxBuf[_FC_BYTE7]==SUB1_VCP_FC_ENTER_FACTORY_MODE) 
							{
								EnterFactroyMode();
							}
							
							TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);		
						}
						break;
//DFM rev05 patch note 5>>
//--------0xE1-[0xA1]
					case SUB_VCP_FC_NVRAW_RESTORE_A1:
                        if((GET_OSD_BRIGHTNESS() == 0x00) && (GET_OSD_CONTRAST() == 0x00))
                        {
                            if(g_ucDdcciRxBuf[_FC_BYTE6] == 0x00) 
                            {
                                if(g_ucDdcciRxBuf[_FC_BYTE7] == SUB1_VCP_FC_NVRAW_RESTORE_A1_ON)
                                { 
                                    RestoreNVRaw();
                                }						
                            }
                            TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);
                        }
						break;
//DFM rev05 patch note 5>>
//--------0xE1-[0xA2]
					case SUB_VCP_FC_FACTORY_MODE_A2://4
						if(g_ucDdcciRxBuf[_FC_BYTE6] == 0x00)
						{
							if (g_ucDdcciRxBuf[_FC_BYTE7]==SUB1_VCP_FC_SET_BURNIN_OFF) 
							{
								BurnIn_Off();
							}
							else if(g_ucDdcciRxBuf[_FC_BYTE7]==SUB1_VCP_FC_SET_BURNIN_ON)
							{
								BurnIn_On();
							}
							
							TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);		
						}
						else if(g_ucDdcciRxBuf[_FC_BYTE6] == 0x01)
						{
							if(g_ucDdcciRxBuf[_FC_BYTE7] == SUB1_VCP_FC_SET_WR_END)
							{ 
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99 
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
								VGAEDID_WRITE();	
#endif
#endif
//DFM rev07 patch note 3 <<

							
//DFM rev02 patch note 8>>
								FC_EDID_EEPROM_WP_ENABLE();

//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99 
								FC_DDCSRAMWRITE_DISABLE(); 
#endif
//DFM rev07 patch note 3 <<


								if(SysModeGetModeState()!=_MODE_STATUS_ACTIVE)
								{
									SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
									SET_FORCE_POW_SAV_STATUS(_FALSE); 
								}
//DFM rev02 patch note 8<<								
							}
							else if(g_ucDdcciRxBuf[_FC_BYTE7] == SUB1_VCP_FC_SET_WR_START)
							{
//######################Notice, it maybe induce HDCP key loss######################
#if (_DP_SUPPORT == _ON)
								DPEDID_ERASE();
#elif(_MHL_SUPPORT == _ON)///DFM rev05 patch note 3
								MHLEDID_ERASE();
#endif
//#####################################################################
//DFM rev02 patch note 8>>
								FC_EDID_EEPROM_WP_DISABLE();

//DFM rev07 patch note 3 >>  
#ifdef _SUPPORT_PC99 
                                FC_DDCSRAMWRITE_ENABLE(); 
#endif

#if((_DP_SUPPORT == _ON) || (_MHL_SUPPORT == _ON))
                                FC_EDID_ERASE();
#else

#ifdef _SUPPORT_PC99 
                                FC_EDID_ERASE();
#endif

#endif
//DFM rev07 patch note 3 <<

//DFM rev06 patch note 1 >> turn on Power when  writing EDID through DDC channel
								if ((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING))
									SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
//DFM rev06 patch note 1<<
								if(SysModeGetModeState()!=_MODE_STATUS_ACTIVE)
								{
									SysModeSetResetTarget(_MODE_ACTION_RESET_TO_FACTORY_MODE);
									SET_FORCE_POW_SAV_STATUS(_TRUE);
								}
//DFM rev02 patch note 8<<
							}

							TPVFCReplyEDIDPortData();
						}
						break;


//--------0xE1-[0xA3]
					case SUB_VCP_FC_FACTORY_MODE_A3:
						BACKLIGHTTIME_INITIAL();
						TPVFCReplyCommand(_REPLY_RESULT_02,_AWB_COMMAND_LEN_CRC);
						break;
//DFM rev05 patch note 1>>
//--------0xE1-[0xA4]
					case SUB_VCP_FC_FACTORY_MODE_A4:
						
						if(g_ucDdcciRxBuf[_FC_BYTE6] == 0x12)//ICARE
						{
							FC_A4_12_COMMAND(g_ucDdcciRxBuf[_FC_BYTE7]);
						}
						else if(g_ucDdcciRxBuf[_FC_BYTE6] == 0x13)//DPS
						{
							FC_A4_13_COMMAND(g_ucDdcciRxBuf[_FC_BYTE7]);							
						}
						//for Philips project & Benq Project
						else if(g_ucDdcciRxBuf[_FC_BYTE6] == 0x08)//ErgoSensor
						{
							FC_A4_08_COMMAND(g_ucDdcciRxBuf[_FC_BYTE7]);
						}
						else if(g_ucDdcciRxBuf[_FC_BYTE6] == 0x14)//ErgoSensor
						{
							FC_A4_14_COMMAND(g_ucDdcciRxBuf[_FC_BYTE7]);
						}
						break;
//DFM rev05 patch note 1<<

//--------0xE1-[0xA5]
					case SUB_VCP_FC_FACTORY_MODE_A5:
						if(g_ucDdcciRxBuf[_FC_BYTE6] == 0x00)
						{
							if(g_ucDdcciRxBuf[_FC_BYTE7]== SUB1_VCP_FC_EXIT_DFM)
							{

#if(_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)
								break;
#endif	
								TPVDFMSet(_OFF);// 20120528 by jerry, 
								EXIT_DFMPROC();
							}
							else if(g_ucDdcciRxBuf[_FC_BYTE7]== SUB1_VCP_FC_ENTER_DFM)
							{
								TPVDFMSet(_ON);// 20120528 by jerry, 
							}
							
							TPVFCReplyCommand(_REPLY_RESULT_02 ,_AWB_COMMAND_LEN_CRC);
						}
						break;
//--------0xE1-[0xA6]
					case SUB_VCP_FC_FACTORY_MODE_A6:
						//reserve for IIC switch 
						break;
//--------0xE1-[0xA7]
					case SUB_VCP_FC_FACTORY_MODE_A7:
						if((g_ucDdcciRxBuf[_FC_BYTE6]) == VCP_FC_FACTORY_LOGO_OFF)//DFM rev04 patch note 2
						{
							if(g_ucDdcciRxBuf[_FC_BYTE7]==VCP_FC_FACTORY_LOGO_OFF_ENABLE)//DFM rev04 patch note 2 
							{
								SET_FACTORY_FORCE_LOGO_OFF( _ON);//DFM rev04 patch note 2	
							}
							else if(g_ucDdcciRxBuf[_FC_BYTE7]==VCP_FC_FACTORY_LOGO_OFF_DISABLE)//DFM rev04 patch note 2
							{
								SET_FACTORY_FORCE_LOGO_OFF( _OFF);//DFM rev04 patch note 2
							}
							TPVNVRamSaveFactoryDate();
							TPVFCReplyCommand(_REPLY_RESULT_02,_AWB_COMMAND_LEN_CRC);
						}
#if(_DCR_SUPPORT == _ON)                 
						else if((g_ucDdcciRxBuf[_FC_BYTE6]) == VCP_FC_FACTORY_DCR_MODE)
						{
						//DFM rev05 patch note 1>>
							FC_A7_03_DCR_COMMAND(g_ucDdcciRxBuf[_FC_BYTE7]);
						//DFM rev05 patch note 1<<
							TPVFCReplyCommand(_REPLY_RESULT_02,_AWB_COMMAND_LEN_CRC);
						}
#endif                        
						break;
#if (_PANEL_VCOM_ADJUST_FUNCTION==_ON)                                                
//--------0xE1-[0xA9]
					case SUB_VCP_FC_FACTORY_MODE_A9:
						if (g_ucDdcciRxBuf[_FC_BYTE6]==0x00)
						{
							SET_FACTORY_VCOM(g_ucDdcciRxBuf[_FC_BYTE7]);
							SET_SW_IIC_STATUS(_I2C_LINE_PANEL);
							pData[0]=0x00;
							ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x02, 1, &pData[0]);
							pData[0]=GET_FACTORY_VCOM();
							ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x00, 1, &pData[0]);
							SET_SW_IIC_STATUS(_I2C_LINE_NVRAM);
							TPVNVRamSaveFactoryDate();    
						}                       
						break;
#endif
//--------0xE1-[0xE0]
					case SUB_VCP_FC_SET_HDCP_WRITE_START:
#if((_DIGITAL_PORT_SUPPORT == _ON))
							bAocFactoryHdcpWriteStart=_TRUE;
							HDCP_START();
#endif 
						break;
				}
				break;

//--------0xEA
			case VCP_FC_Code0A:
#if(_DIGITAL_PORT_SUPPORT == _ON)				
					if(bAocFactoryHdcpWriteStart ==_TRUE)
					{
						HDCP_WRITE();
						TPVFCReplyCommand(_REPLY_RESULT_02, g_ucDdcciRxBuf[_FC_BYTE5]+2);
					}
#endif
				break;

//--------0xEF
			case VCP_FC_Code0F:
	    		TPVFCEDIDWriteData();
				break;

	        default:
		        break;
		}
	}
	else if((g_ucDdcciRxBuf[_DDCCI_COMMAND] == _DDCCI_CMD_GET_VCP_FEATURE))
	{
		if((g_ucDdcciRxBuf[_FC_BYTE4]== VCP_FC_Code01)&&(g_ucDdcciRxBuf[_FC_BYTE5]== SUB_VCP_FC_READ_HDCP_CRC))
		{
			TPVFCHdcpCrcCheck();
			//SysPowerRecoverHDCPKey();//need to confirm
		}		 
#if (_PANEL_VCOM_ADJUST_FUNCTION == _ON)        
		else if((g_ucDdcciRxBuf[_FC_BYTE4]== VCP_FC_Code01)&&(g_ucDdcciRxBuf[_FC_BYTE5]== SUB_VCP_FC_FACTORY_MODE_A9))
		{
			g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
			g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x08;
			g_ucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
			g_ucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
			g_ucDdcciTxBuf[_DDCCI_SINK_OPCODE] = CMD_FC_TPVFactory;
			UserCommonDdcciSetVCPReplyValue(0x01, GET_FACTORY_VCOM(), 0);
			g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = UserCommonDdcciCalCheckSum();
			ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
		}
#endif	
		else if(g_ucDdcciRxBuf[_FC_BYTE4]== VCP_FC_Code0F)
		{
			TPVFCEDIDReadData();
		}
		else
		{
			switch(g_ucDdcciRxBuf[_FC_BYTE4])
			{
	//--------0xE1
				case VCP_FC_Code01:
					switch(g_ucDdcciRxBuf[_FC_BYTE5])
					{
	//--------0xE1-[0xE4]
						case SUB_VCP_FC_READ_DEVICE_ID:
							TPVFCmdGetText(_DFM_TEXT_DEVICE_VERSION);
							break;
	//--------0xE1-[0xA7]
						case SUB_VCP_FC_FACTORY_MODE_A7:
							if((g_ucDdcciRxBuf[_FC_BYTE6]== 0x07)&& (g_ucDdcciRxBuf[_FC_BYTE7]== 0x00))//panel  type
							{
								TPVFCmdGetText(_DFM_TEXT_PANEL_TYPE);
							}
							break;
						
	//--------0xE1-[0xA4]
						case SUB_VCP_FC_FACTORY_MODE_A4:
							if(g_ucDdcciRxBuf[_FC_BYTE6]== 0x01)
							{
								TPVFCmdGetText(_DFM_TEXT_URL);
							}
							
							break;
							
						default:
							break;
					}
					break;
	//--------0xE2
				case VCP_FC_Code02:
#if(_VGA_SUPPORT == _ON)
					switch(g_ucDdcciRxBuf[_FC_BYTE5])
					{
	//--------0xE2	-[0x01~0x06]
						case SUB_VCP_FC_ADJUST_ADC_R_GAIN:
							TPVFCmdGetValue(0x01, GET_ADC_RGAIN(), 0);
							break;
						case SUB_VCP_FC_ADJUST_ADC_G_GAIN:
							TPVFCmdGetValue(0x01, GET_ADC_GGAIN(), 0);
							break;
						case SUB_VCP_FC_ADJUST_ADC_B_GAIN:
							TPVFCmdGetValue(0x01, GET_ADC_BGAIN(), 0);
							break;
						case SUB_VCP_FC_ADJUST_ADC_R_OFFSET:
							TPVFCmdGetValue(0x01, GET_ADC_ROFFSET(), 0);
							break;
						case SUB_VCP_FC_ADJUST_ADC_G_OFFSET:
							TPVFCmdGetValue(0x01, GET_ADC_GOFFSET(), 0);
							break;
						case SUB_VCP_FC_ADJUST_ADC_B_OFFSET:
							TPVFCmdGetValue(0x01, GET_ADC_BOFFSET(), 0);
							break;

						default:
							break;
					}
#endif // End of #if(_VGA_SUPPORT == _ON)
			break;
			
//--------0xE9(read edid model name)
			case VCP_FC_Code09:
				TPVFCmdGetText(_DFM_TEXT_MODEL_NAME);
				break;

//--------0x10(get brightness)
			case VCP_FC_ADJUST_BL_BRIGHTNESS:
				TPVFCmdGetValue(0x01, FC_GET_BRIGHTNESS(), 0);
				break;

//--------0x16(get gain max)
			case VCP_FC_RANGE_GAIN:
				if(g_ucDdcciRxBuf[_FC_BYTE5] == SUB_VCP_FC_COLORTMP_GAIN_MAX)
				{
					TPVFCmdGetValue(0x01, FC_GET_RANGE_GAIN(), 0);
				}
				break;

//--------0xCC(get language)
			case VCP_FC_SET_LANGUAGE:
				TPVFCmdGetValue(0x01, FC_GET_LANGUAGE(), 0);
				break;

			default:
				break;

			}
		}
		
	}	
	else if((g_ucDdcciRxBuf[_FC_BYTE4]== 'R')&&(g_ucDdcciRxBuf[_FC_BYTE5]== 'E')\
	&&(g_ucDdcciRxBuf[_FC_BYTE6]== 'D')&&(g_ucDdcciRxBuf[_FC_BYTE7]== 'I')&&(g_ucDdcciRxBuf[_FC_BYTE8]== 'D'))
	{
		TPVFCReplyEDIDStatus();
	}

	return _TRUE;
}

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCmdGetText(BYTE StringItem)
{
    BYTE ucSendLen = 0;
    BYTE ucCount = 0;
    BYTE *pArrayBuffer;

    switch(StringItem)
    {
        case _DFM_TEXT_DEVICE_VERSION:
            {
                BYTE tInfor[] = {_MICROCODE};
                pArrayBuffer = tInfor;
                ucSendLen = sizeof(tInfor);
            }
            break;

        case _DFM_TEXT_PANEL_TYPE:
            {
                BYTE tInfor[] = {_PANNEL_NAME};
                pArrayBuffer = tInfor;
                ucSendLen = sizeof(tInfor);
            }
            break;

        case _DFM_TEXT_URL:
            {
                BYTE tInfor[] = {_F_URL};
                pArrayBuffer = tInfor;
                ucSendLen = sizeof(tInfor);
            }
            break;

        case _DFM_TEXT_MODEL_NAME:
            {
                BYTE tInfor[] = {_MODEL_NAME};
                pArrayBuffer = tInfor;
                ucSendLen = sizeof(tInfor);
            }
            break;

        default:
            break;
    }

    if(ucSendLen > 0x20)
    {
        return;
    }
    
	g_ucDdcciTxBuf[_DDCCI_SOURCE] 		= _DDCCI_DEST_ADDRESS;
	g_ucDdcciTxBuf[_DDCCI_LENGTH] 		= _DDCCI_CONTROL_STATUS_FLAG |(ucSendLen + 4);
	g_ucDdcciTxBuf[_DDCCI_COMMAND] 	= _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
	g_ucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
    g_ucDdcciTxBuf[_DDCCI_SINK_OPCODE] = g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE];
    g_ucDdcciTxBuf[_DDCCI_TYPE_CODE] = 0x00;
    
    for(ucCount = 0; ucCount < ucSendLen; ucCount++)
    {
        g_ucDdcciTxBuf[_FC_BYTE6 + ucCount] = pArrayBuffer[ucCount];
    }
	g_ucDdcciTxBuf[(g_ucDdcciTxBuf[_DDC_LENGTH] & 0x7f) + 2] = UserCommonDdcciCalCheckSum();

	ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCmdGetValue(BYTE ucTypeOpcode, WORD usPresent1, WORD usPresent2)
{
    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x08;
    g_ucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
    g_ucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
    g_ucDdcciTxBuf[_DDCCI_SINK_OPCODE] = g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE];

    g_ucDdcciTxBuf[_DDCCI_TYPE_CODE] = ucTypeOpcode;
    g_ucDdcciTxBuf[_DDCCI_MAX_HIGH_BYTE] = HIBYTE(usPresent1);
    g_ucDdcciTxBuf[_DDCCI_MAX_LOW_BYTE] = LOBYTE(usPresent1);
    g_ucDdcciTxBuf[_DDCCI_PRESENT_HIGH_BYTE] = HIBYTE(usPresent2);
    g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE] = LOBYTE(usPresent2);
    
    g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = UserCommonDdcciCalCheckSum();
    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}



//--------------------------------------------------
// Description  : TPV Factory Command save Color Temp.
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCSetSaveColorTemp(void)
{
	if((g_ucDdcciRxBuf[_FC_BYTE5] == SUB_VCP_FC_SAVE_COLORTEMP_All))//save all
	{		
		COLORTEMP_All_SAVE();
		return;
	}

	switch(g_ucDdcciRxBuf[_FC_BYTE5]) 
	{	
		case SUB_VCP_FC_SAVE_COLORTEMP_6500:
			COLORTEMP_6500();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_9300:
			COLORTEMP_9300();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_User:
			COLORTEMP_User();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_sRGB:
			COLORTEMP_sRGB();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_Native:
			COLORTEMP_Native();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_4000:
			COLORTEMP_4000();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_5000:
			COLORTEMP_5000();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_7200:
			COLORTEMP_7200();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_8200:
			COLORTEMP_8200();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_10000:
			COLORTEMP_10000();
			break;
		case SUB_VCP_FC_SAVE_COLORTEMP_11500:
			COLORTEMP_11500();
			break;
		default:
			COLORTEMP_User();
		break;

	}
	

	if(g_ucDdcciRxBuf[_FC_BYTE7] == 0x01)//recall
	{
		COLORTEMP_RECALL();
	}
	else if(g_ucDdcciRxBuf[_FC_BYTE7] == 0x00)//save
	{
	    COLORTEMP_SAVE();	
	}
}


//--------------------------------------------------
// Description  : TPV Factory Command set language
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////
//- 0x00 = Reserved, must be ignored
//- 0x01 = Chinese (traditional / Hantai)    - 0x02 = English    	- 0x03 = French 	- 0x04 = German
//- 0x05 = Italian                     	- 0x06 = Japanese   		- 0x07 = Korean 	- 0x08 = Portuguese (Portugal)
//- 0x09 = Russian						- 0x0A = Spanish (Espanol)  - 0x0B = Swedish	- 0x0C = Turkish
//- 0x0D = Chinese (simplified / Kantai)      - 0x0E = Portuguese (Brazil)    - 0x0F = Arabic           - 0x10 = Bulgarian
//- 0x11 = Croatian                 	- 0x12 = Czech  			- 0x13 = Danish 	- 0x14 = Dutch (Netherlands)
//- 0x15 = Estonian                 	- 0x16 = Finnish    		- 0x17 = Greek  	- 0x18 = Hebrew
//- 0x19 = Hindi                    	- 0x1A = Hungarian  		- 0x1B = Latvian    - 0x1C = Lithuanian
//- 0x1D = Norwegian                    - 0x1E = Polish 			- 0x1F = Romanian	- 0x20 = Serbian
//- 0x21 = Slovak                       - 0x22 = Slovenian			- 0x23 = Thai     	- 0x24 = Ukrainian
//- 0x25 = Vietnamese
/////////////////////////////////////////////////////////////////////////////////////////
void TPVFCSetLanguage(void)
{
	switch(g_ucDdcciRxBuf[_FC_BYTE7])
	{
	       case 0x01://Chinese (traditional )
                FC_CHNIESE_T();
            	break;
		   case 0x02://English
           		FC_ENGLISH();
            	break;
           case 0x03://French
            	FC_FRENCH();
            	break;
        	case 0x04://German   
            	FC_GERMAN();
            	break;
        	case 0x05://Italian   
            	FC_ITALIAN();
            	break;
        	case 0x06://Japanese   
                FC_JAPANESE();
            	break;
			case 0x07://Korean
				FC_KOREAN();
				break;
			case 0x08://Portuguese (Portugal)
				FC_PORTUGUESE_P();
				break;
		    case 0x09://Russian
				FC_RUSSIAN();
		        break;		
        	case 0x0A://Spanish 
        		FC_SPANISH();
            	break;
			case 0x0B://Swedish	
				FC_SWEDISH();
				break;
			case 0x0C://Turkish
				FC_TURKISH();
				break;
			case 0x0D://Chinese (simplified)
				FC_CHINESE_S();
				break;
			case 0x0e://Portuguese (Brazil)	
				FC_PORTUGUESE_B();
				break;
			case 0x0F://Arabic
				FC_ARABIC();
				break;
			case 0x12://Czech
				FC_CZECH();
				break;
			case 0x13://Danish
				FC_DANISH();
				break;
			case 0x14://Dutch
				FC_DUTCH();
				break;
			case 0x16://Finnish
				FC_FINNISH();
				break;
			case 0x1E://Polish
				FC_POLISH();
				break;
        	default:
            	break;
    	}
	
	FC_LANGUAGE();
}
//--------------------------------------------------
// Description  : TPV Factory Command enter power saving
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCForcePowerSaving(void)  
{
	if(g_ucDdcciRxBuf[_FC_BYTE7]==0)//enter power saving
	{
		if(GET_FORCE_POW_SAV_STATUS()==_FALSE)
		{
			SET_FORCE_POW_SAV_STATUS(_TRUE);
			SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
		}
	}
	TPVFCReplyCommand(_REPLY_RESULT_02, _AWB_COMMAND_LEN_CRC);
}

//--------------------------------------------------
// Description  : TPV Factory Command reply EDID port
// 				AOC Factory tool will detect this return value to determind EDID write procedure
//				EDIDPort {VGA1=BIT7,VGA2=BIT6,DVI1=BIT5,DVI2=BIT4,HDMI1=BIT3,HDMI2=BIT2,DP1=BIT1,DP2=BIT0}	
//				Sample(_HDMI_SUPPORT == _ON):g_ucDdcciTxBuf[3] = (_BIT7 |_BIT5 |_BIT3);	 // VGA1 DVI1 HDMI1
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCReplyEDIDPortData(void)
{
	g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
	g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x03;
	g_ucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
	g_ucDdcciTxBuf[3] = 0x00;
	g_ucDdcciTxBuf[4] = 0x00;//DFM rev05 patch note 3
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
	g_ucDdcciTxBuf[3] |= (_BIT7);    // VGA1
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT))
	g_ucDdcciTxBuf[3] |= (_BIT5);    //  DVI1
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)&&(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT))
	g_ucDdcciTxBuf[3] |= (_BIT4);    //  DVI2
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT))
	g_ucDdcciTxBuf[3] |= (_BIT3);    //  HDMI1
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)&&(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT))
	g_ucDdcciTxBuf[3] |= (_BIT2);    //  HDMI2
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)||(_D1_INPUT_PORT_TYPE == _D1_DP_PORT))
	g_ucDdcciTxBuf[3] |= (_BIT1);    //DP
#endif
//DFM rev05 patch note 3>>
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)&&(_D1_INPUT_PORT_TYPE == _D1_DP_PORT))
	g_ucDdcciTxBuf[3] |= (_BIT0);    //DP2
#endif
//-------------------------------------------------------------
#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
	g_ucDdcciTxBuf[4] |= (_BIT5);	 //MHL1
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
	g_ucDdcciTxBuf[3] |= (_BIT3);    //  HDMI1
#elif(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
	g_ucDdcciTxBuf[3] |= (_BIT2);    //  HDMI2
#endif    
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)&&(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
	g_ucDdcciTxBuf[4] |= (_BIT4);	 //MHL2
    g_ucDdcciTxBuf[3] |= (_BIT2) | (_BIT3);    //  HDMI1 && HDMI2
#endif
	g_ucDdcciTxBuf[4] |= ((g_ucDdcciRxBuf[_FC_BYTE7]==_ON) ? _BIT1 : 0x00 );//Status {BIT0 (0:EEPROM;1:FLASH)  BIT1(0:Disable;1:Enable)  BIT2~BIT7=>(reversed)}
//DFM rev05 patch note 3<<
    g_ucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}


//--------------------------------------------------
// Description  : TPV Factory Command HDCP data write
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCEDIDWriteData(void)
{       
	BYTE ucEdidLength = (g_ucDdcciRxBuf[_DDC_LENGTH]-0x86);//32;///DFM rev03 patch note 1
	
    switch(g_ucDdcciRxBuf[_FC_BYTE5])
    {
        case SUB_VCP_FC_VGA1_EDID:  
			
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99      

#else 
//DFM rev07 patch note 3 <<
#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)

			ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, ucEdidLength, &g_ucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6//DFM rev03 patch note 1
			ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#endif
#endif            
        break;

#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DVI_PORT))
        case SUB_VCP_FC_DVI1_EDID:
			
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99     
			DVIEDID_WRITE();
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
			memcpy(MCU_DDCRAM_D0+(g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), &g_ucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
#elif(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
			memcpy(MCU_DDCRAM_D1+(g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), &g_ucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
#endif
			
#else 
//DFM rev07 patch note 3 <<
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, ucEdidLength, &g_ucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6//DFM rev03 patch note 1
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, ucEdidLength, &g_ucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6//DFM rev03 patch note 1
#endif		
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif		
#endif
            break;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))//DFM rev05 patch note 3
        case SUB_VCP_FC_HDMI1_EDID:
			
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99     
			HDMIEDID_WRITE();
#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
			memcpy(MCU_DDCRAM_D0+(g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), &g_ucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
			memcpy(MCU_DDCRAM_D1+(g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), &g_ucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
#endif
			
#else 
//DFM rev07 patch note 3 <<
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, ucEdidLength, &g_ucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6//DFM rev03 patch note 1
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, ucEdidLength, &g_ucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6//DFM rev03 patch note 1
#endif		

#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif		
#endif
            break;
#endif

//#if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) && (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT))||((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))//DFM rev05 patch note 3
#if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) && (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT))||((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))//DFM rev05 patch note 3

        case SUB_VCP_FC_HDMI2_EDID:
			
#if(DFM_HDMI2_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, ucEdidLength, &g_ucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6//DFM rev03 patch note 1
#elif(DFM_HDMI2_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, ucEdidLength, &g_ucDdcciRxBuf[_FC_BYTE8], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6//DFM rev03 patch note 1
#endif		

#if(DFM_HDMI2_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#elif(DFM_HDMI2_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif			

            break;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_PORT)) 
        case SUB_VCP_FC_DP1_EDID:
//DP EDID save to User EEPROM			
#if(_DP_SUPPORT == _ON)
			DPEDID_WRITE();
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
			memcpy(MCU_DDCRAM_D0+(g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), &g_ucDdcciRxBuf[_FC_BYTE8], ucEdidLength);//DFM rev03 patch note 1
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
			memcpy(MCU_DDCRAM_D1+(g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), &g_ucDdcciRxBuf[_FC_BYTE8], ucEdidLength);//DFM rev03 patch note 1
#endif 
#endif//END OF #if(_DP_SUPPORT == _ON)
            break;
#endif			
//DFM rev05 patch note 3>>
#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
		case SUB_VCP_FC_MHL1_EDID:
			MHLEDID_WRITE();
			memcpy(MCU_DDCRAM_MHL+(g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), &g_ucDdcciRxBuf[_FC_BYTE8], ucEdidLength);
			break;
#endif		
#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
		case SUB_VCP_FC_MHL2_EDID:
			MHL2EDID_WRITE();
			break;
#endif		
//DFM rev05 patch note 3<<

		case SUB_VCP_FC_VGA2_EDID:
		case SUB_VCP_FC_DVI2_EDID:
		case SUB_VCP_FC_DP2_EDID:
		case SUB_VCP_FC_EEPROM:
		case SUB_VCP_FC_HDCP1:
		case SUB_VCP_FC_HDCP2:
		case SUB_VCP_FC_OSDSN:
		case SUB_VCP_FC_OSDMODELNAME:
			
        default:
	        break;
    }  
    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x03;
    g_ucDdcciTxBuf[2] = g_ucDdcciRxBuf[_FC_BYTE6];
    g_ucDdcciTxBuf[3] = g_ucDdcciRxBuf[_FC_BYTE7];
    g_ucDdcciTxBuf[4] = ucEdidLength;//DFM rev03 patch note 1
    g_ucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);

}

//--------------------------------------------------
// Description  : TPV Factory Command EDID Read
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCEDIDReadData(void)
{
    switch(g_ucDdcciRxBuf[_FC_BYTE5])
    {
        case SUB_VCP_FC_VGA1_EDID: 
			
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99
			VGAEDID_READ();
#else
//DFM rev07 patch note 3 <<
#if(_EEPROM_ACCESS_FUNCTION_SUPPORT == _ON)

			ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_ucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
			ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#endif

#endif
            break;
			  
#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DVI_PORT))		  
        case SUB_VCP_FC_DVI1_EDID:
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99
			DVIEDID_READ();
#else
//DFM rev07 patch note 3 <<

#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_ucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_ucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
#endif		

#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif				
#endif		    
            break;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))//DFM rev05 patch note 3
        case SUB_VCP_FC_HDMI1_EDID:
			
//DFM rev07 patch note 3 >>
#ifdef _SUPPORT_PC99    
			HDMIEDID_READ();
#else
//DFM rev07 patch note 3 <<
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_ucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_ucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
#endif		

#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif		
#endif       
            break;
#endif


//#if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) && (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT))||((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))//DFM rev05 patch note 3
#if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) && (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT))||((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))//DFM rev05 patch note 3
		case SUB_VCP_FC_HDMI2_EDID:

#if(DFM_HDMI2_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_ucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
#elif(DFM_HDMI2_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
			UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, (g_ucDdcciRxBuf[_FC_BYTE6]+g_ucDdcciRxBuf[_FC_BYTE7]), 1, 32, &g_ucDdcciTxBuf[_FC_BYTE2], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
#endif		


#if(DFM_HDMI2_DDC_CHANNEL == _DDC2)
			ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#elif(DFM_HDMI2_DDC_CHANNEL == _DDC3)
			ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif			


			break;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_PORT))
        case SUB_VCP_FC_DP1_EDID:
			DPEDID_READ();		    
            break;		
#endif
//DFM rev05 patch note 3>>
#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))//DFM rev05 patch note 3
		case SUB_VCP_FC_MHL1_EDID:
			MHLEDID_READ();
			break;
#endif		
#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))//DFM rev05 patch note 3
		case SUB_VCP_FC_MHL2_EDID:
			MHL2EDID_READ();
			break;
#endif		
//DFM rev05 patch note 3<<

        default:
            break;
    }  
    
    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x20;//32 bytes
    g_ucDdcciTxBuf[(g_ucDdcciTxBuf[_DDC_LENGTH] & 0x7f) + 2] = UserCommonDdcciCalCheckSum();    
    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);

}



// 20111220 by jerry, <<
//===================================
//REDIDWAY = 52 45 44 49 44 57 41 59
//Sending Command is REDIDWAY "51 8A 01 FE 52 45 44 49 44 57 41 59"
//IDFLH = 49 44 46 4C 48 
//Received data is IDFLH "6E 88 02 00 FE 49 44 46 4C 48 05"
//IDXPP = 49 44 58 50 50 
//Received data is IDXPP "6E 88 02 00 FE 49 44 58 50 50 1F"
//===================================
void TPVFCReplyEDIDStatus(void)
{        
	g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
	g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x08;
	g_ucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
	g_ucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
	g_ucDdcciTxBuf[_DDCCI_SINK_OPCODE] = CMD_FC_TPVFactory;
#if 1
	g_ucDdcciTxBuf[5]='I';
	g_ucDdcciTxBuf[6]='D';
	g_ucDdcciTxBuf[7]='X';		
	g_ucDdcciTxBuf[8]='P';
	g_ucDdcciTxBuf[9]='P';
#else
	g_ucDdcciTxBuf[5]='I';
	g_ucDdcciTxBuf[6]='D';
	g_ucDdcciTxBuf[7]='F';
	g_ucDdcciTxBuf[8]='L';
	g_ucDdcciTxBuf[9]='H';
#endif
	g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = UserCommonDdcciCalCheckSum();
	ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}


//--------------------------------------------------
// Description  : TPV Factory Command CRC calculation for HDCP
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVFCHdcpCrcCheck(void)
{
#if(_DIGITAL_PORT_SUPPORT == _ON)
    WORD nCRC = 0;
    BYTE ucI=0,ucJ=0;
		
    if(bAocFactoryHdcpWriteStart == _FALSE)
    {
        return;
    }

    bAocFactoryHdcpWriteStart = _FALSE;
	for(ucI=0; ucI<(376/8); ucI++)
	{
		HDCP_READ(ucI*8);
		for(ucJ=0; ucJ<8; ucJ++)
			nCRC = TPVFCCrc16(pData[ucJ], nCRC);
	}
    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x08;
    g_ucDdcciTxBuf[_DDCCI_COMMAND] = _DDCCI_CMD_GET_VCP_FEATURE_REPLY;
    g_ucDdcciTxBuf[_DDCCI_RESULT_CODE] = 0x00;
    g_ucDdcciTxBuf[_DDCCI_SINK_OPCODE] = g_ucDdcciRxBuf[_DDCCI_SOURCE_OPCODE];
	UserCommonDdcciSetVCPReplyValue(SUB_VCP_FC_READ_HDCP_CRC, nCRC, 0);
    g_ucDdcciTxBuf[_DDCCI_PRESENT_LOW_BYTE + 1] = UserCommonDdcciCalCheckSum();
    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);

#endif
}


//--------------------------------------------------
// Description  : TPV Factory Command CRC calculation
// Input Value  : None
// Output Value : CRC
//--------------------------------------------------
WORD TPVFCCrc16(BYTE nData, WORD nCRC)
{
    BYTE nMask;
    bit fFeedback;
    for (nMask= 0x80; nMask; nMask >>= 1)
    {
        fFeedback= (bit)(((nCRC & 0x8000) ? 1 : 0) ^ ((nMask & nData) ? 1 : 0));
        nCRC <<= 1;
        if (fFeedback)
        {
            nCRC ^= 0x1021;
        }
    }

    return nCRC;
}

//--------------------------------------------------
// Description  : TPV Factory Command Tx command 
// Input Value  : None
// Output Value : checksum
//--------------------------------------------------
void TPVFCReplyCommand(BYTE ucResult, BYTE ucLength)
{
    WORD usCRC = 0;
    BYTE i = 0;

    for(i = 0; i < ucLength; i++ )
    {
        usCRC = TPVFCCrc16(g_ucDdcciRxBuf[_FC_BYTE4 + i], usCRC);
    }

    g_ucDdcciTxBuf[_DDCCI_SOURCE] = _DDCCI_DEST_ADDRESS;
    g_ucDdcciTxBuf[_DDCCI_LENGTH] = _DDCCI_CONTROL_STATUS_FLAG | 0x03;
    g_ucDdcciTxBuf[_DDCCI_COMMAND] = ucResult;
    g_ucDdcciTxBuf[3] = (BYTE)((usCRC&0xff00)>>8);
    g_ucDdcciTxBuf[4] = (BYTE)(usCRC&0x00ff);
    g_ucDdcciTxBuf[5] = UserCommonDdcciCalCheckSum();

    ScalerMcuDdcciSendData(g_ucDdcciTxBuf);
}




//--------------------------------------------------
//DFM Mode
//--------------------------------------------------

//--------------------------------------------------
// Description  : DFM mode Initial
//add to last line of UserInterfaceInitial()  , just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVDFMInitial(void)
{
	
	if(GET_FACTORY_DFM_MODE() == _PRODUCT_ON)
	{
		bProductModeFlag = _ON;
		FC_DFM_INITIAL();
#if (_AUDIO_SUPPORT == _ON)
		FC_AUDIO_VOLUMN();
#endif
	}
	else
	{
		bProductModeFlag = _OFF;
	}
	SET_FACTORY_MODE(_OFF);//AC ON Factory have to turn OFF//DFM rev02 patch note 2
}
//--------------------------------------------------
// Description  : DFM mode reset to off
//add to bottom line of Factory Reset process ,just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVDFMFactoryRest(void)
{
//DFM rev02 patch note 9>>
    if((TPVDFMModeFlag()==_ON) || (GET_FACTORY_BURNIN() == _ON))
    {
        SET_FACTORY_BURNIN(_OFF);//by jerry DFM rev02 patch note 3
		TPVDFMSet(_OFF);
		//NVRamRestorePanelUsedTimeData();
	}
//DFM rev02 patch note 9<<	
}

//--------------------------------------------------
// Description  : DFM mode flag Check
//for check DFM status check , Call many times depend on project
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit TPVDFMModeFlag(void)
{
	return bProductModeFlag;
}

//--------------------------------------------------
// Description	: WP check depend on Cable &DFM mode 
//add to _MODE_STATUS_NOSIGNAL status of AOC2011OsdSystemFlowProc()  and when SysModeGetModeStateChange()==High
//just call once
// Input Value	: None
// Output Value : None
//--------------------------------------------------
bit TPVDFMCableWPCheck(void)//DFM rev02 patch note 7
{
	BYTE ucCable_Status=0x00;
    static BYTE ucISBacklightMax = 0;

#if (_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_A0_INPUT_PORT);
#endif	

#if (_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D0_INPUT_PORT);
#endif	
#if (_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
	ucCable_Status |= SysSourceGetCableDetect(_D1_INPUT_PORT);
#endif

	if(ucCable_Status == 0)//all cable disconnect
	{
#if (DFM_DDC_WRITE_PORT == _DFM_D0_PORT)
		ScalerMcuDdcciSwitchPort(_DDCCI_MODE,_D0_INPUT_PORT);
#elif (DFM_DDC_WRITE_PORT == _DFM_D1_PORT)
		ScalerMcuDdcciSwitchPort(_DDCCI_MODE,_D1_INPUT_PORT);
#elif (DFM_DDC_WRITE_PORT == _DFM_A0_PORT)
		ScalerMcuDdcciSwitchPort(_DDCCI_MODE,_A0_INPUT_PORT);
#endif
//DFM rev03 patch note 3>>
/*
		if((TPVDFMModeFlag()== _OFF) && (CheckFactroyMode()==_FALSE))
		{
			FC_EDID_EEPROM_WP_DISABLE();//DFM rev02 patch note 8		
		}
*/
	
#if ((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
		if(TPVDFMModeFlag()== _ON)
		{		
			if((TPVDFMModeFlag()== _ON)&&((GET_VGA_EDID_CHECK()==_TRUE)||(GET_DVI_EDID_CHECK()==_TRUE)||(GET_HDMI_EDID_CHECK()==_TRUE))&&(bEDID2EEPROM_OVERWRITE==_FALSE))
			{
				CTPVFCReloadEdid();
			}
			FC_EDID_EEPROM_WP_ENABLE();//DFM rev02 patch note 8
		}
		else
#endif
		{		
			FC_EDID_EEPROM_WP_ENABLE();//DFM rev02 patch note 8
		}
//DFM rev03 patch note 3<<
//DFM rev02 patch note 7>>
		if(DFM_BURN_IN() == _ON)
		{
		    if(ucISBacklightMax == 0)
            {      
                UserAdjustBacklightPercent(100);
                ucISBacklightMax = 1;
            }
		    UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);//Robert Wang 20130111 for Burning LED is Org
            UserInterfacePanelPowerAction(_BACKLIGHT_ON);//ada.chen 20150519 modify Burning AC ON after flicker issue
            ScalerDDomainBackgroundEnable(_ENABLE);
            ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
            TPVFactFuncBurnInPattern();
#if(_AUDIO_EXTERNAL_AMP_SUPPORT == _ON) //for line in               
			UserAdjustAudioVolume(GET_OSD_VOLUME());
#endif                
           // UserInterfacePanelPowerAction(_BACKLIGHT_ON);
			return _TRUE;
		}
//DFM rev02 patch note 7<<
	}
	else //anyone connected
	{
		FC_EDID_EEPROM_WP_ENABLE();//DFM rev02 patch note 8
		if(ucISBacklightMax == 1)
        {
            UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            ucISBacklightMax = 0;
        }      
	}
//fast enter Powersaving
DebugMessageOsd("4.bProductModeFlag",bProductModeFlag);
	if(bProductModeFlag==_ON)
	{							
		TIMER_NOSIGNAL();	
		TIMER_SAVING();
		return _TRUE;
	}
	else
	{
		if(ucISBacklightMax == 1)
        {
            UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
            ucISBacklightMax = 0;
        }      
	
		return _FALSE;
	}	
    if(ucISBacklightMax == 1)
    {
        UserAdjustBacklightPercent(GET_OSD_BACKLIGHT());
        ucISBacklightMax = 0;
    }      

	return _FALSE;//DFM rev02 patch note 7
}

//--------------------------------------------------
// Description  : DC power ON DFM mode clear
//add to _MODE_STATUS_INITIAL case of  AOC2011OsdSystemFlowProc() ,just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVDFMPowerRecall(void)
{
	if((bProductModeFlag == _ON) || (GET_FACTORY_BURNIN() == _ON))
	{
		DFM_POWERON_REALL();
		BACKLIGHTTIME_INITIAL();//(DFM rev6 patch note 6)
		//TPVDFMFactoryRest();//already do in DFM_POWERON_REALL()
	}
	bTpvDfmLedNotice = _LOW;
}


//--------------------------------------------------
// Description  : DFM mode Logo On Check
//add before Show Logo , just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit TPVDFMLogoOnCheck(void)
{
	if((bProductModeFlag==_ON)||(GET_FACTORY_MODE() ==_ON)||(GET_FACTORY_FORCE_LOGO_OFF()==_ON))//DFM rev04 patch note 2
		return _FALSE;
	else
		return _TRUE;
}
//--------------------------------------------------
// Description  : DFM mode Led indication
//add before Keypad Led
//just call once
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit TPVDFMKeyPadLedCheck(BYTE ucKeyPadLed)
{
#if ((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
    if((bEDID2EEPROM_VGA_Fail == _TRUE)||(bEDID2EEPROM_DVI_Fail == _TRUE)||(bEDID2EEPROM_HDMI_Fail == _TRUE))//Hillybw 20120207
    {
        return _TRUE;
    }
#endif
	if (ucKeyPadLed == _LED_POWER_OFF)
		bTpvDfmLedNotice=_LOW;
	
	return bTpvDfmLedNotice;
}

//--------------------------------------------------
// Description  : DFM mode by pass Auto Config
//add to  in front of Auto config process 
//Call many times depend on project
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit TPVDFMAutoConfigByPass(void)
{
	if((bProductModeFlag == _ON) || (GET_FACTORY_MODE()==_ON))
		return _TRUE;
	else
		return _FALSE;
}


//--------------------------------------------------
// Description  : DFM mode switch
//add to OSD OperationTable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void TPVDFMSet( bit bOnOff)
{
	if(bOnOff == _OFF)
	{
		SET_FACTORY_DFM_MODE(_PRODUCT_OFF);
		bProductModeFlag = _OFF;
	}
	else
	{
		SET_FACTORY_DFM_MODE(_PRODUCT_ON);
		bProductModeFlag = _ON;
	}
	TPVNVRamSaveFactoryDate();	
}
#if (_DFM_BYPASS_FORCE_PANELOFF == _ON)
//--------------------------------------------------
// Description  : DFM mode disable panel power  off
//add to first line of UserCommonInterfaceOsdResetProc()
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit TPVDFMForcePanelOff(void)
{
	if((TPVDFMModeFlag()==_OFF))
	{
		return _FALSE;
	}
	return _TRUE;
}
#endif
//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------

void TPVDFMForce2PowerOff(BYTE ucCmd)
{
	if((ucCmd == 5) && (SysPowerGetPowerStatus() != _POWER_STATUS_OFF))
	{
		SET_FORCE_POW_SAV_STATUS(_FALSE);
		SysPowerSetTargetPowerStatus(_POWER_STATUS_OFF);
	}

}

#if (_PANEL_VCOM_ADJUST_FUNCTION==_ON)

//--------------------------------------------------
//VCOM Mode
//--------------------------------------------------

void TPVFCCheckPanelVcom(void)
{
	BYTE VCMAddr=0x00;
	
	SET_SW_IIC_STATUS(_I2C_LINE_PANEL);
	
	ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x02, 1, &VCMAddr);
	ScalerMcuIICRead(_PANEL_VCOM_I2C_ADDRESS, 1, 0x00, 1, &VCMAddr);
    	
    if (VCMAddr != GET_FACTORY_VCOM())
    {
        VCMAddr=0x80;
		ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x02, 1, &VCMAddr);
        VCMAddr = GET_FACTORY_VCOM();
		ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x00, 1, &VCMAddr);
    }
	SET_SW_IIC_STATUS(_I2C_LINE_NVRAM);
}
#if(0)
BYTE TPVFCGetPanelVcom(void)
{
	return GET_FACTORY_VCOM();
}
#endif
void TPVFCSetPanelVcom(BYTE setPanelVcom)
{
	BYTE VCMAddr=0x80;

	SET_FACTORY_VCOM(setPanelVcom);
	SET_SW_IIC_STATUS(_I2C_LINE_PANEL);
	
	ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x02, 1, &VCMAddr);
	VCMAddr = GET_FACTORY_VCOM();
	ScalerMcuIICWrite(_PANEL_VCOM_I2C_ADDRESS, 1, 0x00, 1, &VCMAddr);
	SET_SW_IIC_STATUS(_I2C_LINE_NVRAM);
	TPVNVRamSaveFactoryDate();
}
#endif


//DFM rev02 patch note 7>>
//--------------------------------------------------
// Description  : 
// Input Value  : 
// Output Value : 
//--------------------------------------------------
void TPVFactFuncBurnInPattern(void)
{
    BYTE code tPatternBurnIn[3][5] = 
    {
        {255, 0, 255, 0, 0},
        {255, 0, 0, 255, 0},
        {255, 0, 0, 0, 255},
    };
    static BYTE g_ucColorTempBurnin = 0;

//#if ((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
    UserInterfaceKeyPadLedControl(_LED_TYPE_1); // for led contron in burn in
//#endif

	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);//DFM rev04 patch note 3
    
    ScalerDDomainBackgroundSetColor(tPatternBurnIn[0][g_ucColorTempBurnin%0x05], tPatternBurnIn[1][g_ucColorTempBurnin%0x05], tPatternBurnIn[2][g_ucColorTempBurnin%0x05]);
    g_ucColorTempBurnin++;
    ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_BURN_IN);
}
//DFM rev02 patch note 7<<


//DFM rev04 patch note 1>>
#if((_TPV_FACTORY_SELECT ==_TPV_WH_FACTORY)||(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY))
void CEdid2EepromVGA(void)
{
    BYTE cnt0 = 0;
    WORD usCheckSumVGA = 0;
	BYTE DDCRAM_TMP[128]={0};

	// disable DDC
	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);
	UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 8, pData, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
		
	//check EDID EEPROM 	 
    if((pData[0] != 0x00)||(pData[1] != 0xff)||(pData[2] != 0xff)||(pData[3] != 0xff)
    ||(pData[4] != 0xff)||(pData[5] != 0xff)||(pData[6] != 0xff)||(pData[7] != 0x00))
    {
		//check EDID fail, reload EDID from code table		
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_A0, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6
        bEDID2EEPROM_OVERWRITE=_TRUE;// only once write eeprom in Ac on/off 
    }
    else// Check edid eeprom 
    {
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 127, DDCRAM_TMP, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6
		//check checksum >>
		for(cnt0 = 0; cnt0 < 127; cnt0++)
		{
		    usCheckSumVGA += DDCRAM_TMP[cnt0];
		}
		usCheckSumVGA = (256- usCheckSumVGA%256)%256;
		ScalerTimerDelayXms(1);
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x7F, 1, 1, pData, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO);//DFM rev02 patch note 6

		if((BYTE)(usCheckSumVGA) != pData[0])
		{
			//UserInterfaceSetEmbeddedEDIDData();??
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_A0, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);//DFM rev02 patch note 6
			bEDID2EEPROM_VGA_Fail = _TRUE;//error:Green LED on
		}		
		else
		{
			SET_VGA_EDID_CHECK(_FALSE);
			TPVNVRamSaveFactoryDate();
		}
    }		 
			
	SET_SW_IIC_STATUS(_I2C_LINE_NVRAM); 			
	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);

}
void CEdid2EepromDVI(void)
{
    BYTE cnt0 = 0;
    WORD usCheckSumDVI = 0;
	BYTE DDCRAM_TMP[128]={0};
	
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
	ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
	UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 8, pData, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
	ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
	UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 8, pData, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
#endif		

    if((pData[0] != 0x00)||(pData[1] != 0xff)||(pData[2] != 0xff)||(pData[3] != 0xff)
    ||(pData[4] != 0xff)||(pData[5] != 0xff)||(pData[6] != 0xff)||(pData[7] != 0x00))
    {
#if(_D0_INPUT_PORT_TYPE==_D0_DVI_PORT)
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D0, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D0, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif
#elif(_D1_INPUT_PORT_TYPE==_D1_DVI_PORT)
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D1, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D1, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif
#endif
        bEDID2EEPROM_OVERWRITE=_TRUE;// only once write eeprom in Ac on/off 
    }
    else// Check edid eeprom 
	{
#if(_D0_INPUT_PORT_TYPE==_D0_DVI_PORT)
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, DDCRAM_TMP, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, DDCRAM_TMP, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
#endif		
#elif(_D1_INPUT_PORT_TYPE==_D1_DVI_PORT)
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, DDCRAM_TMP, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, DDCRAM_TMP, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
#endif		
#endif
		//check checksum >>
		for(cnt0 = 0; cnt0 < 127; cnt0++)
		{
			usCheckSumDVI += DDCRAM_TMP[cnt0];
		}
		usCheckSumDVI = (256- usCheckSumDVI%256)%256;
		ScalerTimerDelayXms(1);

#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x7F, 1, 1, pData, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x7F, 1, 1, pData, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
#endif		

		if((BYTE)(usCheckSumDVI) != pData[0])
		{
#if(_D0_INPUT_PORT_TYPE==_D0_DVI_PORT)
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D0, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D0, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif
#elif(_D1_INPUT_PORT_TYPE==_D1_DVI_PORT)
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D1, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D1, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif
#endif
			bEDID2EEPROM_DVI_Fail = _TRUE;//error:Green LED on
		}		
		else
		{
			SET_DVI_EDID_CHECK(_FALSE);
			TPVNVRamSaveFactoryDate();
		}
	}

	// enable DDC
#if(DFM_DVI1_DDC_CHANNEL == _DDC2)
	ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#elif(DFM_DVI1_DDC_CHANNEL == _DDC3)
	ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif				


}

void CEdid2EepromHDMI(void)
{
    BYTE cnt0 = 0;
    BYTE cnt1 = 0;
    WORD usCheckSumHDMI128 = 0;
    WORD usCheckSumHDMI256 = 0;
	BYTE DDCRAM_TMP[256]={0};
	
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
	ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
	UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 8, pData, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
	ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
	UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 8, pData, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
#endif		
	
    if((pData[0] != 0x00)||(pData[1] != 0xff)||(pData[2] != 0xff)||(pData[3] != 0xff)
    ||(pData[4] != 0xff)||(pData[5] != 0xff)||(pData[6] != 0xff)||(pData[7] != 0x00))    
    {
#if(_D0_INPUT_PORT_TYPE==_D0_HDMI_PORT)
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D0, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D0, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif

#elif(_D1_INPUT_PORT_TYPE==_D1_HDMI_PORT)
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D1, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D1, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif
#endif
        bEDID2EEPROM_OVERWRITE=_TRUE;// only once write eeprom in Ac on/off     

    }
    else// Check edid eeprom 
    {
#if(_D0_INPUT_PORT_TYPE==_D0_HDMI_PORT)
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 255, DDCRAM_TMP, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 255, DDCRAM_TMP, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
#endif		
#elif(_D1_INPUT_PORT_TYPE==_D1_HDMI_PORT)
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 255, DDCRAM_TMP, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 255, DDCRAM_TMP, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
#endif		
#endif
		//check checksum >>
		for(cnt0 = 0; cnt0 < 127; cnt0++)
		{
		    usCheckSumHDMI128 += DDCRAM_TMP[cnt0];
		}
		usCheckSumHDMI128 = (256- usCheckSumHDMI128%256)%256;

		for(cnt1 = 0; cnt1 < 127; cnt1++)
		{
		    usCheckSumHDMI256 += DDCRAM_TMP[128+cnt1];
		}
		usCheckSumHDMI256 = (256- usCheckSumHDMI256%256)%256;
		
		ScalerTimerDelayXms(1);
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x7F, 1, 1, &pData[0], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0xFF, 1, 1, &pData[1], _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x7F, 1, 1, &pData[0], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
		UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0xFF, 1, 1, &pData[1], _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO);
#endif		
		if(((BYTE)(usCheckSumHDMI128) != pData[0])||((BYTE)(usCheckSumHDMI256) != pData[1]))
		{
#if(_D0_INPUT_PORT_TYPE==_D0_HDMI_PORT)
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D0, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D0, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif
#elif(_D1_INPUT_PORT_TYPE==_D1_HDMI_PORT)
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D1, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
			UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D1, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif
#endif
			bEDID2EEPROM_HDMI_Fail = _TRUE;//error:Green LED on
		}		
		else
		{
			SET_HDMI_EDID_CHECK(_FALSE);
			TPVNVRamSaveFactoryDate();
		}
		 
		 
    }

	// enable DDC
#if(DFM_HDMI1_DDC_CHANNEL == _DDC2)
   ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#elif(DFM_HDMI1_DDC_CHANNEL == _DDC3)
   ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif		

}

void CTPVFCReloadEdid(void)
{
	bEDID2EEPROM_VGA_Fail = _FALSE;//default is _FALSE
	bEDID2EEPROM_DVI_Fail = _FALSE;//default is _FALSE
	bEDID2EEPROM_HDMI_Fail = _FALSE;//default is _FALSE

	FC_EDID_EEPROM_WP_DISABLE();//DFM rev02 patch note 8

	if(GET_VGA_EDID_CHECK()==_TRUE)
		CEdid2EepromVGA();

	if(GET_DVI_EDID_CHECK()==_TRUE)
		CEdid2EepromDVI();

	if( GET_HDMI_EDID_CHECK()==_TRUE)
		CEdid2EepromHDMI();

	FC_EDID_EEPROM_WP_ENABLE();//DFM rev02 patch note 8

}


#endif

#if(_TPV_FACTORY_SELECT ==_TPV_BJ_FACTORY)
void CFCEdid2EepromHotKey(void)
{	
	if((TPVDFMModeFlag()== _ON) && ((SysModeGetModeState()== _MODE_STATUS_NOSIGNAL)||(SysModeGetModeState()== _MODE_STATUS_POWER_SAVING)))
	{  
		FC_EDID_EEPROM_WP_DISABLE();//DFM rev02 patch note 8
//VGA port
		ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);

#if(((_D0_DDC_CHANNEL_SEL == _DDC2))||((_D1_DDC_CHANNEL_SEL == _DDC2)))
		ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);
#endif

#if(((_D0_DDC_CHANNEL_SEL == _DDC3))||((_D1_DDC_CHANNEL_SEL == _DDC3)))
		ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);
#endif		


//VGA port
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_A0, _IIC_FOR_DDC1, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
 
//DVI port
#if(((_D0_DDC_CHANNEL_SEL == _DDC2)&&(_D0_INPUT_PORT_TYPE==_D0_DVI_PORT)))
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D0, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);

#elif((_D1_DDC_CHANNEL_SEL == _DDC2)&&(_D1_INPUT_PORT_TYPE==_D1_DVI_PORT))
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D0, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);

#elif((_D0_DDC_CHANNEL_SEL == _DDC3)&&(_D0_INPUT_PORT_TYPE==_D0_DVI_PORT))
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D1, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);

#elif((_D1_DDC_CHANNEL_SEL == _DDC3)&&(_D1_INPUT_PORT_TYPE==_D1_DVI_PORT))
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 128, tEDID_TABLE_D1, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif		

//HDMI port
#if(((_D0_DDC_CHANNEL_SEL == _DDC2)&&(_D0_INPUT_PORT_TYPE==_D0_HDMI_PORT)))
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D0, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif		
#if((_D1_DDC_CHANNEL_SEL == _DDC2)&&(_D1_INPUT_PORT_TYPE==_D1_HDMI_PORT))
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D0, _IIC_FOR_DDC2, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif		
#if((_D0_DDC_CHANNEL_SEL == _DDC3)&&(_D0_INPUT_PORT_TYPE==_D0_HDMI_PORT))
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D1, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif		
#if((_D1_DDC_CHANNEL_SEL == _DDC3)&&(_D1_INPUT_PORT_TYPE==_D1_HDMI_PORT))
		UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 256, tEDID_TABLE_D1, _IIC_FOR_DDC3, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
#endif		

//DFM rev02 patch note 6<<
		SET_VGA_EDID_CHECK(_TRUE);
		SET_DVI_EDID_CHECK(_TRUE);
		SET_HDMI_EDID_CHECK(_TRUE);

        TPVNVRamSaveFactoryDate();
		
	   SET_SW_IIC_STATUS(_I2C_LINE_NVRAM);			   

	   ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);
#if((_D0_DDC_CHANNEL_SEL == _DDC2)||(_D1_DDC_CHANNEL_SEL == _DDC2))
		ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);
#endif
#if((_D0_DDC_CHANNEL_SEL == _DDC3)||(_D1_DDC_CHANNEL_SEL == _DDC3))
		ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);
#endif

		FC_EDID_EEPROM_WP_ENABLE();//DFM rev02 patch note 8
		
	}		

	CTPVFCReloadEdid();
}
#endif
//DFM rev04 patch note 1<<

//DFM rev05 patch note 2>>
void TPVDFMInternalADCCheck(void)
{
#if((_ADC_SELF_CALIBRATION == _ON) && (_A0_INPUT_PORT_TYPE == _A0_VGA_PORT))
    if(GET_INTERNAL_AUTOCOLOR() == _FAIL)
    {
    	if(ScalerAutoDoWhiteBalance(_AUTO_CALIBRATE_RGB) == _AUTO_SUCCESS)
    	{
            ScalerAutoGetAutoColorResult(&g_stAdcData);

            DebugMessageOsd("ADCGainR", g_stAdcData.ucAdcGainMSB[0]);
            DebugMessageOsd("ADCGainG", g_stAdcData.ucAdcGainMSB[1]);
            DebugMessageOsd("ADCGainB", g_stAdcData.ucAdcGainMSB[2]);

            DebugMessageOsd("ADCGainR", g_stAdcData.ucAdcOffsetMSB[0]);
            DebugMessageOsd("ADCGainG", g_stAdcData.ucAdcOffsetMSB[1]);
            DebugMessageOsd("ADCGainB", g_stAdcData.ucAdcOffsetMSB[2]);

            UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
            SET_INTERNAL_AUTOCOLOR(_SUCCESS);
            TPVNVRamSaveFactoryDate();
    	}
    	else
    	{
            // Download adc data from NVRam
            UserCommonNVRamLoadADCSetting(_COLOR_SPACE_RGB);
    	}
    }
#endif
}
//DFM rev05 patch note 2<<


#endif //end of #if ((_FACTORY_MODE_OWNER == _OWNER_TPV))

