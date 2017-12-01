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
// ID Code      : OsdMapRotation.c
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
void ScalerOsdFontLibraryRotation(void);
void ScalerOsdMapRotation(EnumOsdRotateType enumOsdRotateType, EnumOsdRotateMapA enumOsdRotateMapA, BYTE ucMapARowSize, EnumOsdRotateMapB enumOsdRotateMapB, BYTE ucMapBRowSize, EnumOsdRotateFontLib enumOsdRotateFontLib);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : None
// Input Value  : None
// Output Value : 
//--------------------------------------------------
void ScalerOsdFontLibraryRotation(void)
{
    WORD i = 0;

    for(i = 100 ; i > 0 ; i--)
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);

        if((ScalerOsdFrameControlByteGet(0x016, _OSD_BYTE0) & _BIT3) == 0x00)
        {
            break;
        }
    }
}



//--------------------------------------------------
// Description  : Set Osd rotation
// Input Value  : ucRotateFlage -> Rotate status (now)
//                enumOsdRotateType    -> _OSD_ROTATE_DEGREE_0 or _OSD_ROTATE_DEGREE_90 or _OSD_ROTATE_DEGREE_270
//                enumOsdRotateMapA    -> _OSD_MAP_A_REMAPPING_DISABLE or _OSD_MAP_A_REMAPPING_ENABLE
//                ucMapARowSize        -> MapA Row size
//                enumOsdRotateMapB    -> _OSD_MAP_B_REMAPPING_DISABLE or _OSD_MAP_B_REMAPPING_ENABLE
//                ucMapBRowSize        -> MapB Row size
//                enumOsdRotateFontLib -> _OSD_FONT_LIB_ROTATION_DISABLE or _OSD_FONT_LIB_ROTATION_ENABLE
// Output Value : 
//--------------------------------------------------
void ScalerOsdMapRotation(EnumOsdRotateType enumOsdRotateType, EnumOsdRotateMapA enumOsdRotateMapA, BYTE ucMapARowSize, EnumOsdRotateMapB enumOsdRotateMapB, BYTE ucMapBRowSize, EnumOsdRotateFontLib enumOsdRotateFontLib)
{
    BYTE ucTemp = 0;

    ucTemp = ScalerOsdFrameControlByteGet(0x016, _OSD_BYTE0);
    ScalerOsdFrameControlByte(0x016, _OSD_BYTE0, ((ucTemp & ~(_BIT2 | _BIT1)) | (BYTE)enumOsdRotateMapA << 2 | (BYTE)enumOsdRotateMapB << 1));

    if((ucTemp & _BIT0) == _BIT0)
    {
        if((ucTemp & _BIT4) == _BIT4)
        {
            ucTemp = _OSD_ROTATE_DEGREE_90;     // CW
        }
        else
        {
            ucTemp = _OSD_ROTATE_DEGREE_270;    // CCW
        }
    }
    else
    {
        ucTemp = _OSD_ROTATE_DEGREE_0;
    }

    ScalerOsdFrameControlAllByte(0x015, _OSD_WITHOUT_DB, ucMapARowSize, ucMapARowSize, ucMapBRowSize);

    if(ucTemp == enumOsdRotateType)
    {
        return;
    }

    if(ucTemp == _OSD_ROTATE_DEGREE_90)
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x00);
        ScalerOsdFrameControlByte(0x016, _OSD_BYTE0, (_BIT4 | _BIT3));     // _OSD_ROTATE_CW

        ScalerOsdFontLibraryRotation();
    }
    else if(ucTemp == _OSD_ROTATE_DEGREE_270)
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x00);
        ScalerOsdFrameControlByte(0x016, _OSD_BYTE0, (_BIT3));     // _OSD_ROTATE_CW

        ScalerOsdFontLibraryRotation();
    }

    if(enumOsdRotateType == _OSD_ROTATE_DEGREE_0)
    {
        return;
    }
    else if(enumOsdRotateType == _OSD_ROTATE_DEGREE_90)
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x01);
        ScalerOsdFrameControlByte(0x016, _OSD_BYTE0, (_BIT4 | (BYTE)enumOsdRotateFontLib << 3 | (BYTE)enumOsdRotateMapA << 2 | (BYTE)enumOsdRotateMapB << 1) | _BIT0);       // _OSD_ROTATE_CW
    }
    else if(enumOsdRotateType == _OSD_ROTATE_DEGREE_270)
    {
        ScalerOsdFrameControlByte(0x003, _OSD_BYTE2, 0x01);
        ScalerOsdFrameControlByte(0x016, _OSD_BYTE0, ((BYTE)enumOsdRotateFontLib << 3 | (BYTE)enumOsdRotateMapA << 2 | (BYTE)enumOsdRotateMapB << 1) | _BIT0);               // _OSD_ROTATE_CCW
    }

    ScalerOsdFontLibraryRotation();
}
