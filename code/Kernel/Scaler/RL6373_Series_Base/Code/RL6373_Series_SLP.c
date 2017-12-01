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
// ID Code      : RL6373_Series_SLP.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6373_SERIES_SLP__

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
BYTE g_ucSlpWakeUpStatus = _SLP_NO_EVENT;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerSLPPC99PowerDetect(void);
void ScalerSLPVcckoffRelease(void);
bit ScalerSLPPowerKeyHit(void);
BYTE ScalerSarAdcCodeValue(void);
bit ScalerSLPCableDetectHit(void);
void ScalerSLPLedLevelMode(bit ucLedStatus);
void ScalerSLPLedCounterMode(void);

#if(_SUPER_LOW_POWER_SUPPORT == _ON)
void ScalerSLPSystemInitial(void);
void ScalerSLPPSFlagClear(void);
void ScalerSLPPDFlagClear(void);
void ScalerSLPPowerStatus(EnumPowerStatus enumPorStatus);
bit ScalerSLPV33OffStatus(void);
bit ScalerSLPVcckOffStatus(void);
void ScalerSLPVSetSwrEn(bit ucSwrStatus);
bit ScalerSLPVSetSwrEnStatus(void);
BYTE ScalerSLPWakeUpStatus(void);
void ScalerSLPFilterKeyEvent(void);
void ScalerSLPHitEventClear(void);
#endif
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : SLP VCCK_OFF & turn off PC99 LDO
// Input Value  : None
// Output Value : _TRUE
//--------------------------------------------------
bit ScalerSLPPC99PowerDetect(void)
{
    return _TRUE;
}

//--------------------------------------------------
// Description  : SLP Vcckoff Release
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPVcckoffRelease(void)
{
    // In order to release VCCK_OFF
    ScalerSetBit(P64_A0_SLP_CTRL1, ~_BIT6, 0x00);

    // At Least 2ms For VCCK_OFF Release
    ScalerTimerDelayXms(3);
   
    ScalerSetBit(P64_A0_SLP_CTRL1, ~_BIT6, _BIT6);

    ScalerTimerPollingFlagProc(10, P64_A0_SLP_CTRL1, _BIT4, 0x00); 
}

//--------------------------------------------------
// Description  : SLP Power Key Hit
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerSLPPowerKeyHit(void)
{
    bit bPowerKey = 0;

    bPowerKey = ScalerGetBit(P64_A2_SLP_CTRL3, _BIT0);

    if(bPowerKey == _TRUE)
    {
        ScalerSLPVSetSwrEn(_ON);
        
        do
        {
            if(ScalerGetBit(P64_A2_SLP_CTRL3, _BIT0) == 0x00)
            {
                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);
            }
            else
            {   
                // In order to release VCCK_OFF
                ScalerSLPVcckoffRelease();

                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, 0x00);
                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);
            }

        }while(ScalerTimerPollingFlagProc(5, P64_A2_SLP_CTRL3, _BIT0, _TRUE) == _TRUE);
    }

    return bPowerKey;
}

//--------------------------------------------------
// Description  : SLP 5bit Sar Adc Code
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerSarAdcCodeValue(void)
{
    BYTE bAdKey = 0x1F;

    bAdKey = ScalerGetByte(P64_A6_SLP_CTRL7);

    if(bAdKey != 0x1F)
    {
        ScalerTimerDelayXms(5);
        
        if(abs(bAdKey - ScalerGetByte(P64_A6_SLP_CTRL7)) <= 2)
        {
            return bAdKey;      
        }
    }
    
    return 0x1F;
}

//--------------------------------------------------
// Description  : SLP Cable Detect Hit
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerSLPCableDetectHit(void)
{
    bit bCableDetect = 0;
    
    // Check Cable Detect Low Happened or Not
    bCableDetect = ScalerGetBit(P64_A7_SLP_CTRL8, _BIT1);

    if(bCableDetect == _TRUE)
    {
        // Reset Detect Low Event & Start to Detect Low
        ScalerSetBit(P64_A7_SLP_CTRL8, ~_BIT7, 0x00);
        ScalerSetBit(P64_A7_SLP_CTRL8, ~_BIT7, _BIT7);
    }

    return bCableDetect;
}

