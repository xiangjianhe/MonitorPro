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
// ID Code      : UserIIC.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_TOUCH_KEY__


#include "UserCommonInclude.h"

#if(_TOUCH_KEY_SUPPORT == _ON) 

#define _CHIP_SYNAPTICS                         0// Synaptics One Touch SO380000
#define _CHIP_CAP1106                           1//SMSC CAP1105/1106

#define _TOUCH_KEY_CHIP_TYPE                    _CHIP_CAP1106//_CHIP_CAP1106


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if( _TOUCH_KEY_CHIP_TYPE == _CHIP_SYNAPTICS)
#define _KEY_TOURCH_SENSOR_SLAVE_ADDRESS        _TOUCHPAD_DRICE_ADDRESS  
#elif( _TOUCH_KEY_CHIP_TYPE == _CHIP_CAP1106)
#define _KEY_TOURCH_SENSOR_SLAVE_ADDRESS        0x50  
#endif

//Configuration Registers
#define _ONE_TOUCH_SENSOR_CR_0000               0x0000
#define _ONE_TOUCH_SENSOR_CR_0001               0x0001
#define _ONE_TOUCH_SENSOR_CR_0002               0x0002
#define _ONE_TOUCH_SENSOR_CR_0004               0x0004
#define _ONE_TOUCH_SENSOR_CR_0008               0x0008
#define _ONE_TOUCH_SENSOR_CR_000E               0x000E
#define _ONE_TOUCH_SENSOR_CR_0010               0x0010
#define _ONE_TOUCH_SENSOR_CR_0011               0x0011
#define _ONE_TOUCH_SENSOR_CR_0012               0x0012
#define _ONE_TOUCH_SENSOR_CR_0013               0x0013
#define _ONE_TOUCH_SENSOR_CR_0014               0x0014
#define _ONE_TOUCH_SENSOR_CR_0015               0x0015
#define _ONE_TOUCH_SENSOR_CR_0022               0x0022//LED Enable
#define _ONE_TOUCH_SENSOR_CR_0023               0x0023
#define _ONE_TOUCH_SENSOR_CR_0024               0x0024
#define _ONE_TOUCH_SENSOR_CR_0025               0x0025
#define _ONE_TOUCH_SENSOR_CR_0026               0x0026
#define _ONE_TOUCH_SENSOR_CR_0027               0x0027

//Data Registers
#define _ONE_TOUCH_SENSOR_DR_0106               0x0106
#define _ONE_TOUCH_SENSOR_DR_0107               0x0107
#define _ONE_TOUCH_SENSOR_DR_0108               0x0108
#define _ONE_TOUCH_SENSOR_DR_0109               0x0109

//Reset Registers
#define _ONE_TOUCH_SENSOR_RESET_0300            0x0300

#define _MAX_LED_Brightness                     (0xA0 + 0x001F)//Louis 0621 x0xA0


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
#if( _TOUCH_KEY_CHIP_TYPE == _CHIP_SYNAPTICS)

WORD code  TOUCH_KEY_INITIAL[]=
{
    0x0007,     // values of 0x0000
    0x0000,     // values of 0x0001
    0x0032,     // values of 0x0002
    0x0384,     // values of 0x0003
    0x007F,     // values of 0x0004
    0x0000,     // values of 0x0005
    0x0000,     // values of 0x0006
    0x0000,     // values of 0x0007
    0x0000,     // values of 0x0008
    0x0000,     // values of 0x0009
    0x0000,     // values of 0x000A
    0x0000,     // values of 0x000B
    0x0000,     // values of 0x000C
    0x0000,     // values of 0x000D
    0x7F7F,     // values of 0x000E
    0x0100,     // values of 0x000F

	0xB2A8,     //* values of 0x0010 */ //s1,s0 Bri, MODE
	0xB2B2,     //* values of 0x0011 */ //s3,s2 Power, Auto
	0xAFBE,     //* values of 0x0012 */ //s5,s4  ECO, MENU
	0xAAAC,     // values of 0x0013 //s6 Input  
	
    0x0000,     // values of 0x0014
    0x0000,     // values of 0x0015
    0x0000,     // values of 0x0016
    0x0000,     // values of 0x0017
    0x0000,     // values of 0x0018
    0x0000,     // values of 0x0019
    0x0000,     // values of 0x001A
    0x0000,     // values of 0x001B
    0x0000,     // values of 0x001C
    0x0000,     // values of 0x001D
    0x0000,     // values of 0x001E
    0x0000,     // values of 0x001F
    0x0000,     // values of 0x0020
    0x0000,     // values of 0x0021
    0x000E,	    // values of 0x0022
    0x0000,	    // values of 0x0023
    0x0000, 	// values of 0x0024
    0x0000, 	// values of 0x0025
    0x0000, 	// values of 0x0026
    0x0000, 	// values of 0x0027
    0x0000, 	// values of 0x0028
    0x0000, 	// values of 0x0029
    0x0000,     // values of 0x002A
    0x0000      // values of 0x002B
};

