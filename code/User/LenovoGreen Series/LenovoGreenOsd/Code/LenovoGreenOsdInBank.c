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
// ID Code      : LenovoGreenOsdInBank.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFUNC__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _LEONVO_GREEN_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

BYTE code tOSD_CHARWIDTH_CHINA_0[] =
{
//Address 0x00
   12,             //__1,   
    4,             //__4,   
    8,             //__8
    9,             //_SLASH,
    4,             //_COLON,
    4,             //_DOT,    
    12,            //  
    12,            //
    5,             //_PARENT_OPEN,    
    5,             //_PARENT_CLOSE,    
    4,             //_COMMA,    
    12,            //_AT_SIGN    
    12,             //_LINE    
    9,            //__X    
    10,            //__H    
    7,            //__z    

//Address 0x10
    8,  // _0_
    8,  // _1_
    8,  // _2_
    8,  // _3_
    8,  // _4_
    8,  // _5_
    8,  // _6_
    8,  // _7_
    8,  // _8_
    8,  // _9_
    9,    
    9,    
    4,    
    7,    
    10,    
    8,  


//CHTfrom 0x21 start:
    12,// ªÅ¥Õ    
    12,// «×
    12,// «G
    12,// ¹ï
    11,// ¤ñ
    12,// ½Õ
    12,// ¾ã
    12,// ¥þ
    12,// «Ì
    11,// ©ú
    12,// ·t
    11,// ¹Ï
    12,// ¹³
    12,// ¦ì
    12,// ¸m
    12,// ¤ô

//Address 0x30    
    12,// ¥­
    12,// ²¾
    12,// °Ê
    12,// ««
    12,// ª½
    9, // ¦Û
    12,// ¤â
    12,// ³]
    12,// ©w
    12,// ¹õ
    12,// Àu
    12,// ¤Æ
    12,// ¬Û
    12,// ¤Î
    12,// ®É
    12,// ÄÁ

//Address 0x40    
    12,// ·Å
    12,// ÃC
    12,// ¬õ
    12,// ºñ
    12,// ÂÅ
    12,// ¿ï
    12,// ¶µ
    12,// °T
    12,// ®§
    12,// §ï
    12,// ÅÜ
    12,// µæ
    12,// ³æ
    12,// »y
    12,// ¨¥
    12,// «ì

//Address 0x50    
    12,// ´_
    12,// ªì
    12,// ©l
    12,// ­È
    12,// ÅT
    12,// À³
    12,// ±±
    12,// ¨î
    12,// «ö
    12,// Áä
    12,// ³t
    12,// Åã
    12,// ¥Ü
    12,// ®É
    12,// ¶¡
    12,// °h

//Address 0x60    
    10,// ¥X
    12,// «O
    12,// ¦s
    12,// ¹w
    12,// ·x
    12,// ¼Ð
    12,// ·Ç
    12,// §N
    11,// ¥Î
    11,// ¤á
    12,// Àq
    12,// »{
    12,// ¤Ï
    12,// Ãö
    12,// ºC
    12,// ¸¹

//Address 0x70    
    12,// ½u
    12,// µL
    12,// ³s
    12,// ±µ
    12,// ÀË
    12,// ¬d
    12,// ¿é
    12,// ¤J
    12,// ¶W
    12,// ½d
    11,// ³ò
    12,// ¾÷
    12,// ºØ
    11,// ¦W
    12,// ª©
    12,// ¥»

//Address 0x80    
    12,// ¼Ò
    12,// ¦¡
    11,// ¤w
    12,// ¸Ñ
    12,// Âê
    12,// ¨ú
    11,// ®ø
    10,// ¤¤
    12,// ½Ð
    12,// µy
    12,// µ¥
    12,// ¤u
    12,// ¼t
    12,// °h
    10,// ¥X
    12,// ¦â

//Address 0x90    
    12,// ½T
    12,// ¶}
    12,// ¸`
    12,// ¹q
    12,// ¤å
    12,// ºô
    12,// ­¶
    12,// ¤ù 
    12,// µø
    12,// ÀW
    12,// ¼v    
    12,// °|
    12,// ¤À
    12,// ¨Ò
    12,// ÁY
    12,// ©ñ

//Address 0xA0
    12,// Áp
    12,// ·Q
    12,// ¬¯
    12,// ±m
    12,// 
    12,// ¯à
    12,// ¾Ü
    12,// ªº
    12,// Ãþ
    12,// «¬
    12,// ÂX
    12,// ®i
    12,// ±N
    12, // ¦Ü
    12, // «Ì
    12, // »P

//Address 0xB0    
    12, // ¦P
    12, // ¼e
    12, // °ª
    12, // ªR
    12, // ¨ê
    12, // ·s
    12, // ²v
    12, // ²£
    12, // «~
    12, // ¬°
//#if(_LENOVO_DPS_SUPPORT == _ON)
    8, // ¬°
    12, // ¬°
    12, // ¬°
    12, // ¬°
    12, // ¬°
    12, // ¬°
//#endif
//Address 0xC0    
    12,
    12,
    12,
    12,
    12,
};
// 
BYTE code tOSD_CHARWIDTH_CHINA_BIG_TEXT[] =
{
//Address 0x00
   12,             //__1,   
    4,             //__4,   
    8,             //__8
    9,             //_SLASH,
    4,             //_COLON,
    4,             //_DOT,    
    12,            //_SEC_1,   
    12,            //_SEC_2,
    5,             //_PARENT_OPEN,    
    5,             //_PARENT_CLOSE,    
    4,             //_COMMA,    
    12,            //_AT_SIGN    
    12,             //_LINE    
    12,            //__    
    12,            //__    
    12,            //__    

//Address 0x10
    8,  // _0_
    8,  // _1_
    8,  // _2_
    8,  // _3_
    8,  // _4_
    8,  // _5_
    8,  // _6_
    8,  // _7_
    8,  // _8_
    8,  // _9_
    12,  // C   
    12,  // 4  
    12,    
    12,    
    12,    
    12,  

//Address 0x20
    12, // 0 // «G«×
    12, // 1 //  
    9, // 2 //
    8, // 3 // 
    12, // 4 // ¹ï¤ñ«×
    12, // 5 //
    12, // 6 //
    12, // 7 // 
    12, // 8 // ½Õ¾ã
    12, // 9 //     
    8, // A //    
    12, // B // ¹Ï¶H
    12, // C //    
    8, // D //    
    12, // E // ¦ì¸m
    12, // F //  

//Address 0x30
    8, // 0 // 
    12, // 1 // ³]©w
    12, // 2 //
    7, // 3 // 
    12, // 4 //¦â·Å
    12, // 5 //
    8, // 6 //
    12, // 7 // ¿ï¶µ
    12, // 8 //
    9, // 9 //     
    12, // A // °h¥X
    12, // B //  
    8, // C //    
    12, // D //¤ô¥­
    12, // E //     
    10, // F //  

//Address 0x40
    12, // 0 // ««ª½
    12, // 1 //  
    9, // 2 //
    12, // 3 //¤â°Ê
    12, // 4 // 
    8, // 5 //
    12, // 6 //ÃC¦â
    12, // 7 // 
    8, // 8 //
    12, // 9 // ¹w¸m
    12, // A //    
    9, // B //  
    12, // C // ¼Ò¦¡
    12, // D //    
    8, // E //     
    12, // F // ¥Î¤á

//Address 0x50
    12, // 0 // 
    10, // 1 //  
    12, // 2 //«H®§
    12, // 3 // 
    9, // 4 // 
    12, // 5 // ¾÷ºØ¦W
    12, // 6 //
    12, // 7 // 
    12, // 8 //
    12, // 9 // ª©¥»¸¹
    12, // A //    
    12, // B //  
    12, // C //    
    12, // D // µæ³æ
    12, // E //     
    9, // F //  

//Address 0x60
    12, // 0 // »y¨¥
    12, // 1 //  
    8, // 2 //
    12, // 3 // ¤u¼t
    12, // 4 // 
    9, // 5 //
    12, // 6 // Àq»{­È
    12, // 7 // 
    12, // 8 //
    12, // 9 //     
    12, // A // OSD
    12, // B //  
    12, // C // ÅTÀ³±±¨î
    12, // D //    
    12, // E //     
    12, // F //  

//Address 0x70
    12, // 0 // 
    8, // 1 //  
    12, // 2 // ®ÉÄÁ
    12, // 3 // 
    12, // 4 // 
    12, // 5 //¬Û¦ì
    12, // 6 //
    12, // 7 // 
    12, // 8 // «O¦s
    12, // 9 //     
    12, // A //    
    12, // B // ¼Ð·Ç  
    12, // C // 
    12, // D //    
    12, // E // ·x     
    5, // F // 

//Address 0x80
    12, // 0 // §N
    5, // 1 //  
    12, // 2 // ¬õ
    5,  // 3 // 
    12, // 4 // ºñ
    5,  // 5 //
    12, // 6 // ÂÅ
    5, // 7 // 
    12, // 8 // ¨ú®ø
    12, // 9 //     
    12, // A // 
    12, // B // ´_¦ì      
    12, // C //    
    12, // D //     
    12, // E // ¿é¤J     
    12, // F //  

//Address 0x90
    10, // 0 // 
    12, // 1 // «H¸¹  
    12, // 2 //
    10, // 3 // 
    12, // 4 // ¼ÒÀÀ
    12, // 5 //
    11, // 6 //
    12, // 7 // ¼Æ¦r
    12, // 8 //
    11, // 9 //     
    12, // A // DP  
    12, // B //  
    12, // C // ¦Û°Ê±½´y    
    12, // D //    
    12, // E //     
    12, // F //  

//Address 0xa0
    12, // 0 // 
    12, // 1 //  
    12, // 2 // ÁY©ñ¤ñ¨Ò
    12, // 3 // 
    12, // 4 // 
    12, // 5 //
    12, // 6 //
    8, // 7 // 
    12, // 8 // ­ì©l¼e°ª¤ñ
    12, // 9 //     
    12, // A //    
    12, // B //  
    12, // C //    
    12, // D //    
    12, // E //     
    12, // F // ¥þ«Ì¹õ  

//Address 0xb0
    12, // 0 // 
    12, // 1 //  
    12, // 2 //
    12, // 3 // Áp·Q¬¯±m¥\¯à
    12, // 4 // 
    12, // 5 //
    12, // 6 //
    12, // 7 // 
    12, // 8 //
    12, // 9 //     
    12, // A //    
    12, // B //  lorimiao 20150716 for font size modify  
    12, // C // Â²Åé¤¤¤å    
    12, // D //    
    12, // E //     
    12, // F //  

//Address 0xc0
    12, // 0 // 
    12, // 1 //  
    12, // 2 //
    12, // 3 //  lorimiao 20150716 for font size modify  
    12, // 4 // 
    12, // 5 //
    12, // 6 //
    12, // 7 // 
    12, // 8 //
    12, // 9 //     
    12, // A //    
    12, // B //  
    12, // C //    
    12, // D //    
    12, // E //     
    12, // F //  

};
BYTE code tOSD_CHARWIDTH_JAPAN_0[] =
{
//Address 0x00
   12,             //__1,   
    4,             //__4,   
    8,             //__8
    9,             //_SLASH,
    4,             //_COLON,
    4,             //_DOT,    
    4,             //dot
    12,            //
    5,             //_PARENT_OPEN,    
    5,             //_PARENT_CLOSE,    
    4,             //_COMMA,    
    12,            //_AT_SIGN    
    12,             //_LINE    
    9,             //__X    
    10,            //__H    
    7,            //__z    

//Address 0x00
    8,  // _0_
    8,  // _1_
    8,  // _2_
    8,  // _3_
    8,  // _4_
    8,  // _5_
    8,  // _6_
    8,  // _7_
    8,  // _8_
    8,  // _9_
    12,    
    12,    
    12,    
    12,    
    12,    
    12,  

//Address 0x20
    12,    

// JAP from 0x21 start:

    9,      // 0x00  £¨
    12,     // 0x01  £©
    11,     // 0x02  ¥¢
    9,      // 0x03  ¥£
    12,     // 0x04  ¥¤
    11,     // 0x05  ¤¤
    10,     // 0x06  ¥¦
    10,     // 0x07  ¥§
    12,     // 0x08  ¥©
    11,     // 0x09  ¥ª
    12,     // 0x0A  ¤ª
    10,     // 0x0B  ¥«
    12,     // 0x0C  ¤¬
    12,     // 0x0D  ¥­
    11,     // 0x0E  ¤­
    10,     // 0x0F  ¥¯
    
	//Address 0x30
    11,      // 0x10  ¤¯
    12,     // 0x11  ¥°
    12,     // 0x12  ¥±
    10,     // 0x13  ¥³
    12,     // 0x14  ¥µ
    9,      // 0x15  ¤µ
    11,     // 0x16  ¥·
    9,      // 0x17  ¤·
    11,     // 0x18  ¥¸
    10,     // 0x19  ¥¹
    12,     // 0x1A  ¤¹
    12,     // 0x1B  ¥º
    11,     // 0x1C  ¥»
    12,     // 0x1D  ¤»
    10,     // 0x1E  ¥¿
    12,     // 0x1F  ¤¿
    
	//Address 0x40
    12,     // 0x20  ¤À
    12,     // 0x21  ¥Á
    10,     // 0x22  ¤Á
    8,      // 0x23  ¥Ã
    11,      // 0x24  ¤Ã
    11,     // 0x25  ¥Æ
    11,     // 0x26  ¤Æ
    11,     // 0x27  ¥Ç
    12,     // 0x28  ¤Ç
    7,      // 0x29  ¥È
    11,      // 0x2A  ¤È
    8,      // 0x2B  ¥É
    11,     // 0x2C  ¥Ê
    12,     // 0x2D  ¤Ê
    12,     // 0x2E  ¥Ë
    11,     // 0x2F  ¤Ë

	//Address 0x50
    11,     // 0x30  ¤Î
    12,     // 0x31  ¤Ð
    12,     // 0x32  ¥Ñ
    10,     // 0x33  ¥Ó
    12,     // 0x34  ¤Ó
    9,      // 0x35  ¥Õ
    11,     // 0x36  ¥Ö
    11,     // 0x37  ¥×
    11,     // 0x38  ¥Ü
    11,     // 0x39  ¥Þ
    10,     // 0x3A  ¤Þ
    11,     // 0x3B  ¤ß
    12,     // 0x3C  ¥à
    10,     // 0x3D  ¥á
    12,     // 0x3E  ¥â
    9,      // 0x3F  ¥ã

	//Address 0x60
    10,     // 0x40  ¥å
    7,      // 0x41  ¥ç
    10,     // 0x42  ¤è
    10,     // 0x43  ¥é
    9,      // 0x44  ¤é
    8,      // 0x45  ¥ê
    12,     // 0x46  ¥ë
    10,     // 0x47  ¤ë
    9,      // 0x48  ¥ì
    12,     // 0x49  ¤ì
    9,      // 0x4A  ¥í
    10,     // 0x4B  ¥ï
    11,     // 0x4C  ¤ò
    11,     // 0x4D  ¥ó
    11,     // 0x4E  ¤ó
    12,     // 0x4F  °µ

	//Address 0x70
    12,     // 0x50  ˆó
    12,     // 0x51  ‰ä
    12,     // 0x52  ±í
    12,     // 0x53  ²¿
    12,     // 0x54  ²î
    12,     // 0x55  ˆö
    12,     // 0x56  ³à
    11,     // 0x57  ³ö
    12,     // 0x58  ³õ
    12,     // 0x59  ³ý
    12,     // 0x5A  ´¹
    12,     // 0x5B  ´ð
    12,     // 0x5C  ´ý
    12,     // 0x5D  Õ{
    12,     // 0x5E  ¶¨
    12,     // 0x5F  „Ó

	//Address 0x80
    12,     // 0x60  ¶È
    12,     // 0x61  ·Ö
    12,     // 0x62  ¸ü
    12,     // 0x63  ¹¤
    12,     // 0x64  ºÅ
    12,     // 0x65  ºÉ
    12,     // 0x66  »¯
    12,     // 0x67  »­
    12,     // 0x68  Ýx
    11,     // 0x69  ég
    12,     // 0x6A  œp
    12,     // 0x6B  ½â
    12,     // 0x6C  À´
    12,     // 0x6D  Á¦
    11,     // 0x6E  ÁË
    12,     // 0x6F  ¾v
    
	//Address 0x90
    12,     // 0x70  Ãæ
    11,     // 0x71  Ãû
    12,     // 0x72  Ã÷
    12,     // 0x73  Æ·
    12,     // 0x74  Æ½
    12,     // 0x75  ÆÚ
    12,     // 0x76  ÇÐ
    12,     // 0x77  Çà
    12,     // 0x78  Çé
    12,     // 0x79  È«
    12,     // 0x7A  Èë
    12,     // 0x7B  É«
    12,     // 0x7C  ÉÏ
    12,     // 0x7D  ÔO
    12,     // 0x7E  •r
    12,     // 0x7F  Ê¾

	//Address 0xa0
    12,     // 0x80  ßm
    12,     // 0x81  ÊÖ
    12,     // 0x82  Ë®
    12,     // 0x83  ËÙ
    12,     // 0x84  Ìå
    12,     // 0x85  ‘ø
    12,     // 0x86  Î»
    12,     // 0x87  ?
    12,     // 0x88  ÏÂ
    12,     // 0x89  Ïà
    12,     // 0x8A  ?
    12,     // 0x8B  Ïñ
    12,     // 0x8C  ÐÅ
    12,     // 0x8D  ÐÐ
    12,     // 0x8E  ßx
    12,     // 0x8F  ÑÔ

	//Address 0xb0
    12,     // 0x90  ÒÆ
    12,     // 0x91  ?
    12,     // 0x92  ê
    12,     // 0x93  ÓÒ
    12,     // 0x94  ÕZ
    12,     // 0x95  ’k
    12,     // 0x96  ?
    12,     // 0x97  Õû
    12,     // 0x98  Ö±
    12,     // 0x99  ÖÃ
    12,     // 0x9A  Ñu
    11,     // 0x9B  ÖÐ
    12,     // 0x9C  ½K
    11,     // 0x9D  ×Ô
    12,     // 0x9E  ×î
    12,     // 0x9F  ×ó

	//Address 0xc0
    12,     
    12,    
    11,		
    12,    
    11,		
    12,     
    11,		
    12,     
    11,		
	12, 	
	11, 	
	12,     
	11,		
	12,     
	11,	
	12,	
	
	//Address 0xd0
	12, 	
	12,    
	12, 	
	12,    
	12, 	
	12, 	
	12, 	
	12, 	
	12, 	
	12, 	
	12, 	
	12, 	
	12, 	
	12, 	
	12, 
	12, 
/*
    //ICON _JT0_
    12, // 0x00
    12, // 0x01
    12, // 0x02
    12, // 0x03
    12, // 0x04
    12, // 0x05
    12, // 0x06
    12, // 0x07
    12, // 0x08
    12, // 0x09
    12, // 0x0A
    12, // 0x0B
    12, // 0x0C
    12, // 0x0D
    12, // 0x0E
    12, // 0x0F
    12, // 0x10
    12, // 0x11
    12, // 0x12
    12, // 0x13
    12, // 0x14
    12, // 0x15
    12,     // 0x16
*/


};


