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
// ID Code      : OsdVerticalStartSelect.c
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
void ScalerOsdVerticalStartSelect(EnumOsdVsyncSelectType enumOsdVsyncSelectType);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set Osd vertical start input signal source select 
// Input Value  : enumOsdVsyncSelectType ->  _OSD_VSYNC_SELECT_DVS or _OSD_VSYNC_SELECT_ENA
// Output Value :  
//--------------------------------------------------
void ScalerOsdVerticalStartSelect(EnumOsdVsyncSelectType enumOsdVsyncSelectType)
{
    BYTE ucTemp = 0;

    ucTemp = (ScalerOsdFrameControlByteGet(0x003, _OSD_BYTE0) & ~(_BIT4)) | (BYTE)enumOsdVsyncSelectType << 4;
    ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, ucTemp);
}


/* 
//--------------------------------------------------
// example
//--------------------------------------------------
    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_ENA);
*/
