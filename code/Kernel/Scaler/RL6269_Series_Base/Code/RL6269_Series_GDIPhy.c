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
// ID Code      : RL6269_Series_GDIPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6269_SERIES_GDIPHY__

#include "ScalerFunctionInclude.h"

#if(_DIGITAL_PORT_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _MHL_1K                                 10
#define _MHL_100K                               11


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
bit bMHL2DSwitch = _FALSE;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerGDIDigitalPhySwitch(BYTE ucInputPortType);
void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect);
void ScalerGDIPhy2DSwitch(BYTE ucPortSelect);
void ScalerGDIPhyPowerSavingProc(void);
void ScalerGDIPhyPowerOffProc(void);
void ScalerGDIBandgap(bit bSelect);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : GDI Digital PHY Switch
// Input Value  : InputPortType
// Output Value : None
//--------------------------------------------------
void ScalerGDIDigitalPhySwitch(BYTE ucInputPortType)
{
    ucInputPortType = ucInputPortType;

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
    if((ucInputPortType == _D0_DVI_PORT) || (ucInputPortType == _D1_DVI_PORT) || (ucInputPortType == _D2_DVI_PORT) || (ucInputPortType == _D3_DVI_PORT) ||
       (ucInputPortType == _D0_HDMI_PORT) || (ucInputPortType == _D1_HDMI_PORT) || (ucInputPortType == _D2_HDMI_PORT) || (ucInputPortType == _D3_HDMI_PORT) ||
       (ucInputPortType == _D0_MHL_PORT) || (ucInputPortType == _D1_MHL_PORT))
    {
        // Current SI at DP
        if((bit)(ScalerGetBit(PB_E0_DIG00, _BIT4)) != _BIT4)
        {
            // Disable Rx_En and CMU_En
            ScalerSetByte(PB_B4_POWER_0, 0x00);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);               

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
            if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
            }
            else
#endif
            {
                // Disable Port 0 Z0
                ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
            }

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
            if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
            }
            else
#endif
            {
                // Disable Port 1 Z0
                ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
            }

            // Dual Mode Disable and Analog Select to HDMI
            ScalerSetBit(PB_AC_CDR_A, ~(_BIT3 | _BIT4), 0x00);
        }

        // Digital PHY Lane Swap Setting
        ScalerSetByte(PB_D0_RXMISC_3, 0xE4);    

        // Digital PHY P/N Swap Setting
        ScalerSetBit(PB_D1_RXMISC_4, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);        

        // Switch to HDMI
        ScalerSetBit(PB_E0_DIG00, ~_BIT4, _BIT4);
        ScalerSetBit(PB_B4_POWER_0, ~_BIT3, _BIT3);

#if(_MHL_SUPPORT == _ON)
        if((ucInputPortType == _D0_DVI_PORT) || (ucInputPortType == _D1_DVI_PORT) || (ucInputPortType == _D2_DVI_PORT) || (ucInputPortType == _D3_DVI_PORT) ||
           (ucInputPortType == _D0_HDMI_PORT) || (ucInputPortType == _D1_HDMI_PORT) || (ucInputPortType == _D2_HDMI_PORT) || (ucInputPortType == _D3_HDMI_PORT) ||
           ((ucInputPortType == _D0_MHL_PORT) && (GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)) || ((ucInputPortType == _D1_MHL_PORT) && (GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)))
        {
            if(ScalerGetBit(PB_AB_CDR_9, _BIT7) == _BIT7)
            {
                // Disable Auto k-offset(foreground)
                ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);

                // Disable MHL OP for Data Removing Common Mode
                ScalerSetBit(PB_AB_CDR_9, ~_BIT7, 0x00);
            }
        }
        else if(((ucInputPortType == _D0_MHL_PORT) && (GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)) || ((ucInputPortType == _D1_MHL_PORT) && (GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)))
        {
            if(ScalerGetBit(PB_AB_CDR_9, _BIT7) == 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB_B4_POWER_0, 0x08);
                
                // Disable Auto k-offset(foreground)
                ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);
                
                // Enable MHL OP for Data Removing Common Mode
                ScalerSetBit(PB_AB_CDR_9, ~_BIT7, _BIT7);
            }
        }
#endif

    }
#endif
}

