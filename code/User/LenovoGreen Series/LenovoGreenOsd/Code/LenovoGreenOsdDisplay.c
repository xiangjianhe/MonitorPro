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
// ID Code      : UserOSDDisplay.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDDISPLAY__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LEONVO_GREEN_OSD)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#define    _Logo_0x00        0x00+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x01        0x01+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x02        0x02+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x03        0x03+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x04        0x04+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x05        0x05+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x06        0x06+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x07        0x07+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x08        0x08+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x09        0x09+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0a        0x0a+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0b        0x0b+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0c        0x0c+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0d        0x0d+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0e        0x0e+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x0f        0x0f+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x10        0x10+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x11        0x11+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x12        0x12+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x13        0x13+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x14        0x14+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x15        0x15+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x16        0x16+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x17        0x17+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x18        0x18+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x19        0x19+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1a        0x1a+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1b        0x1b+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1c        0x1c+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1d        0x1d+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1e        0x1e+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x1f        0x1f+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x20        0x20+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x21        0x21+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x22        0x22+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x23        0x23+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x24        0x24+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x25        0x25+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x26        0x26+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x27        0x27+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x28        0x28+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x29        0x29+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2a        0x2a+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2b        0x2b+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2c        0x2c+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2d        0x2d+_1BIT_EPA_LOG_ICON_START
#define    _Logo_0x2e        0x2e+_1BIT_EPA_LOG_ICON_START

//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)
//20120801 Abel 1Bit Logo Modify
BYTE code LENOVO_LOGO_COMMAND[]=
{
#if ( ( _PANEL_DH_WIDTH==1440 ) && ( _PANEL_DV_HEIGHT == 900 ) )
    //////////////////////////////////////////////////
    //row 0
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xd6,0xd7,        

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    
    //////////////////////////////////////////////////
    //row 1
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xd8,0xd9,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    

    //////////////////////////////////////////////////
    //row 2 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xda,0xdb,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    

    //////////////////////////////////////////////////
    //row 3 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xdc,0xdd,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    

    //////////////////////////////////////////////////
    //row 4 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xde,0xdf,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,    
    //////////////////////////////////////////////////
    //row 5 (1bit字4個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe0,0xe1,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,

    //////////////////////////////////////////////////
    //row 6
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe2,0xe3, 
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,

    //////////////////////////////////////////////////
    //row 7
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe4,0xe5,   
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,

    //////////////////////////////////////////////////
    //row 8
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe6,0xe7,0xe8,   
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,            
    //////////////////////////////////////////////////
    //row 9
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xe9,0xea,0xeb,0xec,0xed,    
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,          
    //////////////////////////////////////////////////
    //row 10
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xee,0xef,0xf0,0xf1,0xf2,     
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,   

    //////////////////////////////////////////////////
    //row 11
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xf3,0xf4,0xf5,     
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,      
    //////////////////////////////////////////////////
    //row 12
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xf6,0xf7,0xf8,      
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,    
    //////////////////////////////////////////////////
    //row 13
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE0, 屬性(使用char blank設定)
        9,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x6c,0xf9,0xfa,0xfb,      
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 14    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(0)),       //FONTBYTE1, 文字Index
        53,_NON_AUTOINC,0x92,
        0x00,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x04,0x05,0x06,0x06,0x06,0x07,0x08,0x09,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x0a,0x04,0x0b,0x06,0x06,0x06,0x0c,0x04,0x0d,0x06,0x0e,0x04,0x0f,0x10,0x11,0x12,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x7f,0x80,0x81,0x82,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(13)),      //FONTBYTE2, 文字顏色(紅色點)
        6,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
        
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(67)),     //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(67)),     //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x00,0x01,0x02,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 15      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(0)),      //FONTBYTE1, 文字Index
        53,_NON_AUTOINC,0x92,      
        0x13,0x14,0x15,0x16,0x17,0x14,0x18,0x19,0x16,0x1a,0x06,0x06,0x06,0x1b,0x1c,0x1d,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x1e,0x16,0x1f,0x06,0x06,0x06,0x20,0x16,0x21,0x06,0x22,0x16,0x23,0x24,0x25,0x26,0x06, 0x06,0x06,0x06,0x06,0x06,0x06,0x83,0x84,0x85,0x86,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(13)),     //FONTBYTE2, 文字顏色(紅色點)
        6,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
        
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x03,0x04,0x05,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 16        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(0)),      //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,                                                                                                                                                                                                                                  
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x06,0x2f,0x2f,0x30,0x31,0x32,0x33,0x1e,0x16,0x1f,0x34,0x2d,0x35,0x36,0x16,0x37,0x06,0x38,0x16,0x39,0x3a,0x2d,0x3b,0x06,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x2d,0x8e,0x06,0x8f,0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x2d,0x99,   

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
            
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x06,0x07,0x08,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 17     
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(0)),     //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x3c,0x3d,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x40,0x41,0x16,0x42,0x1e,0x16,0x1f,0x43,0x16,0x44,0x45,0x16,0x46,0x47,0x16,0x16,0x48,0x19,0x16,0x1a,0x06,0x9a,0x16,0x9b,0x9c,0x16,0x9d,0x9e,0x16,0x16,0x06,0x9f,0x16,0xa0,0xa1,0x16,0xa2,0x49,0x16,0xa3,0xa4,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x09,0x0a,0x0b,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 18      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x1f,0x4b,0x16,0x4c,0x4d,0x16,0x4e,0x4f,0x16,0x50,0x06,0x19,0x16,0x1a,0x06,0xa6,0x16,0xa7,0x9e,0x16,0x3f,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x0c,0x0d,0x0e,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 19  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,     
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x51,0x16,0x52,0x06,0x53,0x16,0x54,0x55,0x16,0x56,0x06,0x19,0x16,0x1a,0x06,0xab,0xac,0xad,0xae,0xaf,0xb0,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,   

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x0f,0x10,0x11,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 20      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x57,0x16,0x58,0x06,0x59,0x16,0x5a,0x5b,0x16,0x5c,0x06,0x19,0x16,0x1a,0x06,0x06,0xb1,0xb2,0x16,0xb3,0xb4,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(64)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                   
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x12,0x13,0x14,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 21  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(0)),   //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x5d,0x5e,0x5f,0x60,0x61,0x5e,0x16,0x62,0x16,0x63,0x06,0x19,0x16,0x1a,0x06,0xb5,0xb6,0xb7,0xb8,0x16,0xb9,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,    

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(64)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x15,0x16,0x17,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 22  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x1f,0x64,0x16,0x65,0x06,0x66,0x16,0x67,0x16,0x68,0x06,0x19,0x16,0x1a,0x06,0xba,0x16,0xaa,0xbb,0x16,0x3f,0x9e,0x16,0x16,0x06,0xa8,0x16,0xa9,0x1e,0x16,0x1f,0x49,0x16,0xaa,0x06,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(64)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
        
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x18,0x19,0x1a,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    //////////////////////////////////////////////////
    //row 23      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(0)),    //FONTBYTE1, 文字Index
        65,_NON_AUTOINC,0x92,      
        0x06,0x06,0x1e,0x16,0x27,0x06,0x06,0x19,0x16,0x1a,0x49,0x16,0x27,0x3e,0x16,0x3f,0x06,0x16,0x16,0x06,0x4a,0x16,0x42,0x1e,0x16,0x1f,0x69,0x16,0x6a,0x06,0x6b,0x16,0x16,0x16,0x6c,0x06,0x19,0x16,0x1a,0x06,0xbc,0x16,0xbd,0xbe,0x16,0xbf,0x9e,0x16,0x16,0x06,0xc0,0x16,0xc1,0xc2,0x16,0xc3,0x49,0x16,0xaa,0x06,0x16,0xa5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(64)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
                
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x1b,0x1c,0x1d,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 24      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(0)),    //FONTBYTE1, 文字Index
        67,_NON_AUTOINC,0x92,  
        0x06,0x06,0x6d,0x6e,0x6f,0x06,0x06,0x70,0x6e,0x71,0x72,0x6e,0x6f,0x73,0x6e,0x74,0x06,0x6e,0x75,0x06,0x76,0x6e,0x77,0x78,0x6e,0x79,0x7a,0x6e,0x7b,0x06,0x7c,0x6e,0x6e,0x6e,0x7d,0x06,0x70,0x6e,0x7e,0x06,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0x6e,0x6e,0x06,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0x6e,0xd2,0x06,0x6e,0xd3,0xd4,0xd5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(64)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(64)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x3c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(64)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
            
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x1e,0x1f,0x20,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    
#if(_EPA_LOGO==_ON)	
    //EPA LOGO
    //////////////////////////////////////////////////
    //row 26  
        //顯示sion
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,    
    
    //////////////////////////////////////////////////
    //row 27
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,    
    
    
    //////////////////////////////////////////////////
    //row 28
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 29
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 30
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 31
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 32
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x47,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14+_OSD_LOGO_COL2_SIZE*11+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif

#elif ( ( _PANEL_DH_WIDTH==1600 ) && ( _PANEL_DV_HEIGHT == 900 ) )

    //////////////////////////////////////////////////
    //row 0
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x00,0x01,0x02,0x02,0x02,      

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,    
    //////////////////////////////////////////////////
    //row 1
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x03,0x04,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 2 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x05,0x06,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 3 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x07,0x08,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 4 (1bit字2個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x09,0x0a,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
    //////////////////////////////////////////////////
    //row 5 (1bit字4個)
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x0b,0x0c,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 6
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x0d,0x0e,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 7
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x0f,0x10,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 8
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x11,0x12,0x02,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 9
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x13,0x14,0x15,0x16,0x17, 
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 10
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x18,0x19,0x1a,0x1b,0x1c,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 11
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x1d,0x1e,0x1f,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 12
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x20,0x21,0x22,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 13
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x23,0x24,0x25,0x02,0x02,   
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 14
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE0, 屬性(使用char blank設定)
        14,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xa2,0x26,0x27,0x28,0x02,0x02,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 15    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(0)),       //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,
        0x00,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x04,0x05,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x07,0x04,0x08,0x06,0x06,0x06,0x09,0x04,0x0a,0x06,0x0b,0x04,0x0c,0x0d,0x0e,0x0f,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x10,0x0e,0x11,    0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,          

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(14)),   //FONTBYTE0, 屬性(紅色點)
        6,_NON_AUTOINC,0x92,
        0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(14)),   //FONTBYTE1, 文字Index(紅色點)
        6,_NON_AUTOINC,0x92,  
        0x29,0x2a,0x2b,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(14)),      //FONTBYTE2, 文字顏色(紅色點)
        6,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
 
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(70)),     //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xa4,0xa5,0xa6,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 16      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(0)),      //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x12,0x13,0x14,0x15,0x16,0x13,0x17,0x18,0x15,0x19,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x1a,0x15,0x1b,0x06,0x06,0x06,0x1c,0x15,0x1d,0x06,0x1e,0x15,0x1f,0x20,0x21,0x22,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x23,0x21,0x22,      0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,    

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(14)),   //FONTBYTE0, 屬性(紅色點)
        6,_NON_AUTOINC,0x92,
        0x2c,0x2c,0x2c,       
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(14)),   //FONTBYTE1, 文字Index(紅色點)
        6,_NON_AUTOINC,0x92,  
        0x2c,0x2d,0x2e,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(14)),      //FONTBYTE2, 文字顏色(紅色點)
        6,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xa7,0xa8,0xa9,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 17        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(0)),      //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,                                                                                                                                                                                                                                  
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x25,0x26,0x27,0x28,0x06,0x29,0x2a,0x2b,0x2c,0x2a,0x2d,0x2e,0x2f,0x30,0x06,0x1a,0x15,0x1b,0x31,0x2a,0x32,0x33,0x15,0x34,0x06,0x35,0x15,0x36,0x37,0x2a,0x38,0x06,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x37,0x2a,0x38,    0x06,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0xb5,0xb6,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xb7,0xb8,0xb9,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 18     
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(0)),     //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x3f,0x40,0x15,0x41,0x06,0x1a,0x15,0x1b,0x42,0x15,0x43,0x44,0x15,0x15,0x06,0x1a,0x15,0x1b,0x45,0x15,0x46,0x47,0x15,0x48,0x06,0x49,0x15,0x4a,0x4b,0x15,0x4c,0x06,0x4d,0x15,0x4e,0x4f,0x15,0x50,0x4b,0x15,0x4c,    0x06,0xba,0xbb,0xbc,0xbd,0xbb,0xbe,0xbf,0xbb,0xc0,0xc1,0xc2,0xbb,0xc3,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
   
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xc4,0xc5,0xc6,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 19      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x1b,0x52,0x15,0x53,0x54,0x15,0x55,0x06,0x56,0x15,0x57,0x4b,0x15,0x4c,0x06,0x15,0x15,0x58,0x18,0x15,0x59,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
   
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xcd,0xce,0xcf,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 20  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,     
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x5a,0x15,0x5b,0x06,0x5c,0x15,0x5d,0x5e,0x15,0x15,0x5f,0x4b,0x15,0x4c,0x06,0x60,0x15,0x61,0x62,0x63,0x64,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
   
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xd0,0xd1,0xd2,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 21      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x65,0x15,0x66,0x06,0x67,0x15,0x15,0x68,0x15,0x69,0x06,0x4b,0x15,0x4c,0x06,0x6a,0x6b,0x15,0x6c,0x6d,0x06,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(67)),   
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xd3,0xd4,0xd5,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 22  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(0)),   //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x6e,0x15,0x6f,0x06,0x06,0x70,0x15,0x71,0x15,0x72,0x06,0x4b,0x15,0x4c,0x06,0x06,0x73,0x74,0x15,0x75,0x76,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xd6,0xd7,0xd8,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 23  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x77,0x78,0x15,0x79,0x06,0x7a,0x15,0x7b,0x15,0x7c,0x06,0x4b,0x15,0x4c,0x06,0x15,0x15,0x7d,0x7e,0x15,0x59,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xd9,0xda,0xdb,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    //////////////////////////////////////////////////
    //row 24      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,      
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x1b,0x7f,0x15,0x80,0x06,0x81,0x15,0x15,0x15,0x82,0x06,0x4b,0x15,0x4c,0x06,0x15,0x15,0x06,0x24,0x15,0x59,0x4b,0x15,0x4c,    0x06,0xbb,0xbb,0xc7,0xc8,0xbb,0xc9,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0x06,0x06,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
   
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xdc,0xdd,0xde,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 25      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,  
        0x06,0x06,0x24,0x15,0x19,0x06,0x06,0x18,0x15,0x19,0x51,0x15,0x15,0x06,0x1a,0x15,0x1b,0x42,0x15,0x19,0x06,0x15,0x15,0x06,0x1a,0x15,0x1b,0x83,0x15,0x84,0x06,0x85,0x15,0x15,0x15,0x86,0x06,0x4b,0x15,0x4c,0x06,0x87,0x15,0x88,0x89,0x8a,0x8b,0x4b,0x15,0x4c,    0x06,0xdf,0xbb,0xe0,0xe1,0xe2,0xe3,0xbf,0xbb,0xca,0x06,0xcb,0xbb,0xcc,0xe4,0xe5,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0xe6,0xe7,0xe8,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 26      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(0)),    //FONTBYTE1, 文字Index
        69,_NON_AUTOINC,0x92,  
        0x06,0x06,0x8c,0x8d,0x8e,0x06,0x06,0x8f,0x90,0x91,0x92,0x90,0x90,0x06,0x93,0x8d,0x94,0x95,0x8d,0x8e,0x06,0x8d,0x8d,0x06,0x96,0x90,0x97,0x98,0x90,0x99,0x06,0x8f,0x90,0x90,0x90,0x9a,0x06,0x9b,0x8d,0x9c,0x06,0x9d,0x9e,0x9f,0xa0,0xa1,0x06,0xa2,0x8d,0xa3,    0x06,0xe9,0xea,0xeb,0xec,0xed,0x06,0xee,0xef,0xf0,0x06,0xf1,0xef,0xf2,0xf3,0xf4,

        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(67)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,    
        
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(67)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0x4e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(67)),
        6,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(70)),   //FONTBYTE1, 文字Index
        6,_NON_AUTOINC,0x92,
        0x06,0xf5,0xf6,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(70)),   //FONTBYTE2, 文字顏色(灰色)
        6,_NON_AUTOINC,0x92, 
        0x40,0x40,0x40,

#if(_EPA_LOGO==_ON)	
    //EPA LOGO
    //////////////////////////////////////////////////
    //row 28  
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,    
    
    //////////////////////////////////////////////////
    //row 29
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,    
    
    
    //////////////////////////////////////////////////
    //row 30
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 31
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 32
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 33
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 34
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0x80,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif

#elif  ( ( _PANEL_DH_WIDTH==1280 ) && ( _PANEL_DV_HEIGHT == 1024 ) )
    //Logo1280x1024 視窗大小非正方形32字高
    //////////////////////////////////////////////////
    //row 0(9字,1~4blank=20字,5blank=18字)      
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xe4,0x00,0x01,        
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 1(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x03,0x04,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 2(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x05,0x06,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 3(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x07,0x08,
          
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 4(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x09,0x0a,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
    
    //////////////////////////////////////////////////
    //row 5(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x0b,0x0c,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
    
    //////////////////////////////////////////////////
    //row 6(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x0d,0x0e,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
      
    //////////////////////////////////////////////////
    //row 7(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x0f,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,
    
    
    //////////////////////////////////////////////////
    //row 8(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x11,0x12,0x13,0x14,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 9(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x15,0x16,0x17,0x18,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 10(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x19,0x1a,0x1b,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 11(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x1c,0x1d,0x1e,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,
    
    //////////////////////////////////////////////////
    //row 12(9字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
        8,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
        11,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xe4,0x1f,0x20,0x21,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        11,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,
    
    //////////////////////////////////////////////////   
    //row 13(64字) 
        //顯示ThinkVision 
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
        47,_NON_AUTOINC,0x92, 
        0x40,0x41,0x41,0x41,0x41,0x42,0x43,0x44,0x45,0x46,0x46,0x47,0x48,0x49,0x4a,0x46,0x46,0x46,0x46,0x46,0x4b,0x44,0x4c,0x46,0x46,0x4d,0x41,0x4e,0x46,0x4f,0x41,0x50,0x51,0x52,0x53,0x46,0x46,0x46,0x46,0x46,0x54,0x55,0x56,0x57,
        
        //紅點
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+COL(11)),   //FONTBYTE2, 文字顏色
        7,_NON_AUTOINC,0x92, 
        0x50,0x50,0x50,0x50,
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x22,0x23,0x24,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,       
    
    
    //////////////////////////////////////////////////
    //row 14(64字) 
        //顯示ThinkVision      
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE),   //FONTBYTE1, 文字Index
        47,_NON_AUTOINC,0x92,      
        0x58,0x59,0x5a,0x5b,0x59,0x5c,0x5d,0x5a,0x5e,0x46,0x46,0x46,0x5f,0x60,0x61,0x46,0x46,0x46,0x46,0x46,0x62,0x5a,0x63,0x46,0x46,0x64,0x5a,0x65,0x46,0x66,0x5a,0x67,0x68,0x69,0x6a,0x46,0x46,0x46,0x46,0x46,0x6b,0x6c,0x6d,0x6e,
    
        //紅點
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE+COL(11)),   //FONTBYTE2,  文字顏色
        7,_NON_AUTOINC,0x92,      
        0x50,0x50,0x50,0x50,
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x25,0x26,0x27,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 15(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x70,0x71,0x72,0x73,0x74,0x75,0x46,0x76,0x77,0x78,0x79,0x7a,0x62,0x5a,0x63,0x7b,0x7c,0x7d,0x7e,0x7f,0x46,0x80,0x5a,0x81,0x82,0x7c,0x83,0x84,0x85,0x86,0x87,0x88,0x46,0x89,0x8a,0x46,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x44,0x02,0x03,0x04,0x05,
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x28,0x29,0x2a,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*2+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,       
    
    //////////////////////////////////////////////////
    //row 16(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x91,0x92,0x5a,0x93,0x94,0x6f,0x46,0x5a,0x95,0x96,0x5a,0x97,0x62,0x5a,0x63,0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,0xa0,0xa1,0x5a,0xa2,0x5d,0x5a,0xa3,0xa4,0x5a,0x93,0xa5,0x6f,0xa6,0x5a,0xa7,0xa8,0x5a,0xa9,0xaa,0x5a,0x06,0x07,0x5a,0x08,
        
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x2b,0x2c,0x2d,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*3+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,        
    
    //////////////////////////////////////////////////
    //row 17(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0xae,0xaf,0xb0,0x46,0xb1,0x5a,0xb2,0xb3,0xb4,0x46,0xa1,0x5a,0xa2,0xb5,0x5a,0xb6,0xb7,0xb8,0xb9,0xa5,0x6f,0xad,0x5a,0xac,0xba,0x5a,0x97,0xaa,0x5a,0x08,0x62,0x5a,0x08, 
        
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x2e,0x2f,0x30,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*4+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40, 
    
    //////////////////////////////////////////////////
    //row 18(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0xbb,0x5a,0xbc,0x46,0xbd,0x5a,0xbe,0x5a,0xbf,0x46,0xa1,0x5a,0xa2,0xc0,0xc1,0x5a,0xc2,0xc3,0x46,0xa5,0x6f,0xad,0x5a,0xac,0xba,0x5a,0x97,0xaa,0x5a,0x08,0x62,0x5a,0x08,   
        
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x31,0x32,0x33,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*5+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,       
    
    
    //////////////////////////////////////////////////
    //row 19(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0xc4,0x5a,0xc5,0x46,0xc6,0x5a,0xc7,0x5a,0xc8,0x46,0xa1,0x5a,0xa2,0xc9,0xca,0xcb,0x5a,0xcc,0xcd,0xa5,0x6f,0xad,0x5a,0xac,0xba,0x5a,0x97,0xaa,0x5a,0x08,0x62,0x5a,0x08, 
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x34,0x35,0x36,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*6+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,        
    
    
    //////////////////////////////////////////////////
    //row 20(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0x63,0xce,0xcf,0x73,0xd0,0x5a,0xd1,0x5a,0xd2,0x46,0xa1,0x5a,0xa2,0x5d,0x5a,0x93,0xd3,0x5a,0x93,0xa5,0x6f,0xad,0x5a,0xac,0xba,0x5a,0x97,0xaa,0x5a,0x08,0x62,0x5a,0x08, 
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x37,0x38,0x39,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*7+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,        
    
    
    //////////////////////////////////////////////////
    //row 21(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8+COL(51)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        7,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8),   //FONTBYTE1, 文字Index
        58,_NON_AUTOINC,0x92,      
        0x46,0x46,0x5a,0x6f,0x46,0x46,0x5d,0x5a,0x5e,0xab,0x5a,0x93,0x94,0x6f,0x46,0x5a,0xac,0xad,0x5a,0x97,0x62,0x5a,0x63,0xd4,0x5a,0xd5,0xd6,0x5a,0x5a,0x5a,0xd7,0x46,0xa1,0x5a,0xa2,0xd8,0x5a,0xd9,0xda,0x5a,0xdb,0xa5,0x6f,0xdc,0x5a,0xdd,0xde,0x5a,0xdf,0xaa,0x5a,0x08,0x62,0x5a,0x08,     
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x3a,0x3b,0x3c,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*8+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,    
    
    //////////////////////////////////////////////////
    //row 22(64字) 
        //顯示ThinkVision     
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9+COL(48)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        12,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x8c,0x2c,0x8c,0x8c,0x2c,0x2c,0x2c,   
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9),   //FONTBYTE1, 文字Index
        60,_NON_AUTOINC,0x92,      
        0x46,0x46,0xe0,0xe1,0x46,0x46,0xe2,0xe0,0xe3,0xe4,0xe0,0xe5,0xe6,0xe1,0x46,0xe0,0xe7,0xe8,0xe0,0xe9,0xea,0xe0,0xeb,0xec,0xe0,0xed,0xee,0xe0,0xe0,0xe0,0xef,0x46,0xf0,0xe0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0x46,0xf7,0xe1,0x46,0xf8,0xf9,0xfa,0xfb,0x00,0x01,0xe0,0x09,0xea,0xe0,0x09,0x0a,0x0b,
        
    
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9+COL(57)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9+COL(57)),   //FONTBYTE1, 文字Index
        9,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0x18,0x3d,0x3e,0x3f,
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*9+COL(57)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        9,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,   
        
