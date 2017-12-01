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
// ID Code      : OsdDrawGridLine.c
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
StructOsdGridWindow g_stOsdGridWindow = {0};


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerOsdDrawGridLine(void);
void ScalerOsdDrawGridLinePanelPitch(WORD ucPitchHorizontal, WORD ucPitchVertical);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Draw grid line
// Input Value  : 
// Output Value : 
//--------------------------------------------------
void ScalerOsdDrawGridLine(void)
{
    BYTE ucTemp[3] = {0};    

    if((GET_OSD_GRID_WINDOW_NUMBER() == _OSD_WINDOW_2) || (GET_OSD_GRID_WINDOW_NUMBER() == _OSD_WINDOW_3) || (GET_OSD_GRID_WINDOW_NUMBER() == _OSD_WINDOW_4))
    {
        ucTemp[0] = ((BYTE)GET_OSD_GRID_LINE_WIDTH() << 6) | (BYTE) GET_OSD_GRID_LINE_COLOR();
        ucTemp[1] = ((BYTE)GET_OSD_GRID_LINE_HORIZONTAL_ENABLE() << 7) | ((BYTE)GET_OSD_GRID_LINE_VERTICAL_ENABLE() << 6) | (BYTE)GET_OSD_GRID_LINE_OFFSET();
        ucTemp[2] = (BYTE)GET_OSD_GRID_LINE_PITCH() & 0xFF;
        ScalerOsdFrameControlAllByte(0x183 + (((BYTE)GET_OSD_GRID_WINDOW_NUMBER() - _OSD_WINDOW_2) * 7), _OSD_WITHOUT_DB, ucTemp[0], ucTemp[1], ucTemp[2]);
    
        ucTemp[0] = ((GET_OSD_GRID_LINE_PITCH() & 0xFF00) >> 7) | (BYTE)GET_OSD_GRID_LINE_FUNCTION_ENABLE();
        ScalerOsdFrameControlByte(0x184 + (((BYTE)GET_OSD_GRID_WINDOW_NUMBER() - _OSD_WINDOW_2) * 7), _OSD_BYTE0, ucTemp[0]);
    }
}

/*
//--------------------------------------------------
// example
//--------------------------------------------------
// bGridLineOffset: Width (in pixel) from window start to the first grid line
// bGridLinePitch: Distance (in um) between two grid lines. For a distance of 1cm, the setting should be bGridLinePitch = 0x2710 in hexadecimal
//--------------------------------------------------
    code StructOsdGridWindow g_stOsdWindowGridTest  = { _OSD_WINDOW_2,        //bGridLineWindowNumber    
                                                        1,                    //bGridLineWidth           
                                                        1,                    //bGridLineColor           
                                                        _DISABLE,             //bGridLineHorizontalEnable
                                                        _ENABLE,              //bGridLineVerticalEnable  
                                                        0x03,                 //bGridLineOffset          
                                                        0x2710,               //bGridLinePitch           
                                                        _ENABLE               //bGridFunctionEnable      
                                                      };                                       
    g_stOsdGridWindow = g_stOsdWindowGridTest;
    ScalerOsdDrawGridLine();
*/




//--------------------------------------------------
// Description  : Set grid line pitch pixel
// Input Value  : ucPitchHorizontal -> Horizontal pitch
// Input Value  : ucPitchVertical   -> Vertical pitch
// Output Value : 
//--------------------------------------------------
void ScalerOsdDrawGridLinePanelPitch(WORD ucPitchHorizontal, WORD ucPitchVertical)
{
    BYTE ucTemp[3] = {0};
    ucTemp[0] = ((ucPitchHorizontal & 0x700) >> 4) | ((ucPitchVertical & 0x700) >> 8);
    ucTemp[1] = LOBYTE(ucPitchHorizontal);
    ucTemp[2] = LOBYTE(ucPitchVertical);
    ScalerOsdFrameControlAllByte(0x12, _OSD_WITHOUT_DB, ucTemp[0], ucTemp[1], ucTemp[2]);
}


/*
//--------------------------------------------------
// example
//--------------------------------------------------
// PanelPitch is composed of 9 bits integer part and 2 bits fractional part. It shold be set based on Panel Spec.
// For example, if panel pitch is 248.25 by 248.25, the interger part is 11111000 and the fractional part is 01.
// Therefore the setting of ucPitchHorizontal and ucPitchVertical are 011 1110 0001 in binary or 993 in decimal.
//--------------------------------------------------
    ScalerOsdDrawGridLinePanelPitch(993, 993);
*/