//--------------------------------------------------
// Description  : LED Display Level Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPLedLevelMode(bit ucLedStatus)
{
    if(ucLedStatus == _LED_ON)
    {
        // Enable LED Drive Power & Level Mode & Drive Pull Low
        ScalerSetBit(P64_AB_SLP_CTRL12, ~(_BIT7 | _BIT6 | _BIT3), _BIT7);
    }
    else
    {

        // Enable LED Drive Power & Level Mode & Drive Pull High
        ScalerSetBit(P64_AB_SLP_CTRL12, ~(_BIT7 | _BIT6 | _BIT3), (_BIT7 | _BIT3));
    }
}

//--------------------------------------------------
// Description  : LED Display Counter Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPLedCounterMode(void)
{
    // Enable LED Drive Power & Counter Mode
    ScalerSetBit(P64_AB_SLP_CTRL12, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
}

#if(_SUPER_LOW_POWER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : SLP System Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPSystemInitial(void)
{
	// Enable SWR_EN
	ScalerSLPVSetSwrEn(_ON); 

    // In order to release VCCK_OFF
    ScalerSLPVcckoffRelease();
	
    // Disable All SWR_Ctrl Signal link SWR_EN
    ScalerSetBit(P64_A1_SLP_CTRL2, ~(_BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1), 0x00);
            
    // Clear 30uA Hit Flag
    ScalerSLPPDFlagClear();

    // Enable Power Key Detect
    ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);

    // Enable Sar-Adc Key Detect
    ScalerSetBit(P64_A3_SLP_CTRL4, ~_BIT7, _BIT7);

    if(ScalerGetByte(CM_0F_ID_REG_02) == 0x91)
    {
        // Enable Sar-Adc 30uA Hit High Level & Low Level 
        ScalerSetByte(P64_A4_SLP_CTRL5, 0x1C);
        ScalerSetByte(P64_A5_SLP_CTRL6, 0x17);
    }
    else if(ScalerGetByte(CM_0F_ID_REG_02) == 0x90)
    {
        // Enable Sar-Adc 30uA Hit High Level & Low Level 
        ScalerSetByte(P64_A4_SLP_CTRL5, 0x1F);
        ScalerSetByte(P64_A5_SLP_CTRL6, 0x1F);
    }

    // Enable Cable Detect Low & Pull-Up Resistor
    ScalerSetBit(P64_A7_SLP_CTRL8, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2), (_BIT7 | _BIT2));
    
    // Disable HS Detect
    ScalerSetBit(P64_A8_SLP_CTRL9, ~_BIT7, 0x00);

    // Disable SOG Detect
    ScalerSetBit(P64_A8_SLP_CTRL9, ~_BIT6, 0x00);

    // Enable LED Drive Power & Level Mode & Open Drain type
    ScalerSetBit(P64_AB_SLP_CTRL12, ~(_BIT7 | _BIT6 | _BIT1), (_BIT7 | _BIT1));

    // Disable Power Key GPI Low Leakage Mode
    ScalerSetBit(P64_AE_SLP_CTRL15, ~_BIT1, 0x00);
}

//--------------------------------------------------
// Description  : SLP Flag Claer For PS
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPPSFlagClear(void)
{     
    // Disable Power Key Detect
    ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, 0x00);

    // Disable Sar-Adc Power Key Detect
    ScalerSetBit(P64_A3_SLP_CTRL4, ~(_BIT7 | _BIT6), 0x00);
 
    // Disable HS&SOG Detect
    ScalerSetBit(P64_A8_SLP_CTRL9, ~(_BIT7 | _BIT6), 0x00);
}

