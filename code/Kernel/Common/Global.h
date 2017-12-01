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
// ID Code      : Global.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "reg52.h"
#include "intrins.h"
#include "string.h"
#include "math.h"

//****************************************************************************
// Data Type Redefine
//****************************************************************************
typedef unsigned char BYTE;
typedef char          SBYTE;
typedef unsigned int  WORD;
typedef int           SWORD;
typedef unsigned long DWORD;
typedef long          SDWORD;


//****************************************************************************
// Extern pData for All Layer Temporary Use
//****************************************************************************
extern BYTE data pData[16];
extern bit g_bA0CableDetect;
extern bit g_bD0CableDetect;
extern bit g_bD1CableDetect;
extern bit g_bD2CableDetect;
extern bit g_bD3CableDetect;
extern bit g_bD1DpDualPortStatus;
extern bit g_bD0MHLCableDetect;
extern bit g_bD1MHLCableDetect;

//****************************************************************************
// Structures
//****************************************************************************
// Struct for all Timing Info
typedef struct
{
    BYTE b1HSP : 1;             // HSP
    BYTE b1VSP : 1;             // VSP
    BYTE b1Interlace : 1;       // Interlace
    WORD usHFreq;               // Horizontal Freq. (unit: 0.1kHz)
    WORD usHTotal;              // Horizontal Total length (unit: Pixel)
    WORD usHWidth;              // Horizontal Active Width (unit: Pixel)
    WORD usHStart;              // Horizontal Start (unit: Pixel)
    WORD usHSWidth;             // Horizontal Sync Pulse Count (unit: SyncProc Clock)

    WORD usVFreq;               // Vertical Freq. (unit: 0.1Hz)
    WORD usVTotal;              // Vertical Total length (unit: HSync)
    WORD usVHeight;             // Vertical Active Height (unit: HSync)
    WORD usVStart;              // Vertical Start (unit: HSync)
    WORD usVSWidth;             // Vertical Sync Width    (unit: HSync)
}StructTimingInfo;

typedef struct
{        
    BYTE b1HSP : 1;
    BYTE b1VSP : 1;    
    WORD usHSPeriod;
    WORD usHSWidth;    
    WORD usVSPeriod;
    WORD usVSWidth;
    
}StructMeasureSyncData;

typedef struct
{            
    WORD usVActiveStart;
    WORD usVActiveEnd;        
    WORD usHActiveStart;
    WORD usHActiveEnd;    
}StructAutoActiveData;

// Struct for Display Timing Info
typedef struct
{
    WORD usHTotal;                // Horizontal Total length (unit: Pixel)
    WORD usHWidth;                // Horizontal Active Width (unit: Pixel)
    WORD usHBackWidth;            // Horizontal Back Ground Active Width (unit: Pixel)
    WORD usHStart;                // Horizontal Start Position    

    WORD usVTotal;                // Vertical Total length (unit: HSync)
    WORD usVHeight;               // Vertical Active Height (unit: HSync)
    WORD usVBackHeight;           // Vertical Back Ground Active Height (unit: HSync)
    WORD usVStart;                // Vertical Start Position
}StructDisplayInfo;

typedef struct
{
    BYTE ucAdcPGA;
    BYTE ucAdcGainMSB[3];
    BYTE ucAdcGainLSB[3];
    BYTE ucAdcOffsetMSB[3];
    BYTE ucAdcOffsetLSB[3];
} StructAdcDataType;

typedef struct
{
    BYTE b1EventValid : 1;
    BYTE b7EventID : 7;
    WORD usTime;
} StructTimerEventTableType;

typedef struct
{		
	WORD usInputHWidth;
    WORD usInputVHeight;
    WORD usOutputHWidth;
	WORD usOutputVHeight;
} StructSDRAMDataInfo;

//--------------------------------------------------
// Definitions of SDRAM Calibration Status
//--------------------------------------------------
typedef struct                                                  
{                                                                            
    BYTE b1FirstAutoKStatus : 1;                
    BYTE b1CasChangeStatus : 1;                    
    BYTE b1DCOnOnLineStatus : 1;
}StructSDRAMCalControl;

//****************************************************************************
// General Definitions
//****************************************************************************
//--------------------------------------------------
// Definitions of Physical Boolean
//--------------------------------------------------
#define _TRUE                                   1
#define _FALSE                                  0
#define _HIGH                                   1
#define _LOW                                    0
#define _ENABLE                                 1
#define _DISABLE                                0
#define _READ                                   1
#define _WRITE                                  0
#define _ON                                     1
#define _OFF                                    0
#define _SUCCESS                                1
#define _FAIL                                   0
#define _STABLE                                 1
#define _UNSTABLE                               0
#define _POSITIVE                               1
#define _NEGATIVE                               0
#define _NEWMODE                                1
#define _OLDMODE                                0
#define _ODD                                    1
#define _EVEN                                   0
#define _WAIT                                   1
#define _NOT_WAIT                               0
#define _RIGHT                                  1
#define _LEFT                                   0
#define _EDID_SWITCH_MODE                       1
#define _MCCS_SWITCH_MODE                       0

//--------------------------------------------------
// Definitions of Page
//--------------------------------------------------
#define _PAGE0                                  0
#define _PAGE1                                  1
#define _PAGE2                                  2
#define _PAGE3                                  3
#define _PAGE4                                  4
#define _PAGE5                                  5
#define _PAGE6                                  6
#define _PAGE7                                  7
#define _PAGE8                                  8
#define _PAGE9                                  9
#define _PAGEA                                  10
#define _PAGEB                                  11
#define _PAGEC                                  12
#define _PAGED                                  13
#define _PAGEE                                  14
#define _PAGEF                                  15
#define _PAGE10                                 16

#define _PAGE_COMMON                            255

//--------------------------------------------------
// Definitions of Bits
//--------------------------------------------------
#define _BIT0                                   0x0001
#define _BIT1                                   0x0002
#define _BIT2                                   0x0004
#define _BIT3                                   0x0008
#define _BIT4                                   0x0010
#define _BIT5                                   0x0020
#define _BIT6                                   0x0040
#define _BIT7                                   0x0080
#define _BIT8                                   0x0100
#define _BIT9                                   0x0200
#define _BIT10                                  0x0400
#define _BIT11                                  0x0800
#define _BIT12                                  0x1000
#define _BIT13                                  0x2000
#define _BIT14                                  0x4000
#define _BIT15                                  0x8000
#define _BIT16                                  0x10000   

//--------------------------------------------------
// Definitions of Clock Divider Number
//--------------------------------------------------
#define _DIV_1                                  1
#define _DIV_2                                  2
#define _DIV_3                                  3
#define _DIV_4                                  4
#define _DIV_5                                  5
#define _DIV_6                                  6
#define _DIV_7                                  7
#define _DIV_8                                  8
#define _DIV_9                                  9
#define _DIV_10                                 10

