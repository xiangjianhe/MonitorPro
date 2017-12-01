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
// ID Code      : RL6229_Series_Scaling_Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

typedef enum
{
    _MASK_TYPE_ONE_SECTION_ONE_SET = 0,
    _MASK_TYPE_TWO_SECTION_KEEP_ODD_TWO_SET, // 001
    _MASK_TYPE_TWO_SECTION_KEEP_EVEN_TWO_SET, // 010 
    _MASK_TYPE_THREE_SECTION_EVERYFRAME_THREE_SET, // 011
    _MASK_TYPE_TWO_DIFF_SECTION_ALTFRAME_FOUR_SET, // 100
    _MASK_TYPE_TWO_DIFF_SECTION_ALTFRAME_TWO_SET, // 101
    _MASK_TYPE_SBS_ALTFRAME, // 110
    _MASK_TYPE_LINE_INTERLEAVE_ALTFRAME, // 111
} EnumMaskTypeDef;

typedef enum
{
    _MASK_ACTIVE_SPACE_0 = 0,
    _MASK_ACTIVE_SPACE_1,
    _MASK_ACTIVE_SPACE_2,
    _MASK_ACTIVE_SPACE_3,
} EnumMaskActiveSpaceNum;

#ifndef __RL6229_SERIES_SCALING__
//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern BYTE g_ucVFCI;


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************

extern void ScalerScalingSetDoubleBufferRegister(void);
extern void ScalerScalingSetScalingDown(StructSDRAMDataInfo stFIFOScaling);
extern void ScalerScalingSetScalingUp(StructSDRAMDataInfo stFIFOScaling);
extern void ScalerScalingGetFIFOScalingSize(StructSDRAMDataInfo* pstData);

#if(_3D_SUPPORT == _ON)
extern EnumVSUCoefType ScalerScalingGetScalingUpType(void);
#endif

#endif // End of #ifndef __RL6229_SERIES_SCALING__
