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
// ID Code      : SysVGA.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_VGA__

#include "SysInclude.h"

#if(_VGA_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _SOY_THRESHOLD_TOL                  0x10
#define _SOY_THRESHOLD                      0x80


//--------------------------------------------------
// Definitions of mode search status
//--------------------------------------------------
#define _VGA_MODE_NOSUPPORT                             254

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE SysVGAScanInputPort(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Scan VGA Port
// Input Value  : None
// Output Value : Source Type
//--------------------------------------------------
BYTE SysVGAScanInputPort(void)
{
    BYTE ucModeNo = 0;

    if(ScalerSyncVgaPreDetect() == _FALSE)
    {
        return _SOURCE_NONE;
    }

    if(ScalerSyncVgaSyncTypeAutoRun() != _NO_SYNC_STATE)
    {
        SET_SOURCE_TYPE(g_ucSearchIndex, _SOURCE_VGA);
        
        // Initial ADC Clock.
        if(ScalerSyncVgaAdcClkInitial() == _FALSE)
        {
            DebugMessageAnalog("Apll initial Fail", 0);
            
            return _SOURCE_NONE;
        }

        CLR_INPUT_TIMING_DOUBLE_CHECK();
        
        // Get Measure Info.
        if(ScalerMeasureInputInfo(GET_SOURCE_TYPE(g_ucSearchIndex)) == _FALSE)
        {
            DebugMessageAnalog("VGA Measure Fail", 0);
            
            return _SOURCE_NONE;
        }
        
        DebugMessageSystem("Input Timing H Polarity", GET_INPUT_TIMING_H_POLARITY());
        DebugMessageSystem("Input Timing V Polarity", GET_INPUT_TIMING_V_POLARITY());
        DebugMessageSystem("Input Timing InterLace", GET_INPUT_TIMING_INTERLACE_FLG());
        DebugMessageSystem("Input Timing HFreq", GET_INPUT_TIMING_HFREQ());
        DebugMessageSystem("Input Timing HTotal", GET_INPUT_TIMING_HTOTAL());
        DebugMessageSystem("Input Timing HStart", GET_INPUT_TIMING_HSTART());
        DebugMessageSystem("Input Timing HWidth", GET_INPUT_TIMING_HWIDTH());
        DebugMessageSystem("Input Timing HSyncWidth", GET_INPUT_TIMING_HSYNCWIDTH());
        DebugMessageSystem("Input Timing VFreq", GET_INPUT_TIMING_VFREQ());
        DebugMessageSystem("Input Timing VTotal", GET_INPUT_TIMING_VTOTAL());
        DebugMessageSystem("Input Timing VStart", GET_INPUT_TIMING_VSTART());
        DebugMessageSystem("Input Timing VHeight", GET_INPUT_TIMING_VHEIGHT());
        DebugMessageSystem("Input Timing VSyncSWidth", GET_INPUT_TIMING_VSYNCWIDTH());

        // Mode No. match
        ucModeNo = UserCommonModeSearchModeVGA();

        DebugMessageAnalog("9. ucModeNo = ", ucModeNo);

        if(ucModeNo == _VGA_MODE_NOSUPPORT)
        {
            SET_INPUT_TIMING_HWIDTH(0); 
            SET_INPUT_TIMING_VHEIGHT(0); 
        }
        else
        {
            // Confirm Clamp Position Setting.
            ScalerSyncVgaSyncProcClampPosCheck(UserCommonModeSearchGetModeVideoType(ucModeNo));

            // Color format setting.
            ScalerADCClampMode(ScalerColorGetColorSpace());

            if(ScalerSyncVgaAdcClkSetting() == _FALSE)
            {
                return _SOURCE_NONE;
            }

            // SOG0 DC Restore Disable
            ScalerADCDCRestoreEn(_OFF);

            // SOG Clamp Enable
            ScalerADCSOGClampEn(_ON);

#if(_VGA_CHROMA_PATTERN12_SUPPORT == _ON)
            // Initial porch voltage check
            ScalerSyncProcSetPorchVoltage();
#endif   

            // Double-check for VS synchronize edge
            ScalerVgipModifyVsLatchEdge(_WAIT);

            // Clear Sync Changed Status flag bit.
            ScalerSyncProcClearSyncChangeStatus();

#if(_YPBPR_SUPPORT == _ON)
            if(ScalerColorGetColorSpace() == _COLOR_SPACE_YPBPR)
            {
                ScalerColorSetColorimetry(UserInterfaceCheckHDTVMode(ucModeNo));
            }
#endif // End of #if (_YPBPR_SUPPORT == _ON)
        }
        
        // Set Timing Confirm Flag.
        SET_MODE_TIMING_CONFIRM();
        SET_INPUT_TIMING_DOUBLE_CHECK();

        return _SOURCE_VGA;
    }

    // Check sync is invalid 
    return _SOURCE_NONE;
}

#endif // End of #if(_VGA_SUPPORT == _ON)