BYTE code tOSD_CHARWIDTH_JAPAN_BIG1[] =
{
//Address 0x00
   12,             //__1,   
    4,             //__4,   
    8,             //__8
    9,             //_SLASH,
    4,             //_COLON,
    4,             //_DOT,    
    12,            //_SEC_1,   
    12,            //_SEC_2,
    5,             //_PARENT_OPEN,    
    5,             //_PARENT_CLOSE,    
    4,             //_COMMA,    
    12,            //_AT_SIGN    
    12,             //_LINE    
    12,            //__    
    12,            //__    
    12,            //__    

    
// address 0x10
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    9, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x20
    12, // 0
    12, // 1
    4, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    6, // C
    12, // D
    12, // E
    12, // F

// address 0x30
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    9, // C
    12, // D
    12, // E
    12, // F

// address 0x40
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    6, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x50
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    6, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    6, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F
    
// address 0x60
    12, // 0
    12, // 1
    12, // 2
    4, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    6, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x70
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    2, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x80
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    3, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x90
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0xA0
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0xB0
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0xC0
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0xD0
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0xE0
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F




};



BYTE code tOSD_CHARWIDTH_JAPAN_BIG2[] =
{
//Address 0x00
   12,             //__1,   
    4,             //__4,   
    8,             //__8
    9,             //_SLASH,
    4,             //_COLON,
    4,             //_DOT,    
    12,            //_SEC_1,   
    12,            //_SEC_2,
    5,             //_PARENT_OPEN,    
    5,             //_PARENT_CLOSE,    
    4,             //_COMMA,    
    12,            //_AT_SIGN    
    12,             //_LINE    
    12,            //__    
    12,            //__    
    12,            //__    

// address 0x10
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x20
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x30
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x40
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F
    
// address 0x50
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x60
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x70
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F

// address 0x80
    12, // 0
    12, // 1
    12, // 2
    12, // 3
    12, // 4
    12, // 5
    12, // 6 
    12, // 7
    12, // 8
    12, // 9
    12, // A
    12, // B
    12, // C
    12, // D
    12, // E
    12, // F


};