#if(_EPA_LOGO==_ON)	
    //EPA LOGO
    //////////////////////////////////////////////////
    //row 24  
        //顯示sion
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 25
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    
    //////////////////////////////////////////////////
    //row 26
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 
    
    //////////////////////////////////////////////////
    //row 27
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   
    
    //////////////////////////////////////////////////
    //row 28
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 29
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 30
    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        19,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       
    
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0x78,0x48,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,
    
    
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13+_OSD_LOGO_COL2_SIZE*10+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
        19,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif
        
#elif( ( _PANEL_DH_WIDTH==1680 ) && ( _PANEL_DV_HEIGHT == 1050 ) )
//Logo1680x1050 視窗大小非正方形28字高
//////////////////////////////////////////////////
//row 0(12字,1~6blank=20字,7blank=8字)      
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x00,0x01,        

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,         

//////////////////////////////////////////////////
//row 1(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x07,0x08,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,     
    
//////////////////////////////////////////////////
//row 2(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x0e,0x0f,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,       

//////////////////////////////////////////////////
//row 3(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
    13,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x1b,0x1c,0x1d,
      
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    13,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,        

//////////////////////////////////////////////////
//row 4(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x22,0x23,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,         

//////////////////////////////////////////////////
//row 5(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
    13,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x28,0x29,0x2a,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    13,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,      

//////////////////////////////////////////////////
//row 6(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
    12,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x2f,0x30,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    12,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,

//////////////////////////////////////////////////
//row 7(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
    13,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x35,0x36,0x37,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    13,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 8(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x03,0x04,0x05,0x06,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 9(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
    15,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x09,0x0a,0x0b,0x0c,0x0d,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    15,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 10(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
    15,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x10,0x11,0x12,0x13,0x14,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    15,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 11(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x17,0x18,0x19,0x1a,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,      

//////////////////////////////////////////////////
//row 12(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x1e,0x1f,0x20,0x21,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,  
    
//////////////////////////////////////////////////
//row 13(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x24,0x25,0x26,0x27,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,         


//////////////////////////////////////////////////
//row 14(12字) 
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE0, 屬性(使用char blank設定)
    10,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE1, 文字Index
    14,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x60,0x2b,0x2c,0x2d,0x2e,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    14,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,         

//////////////////////////////////////////////////
//row 15       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,     
    0x70,0x71,0x71,0x71,0x71,0x71,0x71,0x72,0x73,0x74,0x75,0x02,0x02,0x02,0x02,0x77,0x78,0x79,0x7a,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x7b,0x74,0x7c,0x02,0x02,0x02,0x7d,0x74,0x74,0x7e,0x02,0x7f,0x74,0x74,0x80,0x81,0x82,0x83,
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(15)),  //FONTBYTE2, 屬性(使用char blank顏色設定)
    7,_NON_AUTOINC,0x92,     
    0x50,0x50,0x50,0x50,
    
    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(53)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    6,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(53)),   //FONTBYTE1, 文字Index
    6,_NON_AUTOINC,0x92,      
    0x01,0x02,0x03,
 
    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x31,0x32,0x33,0x34,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 16       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x84,0x85,0x85,0x85,0x85,0x85,0x85,0x86,0x87,0x85,0x88,0x02,0x2,0x02,0x02,0x89,0x85,0x85,0x8a,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x8b,0x85,0x8c,0x02,0x02,0x02,0x8d,0x85,0x85,0x8e,0x02,0x8f,0x85,0x90,0x91,0x92,0x85,0x93, 
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(15)),  //FONTBYTE2, 屬性(使用char blank顏色設定)
    7,_NON_AUTOINC,0x92,     
    0x50,0x50,0x50,0x50,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(53)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    6,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(53)),   //FONTBYTE1, 文字Index
    6,_NON_AUTOINC,0x92,      
    0x04,0x05,0x06,
 
    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x38,0x39,0x2d,0x3a,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,   
    
//////////////////////////////////////////////////
//row 17       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x94,0x95,0x96,0x85,0x85,0x97,0x95,0x98,0x87,0x85,0x88,0x99,0x9a,0x9b,0x02,0x9c,0x9d,0x9e,0x9f,0x02,0x02,0x02,0x02,0xa0,0xa1,0x02,0x02,0x8b,0x85,0x8c,0x02,0xa2,0xa2,0xa3,0x85,0x85,0xa4,0x02,0xa5,0x85,0xa6,0x02,0xa7,0xa8,0xa9, 

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(15)),  //FONTBYTE2, 屬性(使用char blank顏色設定)
    7,_NON_AUTOINC,0x92,     
    0x50,0x50,0x50,0x50,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(47)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    26,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(47)),   //FONTBYTE1, 文字Index
    26,_NON_AUTOINC,0x92,      
    0x07,0x08,0x09,0x0a,0x00,0x00,0x0b,0x0c,0x0d,0x00,0x00,0x0e,0x0f,0x10,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x13,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x3b,0x3c,0x3d,0x3e,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*2+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 18       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0xac,0xad,0x85,0xae,0xaf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0x85,0xb3,0x85,0x85,0xb4,0x02,0x8b,0x85,0x8c,0xb5,0x85,0x85,0xb6,0xb7,0x85,0xb8,0x02,0xb9,0x85,0xba,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(46)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    28,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(46)),   //FONTBYTE1, 文字Index
    28,_NON_AUTOINC,0x92,      
    0x14,0x15,0x05,0x05,0x16,0x17,0x00,0x18,0x05,0x19,0x00,0x1a,0x1b,0x05,0x05,0x1c,0x1d,0x00,0x1e,0x05,0x1f,0x20,0x05,0x05,0x21, 

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x3f,0x40,0x41,0x42,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*3+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 19       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0xbc,0xbd,0xbe,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc0,0xc1,0xc2,0x85,0x88,0x02,0x8b,0x85,0x8c,0xc3,0x85,0xc4,0x02,0xc5,0x85,0xc6,0x02,0xc7,0x85,0xc8,0x02,0xbb,0x85,0x8c, 

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92,      
    0x22,0x05,0x05,0x23,0x24,0x05,0x25,0x00,0x18,0x05,0x19,0x00,0x26,0x05,0x27,0x28,0x05,0x05,0x29,0x1e,0x05,0x2a,0x2b,0x2c,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x43,0x44,0x45,0x46,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*4+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 20       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0x8c,0xcb,0x85,0xcc,0x02,0xcd,0x85,0xce,0x02,0xcf,0x85,0xd0,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92, 
    0x2d,0x05,0x05,0x2e,0x2f,0x05,0x05,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,    

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x47,0x48,0x49,0x4a,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*5+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 21       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0xd1,0xd2,0x85,0xd3,0x02,0xd4,0x85,0xd5,0xd6,0x85,0x85,0xd7,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92, 
    0x34,0x35,0x05,0x36,0x37,0x38,0x39,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x4b,0x4c,0x4d,0x4e,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*6+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 22       
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0xd8,0x85,0xd9,0xda,0x02,0xdb,0x85,0xdc,0xdd,0x85,0x85,0xde,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(46)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    28,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(46)),   //FONTBYTE1, 文字Index
    28,_NON_AUTOINC,0x92, 
    0x3a,0x3b,0x05,0x3c,0x3d,0x3e,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,
    
    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x4f,0x50,0x51,0x52,
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*7+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 23      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0xdf,0x85,0x85,0xe0,0x02,0xe1,0x85,0x85,0xe2,0x85,0x85,0xe3,0x02,0xbb,0x85,0x8c,
    
    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(47)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    27,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(47)),   //FONTBYTE1, 文字Index
    27,_NON_AUTOINC,0x92, 
    0x3f,0x40,0x05,0x05,0x41,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x53,0x54,0x55,0x56,
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*8+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 24      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9),          //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0x8c,0xe4,0x85,0xe5,0x02,0xe6,0x85,0x85,0xe7,0x85,0xe8,0x02,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92, 
    0x42,0x43,0x43,0x44,0x45,0x05,0x46,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x57,0x4d,0x58,0x59,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*9+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 25      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10),         //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0x8c,0xe9,0x85,0xea,0x02,0xeb,0x85,0x85,0x85,0x85,0xec,0x02,0x02,0xbb,0x85,0x8c,

    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92,    
    0x2d,0x05,0x05,0x32,0x47,0x05,0x05,0x00,0x18,0x05,0x19,0x00,0x05,0x05,0x30,0x31,0x05,0x05,0x32,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x5a,0x5b,0x5c,0x5d,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*10+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 26      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11),         //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,
    0x02,0x02,0xaa,0x85,0x85,0xab,0x02,0x02,0x87,0x85,0x88,0x02,0x84,0x85,0xbf,0xb0,0x85,0x85,0xb1,0xb2,0x85,0xc9,0x02,0xca,0x85,0x88,0x02,0x8b,0x85,0x8c,0xed,0x85,0x85,0xee,0x02,0xef,0x85,0x85,0x85,0xf0,0x02,0x02,0xbb,0x85,0x8c,
    
    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    29,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(45)),   //FONTBYTE1, 文字Index
    29,_NON_AUTOINC,0x92,    
    0x48,0x05,0x05,0x49,0x4a,0x05,0x4b,0x00,0x18,0x05,0x19,0x00,0x4c,0x05,0x4d,0x4e,0x05,0x05,0x4f,0x1e,0x05,0x33,0x00,0x1e,0x05,0x19,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x5e,0x5f,0x60,0x61,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*11+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

//////////////////////////////////////////////////
//row 27      
    //顯示ThinkVi       
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12),         //FONTBYTE1, 文字Index
    48,_NON_AUTOINC,0x92,  
    0x02,0x02,0xf1,0xf2,0xf2,0xf3,0x02,0x02,0xf4,0xf5,0xf6,0x02,0xf7,0xf5,0xf8,0xf9,0xf2,0xf2,0xfa,0xfb,0xf2,0x65,0x02,0x66,0xf2,0x67,0x02,0x68,0xf2,0x69,0x6a,0x6b,0xf2,0x6c,0x02,0x6d,0xf5,0xf5,0xf5,0x6e,0x02,0x02,0x6f,0xf2,0x69, 
   
    //顯示sion
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(46)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
    30,_NON_AUTOINC,0x92,  
    0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(46)),   //FONTBYTE1, 文字Index
    30,_NON_AUTOINC,0x92,    
    0x50,0x51,0x52,0x53,0x54,0x55,0x00,0x56,0x57,0x58,0x00,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x00,0x5f,0x57,0x60,0x00,0x5f,0x57,0x58,0x61,0x62,

    //blank設定    
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(73)),   //FONTBYTE0, 屬性(使用char blank設定)
    6,_NON_AUTOINC,0x92,  
    0x10,0x10,0x10,
         
    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(73)),   //FONTBYTE1, 文字Index
    10,_NON_AUTOINC,0x92,      
    0xf0,0xf0,0xb4,0x02,0x62,0x63,0x64,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*12+COL(73)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
    10,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x40,0x40,0x40,0x40,

#if(_EPA_LOGO==_ON)	
//EPA LOGO
//////////////////////////////////////////////////
//row 30  
    //顯示sion

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,  

//////////////////////////////////////////////////
//row 31

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 


//////////////////////////////////////////////////
//row 32

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 

//////////////////////////////////////////////////
//row 33

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,  

//////////////////////////////////////////////////
//row 34

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 35

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 36

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x44,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15+_OSD_LOGO_COL2_SIZE*13+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,      
#endif

