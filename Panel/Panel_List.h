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
// ID Code      : Panel_List.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//--------------------------------------------------
// Panel Type List
//--------------------------------------------------
#define _CMO_LVDS_17                            0       // 1280 x 1024
#define _CMO_LVDS_19_WXGA                       1       // 1440 x  900
#define _AU_LVDS_21_5_WUXGA                     2       // 1920 x 1080
#define _LG_PR_LVDS_21_5_WUXGA                  3       // 1920 x 1080
#define _MULTIPANEL_LVDS_21_5_WUXGA             4       // 1920 x 1080
#define _AU_LVDS_22_WSXGA                       5       // 1680 x 1050
#define _AU_LVDS_22_WSXGA_QC                    6       // 1680 x 1050
#define _AU_LVDS_23_WUXGA                       7       // 1920 x 1200
#define _AU_LVDS_24_WUXGA                       8       // 1920 x 1080
#define _AUO_LED_LVDS_24_WUXGA                  9       // 1920 x 1080
#define _QISDA_LED_LVDS_24_WUXGA                10      // 1920 x 1080
#define _SAMSUNG_LED_LVDS_24_WUXGA              11      // 1920 x 1080
#define _AUO_LED_LVDS_18_5_WUXGA                12      // 1366 x 768
#define _BOE_LED_LVDS_23_WUXGA                  13      // 1920 x 1080
#define _AU_LVDS_21_5_WUXGA_FREESYNC            14      // 1920 x 1080 freesync

//TPV Lenovo Project Panel
#define _TPV_CMO_M215HGE                        100     // 1920 x 1080
#define _TPV_LG_LM190E09                        101     // 1280 x 1024
#define _TPV_SEC_LTM190BT07                     102     // 1440 x 900
#define _TPV_CMI_M220ZGE                        103     // 1680 x 1050
#define _TPV_SEC_LTM220MT09                     104     // 1680 x 1050
#define _TPV_CMI_M190CGE_20                     105     // 1440 x 1050
#define _TPV_LG_LM190E0A                        106     // 1280 x 1024
#define _TPV_CMI_M195FGE_L20                    107     // 1600 x 900
#define _TPV_LG_LM200WD3_TLF1                   108     // 1600 x 900
#define _TPV_LG_LM230WF5_TLF1                   109     // 1920 x 1080
#define _TPV_LG_LM230WF5_TLH1                   110     // 1920 x 1080
#define _TPV_LT_LM215WF3_S2DB                   111     // 1920 x 1080
#define _TPV_AUO_M195RTN01_0                    112     // 1600 x 900
#define _TPV_JV_LM230WF3_S2G2_AD_WUXGA          113     // 1920 x 1080
#define _TPV_LG_LM230WF3_SLQ1					114		//1920 x 1080
#define _TPV_LG_LM230WF3_SLN1					115     //1920 x 1080
#define _TPV_SAMSUNG_LTM230HL08					116		//1920 x 1080
#define _TPV_BOE_HR230WU1_400					117		//1920 x 1080
#define _TPV_AUO_M170ETN01						118		// 1280 x 1024
#define _TPV_SEC_LTM220MT12                     119     // 1680 x 1050
#define _TPV_TPV_TPM190A1_MWW4					120		//1440 x 900
#define _TPV_LG_LM195WD1_TLA1					121		//1600 x 900
#define _TPV_SAMSUNG_LTM215HP01					122		//1920 x 1080
#define _TPV_INL_M215HNE_L30					123		//1920 x 1080
#define _TPV_LNT_LM195WX1_S2A1                  124     // 1440 x 900
#define _TPV_INL_M195FGE_L20                    125     // 1600 x 900
#define _TPV_AUO_TPM190WP2_PTN01				126		//1440 x 900
#define _TPV_LG_LM230WF9_SSA1					127     //1920 x 1080
#define _TPV_LG_LM230WF7_SSB1					128     //1920 x 1080      2015/12/16
#define _TPV_LGD_LM215WF4_TLG1					129     //1920 x 1080      2015/01/04
#define _TPV_BOE_HT215F01_100					130     //1920 x 1080      2015/01/04
#define _TPV_LNT_LM195WX1_S1C1                  131     // 1440 x 900   Ada.chen 20160204
#define _TPV_BOE_MV195WGM_N10                   132     // 1440 x 900   Ada.chen 20160219
#define _TPV_AUO_M215HTN01_DOT_1			    133		//1920 x 1080  hillybw 20160510
#define _TPV_CMI_M215HGE_L21					134		//1920 x 1080  hillybw 20160510
#define _TPV_BOE_MV190E0M_N10					135		//1280 x 1024  Ada.chen  20160602
#define _TPV_LG_LM190E0A_SLD1					136		//1280 x 1024  Ada.chen  20160602
#define _TPV_BOE_MV230FHM_N20					137		//1920 x 1080  Ada.chen  20170331


