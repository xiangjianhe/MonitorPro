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
// ID Code      : Osd3DOutputMode.c
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
void ScalerOsd3DOutputMode(bit b3DModeEnable, bit b3DOutputMode);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Set write protection for SRAM when OSD is on
// Input Value  : b3DModeEnable -> _ENABLE or _DISABLE
//                b3DOutputMode -> _ENABLE or _DISABLE
// Output Value : 
//--------------------------------------------------
void ScalerOsd3DOutputMode(bit b3DModeEnable, bit b3DOutputMode)
{
    BYTE ucTemp = 0;

    ucTemp = (ScalerOsdFrameControlByteGet(0x017, _OSD_BYTE0) & ~(_BIT2 | _BIT1)) | ((BYTE)b3DModeEnable << 2) | ((BYTE)b3DOutputMode << 1);
    ScalerOsdFrameControlByte(0x017, _OSD_BYTE0, ucTemp);
}               
                           