#elif( _TOUCH_KEY_CHIP_TYPE == _CHIP_CAP1106)
BYTE code TOUCH_KEY_INITIAL[]=
{
    0x1f, 0x3f,  
    0x21, 0x1f, 
    0x24, 0x3B,  
    0x27, 0x1f, 
    0x28, 0x00,  
    0x2A, 0x88,  
    0x2f, 0x09, 
    0x30, 0x1C,  
    0x31, 0x1A,  
    0x32, 0x1A,  
    0x33, 0x1A,  
    0x34, 0x1A,  
    0x44, 0x60,  
    0x26, 0x1f, 
    0x00, 0x00,  
};                                                
#endif


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE xdata ucAdjustItemValue=0;
bit idata g_ucTouchKeyInit=0;
bit idata g_ucTouchKeyAbnormal=0;
BYTE data pTouchData[2] = {0};


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
void UserTouchKeyInitial(void);
BYTE UserTouchKeyScan(void);

#if( _TOUCH_KEY_CHIP_TYPE == _CHIP_SYNAPTICS)

bit UserTouchKeyWrite(WORD usAddr, WORD Value)//ONCE FOR 1 WORD
{
    BYTE ucSlaveAddr = _KEY_TOURCH_SENSOR_SLAVE_ADDRESS;

	SET_SW_IIC_STATUS(_IIC_SYS_TOUCHKEY);
    
    if((g_ucTouchKeyInit)&&(!g_ucTouchKeyAbnormal))
    {
        g_ucTouchKeyInit=_FALSE;
        ScalerTimerDelayXms(100);
    }
    
	pData[0]=HIBYTE(Value);
	pData[1]=LOBYTE(Value);
    
    if(ScalerMcuIICWrite(ucSlaveAddr, 2, usAddr, 2, pData) == _FAIL)
    {
        DebugMessageOsd("TouchKey Write _FAIL ",0);
        SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);
		return _FAIL;
    }

    SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);
    return _SUCCESS;
}

bit UserTouchKeyRead(WORD usAddr,  BYTE *pReadArray) //ONCE READ 1 WORD
{
    BYTE ucSlaveAddr = _KEY_TOURCH_SENSOR_SLAVE_ADDRESS;
 
	SET_SW_IIC_STATUS(_IIC_SYS_TOUCHKEY);
    if(ScalerMcuIICRead(ucSlaveAddr, 2, usAddr, 2, pReadArray) == _FAIL)
    {
        DebugMessageOsd("TouchKey Read _FAIL ",0);
        SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);
		return _FAIL;
    }

	SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);
	return _SUCCESS;
}

//--------------------------------------------------
// Description  : None
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserTouchKeyInitial(void)
{
    BYTE i;
    BYTE FailCount=0;
	
    g_ucTouchKeyInit=_TRUE;

    for (i=0; i<=24; i++)
    {
        if(UserTouchKeyWrite(i, TOUCH_KEY_INITIAL[i])==_FAIL)
        {
            i=0;
            if ((FailCount++)==3) break; //double check initial
        }
    }
}
/*
void UserTouchKeyReset(void)
{
    bit ucTouchKeyResult=_FAIL;

    ucTouchKeyResult=UserTouchKeyRead(_ONE_TOUCH_SENSOR_CR_0000,&pData[9]);
    if(ucTouchKeyResult ==_SUCCESS)
    { 		  
        if((!(pData[10]&_BIT2))&&(!GET_TOUCHKEY_SCAN_READY()))
        {   
            SET_TOUCHKEY_SCAN_READY();
            CTouchKeyReset();
        } 		  
    }
    
    if(GET_TOUCHKEY_RESET_READY())
    { 	  
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_TOUCH_KEY_RESET);	  
        CLR_TOUCHKEY_RESET_READY();
        CLR_TOUCHKEY_SCAN_READY();
        g_ucTouchKeyAbnormal=_TRUE;
        UserTouchKeyInitial(); 
        g_ucTouchKeyAbnormal=_FALSE;
    }
}
*/

#if 0
void UserTouchKeyTouchPadLedControl(void)
{
	switch(SysModeGetModeState())
	{
		case _MODE_STATUS_INITIAL:		
		case _MODE_STATUS_SEARCH:			 
		case _MODE_STATUS_ACTIVE:
		case _MODE_STATUS_NOSUPPORT:
			UserTouchKeyTouchPadLed(_LED_POWER_ON);
			break;
		case _MODE_STATUS_POWER_SAVING:
			UserTouchKeyTouchPadLed(_LED_POWER_SAVING);
			break;
		case _MODE_STATUS_POWER_OFF:
			UserTouchKeyTouchPadLed(_LED_POWER_OFF);
			break;
	}
}