//«X¤å¦r¼e
BYTE code tOSD_CHARWIDTH_RUSSIAN[] =
{
//Address 0x00
   12,             //__1,   
    4,             //__4,   
    8,             //__8
    9,             //_SLASH,
    4,             //_COLON,
    4,             //_DOT,    
    12,            //
    12,            //
    5,             //_PARENT_OPEN,    
    5,             //_PARENT_CLOSE,    
    4,             //_COMMA,    
    12,            //_AT_SIGN    
    12,             //_LINE    
    12,            //  
    12,            //  
    12,            //  

//Address 0x10
    8,  // _0_
    8,  // _1_
    8,  // _2_
    8,  // _3_
    8,  // _4_
    8,  // _5_
    8,  // _6_
    8,  // _7_
    8,  // _8_
    8,  // _9_
    7,    
    7,    
    7,    
    7,    
    7,    
    12,  

//Address 0x20
    11,    // 0x20
    11,   // 0x21
    11,    // 0x22
    9,     // 0x23
    11,   // 0x24
    11,   // 0x25
    8,    // 0x26
    11,   // 0x27
    11,   // 0x28
    12,    // 0x29
    13,    // 0x2A
    12,    // 0x2B
    13,   // 0x2C
    13,   // 0x2D
    13,   // 0x2E
    3,     // 0x2F
    
    11,    // 0x30
    13,    // 0x31
    11,   // 0x32
    11,    // 0x33
    11,    // 0x34
    13,    // 0x35
    10,    // 0x36
    11,   // 0x37
    10,    // 0x38
    11,    // 0x39
    9,     // 0x3A
    9,    // 0x3B
    11,    // 0x3C
    11,    // 0x3D
    9,    // 0x3E
   10,   // 0x3F
    
    10,    // 0x40
    9,    // 0x41
    10,    // 0x42
    7,    // 0x43
    7,    // 0x44
    8,    // 0x45
    7,    // 0x46
    10,    // 0x47
    10,    // 0x48
    10,    // 0x49
    9,    // 0x4A
    8,    // 0x4B
    8,    // 0x4C
    10,    // 0x4D
    10,    // 0x4E
    10,    // 0x4F
    
    9,     // 0x50
    9,    // 0x51
    8,     // 0x52
    6,    // 0x53
    9,     // 0x54
    8,    // 0x55
    6,    // 0x56
    6,    // 0x57
    11,    // 0x58
    6,     // 0x59
    9,     // 0x5A
    9,     // 0x5B
    10,    // 0x5C
    9,    // 0x5D
    10,    // 0x5E
    10,    // 0x5F
    
    9,     // 0x60
    7,     // 0x61
    7,     // 0x62
    8,     // 0x63
    9,     // 0x64
    8,     // 0x65
    8,     // 0x66
    7,     // 0x67
    7,     // 0x68
    11,     // 0x69
    10,     // 0x6A
    11,     // 0x6B
    11,     // 0x6C
    10,     // 0x6D
    10,     // 0x6E
    11,     // 0x6F
    
    10,    // 0x70
    9,     // 0x71
    10,     // 0x72
    9,     // 0x73
    10,     // 0x74
    9,     // 0x75
    12,     // 0x76
    10,     // 0x77
    11,     // 0x78
    10,     // 0x79
    3,    // 0x7A
    9,    // 0x7B
    9,     // 0x7C
    10,     // 0x7D
    10,     // 0x7E
    10,     // 0x7F
    
    10,     // 0x80
    8,     // 0x81
    8,    // 0x82
    8,     // 0x83
    8,    // 0x84
    9,     // 0x85
    8,     // 0x86
    9,     // 0x87
    7,     // 0x88
    7,     // 0x89
    8,     // 0x8A
    8,     // 0x8B
    7,     // 0x8C
    7,     // 0x8D
    7,     // 0x8E
    7,     // 0x8F
    
    8,     // 0x90
    11,     // 0x91
    9,     // 0x92
    8,     // 0x93
    8,     // 0x94
    8,     // 0x95
    9,     // 0x96
    9,     // 0x97
    7,    // 0x98
    7,    // 0x99
    7,    // 0x9A
    11,    // 0x9B
    12,     // 0x9C
    8,     // 0x9D
    7,     // 0x9E
    8,     // 0x9F
    
    9,     // 0xA0
    9,     // 0xA1
    6,     // 0xA2
    10,     // 0xA3
    8,     // 0xA4
    10,     // 0xA5
    8,     // 0xA6
    8,     // 0xA7
    9,     // 0xA8
    7,     // 0xA9
    6,     // 0xAa
    7,     // 0xAb
    7,     // 0xAc
    6,     // 0xAd
    6,     // 0xAe
    7,     // 0xAf
    
    6,    // 0xB0
    7,    // 0xB1
    9,    // 0xB2
    8,    // 0xB3
#if(_LENOVO_DPS_SUPPORT == _ON)
    9,    // 0xB4
#elif(_USER_DCR_FUNCTION == _ON)   
	12,    //0xB4
#endif

};

