#ifndef __VOLUME_TABLE_H__
#define __VOLUME_TABLE_H__


#if(CVT_DEF_VOLUME_TABLE_TYPE == VOLUME_TABLE_CS8563S_CVT_DEFAULT)

#define SP_VOLUME_TABLE_0                       0x0000           
#define SP_VOLUME_TABLE_10                      0x0666  
#define SP_VOLUME_TABLE_20                      0x0CCC 
#define SP_VOLUME_TABLE_30                      0x1332 
#define SP_VOLUME_TABLE_40                      0x1998 
#define SP_VOLUME_TABLE_50                      0x1FFE 
#define SP_VOLUME_TABLE_60                      0x2664 
#define SP_VOLUME_TABLE_70                      0x1FFE 
#define SP_VOLUME_TABLE_80                      0x3330 
#define SP_VOLUME_TABLE_90                      0x3996
#define SP_VOLUME_TABLE_100                     0x3FFC//MAX is 496   

#define SP_VOLUME_HDMI_OFFSET                   (0)
#define SP_VOLUME_LINE_IN_OFFSET                0    


#define HP_VOLUME_TABLE_0                       0x0000        
#define HP_VOLUME_TABLE_10                      0x0319   
#define HP_VOLUME_TABLE_20                      0x0632  
#define HP_VOLUME_TABLE_30                      0x094B   
#define HP_VOLUME_TABLE_40                      0x0C64   
#define HP_VOLUME_TABLE_50                      0x0F7D   
#define HP_VOLUME_TABLE_60                      0x1296   
#define HP_VOLUME_TABLE_70                      0x15AF   
#define HP_VOLUME_TABLE_80                      0x18C8   
#define HP_VOLUME_TABLE_90                      0x1BE1   
#define HP_VOLUME_TABLE_100                     0x1EFA //MAX is 496  


#define HP_VOLUME_HDMI_OFFSET                   1
#define HP_VOLUME_LINE_IN_OFFSET                0    
#else
error "CVT_DEF_VOLUME_TABLE_TYPE no define"
#endif
#endif