//--------------------------------------------------
// Description  : GDI Z0 Switch 
// Input Value  : D0/D1 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect)
{

#if(_MHL_SUPPORT == _ON)

#if((_D0_INPUT_PORT_TYPE == _D0_MHL_PORT) && (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    if(ucPortSelect == _D0_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(0);
    }
    else if(ucPortSelect == _D1_INPUT_PORT)
    {
        SET_MHL_PORT_ACTIVE(1);
    }
#else
    SET_MHL_PORT_ACTIVE(0);
#endif

    if(((ucPortSelect == _D0_INPUT_PORT) && (GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)) ||
       ((ucPortSelect == _D1_INPUT_PORT) && (GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)))
    {
        if(ucPortSelect == _D0_INPUT_PORT)
        {        
            if(bSelect == _ON)
            {
                // Set Z0 to MHL Mode
                ScalerSetBit(PB_AC_CDR_A, ~_BIT0, _BIT0);

#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
                // Port 0 Z0 Enable
                ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif

            }
            else
            {
                if((ScalerGetBit(PB_B6_Z0_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4)) && \
                    (GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()) > _MHL_STATE_DEV_CAP_RDY))
                {
                    if(!((GET_D0_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)))
                    {
                        // Reset D0 CBUS While Non-NoteII
                        ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
                    }
                }
            }
        }
        else if(ucPortSelect == _D1_INPUT_PORT)
        {        
            if(bSelect == _ON)
            {
                // Set Z0 to MHL Mode
                ScalerSetBit(PB_A4_CDR_2, ~_BIT4, _BIT4);
                
#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
                // Port 1 Z0 Enable
                ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif

            }
            else
            {
                if((ScalerGetBit(PB_B7_Z0_1, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4)) && \
                    (GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()) > _MHL_STATE_DEV_CAP_RDY))
                {
                    if(!((GET_D1_MHL_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)))
                    {
                        // Reset D1 CBUS While Non-NoteII
                        ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
                    }
                }
            }
        }
    }
    else
    {
        ScalerMHLCBUSPhySwitch(ucPortSelect, _OFF);

        if(ucPortSelect == _D0_INPUT_PORT)
        {        
            if(bSelect == _ON)
            {
                // Set Z0 to HDMI Mode
                ScalerSetBit(PB_AC_CDR_A, ~_BIT0, 0x00);

#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
                if((ScalerGetByte(PB_B6_Z0_0) & 0xF0) == 0x00)
                {
                    SET_TMDS_Z0_ASSERTED();
                    CLR_TMDS_HPD_TRIGGER_EVENT();
                
                    ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                    // Initialize DDC Detection Process
                    g_bTmdsD0DdcDetected = _FALSE;

                    // Enable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
                    MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                    MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
                    MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                    MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;                                                    
#endif                        
                }
#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

                if(ScalerGetBit(PB_B6_Z0_0, _BIT7) == 0x00)
                {
                    // Port 0 Z0 Enable
                    ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                }
            }
            else
            {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
                // Disable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT3 | _BIT1);
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT3 | _BIT1);                                                    
#endif              

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

                    // Port 0 Z0 Disable
                    ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

                if((ScalerGetByte(PB_B7_Z0_1) & 0xF0) == 0x00)
                {
                    // Disable HDCP Module
                    ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT0, 0x00);
                }  
            }
        }
        else if(ucPortSelect == _D1_INPUT_PORT)
        {        
            if(bSelect == _ON)
            {
                // Set Z0 to HDMI Mode
                ScalerSetBit(PB_A4_CDR_2, ~_BIT4, 0x00);

#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
                if((ScalerGetByte(PB_B7_Z0_1) & 0xF0) == 0x00)
                {
                    SET_TMDS_Z0_ASSERTED();
                    CLR_TMDS_HPD_TRIGGER_EVENT();
                
                    ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                    // Initialize DDC Detection Process
                    g_bTmdsD1DdcDetected = _FALSE;    

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
                    MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                    MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
                    MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                    MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;
#endif                
                }
#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

                if(ScalerGetBit(PB_B7_Z0_1, _BIT7) == 0x00)
                {
                    // Port 1 Z0 Enable
                    ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
                }
            }
            else
            {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
                // Disable DDC Toggle IRQ 
#if(_D1_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT3 | _BIT1);
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT3 | _BIT1);
#endif     

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

                    // Port 1 Z0 Disable
                    ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
                                    
                if((ScalerGetByte(PB_B6_Z0_0) & 0xF0) == 0x00)
                {
                    // Disable HDCP Module
                    ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT0, 0x00);
                }  
            }
        }
    }