BYTE code tOSD_CHARWIDTH_LATIN[] =
{
//Address 0x00
    12,  //__1,   
    4,   //__4,   
    8,   //__8
    9,   //_SLASH,
    4,   //_COLON,
    4,   //_DOT,    
    12,  //  
    12,  //
    5,   //_PARENT_OPEN,    
    5,   //_PARENT_CLOSE,    
    4,   //_COMMA,    
    12,  //_AT_SIGN   
    12,   //_LINE    
    10,  //    
    4,   //  
    10,  //  

//Address 0x10
    8,  // _0_
    8,  // _1_
    8,  // _2_
    8,  // _3_
    8,  // _4_
    8,  // _5_
    8,  // _6_
    8,  // _7_
    8,  // _8_
    8,  // _9_
    10,    
    10,    
    9,    
    10,    
    9,    
    6,  
    
//Address 0x20
    //English
    7,    // 0x3A  a
    7,    // 0x3B  b
    6,    // 0x3C  c
    7,    // 0x3D  d
    7,    // 0x3E  e
    5,    // 0x3F  f
    7,    // 0x40  g
    7,    // 0x41  h
    4,    // 0x42  i
    4,    // 0x43  j
    7,    // 0x44  k
    4,    // 0x45  l
    10,   // 0x46  m
    7,    // 0x47  n
    7,    // 0x48  o
    7,    // 0x49  p

//Address 0x30 
    7,    // 0x4A  q
    5,    // 0x4B  r
    6,    // 0x4C  s
    5,    // 0x4D  t
    7,    // 0x4E  u
    8,    // 0x4F  v
    10,   // 0x50  w
    7,    // 0x51  x
    8,    // 0x52  y
    7,    // 0x53  z
    7,    // 0x1A   
    7,    // 0x1B
    7,    // 0x1C
    7,    // 0x1D
    7,    // 0x1E
    7,    // 0x1F
//Address 0x40     
    10,   // 0x20  a
    10,   // 0x21  b
    9,    // 0x22  c
    10,   // 0x23  d
    10,   // 0x24  e
    6,    // 0x25  f
    10,   // 0x26  g
    9,    // 0x27  h
    4,    // 0x28  i
    4,    // 0x29  j
    9,    // 0x2A  k
    4,    // 0x2B  l
    12,   // 0x2C  m
    9,    // 0x2D  n
    9,    // 0x2E  o
    10,   // 0x2F  p
//Address 0x50     
    10,   // 0x30  q
    6,    // 0x31  r
    9,    // 0x32  s
    6,    // 0x33  t
    9,    // 0x34  u
    10,   // 0x35  v
    12,   // 0x36  w
    10,   // 0x37  x
    9,    // 0x38  y
    10,   // 0x39  z

    12,   // 0x00  A
    11,   // 0x01  B
    12,   // 0x02  C
    11,   // 0x03  D
    11,   // 0x04  E
    10,   // 0x05  F
//Address 0x60         
    12,   // 0x06  G
    12,   // 0x07  H
    4,    // 0x08  I
    7,    // 0x09  J
    12,   // 0x0A  K
    9,    // 0x0B  L
    12,   // 0x0C  M
    12,   // 0x0D  N
    12,   // 0x0E  O
    11,   // 0x0F  P
    12,   // 0x10  Q
    12,   // 0x11  R
    11,   // 0x12  S
    10,   // 0x13  T
    12,   // 0x14  U
    12,   // 0x15  V
    12,   // 0x16  W
//Address 0x70         
    12,   // 0x17  X
    12,   // 0x18  Y
    11,   // 0x19  Z

    10,   // 0x54  A
    8,    // 0x55  B
    9,    // 0x56  C
    9,    // 0x57  D
    8,    // 0x58  E
    8,    // 0x59  F
    10,   // 0x5A  G
    8,    // 0x5B  H
    4,    // 0x5C  I
    6,    // 0x5D  J
    9,    // 0x5E  K
    8,    // 0x5F  L
//Address 0x80         
    10,   // 0x60  M
    8,    // 0x61  N
    10,   // 0x62  O
    8,    // 0x63  P
    10,   // 0x64  Q
    9,    // 0x65  R
    8,    // 0x66  S
    8,    // 0x67  T
    8,    // 0x68  U
    10,   // 0x69  V
    12,   // 0x6A  W
    9,    // 0x6B  X
    10,   // 0x6C  Y
    9,    // 0x6D  Z

    10,   //   A
    10,   //   B
//Address 0x90     
    10,   //   C    
    10,   //   D
    9,    //   E
    8,    //   F
    11,   //   G
    10,   //   H
    4,    //   I
    8,    //   J
    10,   //   K
    8,    //   L
    12,   //   M
    10,   //   N
    11,   //   O
    9,    //   P
    11,   //   Q
    10,   //   R
//Address 0xa0         
    9,    //   S
    9,    //   T
    10,   //   U
    10,   //   V
    12,   //   W
    9,    //   X
    9,    //   Y
    9,    //   Z

    7,    //   a
    8,    //   b
    7,    //   c
    8,    //   d
    8,    //   e
    7,    //   f
    8,    //   g
    8,    //   h
//Address 0xb0         
    4,    //   i
    4,    //   j
    7,    //   k
    4,    //   l
    11,   //   m
    8,    //   n
    8,    //   o
    8,    //   p
    8,    //   q
    6,    //   r
    7,    //   s
    6,    //   t
    8,    //   u
    8,    //   v
    12,   //   w
    7,    //   x
//Address 0xc0         
    8,    //   y
    7,    //   z

    8,    // EU e'
    7,    // EU a
    8,    // EU o'
    7,    // EU a'
    8,    // EU u:
    8,    // EU u'
    8,    // EU o:
    11,    // EU d'
    8,    // EU u
    7,    // EU a:
    6,    // EU i'
    7,    // EU a^
    5,    // EU i^
    9,    // EU d'

//Address 0xd0             
    12,    // EU d'
    7,    // EU u'
    7,    // EU u:
    7,    // EU o:
    7,    // EU a:    
    8,    // EU b
    7,    // EU a'
    9,    // EU cc
    9,    // EU n~
    4,   // EU l' 
    10,     //b0
    6,      //b1  
    10,     //b2
    10,     //b3
    11,     //b4
    10,     //b5

//Address 0xe0             
    10,     //b6
    10,     //b7
    10,     //b8
    10,     //b9
    10,     //Big EU e'    
    8,     //m EU n~

    _END_,
};


