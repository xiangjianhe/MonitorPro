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
// ID Code      : UserProject.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if((_PROJECT == _RL6229_PROJECT) && (_3D_SUPPORT == _ON))
#define _OSD_3D_FUNCTION                            _ON

#else
#define _OSD_3D_FUNCTION                            _OFF

#endif

#if((_PROJECT != _RL6229_PROJECT) && (_OSD_3D_FUNCTION == _ON))
#warning "OSD 3D FUNCTION SUPPORT ON!!"
#endif

#define _FACTORY_ONE_PIECE_MARK_SUPPORT             _ON
