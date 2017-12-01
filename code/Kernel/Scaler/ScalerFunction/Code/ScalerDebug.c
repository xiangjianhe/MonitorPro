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
// ID Code      : ScalerDebug.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_DEBUG__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _DATA_OUT_COUNT                       0x05

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
#warning "DEBUG MESSAGE SUPPORT ON!!"
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
bit g_bRunCommand = _FALSE;
BYTE idata g_ucDdcciData[5] = {0};
BYTE idata g_ucDdcciCommandNumber = 0;

bit g_bDDCCIDebugMode = _DEBUG_MODE;

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
BYTE g_usDebugCount = 0;
bit idata g_bDebugMessageEven = _FALSE;
WORD g_usFilterPro = 0;
bit g_bFwHalt = _FALSE;
bit g_bDebugMessageStart = _FALSE;
BYTE idata g_pDebugMessageBUF[4] = {0};
#endif // End of #if(_DEBUG_MESSAGE_SUPPORT == _ON)


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerSelectDDCCIDebugMode(EnumDDCCIDebugMode enumMode);

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
void ScalerDebugMessage(BYTE *pArray1, DWORD pArray2);
#endif // End of #if(_DEBUG_MESSAGE_SUPPORT == _ON)

void ScalerDebugIntProc_EXINT1(void);
void ScalerDebug(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
void ScalerSelectDDCCIDebugMode(EnumDDCCIDebugMode enumMode)
{
    g_bDDCCIDebugMode = enumMode;
}

//--------------------------------------------------
// Description  : Debug Message process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if(_DEBUG_MESSAGE_SUPPORT == _ON)
void ScalerDebugMessage(BYTE *pArray1, DWORD pArray2)
{
    BYTE ucCnt = 0;
    BYTE ucLength = 0;
    BYTE ucCheckSum = 0;
    BYTE ucIndex = 0;

    if(g_ucDdcciData[0] == 0x55)
    {
        g_bDebugMessageEven = _TRUE;
    }

    if(g_bDebugMessageEven == _FALSE)
    {
        return;
    }

    if(*pArray1 == 0)
    {
        MCU_I2C_IRQ_CTRL2_FF2A |= 0x20;
        MCU_I2C_IRQ_CTRL2_FF2A |= 0x40; // Reset IIC Data Buffer
        MCU_I2C_DATA_OUT_FF26 = 0xFC;
        return;
    }

    if((g_usFilterPro & 0xF800) == 0xC800)
    {
        if(g_usFilterPro & (1 << (pArray1[0] - '0')) == 0)
        {
            return;
        }
    }

    g_bDebugMessageStart = 0;
    g_bFwHalt = 1;

    MCU_I2C_IRQ_CTRL2_FF2A |= 0x20;
    MCU_I2C_IRQ_CTRL2_FF2A |= 0x40; // Reset IIC Data Buffer
    MCU_I2C_DATA_OUT_FF26 = 0xF1;

    for(ucCheckSum = 0; ucCheckSum < 4; ucCheckSum++)
    {
        g_pDebugMessageBUF[ucCheckSum] = 0;
    }

    do
    {
        if(g_bRunCommand)
        {
            MCU_I2C_IRQ_CTRL2_FF2A |= 0x20;
            ucCnt = 0;

            switch(g_ucDdcciData[0])
            {
                case 0x20: // Handshake Setting
                case 0x55:

                    if(g_ucDdcciData[1] == 0x5A)
                    {
                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            MCU_I2C_DATA_OUT_FF26 = 0xE7;

                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x01) && ((ucCnt++) < _DATA_OUT_COUNT));
                    }
                    else if(g_ucDdcciData[1] == 0xA5)
                    {
                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            MCU_I2C_DATA_OUT_FF26 = 0xEC;

                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x01) && ((ucCnt++) < _DATA_OUT_COUNT));
                    }
                    else
                    {
                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            MCU_I2C_DATA_OUT_FF26 = 0xF1;

                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x01) && ((ucCnt++) < _DATA_OUT_COUNT));
                    }

                    break;

                case 0x25: // Debug Message Start

                    if(g_ucDdcciData[1] == 0)
                    {
                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            ucLength = 0; // Total Length
                            ucIndex = 0;
                            ucCheckSum = 0x00; // Initial checksum

                            do
                            {
                                ucCheckSum += pArray1[ucLength];

                            }
                            while((pArray1[ucLength++] != 0) && (ucLength < 240)); // To count the length of pArray1 and checksum

                            g_pDebugMessageBUF[0] = (BYTE)(pArray2 >> 24);
                            g_pDebugMessageBUF[1] = (BYTE)(pArray2 >> 16);
                            g_pDebugMessageBUF[2] = (BYTE)(pArray2 >> 8);
                            g_pDebugMessageBUF[3] = (BYTE)(pArray2);
                            ucLength = ucLength - 1;

                            MCU_I2C_DATA_OUT_FF26 = 0xFA;
                            MCU_I2C_DATA_OUT_FF26 = 0xF5;
                            MCU_I2C_DATA_OUT_FF26 = ucLength;
                            MCU_I2C_DATA_OUT_FF26 = g_pDebugMessageBUF[0];
                            MCU_I2C_DATA_OUT_FF26 = g_pDebugMessageBUF[1];
                            MCU_I2C_DATA_OUT_FF26 = g_pDebugMessageBUF[2];
                            MCU_I2C_DATA_OUT_FF26 = g_pDebugMessageBUF[3];

                            ucIndex = ucCheckSum;
                            ucCheckSum = 0x0F;
                            ucCheckSum = ucCheckSum + ucLength + g_pDebugMessageBUF[0] + g_pDebugMessageBUF[1] + g_pDebugMessageBUF[2] + g_pDebugMessageBUF[3];

                            g_pDebugMessageBUF[0] = ucCheckSum + ucIndex; // Save checksum for all string and data
                            MCU_I2C_DATA_OUT_FF26 = g_pDebugMessageBUF[0]; // Checksum for all string and data
                            MCU_I2C_DATA_OUT_FF26 = ucCheckSum + g_pDebugMessageBUF[0];

                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x09) && ((ucCnt++) < _DATA_OUT_COUNT));
                    }
                    else
                    {
                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            ucIndex = (g_ucDdcciData[1] - 1) * 15;
                            ucCheckSum = g_ucDdcciData[1] + 0x0F;
                            g_pDebugMessageBUF[0] = 1;

                            do
                            {
                                MCU_I2C_DATA_OUT_FF26 = pArray1[ucIndex];
                                ucCheckSum += pArray1[ucIndex];
                                ucIndex++;
                                g_pDebugMessageBUF[0] = g_pDebugMessageBUF[0] + 1;

                            }
                            while((ucIndex < (g_ucDdcciData[1] * 15)) && (pArray1[ucIndex] != 0));

                            MCU_I2C_DATA_OUT_FF26 = ucCheckSum;

                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != g_pDebugMessageBUF[0]) && ((ucCnt++) < _DATA_OUT_COUNT));
                        g_bDebugMessageStart = 1;
                    }

                    break;

                case 0x2A: // Debug Message End

                    if(g_bDebugMessageStart)
                    {
                        g_bDebugMessageStart = 0; // Debug Message End
                        g_bFwHalt = 0;
                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            MCU_I2C_DATA_OUT_FF26 = 0xF7;

                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x01) && ((ucCnt++) < _DATA_OUT_COUNT));
                    }

                    break;

                case 0x2F: // Debug Message Event finsih

                    do
                    {
                        MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                        MCU_I2C_DATA_OUT_FF26 = 0xF5;

                    }
                    while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x01) && ((ucCnt++) < _DATA_OUT_COUNT));

                    g_bDebugMessageEven = 0;
                    g_bFwHalt = 0;
                    MCU_I2C_IRQ_CTRL2_FF2A &= 0xBF;
                    break;

                default:
                    break;
            }

            g_bRunCommand = 0;
            g_ucDdcciCommandNumber = 0;

            MCU_I2C_IRQ_CTRL2_FF2A &= 0xDF;

