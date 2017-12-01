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
// ID Code      : DccModePhoto.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// DCC MODE PHOTO
//****************************************************************************
BYTE code tDCC_PHOTO[] =
{
    //control
    0x86, 0x66, 0xc3,
    0xb4, 0xf8, 0x08,
    0x10, 0x0c, 0x18,

    //usercurve
    0x15, 0x1f, 0x2f, 0x3f,
    0x4f, 0x5f, 0x6f, 0x80,
    0x91, 0xa1, 0xb1, 0xc1,
    0xd1, 0xe1, 0xf1, 0x00,
    0x10, 0x00, 0x00,
    0x00, 0x14, 0x00, 0x00,
};