#elif( ( _PANEL_DH_WIDTH==1920 ) && ( _PANEL_DV_HEIGHT == 1080 ) )
      //Logo19200x1080 視窗大小非正方形32字高
    //////////////////////////////////////////////////
    //row 0(13字,1~6blank=20字,7blank=19字)      
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,       

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,  
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x00,0x01,0x02,        

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 1(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x06,0x07,0x08,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 2(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x0f,0x10,0x11,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*2),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 3(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x18,0x19,0x1a,
          
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*3),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 4(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x1f,0x20,0x21,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*4),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 5(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x26,0x27,0x28,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*5),   //FONTBYTE2, 屬性(使用char blank顏色設定 & 文字顏色(灰色))
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,               

    //////////////////////////////////////////////////
    //row 6(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x2d,0x2e,0x2f,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*6),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

      
    //////////////////////////////////////////////////
    //row 7(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x34,0x35,0x36,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*7),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 8(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x3b,0x3c,0x3d,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*8),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 9(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE1, 文字Index
        13,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x42,0x43,0x44,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*9),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        13,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 10(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE1, 文字Index
        12,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x04,0x05,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*10),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        12,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 11(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE1, 文字Index
        16,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*11),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        16,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 12(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE1, 文字Index
        16,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x12,0x13,0x14,0x15,0x16,0x17,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*12),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        16,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,       


    //////////////////////////////////////////////////
    //row 13(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x1b,0x1c,0x1d,0x1e,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*13),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 14(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x22,0x23,0x24,0x25,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*14),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 15(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x29,0x2A,0x2b,0x2c,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*15),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,      
        
    //////////////////////////////////////////////////
    //row 16(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*16),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*16),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x30,0x31,0x32,0x33,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*16),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 17(13字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*17),   //FONTBYTE0, 屬性(使用char blank設定)
        10,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,0x10,0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*17),   //FONTBYTE1, 文字Index
        14,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xe4,0x37,0x38,0x39,0x3a,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*17),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        14,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,       
        
    //////////////////////////////////////////////////
    //row 18(89字)       
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18),          //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x75,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x77,0x78,0x79,0x7a,0x03,0x03,0x03,0x03,0x7b,0x7c,0x7d,0x7e,0x7f,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x80,0x79,0x79,0x81,0x03,0x03,0x03,0x82,0x79,0x79,0x83,0x03,0x84,0x79,0x79,0x85,

        //改變顏色(紅點)
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(16)),          //FONTBYTE1, 文字Index
        8,_NON_AUTOINC,0x92,      
        0x50,0x50,0x50,0x50,0x50,

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        19,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(45)),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,      
        0x05,0x06,0x07,0x08,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x0a,0x0b,0x0c,0x0d,
      
        //blank設定    
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x3e,0x3f,0x40,0x41,

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,       

    //////////////////////////////////////////////////
    //row 19(89字)  
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE),   //FONTBYTE0, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x86,0x87,0x87,0x87,0x87,0x87,0x87,0x87,0x88,0x89,0x87,0x8a,0x03,0x03,0x03,0x03,0x8b,0x8c,0x87,0x8d,0x8e,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x8f,0x87,0x87,0x90,0x03,0x03,0x03,0x91,0x87,0x87,0x92,0x03,0x93,0x87,0x87,0x94,    

        //改變顏色(紅點)
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(16)),          //FONTBYTE1, 文字Index
        8,_NON_AUTOINC,0x92,      
        0x50,0x50,0x50,0x50,0x50,

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        19,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(45)),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,      
        0x0e,0x0f,0x10,0x11,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x12,0x10,0x10,0x14,//0x13,0x14,
     
        //blank設定  
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x45,0x46,0x0a,0x47,
       
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,


    //////////////////////////////////////////////////
    //row 20(89字)    
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2),   //FONTBYTE0, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x95,0x96,0x96,0x87,0x87,0x97,0x96,0x96,0x98,0x89,0x87,0x8a,0x03,0x99,0x9a,0x03,0x03,0x9b,0x9c,0x9d,0x03,0x03,0x03,0x03,0x03,0x9e,0x9f,0x03,0x03,0x8f,0x87,0x87,0x90,0x03,0x03,0x03,0xa0,0x87,0x87,0xa1,0x03,0xa2,0x87,0x87,0xa3,    

        //改變顏色(紅點)
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(16)),          //FONTBYTE1, 文字Index
        8,_NON_AUTOINC,0x92,      
        0x50,0x50,0x50,0x50,0x50,
        
        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        19,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(45)),   //FONTBYTE1, 文字Index
        19,_NON_AUTOINC,0x92,      
        0x15,0x16,0x17,0x18,0x09,0x09,0x19,0x1a,0x1b,0x1c,0x09,0x09,0x1d,0x1e,0x1f,0x20,
     
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x48,0x49,0x4a,0x4b,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*2+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,

    //////////////////////////////////////////////////
    //row 21(89字)    
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0xa4,0xa5,0x87,0x87,0xa6,0x03,0xa7,0x87,0xa8,0x03,0xa9,0xaa,0xab,0xac,0xad,0x87,0xae,0x03,0x8f,0x87,0x87,0x90,0xaf,0x87,0x87,0xb0,0x87,0x87,0xb1,0x03,0xb2,0x87,0x87,0xb3,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x09,0x29,0x2a,0x10,0x10,0x2b,0x2c,0x2d,0x2e,0x10,0x10,0x2f,0x09,0x30,0x31,0x10,0x10,0x10,0x32,0x33,0x09,0x34,0x10,0x35,0x36,0x10,0x10,0x37,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x4c,0x4d,0x4e,0x4f,
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*3+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,
        
    //////////////////////////////////////////////////
    //row 22(89字)      
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0xb4,0xb5,0xb6,0x87,0xb7,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xb9,0xba,0xbb,0x87,0x87,0xbc,0x8f,0x87,0x87,0x90,0xbd,0x87,0xbe,0x03,0xbf,0x87,0xc0,0x03,0xc1,0x87,0x87,0xc2,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x38,0x10,0x10,0x39,0x3a,0x10,0x10,0x3b,0x2e,0x10,0x10,0x3c,0x3d,0x3e,0x10,0x3f,0x40,0x10,0x10,0x41,0x09,0x34,0x10,0x42,0x43,0x44,0x10,0x45,
        
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x50,0x51,0x52,0x53,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*4+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,    

    //////////////////////////////////////////////////
    //row 23(89字)   
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xc3,0xc4,0x87,0xc5,0x03,0xc6,0x87,0xc7,0x03,0xc8,0x87,0x87,0xc9,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x46,0x10,0x10,0x47,0x09,0x10,0x10,0x48,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(80)),   //FONTBYTE0, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x54,0x55,0x0a,0x56,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*5+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,    
      
    //////////////////////////////////////////////////
    //row 24(89字)    
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6),          //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xca,0x87,0x87,0xcb,0x03,0xcc,0x87,0x87,0xcd,0xce,0x87,0xcf,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x4b,0x4c,0x10,0x4d,0x4e,0x4f,0x50,0x51,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,
     
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x57,0x58,0x59,0x5a,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*6+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     
      
    //////////////////////////////////////////////////
    //row 25(89字)     
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xd0,0x87,0xd1,0xd2,0x03,0xd3,0x87,0x87,0xd4,0xd5,0x87,0xd6,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+13*18+89*7+COL(45)),                                     //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x09,0x52,0x53,0x10,0x54,0x55,0x09,0x09,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x09,0x5b,0x5c,0x5d,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*7+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     
      
    //////////////////////////////////////////////////
    //row 26(89字)    
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xd7,0x87,0xd8,0xd9,0x03,0xda,0x87,0x87,0xdb,0x87,0x87,0xdc,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x09,0x09,0x56,0x57,0x10,0x10,0x58,0x59,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x5e,0x5f,0x60,0x61,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*8+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     
       
    //////////////////////////////////////////////////
    //row 27(89字)    
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xdd,0x87,0x87,0xde,0x03,0xdf,0x87,0x87,0xe0,0x87,0x87,0xe1,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x5a,0x5b,0x5b,0x5c,0x5d,0x10,0x10,0x5e,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x62,0x63,0x64,0x65,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*9+COL(80)),   //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     

    //////////////////////////////////////////////////
    //row 28(89字)   
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10),          //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0xe2,0x87,0x87,0xe3,0x03,0xe4,0x87,0x87,0xe5,0x87,0x87,0xe6,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x46,0x10,0x10,0x5f,0x60,0x10,0x10,0x48,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,
        
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x66,0x67,0x68,0x69,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*10+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     
       
    //////////////////////////////////////////////////
    //row 29(89字)     
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0x90,0xe7,0x87,0xe8,0x03,0xe9,0x87,0x87,0x87,0x87,0x87,0xea,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        35,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(45)),   //FONTBYTE1, 文字Index
        35,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x46,0x10,0x10,0x5f,0x2e,0x10,0x10,0x48,0x2e,0x10,0x10,0x3c,0x2e,0x10,0x10,0x48,0x09,0x10,0x10,0x49,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x6a,0x6b,0x6c,0x6d,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*11+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,     

    //////////////////////////////////////////////////
    //row 30(89字)    
        //顯示ThinkV       
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12),            //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0x87,0x87,0x8a,0x03,0x03,0x03,0x89,0x87,0x8a,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0xb8,0x87,0xa8,0x03,0x8f,0x87,0x87,0x90,0x8f,0x87,0x87,0x90,0xeb,0x87,0xec,0xed,0x03,0xee,0x87,0x87,0x87,0x87,0xef,0x03,    
      
        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        37,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(45)),   //FONTBYTE1, 文字Index
        37,_NON_AUTOINC,0x92,      
        0x27,0x10,0x10,0x28,0x61,0x62,0x10,0x63,0x64,0x10,0x10,0x65,0x2e,0x10,0x10,0x3c,0x66,0x67,0x10,0x68,0x69,0x10,0x10,0x6a,0x09,0x34,0x10,0x3c,0x09,0x4a,0x10,0x45,0x09,0x6b,

        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(80)),   //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(80)),   //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x6e,0x6f,0x70,0x71,   
        
        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*12+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,   

    //////////////////////////////////////////////////
    //row 31(89字) 
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(33)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        14,_NON_AUTOINC,0x92,  
        0x2c,0x8c,0x8c,0x2c,0x8c,0x2c,0x8c,0x8c,0x8c,0x2c,0x2c,   
        //顯示ThinkV  
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13),           //FONTBYTE1, 文字Index
        48,_NON_AUTOINC,0x92,      
        0x03,0x03,0x03,0xf0,0xf0,0xf1,0x03,0x03,0x03,0xf2,0xf0,0xf3,0x03,0xf4,0xf0,0xf5,0x03,0xf6,0xf0,0xf7,0x03,0xf4,0xf0,0xf5,0x03,0xf8,0xf0,0xf0,0xf9,0xfa,0xf0,0xf0,0xfb,0x00,0xf0,0xf0,0x01,0x03,0x02,0xf0,0xf0,0xf0,0x03,0x04,0x03,    

        //顯示ision
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(45)),   //FONTBYTE0, 屬性(使用256~511 1Bit字體設定)
        38,_NON_AUTOINC,0x92,  
        0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,

        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(45)),   //FONTBYTE1, 文字Index
        38,_NON_AUTOINC,0x92,      
        0x6c,0x50,0x50,0x6d,0x09,0x6e,0x6f,0x70,0x71,0x72,0x73,0x74,0x75,0x50,0x50,0x76,0x09,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x09,0x7e,0x50,0x7f,0x09,0x80,0x50,0x81,0x09,0x82,0x83,
      
        //blank設定
        5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(80)),    //FONTBYTE0, 屬性(使用char blank設定)
        6,_NON_AUTOINC,0x92,  
        0x10,0x10,0x10,
             
        5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(80)),    //FONTBYTE1, 文字Index
        10,_NON_AUTOINC,0x92,      
        0xf0,0xf0,0xe4,0x03,0x72,0x73,0x74,   

        5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*13+COL(80)),    //FONTBYTE2, 屬性(使用char blank顏色設定)
        10,_NON_AUTOINC,0x92,  
        0x00,0x00,0x00,0x40,0x40,0x40,0x40,   


#if(_EPA_LOGO==_ON)	
//EPA LOGO
//////////////////////////////////////////////////
//row 26  
    //顯示sion

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 

//////////////////////////////////////////////////
//row 27

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   

//////////////////////////////////////////////////
//row 28

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 29

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 30

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 31

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*7),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

//////////////////////////////////////////////////
//row 32

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xcc,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL1_SIZE*18+_OSD_LOGO_COL2_SIZE*14+_OSD_EPA_LOGO_COL_SIZE*8),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif

#endif

    _END,
};

#elif(_LOGO_TYPE == _LENOVO)

BYTE code LENOVO_LOGO_COMMAND[]=
{
    //////////////////////////////////////////////////
    //row 0
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x00,0x01,0x02,0x03,0x04,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,       
    
    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    //////////////////////////////////////////////////
    //row 1
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x00,0x06,0x03,0x03,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,
    0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x21,
    0x23,0x00,0x24,0x21,0x21,0x27,0x28,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    //////////////////////////////////////////////////
    //row 2
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x2F,0x30,0x03,0x31,0x32,0x33,0x03,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x03,0x3B,
    0x3C,0x3D,0x03,0x03,0x3E,0x3F,0x03,0x40,0x41,0x00,0x42,0x03,0x03,0x43,0x03,0x03,
    0x44,0x45,0x46,0x03,0x47,0x48,0x03,0x40,0x41,0x00,0x42,0x03,0x03,0x69,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    //////////////////////////////////////////////////
    //row 3
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x4D,0x03,0x03,0x4E,0x4F,0x03,0x03,0x50,0x51,0x52,0x53,0x54,0x55,0x03,0x03,0x56,
    0x57,0x58,0x03,0x59,0x5A,0x5B,0x03,0x5C,0x5D,0x5E,0x03,0x5F,0x60,0x61,0x03,0x03,
    0x62,0x63,0x64,0x65,0x66,0x67,0x03,0x5C,0x5D,0x5E,0x03,0x5F,0x60,0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    //////////////////////////////////////////////////
    //row 4
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    49,_NON_AUTOINC,0x92,
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     
    0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,0xA6,     

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    49,_NON_AUTOINC,0x92,  
    0x6D,0x4c,0x4c,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x6e,0x6f,0x26,0x68,0x22,
    0x25,0x26,0x26,0x29,0x00,0x2A,0x2B,0x2C,0x2D,0x2E,0x49,0x4A,0x00,0x00,0x4B,0x4C,
    0x4c,0x4c,0x6A,0x00,0x00,0x6B,0x6C,0x2C,0x2D,0x2E,0x49,0x4A,0x00,0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    49,_NON_AUTOINC,0x92,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A, 
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,

#if(_EPA_LOGO==_ON)	
    //////////////////////////////////////////////////
    //row 5
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////
    //row 6
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*1),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*1),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*1),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////
    //row 7
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////
    //row 8
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////
    //row 9
    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    4,_NON_AUTOINC,0x92,
    0x0c,  

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    4,_NON_AUTOINC,0x92,  
    0x00,

    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    4,_NON_AUTOINC,0x92,
    0x00,
    //////////////////////////////////////////////////

    //EPA LOGO
    //////////////////////////////////////////////////
    //row 10  
    //顯示sion

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x00,_Logo_0x00,_Logo_0x01,_Logo_0x02,_Logo_0x03,_Logo_0x04,_Logo_0x05,_Logo_0x06,_Logo_0x00,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0, 

    //////////////////////////////////////////////////
    //row 11

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x08,_Logo_0x09,_Logo_0x0a,_Logo_0x00,_Logo_0x00,_Logo_0x00,_Logo_0x0b,_Logo_0x0c,_Logo_0x0d,_Logo_0x0e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,   

    //////////////////////////////////////////////////
    //row 12

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x0f,_Logo_0x10,_Logo_0x11,_Logo_0x12,_Logo_0x13,_Logo_0x14,_Logo_0x15,_Logo_0x16,_Logo_0x17,_Logo_0x18,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*2),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 13

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x19,_Logo_0x1a,_Logo_0x1b,_Logo_0x1c,_Logo_0x1d,_Logo_0x1e,_Logo_0x1f,_Logo_0x20,_Logo_0x21,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*3),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 14

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x22,_Logo_0x23,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*4),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 15

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x24,_Logo_0x25,_Logo_0x26,_Logo_0x27,_Logo_0x28,_Logo_0x29,_Logo_0x2a,_Logo_0x2b,_Logo_0x2c,_Logo_0x07,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*5),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,

    //////////////////////////////////////////////////
    //row 16

    5,_AUTOINC,0x90,FONTBYTE0(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE0, 屬性(使用char blank設定)
    20,_NON_AUTOINC,0x92,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,0x2c,       

    5,_AUTOINC,0x90,FONTBYTE1(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE1, 文字Index
    20,_NON_AUTOINC,0x92,  
    0xf0,0xf0,0xf0,0xf0,0xf0,0x80,0x10,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2d,_Logo_0x2e,


    5,_AUTOINC,0x90,FONTBYTE2(_OSD_LOGO_ROW_SIZE+1+_OSD_LOGO_COL_SIZE*5+_OSD_SPACE_LOGO_COL_SIZE*5+_OSD_EPA_LOGO_COL_SIZE*6),   //FONTBYTE2, 屬性(使用char blank & 顏色設定)
    20,_NON_AUTOINC,0x92,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,0xa0,
#endif

    _END,

};

#endif


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucLogoTimerCounter = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdDispDisableOsdTimerEvent(void);
void OsdDispMainIcon(void);
void OsdDispKeyInfo(BYTE ucState);
void OsdDispSubStringClear(void);
void OsdDispMainMenuString(BYTE ucState);
void OsdDispMainIconDraw(BYTE ucItem, BYTE ucState);
void OsdDispMainIconChange(BYTE ucItem, BYTE ucState);
void OsdDispMainIconSwitch(void);
void OsdDispSubIcon(BYTE ucItem, BYTE ucState);
void OsdDispSubItem(BYTE ucItem, BYTE ucState);
void OsdDispDrawSlider(BYTE ucRow, BYTE ucColor, BYTE ucPercent, BYTE ucState);
void OsdDispDrawNumber(BYTE ucRow, BYTE ucCol, WORD usValue, BYTE ucLength, BYTE ucColor, BYTE ucAlign, BYTE ucFptsSelect);
void OsdDispSlider(BYTE ucState);
void OsdDispContentClear(void);
void OsdDispContent(BYTE ucState);
void OsdDispMainMenu(BYTE ucState);
void OsdDispBriHotkeyMenu(void);
BYTE OsdDispJudgeSourceType(void);
void OsdDispShowLogo(void);

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
void OsdDisplayLowBlueLightHotKeyMsg(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDispDisableOsdTimerEvent(void)
{
	OsdFuncDisableOsd();
	OsdFuncCloseWindow(_WIN_ALL);
	SET_OSD_STATE(_MENU_NONE);
    ucFactoryOsdState=MENU_FACTORY_START;
    SET_OSD_SLIDER_REDRAW(_ON);//ym20131011 . 
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDispMainIcon(void)
{
    BYTE i;
    
	for(i=0;i< ROW3; i++)
	{
		OsdFuncPutCharSeries(i, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(35));
	}	

#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)		           
	if((GET_LOWBLUELIGHT_STATUS() == _ENABLE) || (GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
#else
	if((GET_COLOR_TEMP_STATUS() == _COLOR_PRESET) && (GET_COLOR_TEMP_TYPE() == _CT_SRGB))
#endif
	{
		OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_STATIC);    // 色溫為sRGB,disable 亮度主icon
	}
	else
	{
		OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_UNSELECT);  
	}
    
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
	    OsdDispSubIcon(_MAIN_ICON_LOWBLUELIGHT, _OSD_UNSELECT);
#endif

	if(SysSourceGetSourceType() == _SOURCE_VGA)
	{
	    OsdDispSubIcon(_MAIN_ICON_POSTION, _OSD_UNSELECT);    
	    OsdDispSubIcon(_MAIN_ICON_SETUP, _OSD_UNSELECT);	
	}
	else
	{
	    OsdDispSubIcon(_MAIN_ICON_POSTION, _OSD_STATIC);    // 非VGA, 將Position、setup disable   
	    OsdDispSubIcon(_MAIN_ICON_SETUP, _OSD_STATIC);		
	}
    
    OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_UNSELECT);   // 畫出其他三個未選中的icon
    OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_UNSELECT);
    OsdDispSubIcon(_MAIN_ICON_EXIT, _OSD_UNSELECT);

    if(GET_FACTORY_MODE() == _TRUE)
    {
        OsdDispMainIconDraw(_MAIN_ICON_FACTORY, _OSD_UNSELECT);  // 畫工場模式 F icon
    }
}    

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//顯示OSD下方提示動作文字
//20120824
void OsdDispKeyInfo(BYTE ucState)
{	    
	BYTE row = ROW14;
	switch(ucState)
	{
		case _KEY_INFO_ALL:
            /*
			OsdFuncPutString(row, COL6, _ENGLISH, tOSD_iBACK, COLOR(_CP_GRAY_26, _CP_GRAY_139), _AT_FS1);
			OsdFuncPutString(row, COL13, _ENGLISH, tOSD_iLEFT, COLOR(_CP_GRAY_26, _CP_GRAY_139), _AT_FS1);
			OsdFuncPutString(row, COL19, _ENGLISH, tOSD_iRIGHT, COLOR(_CP_GRAY_26, _CP_GRAY_139), _AT_FS1);
			OsdFuncPutString(row, COL25, _ENGLISH, tOSD_iOK, COLOR(_CP_GRAY_26, _CP_GRAY_139), _AT_FS1);
            */
            OsdFuncPutIcon2BitTable(row-1, COL6, tOSD_2iKEYITEM1, _CP_GRAYB, _CP_GRAYN, _CP_WHITE2, _CP_GRAYW);  
            OsdFuncPutIcon2BitTable(row, COL13, tOSD_2iKEYITEM2, _CP_GRAYB, _CP_GRAYN, _CP_WHITE2, _CP_GRAYW);  
            OsdFuncPutIcon2BitTable(row, COL19, tOSD_2iKEYITEM3, _CP_GRAYB, _CP_GRAYN, _CP_WHITE2, _CP_GRAYW);  
            OsdFuncPutIcon2BitTable(row, COL25, tOSD_2iKEYITEM4, _CP_GRAYB, _CP_GRAYN, _CP_WHITE2, _CP_GRAYW);  
                        
			OsdFuncPutCharSeries(row+1, COL3, ___, COLOR(_CP_WHITE, _CP_BG), _AT_NORMAL, LENGTH(9));
			OsdFuncPutStringPropCenter(row+1, COL3, WIDTH(9), _PFONT_PAGE_ITEM_0, tOSD_sEXITKEY, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));	
			OsdFuncPutCharSeries(row+1, COL24, ___, COLOR(_CP_WHITE, _CP_BG), _AT_NORMAL, LENGTH(5));            
			OsdFuncPutStringPropCenter(row+1, COL24, WIDTH(5), _PFONT_PAGE_ITEM_1, tOSD_sOKKEY, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));

			break;

		case _KEY_INFO_EXIT:
			OsdFuncPutCharSeries(row+1, COL3, ___, COLOR(_CP_WHITE, _CP_BG), _AT_NORMAL, LENGTH(9));
			OsdFuncPutStringPropCenter(row+1, COL3, WIDTH(9), _PFONT_PAGE_ITEM_0, tOSD_sEXITKEY, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));
			break;

		case _KEY_INFO_CANCEL:
			OsdFuncPutCharSeries(row+1, COL3, ___, COLOR(_CP_WHITE, _CP_BG), _AT_NORMAL, LENGTH(9));
			OsdFuncPutStringPropCenter(row+1, COL3, WIDTH(9), _PFONT_PAGE_ITEM_0, tOSD_sCANCELKEY, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));
			break;

		default:
			break;
		
	}
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//Sub Menu中間說明字串清除
void OsdDispSubStringClear(void)
{
	OsdFuncPutCharSeries(ROW9, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth));
	OsdFuncPutCharSeries(ROW10, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth));
    OsdFuncPutCharSeries(ROW11, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth));
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//Sub Menu Top字串清除
void OsdDispMainStringClear(void)
{
	OsdFuncPutCharSeries(ROW3, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth));
}
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//Sub Title string 字串清除
void OsdDispSubTitleStringClear(void)
{
	OsdFuncPutCharSeries(ROW1, COL8, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth - COL8));
}


#define _NOTE_TEXT_1    ROW1
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//顯示Title字串或說明字串
void OsdDispMainMenuString(BYTE ucState)
{	
	BYTE row = ROW9; // sub string row

	if((ucState >= _MAIN_STRING_PICTURE) && (ucState <= _MAIN_STRING_FACTORY))
	{
		OsdDispMainStringClear();         //Sub Menu Top字串清除
	}
    
	else if((ucState > _MAIN_STRING_FACTORY) && (ucState < _MAIN_STRING_END))
	{
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
	    if((ucState == _MAIN_STRING_LOWBLUELIGHT_ENABLE) || (ucState == _MAIN_STRING_LOWBLUELIGHT_DISABLE))
            OsdDispSubStringClear(); 
        else
#endif
		    OsdDispSubTitleStringClear();          //Sub Menu中間說明字串清除
	}
    
	else if((ucState >= _SUB_STRING_BRIGHTNESS) && (ucState < _SUB_STRING_END))
	{
		OsdDispSubStringClear();          //Sub Menu中間說明字串清除
	}

	switch(ucState)
	{
		case _MAIN_STRING_PICTURE:
			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sBRIGHTNESS_CONTRAST, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
        case _MAIN_STRING_LOWBLUELIGHT:
            if(GET_OSD_LANGUAGE()   == _CHINESE_S)
    			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sLOWBLUELIGHT, _CHINESE_S, COLOR(_CP_GREEN, _CP_BG));
            else
    			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sLOWBLUELIGHT, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));
            break;