//--------------------------------------------------
// Definations of Scaler Write/Read Type
//--------------------------------------------------
#define _NON_AUTOINC                            1
#define _AUTOINC                                0
#define _BURST                                  2
#define _END                                    0

//--------------------------------------------------
// Definitions of Null Pointer
//--------------------------------------------------
#define _NULL_POINTER                           (BYTE *)0xFFFF

//****************************************************************************
// Definitions of Audio
//****************************************************************************
//--------------------------------------------------
// Define for Audio Source Type
//--------------------------------------------------
#define _ANALOG_AUDIO                           0
#define _DIGITAL_AUDIO                          1

//--------------------------------------------------
// Definitions of Audio Volume Resolution
//--------------------------------------------------
#define	_AUDIO_VOLUME_8BIT	                    0
#define	_AUDIO_VOLUME_14BIT	                    1    // DVC  Support Only

//--------------------------------------------------
// Definitions of Analog Audio Input Type
//--------------------------------------------------
#define	_AUDIO_FROM_AIN	                        0
#define	_AUDIO_FROM_DAC	                        1

//****************************************************************************
// Definitions of Auto
//****************************************************************************
//--------------------------------------------------
// Definitions of Auto Function Channel
//--------------------------------------------------
#define _AUTO_RED_CHANNEL                       0
#define _AUTO_GREEN_CHANNEL                     1
#define _AUTO_BLUE_CHANNEL                      2
#define _AUTO_RGB_CHANNEL                       3


//****************************************************************************
// Definitions of CBUS
//****************************************************************************
#define _CBUS0                                  0
#define _CBUS1                                  1
#define _NO_CBUS                                2

//****************************************************************************
// Definitions of Digital Functions
//****************************************************************************
//--------------------------------------------------
// Definitions of Highlight Window Option
//--------------------------------------------------
#define _HLW_BORDER_BOTTOM                      _BIT4
#define _HLW_BORDER_TOP                         _BIT5
#define _HLW_BORDER_RIGHT                       _BIT6
#define _HLW_BORDER_LEFT                        _BIT7

//--------------------------------------------------
// Definitions of ICM Adjust Option
//--------------------------------------------------
#define _CM0_ENABLE                             _BIT0
#define _CM1_ENABLE                             _BIT1
#define _CM2_ENABLE                             _BIT2
#define _CM3_ENABLE                             _BIT3
#define _CM4_ENABLE                             _BIT4
#define _CM5_ENABLE                             _BIT5
#define _Y_CORRECTION_MODE                      _BIT6
#define _UV_DELTA_RANGE                         _BIT7
#define _UV_DELTA_RANGE_EXTEND                  _BIT8

//****************************************************************************
// Definitions of EMCU
//****************************************************************************
//--------------------------------------------------
// Definations of DDC Channel
//--------------------------------------------------
#define _DDC1                                   0
#define _DDC2                                   1
#define _DDC3                                   2
#define _DPDDC2_TMDSDDC3                        3
#define _DPDDC3_TMDSDDC2                        4
#define _NO_DDC                                 5

//--------------------------------------------------
// Define for HW burst write
//--------------------------------------------------
#define _BURSTWRITE_FROM_FLASH                  0
#define _BURSTWRITE_FROM_XRAM                   1

#define _BURSTWRITE_COMMAND                     0
#define _BURSTWRITE_DATA_COMMON                 1
#define _BURSTWRITE_DATA_OSD                    2

//--------------------------------------------------
// Reserved for pin define
//--------------------------------------------------
#define MCU_EMPTY_PIN_ASSIGN_ADDRESS            0


//****************************************************************************
// Definitions of IOSC
//****************************************************************************
//--------------------------------------------------
// Definitions of IOSC Clock Divider Number
//--------------------------------------------------
#define _IOSC_DIV_1                             0
#define _IOSC_DIV_2                             1
#define _IOSC_DIV_4                             2
#define _IOSC_DIV_8                             3

#define _IOSC_DIV                               _IOSC_DIV_1                  

//--------------------------------------------------
// Definitions of IOSC Frequency
//--------------------------------------------------
#define _IOSC27000K                            27000                        
#define _IOSC14318K                            14318                        


//****************************************************************************
// Definitions of Memory
//****************************************************************************
//--------------------------------------------------
// Definitions for Memory
//--------------------------------------------------
#define _FRAME_SYNC_LINE_BUFFER                 0
#define _FRAME_SYNC_SDRAM                       1
#define _FREE_RUN_SDRAM                         2
#define _MN_FRAME_SYNC_SDRAM                    3
#define _FREE_RUN_NO_INPUT                      4

//--------------------------------------------------
// Definitions of DVF type
//--------------------------------------------------
#define _1_IVF                                 0
#define _2_IVF                                 1
#define _3_IVF                                 2
#define _60HZ_DISPLAY                          3
#define _2_5_IVF                               4

//****************************************************************************
// Definitions of MHL Packets
//****************************************************************************
#define _MHL_SUCCESS                            0
#define _MHL_FAIL                               1
#define _MHL_ABORT_FAIL                         2
#define _MHL_ABORT_REPLY                        3

//****************************************************************************
// Definitions of Mode Search
//****************************************************************************
#define _USER_MODE_TYPE                         0
#define _PRESET_MODE_TYPE                       1


//****************************************************************************
// Definitions of OSD
//****************************************************************************
#define _OSD_WF_CONTROL                         0
#define _OSD_SRAM                               _BIT4
#define _OSD_WITHOUT_DB                         0
#define _OSD_WITH_DB                            _BIT5

typedef enum
{
    _OSD_BYTE0   = 0,
    _OSD_BYTE1   = _BIT6,
    _OSD_BYTE2   = _BIT7,
    _OSD_BYTEALL = (_BIT7|_BIT6),
} EnumOsdWriteType;


//****************************************************************************
// Definitions of Panel
//****************************************************************************
//--------------------------------------------------
// Definitions of Panel Power Status
//--------------------------------------------------
#define _PANEL_POWER_OFF_STATE                  0
#define _WAITING_FOR_BACKLIGHT                  1
#define _READY_FOR_BACKLIGHT                    2
#define _BACKLIGHT_ON_ALREADY                   3
#define _PANEL_BACKLIGHT_OFF                    4


//--------------------------------------------------
// Definitions of Panel Power Action
//--------------------------------------------------
#define _PANEL_ON                               0
#define _PANEL_OFF                              1
#define _BACKLIGHT_ON                           2
#define _BACKLIGHT_OFF                          3


