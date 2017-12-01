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
// ID Code      : DccModeGame.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// DCC MODE GAME
//****************************************************************************
BYTE code tDCC_GAME[] =
{
    //control
    0x84, 0xaa, 0xc3,
    0xb4, 0xf8, 0x08,
    0x10, 0x0c, 0x18,

    //usercurve
    0x0a, 0x18, 0x26, 0x36,
    0x46, 0x58, 0x6a, 0x80,
    0x96, 0xa8, 0xba, 0xca,
    0xd8, 0xe8, 0xf6, 0x00,
    0x10, 0x00, 0x00,
    0x64, 0x14, 0x32, 0x00
}; 