#if 1
BYTE code tROW_COMMAND_MAP0[] =
{
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 2
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 3
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 4
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 5
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 6
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 7
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 8
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 9
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 10
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 11
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 12
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 13
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 14	
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 14	
};

#if(_LOGO_TYPE == _IBM_THINKVISION_LENOVO)

//20120801 Abel 1Bit Logo Modify
//Logoµøµ¡¤j¤pRow Command
BYTE code tROW_COMMAND_MAP1[] =
{
#if ( ( _PANEL_DH_WIDTH==1440 ) && ( _PANEL_DV_HEIGHT == 900 ) )
    //Logo1440x900µøµ¡¤j¤p114¦r¼ex25¦r°ª
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 0
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 1
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 2
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 3
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 4
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 5
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 6
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 7
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 8
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 9
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 10
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 11
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 12
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 13
    
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 14   
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 15
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 16
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 17
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 18
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 19
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 20
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 21
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 22
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 23
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 24       
    
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 25
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 26
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 27
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 33

#elif ( ( _PANEL_DH_WIDTH==1600 ) && ( _PANEL_DV_HEIGHT == 900 ) )
    //Logo1600x900
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 0
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 1
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 2
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 3
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 4
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 5
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 6
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 7
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 8
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 9
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 10
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 11
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 12
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 13
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),    // row 14
    
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 15   
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 16
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 17
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 18
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 19
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 20
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 21
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 22
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 23
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 24
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 25       
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),    // row 26     
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 27
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 33
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 34
	