//****************************************************************************
// Definitions of Sync
//****************************************************************************
//--------------------------------------------------
// Definitions of Input Sync Type State
//--------------------------------------------------
#define _NO_SYNC_STATE                          0
#define _SS_STATE                               1
#define _CS_STATE                               2
#define _SOG_STATE                              3
#define _SOY_STATE                              4
#define _DSS_STATE                              5
#define _NOT_SUPPORT_STATE                      0


//****************************************************************************
// Definitions of Source
//****************************************************************************
//--------------------------------------------------
// Definitions of Source Switch Type
//--------------------------------------------------
#define _SOURCE_SWITCH_FIXED_PORT               0
#define _SOURCE_SWITCH_AUTO_IN_GROUP            1
#define _SOURCE_SWITCH_AUTO_WITHOUT_GROUP       2
#define _SOURCE_SWITCH_HP_SOURCE_SCAN           3
#define _SOURCE_SWITCH_HP_TIMING_CHANGE         4
#define _SOURCE_SWITCH_HP_SOURCE_SWITCH         5
#define _SOURCE_SWITCH_HP_OOR_SOURCE_SCAN       6
#define _SOURCE_SWITCH_ASUS_AUTO                7
#define _SOURCE_SWITCH_DELL_HOTKEY_AUTO         8
#define _SOURCE_SWITCH_DELL_HOTKEY_FIXED        9

//--------------------------------------------------
// Definitions of Source Search Delay Mode
//--------------------------------------------------
#define _SOURCE_SEARCH_POLLING_MODE             0
#define _SOURCE_SEARCH_DELAY_DEFAULT_MODE       1
#define _SOURCE_SEARCH_DELAY_REACTIVE_MODE      2
#define _SOURCE_SEARCH_DELAY_NVRAM_PORT_MODE    3

//****************************************************************************
// Definitions of 3D
//****************************************************************************
//--------------------------------------------------
// Definitions of Chroma Weight for Depth Calculation
//--------------------------------------------------
#define _LUMINANCE                              0
#define _CHROMINANCE_1                          1
#define _CHROMINANCE_1_2                        2
#define _CHROMINANCE_1_4                        3

//--------------------------------------------------
// Definitions of LPF Weight Option
//--------------------------------------------------
#define _LPF_BLUR_STRONG                        0
#define _LPF_BLUR_MEDIUM                        1
#define _LPF_BLUR_WEAK                          2

//--------------------------------------------------
// Definitions of Hole Filling Mode
//--------------------------------------------------
#define _INTEGER_LEFT                           0
#define _INTEGER_INTERPOLATE                    1
#define _FRACTION_LEFT                          2
#define _FRACTION_INTERPOLATE                   3

//--------------------------------------------------
// Definitions of SLP Wake Up Event
//--------------------------------------------------
#define _SLP_NO_EVENT                           0
#define _SLP_POWER_KEY_EVENT                    1
#define _SLP_SARADC_KEY_EVENT                   2
#define _SLP_POWER_KEY_EDGE_EVENT               3
#define _SLP_CABLE_DETECT_HIGH_EVENT            4
#define _SLP_CABLE_DETECT_LOW_EVENT             5
#define _SLP_HS_EVENT                           6
#define _SLP_SOG_ENENT                          7

//****************************************************************************
// Global Macros
//****************************************************************************
#define LOBYTE(w)                               ((BYTE)(w))
#define HIBYTE(w)                               ((BYTE)(((WORD)(w) >> 8) & 0x00FF))
#define SEC(x)                                  (1000 * (x))

#define MAXOF(a, b)                             (((a) > (b)) ? (a) : (b))
#define MINOF(a, b)                             (((a) < (b)) ? (a) : (b))

#define SHL(x, y)                               ((x) << (y))
#define SHR(x, y)                               ((x) >> (y))
#define AND(n1, n2)                             ((n1) & (n2))

#define ABSDWORD(x, y)                          (((x) > (y)) ? ((x) - (y)) : ((y) - (x)))

#define GET_CURRENT_BANK_NUMBER()               (MCU_BANK_SWITCH_FFFF)

//--------------------------------------------------
// Macro of WORD/DWORD pData
//--------------------------------------------------
#define PDATA_WORD(x)                           (((WORD*)pData)[x])
#define PDATA_DWORD(x)                          (((DWORD*)pData)[x])

//--------------------------------------------------
// Macro of Cable Detect Flag
//--------------------------------------------------
#define GET_A0_CABLE_STATUS()                   (g_bA0CableDetect)
#define SET_A0_CABLE_STATUS(x)                  (g_bA0CableDetect = x)

#define GET_D0_CABLE_STATUS()                   (g_bD0CableDetect)
#define SET_D0_CABLE_STATUS(x)                  (g_bD0CableDetect = x)

#define GET_D1_CABLE_STATUS()                   (g_bD1CableDetect)
#define SET_D1_CABLE_STATUS(x)                  (g_bD1CableDetect = x)

#define GET_D2_CABLE_STATUS()                   (g_bD2CableDetect)
#define SET_D2_CABLE_STATUS(x)                  (g_bD2CableDetect = x)

#define GET_D3_CABLE_STATUS()                   (g_bD3CableDetect)
#define SET_D3_CABLE_STATUS(x)                  (g_bD3CableDetect = x)

#define GET_D1_DP_DUAL_STATUS()                 (g_bD1DpDualPortStatus)
#define SET_D1_DP_DUAL_STATUS(x)                (g_bD1DpDualPortStatus = x)

#define GET_D0_TMDS_MODE()                      (g_bD0MHLCableDetect)
#define SET_D0_TMDS_MODE(x)                     (g_bD0MHLCableDetect = x)

#define GET_D1_TMDS_MODE()                      (g_bD1MHLCableDetect)
#define SET_D1_TMDS_MODE(x)                     (g_bD1MHLCableDetect = x)

//****************************************************************************
// General Enumerations
//****************************************************************************
//--------------------------------------------------
// Enumerations of DDCCI or Debug Mode
//--------------------------------------------------
typedef enum
{
    _DEBUG_MODE,
    _DDCCI_MODE,
} EnumDDCCIDebugMode;

//--------------------------------------------------
// Enumerations IRQ Type
//--------------------------------------------------
typedef enum 
{
    _IRQ_IVS = 0x00,
    _IRQ_DVS,
    _IRQ_DEN,
    _IRQ_IHS_TIMEOUT,
} EnumIRQ;

