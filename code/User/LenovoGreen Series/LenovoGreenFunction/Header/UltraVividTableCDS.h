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
// ID Code      : UltraVividCDS.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
// ULTRAVIVID TABLE CDS
//----------------------------------------------------------------------------------------------------

#if((_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_0) || (_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_2))
BYTE code tCOLOR_ULTRAVIVID_SETTING_CDS[] =
{
    4,  _NON_AUTOINC,   0x9F,   0x13,
    13, _AUTOINC,       0xA0,   0xF8, 0x00, 0x02, 0x5C, 0x02, 0xF6, 0x03, 0xBB, 0x03, 0x11,
    11, _AUTOINC,       0xB2,   0x00, 0x1E, 0x1E, 0x00, 0x28, 0x00, 0x28, 0x50,
    _END
};

#elif(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_1)   // Elif of #if(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_0)

#define tCOLOR_ULTRAVIVID_SETTING_CDS           _NULL_POINTER

#endif  // End of #if(_ULTRA_VIVID_TABLE_TYPE == _ULTRA_VIVID_GEN_0)