#if(_DEBUG_DDC_CHANNEL_SEL == _DDC3)
            MCU_HDMI_DDC_CTRL2_FF2E &= 0xFE;
#elif(_DEBUG_DDC_CHANNEL_SEL == _DDC2)
            MCU_DVI_DDC_CTRL2_FF20 &= 0xFE;
#else
            MCU_ADC_DDC_CTRL2_FF1D &= 0xFE;
#endif
        }
    }
    while(g_bFwHalt != 0);

    g_bDebugMessageStart = 0;
    g_bFwHalt = 0;
}
#endif // End of #if(_DEBUG_MESSAGE_SUPPORT == _ON)

void ScalerDebugIntProc_EXINT1(void) using 2
{
    BYTE ucTempBuf = 0;
    MCU_I2C_STATUS2_FF29 &= 0xCF;

    if(!g_bRunCommand)
    {
        ucTempBuf = MCU_I2C_STATUS_FF27;

        if(ucTempBuf & 0x02)
        {
            // Clear SUB_I Flag
            MCU_I2C_STATUS_FF27 = 0xBD;

            g_ucDdcciCommandNumber = 0;
            g_ucDdcciData[0] = MCU_I2C_SUB_IN_FF24;

            // Host write Enable
            MCU_I2C_IRQ_CTRL2_FF2A &= 0xDF;
        }

        if(ucTempBuf & 0x04)
        {
            // Avoid buffer overflow
            if((g_ucDdcciCommandNumber + 1) < sizeof(g_ucDdcciData))
            {
                g_ucDdcciCommandNumber++;
            }
            g_ucDdcciData[g_ucDdcciCommandNumber] = MCU_I2C_DATA_IN_FF25;

            // Clear D_IN_I Flag
            MCU_I2C_STATUS_FF27 = 0xBB;
        }

        if((ucTempBuf & _BIT4) == _BIT4)
        {
            MCU_I2C_STATUS_FF27 = 0xAF;

            if(g_ucDdcciCommandNumber > 0)
            {
#if(_DEBUG_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_DDC_CTRL2_FF2E |= 0x01;
#elif(_DEBUG_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_DDC_CTRL2_FF20 |= 0x01;
#else
                MCU_ADC_DDC_CTRL2_FF1D |= 0x01;
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
                g_usDebugCount = 1;

                if(g_ucDdcciData[0] == 0x55)
                {
                    if(g_ucDdcciData[1] == 0x00)
                    {
                        g_usFilterPro = 0;
                    }
                    else
                    {
                        g_usFilterPro = ((g_ucDdcciData[1] << 8) + g_ucDdcciData[2]);
                    }
                }

                if((g_ucDdcciData[0] == 0x2F) && g_bDebugMessageEven)
                {
                    g_bDebugMessageEven = _FALSE;
                    g_bFwHalt = _FALSE;
                }
                else if((g_ucDdcciData[0] == 0x55) && (!g_bDebugMessageEven))
                {
                    g_bDebugMessageEven = _TRUE;
                }
#endif

                MCU_I2C_IRQ_CTRL2_FF2A |= 0x20;
                g_bRunCommand = _TRUE;
            }
        }
	}	
    else
    {
        MCU_I2C_STATUS_FF27 = 0xA9;
    } 
}