//--------------------------------------------------
// Enumerations of LED indication
//--------------------------------------------------
typedef enum
{
    _LED_POWER_ON = 0x00,          
    _LED_POWER_SEARCH,         
    _LED_POWER_ACTIVE,            
    _LED_POWER_SAVING,           
    _LED_POWER_NOSUPPORT,           
    _LED_POWER_NOSUPPORT_SAVING,			
    _LED_POWER_OFF, 			 
    _LED_TYPE_1,         
    _LED_TYPE_2,            
    _LED_TYPE_3,           
    _LED_TYPE_4,           
    _LED_TYPE_5, 			 
    _LED_TYPE_FLASH,	
    _LED_SYSTEM_END,
} EnumLedIndication;

//--------------------------------------------------
// Enumerations of System Clock
//--------------------------------------------------
typedef enum
{
    _EXT_XTAL_CLK,
    _IOSC_CLK,
    _M2PLL_CLK,
} EnumClkSel;

//--------------------------------------------------
// Enumerations of System Data Info
//--------------------------------------------------
typedef enum
{
    _MONITOR_POWER_STATUS,          
    _SEARCH_PORT,                   
    _SOURCE_SCAN_TYPE,              
    _MODE_SLOT_INDEX,               
    _SSC,                           
    _DP_HOT_PLUG_DC_OFF_HIGH,       
    _HDMI_HOT_PLUG_SUPPORT,         
    _HDMI_HOT_PLUG_SUPPORT_TIME,   
    _SOURCE_HP_DEFAULT_PORT,
    _SOURCE_HP_AUTO_SEARCH,    
    _SLP_AC_OFF_DETECT,
} EnumSystemDataItemDataType;

//--------------------------------------------------
// Enumerations of Waiting Events (CR_03)
//--------------------------------------------------
typedef enum
{
    _EVENT_IVS = _BIT0,
    _EVENT_IEN_START = _BIT1,
    _EVENT_IEN_STOP = _BIT2,
    _EVENT_DVS = _BIT3,
    _EVENT_DEN_START = _BIT4,
    _EVENT_DEN_STOP = _BIT5,
    _EVENT_UNDERFLOW = _BIT6,
    _EVENT_OVERFLOW = _BIT7,
    _EVENT_ALL = 0xFF,
} EnumWaitEventType;


//****************************************************************************
// Enumerations of Auto Color
//****************************************************************************
//--------------------------------------------------
// Enumerations of ADC Gain/Offset
//--------------------------------------------------
typedef enum
{
    _ADC_GAIN = 0x00,
    _ADC_OFFSET,
} EnumADCGainOffset;

//--------------------------------------------------
// Enumerations of S/H Gain Operation Mode
//--------------------------------------------------
typedef enum
{
    _SHA_GAIN_CHECK_MODE = 0x00,
    _SHA_GAIN_WRITE_MODE,
} EnumShaGainOptions;

//--------------------------------------------------
// Enumerations of auto-color types
//--------------------------------------------------
typedef enum
{
    _AUTO_TUNE_RGB,
    _AUTO_TUNE_YPBPR,
    _AUTO_CALIBRATE_RGB,
    _AUTO_TUNE_RGB_GAIN_ONLY,    
    _AUTO_TUNE_YPBPR_GAIN_ONLY,
    _AUTP_TUNE_CUSTOM,
} EnumAutoColorType;


//****************************************************************************
// Enumerations of Auto Phase
//****************************************************************************
//--------------------------------------------------
// Enumerations of Hardware Phase Search SOD Method
//--------------------------------------------------
typedef enum
{
    _PHASE_SEARCH_SOD = 0x00,
    _PHASE_SEARCH_WSOD = 0x01,
} EnumAutoPhaseSearchSODMethod; 

//--------------------------------------------------
// Enumerations of Hardware Phase Search Step
//--------------------------------------------------
typedef enum
{
    _PHASE_SEARCH_STEP_1 = 0x00,
    _PHASE_SEARCH_STEP_2 = 0x01,
    _PHASE_SEARCH_STEP_4 = 0x02,
    _PHASE_SEARCH_STEP_8 = 0x03,
    _PHASE_SEARCH_STEP_16 = 0x04,
} EnumAutoPhaseSearchStep; 

//--------------------------------------------------
// Enumerations of image auto-function measure result status
//--------------------------------------------------
typedef enum
{
    _AUTO_FAIL = _FAIL,
    _AUTO_SUCCESS = _SUCCESS,
    _AUTO_ABORT,
} EnumAutoResult;


//****************************************************************************
// Enumerations of Digital Functions
//****************************************************************************
//--------------------------------------------------
// Enumerations of Brightness/Contrast Coefficient Sets
//--------------------------------------------------
typedef enum
{
    _BRIGHTNESS_COEF_A, 
    _BRIGHTNESS_COEF_B,
    _CONTRAST_COEF_A,                    
    _CONTRAST_COEF_B,                       
    _CONTRAST_COEF_A_2,                      
    _CONTRAST_COEF_B_2,                    
} EnumBriConCoefType;

//--------------------------------------------------
// Enumerations of Color Space
//--------------------------------------------------
typedef enum
{
    _COLOR_SPACE_RGB,
    _COLOR_SPACE_YCBCR422,
    _COLOR_SPACE_YCBCR444,
    _COLOR_SPACE_YPBPR,
} EnumColorSpace;

//--------------------------------------------------
// Enumerations of DCR Adjust Option
//--------------------------------------------------
typedef enum
{
    _DCR_ABOVE_TH1_NUM,
    _DCR_ABOVE_TH1_VAL,
    _DCR_ABOVE_TH2_NUM,
    _DCR_ABOVE_TH2_VAL,
    _HIGH_LV_NUM_R,
    _LOW_LV_NUM_R,                      
    _HIGH_LV_VAL_R,                            
    _LOW_LV_VAL_R,                           
    _HIGH_LV_NUM_G,                             
    _LOW_LV_NUM_G,                              
    _HIGH_LV_VAL_G,                             
    _LOW_LV_VAL_G,                             
    _HIGH_LV_NUM_B,                             
    _LOW_LV_NUM_B,                              
    _HIGH_LV_VAL_B,                            
    _LOW_LV_VAL_B,                             
} EnumDCRAdjOption;

//--------------------------------------------------
// Enumerations of Gamma Channel
//--------------------------------------------------
typedef enum
{
    _GAMMA_RED_CHANNEL,
    _GAMMA_GREEN_CHANNEL,
    _GAMMA_BLUE_CHANNEL,
} EnumGammaChannel;

//--------------------------------------------------
// Enumerations of Highlight Window Type
//--------------------------------------------------
typedef enum
{
    _FULL_WINDOW,                                
    _INSIDE_WINDOW,                              
    _OUTSIDE_WINDOW,                             
} EnumHLWType;

//--------------------------------------------------
// Enumerations of Highlight Window Active Select
//--------------------------------------------------
typedef enum
{
    _BRI_CON_A_ON_FULL_WINDOW,                   
    _BRI_CON_B_ON_INSIDE_WINDOW,                 
    _BRI_CON_A_ON_OUTSIDE_WINDOW,                
    _BRI_CON_B_ON_INSIDE_A_ON_OUTSIDE_WINDOW,    
} EnumBriConHLWType;