#define _EFFECT         (_BIT5|_BIT6)
#define _LED_DELAY      10

void UserTouchKeyTouchPadLed(BYTE usTouchPadLed)
{ 
    BYTE ucLedBrightness1 = 0x1F;
    BYTE ucLedBrightness2 = 0x1F;
    BYTE ucLedBrightness3 = 0x1F;
    BYTE ucLedBrightness4 = 0x1F;
    BYTE i=0;
    
    
    switch(usTouchPadLed)
    {
        case _LED_POWER_ON:
        case _LED_POWER_ACTIVE:
        case _LED_POWER_SEARCH:
        case _LED_POWER_NOSUPPORT:
            /*
                UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0022, 0x001E);   
      
                for(ucLedBrightness1=0; ucLedBrightness1<0x20; ucLedBrightness1++)
                {
                    ScalerTimerDelayXms(_LED_DELAY);
                    UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0024, (((_EFFECT|ucLedBrightness1)<<8)|(0x00))); //Up
                }
                    
                for(ucLedBrightness2=0; ucLedBrightness2<0x20; ucLedBrightness2++)
                {
                    ScalerTimerDelayXms(_LED_DELAY);
                    UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0025, ((0x00<<8)|(_EFFECT|ucLedBrightness2)));  //Down
                }
                    
                for(ucLedBrightness3=0; ucLedBrightness3<0x20; ucLedBrightness3++)
                {
                    ScalerTimerDelayXms(_LED_DELAY);
                    UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0025, (((_EFFECT|ucLedBrightness3)<<8)|(_EFFECT|0x1F)));  //Menu
                }
                
                for(ucLedBrightness4=0; ucLedBrightness4<0x20; ucLedBrightness4++)
                {
                    ScalerTimerDelayXms(_LED_DELAY);
                    UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0026, ((0x00<<8)|(_EFFECT|ucLedBrightness4)));  //Exit
                }*/
        break;
        
        case _LED_POWER_SAVING:
        case _LED_POWER_NOSUPPORT_SAVING:
        case _LED_POWER_OFF:
            /*
            for(ucLedBrightness4=0x1F; ucLedBrightness4>0; ucLedBrightness4--)
            {
                ScalerTimerDelayXms(_LED_DELAY);
                UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0026, ((0x00<<8)|(_EFFECT|ucLedBrightness4)));  //Exit
            }
                
            for(ucLedBrightness3=0x1F; ucLedBrightness3>0; ucLedBrightness3--)
            {
                ScalerTimerDelayXms(_LED_DELAY);
                UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0025, (((_EFFECT|ucLedBrightness3)<<8)|(_EFFECT|0x1F)));  //Menu
            }
                
            for(ucLedBrightness2=0x1F; ucLedBrightness2>0; ucLedBrightness2--)
            {
                ScalerTimerDelayXms(_LED_DELAY);
                UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0025, ((0x00<<8)|(_EFFECT|ucLedBrightness2)));  //Down
            }
                
            for(ucLedBrightness1=0x1F; ucLedBrightness1>0; ucLedBrightness1--)
            {
                ScalerTimerDelayXms(_LED_DELAY);
                UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0024, (((_EFFECT|ucLedBrightness1)<<8)|(0x00))); //Up
            }
                */
            UserTouchKeyWrite(_ONE_TOUCH_SENSOR_CR_0022, 0x0000);
        break;
        
        case _LED_TYPE_FLASH:
        break;

        default:
        break;
    }
}
#endif

BYTE UserTouchKeyScan(void)
{
    bit ucKeyResult=_TRUE;
    BYTE ucKeyState = 0;

    ucKeyResult=UserTouchKeyRead(_ONE_TOUCH_SENSOR_DR_0109,&pTouchData[0]);

    if(ucKeyResult==_SUCCESS)
    {
		ucKeyResult=UserTouchKeyRead(_ONE_TOUCH_SENSOR_DR_0109,&pTouchData[0]); 

		if((pTouchData[1] &_BIT3)||(pTouchData[1] &_BIT0))
		{
			ucKeyResult=UserTouchKeyRead(_ONE_TOUCH_SENSOR_DR_0109,&pTouchData[0]); 
		}

		if(ucKeyResult==_SUCCESS)
		{

#if(_DEBUG_MESSAGE_OSD == _ON)
            if(pTouchData[1] != 0)
    			DebugMessageOsd("TouchKey Value", pTouchData[1]);
#endif

			if(pTouchData[1] &_BIT2)                               
				ucKeyState=ucKeyState|_RIGHT_KEY_MASK;  
                                                       
			if(pTouchData[1] &_BIT3)                            
				ucKeyState=ucKeyState|_MENU_KEY_MASK;  
                                                       
			if(pTouchData[1] &_BIT1)                            
				ucKeyState=ucKeyState|_LEFT_KEY_MASK ; 
                                                       
			if(pTouchData[1] &_BIT0)                            
				ucKeyState=ucKeyState|_EXIT_KEY_MASK ;  

            //PCB_KEY_STATE(pTouchData[1], pTouchData[1], pTouchData[1], pTouchData[1], ucKeyState);
		}
    }

    if(!bPOWER_KEY)
        ucKeyState = ucKeyState|_POWER_KEY_MASK;
        
    if(ucKeyState != 0)
    {
    	CLR_KEYSCANREADY();
    	CLR_KEYSCANSTART();
    }

    return ucKeyState;
}