#endif
		case _MAIN_STRING_POSITION:
			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sIMAGE_POSITION, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_SETUP:
			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sIMAGE_SETUP, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_PROPERTIES:
			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sIMAGE_PROPERTIES, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_OPTION:
			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sOPTIONS, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_EXIT:
			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sEXIT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_FACTORY:
			OsdFuncPutStringPropCenter(ROW3, COL0, g_ucOsdWidth, _PFONT_PAGE_0, tOSD_sFACTORY_MODE, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_BRIGHTNESS:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sBRIGHTNESS, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_CONTRAST:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sCONTRAST, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

#if(_LENOVO_DPS_SUPPORT == _ON)
		case _MAIN_STRING_DPS:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sDPS, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;
#endif

#if(_USER_DCR_FUNCTION == _ON)
		case _MAIN_STRING_DCR:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sDCR, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;
#endif

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
		case _MAIN_STRING_LOWBLUELIGHT_ENABLE:
            if(GET_OSD_LANGUAGE()   == _CHINESE_S)
    			OsdFuncPutStringPropCenter(ROW9, COL0, g_ucOsdWidth, _PFONT_PAGE_1, tOSD_sLOWBLUELIGHT_ENABLE, _CHINESE_S, COLOR(_CP_GREEN, _CP_BG));
            else
    			OsdFuncPutStringPropCenter(ROW9, COL0, g_ucOsdWidth, _PFONT_PAGE_1, tOSD_sLOWBLUELIGHT_ENABLE, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));
            break;
			
		case _MAIN_STRING_LOWBLUELIGHT_DISABLE:
            if(GET_OSD_LANGUAGE()   == _CHINESE_S)
    			OsdFuncPutStringPropCenter(ROW9, COL0, g_ucOsdWidth, _PFONT_PAGE_1, tOSD_sLOWBLUELIGHT_DISABLE, _CHINESE_S, COLOR(_CP_GREEN, _CP_BG));
            else
    			OsdFuncPutStringPropCenter(ROW9, COL0, g_ucOsdWidth, _PFONT_PAGE_1, tOSD_sLOWBLUELIGHT_DISABLE, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));
            break;
#endif

		case _MAIN_STRING_HPOS:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sHPOS, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_VPOS:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sVPOS, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_MANUAL:
            OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sMANUAL, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;
			
		case _MAIN_STRING_COLOR:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sCOLOR, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_PRESET:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sPRESET, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_CUSTOM:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sCUSTOM, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_INPUT:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sINPUT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_SCALING:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sSCALING, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;	
            
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
		case _MAIN_STRING_BLUELIGHT:
            if( GET_OSD_LANGUAGE() == _CHINESE_S)
            {
                OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sBLUELIGHT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
            }
            else
            {
    			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sBLUELIGHT, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));
            }
			break;	
#endif            
            
#if(_OD_SUPPORT == _ON)
		case _MAIN_STRING_OD:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sOD, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;			
#endif
		case _MAIN_STRING_INFORMATION:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sINFORMATION, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;
			
		case _MAIN_STRING_LANGUAGE:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sLANGUAGE, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_OSDPOS:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sOSDPOS, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;

		case _MAIN_STRING_DEFAULT:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sFACTORY_DEFAULT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;			

		case _MAIN_STRING_ACCESSIBILITY:
			OsdFuncPutStringProp(_NOTE_TEXT_1, COL10, _PFONT_PAGE_0, tOSD_sACCESSIBILITY, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			break;
			
//		case _MAIN_STRING_BUTTON_REPEAT:
//			OsdFuncPutStringProp(ROW3, COL5, _PFONT_PAGE_0, tOSD_sBUTTON_REPEAT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
//			break;
			
//		case _MAIN_STRING_MENU_TIMEOUT:
//			OsdFuncPutStringProp(ROW3, COL5, _PFONT_PAGE_0, tOSD_sMENU_TIMEOUT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
//			break;


        //中間說明字串(兩行)
		case _SUB_STRING_BRIGHTNESS:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sBRIGHTNESS_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sBRIGHTNESS_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
			break;

		case _SUB_STRING_CONTRAST:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sCONTRAST_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sCONTRAST_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
			break;
#if(_LENOVO_DPS_SUPPORT == _ON)
		case _SUB_STRING_DPS:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sDPS_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sDPS_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
			break;

#endif

#if(_USER_DCR_FUNCTION == _ON)
		case _SUB_STRING_DCR:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sDCR_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sDCR_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG)); 	
			break;
		
#endif

		case _SUB_STRING_HPOS:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sHPOS_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sHPOS_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
			break;
			
		case _SUB_STRING_VPOS:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sVPOS_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sVPOS_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
			break;

		case _SUB_STRING_AUTOMATIC:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sAUTOMATIC_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sAUTOMATIC_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));	
			break;

		case _SUB_STRING_MANUAL:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sMANUAL_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sMANUAL_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));	
			break;

		case _SUB_STRING_COLOR:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sCOLOR_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sCOLOR_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));						
			break;

		case _SUB_STRING_INPUT:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sINPUT_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sINPUT_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));								
			break;

		case _SUB_STRING_SCALING:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sSCALING_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sSCALING_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));										
			break;

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
        case _SUB_STRING_BLUELIGHT:
            if( GET_OSD_LANGUAGE() == _CHINESE_S)
                {
			        OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sBLUELIGHT_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
                }
            else
                {
                    OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sBLUELIGHT_COLON, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));
                }
            break;
#endif            
            
#if(_OD_SUPPORT == _ON)
		case _SUB_STRING_OD:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sOD_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sOD_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));										
			break;
#endif
		case _SUB_STRING_INFORMATION:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sINFORMATION_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sINFORMATION_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));
            OsdFuncPutStringProp(row+2, COL1, _PFONT_PAGE_1, tOSD_sINFORMATION_EXPLAIN2, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));	
			break;
			
		case _SUB_STRING_LANGUAGE_SELECT:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sLANGUAGE_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sLANGUAGE_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));												
			break;
			
		case _SUB_STRING_OSDPOSTION_SELECT:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sOSDPOS_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sOSDPOS_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));												
			break;
			
		case _SUB_STRING_DEFAULT_SELECT:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sFACTORY_DEFAULT_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sFACTORY_DEFAULT_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));	
            OsdFuncPutStringProp(row+2, COL1, _PFONT_PAGE_1, tOSD_sFACTORY_DEFAULT_EXPLAIN2, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));
			break;
			
		case _SUB_STRING_ACCESSIBILITY:
			OsdFuncPutStringProp(row, COL1, _PFONT_PAGE_1, tOSD_sACCESSIBILITY_COLON, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringProp(row+1, COL1, _PFONT_PAGE_1, tOSD_sACCESSIBILITY_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));	
            OsdFuncPutStringProp(row+2, COL1, _PFONT_PAGE_1, tOSD_sACCESSIBILITY_EXPLAIN2, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));
			break;

		case _SUB_STRING_SCALING_OFF:
			OsdFuncPutCharSeries(row, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth));
            OsdFuncPutStringProp(ROW10, COL1, _PFONT_PAGE_1, tOSD_sSCALING_OFF_EXPLAIN1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));			
            OsdFuncPutStringProp(ROW11, COL1, _PFONT_PAGE_1, tOSD_sSCALING_OFF_EXPLAIN2, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));			            
			break;

		case _SUB_STRING_SCALING_ON:
			OsdFuncPutCharSeries(row, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth));
            OsdFuncPutStringProp(ROW10, COL1, _PFONT_PAGE_1, tOSD_sSCALING_ON_EXPLAIN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));				            
			break;

		case _SUB_STRING_BUTTON_REPEAT:
			OsdFuncPutStringPropCenter(row, COL0, LENGTH(g_ucOsdWidth), _PFONT_PAGE_1, tOSD_sBUTTON_REPEAT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));		
			break;

		case _SUB_STRING_MENU_TIMEOUT:
			OsdFuncPutStringPropCenter(row, COL0, LENGTH(g_ucOsdWidth), _PFONT_PAGE_1, tOSD_sMENU_TIMEOUT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));		
			break;

        case _SUB_TITLE_STRING_BUTTON_REPEAT:
			OsdFuncPutStringProp(ROW3, COL5, _PFONT_PAGE_1, tOSD_sBUTTON_REPEAT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));		            
            break;
            
        case _SUB_TITLE_STRING_MENU_TIMEOUT:
			OsdFuncPutStringProp(ROW3, COL5, _PFONT_PAGE_1, tOSD_sMENU_TIMEOUT, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));		            
            break;


        
		default:
			break;
	}		
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//顯示Top Icon        
void OsdDispMainIconDraw(BYTE ucItem, BYTE ucState)
{
	BYTE color = COLOR(_CP_WHITE, _CP_BG);

	if((ucState == _OSD_SELECT) || (ucState == _OSD_INDICATE))
	{
		color = COLOR(_CP_GREEN, _CP_BG);
	}
	else if(ucState == _OSD_STATIC)
	{
		color = COLOR(_CP_GRAYB, _CP_BG);
	}

	switch(ucItem)
	{
/*//Eli 20120823 modify osd icon.      
		case _MAIN_ICON_PICTURE:
			OsdFuncPutString(ROW0, COL1, 0, tOSD_iPICTURE, color, _AT_FS1);
			break;

		case _MAIN_ICON_POSTION:
			OsdFuncPutString(ROW0, COL6, 0, tOSD_iPOSITION, color, _AT_FS1);
			break;

		case _MAIN_ICON_SETUP:
			OsdFuncPutString(ROW0, COL11, 0, tOSD_iSETUP, color, _AT_FS1);
			break;

		case _MAIN_ICON_PROPERTIES:
			OsdFuncPutString(ROW0, COL16, 0, tOSD_iPROPERTIES, color, _AT_FS1);
			break;

		case _MAIN_ICON_OPTION:
			OsdFuncPutString(ROW0, COL21, 0, tOSD_iOPTION, color, _AT_FS1);
			break;

		case _MAIN_ICON_EXIT:
			OsdFuncPutString(ROW0, COL26, 0, tOSD_iEXIT, color, _AT_FS1);
			break;
*/			
		case _MAIN_ICON_FACTORY:
			OsdFuncPutChar(ROW1, COL0, _iF, color, _AT_FS1);		
			break;

		default:
			break;		
	}

	if(ucItem != _MAIN_ICON_FACTORY)
	{
		if(ucState == _OSD_SELECT)
		{
			OsdFuncPutChar(ROW2, COL2+((ucItem -_MAIN_ICON_PICTURE)*6), _iUP, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
		}
		else
		{
			OsdFuncPutChar(ROW2, COL2+((ucItem -_MAIN_ICON_PICTURE)*6), ___, COLOR(_CP_BG, _CP_BG), _AT_FS1);
		}
	}	

}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDispMainIconChange(BYTE ucItem, BYTE ucState)
{
	BYTE color = COLOR(_CP_WHITE, _CP_BG);

	if((ucState == _OSD_SELECT) || (ucState == _OSD_INDICATE))
	{
		color = COLOR(_CP_GREEN, _CP_BG);
	}
	else if(ucState == _OSD_STATIC)
	{
		color = COLOR(_CP_GRAYB, _CP_BG);
	}

    OsdDispSubIcon((ucItem -_MAIN_ICON_PICTURE), ucState); 

	if(ucItem == _MAIN_ICON_FACTORY)
	{	
		OsdFuncChangeColor1Bit(ROW1, COL0, WIDTH(1), HEIGHT(1), color);
	}
	else
	{
//		OsdFuncChangeColor1Bit(ROW0, COL1+((ucItem-_MAIN_ICON_PICTURE)*5), WIDTH(3), HEIGHT(2), color);//Eli 20120823 modify osd icon. 

//畫出主icon下方箭頭 
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
		if(ucState == _OSD_SELECT)
		{
			OsdFuncPutChar(ROW2, COL2+((ucItem -_MAIN_ICON_PICTURE)*5), _iUP, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
		}
		else
		{
			OsdFuncPutChar(ROW2, COL2+((ucItem -_MAIN_ICON_PICTURE)*5), ___, COLOR(_CP_BG, _CP_BG), _AT_FS1);
		}
#else
		if(ucState == _OSD_SELECT)
		{
			OsdFuncPutChar(ROW2, COL2+((ucItem -_MAIN_ICON_PICTURE)*6), _iUP, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
		}
		else
		{
			OsdFuncPutChar(ROW2, COL2+((ucItem -_MAIN_ICON_PICTURE)*6), ___, COLOR(_CP_BG, _CP_BG), _AT_FS1);
		}	
#endif
	}
	
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//第一層OSD左右Key動作
void OsdDispMainIconSwitch(void)//Eli 20120823 modify osd icon. 
{
	// from 
	if((GET_OSD_PRE_STATE() >= _OSD_MAIN_BRIGHTCONTRAST) && (GET_OSD_PRE_STATE() <= _OSD_MAIN_TPV_FACTORY))
	{
        OsdDispSubIcon(GET_OSD_PRE_STATE()-_OSD_MAIN_BRIGHTCONTRAST, _OSD_UNSELECT);         //顯示Icon     
        OsdDispMainIconChange(GET_OSD_PRE_STATE()-_OSD_MAIN_BRIGHTCONTRAST, _OSD_UNSELECT);
	}	

	// to
	if((GET_OSD_STATE() >= _OSD_MAIN_BRIGHTCONTRAST) && (GET_OSD_STATE() <= _OSD_MAIN_TPV_FACTORY))
	{
        OsdDispSubIcon(GET_OSD_STATE()-_OSD_MAIN_BRIGHTCONTRAST, _OSD_SELECT);
		OsdDispMainIconChange(GET_OSD_STATE()-_OSD_MAIN_BRIGHTCONTRAST, _OSD_SELECT);			
        OsdDispContent(GET_OSD_STATE()-_OSD_MAIN_BRIGHTCONTRAST);
	}

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)||(_USER_DCR_FUNCTION == _ON))
    if(GET_OSD_STATE() == _OSD_MAIN_IMAGEPROPERTIES)
	{
        if((GET_LOWBLUELIGHT_STATUS() == _ENABLE)
	#if(_USER_DCR_FUNCTION == _ON)	
		||(GET_OSD_DCR_STATUS() == _ON)
	#endif
	)
			
        {
            OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_STATIC); 
        }
        else
        {
            OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT); 
        }
		if(UserAdjustCheckAspectRatio() == _TRUE)
		{
			OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT); 
		}
		else
		{
			OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC); 
		}
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	        
        OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT); 
#endif
	}
#endif
}



#define _COL_CONTENT_TWO_1      12
#define _COL_CONTENT_TWO_2      23
#define _COL_CONTENT_THREE_1      9
#define _COL_CONTENT_THREE_2      17
#define _COL_CONTENT_THREE_3      25
#define _COL_CONTENT_FOUR_1      8
#define _COL_CONTENT_FOUR_2      14
#define _COL_CONTENT_FOUR_3      20
#define _COL_CONTENT_FOUR_4      26
#define _COL_CONTENT_FIVE_1      5
#define _COL_CONTENT_FIVE_2      11
#define _COL_CONTENT_FIVE_3      17
#define _COL_CONTENT_FIVE_4      23
#define _COL_CONTENT_FIVE_5      29


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------

void OsdDispSubIcon(BYTE ucItem, BYTE ucState)
{
	BYTE row = ROW7, col;
	BYTE color0 = _CP_BLACK, color1 = _CP_WHITE, color2 = _CP_GRAYW, color3 = _CP_GRAYB;
    BYTE i;
    
	if((ucState == _OSD_SELECT) || (ucState == _OSD_INDICATE))
	{
		color1 = _CP_GREEN;
		color2 = _CP_GREENW0;        
		color3 = _CP_GREENW1;        
	}
	else if(ucState == _OSD_STATIC)
	{
		color1 = _CP_GRAYB;
		color2 = _CP_GRAYB;        
		color3 = _CP_GRAYB;
	}

    // clear title icon
    if ((ucItem >= _TITLE_ICON_BRIGHTNESS) && (ucItem <= _TITLE_ICON_ACCESSIBILITY))
    {
        for(i=0;i< ROW4; i++)
        {
            OsdFuncPutCharSeries(i, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth));
        }	
    }

	switch(ucItem)
	{
        case _MAIN_ICON_PICTURE:
            row = ROW0;
            col = COL1;
            OsdFuncPutIcon2BitTable(row, col, tOSD_2iPICTURE, color0, color1, color2, color3);  

            break;
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
        case _MAIN_ICON_LOWBLUELIGHT:
            row = ROW0;
            col = COL6;
            OsdFuncPutIcon2BitTable(row, col, tOSD_2iLOWBLUELIGHT, color0, color1, color2, color3);  
            break;
#endif           
        case _MAIN_ICON_POSTION:
            row = ROW0;
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
            col = COL11;
#else
            col = COL7;
#endif           
            OsdFuncPutIcon2BitTable(row, col, tOSD_2iPOSITION, color0, color1, color2, color3);  

            break;
        
        case _MAIN_ICON_SETUP:
            row = ROW0;
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
            col = COL16;
#else
            col = COL13;
#endif           
            OsdFuncPutIcon2BitTable(row, col, tOSD_2iSETUP, color0, color1, color2, color3);  

            break;
        
        case _MAIN_ICON_PROPERTIES:
            row = ROW0;
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
            col = COL21;
#else
            col = COL19;
#endif           
            OsdFuncPutIcon2BitTable(row, col, tOSD_2iPROPERTIES, color0, color1, color2, color3);  

            break;
        
        case _MAIN_ICON_OPTION:
            row = ROW0;
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
            col = COL26;
#else
            col = COL25;
#endif           
            OsdFuncPutIcon2BitTable(row, col, tOSD_2iOPTION, color0, color1, color2, color3);  

            break;
        
        case _MAIN_ICON_EXIT:
            row = ROW0;
            col = COL31;
            OsdFuncPutIcon2BitTable(row, col, tOSD_2iEXIT, color0, color1, color2, color3);  

            break;

#if((_LENOVO_DPS_SUPPORT == _ON)||(_USER_DCR_FUNCTION ==_ON))
		case _SUB_ICON_BRIGHTNESS:		
			col = _COL_CONTENT_THREE_1;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_BRIGHTNESS_SUB, color0, color1, color2, color3);			
			break;

		case _SUB_ICON_CONTRAST:
			col = _COL_CONTENT_THREE_2;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_CONTRAST_SUB, color0, color1, color2, color3);			
			break;
#if(_LENOVO_DPS_SUPPORT == _ON)
		case _SUB_ICON_DPS:
			col = _COL_CONTENT_THREE_3;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_DPS_SUB, color0, color1, color2, color3);			
			break;
#elif(_USER_DCR_FUNCTION ==_ON)
		case _SUB_ICON_DCR:
			col = _COL_CONTENT_THREE_3;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_DCR_SUB, color0, color1, color2, color3); 		
			break;
#endif

#else
		case _SUB_ICON_BRIGHTNESS:		
			col = _COL_CONTENT_TWO_1;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_BRIGHTNESS_SUB, color0, color1, color2, color3);			
			break;

		case _SUB_ICON_CONTRAST:
			col = _COL_CONTENT_TWO_2;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_CONTRAST_SUB, color0, color1, color2, color3);			
			break;
#endif

#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
        case _SUB_ICON_LOWBLUELIGHT_ENABLE:
            row = ROW6;
			col = 12;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_LOWBLUELIGHT_ENABLE, color0, color1, color2, color3);			
			break;
            
        case _SUB_ICON_LOWBLUELIGHT_DISABLE:
            row = ROW6;
			col = 20;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_LOWBLUELIGHT_DISABLE, color0, color1, color2, color3);			
			break;
#endif
		case _SUB_ICON_HPOS:
			col = _COL_CONTENT_TWO_1;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_HPOS_SUB, color0, color1, color2, color3);			
			break;

		case _SUB_ICON_VPOS:
			col = _COL_CONTENT_TWO_2;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_VPOS_SUB, color0, color1, color2, color3);			
			break;

		case _SUB_ICON_AUTOMATIC:
			col = _COL_CONTENT_TWO_1;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_AUTOMATIC_SUB, color0, color1, color2, color3);			
			break;
			
		case _SUB_ICON_MANUAL:
			col = _COL_CONTENT_TWO_2;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_MANUAL_SUB, color0, color1, color2, color3);			
			break;

#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425

		case _SUB_ICON_COLOR:
#if((_ASPECT_RATIO_SUPPORT==_ON) && (_OD_SUPPORT ==_ON))	
    		col = _COL_CONTENT_FOUR_1;// 4
#elif((_ASPECT_RATIO_SUPPORT==_ON) || (_OD_SUPPORT ==_ON))		
    		col = _COL_CONTENT_THREE_1;
#else
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
            col = _COL_CONTENT_THREE_1;
#else
    		col = _COL_CONTENT_TWO_1;
#endif
#endif
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_COLOR_SUB, color0, color1, color2, color3);			
			break;
			
		case _SUB_ICON_INPUT:		
#if((_ASPECT_RATIO_SUPPORT==_ON) && (_OD_SUPPORT ==_ON))	
    		col = _COL_CONTENT_FOUR_2;// 4
