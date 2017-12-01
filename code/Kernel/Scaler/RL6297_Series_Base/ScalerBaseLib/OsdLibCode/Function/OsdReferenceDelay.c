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
// ID Code      : OsdReferenceDelay.c
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
void ScalerOsdReferenceDelay(EnumOsdMapType enumOsdMapType, EnumOsdReferenceType enumOsdReferenceType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set osd delay reference to which osd
// Input Value  : enumOsdMapType       -> _OSD_A or _OSD_B
//                enumOsdReferenceType -> _OSD_FIRST_DELAY or _OSD_SECOND_DELAY
// Output Value : 
//--------------------------------------------------
void ScalerOsdReferenceDelay(EnumOsdMapType enumOsdMapType, EnumOsdReferenceType enumOsdReferenceType)
{
    BYTE ucTemp[2] = {0};
    ucTemp[1] = (enumOsdMapType == _OSD_A) ? ~_BIT2 : ~_BIT1;
    ucTemp[0] = (ScalerOsdFrameControlByteGet(0x008, _OSD_BYTE0) & ucTemp[1]) | (BYTE)enumOsdReferenceType << (2 - (BYTE)enumOsdMapType);
    ScalerOsdFrameControlByte(0x008, _OSD_BYTE0, ucTemp[0]);
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdReferenceDelay(_OSD_B, _OSD_SECOND_DELAY);
*/



