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
// ID Code      : RL6229_Series_3D_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Macro of 3D Info Frame Detecting Flag
//--------------------------------------------------
#if(_3D_SUPPORT == _ON)

#if((_OD_SUPPORT == _ON) || (_SDRAM_PHASE_CALIBRATION == _ON))
// Avoid OD data overlap R image before R output in LR display.
// unit: pixel
// if (_SDRAM_PHASE_CALIBRATION == _ON), 8 < (_3_BLOCK_OD_MARGIN * _BIT_PER_PIXEL / _MEMORY_BUS_WIDTH).
#define _3_BLOCK_OD_MARGIN                          16
#endif
                                                    
#define GET_3D_EXT_DATA()                           (g_st3DCtrl.b3ThreeDExtData)
#define SET_3D_EXT_DATA(x)                          (g_st3DCtrl.b3ThreeDExtData = x)
#define CLR_3D_EXT_DATA()                           (g_st3DCtrl.b3ThreeDExtData = _3D_EXT_OL_OR)

#define GET_3D_TX_INPUT_FORMAT()                    (g_st3DCtrl.b4ThreeDInputFormat)
#define SET_3D_TX_INPUT_FORMAT(x)                   (g_st3DCtrl.b4ThreeDInputFormat = x)
#define CLR_3D_TX_INPUT_FORMAT()                    (g_st3DCtrl.b4ThreeDInputFormat = _NO_3D_FORMAT)

#define GET_3D_INPUT_FORMAT()                       (g_stThreeD.b4ThreeDInputFormat)
#define SET_3D_INPUT_FORMAT(x)                      (g_stThreeD.b4ThreeDInputFormat = x)
#define CLR_3D_INPUT_FORMAT()                       (g_stThreeD.b4ThreeDInputFormat = _NO_3D_FORMAT)

#define GET_3D_OUTPUT_SEQUENCE()                    (g_stThreeD.b4ThreeDDisplaySeq)
#define SET_3D_OUTPUT_SEQUENCE(x)                   (g_stThreeD.b4ThreeDDisplaySeq = x)
#define CLR_3D_OUTPUT_SEQUENCE()                    (g_stThreeD.b4ThreeDDisplaySeq = _3D_DISPLAY_LR)

#define GET_3D_SELECT_FORMAT()                      (g_st3DSelect.b2ThreeDSelectFormat)
#define SET_3D_SELECT_FORMAT(x)                     (g_st3DSelect.b2ThreeDSelectFormat = x)
#define CLR_3D_SELECT_FORMAT()                      (g_st3DSelect.b2ThreeDSelectFormat = 0x00)

#define GET_3D_SELCET_DISPLAY()                     (g_st3DSelect.b2ThreeDSelectDisplay)
#define SET_3D_SELCET_DISPLAY(x)                    (g_st3DSelect.b2ThreeDSelectDisplay = x)
#define CLR_3D_SELCET_DISPLAY()                     (g_st3DSelect.b2ThreeDSelectDisplay = 0x00)

#define GET_3D_SELECT_CONVERGENCE()                 (g_st3DSelect.b1ThreeDSelectConvergence)
#define SET_3D_SELECT_CONVERGENCE(x)                (g_st3DSelect.b1ThreeDSelectConvergence = x)
#define CLR_3D_SELECT_CONVERGENCE()                 (g_st3DSelect.b1ThreeDSelectConvergence = 0x00)
  
#define GET_3D_SELECT_CONVERGENCE_MODE()            (g_st3DSelect.b3ThreeDSelectConvergenceMode)
#define SET_3D_SELECT_CONVERGENCE_MODE(x)           (g_st3DSelect.b3ThreeDSelectConvergenceMode = x)
#define CLR_3D_SELECT_CONVERGENCE_MODE()            (g_st3DSelect.b3ThreeDSelectConvergenceMode = _LINEAR_MODE)

#define GET_3D_SHIFT_MODE_EFFECT()                  (g_st3DSelect.ucThreeDSelectEffect)
#define SET_3D_SHIFT_MODE_EFFECT(x)                 (g_st3DSelect.ucThreeDSelectEffect = x)
#define CLR_3D_SHIFT_MODE_EFFECT()                  (g_st3DSelect.ucThreeDSelectEffect = 0x00)

