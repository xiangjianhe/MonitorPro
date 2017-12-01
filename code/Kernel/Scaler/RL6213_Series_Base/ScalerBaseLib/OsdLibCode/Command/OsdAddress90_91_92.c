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
// ID Code      : OsdAddress90_91_92.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "OSD_Lib_Extern.h"

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
void ScalerOsdAddrMsb(BYTE ucValue);
void ScalerOsdAddrLsb(BYTE ucValue);
void ScalerOsdDataPort(BYTE ucValue);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OSD Addr Msb 0x90  
// Input Value  : ucValue -> 0x90 data
// Output Value : 
//--------------------------------------------------
void ScalerOsdAddrMsb(BYTE ucValue)
{
    ScalerSetByte(CM_90_OSD_ADDR_MSB, ucValue);
}

//--------------------------------------------------
// Description  : OSD Addr Lsb 0x91  
// Input Value  : ucValue -> 0x91 data
// Output Value : 
//--------------------------------------------------
void ScalerOsdAddrLsb(BYTE ucValue)
{
    ScalerSetByte(CM_91_OSD_ADDR_LSB, ucValue);
}

//--------------------------------------------------
// Description  : OSD Data Port 0x92 
// Input Value  : ucValue -> 0x92 data
// Output Value : 
//--------------------------------------------------
void ScalerOsdDataPort(BYTE ucValue)
{
    ScalerSetByte(CM_92_OSD_DATA_PORT, ucValue);
}
