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
// ID Code      : OsdRollUp.c
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
void ScalerOsdRollUp(bit bEnable, BYTE ucRowStart, BYTE ucRowBack);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set OSD RollUp function
// Input Value  :  bEnable    -> _ENABLE or _DISABLE
//                 ucRowStart -> Set RollUp start (end) row
//                 ucRowBack  -> Set RollUp reposition row
// Output Value : 
//--------------------------------------------------
void ScalerOsdRollUp(bit bEnable, BYTE ucRowStart, BYTE ucRowBack)
{
    BYTE ucTemp[2] = {0};
    WORD usCharCommandAddress = 0;

    ucTemp[0] = ScalerOsdFrameControlByteGet(0x008, _OSD_BYTE0) & ~(_BIT7 | _BIT6);
    ScalerOsdFrameControlByte(0x008, _OSD_BYTE0, (ucTemp[0] | ((BYTE)bEnable << 7)));

    ucTemp[0] = ScalerOsdFrameControlByteGet(0x004, _OSD_BYTE0);
    ucTemp[1] = ScalerOsdFrameControlByteGet(0x004, _OSD_BYTE1);
    usCharCommandAddress = (WORD)((ucTemp[1] & 0xF0) << 4) | ucTemp[0];
    usCharCommandAddress = usCharCommandAddress + (ucRowStart * GET_OSD_MAPA_COL_MAX());

    ScalerOsdFrameControlByte(0x008, _OSD_BYTE1, ucRowStart);
    ScalerOsdFrameControlByte(0x008, _OSD_BYTE2, ucRowBack);
             
    ScalerOsdFrameControlByte(0x009, _OSD_BYTE0, ((usCharCommandAddress & 0xF00) >> 4) | (ScalerOsdFrameControlByteGet(0x009, _OSD_BYTE0) & 0x0F));
    ScalerOsdFrameControlByte(0x009, _OSD_BYTE1, (usCharCommandAddress & 0x0FF));
}               
