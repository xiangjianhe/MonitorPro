//Customer config define //
#ifndef _CustomerCfg_H_
#define _CustomerCfg_H_

#include "Global_Product_Define.h"


#define Maco2Str(x)                         #x      
#define StrToVal(x)                         Maco2Str(x)

//---------------------------------------------------------------------------------
// CUSTOMER SELECTION
//---------------------------------------------------------------------------------
#define CUSTOMER_CVTE                       0

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
#define CUSTOMER_TYPE                       CUSTOMER_CVTE
//---------------------------------------------------------------------------------

#if (CUSTOMER_TYPE == CUSTOMER_CVTE)
#include "Customer_CVTE.h"
#else
#error "not config Customer"
#endif

#define MainBoardType                       BOARD_TYPE(CVT_DEF_BOARD_TYPE)
#ifndef _TUKISH_EN
#define _TUKISH_EN                          _OFF
#endif

#include "Global_Default_Config.h"
#include "Global_Config_Check.h"
//---------------------------------------------------------------------------------
#endif