#elif((_ASPECT_RATIO_SUPPORT==_ON) || (_OD_SUPPORT ==_ON))			
			col = _COL_CONTENT_THREE_2;
#else
			col = _COL_CONTENT_THREE_2+3;
#endif
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_INPUT_SUB, color0, color1, color2, color3);			
			break;

		case _SUB_ICON_SCALING:
#if(_OD_SUPPORT ==_ON)	
			col = _COL_CONTENT_FOUR_3;
#else
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
			col = _COL_CONTENT_THREE_2;
#else
            col = _COL_CONTENT_THREE_3;
#endif
#endif
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_SCALING_SUB, color0, color1, color2, color3);		
			break;

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
        case _SUB_ICON_BLUELIGHT:
            col = _COL_CONTENT_THREE_3;            
            OsdFuncPutIcon2BitTable(row, col, tOSD_2i_BLUELIGHT_SUB, color0, color1, color2, color3);	
            break;
#endif
            
#if(_OD_SUPPORT==_ON)			
		case _SUB_ICON_OD:	
#if(_ASPECT_RATIO_SUPPORT==_ON)			
			col = _COL_CONTENT_FOUR_4;
#else
			col = _COL_CONTENT_THREE_3;
#endif
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_OD_SUB, color0, color1, color2, color3);		
			break;
#endif

#else//A Only

		case _SUB_ICON_COLOR:
#if((_ASPECT_RATIO_SUPPORT==_ON) && (_OD_SUPPORT ==_ON))	
    		col = _COL_CONTENT_THREE_1;
#else
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
            col = _COL_CONTENT_THREE_1;
#else
		    col = _COL_CONTENT_TWO_1;
#endif
#endif
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_COLOR_SUB, color0, color1, color2, color3);			
			break;
			
		case _SUB_ICON_SCALING:
#if(_OD_SUPPORT==_ON)			
			col = _COL_CONTENT_THREE_2;
#else
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
            col = _COL_CONTENT_THREE_2;
#else        
			col = _COL_CONTENT_TWO_2;
#endif
#endif
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_SCALING_SUB, color0, color1, color2, color3);		
			break;
#if(_OD_SUPPORT==_ON)			
		case _SUB_ICON_OD:	
#if(_ASPECT_RATIO_SUPPORT==_ON)			
			col = _COL_CONTENT_THREE_3;
#else
			col = _COL_CONTENT_TWO_2;
#endif
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_OD_SUB, color0, color1, color2, color3);		
			break;
#endif

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
        case _SUB_ICON_BLUELIGHT:
            col = _COL_CONTENT_THREE_3;            
            OsdFuncPutIcon2BitTable(row, col, tOSD_2i_BLUELIGHT_SUB, color0, color1, color2, color3);	
            break;
#endif //#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
#endif //#if(_INPUT_PORT_MAX != 1)
            	
		case _SUB_ICON_INFORMATION:
			col = _COL_CONTENT_FIVE_1;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_INFORMATION_SUB, color0, color1, color2, color3);			
			break;
			
		case _SUB_ICON_LANGUAGE:
			col = _COL_CONTENT_FIVE_2;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_LANGUAGE_SUB, color0, color1, color2, color3);			
			break;
			
		case _SUB_ICON_OSDPOS:
			col = _COL_CONTENT_FIVE_3;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_OSDPOS_SUB, color0, color1, color2, color3);			
			break;
			
		case _SUB_ICON_RESET:
			col = _COL_CONTENT_FIVE_4;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_RESET_SUB, color0, color1, color2, color3);			
			break;
			
		case _SUB_ICON_ACCESSIBILITY:
			col = _COL_CONTENT_FIVE_5;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_ACCESSIBILITY_SUB, color0, color1, color2, color3);			
			break;

		case _SUB_ICON_BUTTON_REPEAT:            
            row = 5;            
            col = _COL_CONTENT_TWO_1;
			//lorimiao 20140702 for BUTTON_REPEAT ICON error
			//OsdFuncPutIcon2BitTable(row, col, tOSD_2i_ACCESSIBILITY_SUB, color0, color1, color2, color3);
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_BUTTON_REPEAT_SUB, color0, color1, color2, color3);

			break;
		
		case _SUB_ICON_MENU_TIMEOUT:  
            row = 5;            
            col = _COL_CONTENT_TWO_2;
			OsdFuncPutIcon2BitTable(row, col, tOSD_2i_MENU_TIMEOUT_SUB, color0, color1, color2, color3);
			break;
			

		case _SUB_ICON_BRIGHTNESS_ADJUST:
			OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_BRIGHTNESS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_BRIGHTNESS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
                        
			break;
			
		case _SUB_ICON_CONTRAST_ADJUST:
			OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_CONTRAST_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_CONTRAST_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			break;

		case _SUB_ICON_HPOS_ADJUST:
			OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_HPOS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_HPOS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			break;

		case _SUB_ICON_VPOS_ADJUST:
			OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_VPOS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_VPOS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			break;

		case _SUB_ICON_ANALOG:

			if(ucState == _OSD_SELECT)
			OsdFuncPutIcon2BitTable(ROW5, COL5, tOSD_2i_VGA_SUB, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);									
			else
			OsdFuncPutIcon2BitTable(ROW5, COL5, tOSD_2i_VGA_SUB, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			break;
		case _SUB_ICON_DIGITAL:	

			if(ucState == _OSD_SELECT)
			OsdFuncPutIcon2BitTable(ROW5, COL19, tOSD_2i_DVI_SUB, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1); 				
			else
			OsdFuncPutIcon2BitTable(ROW5, COL19, tOSD_2i_DVI_SUB, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			break;

        case _TITLE_ICON_BRIGHTNESS:// draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_PICTURE, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_BRIGHTNESS_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);            
            break;
        case _TITLE_ICON_CONTRAST:
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_PICTURE, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_CONTRAST_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);            
            break;
#if(_LENOVO_DPS_SUPPORT == _ON)
        case _TITLE_ICON_DPS:
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2iPICTURE, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW0, COL5, tOSD_2i_DPS_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);            
            break;
#endif

#if(_USER_DCR_FUNCTION == _ON)
		case _TITLE_ICON_DCR:
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_PICTURE, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_DCR_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);			
			break;
#endif

        case _TITLE_ICON_HPOS:// draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_POSITION, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_HPOS_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);            
            break;
        case _TITLE_ICON_VPOS:// draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_POSITION, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_VPOS_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);            
            break;
            
        case _TITLE_ICON_MANUAL: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_MANUAL, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_MANUAL_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;
        case _TITLE_ICON_COLOR: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_COLOR, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_COLOR_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;       
        case _TITLE_ICON_INPUT: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_COLOR, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW0, COL5, tOSD_2i_INPUT_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;        
        case _TITLE_ICON_SCALING: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_COLOR, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_SCALING_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;
            
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)	
        case _TITLE_ICON_BLUELIGHT:
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_COLOR, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_BLUELIGHT, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);            
            break;
#endif

#if(_OD_SUPPORT==_ON)			
        case _TITLE_ICON_OD: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2iPROPERTIES, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW0, COL5, tOSD_2i_OD_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;
#endif 

        case _TITLE_ICON_INFORMATION:
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_INFORMATION, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_INFORMATION_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
            break;
            
        case _TITLE_ICON_LANGUAGE: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_INFORMATION, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_LANGUAGE_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;        
        case _TITLE_ICON_OSDPOS: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_INFORMATION, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_OSDPOS_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;        
        case _TITLE_ICON_RESET: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_INFORMATION, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_RESET_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;        
        case _TITLE_ICON_ACCESSIBILITY: // draw title icon
			OsdFuncPutIcon2BitTable(ROW0, COL1, tOSD_2i_SUB_INFORMATION, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW1, COL5, tOSD_2i_ACCESSIBILITY_H, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;
		case _SUBTITLE_ICON_BUTTON_REPEAT:
			//lorimiao 20140702 for BUTTON_REPEAT ICON error
			//OsdFuncPutIcon2BitTable(ROW3, COL2, tOSD_2i_ACCESSIBILITY_SUB, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			OsdFuncPutIcon2BitTable(ROW3, COL2, tOSD_2i_BUTTON_REPEAT_SUB, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;		
		case _SUBTITLE_ICON_MENU_TIMEOUT:           
			OsdFuncPutIcon2BitTable(ROW3, COL2, tOSD_2i_MENU_TIMEOUT_SUB, _CP_BG, _CP_GREEN, _CP_GREENW0, _CP_GREENW1);
			break;
            
		case _SUB_ICON_OSDPOS_HPOS_ADJUST:
			OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_OSDHPOS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_OSDHPOS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);	
			break;

		case _SUB_ICON_OSDPOS_VPOS_ADJUST:
			OsdFuncPutIcon2BitTable(ROW6, COL5, tOSD_2i_OSDVPOS_L, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);					
			OsdFuncPutIcon2BitTable(ROW6, COL30, tOSD_2i_OSDVPOS_R, _CP_BG, _CP_WHITE, _CP_GRAYW, _CP_GRAYB);	
			break;

		default:
			break;
	}

    // 畫出subicon的箭頭    
	if((ucItem > _MAIN_ICON_FACTORY) && (ucItem < _TITLE_ICON_BRIGHTNESS))
	{
        if(ucState == _OSD_SELECT)
        {
#if(_INPUT_PORT_MAX != 1)
            if(GET_OSD_STATE() == _OSD_PROP_INPUT)
            {
                OsdFuncPutChar(row+1, col+1, _iUP, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
            }
            else
 #endif
            {
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
                if((ucItem == _SUB_ICON_LOWBLUELIGHT_ENABLE) || (ucItem == _SUB_ICON_LOWBLUELIGHT_DISABLE))
                {
                    OsdFuncPutChar(row+2, col+1, _iUP, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
                }
                else
 #endif
                {
                    OsdFuncPutChar(row+1, col, _iUP_0, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
                    OsdFuncPutChar(row+1, col+1, _iUP_1, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
                }
            }
            
        }
        else
        {
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
            if((ucItem == _SUB_ICON_LOWBLUELIGHT_ENABLE) || (ucItem == _SUB_ICON_LOWBLUELIGHT_DISABLE))
            {
                OsdFuncPutChar(row+2, col, ___, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
                OsdFuncPutChar(row+2, col+1, ___, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);    
                OsdFuncPutChar(row+2, col+2, ___, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);            
            }
            else
 #endif
            {
                OsdFuncPutChar(row+1, col, ___, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
                OsdFuncPutChar(row+1, col+1, ___, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);            
            }
        }
	}
}

//////////////////////////////////////
// sub item
#define ROW_SUB_ITEM        ROW5
#define ROW_SUB_NUM         ROW6

// 2 item
#define COL_SUB_ITEM_21     COL0
#define COL_SUB_ITEM_22     COL17
#define COL_SUB_NUM_21      COL8
#define COL_SUB_NUM_22      COL25
#define SPACE_ITEM2         17


// 3item
#define COL_SUB_ITEM_31      COL0
#define COL_SUB_ITEM_32      COL12
#define COL_SUB_ITEM_33      COL24
#define COL_SUB_NUM_31      COL5
#define COL_SUB_NUM_32      COL17
#define COL_SUB_NUM_33      COL29
#define SPACE_ITEM3         11 


// 4item

#if(_PROJECT == _PRJ_L_LS2014_A_LBL) //Ada.chen 20150906_2
#define COL_SUB_ITEM_41     COL2
#define COL_SUB_ITEM_42     COL9
#define COL_SUB_ITEM_43     COL18
#define COL_SUB_ITEM_44     COL27
#define COL_SUB_NUM_41      COL5
#define COL_SUB_NUM_42      COL13
#define COL_SUB_NUM_43      COL21
#define COL_SUB_NUM_44      COL30
#else
#define COL_SUB_ITEM_41     COL0
#define COL_SUB_ITEM_42     COL8
#define COL_SUB_ITEM_43     COL19
#define COL_SUB_ITEM_44     COL27
#define COL_SUB_NUM_41      COL3
#define COL_SUB_NUM_42      COL12
#define COL_SUB_NUM_43      COL22
#define COL_SUB_NUM_44      COL30
#endif
#define COL_SUB_ITEM_45     COL0
#define COL_SUB_ITEM_46     COL8
#define COL_SUB_ITEM_47     COL19
#define COL_SUB_ITEM_48     COL27
#define COL_SUB_NUM_45      COL3
#define COL_SUB_NUM_46      COL12
#define COL_SUB_NUM_47      COL22
#define COL_SUB_NUM_48      COL30

#define SPACE_ITEM4         8 


/*
#define COL_SUB_NUM_41      COL6
#define COL_SUB_NUM_42      COL14
#define COL_SUB_NUM_43      COL22
#define COL_SUB_NUM_44      COL22
*/


//////////////////////////////////////

//////////////////////////////////////
// adj item
#define ROW_ADJ_ITEM        ROW5
#define COL_ADJ_ITEM        COL4//COL1

#define ROW_ADJ_VALUE       ROW6
#define COL_ADJ_VALUE       COL4
//////////////////////////////////////



//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDispSubItem(BYTE ucItem, BYTE ucState)
{
	BYTE row = ROW7, col;
	BYTE color = COLOR(_CP_WHITE, _CP_BG);

	if((ucState == _OSD_SELECT) || (ucState == _OSD_INDICATE))
	{
		color = COLOR(_CP_WHITE, _CP_BG);
	}

	switch(ucItem)
	{
		case _SUB_ITEM_MANUAL_CLOCK:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, (COL_SUB_ITEM_31), LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_3, tOSD_sCLOCK, GET_OSD_LANGUAGE(), color);
			OsdDispDrawNumber(ROW_SUB_NUM, (COL_SUB_NUM_31-1), g_usAdjustValue0, LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);		
			//col = _COL_CONTENT_THREE_1;	// up icon position
			col = COL_SUB_NUM_31;	// up icon position
			break;

		case _SUB_ITEM_MANUAL_PHASE:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, (COL_SUB_ITEM_32), LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_4, tOSD_sPHASE, GET_OSD_LANGUAGE(), color);
			OsdDispDrawNumber(ROW_SUB_NUM, (COL_SUB_NUM_32-1), g_usAdjustValue1, LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);					
			col = COL_SUB_NUM_32;	// up icon position
			break;

		case _SUB_ITEM_MANUAL_SAVE:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, (COL_SUB_ITEM_33), LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_5, tOSD_sSAVE, GET_OSD_LANGUAGE(), color);
			col = COL_SUB_NUM_33;	// up icon position
			break;

		case _SUB_ITEM_MANUAL_CLOCK_ADJUST:
            OsdFuncPutStringProp(ROW_ADJ_ITEM, COL_ADJ_ITEM, _PFONT_PAGE_0, tOSD_sCLOCK, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			//OsdFuncPutStringPropCenter(ROW_ADJ_ITEM, COL_ADJ_ITEM, LENGTH(SPACE_ITEM3+2), _PFONT_PAGE_0, tOSD_sCLOCK, GET_OSD_LANGUAGE(), color);
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, g_usAdjustValue0, LENGTH(3),  COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_3);	
#else
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, g_usAdjustValue0, LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);
#endif
			break;

		case _SUB_ITEM_MANUAL_PHASE_ADJUST:
            OsdFuncPutStringProp(ROW_ADJ_ITEM, COL_ADJ_ITEM, _PFONT_PAGE_0, tOSD_sPHASE, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			//OsdFuncPutStringPropCenter(ROW_ADJ_ITEM, COL_ADJ_ITEM, LENGTH(10), _PFONT_PAGE_0, tOSD_sPHASE, GET_OSD_LANGUAGE(), color);
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, g_usAdjustValue1, LENGTH(3),  COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_4);		            
#else
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, g_usAdjustValue1, LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);	
#endif
			break;

		case _SUB_ITEM_COLOR_PRESET:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_21, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_3, tOSD_sPRESET, GET_OSD_LANGUAGE(), color);
            row = ROW6;
            col = COL_SUB_NUM_21;
			break;

		case _SUB_ITEM_COLOR_CUSTOM:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_22, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_4, tOSD_sCUSTOM, GET_OSD_LANGUAGE(), color);		
            row = ROW6;
			col = COL_SUB_NUM_22;
			break;

		case _SUB_ITEM_PRESET_NEUTRAL:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_41, LENGTH(SPACE_ITEM4), _PFONT_PAGE_ITEM_3, tOSD_sNEUTRAL, GET_OSD_LANGUAGE(), color);		
            row = ROW7;
			col = COL_SUB_NUM_41;		
			break;

		case _SUB_ITEM_PRESET_SRGB:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_42, LENGTH(SPACE_ITEM4+2), _PFONT_PAGE_ITEM_4, tOSD_sSRGB, GET_OSD_LANGUAGE(), color);		
            row = ROW7;
			col = COL_SUB_NUM_42;				
			break;

		case _SUB_ITEM_PRESET_REDDISH:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_43, LENGTH(SPACE_ITEM4), _PFONT_PAGE_ITEM_5, tOSD_sREDDISH, GET_OSD_LANGUAGE(), color);		
            row = ROW7;
			col = COL_SUB_NUM_43;				
			break;
			
		case _SUB_ITEM_PRESET_BLUISH:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_44, LENGTH(SPACE_ITEM4), _PFONT_PAGE_ITEM_6, tOSD_sBLUISH, GET_OSD_LANGUAGE(), color);		
            row = ROW7;
			col = COL_SUB_NUM_44;				
			break;

		case _SUB_ITEM_CUSTOM_RED:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_45, LENGTH(SPACE_ITEM4), _PFONT_PAGE_ITEM_3, tOSD_sRED, GET_OSD_LANGUAGE(), color);	
			OsdDispDrawNumber((ROW_SUB_ITEM+1), COL_SUB_NUM_45, (GET_COLOR_TEMP_TYPE_USER_R()-_USER_COLOR_MIN), LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);		
			col = COL_SUB_NUM_45;
			break;
			
		case _SUB_ITEM_CUSTOM_GREEN:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_46, LENGTH(SPACE_ITEM4+2), _PFONT_PAGE_ITEM_4, tOSD_sGREEN, GET_OSD_LANGUAGE(), color);		
			OsdDispDrawNumber((ROW_SUB_ITEM+1), COL_SUB_NUM_46, (GET_COLOR_TEMP_TYPE_USER_G()-_USER_COLOR_MIN), LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);		
			col = COL_SUB_NUM_46;		
			break;
			
		case _SUB_ITEM_CUSTOM_BLUE:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_47, LENGTH(SPACE_ITEM4), _PFONT_PAGE_ITEM_5, tOSD_sBLUE, GET_OSD_LANGUAGE(), color);		
			OsdDispDrawNumber((ROW_SUB_ITEM+1), COL_SUB_NUM_47, (GET_COLOR_TEMP_TYPE_USER_B()-_USER_COLOR_MIN), LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_2);		
			col = COL_SUB_NUM_47;		
			break;
			
		case _SUB_ITEM_CUSTOM_SAVE:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_48, LENGTH(SPACE_ITEM4), _PFONT_PAGE_ITEM_6, tOSD_sSAVE, GET_OSD_LANGUAGE(), color);		
			col = COL_SUB_NUM_48;		
			break;
			
		case _SUB_ITEM_CUSTOM_RED_ADJUST:
            OsdFuncPutStringProp(ROW_ADJ_ITEM, COL_ADJ_ITEM, _PFONT_PAGE_0, tOSD_sRED, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			//OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_ADJ_ITEM, LENGTH(10), _PFONT_PAGE_0, tOSD_sRED, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, (GET_COLOR_TEMP_TYPE_USER_R()-_USER_COLOR_MIN), LENGTH(3),  COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_3);		
#else
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, (GET_COLOR_TEMP_TYPE_USER_R()-_USER_COLOR_MIN), LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);		
#endif            
			break;
			
		case _SUB_ITEM_CUSTOM_GREEN_ADJUST:
            OsdFuncPutStringProp(ROW_ADJ_ITEM, COL_ADJ_ITEM, _PFONT_PAGE_0, tOSD_sGREEN, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			//OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_ADJ_ITEM, LENGTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sGREEN, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, (GET_COLOR_TEMP_TYPE_USER_G()-_USER_COLOR_MIN), LENGTH(3),  COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_3);		
#else
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, (GET_COLOR_TEMP_TYPE_USER_G()-_USER_COLOR_MIN), LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);		
#endif
			break;
			
		case _SUB_ITEM_CUSTOM_BLUE_ADJUST:
            OsdFuncPutStringProp(ROW_ADJ_ITEM, COL_ADJ_ITEM, _PFONT_PAGE_0, tOSD_sBLUE, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			//OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_ADJ_ITEM, LENGTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sBLUE, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, (GET_COLOR_TEMP_TYPE_USER_B()-_USER_COLOR_MIN), LENGTH(3),  COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_3);		
#else
			OsdDispDrawNumber(ROW_ADJ_VALUE, COL_ADJ_VALUE, (GET_COLOR_TEMP_TYPE_USER_B()-_USER_COLOR_MIN), LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);		
#endif
			break;

		case _SUB_ITEM_INPUT_ANALOG:
			OsdFuncPutStringProp(ROW_SUB_ITEM, COL8, _PFONT_PAGE_ITEM_3, tOSD_sANALOG, GET_OSD_LANGUAGE(), color);				
			col = COL8;
			break;

		case _SUB_ITEM_INPUT_DIGITAL:
			//OsdFuncPutStringProp(ROW_SUB_ITEM, COL23,_PFONT_PAGE_ITEM_4, tOSD_sDVI, _ENGLISH, color);				
			OsdFuncPutStringProp(ROW_SUB_ITEM, COL22,_PFONT_PAGE_ITEM_4, tOSD_sDVI, GET_OSD_LANGUAGE(), color);				
            col = COL22;
			break;

		case _SUB_ITEM_SCALING_OFF:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_21, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_3, tOSD_sSCALING_OFF, GET_OSD_LANGUAGE(), color);	
			col = COL_SUB_NUM_21;
			break;

		case _SUB_ITEM_SCALING_ON:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_22, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_4, tOSD_sSCALING_ON, GET_OSD_LANGUAGE(), color);		
			col = COL_SUB_NUM_22;		
			break;