//--------------------------------------------------
// Description  : SLP Flag Claer For PD
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPPDFlagClear(void)
{
    // Disable Power Key Detect
    ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, 0x00);

    // Disable Sar-Adc Power Key Detect
    ScalerSetBit(P64_A3_SLP_CTRL4, ~(_BIT7 | _BIT6), 0x00);

    // Disable Cable Detect
    ScalerSetBit(P64_A7_SLP_CTRL8, ~(_BIT7 | _BIT6 | _BIT2), 0x00);
    
    // Disable HS&SOG Detect
    ScalerSetBit(P64_A8_SLP_CTRL9, ~(_BIT7 | _BIT6), 0x00);
}

//--------------------------------------------------
// Description  : SLP Power Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPPowerStatus(EnumPowerStatus enumPorStatus)
{
    // In order to release VCCK_OFF
    ScalerSLPVcckoffRelease();

    // In order to clear 30uA hit flag
    ScalerSLPHitEventClear();
        
    if(enumPorStatus == _POWER_STATUS_SAVING)
    {
        // Clear SLP Hit Flag
        ScalerSLPPSFlagClear();

        // Check Vcckoff release already
        if(ScalerSLPVcckOffStatus() == _TRUE)
        {
            ScalerSLPVcckoffRelease(); 
        }
            
        // Enable Power Key Detect
        ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);

        // Enable Sar-Adc Key Detect
        ScalerSetBit(P64_A3_SLP_CTRL4, ~_BIT7, _BIT7);

        if((ScalerGetBit(P64_A7_SLP_CTRL8, _BIT1)) == _BIT1) 
        {
            // Enable Cable Detect High & HW Mode & Disable Pull Up Control
            ScalerSetBit(P64_A7_SLP_CTRL8, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2), (_BIT6 | _BIT5));
        }
        else if((ScalerGetBit(P64_A7_SLP_CTRL8, _BIT0)) == _BIT0) 
        {
            // Enable Cable Detect Low & HW Mode & Disable Pull Up Control
            ScalerSetBit(P64_A7_SLP_CTRL8, ~(_BIT7 | _BIT6 | _BIT5 | _BIT2), (_BIT7 | _BIT5));
        }

        // Enable SLP SOG IR Mode
        ScalerSetBit(P64_A9_SLP_CTRL10, ~_BIT0, _BIT0);

        // Enable SLP SOG Clamp Voltage
        ScalerSetBit(P64_A9_SLP_CTRL10, ~(_BIT6 | _BIT5 | _BIT4), _BIT4);

        // Enable SLP SOG Comparator Voltage
        ScalerSetBit(P64_A9_SLP_CTRL10, ~(_BIT3 | _BIT2 | _BIT1), 0x00);

        // Set SLP Mbias Current to 30uA For SOG Detect
        ScalerSetBit(P64_AA_SLP_CTRL11, ~(_BIT3 | _BIT2), _BIT3);

        // Enable HS Detect
        ScalerSetBit(P64_A8_SLP_CTRL9, ~_BIT7, _BIT7);

        // Enable SOG Detect
        ScalerSetBit(P64_A8_SLP_CTRL9, ~_BIT6, _BIT6);

        // Enable SOG DC Restore Capacity Charge
        ScalerSetBit(P64_A9_SLP_CTRL10, ~_BIT7, _BIT7);
        ScalerTimerDelayXms(1);
        ScalerSetBit(P64_A9_SLP_CTRL10, ~_BIT7, 0x00);
            
        // Enable LED Drive Counter Mode
        ScalerSLPLedCounterMode();

        // Enable SWR_CTRL Link SWR_EN When Event Happened(PK, SA, HPD, HS, SOG)
        ScalerSetBit(P64_A1_SLP_CTRL2, ~(_BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1), _BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1);
        
        if(ScalerSLPWakeUpStatus() != _SLP_NO_EVENT)
        {
            // In order to release VCCK_OFF
            ScalerSLPVcckoffRelease();

            // Clear SLP Hit Flag
            ScalerSLPPSFlagClear();
            
            // Enable Power Key Detect
            ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);

            // Enable Sar-Adc Key Detect
            ScalerSetBit(P64_A3_SLP_CTRL4, ~_BIT7, _BIT7);

            // Enable HS Detect
            ScalerSetBit(P64_A8_SLP_CTRL9, ~_BIT7, _BIT7);

            // Enable SOG Detect
            ScalerSetBit(P64_A8_SLP_CTRL9, ~_BIT6, _BIT6); 
        }
            
        do
        {
            if(ScalerSLPWakeUpStatus() == _SLP_NO_EVENT)
            {
                // Enable Power Key Detect
                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);

                // Enable Sar-Adc Key Detect
                ScalerSetBit(P64_A3_SLP_CTRL4, ~_BIT7, _BIT7);
            }
            else
            {
                // In order to release VCCK_OFF
                ScalerSLPVcckoffRelease();

                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, 0x00);
                ScalerSetBit(P64_A3_SLP_CTRL4, ~_BIT7, 0x00);
                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);
                ScalerSetBit(P64_A3_SLP_CTRL4, ~_BIT7, _BIT7);
            }

        }while((ScalerTimerPollingFlagProc(100, P64_A2_SLP_CTRL3, _BIT0, _TRUE) == _TRUE) || 
               (ScalerTimerPollingFlagProc(100, P64_A3_SLP_CTRL4, _BIT1, _TRUE) == _TRUE));
        
        // Disable SWR_EN
        ScalerSetBit(P64_A1_SLP_CTRL2, ~_BIT7, 0x00);
 
    }
    else if(enumPorStatus == _POWER_STATUS_OFF)
    {
        // Clear SLP Hit Flag
        ScalerSLPPDFlagClear();

        // Disable LED Drive
        ScalerSetBit(P64_AB_SLP_CTRL12, ~_BIT7, 0x00);

        // Check Vcckoff release already
        if(ScalerSLPVcckOffStatus() == _TRUE)
        {
            ScalerSLPVcckoffRelease();    
        }
        
        // Enable Power Key Detect
        ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);

        // Enable SWR_CTRL Link SWR_EN When Event Happened(PK)
        ScalerSetBit(P64_A1_SLP_CTRL2, ~(_BIT6 | _BIT5 | _BIT3 | _BIT2 | _BIT1), _BIT6);

        do
        {
            if(ScalerSLPWakeUpStatus() == _SLP_NO_EVENT)
            {
                // Enable Power Key Detect
                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);
            }
            else
            {
                // In order to release VCCK_OFF
                ScalerSLPVcckoffRelease();

                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, 0x00);
                ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);
            }

        }while(ScalerTimerPollingFlagProc(100, P64_A2_SLP_CTRL3, _BIT0, _TRUE) == _TRUE);

        // Enable Power Key GPI Low Leakage Mode
        ScalerSetBit(P64_AE_SLP_CTRL15, ~_BIT1, _BIT1);
            
        // Disable SWR_EN
        ScalerSetBit(P64_A1_SLP_CTRL2, ~_BIT7, 0x00);
    }
}
//--------------------------------------------------
// Description  : SLP V33Off Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerSLPV33OffStatus(void)
{
    if(ScalerGetBit(P64_A0_SLP_CTRL1, _BIT5) == _BIT5)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : SLP VcckOff Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerSLPVcckOffStatus(void)
{
    if(ScalerGetBit(P64_A0_SLP_CTRL1, _BIT4) == _BIT4)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : SLP Set SWR_EN Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPVSetSwrEn(bit ucSwrStatus)
{
    if(ucSwrStatus == _ON)
    {
        ScalerSetBit(P64_A1_SLP_CTRL2, ~_BIT7, _BIT7);
    }
    else
    {
        ScalerSetBit(P64_A1_SLP_CTRL2, ~_BIT7, 0x00);
    }
}

//--------------------------------------------------
// Description  : SLP SWR_EN Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerSLPVSetSwrEnStatus(void)
{
    if(ScalerGetBit(P64_A0_SLP_CTRL1, _BIT7) == _BIT7)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : SLP Wake Up Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerSLPWakeUpStatus(void)
{
    // AC_ON Power On Wake Up
    if((ScalerGetBit(P64_A2_SLP_CTRL3, _BIT0) == 0x00) && (ScalerGetBit(P64_A3_SLP_CTRL4, (_BIT1 |_BIT0)) == 0x00) &&
       (ScalerGetBit(P64_A7_SLP_CTRL8, (_BIT1 | _BIT0)) == 0x00) && (ScalerGetBit(P64_A8_SLP_CTRL9, (_BIT1 | _BIT0)) == 0x00)) 
    {
        g_ucSlpWakeUpStatus = _SLP_NO_EVENT;
    }
    // Power Down Wake Up
    else if(ScalerGetBit(P64_A2_SLP_CTRL3, _BIT0) == _BIT0)
    {
        g_ucSlpWakeUpStatus = _SLP_POWER_KEY_EVENT;          
    }
    // Power Saving Wake Up
    else if((ScalerGetBit(P64_A2_SLP_CTRL3, _BIT0) == _BIT0) || (ScalerGetBit(P64_A3_SLP_CTRL4, _BIT1) == _BIT1) ||
       (ScalerGetBit(P64_A3_SLP_CTRL4, _BIT0) == _BIT0) || (ScalerGetBit(P64_A7_SLP_CTRL8, _BIT1) == _BIT1) || 
       (ScalerGetBit(P64_A7_SLP_CTRL8, _BIT0) == _BIT0) || (ScalerGetBit(P64_A8_SLP_CTRL9, _BIT1) == _BIT1) || 
       (ScalerGetBit(P64_A8_SLP_CTRL9, _BIT0) == _BIT0))
    {
        if(ScalerGetBit(P64_A2_SLP_CTRL3, _BIT0) == _BIT0)
        {
            g_ucSlpWakeUpStatus = _SLP_POWER_KEY_EVENT;
        }
        else if((ScalerGetBit(P64_A3_SLP_CTRL4, _BIT1) == _BIT1))
        {
            g_ucSlpWakeUpStatus = _SLP_SARADC_KEY_EVENT;
        }
        else if((ScalerGetBit(P64_A3_SLP_CTRL4, _BIT0) == _BIT0))
        {
            g_ucSlpWakeUpStatus = _SLP_POWER_KEY_EDGE_EVENT;
        }
        else if(ScalerGetBit(P64_A7_SLP_CTRL8, _BIT1) == _BIT1)
        {
            g_ucSlpWakeUpStatus = _SLP_CABLE_DETECT_HIGH_EVENT;
        }
        else if(ScalerGetBit(P64_A7_SLP_CTRL8, _BIT0) == _BIT0)
        {
            g_ucSlpWakeUpStatus = _SLP_CABLE_DETECT_LOW_EVENT;            
        }
        else if(ScalerGetBit(P64_A8_SLP_CTRL9, _BIT1) == _BIT1)
        {
            g_ucSlpWakeUpStatus = _SLP_HS_EVENT;               
        }
        else if(ScalerGetBit(P64_A8_SLP_CTRL9, _BIT0) == _BIT0)
        {
            g_ucSlpWakeUpStatus = _SLP_SOG_ENENT;             
        }
    }

    return g_ucSlpWakeUpStatus;
}

//--------------------------------------------------
// Description  : SLP Filter Key Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPFilterKeyEvent(void)
{
    do
    {
        if(ScalerGetBit(P64_A2_SLP_CTRL3, _BIT0) == 0x00)
        {
            ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);
        }
        else
        {
            ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, 0x00);
            ScalerSetBit(P64_A2_SLP_CTRL3, ~_BIT7, _BIT7);
        }

    }while(ScalerTimerPollingFlagProc(100, P64_A2_SLP_CTRL3, _BIT0, _TRUE) == _TRUE);
}

//--------------------------------------------------
// Description  : SLP 30uA Hit Flag Clear
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSLPHitEventClear(void)
{
    // In order to release 30uA hit flag
    ScalerSetBit(P64_AE_SLP_CTRL15, ~_BIT3, _BIT3);

    // At Least 40us For 30uA hit Release
    for(pData[0] = 0; pData[0] <= 100; pData[0]++)
    {
        _nop_();
    }
   
    ScalerSetBit(P64_AE_SLP_CTRL15, ~_BIT3, 0x00);
}

#endif //#if(_SUPER_LOW_POWER_SUPPORT == _ON)