#elif ( ( _PANEL_DH_WIDTH==1280 ) && ( _PANEL_DV_HEIGHT == 1024 ) )
    //Logo1280x1024 °Ï¶ô«D¥¿¤è§Î23¦r°ª
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 2
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 3
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 4
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 5
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 6
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 7
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 8
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 9
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 10
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 11
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 12
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 13
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 14	
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 15
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 16
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 17
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 18
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 19
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 20
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 21
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 22
    
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 24
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 25
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 26
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 27
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32
	
#elif( ( _PANEL_DH_WIDTH==1680 ) && ( _PANEL_DV_HEIGHT == 1050 ) )
    //Logo1680x1050 °Ï¶ô«D¥¿¤è§Î28¦r°ª
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 2
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 3
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 4
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 5
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 6
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 7
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 8
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 9
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 10
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 11
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 12
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 13
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 14	
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 15
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 16
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 17
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 18
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 19
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 20
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 21
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 22
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 23
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 24
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 25
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 26
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 27
    
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 33
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 34
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 35
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 36

#elif( ( _PANEL_DH_WIDTH==1920 ) && ( _PANEL_DV_HEIGHT == 1080 ) )
    //Logo19200x1080 µøµ¡¤j¤p«D¥¿¤è§Î32¦r°ª
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 2
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 3
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 4
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 5
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 6
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 7
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 8
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 9
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 10
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 11
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 12
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 13
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 14	
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 15
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 16
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL1_SIZE)),	// row 17
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 18
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 19
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 20
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 21
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 22
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 23
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 24
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 25
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 26
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 27
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 28
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 29
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 30
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL2_SIZE)),	// row 31

    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 24
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 25
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 26
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 27
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 28
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 29
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 30
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 31
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 32

#endif
    
};

#elif(_LOGO_TYPE == _LENOVO)

BYTE code tROW_COMMAND_MAP1[] =
{
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 0
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 1
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 2
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 3
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_LOGO_COL_SIZE)),    // row 4
#if(_EPA_LOGO==_ON)	
    //ROW SPACE
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 5
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 6
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 7
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 8
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_SPACE_LOGO_COL_SIZE)),    // row 9
    //EPA_LOGO
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 10
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 11
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 12
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 13
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 14
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 15
    ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(_OSD_EPA_LOGO_COL_SIZE)),   // row 16
#endif
};

#endif



BYTE code tROW_COMMAND_MAP2[] =
{
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 2
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 3
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(35)),	// row 4
};
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
BYTE code tROW_COMMAND_MAP3[] =
{
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(5)),	// row 0
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(5)),	// row 1
	ROWCOMMAND(_ROW_START, _VBI_DISABLE, _1BIT_0_511, _1BIT_BS_NONE, _CHAR_WIDTH_NORMAL, _CHAR_HEIGHT_NORMAL, ROW_HEIGHT(18), COL_SPACE(0), ROW_LENGTH(5)),	// row 2
};
#endif
//¤¤¤å²ÓÅé
#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE OsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer);
BYTE OsdFuncGetOsdFontPointer(BYTE ucPointerSelect);
void OsdFuncApplyMap(BYTE ucOsdMap, BYTE ucColor);
WORD OsdFuncGetAddr(BYTE ucOsdMap, BYTE ucRow, BYTE ucCol);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE OsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer)
{
    ucPointer++;

    if(ucPointerSelect == _PFONT_PAGE_0)
    {
        if(ucPointer >= _OSD_PAGE_0_END)
        {
            ucPointer = _OSD_PAGE_0_START;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_1)
    {
        if(ucPointer >= _OSD_PAGE_1_END)
        {
            ucPointer = _OSD_PAGE_1_START;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_2)
    {
        if(ucPointer >= _OSD_PAGE_2_END)
        {
            ucPointer = _OSD_PAGE_2_START;
        }
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_0)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_0_END)
        {
            ucPointer = _SUB_PAGE_ITEM_0;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_1)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_1_END)
        {
            ucPointer = _SUB_PAGE_ITEM_1;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_2)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_2_END)
        {
            ucPointer = _SUB_PAGE_ITEM_2;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_3)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_3_END)
        {
            ucPointer = _SUB_PAGE_ITEM_3;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_4)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_4_END)
        {
            ucPointer = _SUB_PAGE_ITEM_4;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_5)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_5_END)
        {
            ucPointer = _SUB_PAGE_ITEM_5;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_6)
    {
        if(ucPointer >= _SUB_PAGE_ITEM_6_END)
        {
            ucPointer = _SUB_PAGE_ITEM_6;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_NUMBER_0)
    {
        if(ucPointer >= _SUB_PAGE_NUMBER_0_END)
        {
            ucPointer = _SUB_PAGE_NUMBER_0;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_NUMBER_1)
    {
        if(ucPointer >= _SUB_PAGE_NUMBER_1_END)
        {
            ucPointer = _SUB_PAGE_NUMBER_1;
        }
    }        
    else if(ucPointerSelect == _PFONT_PAGE_NUMBER_2)
    {
        if(ucPointer >= _SUB_PAGE_NUMBER_2_END)
        {
            ucPointer = _SUB_PAGE_NUMBER_2;
        }
    }        
    
    return ucPointer;        
}


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE OsdFuncGetOsdFontPointer(BYTE ucPointerSelect)
{
    BYTE ucPointer = 0;
    
    if(ucPointerSelect == _PFONT_PAGE_0)
    {
        ucPointer = g_ucFontPointer0;
    }
    else if(ucPointerSelect  == _PFONT_PAGE_1)
    {
        ucPointer = g_ucFontPointer1;
    }
    else if(ucPointerSelect == _PFONT_PAGE_2)
    {
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_0)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_0;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_1)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_1;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_2)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_2;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_3)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_3;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_4)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_4;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_5)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_5;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_ITEM_6)
    {
        g_ucFontPointer2 = _SUB_PAGE_ITEM_6;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_NUMBER_0)
    {
        g_ucFontPointer2 = _SUB_PAGE_NUMBER_0;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_NUMBER_1)
    {
        g_ucFontPointer2 = _SUB_PAGE_NUMBER_1;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_NUMBER_2)
    {
        g_ucFontPointer2 = _SUB_PAGE_NUMBER_2;
        ucPointer = g_ucFontPointer2;
    }