#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
        case _SUB_ITEM_BLUELIGHT_OFF:
            col = 4;	
            OsdFuncPutStringPropCenter(ROW6,COL5, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_3, tOSD_sOFF, GET_OSD_LANGUAGE(), color);	
            row = ROW7; 		   	
            col = COL10;            
            break;

        case _SUB_ITEM_BLUELIGHT_ON:
            col = 21;   
            OsdFuncPutStringPropCenter(ROW6,COL19, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_4, tOSD_sON, GET_OSD_LANGUAGE(), color);   
            row = ROW7;             
            col = COL24;
            break;
#endif

#if(_OD_SUPPORT == _ON)
		case _SUB_ITEM_OD_ON:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_21, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_3, tOSD_sON, GET_OSD_LANGUAGE(), color);	
			col = COL_SUB_NUM_21;
			break;

		case _SUB_ITEM_OD_OFF:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_22, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_4, tOSD_sOFF, GET_OSD_LANGUAGE(), color);		
			col = COL_SUB_NUM_22;		
			break;
#endif
		case _SUB_ITEM_OSDPOS_DEFAULT:
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_21, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_4, tOSD_sDEFAULT, GET_OSD_LANGUAGE(), color);				
#else
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_21, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_3, tOSD_sDEFAULT, GET_OSD_LANGUAGE(), color);				
#endif
			col = COL_SUB_NUM_21;
			break;
			
		case _SUB_ITEM_OSDPOS_CUSTOM:
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_22, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_3, tOSD_sOSDPOSITIONCUSTOM, GET_OSD_LANGUAGE(), color);		
#else
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_22, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_4, tOSD_sOSDPOSITIONCUSTOM, GET_OSD_LANGUAGE(), color);		
#endif
			col = COL_SUB_NUM_22;		
			break;

		case _SUB_ITEM_OSDPOS_H:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_31, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_3, tOSD_sOSDHPOS, GET_OSD_LANGUAGE(), color);
			OsdDispDrawNumber(ROW_ADJ_VALUE, (COL_SUB_NUM_31-1), g_usAdjustValue0, LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);		
			col = COL_SUB_NUM_31;	// up icon position
			break;

		case _SUB_ITEM_OSDPOS_V:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_32, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_4, tOSD_sOSDVPOS, GET_OSD_LANGUAGE(), color);
			OsdDispDrawNumber(ROW_ADJ_VALUE, (COL_SUB_NUM_32-1), g_usAdjustValue1, LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);					
			col = COL_SUB_NUM_32;
			break;

		case _SUB_ITEM_OSDPOS_SAVE:
			OsdFuncPutStringPropCenter(ROW_SUB_ITEM, COL_SUB_ITEM_33, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_5, tOSD_sOSDPOSITIONSAVE, GET_OSD_LANGUAGE(), color);
			col = COL_SUB_NUM_33;
			break;		

		case _SUB_ITEM_OSDPOS_H_ADJUST:
			OsdFuncPutStringProp(ROW3, COL5, _PFONT_PAGE_0, tOSD_sOSDHPOS, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));		
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			OsdDispDrawNumber(ROW4, COL5, g_usAdjustValue0, LENGTH(3),  COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_3);		
#else
			OsdDispDrawNumber(ROW4, COL5, g_usAdjustValue0, LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);		
#endif
            break;

		case _SUB_ITEM_OSDPOS_V_ADJUST:
			OsdFuncPutStringProp(ROW3, COL5, _PFONT_PAGE_0, tOSD_sOSDVPOS, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));		
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
			OsdDispDrawNumber(ROW4, COL5, g_usAdjustValue1, LENGTH(3),  COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_4);		
#else
			OsdDispDrawNumber(ROW4, COL5, g_usAdjustValue1, LENGTH(3),  color, _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);		
#endif
			break;

		case _SUB_ITEM_DEFAULT_CANCEL:
			OsdFuncPutStringPropCenter(ROW5, COL_SUB_ITEM_21, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_3, tOSD_sCANCEL, GET_OSD_LANGUAGE(), color);				
			col = COL_SUB_NUM_21;
			break;
			
		case _SUB_ITEM_DEFAULT_RESET:
			OsdFuncPutStringPropCenter(ROW5, COL_SUB_ITEM_22, LENGTH(SPACE_ITEM2), _PFONT_PAGE_ITEM_4, tOSD_sRESET, GET_OSD_LANGUAGE(), color);		
			col = COL_SUB_NUM_22;				
			break;

		case _SUB_ITEM_BUTTON_OFF:
            col = 4;
			OsdFuncPutStringPropCenter(ROW7,COL_SUB_ITEM_31, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_3, tOSD_sOFF, GET_OSD_LANGUAGE(), color);
            row = ROW8;            
			col = COL_SUB_NUM_31;
			break;
			
		case _SUB_ITEM_BUTTON_DEFAULT:
            col = 12;            
			OsdFuncPutStringPropCenter(ROW7,COL_SUB_ITEM_32, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_4, tOSD_sBTNDEFAULT, GET_OSD_LANGUAGE(), color);
            row = ROW8;            
			col = COL_SUB_NUM_32;
			break;
			
		case _SUB_ITEM_BUTTON_SLOW:
            col = 21;            
			OsdFuncPutStringPropCenter(ROW7,COL_SUB_ITEM_33, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_5, tOSD_sSLOW, GET_OSD_LANGUAGE(), color);
            row = ROW8;            
			col = COL_SUB_NUM_33;		
			break;

#if(_LENOVO_DPS_SUPPORT == _ON)
		case _SUB_ITEM_DPS_OFF:
            col = 4;
			OsdFuncPutStringPropCenter(ROW6,COL5, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_3, tOSD_sOFF, GET_OSD_LANGUAGE(), color);
            row = ROW7;            
			col = COL10;
			break;
            
		case _SUB_ITEM_DPS_ON:
            col = 21;
			OsdFuncPutStringPropCenter(ROW6,COL19, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_4, tOSD_sON, GET_OSD_LANGUAGE(), color);
            row = ROW7;            
			col = COL24;
			break;
#endif
#if(_USER_DCR_FUNCTION == _ON)
		case _SUB_ITEM_DCR_OFF:
			col = 4;
			OsdFuncPutStringPropCenter(ROW6,COL5, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_3, tOSD_sOFF, GET_OSD_LANGUAGE(), color);
			row = ROW7; 		   
			col = COL10;
			break;
			
		case _SUB_ITEM_DCR_ON:
			col = 21;
			OsdFuncPutStringPropCenter(ROW6,COL19, LENGTH(SPACE_ITEM3), _PFONT_PAGE_ITEM_4, tOSD_sON, GET_OSD_LANGUAGE(), color);
			row = ROW7; 		   
			col = COL24;
			break;