//--------------------------------------------------
// Enumerations of OD Table Type
//--------------------------------------------------
typedef enum
{
    _OD_TABLE_COMMON = 0x00,                
    _OD_TABLE_SEPARATE,
} EnumODTableType;

//--------------------------------------------------
// Enumerations of Y Peaking
//--------------------------------------------------
typedef enum
{
    _YPEAKING_GAIN_MODE,
    _YPEAKING_TABLE_MODE,
} EnumYpeakingMode;

typedef enum
{
    _YPEAKING_N_DIV32,
    _YPEAKING_N_DIV64,
    _YPEAKING_NO_DIV,
} EnumYpeakingCoeffResolution;

//--------------------------------------------------
// Enumerations of OCC Options
//--------------------------------------------------
typedef enum
{
    _PCM_SRGB,
    _PCM_ADOBE_RGB,
    _PCM_USER_MODE,
} EnumPCMType;

//****************************************************************************
// Enumerations of DP
//****************************************************************************
//--------------------------------------------------
// Enumerations of DP Link Training Type
//--------------------------------------------------
typedef enum
{
    _DP_NORMAL_LT = 0x00,                
    _DP_FAKE_LT,
} EnumDpLinkTrainingType;

//--------------------------------------------------
// Enumerations of DP Lane Number
//--------------------------------------------------
typedef enum
{
    _DP_LANE0 = 0x00,
    _DP_LANE1 = 0x02,
    _DP_LANE2 = 0x01,
    _DP_LANE3 = 0x03,
} EnumDpLaneNumber;

//--------------------------------------------------
// Enumerations of DP Fifo Check Condition
//--------------------------------------------------
typedef enum
{
    _DP_FIFO_DELAY_CHECK = 0x00,
    _DP_FIFO_POLLING_CHECK,
} EnumDpFifoCheckCondition;

//--------------------------------------------------
// Enumerations of DP Sink Reveive Port
//--------------------------------------------------
typedef enum
{
    _DP_SINK_REVEICE_PORT0 = 0x00,
    _DP_SINK_REVEICE_PORT1,
} EnumDpSinkReceivePort;

//--------------------------------------------------
// Enumerations of DP Sink Status
//--------------------------------------------------
typedef enum
{
    _DP_SINK_OUT_OF_SYNC = 0x00,
    _DP_SINK_IN_SYNC,
} EnumDpSinkStatus;

//--------------------------------------------------
// Enumerations of DP Hot Plug Assert Type
//--------------------------------------------------
typedef enum
{
    _DP_HPD_ASSERTED = 0x00,
    _DP_LONG_HPD_EVENT,
    _DP_HDCP_LONG_HPD_EVENT,    
} EnumDpHotPlugAssertType;

//****************************************************************************
// Enumerations of Measure
//****************************************************************************
//--------------------------------------------------
// Enumerations of Measure Data Info
//--------------------------------------------------
typedef enum
{
    _MEASURE_DATA_HPOLARITY,     
    _MEASURE_DATA_VPOLARITY,     
    _MEASURE_DATA_ERROR_FLAG,    
    _MEASURE_DATA_HPERIOD,       
    _MEASURE_DATA_HPULSE_WIDTH,  
    _MEASURE_DATA_VPERIOD,       
    _MEASURE_DATA_VPULSE_WIDTH,  
} EnumMeasureInputTimingDataType;


//--------------------------------------------------
// Enumerations of SyncProc/AutoFunc Measure Mode
//--------------------------------------------------
typedef enum
{
    _ANALOG_MODE_MEASURE  = 0x00,
    _DIGITAL_MODE_MEASURE = 0x01,
} EnumMeasureModeType;    

//--------------------------------------------------
// Enumerations of AutoFunction Measure Field Select
//--------------------------------------------------
typedef enum
{
    _EVEN_FIELD_MEASURE  = 0x00,
    _ODD_FIELD_MEASURE = 0x01,
    _NORMAL_MEASURE = 0x02,
} EnumMeasureFieldSelect;    

//--------------------------------------------------
// Enumerations of AutoFunction Measure Boundary Type
//--------------------------------------------------
typedef enum
{
    _FULL_BOUNDARY  = 0x00,
    _OVERSCAN_BOUNDARY = 0x01,
} EnumMeasureBoundType;    

//--------------------------------------------------
// Enumerations of SyncProc/AutoFunc Measure Mode
//--------------------------------------------------
typedef enum
{
    _ANALOG_MEASURE  = 0x00,
    _DIGITAL_MEASURE = 0x01,
} EnumSyncMeasureAnalogDigitalSel; 

//--------------------------------------------------
// Definitions of active region count type
//--------------------------------------------------
typedef enum
{
    _ACTIVE_REGION_TYPE = 0x00,
    _WHOLE_FRAME_TYPE = _BIT4,
    _BACK_PORCH_TYPE = _BIT5,
    _FRONT_PORCH_TYPE = (_BIT5 | _BIT4),
}EnumActiveRegionType;


//****************************************************************************
// Enumerations of Memory
//****************************************************************************
//--------------------------------------------------
// Enumerations of Memory Work
//--------------------------------------------------
typedef enum
{
    _NO_SDRAM_WORK_MODE = 0x00,
    _FRC_WORK_MODE,		
    _FRAME_SYNC_SDRAM_WORK_MODE,
    _3D_WORK_MODE,
} EnumMemoryWorkMode;

//--------------------------------------------------
// Enumerations of FIFO Frequency
//--------------------------------------------------
typedef enum
{
	_SCALER_FIFO_FREQ_M2PLL,
	_SCALER_FIFO_FREQ_MPLL,
} EnumScalerFIFOFreq;

//****************************************************************************
// Enumerations of MHL
//****************************************************************************
//--------------------------------------------------
// Definitions of MSC Native Commands
//--------------------------------------------------
typedef enum
{
    _MSC_SET_INT = 0x60,
    _MSC_WRITE_STAT = 0x60,
    _MSC_READ_DEVCAP = 0x61,
    _MSC_SET_HPD = 0x64,
    _MSC_CLR_HPD,
    _MSC_WRITE_BURST = 0x6C,
    _MSC_ABORT = 0x35,
    _MSC_MSG = 0x68,
} EnumMHLMscCommand;

