/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : ScalerDDomainInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

#if(_PANEL_EXIST_MULTIPANEL == _ON)
extern BYTE g_ucDDomainPanelIndex;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerDDomainBackgroundEnable(bit bEnable);
extern void ScalerDDomainBackgroundSetColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue);
extern void ScalerDDomainPatternGenEnable(bit bEnable);
extern void ScalerDDomainPatternGenAdjustColor(BYTE ucRed, BYTE ucGreen, BYTE ucBlue);
extern void ScalerDisplayInitialTable(void);
extern void ScalerDisplayLvdsDrivingControl(BYTE ucData, BYTE ucClock);

#if(_OCC_SUPPORT == _ON) 
extern void ScalerDDomainPatternGenShowBatch7Pattern(BYTE ucRed, BYTE ucGreen, BYTE ucBlue);  
#endif