//--------------------------------------------------
// Description  : IC Debug Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDebug(void)
{
    BYTE ucHalt = 0;
    BYTE cnt = 0;
    BYTE ucResult = 0;
    BYTE xdata *pucFlashData = 0x0000;

    if(g_bDDCCIDebugMode == _DEBUG_MODE)
    {    
        do
        {
            if(g_bRunCommand)
            {
                cnt = 0;

                switch(g_ucDdcciData[0])
                {
                    case 0x80:
                        ucHalt = g_ucDdcciData[1];
                        break;

                    case 0x41:
                        MCU_I2C_IRQ_CTRL2_FF2A |= 0x20;

                        // CScalerRead
                        MCU_SCA_INF_CTRL_FFF3 |= 0x20;
                        MCU_SCA_INF_ADDR_FFF4 = g_ucDdcciData[1];
                        ucResult = MCU_SCA_INF_DATA_FFF5;

                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            MCU_I2C_DATA_OUT_FF26 = ucResult;

                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x01) && ((cnt++) < _DATA_OUT_COUNT));

                        break;

                    case 0x44:
                        MCU_I2C_IRQ_CTRL2_FF2A |= 0x20;

#if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

                        SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);

#if(_EEPROM_TYPE == _EEPROM_24LC16)
                        ScalerMcuIICRead(g_ucDdcciData[2], 1, g_ucDdcciData[1], 1, &ucResult);
#elif(_EEPROM_TYPE == _EEPROM_24WC64)
                        ScalerMcuIICRead(g_ucDdcciData[2], 2, ((g_ucDdcciData[4] << 8) & 0xFF00) + (((WORD)g_ucDdcciData[1]) & 0x00FF), 1, &ucResult);
#endif

#elif(_PCB_SYS_EEPROM_IIC != _NO_IIC_PIN)   // Else of #if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

#if(_EEPROM_TYPE == _EEPROM_24LC16)
                        ScalerMcuHwIICRead(g_ucDdcciData[2], 1, g_ucDdcciData[1], 1, &ucResult, _PCB_SYS_EEPROM_IIC);
#elif(_EEPROM_TYPE == _EEPROM_24WC64)
                        ScalerMcuHwIICRead(g_ucDdcciData[2], 2, ((g_ucDdcciData[4] << 8) & 0xFF00) + (((WORD)g_ucDdcciData[1]) & 0x00FF), 1, &ucResult, _PCB_SYS_EEPROM_IIC);
#endif

#endif  // End of #if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            MCU_I2C_DATA_OUT_FF26 = ucResult;
                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x01) && ((cnt++) < _DATA_OUT_COUNT));

                        break;