#else // Else of #if(_MHL_SUPPORT == _ON)

    if(ucPortSelect == _D0_INPUT_PORT)
    {        
        if(bSelect == _ON)
        {
            // Set Z0 to HDMI Mode
            ScalerSetBit(PB_AC_CDR_A, ~_BIT0, 0x00);

#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
            if((ScalerGetByte(PB_B6_Z0_0) & 0xF0) == 0x00)
            {
                SET_TMDS_Z0_ASSERTED();
                CLR_TMDS_HPD_TRIGGER_EVENT();
                
                ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                g_bTmdsD0DdcDetected = _FALSE;

                // Enable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;                                                    
#endif                        
            }
#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            if(ScalerGetBit(PB_B6_Z0_0, _BIT7) == 0x00)
            {
                // Port 0 Z0 Enable
                ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
            // Disable DDC Toggle IRQ
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
            MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT3 | _BIT1);
#elif(_D0_DDC_CHANNEL_SEL == _DDC3)
            MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT3 | _BIT1);                                                    
#endif              

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            // Port 0 Z0 Disable
            ScalerSetBit(PB_B6_Z0_0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            if((ScalerGetByte(PB_B7_Z0_1) & 0xF0) == 0x00)
            {
                // Disable HDCP Module
                ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT0, 0x00);
            }  
        }
    }
    else if(ucPortSelect == _D1_INPUT_PORT)
    {        
        if(bSelect == _ON)
        {
            // Set Z0 to HDMI Mode
            ScalerSetBit(PB_A4_CDR_2, ~_BIT4, 0x00);

#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
            if((ScalerGetByte(PB_B7_Z0_1) & 0xF0) == 0x00)
            {
                SET_TMDS_Z0_ASSERTED();
                CLR_TMDS_HPD_TRIGGER_EVENT();
                
                ScalerSetBit(P2_A9_TMDS_ACC1, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                g_bTmdsD1DdcDetected = _FALSE;    

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT2;
                MCU_DVI_EDID_IRQ_FFE4 |= _BIT3;
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT2;
                MCU_HDMI_EDID_IRQ_FFE5 |= _BIT3;
#endif                
            }
#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            if(ScalerGetBit(PB_B7_Z0_1, _BIT7) == 0x00)
            {
                // Port 1 Z0 Enable
                ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
#if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))            
            // Disable DDC Toggle IRQ 
#if(_D1_DDC_CHANNEL_SEL == _DDC2)
            MCU_DVI_EDID_IRQ_FFE4 &= ~(_BIT3 | _BIT1);
#elif(_D1_DDC_CHANNEL_SEL == _DDC3)
            MCU_HDMI_EDID_IRQ_FFE5 &= ~(_BIT3 | _BIT1);
#endif     

#endif // End of #if((_HDMI_SUPPORT == _ON) || (_DVI_SUPPORT == _ON))

            // Port 1 Z0 Disable
            ScalerSetBit(PB_B7_Z0_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            if((ScalerGetByte(PB_B6_Z0_0) & 0xF0) == 0x00)
            {
                // Disable HDCP Module
                ScalerSetBit(P2_C0_HDCP_CTRL, ~_BIT0, 0x00);
            }  
        }
    }
#endif // End of #if(_MHL_SUPPORT == _ON)
}

//--------------------------------------------------
// Description  : GDI 2D Switch 
// Input Value  : D0/D1 Port Select
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhy2DSwitch(BYTE ucPortSelect)
{
    if(ucPortSelect == _D0_INPUT_PORT)
    {
        if((ScalerGetBit(PB_B5_DP_2D_SWITCH, _BIT2) != 0x00) || (ScalerGetBit(P0_C6_ADC_POWER, (_BIT2 | _BIT1 | _BIT0) == (_BIT2 | _BIT1 | _BIT0))))
        {
            // Switch to Port 0
            ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT2, 0x00);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
            CLR_TMDS_PHY_SET();
            
            g_usTmdsClkCount = 0;
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
            if((GET_D0_TMDS_MODE() == _TMDS_MHL_MODE) && (ScalerGetBit(PB_B6_Z0_0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4)) && \
                (GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()) >= _MHL_STATE_DEV_CAP_RDY) && (GET_MHL_2D_SWITCH() == _FALSE) && \
                (((GET_D0_MHL_ADOPTER_ID_HBYTE() == _ASUS_PADFONE2_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _ASUS_PADFONE2_ADOPTER_ID_LBYTE)) ||
                ((GET_D0_MHL_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_D0_MHL_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE))))
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D0_INPUT_PORT);

                SET_MHL_2D_SWITCH();
            }
#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

            DebugMessageDigital("7. wuanne test : 2D Switch to D0", 0);
        }
    }
    else
    {
        if((ScalerGetBit(PB_B5_DP_2D_SWITCH, _BIT2) != _BIT2) || (ScalerGetBit(P0_C6_ADC_POWER, (_BIT2 | _BIT1 | _BIT0) == (_BIT2 | _BIT1 | _BIT0))))
        {
            // Switch to Port 1
            ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT2, _BIT2);

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
            CLR_TMDS_PHY_SET();

            g_usTmdsClkCount = 0;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
            if((GET_D1_TMDS_MODE() == _TMDS_MHL_MODE) && (ScalerGetBit(PB_B7_Z0_1, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) == (_BIT7 | _BIT6 | _BIT5 | _BIT4)) && \
                (GET_MHL_PROCESS_STATE(GET_MHL_PORT_ACTIVE()) >= _MHL_STATE_DEV_CAP_RDY) && (GET_MHL_2D_SWITCH() == _FALSE) && \
                (((GET_D1_MHL_ADOPTER_ID_HBYTE() == _ASUS_PADFONE2_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _ASUS_PADFONE2_ADOPTER_ID_LBYTE)) ||
                ((GET_D1_MHL_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_D1_MHL_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE))))
            {           
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
                
                SET_MHL_2D_SWITCH();
            }
#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

            DebugMessageDigital("7. wuanne test : 2D Switch to D1", 0);                
        }
    }
}