//--------------------------------------------------
// Definitions of MSC Offset
//--------------------------------------------------
typedef enum
{
    _MSC_NULL_ADDRESS,
    // _MSC_SET_INT
    _MSC_RCHANGE_INT = 0x20,
    _MSC_DCHANGE_INT,
    // _MSC_WRITE_STAT
    _MSC_CONNECTED_RDY = 0x30,
    _MSC_LINK_MODE,
    // _MSC_MSG
    _MSC_MSGE = 0x02,
    _MSC_RCP = 0x10,
    _MSC_RCPK = 0x11,
    _MSC_RCPE = 0x12,
    _MSC_RAP = 0x20,
    _MSC_RAPK = 0x21,
    _MSC_UCP = 0x30,
    _MSC_UCPK = 0x31,
} EnumMHLMscOffset;

//--------------------------------------------------
// Definitions of MSC Data
//--------------------------------------------------
typedef enum
{
    _MSC_NULL_VALUE,
    // _MSC_RCHANGE_INT
    _MSC_DCAP_CHG = 0x01,
    _MSC_DSCR_CHG = 0x02,
    _MSC_REQ_WRT = 0x04,
    _MSC_GRT_WRT = 0x08,
    // _MSC_DCHANGE_INT
    _MSC_EDID_CHG = 0x02,
    // _MSC_CONNECTED_RDY
    _MSC_DCAP_RDY = 0x01,
    // _MSC_LINK_MODE
    _MSC_PATH_EN = 0x08,
    _MSC_MUTED = 0x10,
} EnumMHLMscData;

typedef enum
{
    _MHL_WRITE_BURST_WITH_REQ,
    _MHL_WRITE_BURST_WITHOUT_REQ,
}EnumMHLWriteBurstMode;

//****************************************************************************
// Enumerations of Mode
//****************************************************************************
//--------------------------------------------------
// Enumerations of Mode State
//--------------------------------------------------
typedef enum
{
    _MODE_STATUS_INITIAL = 0x00,            
    _MODE_STATUS_SEARCH,             
    _MODE_STATUS_DISPLAY_SETTING,    
    _MODE_STATUS_ACTIVE,             
    _MODE_STATUS_NOSUPPORT,          
    _MODE_STATUS_NOSIGNAL,           
    _MODE_STATUS_POWER_SAVING,       
    _MODE_STATUS_POWER_OFF,          
    _MODE_STATUS_FACTORY,  
    _MODE_STATUS_NONE = 0xFF,
} EnumModeStatus;


//****************************************************************************
// Enumerations of Power
//****************************************************************************
//--------------------------------------------------
// Enumerations of Power Status/Action
//--------------------------------------------------
typedef enum
{
    _POWER_STATUS_AC_ON = 0x00,
    _POWER_STATUS_OFF,
    _POWER_STATUS_NORMAL,
    _POWER_STATUS_SAVING,
    _POWER_STATUS_NOSUPPORT_SAVING,
    _POWER_STATUS_NONE = 0xFF,
} EnumPowerStatus;

//--------------------------------------------------
// Enumerations of Power Action
//--------------------------------------------------
typedef enum
{
    _POWER_ACTION_OFF_TO_NORMAL = 0x00,          
    _POWER_ACTION_AC_ON_TO_NORMAL,         
    _POWER_ACTION_AC_ON_TO_OFF,            
    _POWER_ACTION_PS_TO_NORMAL,           
    _POWER_ACTION_PS_TO_OFF,              
    _POWER_ACTION_NORMAL_TO_PS,           
    _POWER_ACTION_NORMAL_TO_OFF,          
    _POWER_ACTION_NORMAL_TO_NOSUPPORT_PS, 
    _POWER_ACTION_NOSUPPORT_PS_TO_PS,
    _POWER_ACTION_NOSUPPORT_PS_TO_OFF, 
    _POWER_ACTION_NONE = 0xFF,
} EnumPowerAction;

//--------------------------------------------------
// Enumerations of Power Action
//--------------------------------------------------
typedef enum
{
    _MODE_ACTION_NO_RESET_MODE = 0x00,                
    _MODE_ACTION_RESET_TO_SEARCH,
    _MODE_ACTION_RESET_TO_DISPLAY_SETTING, 
    _MODE_ACTION_RESET_TO_DISPLAY_SETTING_WITHOUT_FORCETOBG,
    _MODE_ACTION_RESET_TO_NOSUPPORT,    
    _MODE_ACTION_RESET_TO_NOSIGNAL,
    _MODE_ACTION_RESET_TO_POWER_SAVING,    
    _MODE_ACTION_RESET_TO_POWER_OFF,           
    _MODE_ACTION_RESET_TO_FACTORY_MODE,   
    _MODE_ACTION_NONE = 0xFF,
} EnumModeAction;


//****************************************************************************
// Enumerations of Scaling
//****************************************************************************
//--------------------------------------------------
// Enumerations of VSU Type
//--------------------------------------------------
typedef enum
{
    _VSU_2D_4LINE_COEF 	= 0x00,  // 2D 4line SU
    _VSU_2D_3LINE_COEF 	= 0x01,	 // 2D 3line SU	    
    _VSU_3D_2LINE_COEF 	= 0x02,  // 3D 2line SU 
    _VSU_3D_3LINE_COEF 	= 0x03,  // 3D 3line SU 
    _VSU_3D_4LINE_COEF 	= 0x04,  // 3D 4line SU   
} EnumVSUCoefType;


//****************************************************************************
// Enumerations of Source
//****************************************************************************
//--------------------------------------------------
// Enumerations of Source State
//--------------------------------------------------
typedef enum
{
    _SOURCE_VGA,
    _SOURCE_VIDEO,
    _SOURCE_DVI,
    _SOURCE_HDMI,
    _SOURCE_DP,
    _SOURCE_NONE,
    _SOURCE_AMOUNT = _SOURCE_NONE,
} EnumSourceTypeDef;

//--------------------------------------------------
// Enumerations of Input Port List
//--------------------------------------------------
typedef enum
{
    _D0_INPUT_PORT = 0x00,
    _D1_INPUT_PORT,
    _D2_INPUT_PORT,
    _D3_INPUT_PORT,
    _A0_INPUT_PORT,
    _NO_INPUT_PORT,
}EnumSourceSearchPort;

///////////////////////////////////////
// Special Case for User Application //
///////////////////////////////////////
//--------------------------------------------------
// Input Port List
//--------------------------------------------------
#define _D0_INPUT_PORT                              0
#define _D1_INPUT_PORT                              1
#define _D2_INPUT_PORT                              2
#define _D3_INPUT_PORT                              3
#define _A0_INPUT_PORT                              4
#define _NO_INPUT_PORT                              5

//--------------------------------------------------
// Enumerations of Input Port List
//--------------------------------------------------
typedef enum
{
    _INPUT_PORT_PRIORITY_0 = 0x00,
    _INPUT_PORT_PRIORITY_1,
    _INPUT_PORT_PRIORITY_2,
    _INPUT_PORT_PRIORITY_3,
    _INPUT_PORT_PRIORITY_4,
    _INPUT_PORT_PRIORITY_NONE,
}EnumSourceSearchPortPriority;