#if(_DEBUG_MESSAGE_SUPPORT == _ON)
                    case 0x2F: // Debug Message Event finsih
                        MCU_I2C_IRQ_CTRL2_FF2A |= 0x20;

                        do
                        {
                            MCU_I2C_IRQ_CTRL2_FF2A |= 0x40;
                            MCU_I2C_IRQ_CTRL2_FF2A &= 0xBF; // Reset IIC Data Buffer
                            MCU_I2C_DATA_OUT_FF26 = 0xF5;

                        }
                        while(((MCU_DDCCI_REMAIN_FF35 & 0x1F) != 0x01) && ((cnt++) < _DATA_OUT_COUNT));

                        MCU_I2C_IRQ_CTRL2_FF2A &= 0xDF;
                        g_bDebugMessageStart = 0;
                        g_bFwHalt = _FALSE;
                        g_bDebugMessageEven = 0;
                        break;
#endif // End of #if(_DEBUG_MESSAGE_SUPPORT == _ON)

                    case 0x3A:
                        // Read flash(if the address is max than 0xFF00, read mcu register)
                        MCU_I2C_DATA_OUT_FF26 = pucFlashData[(g_ucDdcciData[2] << 8) + g_ucDdcciData[1]];
                        break;

                    case 0x3B:
                        // Write flash(if the address is max than 0xFF00, write mcu register)
                        pucFlashData[(g_ucDdcciData[2] << 8) + g_ucDdcciData[1]] = g_ucDdcciData[3];
                        break;

                    default:
                        switch(g_ucDdcciData[0] & 0x0F) // Write command
                        {
                            case 0x00:
                                //ScalerSetByte(g_ucDdcciData[2], g_ucDdcciData[1]);
                                MCU_SCA_INF_CTRL_FFF3 |= 0x20;
                                MCU_SCA_INF_ADDR_FFF4 = g_ucDdcciData[2];
                                MCU_SCA_INF_DATA_FFF5 = g_ucDdcciData[1];
                                break;

                            case 0x01:
                            case 0x02: // For RTD & I2c Device
                                g_ucDdcciData[2] = g_ucDdcciData[1];
                                break;

                            case 0x06:
                            case 0x03: // For I2c Device
                                g_ucDdcciData[3] = g_ucDdcciData[1];
                                break;

                            case 0x05:
                                g_ucDdcciData[4] = g_ucDdcciData[1];
                                break;

                            case 0x04: // For I2c Device

                                // Disable EEPROM Write Protect
                                PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);

#if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

                                SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);

#if(_EEPROM_TYPE == _EEPROM_24LC16)
                                ScalerMcuIICWrite(g_ucDdcciData[2], 1, g_ucDdcciData[1], 1, g_ucDdcciData + 3);
#elif(_EEPROM_TYPE == _EEPROM_24WC64)
                                ScalerMcuIICWrite(g_ucDdcciData[2], 2, ((g_ucDdcciData[4] << 8) & 0xFF00) + (((WORD)g_ucDdcciData[1]) & 0x00FF), 1, g_ucDdcciData + 3);
#endif

#elif(_PCB_SYS_EEPROM_IIC != _NO_IIC_PIN)  // Else of #if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

#if(_EEPROM_TYPE == _EEPROM_24LC16)
                                ScalerMcuHwIICWrite(g_ucDdcciData[2], 1, g_ucDdcciData[1], 1, g_ucDdcciData + 3, _PCB_SYS_EEPROM_IIC);
#elif(_EEPROM_TYPE == _EEPROM_24WC64)
                                ScalerMcuHwIICWrite(g_ucDdcciData[2], 2, ((g_ucDdcciData[4] << 8) & 0xFF00) + (((WORD)g_ucDdcciData[1]) & 0x00FF), 1, g_ucDdcciData + 3, _PCB_SYS_EEPROM_IIC);
#endif

#endif  // End of #if(_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)

                                // Enable EEPROM Write Protect
                                PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);

                                break;

                            default:
                                break;
                        }
                        break;
                        
                }

                g_bRunCommand = 0;
                g_ucDdcciCommandNumber = 0;

                // Host write Enable
                MCU_I2C_IRQ_CTRL2_FF2A &= (~_BIT5);

#if(_DEBUG_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_DDC_CTRL2_FF2E &= 0xFE;
#elif(_DEBUG_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_DDC_CTRL2_FF20 &= 0xFE;
#else
                MCU_ADC_DDC_CTRL2_FF1D &= 0xFE;
#endif
            }
        }
        while(ucHalt != 0);
    }
}