//--------------------------------------------------
// Description  : GDI Power Saving Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyPowerSavingProc(void)
{
    // Disable R/G/B RX_EN, Disable R/G/B/Clock CMU_EN
    ScalerSetByte(PB_B4_POWER_0, 0x08); 

    // Disable Auto k-offset(foreground)
    ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);
}

//--------------------------------------------------
// Description  : GDI Power Off Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyPowerOffProc(void)
{
    // Disable RX_EN and CMU_EN
    ScalerSetByte(PB_B4_POWER_0, 0x00);

    // Disable Auto k-offset(foreground)
    ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00);   
        
    CLR_DIGITAL_PORT_SWITCH_TO_D0();
    CLR_DIGITAL_PORT_SWITCH_TO_D1();
    CLR_DIGITAL_PORT_SWITCH_TO_D2();
    CLR_DIGITAL_PORT_SWITCH_TO_D3();
}

//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIBandgap(bit bSelect)
{
    if(bSelect == _ON)
    {
        // GDI Bandgap External Resistor 12k connect to GND
        ScalerSetBit(PB_A0_SIG_DET, ~_BIT3, 0x00);  

        // GDI BG Power On       
        ScalerSetBit(PB_F4_AUX_5, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

        // Disable GDI from POR Bandgap
        ScalerSetBit(PB_F4_AUX_5, ~_BIT4, 0x00);

        // Disable CDR PSM
        ScalerSetBit(PB_BB_BANDGAP, ~_BIT2, 0x00);
        
        // Apply RLRS Code
        ScalerSetBit(PB_B8_Z0_2, ~_BIT7, _BIT7);     
        ScalerSetByte(PB_B7_Z0_1, (ScalerGetByte(PB_B7_Z0_1)) | ((((ScalerGetByte(PB_B8_Z0_2) >> 3) & 0x0C) | ((ScalerGetByte(PB_B8_Z0_2) >> 5) & 0x03)) & 0x0F));  

        // Disable Auto k-offset(foreground)
        ScalerSetBit(PB_B2_EQ_2 , ~(_BIT6 | _BIT5), 0x00); 

        // [1] z0_autok = 1 --> 50ohm auto calibration (Default value = 1) 
        ScalerSetBit(PB_B5_DP_2D_SWITCH, ~_BIT1, _BIT1);

        // [7:6] z0_tune = 2'b11 --> 50ohm calibration target is 50ohm (Default value = 2'b11)
        ScalerSetBit(PB_B5_DP_2D_SWITCH, ~(_BIT6 | _BIT7), (_BIT6 | _BIT7));  

        // [5] p_channel = 1 switch p channel 50ohm z0         
        // [4] n_channel = 1 switch n channel 50ohm z0 
        ScalerSetBit(PB_B3_SINGLE_END, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));  

        // [1] Disable K offset Injection
        // [0] Enable Servo Loop Adaptation
        ScalerSetBit(PB_A4_CDR_2, ~(_BIT1 | _BIT0), _BIT0);

        // [6] Loop ok = 0
        // [5] reg_loop_f_sel = 1
        // [1] Enable TP1 Input(Valid Only DP Mode)
        ScalerSetBit(PB_A9_CDR_7, ~(_BIT6 | _BIT5 | _BIT1), (_BIT5 | _BIT1));

        // [5] use dp_rate_in(Valid Only DP Mode)
        ScalerSetBit(PB_AC_CDR_A, ~_BIT5, _BIT5);
        
        // [6] Loop_Manual = 1
        ScalerSetBit(PB_AF_RXMISC_2, ~_BIT6, _BIT6);    

        // For DP Analog PHY to Digital PHY clock inverse
        ScalerSetBit(PB_D1_RXMISC_4, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);  
        
        // tp1_det_manual, tp1_det_manual_sel
        ScalerSetBit(PB_FF_RXBIST_0, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));    

        if(ScalerGetBit(PB_B6_Z0_0, _BIT7) == _BIT7)
        {
            // Enable D0 RGB Z0
            ScalerSetBit(PB_B6_Z0_0, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }

        if(ScalerGetBit(PB_B7_Z0_1, _BIT7) == _BIT7)
        {
            // Enable D1 RGB Z0
            ScalerSetBit(PB_B7_Z0_1, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
        }
        
#if(_MHL_SUPPORT == _ON)
        ScalerSetBit(P27_A1_RES_AUTOK_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _MHL_1K);

        pData[0] = ScalerGetBit(P24_A6_EFUSE_DATA0, (_BIT3 | _BIT2 | _BIT1 | _BIT0));
        
        if(pData[0] == 0x00)
        {
            ScalerSetBit(P27_A2_RES_AUTOK_2, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_MHL_100K << 2));
        }
        else
        {
            ScalerSetBit(P27_A2_RES_AUTOK_2, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (pData[0] << 2));
        }
#endif
        // Disable Aux Power Saving Mode
        ScalerSetBit_EXINT0(PB_F1_AUX_2, ~_BIT1, 0x00);

        // Switch Aux PHY to GDI BandGap
        ScalerSetBit_EXINT0(PB_F2_AUX_3, ~_BIT7, 0x00);

        // Aux comm current select max
        ScalerSetBit_EXINT0(PB_F3_AUX_4, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    }
    else
    {
        // Enable GDI from POR Bandgap 
        ScalerSetBit(PB_F4_AUX_5, ~_BIT4,_BIT4);

        // Enable CDR PSM
        ScalerSetBit(PB_BB_BANDGAP, ~_BIT2, _BIT2);
        
        // Disable GDI Band Gap and 3.3V to 1.2V regulator
        ScalerSetBit(PB_F4_AUX_5, ~_BIT3 , 0x00);        

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

#if(_MHL_SUPPORT == _ON)

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        if(GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)
        {
            // Disable D0 RGB Z0
            ScalerSetBit(PB_B6_Z0_0, ~(_BIT6 | _BIT5 | _BIT4), 0x00);            
        }
#else
        // Disable D0 RGB Z0
        ScalerSetBit(PB_B6_Z0_0, ~(_BIT6 | _BIT5 | _BIT4), 0x00);                    
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
        if(GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)
        {
            // Disable D1 RGB Z0
            ScalerSetBit(PB_B7_Z0_1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
        }
#else
        // Disable D1 RGB Z0
        ScalerSetBit(PB_B7_Z0_1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
#endif
        
#else // Else of #if(_MHL_SUPPORT == _ON)

        // Disable D0 RGB Z0
        ScalerSetBit(PB_B6_Z0_0, ~(_BIT6 | _BIT5 | _BIT4), 0x00);            

        // Disable D1 RGB Z0
        ScalerSetBit(PB_B7_Z0_1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
        
#endif // End of #if(_MHL_SUPPORT == _ON)        

#endif // End of #if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)
    }
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)