//--------------------------------------------------
// Enumerations of Input Port Search Group List
//--------------------------------------------------
typedef enum
{
    _INPUT_PORT_GROUP_0 = 0x00,
    _INPUT_PORT_GROUP_1,
    _INPUT_PORT_GROUP_2,
    _INPUT_PORT_GROUP_3,
    _INPUT_PORT_GROUP_4,
    _INPUT_PORT_GROUP_NONE,
}EnumSourceSearchGroup;


//****************************************************************************
// Enumerations of Timer
//****************************************************************************
//--------------------------------------------------
// Enumerations of Timer Operation
//--------------------------------------------------
typedef enum
{
    _TIMER_OPERATION_INITIAL_MODE,
    _TIMER_OPERATION_POWER_NORMAL_MODE,
    _TIMER_OPERATION_POWER_SAVING_MODE,
    _TIMER_OPERATION_POWER_SAVING_FAST_MODE,    
    _TIMER_OPERATION_POWER_IDLE_MODE,
    _TIMER_OPERATION_OSD_MODE,
} EnumScalerTimerOperationMode;

//--------------------------------------------------
// Enumerations of Instant Timer Counter Options
//--------------------------------------------------
typedef enum
{
    _TIMER_OFF,
    _TIMER_COUNT_1_MS = 1000,
    _TIMER_COUNT_2_MS = 2000,
    _TIMER_COUNT_3_MS = 3000,
    _TIMER_COUNT_4_MS = 4000,
    _TIMER_COUNT_5_MS = 5000,
    _TIMER_COUNT_6_MS = 6000,
    _TIMER_COUNT_7_MS = 7000,
    _TIMER_COUNT_8_MS = 8000,
    _TIMER_COUNT_9_MS = 9000,
    _TIMER_COUNT_10_MS = 10000,
    _TIMER_COUNT_11_MS = 11000,
    _TIMER_COUNT_12_MS = 12000,
    _TIMER_COUNT_13_MS = 13000,
    _TIMER_COUNT_14_MS = 14000,
    _TIMER_COUNT_15_MS = 15000,
    _TIMER_COUNT_16_MS = 16000,
    _TIMER_COUNT_17_MS = 17000,
    _TIMER_COUNT_18_MS = 18000,
    _TIMER_COUNT_19_MS = 19000,
    _TIMER_COUNT_20_MS = 20000,
    _TIMER_COUNT_21_MS = 21000,
    _TIMER_COUNT_22_MS = 22000,
    _TIMER_COUNT_23_MS = 23000,
    _TIMER_COUNT_24_MS = 24000,
    _TIMER_COUNT_25_MS = 25000,
    _TIMER_COUNT_26_MS = 26000,
    _TIMER_COUNT_27_MS = 27000,
    _TIMER_COUNT_28_MS = 28000,
    _TIMER_COUNT_29_MS = 29000,
    _TIMER_COUNT_30_MS = 30000,
    _TIMER_COUNT_BY_DEN_STOP = 0xFFFF,
}EnumInstTimerCounter;

//****************************************************************************
// Enumerations of Timing Info
//****************************************************************************
//--------------------------------------------------
// Enumerations of Timing Info
//--------------------------------------------------
typedef enum
{
    _HPOLARITY = 0x00,
    _VPOLARITY,
    _INTERLACE,
    _IHFREQ,
    _IHTOTAL,
    _IHWIDTH,
    _IHSTART,
    _IVFREQ,
    _IVTOTAL,
    _IVHEIGHT,
    _IVSTART,
    _IVSYNC_WIDTH,
    _MISC,
} EnumTimingInfoSelect;

//--------------------------------------------------
// Enumerations of Display Timing Data Info
//--------------------------------------------------
typedef enum
{
    _DISPLAY_TIMING_HTOTAL,       
    _DISPLAY_TIMING_VTOTAL,       
    _DISPLAY_TIMING_HSTART,       
    _DISPLAY_TIMING_VSTART,       
    _DISPLAY_TIMING_HWIDTH,       
    _DISPLAY_TIMING_VHEIGHT,      
} EnumDispTimingDataType;

//****************************************************************************
// Enumerations of Audio
//****************************************************************************
//--------------------------------------------------
// Enumerations of Audio State
//--------------------------------------------------
typedef enum
{
    _AUDIO_STATUS_POWER_OFF,
    _AUDIO_STATUS_PREPARING,
    _AUDIO_STATUS_PLAYBACK,
} EnumAudioState;

//--------------------------------------------------
// Enumerations of Audio DAC State
//--------------------------------------------------
typedef enum
{
    _AUDIO_DAC_OFF,
    _AUDIO_DAC_INITIAL,
    _AUDIO_DAC_CHARGE,
    _AUDIO_DAC_DEPOP,
    _AUDIO_DAC_READY,
} EnumAudioDACState;

//--------------------------------------------------
// Enumerations of Audio DAC Output
//--------------------------------------------------
typedef enum
{
    _AUDIO_DAC_OUTPUT_NONE,
    _AUDIO_DAC_OUTPUT_SPEAKER,
    _AUDIO_DAC_OUTPUT_HEADPHONE,
    _AUDIO_DAC_OUTPUT_BOTH,    
} EnumAudioDACOutput;

//--------------------------------------------------
// Enumerations of Audio Sampling Freq
//--------------------------------------------------
typedef enum
{
    _AUDIO_FREQ_NONE,
    _AUDIO_FREQ_32K,
    _AUDIO_FREQ_44_1K,
    _AUDIO_FREQ_48K,
    _AUDIO_FREQ_88_2K,
    _AUDIO_FREQ_96K,
    _AUDIO_FREQ_176_4K,
    _AUDIO_FREQ_192K,
    _AUDIO_FREQ_NO_SUPPORT,    
} EnumAudioSamplingFreq;

//--------------------------------------------------
// Enumerations of Digital Audio Source
//--------------------------------------------------
typedef enum
{
    _DIGITAL_AUDIO_SOURCE_NONE,    
    _DIGITAL_AUDIO_SOURCE_HDMI,
    _DIGITAL_AUDIO_SOURCE_DP,
} EnumAudioDigitalSource;

//****************************************************************************
// Enumerations of 3D
//****************************************************************************
//--------------------------------------------------
// Enumerations of 3D Format
//--------------------------------------------------
typedef enum
{
    _FRAME_PACKING = 0x00,
	_FRAME_SEQUENTIAL = 0x01,
    _LINE_INTERLACE = 0x02,
    _SIDE_BY_SIDE_FULL = 0x03,    
    _TOP_AND_BOTTOM = 0x06,
    _SIDE_BY_SIDE_HALF = 0x08,  
    _PIXEL_INTERLEAVE_0,
    _PIXEL_INTERLEAVE_1,  
    _NO_3D_FORMAT,    
} Enum3DinputFormat;