#if(_LEONVO_GREEN_OSD_STYLE==_LEONVO_GREEN_OSD_STYLE_0)
    else if(ucPointerSelect == _PFONT_PAGE_NUMBER_3)
    {
        g_ucFontPointer2 = _SUB_PAGE_NUMBER_3;
        ucPointer = g_ucFontPointer2;
    }
    else if(ucPointerSelect == _PFONT_PAGE_NUMBER_4)
    {
        g_ucFontPointer2 = _SUB_PAGE_NUMBER_4;
        ucPointer = g_ucFontPointer2;
    }
#endif    
    return ucPointer;    
}


//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
BYTE OsdFucnGetCharWidth(BYTE ucChar, BYTE ucFontTabSelect, BYTE ucLanguage)
{
	BYTE pixel;
	
	if(ucLanguage == _CHINESE_S)
	{
		if(ucFontTabSelect == _TABSEL_CHT_BIG)
		{
			pixel = tOSD_CHARWIDTH_CHINA_BIG_TEXT[ucChar];
		}
		else if(ucFontTabSelect == _TABSEL_CHT_ENG)
		{
			pixel = tOSD_CHARWIDTH_LATIN[ucChar];
		}		
		else
		{
			pixel = tOSD_CHARWIDTH_CHINA_0[ucChar];
		}
		
	}
	else if(ucLanguage == _JAPAN)
	{
		if(ucFontTabSelect == _TABSEL_JAP_ENG)
		{
			pixel = tOSD_CHARWIDTH_LATIN[ucChar];		
		}
		else if(ucFontTabSelect == _TABSEL_JAP_BIG1)
		{
			pixel = tOSD_CHARWIDTH_JAPAN_BIG1[ucChar];		
		}
		else if(ucFontTabSelect == _TABSEL_JAP_BIG2)
		{
			pixel = tOSD_CHARWIDTH_JAPAN_BIG2[ucChar];		
		}       
		else
		{
			pixel = tOSD_CHARWIDTH_JAPAN_0[ucChar];
		}		
	}
    else if(ucLanguage == _RUSSIAN)
	{
		pixel = tOSD_CHARWIDTH_RUSSIAN[ucChar];
	}    
	else
    {
        pixel = tOSD_CHARWIDTH_LATIN[ucChar];
    }                   

	return pixel;
}

#if 1

void OsdFuncPutChar(BYTE ucRow, BYTE ucCol, BYTE ucChar, BYTE ucColor, BYTE ucAttribute)
{
    ScalerOsdCommandAllByte(OsdFuncGetAddr(g_ucOsdMap, ucRow, ucCol), ucAttribute, ucChar, ucColor);
}

void OsdFuncPutCharSeries(BYTE ucRow, BYTE ucCol, BYTE ucChar, BYTE ucColor, BYTE ucAttribute, BYTE ucLength)
{
	ScalerOsdCharCommandByteSeries(OsdFuncGetAddr(g_ucOsdMap, ucRow, ucCol), _OSD_BYTE1, ucChar, ucLength);
	ScalerOsdCharCommandByteSeries(OsdFuncGetAddr(g_ucOsdMap, ucRow, ucCol), _OSD_BYTE2, ucColor, ucLength);
	ScalerOsdCharCommandByteSeries(OsdFuncGetAddr(g_ucOsdMap, ucRow, ucCol), _OSD_BYTE0, ucAttribute, ucLength);
}