#define GET_3D_DEPTH_GAIN()                         (g_st3DSelect.ucThreeDDepthGain)
#define SET_3D_DEPTH_GAIN(x)                        (g_st3DSelect.ucThreeDDepthGain = (x & 0x3F))

#endif

#if((_3D_SUPPORT == _ON) || (_FRC_SUPPORT == _ON))
#define GET_3D_MISC_DOUBLE_BUFFER()                 ((bit)ScalerGetBit(P20_A0_3D_IVS_DB_CTRL, _BIT7))
#define SET_3D_MISC_DOUBLE_BUFFER()                 (ScalerSetBit(P20_A0_3D_IVS_DB_CTRL, ~_BIT7, _BIT7))
#endif

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum 
{
    _3D_EXT_OL_OR = 0x00,// Odd/Left picture, Odd/Right picture
    _3D_EXT_OL_ER           ,// Odd/Left picture, Even/Right picture
    _3D_EXT_EL_OR         ,// Even/Left picture, Odd/Right picture
    _3D_EXT_EL_ER         ,// Even/Left picture, Even/Right picture

    _3D_EXT_OL_OR_QUIN      ,// Odd/Left picture, Odd/Right picture
    _3D_EXT_OL_ER_QUIN       ,// Odd/Left picture, Even/Right picture
    _3D_EXT_EL_OR_QUIN    ,// Even/Left picture, Odd/Right picture
    _3D_EXT_EL_ER_QUIN    ,// Even/Left picture, Even/Right picture
} Enum3DExtData;

typedef struct
{
    Enum3DExtData b3ThreeDExtData : 3;
    Enum3DinputFormat b4ThreeDInputFormat : 4;
} Struct3DCtrlType;

typedef struct
{
    Enum3DinputFormat b4ThreeDInputFormat : 4;
    Enum3DDisplaySequence b4ThreeDDisplaySeq : 4;
} Struct3DFormat;

typedef struct
{
    Enum3DFormatSelect  b2ThreeDSelectFormat : 2;
    Enum3DDisplaySequence  b2ThreeDSelectDisplay : 2; 
    Enum3DSelectConvergence  b1ThreeDSelectConvergence : 1;
    Enum3DSelectConvergenceMode b3ThreeDSelectConvergenceMode : 3;
    BYTE ucThreeDSelectEffect;
    BYTE ucThreeDDepthGain;
} Struct3DSelect;

#ifndef __RL6229_SERIES_3D__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

#if(_3D_SUPPORT == _ON)

#if(_2D_TO_3D_FUNCTION == _ON)
extern BYTE g_ucIVstart;
extern BYTE g_ucIVSDelay;
extern BYTE g_ucDVstart;
extern SDWORD g_ulLastLineCompen;
#endif

extern Struct3DCtrlType g_st3DCtrl;
extern Struct3DFormat g_stThreeD;
extern Struct3DSelect g_st3DSelect;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

#if(_3D_SUPPORT ==_ON)
extern void Scaler3DDetect(BYTE ucInputSource);
extern void Scaler3DControl(WORD usInputHorSize, WORD usInputVerSize, WORD usOutputHorSize, WORD usOutputVerSize);
extern void Scaler3DSBSHReset(WORD usHWidth);
extern void Scaler3DAdjustWithoutMuteLineBuffer(void);
extern void Scaler3DAdjustWithoutMuteFrameBuffer(void);

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_SHUTTER_GLASSES)
extern void Scaler3DSetDisplayLRFlagEnable(BYTE ucEn);
#endif

#if(_PANEL_DISPLAY_TYPE == _PANEL_DISPLAY_PATTERN_RETARDER)
extern void Scaler3DAdjustIVS2DVSDelayPRType(void);
extern void Scaler3DInputCtrlPRType(WORD usHorSize, WORD usVerSize);
extern void Scaler3DDisplayCtrlPRType(WORD usHorSize, WORD usVerSize);
#endif

#endif // End of #if(_3D_SUPPORT ==_ON)

#endif // End of #ifndef __RL6229_SERIES_3D__