#endif

		default:
			break;
	}

	// up icon
	switch(ucItem)
	{

		case _SUB_ITEM_MANUAL_CLOCK:
		case _SUB_ITEM_MANUAL_PHASE:
		case _SUB_ITEM_MANUAL_SAVE:
		case _SUB_ITEM_BUTTON_OFF:
		case _SUB_ITEM_BUTTON_DEFAULT:
		case _SUB_ITEM_BUTTON_SLOW:            
		case _SUB_ITEM_OSDPOS_H:		
		case _SUB_ITEM_OSDPOS_V:
		case _SUB_ITEM_OSDPOS_SAVE:
		case _SUB_ITEM_COLOR_PRESET:
		case _SUB_ITEM_COLOR_CUSTOM:
		case _SUB_ITEM_SCALING_ON:
		case _SUB_ITEM_SCALING_OFF:
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
        case _SUB_ITEM_BLUELIGHT_ON:
        case _SUB_ITEM_BLUELIGHT_OFF:
#endif
#if(_OD_SUPPORT == _ON)
		case _SUB_ITEM_OD_ON:
		case _SUB_ITEM_OD_OFF:
#endif
		case _SUB_ITEM_OSDPOS_DEFAULT:
		case _SUB_ITEM_OSDPOS_CUSTOM:
#if(_LENOVO_DPS_SUPPORT == _ON)
		case _SUB_ITEM_DPS_OFF:
		case _SUB_ITEM_DPS_ON:
#endif
#if(_USER_DCR_FUNCTION == _ON)
		case _SUB_ITEM_DCR_OFF:
		case _SUB_ITEM_DCR_ON:
#endif
		case _SUB_ITEM_INPUT_ANALOG:
		case _SUB_ITEM_INPUT_DIGITAL:
		case _SUB_ITEM_DEFAULT_CANCEL:
		case _SUB_ITEM_DEFAULT_RESET:
            
		
			if(ucState == _OSD_SELECT)
			{
				OsdFuncPutChar(row, col, _iUP, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
			}
			else
			{
				OsdFuncPutChar(row, col, ___, COLOR(_CP_WHITE, _CP_BG), _AT_FS1);		
			}
		
			break;
		case _SUB_ITEM_CUSTOM_RED:
		case _SUB_ITEM_CUSTOM_GREEN:
		case _SUB_ITEM_CUSTOM_BLUE:
		case _SUB_ITEM_CUSTOM_SAVE:
			
		case _SUB_ITEM_PRESET_NEUTRAL:
		case _SUB_ITEM_PRESET_SRGB:
		case _SUB_ITEM_PRESET_REDDISH:
		case _SUB_ITEM_PRESET_BLUISH:
			if(ucState == _OSD_SELECT)
			{
				OsdFuncPutChar(row, col, _iUP_0, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
				OsdFuncPutChar(row, col+1, _iUP_1, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);		
                
			}
			else
			{
				OsdFuncPutChar(row, col, ___, COLOR(_CP_WHITE, _CP_BG), _AT_FS1);		
				OsdFuncPutChar(row, col+1, ___, COLOR(_CP_WHITE, _CP_BG), _AT_FS1);		
			}
			break;

            break;
		case _SUB_ITEM_MANUAL_CLOCK_ADJUST:		
		case _SUB_ITEM_MANUAL_PHASE_ADJUST:
		default:
			break;
	}

	
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
#define COL_SLIDER  7
void OsdDispDrawSlider(BYTE ucRow, BYTE ucColor, BYTE ucPercent, BYTE ucState)
{
	BYTE temp = 23;
    BYTE x,c,c1,c2,c3;
    

	if(ucPercent > 100)
	{
		ucPercent = 100;
	}

	if(ucState == _SLIDER_12)
	{
		temp = 12;
	}
    x = ucPercent / 5;

    OsdFuncPutIcon2BitTable(ucRow, COL_SLIDER, tOSD_2iSliderBar, _CP_BG , _CP_WHITE, ucColor, _CP_GRAYB);  

    c = OsdGetTableValue(ucPercent,0);
    c1 = OsdGetTableValue(ucPercent,1);
    c2 = OsdGetTableValue(ucPercent,2);
    c3 = OsdGetTableValue(ucPercent,3);

    OsdFuncPutIcon2Bit(ucRow, (COL_SLIDER + x + 1), c, _CP_BG , _CP_WHITE, _CP_GREEN, _CP_GRAYB);  
    OsdFuncPutIcon2Bit(ucRow+1, (COL_SLIDER + x + 1), c1, _CP_BG , _CP_WHITE, _CP_GREEN, _CP_GRAYB);  
    OsdFuncPutIcon2Bit(ucRow, (COL_SLIDER + x + 2), c2, _CP_BG , _CP_WHITE, _CP_GREEN, _CP_GRAYB);  
    OsdFuncPutIcon2Bit(ucRow+1, (COL_SLIDER + x + 2), c3, _CP_BG , _CP_WHITE, _CP_GREEN, _CP_GRAYB);  


}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDispDrawNumber(BYTE ucRow, BYTE ucCol, WORD usValue, BYTE ucLength, BYTE ucColor, BYTE ucAlign, BYTE ucFptsSelect)
{
	BYTE parray[7],i;

    pData[0] = (_0_ + (usValue / 100000));
    pData[1] = (_0_ + (usValue % 100000 / 10000));
    pData[2] = (_0_ + (usValue % 10000) / 1000);
    pData[3] = (_0_ + (usValue % 1000) / 100);
    pData[4] = (_0_ + (usValue % 100) / 10);
    pData[5] = (_0_ + (usValue % 10));

	for(i=0;i<6;i++)
	{
		if(pData[i] > _0_)
		{
			break;
		}
		else
		{
			pData[i] = __8;
		}
	}

	if(usValue == 0)
	{
		pData[5] = _0_;
	}	
	
	if(ucAlign == _ALIGN_LEFT)
	{
		for(i=0;i<ucLength;i++)
		{
			parray[i] = pData[i+6-ucLength];
		}
		parray[ucLength] = _END_;
	}
	else
	{
		
	}
		
	OsdFuncPutStringProp(ucRow, ucCol, ucFptsSelect, parray, _ENGLISH, ucColor);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//顯示調整Bar
void OsdDispSlider(BYTE ucState)
{
	BYTE row = ROW6;
    BYTE value;

    if(!GET_OSD_SLIDER_REDRAW())//ym20131011 . 
    {
        SET_OSD_SLIDER_REDRAW(_ON);
        return;
    }
    
	switch(ucState)
	{
		case _SLIDER_BRIGHTNESS:
		case _SLIDER_CONTRAST:
		case _SLIDER_HPOS:
		case _SLIDER_OSDHPOS:
			OsdDispDrawNumber(ROW5, COL17, g_usAdjustValue0, LENGTH(3), COLOR(_CP_GREEN, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);            
			OsdDispDrawNumber(ROW7, COL4, 0, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);            
			OsdDispDrawSlider(ROW6, COLOR(_CP_GREEN, _CP_BG), g_usAdjustValue0, _SLIDER_20);			
			OsdDispDrawNumber(ROW7, COL30, 100, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_2);		            
            break;

        case _SLIDER_VPOS:
        case _SLIDER_OSDVPOS:
			OsdDispDrawNumber(ROW5, COL17, g_usAdjustValue1, LENGTH(3), COLOR(_CP_GREEN, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);            
			OsdDispDrawNumber(ROW7, COL4, 0, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);            
			OsdDispDrawSlider(ROW6, COLOR(_CP_GREEN, _CP_BG), g_usAdjustValue1, _SLIDER_20);			
			OsdDispDrawNumber(ROW7, COL30, 100, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_2);		            
			break;

		case _SLIDER_CLOCK:
			OsdDispDrawNumber(ROW8, COL17, g_usAdjustValue0, LENGTH(3), COLOR(_CP_GREEN, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);
			OsdDispDrawNumber(ROW10, COL4, 0, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);            
			OsdDispDrawSlider(ROW9, COLOR(_CP_GREEN, _CP_BG), g_usAdjustValue0, _SLIDER_20);		
			OsdDispDrawNumber(ROW10, COL30, 100, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_2);            
			break;
            
		case _SLIDER_PHASE:
            
			OsdDispDrawNumber(ROW8, COL17, g_usAdjustValue1, LENGTH(3), COLOR(_CP_GREEN, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);
			OsdDispDrawNumber(ROW10, COL4, 0, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);            
			OsdDispDrawSlider(ROW9, COLOR(_CP_GREEN, _CP_BG), g_usAdjustValue1, _SLIDER_20);			
			OsdDispDrawNumber(ROW10, COL30, 100, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_2);            
			break;


		case _SLIDER_RED:
		case _SLIDER_GREEN:
		case _SLIDER_BLUE:
            
            if (ucState == _SLIDER_RED)
                value = (GET_COLOR_TEMP_TYPE_USER_R()-_USER_COLOR_MIN);
            else if (ucState == _SLIDER_GREEN)
                value = (GET_COLOR_TEMP_TYPE_USER_G()-_USER_COLOR_MIN);
            else
                value = (GET_COLOR_TEMP_TYPE_USER_B()-_USER_COLOR_MIN);
            
			OsdDispDrawNumber(ROW8, COL17, value, LENGTH(3), COLOR(_CP_GREEN, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);

			OsdDispDrawNumber(ROW10, COL4, 0, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);
			
			OsdDispDrawSlider(ROW9, COLOR(_CP_GREEN, _CP_BG), value, _SLIDER_20);
			
			OsdDispDrawNumber(ROW10, COL30, 100, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_2);		
			break;


		case _SLIDER_OSDTIMEOUT:
			OsdDispDrawNumber(ROW6, COL17, g_usAdjustValue0, LENGTH(3), COLOR(_CP_GREEN, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_0);

			//OsdDispDrawNumber(ROW8, COL4, 5, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_1);
            OsdFuncPutStringProp(ROW8, COL4, _PFONT_PAGE_ITEM_3, tOSD_sBTNSlider_L, _ENGLISH, COLOR(_CP_WHITE, _CP_BG));
			OsdDispDrawSlider(ROW7, COLOR(_CP_GREEN, _CP_BG), ((WORD)(g_usAdjustValue0 - 5) * 100 / 55), _SLIDER_12);
			
			//OsdDispDrawNumber(ROW8, COL30, 60, LENGTH(3), COLOR(_CP_WHITE, _CP_BG), _ALIGN_LEFT, _PFONT_PAGE_NUMBER_2);
            OsdFuncPutStringProp(ROW8, COL30, _PFONT_PAGE_ITEM_4, tOSD_sBTNSlider_R, _ENGLISH, COLOR(_CP_WHITE, _CP_BG));

			break;
		
		default:	
			break;
	}
		
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//清除中間頁面...Row4~Row11(Top Icon & Sub Menu Top字串不清除)
void OsdDispContentClear()
{
	BYTE i;
    
//    BYTE ucRow;

//    if (GET_OSD_STATE() > _OSD_OPTION_ACCESSIBILITY)
//        ucRow= 0;
//    else
//        ucRow= 4;
    
//	for(i=ucRow;i< ROW11; i++)

	for(i=ROW3;i< ROW12; i++)
	{
		OsdFuncPutCharSeries(i, COL0, ___, COLOR(_CP_BG, _CP_BG), _AT_NORMAL, LENGTH(g_ucOsdWidth));
	}	
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
// Title string and sub icon
void OsdDispContent(BYTE ucState)
{
//	OsdDispMainStringClear();
	OsdDispContentClear();	
	
	switch(ucState)
	{
		case _MAIN_CONTENT_PICTURE:	
			OsdDispMainMenuString(_MAIN_STRING_PICTURE);  //顯示Title字串或說明字串
			OsdLoadFont(_FONT2_DYNAMIC_PICTURE_CONTENT);    // load sub icon font
#if(_USER_DCR_FUNCTION == _ON)
		if(GET_OSD_DCR_STATUS() == _ON)
		{
			OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_STATIC);
			OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_STATIC);
		}
		else
		{
			OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);
		}
#else
		OsdDispSubIcon(_SUB_ICON_BRIGHTNESS, _OSD_UNSELECT);
		OsdDispSubIcon(_SUB_ICON_CONTRAST, _OSD_UNSELECT);
#endif
#if(_LENOVO_DPS_SUPPORT == _ON)
			OsdDispSubIcon(_SUB_ICON_DPS, _OSD_UNSELECT);  
#endif
#if(_USER_DCR_FUNCTION == _ON)
			OsdDispSubIcon(_SUB_ICON_DCR, _OSD_UNSELECT);  
#endif

			break;
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
        case _MAIN_CONTENT_LOWBLUELIGHT:
			OsdDispMainMenuString(_MAIN_STRING_LOWBLUELIGHT);
			OsdLoadFont(_FONT2_DYNAMIC_LOWBLUELIGHT_CONTENT);
			OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_ENABLE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LOWBLUELIGHT_DISABLE, _OSD_UNSELECT);		
			break;
#endif
		case _MAIN_CONTENT_POSTION:
			OsdDispMainMenuString(_MAIN_STRING_POSITION);
			OsdLoadFont(_FONT2_DYNAMIC_POSITION_CONTENT);
			OsdDispSubIcon(_SUB_ICON_HPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_VPOS, _OSD_UNSELECT);		
			break;

		case _MAIN_CONTENT_SETUP:
			OsdDispMainMenuString(_MAIN_STRING_SETUP);
			OsdLoadFont(_FONT2_DYNAMIC_SETUP_CONTENT);
			OsdDispSubIcon(_SUB_ICON_AUTOMATIC, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_MANUAL, _OSD_UNSELECT);				
			break;

		case _MAIN_CONTENT_PROPERTIES:
			OsdDispMainMenuString(_MAIN_STRING_PROPERTIES);
			OsdLoadFont(_FONT2_DYNAMIC_PROPERTIES_CONTENT);
			OsdDispSubIcon(_SUB_ICON_COLOR, _OSD_UNSELECT);
#if(_INPUT_PORT_MAX != 1)//Robert Wang 20140425
			OsdDispSubIcon(_SUB_ICON_INPUT, _OSD_UNSELECT);	
#endif
#if(_ASPECT_RATIO_SUPPORT==_ON)
			if(UserAdjustCheckAspectRatio() == _TRUE)
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_UNSELECT);
			}
			else
			{
				OsdDispSubIcon(_SUB_ICON_SCALING, _OSD_STATIC);
			}
#endif

#if(_OD_SUPPORT==_ON)
			OsdDispSubIcon(_SUB_ICON_OD, _OSD_UNSELECT);	
#endif
#if(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _ON)
            OsdDispSubIcon(_SUB_ICON_BLUELIGHT, _OSD_UNSELECT);
#endif
			break;

		case _MAIN_CONTENT_OPTION:
			OsdDispMainMenuString(_MAIN_STRING_OPTION);
			OsdLoadFont(_FONT2_DYNAMIC_OPTION_CONTENT);
			OsdDispSubIcon(_SUB_ICON_INFORMATION, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_LANGUAGE, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_OSDPOS, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_RESET, _OSD_UNSELECT);
			OsdDispSubIcon(_SUB_ICON_ACCESSIBILITY, _OSD_UNSELECT);		
			break;

		case _MAIN_CONTENT_EXIT:
			OsdDispMainMenuString(_MAIN_STRING_EXIT);
			break;

		case _MAIN_CONTENT_FACTORY:
			OsdDispMainMenuString(_MAIN_STRING_FACTORY);
			break;
			
		default:
			break;		
	}
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//OSD Main Menu(主選單)      
void OsdDispMainMenu(BYTE ucState)
{
	OsdFuncApplyMap(_OSD_MAP0, COLOR(_CP_WHITE, _CP_BG));   //Main Menu Map初始化

    OsdFuncSetBlending(_OSD_TRANSPARENCY_ALL);    
    OsdFuncSetTransparency(GET_OSD_TRANSPARENCY_STATUS());       
      
    //==== Load font & icon & color palette=======   
    OsdFuncSet2BitIconOffset(_2BIT_OFFSET);   
    OsdLoadFont(_FONT1_GLOBAL);          
    OsdLoadFont(_FONT1_P2_MAIN);                               //載入Top ICON Bitmap 
    
    OsdLoadFont(_FONT2_KEYITEM);    //載入Top ICON Bitmap 
    OsdLoadFont(_FONT2_MAINICON);    //載入Top ICON Bitmap 
    OsdLoadFont(_FONT2_SLIDER);


	OsdLoadPalette(_PALETTE_COMMOND);       //載入調色盤
	
    if(GET_FACTORY_MODE() == _TRUE)
		OsdFuncSetPosition(_POS_PERCENT,10*10, 100*10);  //設定factory的OSD位置
	else
		OsdFuncSetPosition(_POS_PERCENT, GET_OSD_HPOS()*10, GET_OSD_VPOS()*10); //設定OSD位置


	// windows bg(視窗背景顏色設定)
	//OsdFuncDrawWindow(_WIN0, ROW0, COL0, g_ucOsdWidth, g_ucOsdHeight-4, _CP_BG, tOSD_WIN_TYPE0);
	//OsdFuncDrawWindow(_WIN1, g_ucOsdHeight-4, COL0, g_ucOsdWidth, HEIGHT(2), _CP_GRAY_224, tOSD_WIN_TYPE0);
	OsdFuncDrawWindow(_WIN0, ROW0, COL0, 35, 13, _CP_BG, tOSD_WIN_TYPE0);
	OsdFuncDrawWindow(_WIN1, ROW13, COL0, 35, 4, _CP_GRAY_224, tOSD_WIN_TYPE0);


/*
//===============================================================================
//Eli 20120823 modify osd icon. 
	// main icon(Top Icon灰色沒選)
	OsdDispMainIconDraw(_MAIN_ICON_PICTURE, _OSD_UNSELECT);
	OsdDispMainIconDraw(_MAIN_ICON_POSTION, _OSD_UNSELECT);
	OsdDispMainIconDraw(_MAIN_ICON_SETUP, _OSD_UNSELECT);
	OsdDispMainIconDraw(_MAIN_ICON_PROPERTIES, _OSD_UNSELECT);
	OsdDispMainIconDraw(_MAIN_ICON_OPTION, _OSD_UNSELECT);
	OsdDispMainIconDraw(_MAIN_ICON_EXIT, _OSD_UNSELECT);

	if(GET_FACTORY_MODE() == _TRUE)
	{
		OsdDispMainIconDraw(_MAIN_ICON_FACTORY, _OSD_UNSELECT);
	}

	OsdDispMainIconDraw((ucState - _OSD_MAIN_BRIGHTCONTRAST), _OSD_SELECT);
	// sub content
	OsdDispContent((ucState - _OSD_MAIN_BRIGHTCONTRAST));		
*/

    OsdDispMainIcon();

    if(ucState == _OSD_MAIN_BRIGHTCONTRAST)
    {
        OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_SELECT);
        // sub content
        OsdDispContent(_MAIN_CONTENT_PICTURE);      
    }
#if((_LOW_BLUE_LIGHT_FUNCTION == _ON)&&(_LOW_BLUE_LIGHT_STYLE_IN_COLOR_TEMP == _OFF))
    else if(ucState == _OSD_MAIN_LOWBLUELIGHT)
    {
        OsdDispSubIcon(_MAIN_ICON_LOWBLUELIGHT, _OSD_SELECT);
        // sub content
        OsdDispContent(_MAIN_CONTENT_LOWBLUELIGHT);        
    }
#endif    
    else if(ucState == _OSD_MAIN_IMAGEPOSTION)
    {
        OsdDispSubIcon(_MAIN_ICON_POSTION, _OSD_SELECT);
        // sub content
        OsdDispContent(_MAIN_CONTENT_POSTION);        
    }
    else if(ucState == _OSD_MAIN_IMAGESETUP)
    {
        OsdDispSubIcon(_MAIN_ICON_SETUP, _OSD_SELECT);
        // sub content
        OsdDispContent(_MAIN_CONTENT_SETUP);    
    }
    else if(ucState == _OSD_MAIN_IMAGEPROPERTIES)
    {
        OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_SELECT);
        // sub content
        OsdDispContent(_MAIN_CONTENT_PROPERTIES);    
    }
    else if(ucState == _OSD_MAIN_TPV_FACTORY)
    {
        OsdDispMainIconDraw(_MAIN_ICON_FACTORY, _OSD_SELECT);
        // sub content
        OsdDispContent(_MAIN_CONTENT_FACTORY);      
    }
    OsdDispMainIconChange(GET_OSD_STATE()-_OSD_MAIN_BRIGHTCONTRAST, _OSD_SELECT);
//=================================================================================
	// key info(顯示OSD下方提示動作文字)
	OsdDispKeyInfo(_KEY_INFO_ALL);

	OsdFuncEnableOsd();

}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//Bri OSD Hotkey Menu      
void OsdDispBriHotkeyMenu()
{
	OsdFuncApplyMap(_OSD_MAP0, COLOR(_CP_GRAY_224, _CP_BG));   //Main Menu Map初始化

    //==== Load font & icon & color palette=======   

    OsdFuncSet2BitIconOffset(_2BIT_OFFSET);   
    OsdLoadFont(_FONT1_GLOBAL); 
    OsdLoadFont(_FONT1_P2_MAIN);                               //載入Top ICON Bitmap 
    
    OsdLoadFont(_FONT2_KEYITEM);    //載入Top ICON Bitmap 
    OsdLoadFont(_FONT2_MAINICON);    //載入Top ICON Bitmap 
    OsdLoadFont(_FONT2_SLIDER);


	OsdLoadPalette(_PALETTE_COMMOND);       //載入調色盤
    
	OsdFuncSetPosition(_POS_PERCENT, GET_OSD_HPOS()*10, GET_OSD_VPOS()*10);                //設定OSD位置
	
	// windows bg(視窗背景顏色設定)
//	OsdFuncDrawWindow(_WIN0, ROW0, COL0, g_ucOsdWidth, g_ucOsdHeight-4, _CP_BLACK, tOSD_WIN_TYPE0);
//	OsdFuncDrawWindow(_WIN1, g_ucOsdHeight-3, COL0, g_ucOsdWidth, HEIGHT(3), _CP_GRAY_224, tOSD_WIN_TYPE0);
	OsdFuncDrawWindow(_WIN0, ROW0, COL0, 35, 13, _CP_BG, tOSD_WIN_TYPE0);
	OsdFuncDrawWindow(_WIN1, ROW13, COL0, 35, 4, _CP_GRAY_224, tOSD_WIN_TYPE0);



    //Main Icon顯示
    OsdDispSubIcon(_MAIN_ICON_PICTURE, _OSD_SELECT);
//	OsdDispSubIcon(_MAIN_ICON_POSTION, _OSD_UNSELECT);
//	OsdDispSubIcon(_MAIN_ICON_SETUP, _OSD_UNSELECT);
//	OsdDispSubIcon(_MAIN_ICON_PROPERTIES, _OSD_UNSELECT);
//	OsdDispSubIcon(_MAIN_ICON_OPTION, _OSD_UNSELECT);
//	OsdDispSubIcon(_MAIN_ICON_EXIT, _OSD_UNSELECT);

    //載入sub Icon Bitmap
    OsdDispMainMenuString(_MAIN_STRING_PICTURE);
	OsdLoadFont(_FONT2_DYNAMIC_PICTURE_CONTENT); 
	g_usAdjustValue0 = GET_OSD_BACKLIGHT();                                 
	OsdDispSubIcon(_TITLE_ICON_BRIGHTNESS, _OSD_INDICATE); 
    OsdDispSubIcon(_SUB_ICON_BRIGHTNESS_ADJUST, _OSD_INDICATE);  //顯示Icon                          
    OsdDispSlider(_SLIDER_BRIGHTNESS);                           //顯示調整Bar    
    OsdDispMainMenuString(_MAIN_STRING_BRIGHTNESS);  
    //=================================================================================
	// key info(顯示OSD下方提示動作文字)
	OsdDispKeyInfo(_KEY_INFO_ALL);

	OsdFuncEnableOsd();
}

//20120730 Abel add
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE OsdDispJudgeSourceType(void)
{
    BYTE ucTemp = 0;

    switch(SysSourceGetInputPort())
    {
        case _A0_INPUT_PORT:
            ucTemp = _OSD_SOURCE_PORT_VGA;
            break;
    
        case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
                ucTemp = _OSD_SOURCE_PORT_DVI;
#elif(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
                ucTemp = _OSD_SOURCE_PORT_HDMI;
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                ucTemp = _OSD_SOURCE_PORT_DP;
#endif
            break;
    
        case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
                ucTemp = _OSD_SOURCE_PORT_DVI;
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
                ucTemp = _OSD_SOURCE_PORT_HDMI;
#elif((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_DUAL_PORT))
                ucTemp = _OSD_SOURCE_PORT_DP;
#endif
            break;
       
        default:
            break;
    }

    return(ucTemp);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
//顯示Logo
void OsdDispShowLogo(void)
{
    OsdDispDisableOsdTimerEvent();//ym20131030 . 
    
#if (_FACTORY_MODE_OWNER == _OWNER_TPV)//DFM
	if(TPVDFMLogoOnCheck()==_TRUE)
#elif(_FACTORY_MODE_OWNER == _OWNER_FOXCONN)//lorimiao 0502			
	if((!GET_FACTORY_MODE()) && (GET_FACTORY_LOGO_ON_OFF()))
#elif(_FACTORY_MODE_OWNER == _OWNER_WISTRON)            
    if (!GET_FACTORY_MODE() && !GET_ATE_COMMAND_STATUS())
#endif			
    {
#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)

        OsdFuncApplyMap(_OSD_MAP1, COLOR(_CP_GRAY_224, _CP_BG));

        OsdFuncSetBlending(_OSD_TRANSPARENCY_ALL);    
        OsdFuncSetTransparency(GET_OSD_TRANSPARENCY_STATUS());      

        //載入1Bit Bitmap    
        OsdLoadFont(_FONT1_LOGO0);   
        OsdLoadFont(_FONT1_LOGO1);
        OsdLoadFont(_FONT1_EPA_LOGO);

        OsdLoadPalette(_PALETTE_LOGO);

        //OSD顯示位置    
#if ( ( _PANEL_DH_WIDTH==1440 ) && ( _PANEL_DV_HEIGHT == 900 ) )          
         OsdFuncSetPosition(_POS_PERCENT, 25, 25);
#if(_EPA_LOGO == _ON)
         OsdFuncDrawWindowPixel(_WIN0, 1278, 482, 116, 116, _CP_LOGO_IBM_WHITE, tOSD_WIN_TYPE0);
#endif
#elif ( ( _PANEL_DH_WIDTH==1600 ) && ( _PANEL_DV_HEIGHT == 900 ) )          
         OsdFuncSetPosition(_POS_PERCENT, 50, 200);
#if(_EPA_LOGO == _ON)
         OsdFuncDrawWindowPixel(_WIN0, 1335, 500, 116, 116, _CP_LOGO_IBM_WHITE, tOSD_WIN_TYPE0); 
#endif
#elif ( ( _PANEL_DH_WIDTH==1280 ) && ( _PANEL_DV_HEIGHT == 1024 ) ) 
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)	
         OsdFuncSetPosition(_POS_PERCENT, 10, 100);
#if(_EPA_LOGO == _ON)
         OsdFuncDrawWindowPixel(_WIN0, 1159, 428, 116, 116, _CP_LOGO_IBM_WHITE, tOSD_WIN_TYPE0);
#endif
#else
         OsdFuncSetPosition(_POS_PERCENT, 10, 400);
#if(_EPA_LOGO == _ON)
         OsdFuncDrawWindowPixel(_WIN0, 1159, 428, 116, 116, _CP_LOGO_IBM_WHITE, tOSD_WIN_TYPE0);  
#endif
#endif
#elif( ( _PANEL_DH_WIDTH==1680 ) && ( _PANEL_DV_HEIGHT == 1050 ) )
         OsdFuncSetPosition(_POS_PERCENT, 35, 400);
#if(_EPA_LOGO == _ON)
         OsdFuncDrawWindowPixel(_WIN0, 1515, 536, 116, 116, _CP_LOGO_IBM_WHITE, tOSD_WIN_TYPE0); 
#endif
#elif( ( _PANEL_DH_WIDTH==1920 ) && ( _PANEL_DV_HEIGHT == 1080 ) )
         OsdFuncSetPosition(_POS_PERCENT,58,300 );//88, 600);
#if(_EPA_LOGO == _ON)
         OsdFuncDrawWindowPixel(_WIN0, 1651, 608, 116, 116, _CP_LOGO_IBM_WHITE, tOSD_WIN_TYPE0);  
#endif
#endif
        // Logo char command setting
        ScalerOsdBurstWriteDataPort(LENOVO_LOGO_COMMAND, sizeof(LENOVO_LOGO_COMMAND), GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);                     

#elif(_LOGO_TYPE == _LENOVO)

        OsdFuncApplyMap(_OSD_MAP1, COLOR(_CP_GRAY_224, _CP_BG));

        OsdFuncSetBlending(_OSD_TRANSPARENCY_ALL);    
        OsdFuncSetTransparency(GET_OSD_TRANSPARENCY_STATUS());      

        //載入1Bit Bitmap    
        OsdLoadFont(_FONT2_LOGO);   
        OsdLoadFont(_FONT1_EPA_LOGO);

        OsdLoadPalette(_PALETTE_LOGO);

#if(_EPA_LOGO == _ON)
#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
        OsdFuncSetPosition(_POS_PERCENT, 100, 50);
#else
        OsdFuncSetPosition(_POS_PERCENT, 100, 50);
#endif

#else
#if((_PANEL_DH_WIDTH == 1920) && (_PANEL_DV_HEIGHT == 1080))
		OsdFuncSetPosition(_POS_PERCENT,130,270 );
#else
		OsdFuncSetPosition(_POS_PERCENT,130,270 );
#endif
#endif

        ScalerDDomainBackgroundEnable(_ENABLE);
        ScalerDDomainBackgroundSetColor(255, 255, 255);

        ScalerOsdBurstWriteDataPort(LENOVO_LOGO_COMMAND, sizeof(LENOVO_LOGO_COMMAND), GET_CURRENT_BANK_NUMBER(), _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);                     

#elif((_LOGO_TYPE == _LENOVO_THINKVISION_EPA) || (_LOGO_TYPE == _LENOVO_THINKVISION) ||(_LOGO_TYPE == _LENOVO_2015_EPA) ||(_LOGO_TYPE == _LENOVO_2015))

	    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
	    ScalerDDomainPatternGenEnable(_ENABLE);
	    ScalerDDomainBackgroundEnable(_DISABLE);

	    OsdLoadPalette(_PALETTE_LOGO);

		//OsdTableFuncSetColorPalette(_PALETTE_INDEX3, _PALETTE_LOGO);
		
	    OsdDispDisableOsdTimerEvent();
		//OsdFuncOsdBlending(_BLENDING_TYPE1);
		OsdFuncSetTransparency(0);	  

	    OsdLoadFont(_FONT1_LOGO0);

		//OsdFontLoadFontBank2(_FONTX_LOGO);

		ScalerOsdPosition(_OSD_POSITION_GLOBAL_A, 0, 0);


#endif

        SET_OSD_LOGO_ON(_ON);    
        UserAdjustBacklightPercent(100);	//  20121011_1 fixed logo backlight
        UserInterfacePanelPowerAction(_BACKLIGHT_ON);                                //Panel控制(背光開啟)
        OsdFuncEnableOsd();
        ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO); //3秒後Logo OFF

    }
}

BYTE code tOSD_LANGUAGE_POSITION[][2]=
{
	{ROW5, COL2	},
	{ROW5, COL9	},
	{ROW5, COL16	},
	{ROW5, COL23	},
	{ROW8, COL2	},
	{ROW8, COL9	},
	{ROW8, COL16	},
	{ROW8, COL23	},
};

void OsdDispLanguageSelect(BYTE ucLanguage)
{
	OsdFuncChangeColor1Bit(ROW5, COL0, g_ucOsdWidth, HEIGHT(3), COLOR(_CP_WHITE, _CP_BG));
	OsdFuncChangeColor1Bit(ROW8, COL0, g_ucOsdWidth, HEIGHT(3), COLOR(_CP_WHITE, _CP_BG));
	
	OsdFuncChangeColor1Bit(tOSD_LANGUAGE_POSITION[ucLanguage][0], tOSD_LANGUAGE_POSITION[ucLanguage][1], LENGTH(7), HEIGHT(1), COLOR(_CP_GREEN, _CP_BG));

    OsdFuncPutChar(tOSD_LANGUAGE_POSITION[g_usAdjustValue1][0] +1, tOSD_LANGUAGE_POSITION[g_usAdjustValue1][1]+3, ___, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);//Clear prve 'up' icon

    OsdFuncPutChar(tOSD_LANGUAGE_POSITION[ucLanguage][0] +1, tOSD_LANGUAGE_POSITION[ucLanguage][1]+3, _iUP, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);  //Show current 'up' icon
}

//顯示多國語言選擇Item
void OsdDispLanguagePage(BYTE ucLanguage)
{	
	BYTE color;
	(ucLanguage == _ENGLISH) ? (color = COLOR(_CP_GREEN, _CP_BG)) : (color = COLOR(_CP_WHITE, _CP_BG));
	OsdFuncPutStringPropCenter(tOSD_LANGUAGE_POSITION[0][0], tOSD_LANGUAGE_POSITION[0][1], LENGTH(7), _PFONT_PAGE_0, tOSD_sENGLISH, _ENGLISH, color);

	(ucLanguage == _FRENCH) ? (color = COLOR(_CP_GREEN, _CP_BG)) : (color = COLOR(_CP_WHITE, _CP_BG));
	OsdFuncPutStringPropCenter(tOSD_LANGUAGE_POSITION[1][0], tOSD_LANGUAGE_POSITION[1][1], LENGTH(7), _PFONT_PAGE_0, tOSD_sFRENCH, _ENGLISH, color);

	(ucLanguage == _ITALIAN) ? (color = COLOR(_CP_GREEN, _CP_BG)) : (color = COLOR(_CP_WHITE, _CP_BG));	
	OsdFuncPutStringPropCenter(tOSD_LANGUAGE_POSITION[2][0], tOSD_LANGUAGE_POSITION[2][1], LENGTH(7), _PFONT_PAGE_0, tOSD_sITALIAN, _ENGLISH, color);

	(ucLanguage == _CHINESE_S) ? (color = COLOR(_CP_GREEN, _CP_BG)) : (color = COLOR(_CP_WHITE, _CP_BG));
	OsdFuncPutStringPropCenter(tOSD_LANGUAGE_POSITION[3][0], tOSD_LANGUAGE_POSITION[3][1], LENGTH(7), _PFONT_PAGE_0, tOSD_sCHINESE_S, _CHINESE_S, color);


	(ucLanguage == _SPANISH) ? (color = COLOR(_CP_GREEN, _CP_BG)) : (color = COLOR(_CP_WHITE, _CP_BG));
	OsdFuncPutStringPropCenter(tOSD_LANGUAGE_POSITION[4][0], tOSD_LANGUAGE_POSITION[4][1], LENGTH(7), _PFONT_PAGE_0, tOSD_sSPANISH, _ENGLISH, color);

	(ucLanguage == _JAPAN) ? (color = COLOR(_CP_GREEN, _CP_BG)) : (color = COLOR(_CP_WHITE, _CP_BG));
	OsdFuncPutStringPropCenter(tOSD_LANGUAGE_POSITION[5][0], tOSD_LANGUAGE_POSITION[5][1], LENGTH(7), _PFONT_PAGE_0, tOSD_sJAPAN, _JAPAN, color);

	(ucLanguage == _GERMAN) ? (color = COLOR(_CP_GREEN, _CP_BG)) : (color = COLOR(_CP_WHITE, _CP_BG));
	OsdFuncPutStringPropCenter(tOSD_LANGUAGE_POSITION[6][0], tOSD_LANGUAGE_POSITION[6][1], LENGTH(7), _PFONT_PAGE_0, tOSD_sGERMAN, _ENGLISH, color);

	(ucLanguage == _RUSSIAN) ? (color = COLOR(_CP_GREEN, _CP_BG)) : (color = COLOR(_CP_WHITE, _CP_BG));
	OsdFuncPutStringPropCenter(tOSD_LANGUAGE_POSITION[7][0], tOSD_LANGUAGE_POSITION[7][1], LENGTH(7), _PFONT_PAGE_0, tOSD_sRUSSIAN, _RUSSIAN, color);	

    OsdFuncPutChar(tOSD_LANGUAGE_POSITION[ucLanguage][0] +1, tOSD_LANGUAGE_POSITION[ucLanguage][1] + 3, _iUP, COLOR(_CP_GREEN, _CP_BG), _AT_FS1);	//Show current 'up' icon
}

void OsdDispInformationPage(void)
{
	BYTE xdata parray[20]= 0;
	BYTE row=ROW5,i=0;
	//OsdFuncPutStringPropAlignRight(ROW6, COL0, 13, _PFONT_PAGE_0, tOSD_sMODE, _ENGLISH, COLOR(_CP_GRAY_224, _CP_BG));
    OsdFuncPutStringPropAlignRight(row, COL0, 13, _PFONT_PAGE_0, tOSD_sMODE, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));

	//OsdFuncPutStringPropAlignRight(ROW9, COL0, 13, _PFONT_PAGE_0, tOSD_sMODE_NAME, _ENGLISH, COLOR(_CP_GRAY_224, _CP_BG));
	OsdFuncPutStringPropAlignRight(row+3, COL0, 13, _PFONT_PAGE_0, tOSD_sMODE_NAME, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));
    
	//OsdFuncPutStringPropAlignRight(ROW11, COL0, 13, _PFONT_PAGE_0, tOSD_sMICROCODE, _ENGLISH, COLOR(_CP_GRAY_224, _CP_BG));
	OsdFuncPutStringPropAlignRight(row+5, COL0, 13, _PFONT_PAGE_0, tOSD_sMICROCODE, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));

	// show resolution
	if(GET_INPUT_TIMING_HWIDTH() > 999)
	{
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() / 1000) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 1000 / 100) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 100 / 10) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 10) + _b0_;	
	}
	else
	{
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 1000 / 100) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 100 / 10) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_HWIDTH() % 10) + _b0_;	
	}

    parray[i++] = _4P_;
	parray[i++] = _mX_;
    parray[i++] = _4P_;

	if(GET_INPUT_TIMING_VHEIGHT() > 999)
	{
		parray[i++] = (GET_INPUT_TIMING_VHEIGHT() / 1000) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 1000 / 100) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 100 / 10) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 10) + _b0_;	
	}
	else
	{
		parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 1000 / 100) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 100 / 10) + _b0_;
		parray[i++] = (GET_INPUT_TIMING_VHEIGHT() % 10) + _b0_;	
	}
	
    parray[i++] = _END_;
	
	OsdFuncPutStringProp(row, COL14, _PFONT_PAGE_0, parray, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));

	// H / V
	i = 0;

	parray[i++] = (GET_INPUT_TIMING_HFREQ() / 100) + _b0_;
	parray[i++] = (GET_INPUT_TIMING_HFREQ() % 100 / 10) + _b0_;
	parray[i++] = _DOT;
	parray[i++] = (GET_INPUT_TIMING_HFREQ() % 10) + _b0_;
	parray[i++] = _K_;
	parray[i++] = _H_;
	parray[i++] = _z_;
	parray[i++] = __4;
	parray[i++] = _SLASH;
	parray[i++] = __4;
	parray[i++] = (GET_INPUT_TIMING_VFREQ() / 100) + _b0_;
	parray[i++] = (GET_INPUT_TIMING_VFREQ() % 100 / 10) + _b0_;
	parray[i++] = _DOT;
	parray[i++] = (GET_INPUT_TIMING_VFREQ() % 10) + _b0_;
	parray[i++] = _H_;
	parray[i++] = _z_;
	parray[i++] = _END_;	
	OsdFuncPutStringProp(row+1, COL14, _PFONT_PAGE_0, parray, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));

	OsdFuncPutStringProp(row+3, COL14, _PFONT_PAGE_0, tOSD_scMODE_NAME, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));

	OsdFuncPutStringProp(row+5, COL14, _PFONT_PAGE_0, tOSD_scMICROCODE, _ENGLISH, COLOR(_CP_GREEN, _CP_BG));
	
}

