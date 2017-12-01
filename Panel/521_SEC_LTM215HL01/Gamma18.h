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
// ID Code      : Gamma18.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// GAMMA 1.8
//****************************************************************************
BYTE code tLUTGAMMA_18_TABLE[] =
{
    0x00, 0x00, 0x07, //R 0, 1
    0x01, 0x10, 0x1D, //R 2, 3
    0x02, 0x60, 0x2C, //R 4, 5
    0x03, 0x40, 0x3B, //R 6, 7
    0x04, 0x30, 0x4B, //R 8, 9
    0x05, 0x00, 0x57, //R 10, 11
    0x05, 0xE0, 0x63, //R 12, 13
    0x06, 0xA0, 0x70, //R 14, 15
    0x07, 0x40, 0x7B, //R 16, 17
    0x08, 0x10, 0x86, //R 18, 19
    0x08, 0xD0, 0x93, //R 20, 21
    0x09, 0x90, 0x9F, //R 22, 23
    0x0A, 0x50, 0xAA, //R 24, 25
    0x0A, 0xE0, 0xB4, //R 26, 27
    0x0B, 0x90, 0xBF, //R 28, 29
    0x0C, 0x30, 0xC6, //R 30, 31
    0x0C, 0xB0, 0xD0, //R 32, 33
    0x0D, 0x50, 0xDB, //R 34, 35
    0x0D, 0xF0, 0xE3, //R 36, 37
    0x0E, 0x70, 0xEC, //R 38, 39
    0x0F, 0x10, 0xF4, //R 40, 41
    0x0F, 0x80, 0xFD, //R 42, 43
    0x10, 0x11, 0x06, //R 44, 45
    0x10, 0xA1, 0x0F, //R 46, 47
    0x11, 0x31, 0x19, //R 48, 49
    0x11, 0xD1, 0x21, //R 50, 51
    0x12, 0x61, 0x2C, //R 52, 53
    0x12, 0xF1, 0x34, //R 54, 55
    0x13, 0x91, 0x3D, //R 56, 57
    0x14, 0x41, 0x49, //R 58, 59
    0x14, 0xD1, 0x51, //R 60, 61
    0x15, 0x61, 0x5B, //R 62, 63
    0x15, 0xF1, 0x64, //R 64, 65
    0x16, 0x91, 0x6B, //R 66, 67
    0x16, 0xF1, 0x74, //R 68, 69
    0x17, 0x81, 0x7D, //R 70, 71
    0x18, 0x11, 0x85, //R 72, 73
    0x18, 0xA1, 0x8E, //R 74, 75
    0x19, 0x21, 0x95, //R 76, 77
    0x19, 0x91, 0x9D, //R 78, 79
    0x1A, 0x11, 0xA4, //R 80, 81
    0x1A, 0xA1, 0xAD, //R 82, 83
    0x1B, 0x21, 0xB6, //R 84, 85
    0x1B, 0xA1, 0xBD, //R 86, 87
    0x1C, 0x11, 0xC5, //R 88, 89
    0x1C, 0x81, 0xCD, //R 90, 91
    0x1D, 0x11, 0xD5, //R 92, 93
    0x1D, 0x81, 0xDC, //R 94, 95
    0x1E, 0x01, 0xE4, //R 96, 97
    0x1E, 0x71, 0xEC, //R 98, 99
    0x1F, 0x01, 0xF4, //R 100, 101
    0x1F, 0x71, 0xFC, //R 102, 103
    0x1F, 0xF2, 0x02, //R 104, 105
    0x20, 0x62, 0x0A, //R 106, 107
    0x20, 0xD2, 0x0F, //R 108, 109
    0x21, 0x32, 0x16, //R 110, 111
    0x21, 0xB2, 0x1E, //R 112, 113
    0x22, 0x22, 0x25, //R 114, 115
    0x22, 0x92, 0x2D, //R 116, 117
    0x23, 0x02, 0x34, //R 118, 119
    0x23, 0x82, 0x3C, //R 120, 121
    0x23, 0xF2, 0x42, //R 122, 123
    0x24, 0x62, 0x4A, //R 124, 125
    0x24, 0xE2, 0x51, //R 126, 127
    0x25, 0x42, 0x58, //R 128, 129
    0x25, 0xC2, 0x5E, //R 130, 131
    0x26, 0x02, 0x64, //R 132, 133
    0x26, 0x82, 0x6B, //R 134, 135
    0x26, 0xF2, 0x72, //R 136, 137
    0x27, 0x62, 0x79, //R 138, 139
    0x27, 0xD2, 0x80, //R 140, 141
    0x28, 0x32, 0x87, //R 142, 143
    0x28, 0x92, 0x8B, //R 144, 145
    0x28, 0xE2, 0x91, //R 146, 147
    0x29, 0x52, 0x99, //R 148, 149
    0x29, 0xC2, 0x9E, //R 150, 151
    0x2A, 0x42, 0xA6, //R 152, 153
    0x2A, 0x92, 0xAE, //R 154, 155
    0x2B, 0x12, 0xB4, //R 156, 157
    0x2B, 0x72, 0xBA, //R 158, 159
    0x2B, 0xE2, 0xC1, //R 160, 161
    0x2C, 0x42, 0xC7, //R 162, 163
    0x2C, 0xA2, 0xCC, //R 164, 165
    0x2D, 0x12, 0xD3, //R 166, 167
    0x2D, 0x62, 0xDC, //R 168, 169
    0x2D, 0xE2, 0xE1, //R 170, 171
    0x2E, 0x32, 0xE6, //R 172, 173
    0x2E, 0xA2, 0xED, //R 174, 175
    0x2E, 0xF2, 0xF2, //R 176, 177
    0x2F, 0x42, 0xF9, //R 178, 179
    0x2F, 0xC3, 0x01, //R 180, 181
    0x30, 0x33, 0x06, //R 182, 183
    0x30, 0x83, 0x0B, //R 184, 185
    0x30, 0xE3, 0x11, //R 186, 187
    0x31, 0x43, 0x16, //R 188, 189
    0x31, 0x93, 0x1E, //R 190, 191
    0x32, 0x03, 0x23, //R 192, 193
    0x32, 0x63, 0x28, //R 194, 195
    0x32, 0xB3, 0x2E, //R 196, 197
    0x33, 0x13, 0x33, //R 198, 199
    0x33, 0x63, 0x39, //R 200, 201
    0x33, 0xD3, 0x40, //R 202, 203
    0x34, 0x33, 0x46, //R 204, 205
    0x34, 0x83, 0x4A, //R 206, 207
    0x34, 0xD3, 0x52, //R 208, 209
    0x35, 0x43, 0x57, //R 210, 211
    0x35, 0x93, 0x5C, //R 212, 213
    0x35, 0xE3, 0x62, //R 214, 215
    0x36, 0x53, 0x68, //R 216, 217
    0x36, 0xB3, 0x6E, //R 218, 219
    0x37, 0x23, 0x74, //R 220, 221
    0x37, 0x83, 0x7A, //R 222, 223
    0x37, 0xC3, 0x80, //R 224, 225
    0x38, 0x23, 0x85, //R 226, 227
    0x38, 0x93, 0x8C, //R 228, 229
    0x39, 0x13, 0x93, //R 230, 231
    0x39, 0x73, 0x9A, //R 232, 233
    0x39, 0xC3, 0xA0, //R 234, 235
    0x3A, 0x23, 0xA4, //R 236, 237
    0x3A, 0x83, 0xAA, //R 238, 239
    0x3A, 0xD3, 0xB0, //R 240, 241
    0x3B, 0x53, 0xBC, //R 242, 243
    0x3C, 0x13, 0xC5, //R 244, 245
    0x3C, 0xA3, 0xD0, //R 246, 247
    0x3D, 0x63, 0xDC, //R 248, 249
    0x3E, 0x23, 0xE7, //R 250, 251
    0x3E, 0xC3, 0xF2, //R 252, 253
    0x3F, 0x93, 0xFC, //R 254, 255
    0x3F, 0xC0, 0x00, //R 256

    0x00, 0x00, 0x07, //G 0, 1
    0x01, 0x40, 0x20, //G 2, 3
    0x02, 0x80, 0x31, //G 4, 5
    0x03, 0x90, 0x40, //G 6, 7
    0x04, 0x80, 0x4F, //G 8, 9
    0x05, 0x60, 0x5D, //G 10, 11
    0x06, 0x30, 0x69, //G 12, 13
    0x07, 0x00, 0x76, //G 14, 15
    0x07, 0xC0, 0x82, //G 16, 17
    0x08, 0x80, 0x8F, //G 18, 19
    0x09, 0x40, 0x9A, //G 20, 21
    0x0A, 0x00, 0xA5, //G 22, 23
    0x0A, 0xB0, 0xB0, //G 24, 25
    0x0B, 0x50, 0xBB, //G 26, 27
    0x0C, 0x00, 0xC5, //G 28, 29
    0x0C, 0xA0, 0xCF, //G 30, 31
    0x0D, 0x40, 0xD9, //G 32, 33
    0x0D, 0xE0, 0xE3, //G 34, 35
    0x0E, 0x70, 0xEC, //G 36, 37
    0x0F, 0x10, 0xF5, //G 38, 39
    0x0F, 0xA0, 0xFE, //G 40, 41
    0x10, 0x21, 0x07, //G 42, 43
    0x10, 0xD1, 0x11, //G 44, 45
    0x11, 0x61, 0x1B, //G 46, 47
    0x12, 0x01, 0x24, //G 48, 49
    0x12, 0xA1, 0x2E, //G 50, 51
    0x13, 0x31, 0x38, //G 52, 53
    0x13, 0xD1, 0x41, //G 54, 55
    0x14, 0x61, 0x4B, //G 56, 57
    0x15, 0x01, 0x54, //G 58, 59
    0x15, 0x91, 0x5E, //G 60, 61
    0x16, 0x11, 0x66, //G 62, 63
    0x16, 0xB1, 0x6F, //G 64, 65
    0x17, 0x31, 0x78, //G 66, 67
    0x17, 0xD1, 0x81, //G 68, 69
    0x18, 0x51, 0x8A, //G 70, 71
    0x18, 0xF1, 0x92, //G 72, 73
    0x19, 0x61, 0x9B, //G 74, 75
    0x19, 0xF1, 0xA2, //G 76, 77
    0x1A, 0x71, 0xAB, //G 78, 79
    0x1A, 0xF1, 0xB3, //G 80, 81
    0x1B, 0x71, 0xBC, //G 82, 83
    0x1B, 0xF1, 0xC3, //G 84, 85
    0x1C, 0x81, 0xCC, //G 86, 87
    0x1D, 0x01, 0xD4, //G 88, 89
    0x1D, 0x81, 0xDD, //G 90, 91
    0x1E, 0x01, 0xE4, //G 92, 93
    0x1E, 0x81, 0xEC, //G 94, 95
    0x1F, 0x01, 0xF3, //G 96, 97
    0x1F, 0x71, 0xFC, //G 98, 99
    0x20, 0x02, 0x03, //G 100, 101
    0x20, 0x62, 0x0A, //G 102, 103
    0x20, 0xE2, 0x11, //G 104, 105
    0x21, 0x42, 0x19, //G 106, 107
    0x21, 0xD2, 0x21, //G 108, 109
    0x22, 0x42, 0x28, //G 110, 111
    0x22, 0xC2, 0x30, //G 112, 113
    0x23, 0x32, 0x37, //G 114, 115
    0x23, 0xB2, 0x3F, //G 116, 117
    0x24, 0x22, 0x45, //G 118, 119
    0x24, 0x92, 0x4D, //G 120, 121
    0x25, 0x02, 0x53, //G 122, 123
    0x25, 0x72, 0x5B, //G 124, 125
    0x25, 0xF2, 0x62, //G 126, 127
    0x26, 0x52, 0x69, //G 128, 129
    0x26, 0xD2, 0x70, //G 130, 131
    0x27, 0x32, 0x76, //G 132, 133
    0x27, 0xB2, 0x7E, //G 134, 135
    0x28, 0x12, 0x84, //G 136, 137
    0x28, 0x82, 0x8C, //G 138, 139
    0x28, 0xF2, 0x92, //G 140, 141
    0x29, 0x52, 0x99, //G 142, 143
    0x29, 0xD2, 0xA0, //G 144, 145
    0x2A, 0x32, 0xA6, //G 146, 147
    0x2A, 0xB2, 0xAE, //G 148, 149
    0x2B, 0x12, 0xB4, //G 150, 151
    0x2B, 0x72, 0xBB, //G 152, 153
    0x2B, 0xE2, 0xC1, //G 154, 155
    0x2C, 0x42, 0xC7, //G 156, 157
    0x2C, 0xB2, 0xCE, //G 158, 159
    0x2D, 0x12, 0xD4, //G 160, 161
    0x2D, 0x72, 0xDB, //G 162, 163
    0x2D, 0xE2, 0xE1, //G 164, 165
    0x2E, 0x42, 0xE7, //G 166, 167
    0x2E, 0xB2, 0xEE, //G 168, 169
    0x2F, 0x12, 0xF4, //G 170, 171
    0x2F, 0x72, 0xFB, //G 172, 173
    0x2F, 0xE3, 0x01, //G 174, 175
    0x30, 0x33, 0x06, //G 176, 177
    0x30, 0xA3, 0x0D, //G 178, 179
    0x30, 0xF3, 0x12, //G 180, 181
    0x31, 0x43, 0x18, //G 182, 183
    0x31, 0xB3, 0x1E, //G 184, 185
    0x32, 0x13, 0x23, //G 186, 187
    0x32, 0x63, 0x29, //G 188, 189
    0x32, 0xC3, 0x2F, //G 190, 191
    0x33, 0x13, 0x33, //G 192, 193
    0x33, 0x63, 0x3A, //G 194, 195
    0x33, 0xD3, 0x3F, //G 196, 197
    0x34, 0x23, 0x44, //G 198, 199
    0x34, 0x73, 0x4B, //G 200, 201
    0x34, 0xE3, 0x50, //G 202, 203
    0x35, 0x33, 0x55, //G 204, 205
    0x35, 0x83, 0x5C, //G 206, 207
    0x35, 0xE3, 0x61, //G 208, 209
    0x36, 0x33, 0x66, //G 210, 211
    0x36, 0xA3, 0x6D, //G 212, 213
    0x36, 0xF3, 0x72, //G 214, 215
    0x37, 0x43, 0x77, //G 216, 217
    0x37, 0xA3, 0x7D, //G 218, 219
    0x38, 0x03, 0x82, //G 220, 221
    0x38, 0x53, 0x88, //G 222, 223
    0x38, 0xB3, 0x8E, //G 224, 225
    0x39, 0x03, 0x93, //G 226, 227
    0x39, 0x63, 0x99, //G 228, 229
    0x39, 0xC3, 0x9F, //G 230, 231
    0x3A, 0x13, 0xA4, //G 232, 233
    0x3A, 0x73, 0xAA, //G 234, 235
    0x3A, 0xD3, 0xB0, //G 236, 237
    0x3B, 0x23, 0xB5, //G 238, 239
    0x3B, 0x83, 0xBC, //G 240, 241
    0x3B, 0xF3, 0xC1, //G 242, 243
    0x3C, 0x43, 0xC8, //G 244, 245
    0x3C, 0xB3, 0xCF, //G 246, 247
    0x3D, 0x43, 0xDE, //G 248, 249
    0x3E, 0x63, 0xEB, //G 250, 251
    0x3E, 0xF3, 0xF3, //G 252, 253
    0x3F, 0x73, 0xFC, //G 254, 255
    0x3F, 0xC0, 0x00, //G 256

    0x00, 0x00, 0x05, //B 0, 1
    0x00, 0xD0, 0x1A, //B 2, 3
    0x02, 0x30, 0x2E, //B 4, 5
    0x03, 0x60, 0x41, //B 6, 7
    0x04, 0x80, 0x4F, //B 8, 9
    0x05, 0x70, 0x5E, //B 10, 11
    0x06, 0x50, 0x6E, //B 12, 13
    0x07, 0x40, 0x7B, //B 14, 15
    0x08, 0x20, 0x88, //B 16, 17
    0x08, 0xD0, 0x93, //B 18, 19
    0x09, 0xA0, 0xA0, //B 20, 21
    0x0A, 0x50, 0xA9, //B 22, 23
    0x0B, 0x00, 0xB4, //B 24, 25
    0x0B, 0xA0, 0xBF, //B 26, 27
    0x0C, 0x40, 0xC9, //B 28, 29
    0x0C, 0xE0, 0xD4, //B 30, 31
    0x0D, 0x80, 0xDD, //B 32, 33
    0x0E, 0x30, 0xE7, //B 34, 35
    0x0E, 0xA0, 0xF0, //B 36, 37
    0x0F, 0x40, 0xF8, //B 38, 39
    0x0F, 0xC1, 0x01, //B 40, 41
    0x10, 0x61, 0x0B, //B 42, 43
    0x11, 0x01, 0x14, //B 44, 45
    0x11, 0xA1, 0x1E, //B 46, 47
    0x12, 0x31, 0x27, //B 48, 49
    0x12, 0xD1, 0x32, //B 50, 51
    0x13, 0x71, 0x3B, //B 52, 53
    0x14, 0x01, 0x47, //B 54, 55
    0x14, 0xD1, 0x50, //B 56, 57
    0x15, 0x51, 0x5B, //B 58, 59
    0x15, 0xF1, 0x63, //B 60, 61
    0x16, 0x91, 0x6C, //B 62, 63
    0x17, 0x01, 0x76, //B 64, 65
    0x17, 0x91, 0x7E, //B 66, 67
    0x18, 0x31, 0x87, //B 68, 69
    0x18, 0xC1, 0x90, //B 70, 71
    0x19, 0x31, 0x99, //B 72, 73
    0x19, 0xD1, 0xA0, //B 74, 75
    0x1A, 0x31, 0xAA, //B 76, 77
    0x1A, 0xD1, 0xB1, //B 78, 79
    0x1B, 0x51, 0xBA, //B 80, 81
    0x1B, 0xE1, 0xC3, //B 82, 83
    0x1C, 0x71, 0xCA, //B 84, 85
    0x1C, 0xE1, 0xD3, //B 86, 87
    0x1D, 0x71, 0xDC, //B 88, 89
    0x1D, 0xF1, 0xE3, //B 90, 91
    0x1E, 0x61, 0xEA, //B 92, 93
    0x1E, 0xE1, 0xF2, //B 94, 95
    0x1F, 0x81, 0xFB, //B 96, 97
    0x1F, 0xF2, 0x02, //B 98, 99
    0x20, 0x62, 0x0B, //B 100, 101
    0x20, 0xE2, 0x11, //B 102, 103
    0x21, 0x32, 0x19, //B 104, 105
    0x21, 0xC2, 0x1F, //B 106, 107
    0x22, 0x42, 0x27, //B 108, 109
    0x22, 0xB2, 0x2F, //B 110, 111
    0x23, 0x32, 0x37, //B 112, 113
    0x23, 0xA2, 0x3F, //B 114, 115
    0x24, 0x32, 0x46, //B 116, 117
    0x24, 0x92, 0x4C, //B 118, 119
    0x25, 0x02, 0x55, //B 120, 121
    0x25, 0x82, 0x5C, //B 122, 123
    0x25, 0xF2, 0x62, //B 124, 125
    0x26, 0x52, 0x68, //B 126, 127
    0x26, 0xD2, 0x70, //B 128, 129
    0x27, 0x42, 0x78, //B 130, 131
    0x27, 0xC2, 0x7F, //B 132, 133
    0x28, 0x22, 0x85, //B 134, 135
    0x28, 0x82, 0x8B, //B 136, 137
    0x28, 0xE2, 0x91, //B 138, 139
    0x29, 0x62, 0x9A, //B 140, 141
    0x29, 0xD2, 0xA0, //B 142, 143
    0x2A, 0x52, 0xA7, //B 144, 145
    0x2A, 0xA2, 0xAE, //B 146, 147
    0x2B, 0x22, 0xB5, //B 148, 149
    0x2B, 0x82, 0xBB, //B 150, 151
    0x2B, 0xE2, 0xC1, //B 152, 153
    0x2C, 0x42, 0xC7, //B 154, 155
    0x2C, 0xA2, 0xD0, //B 156, 157
    0x2D, 0x32, 0xD5, //B 158, 159
    0x2D, 0x82, 0xDB, //B 160, 161
    0x2D, 0xF2, 0xE2, //B 162, 163
    0x2E, 0x52, 0xE7, //B 164, 165
    0x2E, 0xB2, 0xEE, //B 166, 167
    0x2F, 0x12, 0xF4, //B 168, 169
    0x2F, 0x92, 0xFB, //B 170, 171
    0x2F, 0xF3, 0x02, //B 172, 173
    0x30, 0x43, 0x06, //B 174, 175
    0x30, 0x93, 0x0D, //B 176, 177
    0x31, 0x03, 0x13, //B 178, 179
    0x31, 0x63, 0x19, //B 180, 181
    0x31, 0xC3, 0x1E, //B 182, 183
    0x32, 0x13, 0x24, //B 184, 185
    0x32, 0x63, 0x29, //B 186, 187
    0x32, 0xC3, 0x2F, //B 188, 189
    0x33, 0x13, 0x33, //B 190, 191
    0x33, 0x63, 0x39, //B 192, 193
    0x33, 0xC3, 0x40, //B 194, 195
    0x34, 0x33, 0x45, //B 196, 197
    0x34, 0x83, 0x4A, //B 198, 199
    0x34, 0xD3, 0x50, //B 200, 201
    0x35, 0x23, 0x55, //B 202, 203
    0x35, 0x83, 0x5A, //B 204, 205
    0x35, 0xC3, 0x60, //B 206, 207
    0x36, 0x43, 0x67, //B 208, 209
    0x36, 0xA3, 0x6D, //B 210, 211
    0x37, 0x03, 0x72, //B 212, 213
    0x37, 0x53, 0x78, //B 214, 215
    0x37, 0xA3, 0x7D, //B 216, 217
    0x38, 0x03, 0x82, //B 218, 219
    0x38, 0x43, 0x88, //B 220, 221
    0x38, 0xA3, 0x8C, //B 222, 223
    0x39, 0x03, 0x92, //B 224, 225
    0x39, 0x43, 0x98, //B 226, 227
    0x39, 0xA3, 0x9C, //B 228, 229
    0x39, 0xF3, 0xA1, //B 230, 231
    0x3A, 0x33, 0xA5, //B 232, 233
    0x3A, 0x63, 0xA8, //B 234, 235
    0x3A, 0xA3, 0xAC, //B 236, 237
    0x3A, 0xE3, 0xB0, //B 238, 239
    0x3B, 0x23, 0xB5, //B 240, 241
    0x3B, 0x73, 0xB9, //B 242, 243
    0x3B, 0xB3, 0xBE, //B 244, 245
    0x3C, 0x03, 0xC3, //B 246, 247
    0x3C, 0x63, 0xC8, //B 248, 249
    0x3C, 0xC3, 0xCF, //B 250, 251
    0x3D, 0x33, 0xD8, //B 252, 253
    0x3D, 0xE3, 0xFC, //B 254, 255
    0x3F, 0xC0, 0x00, //B 256
};