//Foxconn Lenovo Project Panel
#define _FOX_AUO_M185XTN01_3                    500     // 1366 x 768  for LT1931EW  E1922S
#define _FOX_LG_LM215WF4_TLG1                   501     // 1920 x 1080 for LI2241W
#define _FOX_CMI_M215HGE_L21                    502     // 1920 x 1080 for LI2241W
#define _FOX_AUO_M215HTN01_1                    503     // 1920 x 1080 for LI2241W
#define _FOX_CMI_M195FGE_L20					504		// 1600 X 900 for E2013W,    for TE20-11,TE20-14,V20-10
#define _FOX_CMI_M200FGE_L23					505		// 1600 X 900 for LI2041
#define _FOX_AUO_M170ETN01_1                    506     // 1280 x 1024 for LT1713
#define _FOX_BOE_HM185WX1_400					507		// 1366 X 768 for E1922S
#define _FOX_CMI_M185BGE_L23					508		// 1366 X 768 for E1922S
#define _FOX_LG_LM185WH2						509		// 1366 X 768 for E1922S
#define _FOX_AUO_M185XTN01_2					510		// 1366 X 768 for E1922W
#define _FOX_CMI_M185BGE_L22					511		// 1366 X 768 for E1922W
#define _FOX_SEC_LTM185AT05						512		// 1366 X 768 for E1922W
#define _FOX_SEC_LTM200KT13						513		// 1600 X 900 for LI2041
#define _FOX_DSBJ_FQ21M31						514		// 1920 X 1080 for LI2241W
#define _FOX_BOE_HT215F01_100					515		// 1920 X 1080 for LS2233
#define _FOX_SEC_LTM215HT05					    516		// 1920 X 1080 for LI2241W
#define _FOX_PAN_LM215DT1A						517		// 1920 X 1080 for LS2233
#define _FOX_DSBJ_FQ21M31_D						518		// 1920 X 1080 for LS2233
#define _FOX_CMI_M200HJJ						519		// 1920 X 1080 for E2024
#define _FOX_LG_LM215WF3_SLN1                   520     // 1920 x 1080 for T2224zwD & T2224pwD
#define _FOX_SEC_LTM215HL01						521     // 1920 x 1080 for T2224zwD & T2224pwD
#define _FOX_BOE_HR215WU1_120					522     // 1920 x 1080 for T2224zwD & T2224pwD
#define _FOX_BOE_MT185WHM_N10					523		// 1366 X 768 for E1922S
#define _FOX_BOE_MT185WHM_N20				    524		// 1366 X 768 for E1922W
#define _FOX_SEC_LTM185AT07						525		// 1366 X 768 for E1922S
#define _FOX_DSBJ_FQ18M31A                      526		// 1366 X 768 for E1922S
#define _FOX_SEC_LTM200KL01						527     // 1600 x 900 for LS2033wD
#define _FOX_DSBJ_FQ18M31A_N                    528		// 1366 X 768 for E1922S
#define _FOX_CMI_M215HGE_L23                    529		// 1920 X 1080 for E2215D
#define _FOX_AUO_M195RTN01_0                    530		// 1600 X 900 for TE20-11,TE20-14,V20-10


//Wistorn Lenovo Project Panel
#define _M240HTN01_LVDS_24_WUXGA              	800      // 1920 x 1080
#define _CMI_M215HGE_LVDS_21_5_WUXGA            801      // 1920 x 1080
#define _AUO_M170ETN01_1                        802      // 1280 x 1024
#define _CMI_M236HGE_LVDS_23_5_WUXGA            803      // 1920 x 1080
#define _BOE_HM236WU1_300                       804      // 1920 x 1080
#define _MULTIPANEL_22_WUXGA                    805

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_AUO                              0
#define _PANEL_CMO                              1
#define _PANEL_CPT                              2
#define _PANEL_HSD                              3
#define _PANEL_SAMSUNG                          4
#define _PANEL_LGD                              5
#define _PANEL_SVA                              6
#define _PANEL_BOE                              7
#define _PANEL_INNOLUX                          8
#define _PANEL_QISDA                            9
#define _PANEL_DSBJ                             10
#define _PANEL_PANDA                            11

//--------------------------------------------------
// Definitions for Panel Settings
//--------------------------------------------------
#define _PANEL_TTL                              0
#define _PANEL_LVDS                             1
#define _PANEL_RSDS                             2

//--------------------------------------------------
// Definitions for LVDS Bit Length
//--------------------------------------------------
#define _DISP_24_BIT                            0
#define _DISP_18_BIT                            1
#define _DISP_30_BIT                            2

//--------------------------------------------------
// Definitions for LVDS Port Counts
//--------------------------------------------------
#define _DISP_SINGLE_PORT                       0
#define _DISP_DOUBLE_PORT                       1

//--------------------------------------------------
// Definitions for LVDS Bit Map Table
//--------------------------------------------------
#define _LVDS_BIT_MAP_TABLE_1                   0
#define _LVDS_BIT_MAP_TABLE_2                   1

//--------------------------------------------------
// Definitions for 2D / 3D panel type
//--------------------------------------------------
#define _PANEL_DISPLAY_NORMAL                   0
#define _PANEL_DISPLAY_SHUTTER_GLASSES          1
#define _PANEL_DISPLAY_PATTERN_RETARDER         2

//--------------------------------------------------
// Definitions for PR Panel Display Type
//--------------------------------------------------
#define _PANEL_PR_LR_DISPLAY                    0
#define _PANEL_PR_RL_DISPLAY                    1

//--------------------------------------------------
// Definitions for Panel Backlight
//--------------------------------------------------
#define _PANEL_BACKLIGHT_CCFL                   0
#define _PANEL_BACKLIGHT_LED                    1

//--------------------------------------------------
// Panel Normally status
//--------------------------------------------------
#define _PANEL_NORMALLY_WHITE                  0
#define _PANEL_NORMALLY_BLACK                  1
#define _PANEL_NORMALLY_UNCONFIRMED            2