void OsdDispMessage(BYTE ucState)
{

	if(ucState != _MSG_FLYING)
	{
		OsdFuncApplyMap(_OSD_MAP2, COLOR(_CP_BLACK, _CP_BG));

	    OsdFuncSetBlending(_OSD_TRANSPARENCY_ALL);    
	    OsdFuncSetTransparency(GET_OSD_TRANSPARENCY_STATUS());      
	//    OsdFuncSet2BitIconOffset(_2BIT_OFFSET);    
	    OsdLoadFont(_FONT1_GLOBAL);
	    OsdLoadFont(_FONT1_P2_MAIN);                                //載入Top ICON Bitmap 
	//	OsdLoadFont(_FONT2_GLOBAL);
	    
		OsdLoadPalette(_PALETTE_COMMOND);                           //載入調色盤
		OsdFuncSetPosition(_POS_MSG, 500, 500);                     //設定OSD位置

#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_1)
		g_ucOsdFlyH = _OSD_FLY_H_STEP/2;
		g_ucOsdFlyV = _OSD_FLY_V_STEP/2;
		
		SET_OSD_FLY_H_STATE(); 
		SET_OSD_FLY_V_STATE();

#if 1//Robert Wang 20140527
		OsdFuncDrawWindow(_WIN6, ROW0, COL0, 35, 5, _CP_BLACK, tOSD_WIN_TYPE1);
#else
		OsdFuncDrawWindow(_WIN6, ROW0, COL0, 36, 5, _CP_BLACK, tOSD_WIN_TYPE1);
#endif
#else        
        //Robert Wang 20131029 modify for _MSG_FLYING
		OsdFuncDrawWindow(_WIN6, ROW0, COL0, 35, 5, _CP_BLACK, tOSD_WIN_TYPE1);
#endif
	}									   



	switch(ucState)
	{
		case _MSG_AUTO:
			OsdFuncPutStringPropCenter(ROW1, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sAUTOADJUST_0, GET_OSD_LANGUAGE(), COLOR(_CP_GREEN, _CP_BG));
			OsdFuncPutStringPropCenter(ROW3, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sAUTOADJUST_1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));
			break;
			
		case _MSG_LOCK:	
			
		    OsdFuncPutStringPropCenter(ROW2, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sMENU_LOCK, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));
			break;

		case _MSG_UNLOCK:
			
			OsdFuncPutStringPropCenter(ROW2, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sMENU_UNLOCK, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));	
			break;

		case _MSG_DDCCI_ON:			
			OsdFuncPutStringPropCenter(ROW2, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sDDCCI_ON, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
			break;

		case _MSG_DDCCI_OFF:
			
			OsdFuncPutStringPropCenter(ROW2, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sDDCCI_OFF, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
			break;
			
		case _MSG_SLEEP:				
			OsdFuncPutStringPropCenter(ROW2, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sPOWER_SAVING, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));			
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
            OsdFuncSetPosition(_POS_MSG, ((DWORD)1000*g_ucOsdFlyH/_OSD_FLY_H_STEP), ((DWORD)1000*g_ucOsdFlyV/_OSD_FLY_V_STEP));// 20120927                //設定OSD位置
#endif
			break;
						
		case _MSG_NOCABLE:
			if(GET_OSD_LANGUAGE() == _FRENCH)//lorimiao 20140531
			{
				OsdFuncPutStringPropCenter(ROW2, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sNOCABLE_0, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));				
			}
			else
			{
				OsdFuncPutStringPropCenter(ROW1, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sNOCABLE_0, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));				
				OsdFuncPutStringPropCenter(ROW3, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sNOCABLE_1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));			
			}
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
            OsdFuncSetPosition(_POS_MSG, ((DWORD)1000*g_ucOsdFlyH/_OSD_FLY_H_STEP), ((DWORD)1000*g_ucOsdFlyV/_OSD_FLY_V_STEP));// 20120927                //設定OSD位置
#endif
			break;
			
		case _MSG_OOR:
			OsdFuncPutStringPropCenter(ROW1, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sOOR_0, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));		
			OsdFuncPutStringPropCenter(ROW3, COL0, WIDTH(g_ucOsdWidth), _PFONT_PAGE_0, tOSD_sOOR_1, GET_OSD_LANGUAGE(), COLOR(_CP_WHITE, _CP_BG));	      
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
            OsdFuncSetPosition(_POS_MSG, ((DWORD)1000*g_ucOsdFlyH/_OSD_FLY_H_STEP), ((DWORD)1000*g_ucOsdFlyV/_OSD_FLY_V_STEP));// 20120927                //設定OSD位置
#endif
			break;

		case _MSG_FLYING:

			if(GET_OSD_FLY_H_STATE())
			{
				if(g_ucOsdFlyH < _OSD_FLY_H_STEP)
				{
					g_ucOsdFlyH++;
				}
				else
				{
					g_ucOsdFlyH--;
					CLR_OSD_FLY_H_STATE();
				}
			}
			else
			{
				if(g_ucOsdFlyH > 0)
				{
					g_ucOsdFlyH--;
				}
				else
				{
					g_ucOsdFlyH++;
					SET_OSD_FLY_H_STATE();
				}
			
			}

			if(GET_OSD_FLY_V_STATE())
			{
				if(g_ucOsdFlyV < _OSD_FLY_V_STEP)
				{
					g_ucOsdFlyV++;
				}
				else
				{
					g_ucOsdFlyV--;
					CLR_OSD_FLY_V_STATE();
				}
			}
			else
			{
				if(g_ucOsdFlyV > 0)
				{
					g_ucOsdFlyV--;
				}
				else
				{
					g_ucOsdFlyV++;
					SET_OSD_FLY_V_STATE();
				}
			
			}
            
			OsdFuncSetPosition(_POS_MSG, ((DWORD)1000*g_ucOsdFlyH/_OSD_FLY_H_STEP), ((DWORD)1000*g_ucOsdFlyV/_OSD_FLY_V_STEP));                //設定OSD位置

#if 1//Robert Wang 20140527(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
            if((SysModeGetModeState() == _MODE_STATUS_ACTIVE)||(SysModeGetModeState() == _MODE_STATUS_NOSUPPORT))
            {
                if(g_ucOsdFlyV%2 == 1)
                {
                    UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
                }
                else
                {
                    UserInterfaceKeyPadLedControl(_LED_POWER_OFF);                
                }
            }
#endif
			break;
			
		default:
			break;
	}

#if 1//Robert Wang 20131029 modify for _MSG_FLYING
    ScalerOsdPosition(_OSD_POSITION_FONT_A,X_POS(_MSG_POSITION_FONT_A_H_DELAY_),Y_POS(_MSG_POSITION_FONT_A_V_DELAY_));
#endif

	ScalerOsdEnableOsd();
}


/*
void OsdDispInputInfo(void)
{
	OsdFuncApplyMap(_OSD_MAP2, COLOR(_CP_GREEN_255, _CP_BG));

    OsdFuncSetBlending(_OSD_TRANSPARENCY_ALL);    
    OsdFuncSetTransparency(GET_OSD_TRANSPARENCY_STATUS());       
    OsdFuncSet2BitIconOffset(_2BIT_OFFSET);    
    OsdLoadFont(_FONT1_GLOBAL);
    OsdLoadFont(_FONT1_P2_INPUTINFO);                
    OsdLoadFont(_FONT2_GLOBAL);
    OsdLoadFont(_FONT2_DYNAMIC_INPUTINFO);
    
	OsdLoadPalette(_PALETTE_COMMOND);                          //載入調色盤
	OsdFuncSetPosition(_POS_PERCENT, 15, 980);                //設定OSD位置

	OsdFuncDrawWindow(_WIN0, ROW0, COL0, WIDTH(12), HEIGHT(4), _CP_BLACK, tOSD_WIN_TYPE0);

	if(SysSourceGetSourceType() == _SOURCE_VGA)
	{
        OsdFuncPutIcon2BitTable(ROW1, COL1, tOSD_2i_VGA, _CP_BG, _CP_GRAY_224, _CP_BG, _CP_BLUE_255);  		

		OsdFuncPutString(ROW1, COL6, _ENGLISH, tOSD_isVGA, COLOR(_CP_GREEN_255, _CP_BG), _AT_FS1);        
	}
	else
	{
		OsdFuncPutIcon2BitTable(ROW1, COL1, tOSD_2i_DVI, _CP_BG, _CP_GRAY_224, _CP_BLACK, _CP_BG);  	

		OsdFuncPutString(ROW1, COL6, _ENGLISH, tOSD_isDVI, COLOR(_CP_GREEN_255, _CP_BG), _AT_FS1);        
	}
	ScalerOsdEnableOsd();
}
*/
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
void OsdDisplayLowBlueLightHotKeyMsg(void)
{
    OsdFuncDisableOsd();
    OsdFuncApplyMap(_OSD_MAP3, COLOR(_CP_BLACK, _CP_BG));

    OsdFuncSetBlending(_OSD_TRANSPARENCY_ALL);    
    OsdFuncSetTransparency(GET_OSD_TRANSPARENCY_STATUS());      
    OsdFuncSet2BitIconOffset(_2BIT_OFFSET);   
    OsdLoadFont(_FONT1_GLOBAL);
    OsdLoadFont(_FONT2_LOWBLUELIGHT_HOTKEY);
    
    OsdLoadPalette(_PALETTE_COMMOND); 
    OsdFuncSetPosition(_POS_MSG, _OSD_LBL_H_POS, _OSD_LBL_V_POS);
	OsdFuncDrawWindow(_WIN0, ROW0, COL0, 5, 3, _CP_BG, tOSD_WIN_TYPE0);

	if(GET_LOWBLUELIGHT_STATUS() == _ENABLE)
		OsdFuncPutIcon2BitTable(ROW0, COL0, tOSD_LBL_HOTKEY_ICO_ENABLE, _CP_BLACK, _CP_WHITE, _CP_WHITE, _CP_WHITE);			
	else
		OsdFuncPutIcon2BitTable(ROW0, COL0, tOSD_LBL_HOTKEY_ICO_DISABLE, _CP_BLACK, _CP_WHITE, _CP_WHITE, _CP_WHITE);			

	OsdFuncEnableOsd();
}
#endif

#define _OSD_INPUT_WIDTH                            120
#define _OSD_INPUT_HEIGHT                           54

#define _OSD_INPUT_2BIT_OFFSET_A                    4
#define _OSD_INPUT_2BIT_OFFSET_D                    6
#define _OSD_INPUT_FONT_BASE_ADDRESS                36

#define _OSD_INPUT_ADDRESS_ROWCOMMAND               0
#define _OSD_INPUT_ADDRESS_CHARCOMMAND              4

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdDispTimingAndInputSource(void)
	{  
		OsdFuncSetBlending(_OSD_TRANSPARENCY_ALL);
		OsdFuncSetTransparency(GET_OSD_TRANSPARENCY_STATUS());	 
		
		OsdLoadPalette(_PALETTE_INPUT);
	
		switch (SysSourceGetInputPort())
		{
			case _A0_INPUT_PORT:
#if(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT)
				ScalerOsd2BitFontOffset(_OSD_INPUT_2BIT_OFFSET_A);
				ScalerOsd2FontFunction(_OSD_2_FONT_FUNCTION_LOGO);
				ScalerOsdSramBaseAddressSet(_OSD_A, _OSD_INPUT_ADDRESS_ROWCOMMAND, _OSD_INPUT_ADDRESS_CHARCOMMAND, _OSD_INPUT_FONT_BASE_ADDRESS);		
				OsdLoadFont(_FONT0_DSUB);
				break;
#endif
	
			case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
	            ScalerOsd2BitFontOffset(_OSD_INPUT_2BIT_OFFSET_D);
	            ScalerOsd2FontFunction(_OSD_2_FONT_FUNCTION_LOGO);
	            ScalerOsdSramBaseAddressSet(_OSD_A, _OSD_INPUT_ADDRESS_ROWCOMMAND, _OSD_INPUT_ADDRESS_CHARCOMMAND, _OSD_INPUT_FONT_BASE_ADDRESS);		
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
	            OsdLoadFont(_FONT0_DVI);
#elif(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)		
				OsdLoadFont(_FONT0_HDMI);
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
				OsdLoadFont(_FONT0_DP);
#endif 
#endif
				break;

			case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
	            ScalerOsd2BitFontOffset(_OSD_INPUT_2BIT_OFFSET_D);
	            ScalerOsd2FontFunction(_OSD_2_FONT_FUNCTION_LOGO);
	            ScalerOsdSramBaseAddressSet(_OSD_A, _OSD_INPUT_ADDRESS_ROWCOMMAND, _OSD_INPUT_ADDRESS_CHARCOMMAND, _OSD_INPUT_FONT_BASE_ADDRESS);		
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
	            OsdLoadFont(_FONT0_DVI);
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
	            OsdLoadFont(_FONT0_HDMI);
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
	            OsdLoadFont(_FONT0_DP);
#endif
#endif
				break;

			case _D2_INPUT_PORT:
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
	            ScalerOsd2BitFontOffset(_OSD_INPUT_2BIT_OFFSET_D);
	            ScalerOsd2FontFunction(_OSD_2_FONT_FUNCTION_LOGO);
	            ScalerOsdSramBaseAddressSet(_OSD_A, _OSD_INPUT_ADDRESS_ROWCOMMAND, _OSD_INPUT_ADDRESS_CHARCOMMAND, _OSD_INPUT_FONT_BASE_ADDRESS);		
#if(_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)
	            OsdLoadFont(_FONT0_DVI);
#elif(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
	            OsdLoadFont(_FONT0_HDMI);
#endif
#endif
			break;

	
			default:
				break;
		}
		ScalerOsdPosition(_OSD_POSITION_GLOBAL_A, 16, 18);  
		OsdFuncEnableOsd();
	}



#endif//#if(_OSD_TYPE == _LEONVO_GREEN_OSD)