#elif( _TOUCH_KEY_CHIP_TYPE == _CHIP_CAP1106)

bit UserTouchKeyWrite(BYTE usAddr, BYTE Value) 
{
    BYTE ucSlaveAddr = _KEY_TOURCH_SENSOR_SLAVE_ADDRESS;

	SET_SW_IIC_STATUS(_IIC_SYS_TOUCHKEY);
    
    if((g_ucTouchKeyInit)&&(!g_ucTouchKeyAbnormal))
    {
        g_ucTouchKeyInit=_FALSE;
        ScalerTimerDelayXms(100);
    }
    
	pData[0]=Value;
    
    if(ScalerMcuIICWrite(ucSlaveAddr, 1, usAddr, 1, pData) == _FAIL)
    {
        DebugMessageOsd("TouchKey Write _FAIL ",0);
        SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);
		return _FAIL;
    }

    SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);
    return _SUCCESS;
}

bit UserTouchKeyRead(BYTE usAddr,  BYTE *pReadArray) 
{
    BYTE ucSlaveAddr = _KEY_TOURCH_SENSOR_SLAVE_ADDRESS;

    SET_SW_IIC_STATUS(_IIC_SYS_TOUCHKEY);
    if(ScalerMcuIICRead(ucSlaveAddr, 1, usAddr, 1, pReadArray) == _FAIL)
    {
        DebugMessageOsd("TouchKey Read _FAIL ",0);
        SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);
        return _FAIL;
    }

    SET_SW_IIC_STATUS(_IIC_SYS_EEPROM);
    return _SUCCESS;
}

//--------------------------------------------------
// Description  : None
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserTouchKeyInitial(void)
{
    BYTE i;

    for(i = 0; i<(sizeof(TOUCH_KEY_INITIAL)/sizeof(TOUCH_KEY_INITIAL[0])); i+=2)
    {
        if(UserTouchKeyWrite(TOUCH_KEY_INITIAL[i], TOUCH_KEY_INITIAL[i+1]) == _FAIL)
        {
            break;
        }
    }

    SET_KEYSCANREADY();
    SET_KEYSCANSTART();
}

void UserTouchKeyTouchPadLed(BYTE usTouchPadLed)
{ 
    usTouchPadLed = 0;
}

BYTE UserTouchKeyScan(void)
{
    BYTE ucKeyState = 0;

	if(SysModeGetModeState() == _MODE_STATUS_POWER_OFF)
	{
		ScalerTimerDelayXms(3);
	}

	if(UserTouchKeyRead(0x00, &pTouchData[0]) == _SUCCESS)
	{
		if((pTouchData[0] & _BIT6 )== 0)//ic reset
		{
			UserTouchKeyInitial();
    		ScalerTimerDelayXms(3);
		}
	}
	
	pTouchData[0] = 0x40;// for clear INT. bit
	
	if(UserTouchKeyWrite(0x00, pTouchData[0]) == _FAIL)
	{
	 	return 0;
	}
    
	// get latest key status from register 0x03
	if(UserTouchKeyRead(0x03, &pTouchData[1])== _FAIL)
	{
	 	return 0;
	}
    
    //keeps only CS1,2,3,4,5
	pTouchData[1] &= 0x1f;
		
    if(pTouchData[1] != 0)
    {
        DebugMessageOsd("TouchKey Value", pTouchData[1]);
        PCB_KEY_STATE(pTouchData[1], pTouchData[1], pTouchData[1], pTouchData[1], ucKeyState);
    }

    if(!bPOWER_KEY)
        ucKeyState = ucKeyState|_POWER_KEY_MASK;    

    if(ucKeyState != 0)
    {
    	CLR_KEYSCANREADY();
    	CLR_KEYSCANSTART();
    }

    return ucKeyState;
}
#endif



#endif // End of #if(_TOUCH_KEY_SUPPORT == _ON)