//--------------------------------------------------
// Description	: 
// Input Value	: None
// Output Value : None
//--------------------------------------------------
void OsdFuncApplyMap(BYTE ucOsdMap, BYTE ucColor)
{
	BYTE i;

	g_ucOsdMap = ucOsdMap;
	
	switch(ucOsdMap)
	{
		case _OSD_MAP0:

            //==================	
			g_ucOsdHeight = sizeof(tROW_COMMAND_MAP0)/3;  // tROW_COMMAND_MAP0 is a nx3 matrix
			g_ucOsdWidth = tROW_COMMAND_MAP0[2];	
			// row command
			for(i=0;i<g_ucOsdHeight;i++)  
			{
				ScalerOsdCommandAllByte(i, tROW_COMMAND_MAP0[(i*3)+0], tROW_COMMAND_MAP0[(i*3)+1], tROW_COMMAND_MAP0[(i*3)+2]);
			}
			// row command end
			ScalerOsdCommandByte(g_ucOsdHeight, _OSD_BYTE0, _ROW_END);
            //==================

            //==================
			// calc char start address
			g_usFontSelectStart = g_ucOsdHeight + 1; // char start = display area start = Row command + 1(end) 
            //==================


            //==================
			// calc font start address
			g_usFontTableStart = g_usFontSelectStart;			
			for(i=0;i<g_ucOsdHeight;i++)
			{
				g_usFontTableStart += tROW_COMMAND_MAP0[(i*3)+2]; // font start = display area(OSD row X Col) + Row command + 1(end)
			}
            //==================			


            //==================			            
			// char command initial
			// char byte 0 = _AT_NORMAL(0x8c) // font select 0 ~ 255
			ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, ___, ucColor, (g_usFontTableStart-g_usFontSelectStart));
            
            //==================			

			break;

        case _OSD_MAP1:      //20120801 Abel 1Bit Logo Modify
#if((_LOGO_TYPE != _LENOVO_THINKVISION) && (_LOGO_TYPE != _LENOVO_THINKVISION_EPA) && (_LOGO_TYPE != _LENOVO_2015_EPA) && (_LOGO_TYPE != _LENOVO_2015))

			g_ucOsdHeight = sizeof(tROW_COMMAND_MAP1)/3;
			g_ucOsdWidth = tROW_COMMAND_MAP1[2];	
	
			// row command
			for(i=0;i<g_ucOsdHeight;i++)
			{
				ScalerOsdCommandAllByte(i, tROW_COMMAND_MAP1[(i*3)+0], tROW_COMMAND_MAP1[(i*3)+1], tROW_COMMAND_MAP1[(i*3)+2]);
			}

			// row command end
			ScalerOsdCommandByte(g_ucOsdHeight, _OSD_BYTE0, _ROW_END);


			// calc char start address
			g_usFontSelectStart = g_ucOsdHeight + 1;

			// calc font start address
			g_usFontTableStart = g_usFontSelectStart;
			
			for(i=0;i<g_ucOsdHeight;i++)
			{
				g_usFontTableStart += tROW_COMMAND_MAP1[(i*3)+2];
			}
            
            // char command initial(©Ò¦³³£¶ñªÅ¥Õ)   
         #if ( ( _PANEL_DH_WIDTH==1440 ) && ( _PANEL_DV_HEIGHT == 900 ) )          
        	// char byte 0 = _AT_NORMAL(0x8c) (1440x900 ªÅ¥Õ¦b0x06)        	
        	ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x06, ucColor, (g_usFontTableStart-g_usFontSelectStart));
         #elif ( ( _PANEL_DH_WIDTH==1600 ) && ( _PANEL_DV_HEIGHT == 900 ) )          
            // char byte 0 = _AT_NORMAL(0x8c) (1440x900 ªÅ¥Õ¦b0x06)         
            ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x06, ucColor, (g_usFontTableStart-g_usFontSelectStart));         
         #elif ( ( _PANEL_DH_WIDTH==1280 ) && ( _PANEL_DV_HEIGHT == 1024 ) ) 
            //1280x1024 ªÅ¥Õ¦b0x02
        	ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x02, ucColor, (g_usFontTableStart-g_usFontSelectStart)); 
         #elif( ( _PANEL_DH_WIDTH==1680 ) && ( _PANEL_DV_HEIGHT == 1050 ) )
            //1680x1050 ªÅ¥Õ¦b0x02
        	ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x02, ucColor, (g_usFontTableStart-g_usFontSelectStart)); 
         #elif( ( _PANEL_DH_WIDTH==1920 ) && ( _PANEL_DV_HEIGHT == 1080 ) )
            //1920x1080 ªÅ¥Õ¦b0x03
        	ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, 0x03, ucColor, (g_usFontTableStart-g_usFontSelectStart));
         #endif
 #endif        
			break;		


		case _OSD_MAP2:
			g_ucOsdHeight = sizeof(tROW_COMMAND_MAP2)/3;
			g_ucOsdWidth = tROW_COMMAND_MAP2[2];	
	
			// row command
			for(i=0;i<g_ucOsdHeight;i++)
			{
				ScalerOsdCommandAllByte(i, tROW_COMMAND_MAP2[(i*3)+0], tROW_COMMAND_MAP2[(i*3)+1], tROW_COMMAND_MAP2[(i*3)+2]);
			}

			// row command end
			ScalerOsdCommandByte(g_ucOsdHeight, _OSD_BYTE0, _ROW_END);


			// calc char start address
			g_usFontSelectStart = g_ucOsdHeight + 1;

			// calc font start address
			g_usFontTableStart = g_usFontSelectStart;
			
			for(i=0;i<g_ucOsdHeight;i++)
			{
				g_usFontTableStart += tROW_COMMAND_MAP2[(i*3)+2];
			}
			
			// char command initial
			// char byte 0 = _AT_NORMAL(0x8c) // font select 0 ~ 255
			ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, ___, ucColor, (g_usFontTableStart-g_usFontSelectStart));
		
			break;
#if(_LOW_BLUE_LIGHT_FUNCTION == _ON)
		case _OSD_MAP3:
			g_ucOsdHeight = sizeof(tROW_COMMAND_MAP3)/3;
			g_ucOsdWidth = tROW_COMMAND_MAP3[2];	
	
			// row command
			for(i=0;i<g_ucOsdHeight;i++)
			{
				ScalerOsdCommandAllByte(i, tROW_COMMAND_MAP3[(i*3)+0], tROW_COMMAND_MAP3[(i*3)+1], tROW_COMMAND_MAP3[(i*3)+2]);
			}

			// row command end
			ScalerOsdCommandByte(g_ucOsdHeight, _OSD_BYTE0, _ROW_END);


			// calc char start address
			g_usFontSelectStart = g_ucOsdHeight + 1;

			// calc font start address
			g_usFontTableStart = g_usFontSelectStart;
			
			for(i=0;i<g_ucOsdHeight;i++)
			{
				g_usFontTableStart += tROW_COMMAND_MAP3[(i*3)+2];
			}
			
			// char command initial
			// char byte 0 = _AT_NORMAL(0x8c) // font select 0 ~ 255
			ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, _AT_NORMAL, ___, ucColor, (g_usFontTableStart-g_usFontSelectStart));
		
			break;
#endif
		default:
			break;

	}

	// setting char&font start address
	ScalerOsdFrameControlAllByte(0x004, _OSD_WITHOUT_DB, (BYTE)g_usFontSelectStart, ((g_usFontSelectStart >> 4) & 0xf0) | (g_usFontTableStart & 0x0f), g_usFontTableStart >> 4);


	// select ena as OSD Vsync input
	ScalerOsdFrameControlByte(0x003, _OSD_BYTE0, 0x10);

	// set char shadow color
	ScalerOsdFrameControlByte(0x003, _OSD_BYTE1, 0x00);
}

WORD OsdFuncGetAddr(BYTE ucOsdMap, BYTE ucRow, BYTE ucCol)
{
	WORD usaddr=g_ucOsdHeight+1;

    BYTE *ptabaddr;

	switch(ucOsdMap)
	{
		case _OSD_MAP0:
			ptabaddr = tROW_COMMAND_MAP0;
			break;


		case _OSD_MAP2:
			ptabaddr = tROW_COMMAND_MAP2;
			break;

		default:
			break;
	}

	if(ucRow > 0)
	{
		while(ucRow-- > 0)
		{
			usaddr += *(ptabaddr + (ucRow * 3) + 2);
		}
	}

	usaddr += ucCol;

	return usaddr;
	
}

#endif

#endif