//--------------------------------------------------
// Enumerations of 3D Display Sequence
//--------------------------------------------------
typedef enum
{
    _3D_DISPLAY_RL = 0x00,
    _3D_DISPLAY_LR = 0x01,		
    _3D_DISPLAY_2D = 0x02,
} Enum3DDisplaySequence;
 
//--------------------------------------------------
// Enumerations of OSD select 3D format
//--------------------------------------------------
typedef enum
{
    _3D_MODE_FORMAT_AUTO = 0x00,
    _3D_MODE_FORMAT_SBS,
    _3D_MODE_FORMAT_TNB,
    _3D_MODE_FORMAT_LINE_INTERLACE,
} Enum3DFormatSelect;

//--------------------------------------------------
// Enumerations of 3D Advance Support
//--------------------------------------------------
typedef enum
{
    _3D_OFF = 0x00,
    _3D_ON, 
    _3D_2D_TO_3D,
} Enum3DAdvanceSupport;

//--------------------------------------------------
// Enumerations of 3D Convergence
//--------------------------------------------------
typedef enum
{
    _3D_IN = 0x00,
    _3D_OUT,
} Enum3DSelectConvergence;

//--------------------------------------------------
// Enumerations of 3D Convergence Mode
//--------------------------------------------------
typedef enum
{
    _LINEAR_MODE = 0x00,
    _NON_LINEAR_MODE_1,
    _NON_LINEAR_MODE_2,
    _NON_LINEAR_MODE_3,
    _NON_LINEAR_MODE_4,
    _NON_LINEAR_MODE_5,
    _NON_LINEAR_MODE_AMOUNT = _NON_LINEAR_MODE_5,
} Enum3DSelectConvergenceMode;

//--------------------------------------------------
// Definitions of DP Dual Mode Status
//--------------------------------------------------
typedef enum
{
    _DP_DUAL_MODE_DP = 0x00,
    _DP_DUAL_MODE_TMDS,
} EnumDpDualModeStatus;

//------------------------------------------------------------
// Definitions of Pin Share Config type that user can adjust
//------------------------------------------------------------
typedef enum
{
    _GPI,
    _GPO_OD,
    _GPO_PP,
    _PWM0_OD,
    _PWM0_PP,
    _PWM1_OD,
    _PWM1_PP,
    _PWM2_OD,
    _PWM2_PP,
    _PWM3_OD,
    _PWM3_PP,
    _PWM4_OD,
    _PWM4_PP,
    _PWM5_OD,
    _PWM5_PP,
} EnumPinConfigTyte;

//--------------------------------------------------
// Definitions of AVI Info Frame Contents
//--------------------------------------------------
typedef enum
{
    _AVI_INFO_COLOR_SPACE,
    _AVI_INFO_COLORIMETRY,
    _AVI_INFO_EXTENDED_COLORIMETRY,
    _AVI_INFO_RGB_QUANTIZATION,
    _AVI_INFO_YCC_QUANTIZATION,    
    _AVI_INFO_SCAN_INFO,
    _AVI_INFO_IT_CONTENT,
} EnumAviInfoContent;

//--------------------------------------------------
// Definitions of AVI Info Content Types
//--------------------------------------------------
typedef enum
{
    _AVI_COLOR_SPACE_RGB = 0x00,
    _AVI_COLOR_SPACE_YCC_422 = 0x01,
    _AVI_COLOR_SPACE_YCC_444 = 0x02,
    _AVI_COLOR_SPACE_RESERVED = 0x03,    
} EnumAviInfoColorSpace;

typedef enum
{
    _AVI_COLORIMETRY_NONE = 0x00,
    _AVI_COLORIMETRY_ITU601 = 0x01,
    _AVI_COLORIMETRY_ITU709 = 0x02,
    _AVI_COLORIMETRY_EXTENDED = 0x03,    
} EnumAviInfoColorimetry;

typedef enum
{
    _AVI_COLORIMETRY_EXT_XVYCC601 = 0x00,
    _AVI_COLORIMETRY_EXT_XVYCC709 = 0x01,  
} EnumAviInfoColorimetryExt;

typedef enum
{
    _SPD_INFO_OUI,
    _SPD_INFO_FREESYNC_SUPPORT,
    _SPD_INFO_FREESYNC_ENABLE,
    _SPD_INFO_FREESYNC_ACTIVE,
    _SPD_INFO_FREESYNC_MIN_VFREQ,
    _SPD_INFO_FREESYNC_MAX_VFREQ,
} EnumAmdSpdInfoContent;

//--------------------------------------------------
// Definitions of RGB Quantization Range
//--------------------------------------------------
typedef enum
{
    _RGB_QUANTIZATION_FULL_RANGE = 0x00,
    _RGB_QUANTIZATION_LIMIT_RANGE = 0x01,
    _RGB_QUANTIZATION_DEFAULT_RANGE = 0x02,
    _RGB_QUANTIZATION_RESERVED = 0x03,    
} EnumColorRGBQuantization;

typedef enum
{
    _AVI_RGB_QUANTIZATION_DEFAULT = 0x00,
    _AVI_RGB_QUANTIZATION_LIMITED = 0x01,
    _AVI_RGB_QUANTIZATION_FULL = 0x02,
    _AVI_RGB_QUANTIZATION_RESERVED = 0x03,    
} EnumAviInfoRGBQuantization;

//--------------------------------------------------
// Definitions of YCC Quantization Range
//--------------------------------------------------
typedef enum
{
    _YCC_QUANTIZATION_LIMIT_RANGE = 0x00,
    _YCC_QUANTIZATION_FULL_RANGE = 0x01,        
} EnumColorYCCQuantization;

typedef enum
{
    _AVI_YCC_QUANTIZATION_LIMITED = 0x00,
    _AVI_YCC_QUANTIZATION_FULL = 0x01,    
} EnumAviInfoYCCQuantization;

typedef enum
{
    _AVI_SCAN_INFO_NONE = 0x00,
    _AVI_SCAN_INFO_OVERSCAN = 0x01,
    _AVI_SCAN_INFO_UNDERCAN = 0x02,
    _AVI_SCAN_INFO_RESERVED = 0x03,    
} EnumAviInfoScanInfo;

typedef enum
{
    _AVI_IT_CONTENT_NONE = 0x00,
    _AVI_IT_CONTENT_TRUE = 0x01,  
} EnumAviInfoITContent;
