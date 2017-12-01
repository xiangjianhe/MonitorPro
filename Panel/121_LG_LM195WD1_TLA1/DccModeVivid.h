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
// ID Code      : DccModeVivid.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// DCC MODE VIVID
//****************************************************************************
BYTE code tDCC_VIVID[] =
{
    //control
	0x04,  0x66,  0xc3,  
	0xb4,  0xff,  0x00,  
	0x10,  0x0c,  0x18,

    //usercurve
	0x09,  0x17,  0x28,  0x3c,  
	0x4e,  0x5f,  0x70,  0x84,  
	0x9a,  0xad,  0xbf,  0xcf,  
	0xdd,  0xec,  0xfa,  0xff,  	
	0x10,  0x00,  0x00,
	0x54,  0x14,  0x34,  0x23,  
};
