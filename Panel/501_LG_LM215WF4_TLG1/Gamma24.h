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
// ID Code      : Gamma24.h No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// GAMMA 2.4
//****************************************************************************
BYTE code tLUTGAMMA_24_TABLE[] =
{
    0x00, 0x00, 0x00, //R 0, 1
    0x00, 0x10, 0x02, //R 2, 3
    0x00, 0x40, 0x09, //R 4, 5
    0x00, 0xD0, 0x10, //R 6, 7
    0x01, 0x50, 0x1A, //R 8, 9
    0x01, 0xF0, 0x23, //R 10, 11
    0x02, 0x70, 0x2A, //R 12, 13
    0x02, 0xE0, 0x32, //R 14, 15
    0x03, 0x60, 0x39, //R 16, 17
    0x03, 0xD0, 0x42, //R 18, 19
    0x04, 0x60, 0x4B, //R 20, 21
    0x04, 0xE0, 0x51, //R 22, 23
    0x05, 0x60, 0x5A, //R 24, 25
    0x05, 0xE0, 0x61, //R 26, 27
    0x06, 0x50, 0x69, //R 28, 29
    0x06, 0xE0, 0x72, //R 30, 31
    0x07, 0x50, 0x79, //R 32, 33
    0x07, 0xE0, 0x82, //R 34, 35
    0x08, 0x50, 0x89, //R 36, 37
    0x08, 0xE0, 0x92, //R 38, 39
    0x09, 0x70, 0x9B, //R 40, 41
    0x0A, 0x00, 0xA4, //R 42, 43
    0x0A, 0x80, 0xAB, //R 44, 45
    0x0A, 0xF0, 0xB3, //R 46, 47
    0x0B, 0x70, 0xBB, //R 48, 49
    0x0C, 0x00, 0xC3, //R 50, 51
    0x0C, 0x50, 0xC9, //R 52, 53
    0x0C, 0xD0, 0xD1, //R 54, 55
    0x0D, 0x50, 0xD9, //R 56, 57
    0x0D, 0xD0, 0xE1, //R 58, 59
    0x0E, 0x40, 0xE7, //R 60, 61
    0x0E, 0xB0, 0xF0, //R 62, 63
    0x0F, 0x30, 0xF6, //R 64, 65
    0x0F, 0xA0, 0xFE, //R 66, 67
    0x10, 0x11, 0x06, //R 68, 69
    0x10, 0x91, 0x0D, //R 70, 71
    0x11, 0x11, 0x16, //R 72, 73
    0x11, 0xB1, 0x1E, //R 74, 75
    0x12, 0x21, 0x26, //R 76, 77
    0x12, 0xB1, 0x2E, //R 78, 79
    0x13, 0x21, 0x37, //R 80, 81
    0x13, 0xB1, 0x40, //R 82, 83
    0x14, 0x61, 0x4B, //R 84, 85
    0x14, 0xE1, 0x52, //R 86, 87
    0x15, 0x71, 0x5B, //R 88, 89
    0x15, 0xF1, 0x64, //R 90, 91
    0x16, 0x81, 0x6B, //R 92, 93
    0x16, 0xF1, 0x73, //R 94, 95
    0x17, 0x71, 0x7C, //R 96, 97
    0x18, 0x01, 0x84, //R 98, 99
    0x18, 0x81, 0x8D, //R 100, 101
    0x19, 0x11, 0x94, //R 102, 103
    0x19, 0x81, 0x9C, //R 104, 105
    0x1A, 0x01, 0xA3, //R 106, 107
    0x1A, 0x91, 0xAC, //R 108, 109
    0x1B, 0x01, 0xB5, //R 110, 111
    0x1B, 0x91, 0xBD, //R 112, 113
    0x1C, 0x01, 0xC5, //R 114, 115
    0x1C, 0x81, 0xCC, //R 116, 117
    0x1D, 0x11, 0xD5, //R 118, 119
    0x1D, 0x81, 0xDD, //R 120, 121
    0x1E, 0x11, 0xE4, //R 122, 123
    0x1E, 0x81, 0xED, //R 124, 125
    0x1F, 0x11, 0xF5, //R 126, 127
    0x1F, 0x91, 0xFD, //R 128, 129
    0x20, 0x02, 0x04, //R 130, 131
    0x20, 0x92, 0x0C, //R 132, 133
    0x20, 0xF2, 0x12, //R 134, 135
    0x21, 0x72, 0x1B, //R 136, 137
    0x21, 0xF2, 0x23, //R 138, 139
    0x22, 0x72, 0x2C, //R 140, 141
    0x22, 0xF2, 0x33, //R 142, 143
    0x23, 0x72, 0x3B, //R 144, 145
    0x23, 0xF2, 0x43, //R 146, 147
    0x24, 0x72, 0x4C, //R 148, 149
    0x24, 0xF2, 0x53, //R 150, 151
    0x25, 0x72, 0x5B, //R 152, 153
    0x25, 0xE2, 0x61, //R 154, 155
    0x26, 0x52, 0x69, //R 156, 157
    0x26, 0xD2, 0x71, //R 158, 159
    0x27, 0x52, 0x79, //R 160, 161
    0x27, 0xD2, 0x81, //R 162, 163
    0x28, 0x52, 0x88, //R 164, 165
    0x28, 0xB2, 0x8E, //R 166, 167
    0x29, 0x22, 0x96, //R 168, 169
    0x29, 0xA2, 0x9D, //R 170, 171
    0x2A, 0x12, 0xA6, //R 172, 173
    0x2A, 0xA2, 0xAE, //R 174, 175
    0x2B, 0x22, 0xB6, //R 176, 177
    0x2B, 0xA2, 0xBD, //R 178, 179
    0x2C, 0x12, 0xC5, //R 180, 181
    0x2C, 0x82, 0xCB, //R 182, 183
    0x2D, 0x02, 0xD4, //R 184, 185
    0x2D, 0x72, 0xDD, //R 186, 187
    0x2E, 0x02, 0xE3, //R 188, 189
    0x2E, 0x62, 0xEB, //R 190, 191
    0x2E, 0xE2, 0xF1, //R 192, 193
    0x2F, 0x42, 0xF9, //R 194, 195
    0x2F, 0xD3, 0x02, //R 196, 197
    0x30, 0x53, 0x08, //R 198, 199
    0x30, 0xC3, 0x10, //R 200, 201
    0x31, 0x33, 0x16, //R 202, 203
    0x31, 0xA3, 0x1F, //R 204, 205
    0x32, 0x23, 0x25, //R 206, 207
    0x32, 0x83, 0x2C, //R 208, 209
    0x32, 0xF3, 0x33, //R 210, 211
    0x33, 0x63, 0x3A, //R 212, 213
    0x33, 0xE3, 0x42, //R 214, 215
    0x34, 0x63, 0x48, //R 216, 217
    0x34, 0xB3, 0x51, //R 218, 219
    0x35, 0x43, 0x57, //R 220, 221
    0x35, 0xB3, 0x5E, //R 222, 223
    0x36, 0x13, 0x66, //R 224, 225
    0x36, 0xA3, 0x6D, //R 226, 227
    0x37, 0x23, 0x76, //R 228, 229
    0x37, 0x93, 0x7C, //R 230, 231
    0x38, 0x03, 0x83, //R 232, 233
    0x38, 0x93, 0x8C, //R 234, 235
    0x39, 0x13, 0x95, //R 236, 237
    0x39, 0x93, 0x9D, //R 238, 239
    0x3A, 0x13, 0xA3, //R 240, 241
    0x3A, 0x83, 0xAB, //R 242, 243
    0x3A, 0xE3, 0xB4, //R 244, 245
    0x3B, 0xC3, 0xC2, //R 246, 247
    0x3C, 0x83, 0xD0, //R 248, 249
    0x3D, 0x83, 0xE0, //R 250, 251
    0x3E, 0x63, 0xED, //R 252, 253
    0x3F, 0x63, 0xFC, //R 254, 255
    0x3F, 0xC0, 0x00, //R 256

    0x00, 0x00, 0x00, //G 0, 1
    0x00, 0x20, 0x04, //G 2, 3
    0x00, 0x80, 0x0C, //G 4, 5
    0x01, 0x10, 0x14, //G 6, 7
    0x01, 0x90, 0x1E, //G 8, 9
    0x02, 0x20, 0x26, //G 10, 11
    0x02, 0xA0, 0x2F, //G 12, 13
    0x03, 0x20, 0x36, //G 14, 15
    0x03, 0xB0, 0x3F, //G 16, 17
    0x04, 0x30, 0x47, //G 18, 19
    0x04, 0xB0, 0x50, //G 20, 21
    0x05, 0x30, 0x57, //G 22, 23
    0x05, 0xC0, 0x60, //G 24, 25
    0x06, 0x30, 0x67, //G 26, 27
    0x06, 0xC0, 0x70, //G 28, 29
    0x07, 0x30, 0x78, //G 30, 31
    0x07, 0xC0, 0x80, //G 32, 33
    0x08, 0x40, 0x89, //G 34, 35
    0x08, 0xD0, 0x91, //G 36, 37
    0x09, 0x50, 0x9A, //G 38, 39
    0x09, 0xE0, 0xA2, //G 40, 41
    0x0A, 0x60, 0xAA, //G 42, 43
    0x0A, 0xE0, 0xB2, //G 44, 45
    0x0B, 0x60, 0xBA, //G 46, 47
    0x0B, 0xE0, 0xC2, //G 48, 49
    0x0C, 0x60, 0xCA, //G 50, 51
    0x0C, 0xE0, 0xD2, //G 52, 53
    0x0D, 0x60, 0xDA, //G 54, 55
    0x0D, 0xE0, 0xE2, //G 56, 57
    0x0E, 0x60, 0xEA, //G 58, 59
    0x0E, 0xE0, 0xF1, //G 60, 61
    0x0F, 0x50, 0xF9, //G 62, 63
    0x0F, 0xD1, 0x00, //G 64, 65
    0x10, 0x41, 0x09, //G 66, 67
    0x10, 0xD1, 0x11, //G 68, 69
    0x11, 0x51, 0x1A, //G 70, 71
    0x11, 0xF1, 0x22, //G 72, 73
    0x12, 0x71, 0x2C, //G 74, 75
    0x13, 0x01, 0x33, //G 76, 77
    0x13, 0x81, 0x3D, //G 78, 79
    0x14, 0x11, 0x45, //G 80, 81
    0x14, 0xA1, 0x4E, //G 82, 83
    0x15, 0x21, 0x57, //G 84, 85
    0x15, 0xC1, 0x5F, //G 86, 87
    0x16, 0x31, 0x68, //G 88, 89
    0x16, 0xC1, 0x70, //G 90, 91
    0x17, 0x41, 0x79, //G 92, 93
    0x17, 0xD1, 0x81, //G 94, 95
    0x18, 0x61, 0x8A, //G 96, 97
    0x18, 0xF1, 0x92, //G 98, 99
    0x19, 0x61, 0x9B, //G 100, 101
    0x19, 0xF1, 0xA2, //G 102, 103
    0x1A, 0x71, 0xAB, //G 104, 105
    0x1A, 0xF1, 0xB3, //G 106, 107
    0x1B, 0x71, 0xBC, //G 108, 109
    0x1C, 0x01, 0xC3, //G 110, 111
    0x1C, 0x81, 0xCC, //G 112, 113
    0x1D, 0x01, 0xD4, //G 114, 115
    0x1D, 0x91, 0xDD, //G 116, 117
    0x1E, 0x11, 0xE5, //G 118, 119
    0x1E, 0x91, 0xED, //G 120, 121
    0x1F, 0x11, 0xF5, //G 122, 123
    0x1F, 0xA1, 0xFE, //G 124, 125
    0x20, 0x22, 0x05, //G 126, 127
    0x20, 0x92, 0x0D, //G 128, 129
    0x21, 0x12, 0x14, //G 130, 131
    0x21, 0x92, 0x1E, //G 132, 133
    0x22, 0x12, 0x25, //G 134, 135
    0x22, 0xA2, 0x2E, //G 136, 137
    0x23, 0x22, 0x36, //G 138, 139
    0x23, 0xA2, 0x3E, //G 140, 141
    0x24, 0x22, 0x45, //G 142, 143
    0x24, 0xA2, 0x4E, //G 144, 145
    0x25, 0x12, 0x55, //G 146, 147
    0x25, 0xA2, 0x5E, //G 148, 149
    0x26, 0x12, 0x65, //G 150, 151
    0x26, 0x92, 0x6D, //G 152, 153
    0x27, 0x12, 0x74, //G 154, 155
    0x27, 0x92, 0x7E, //G 156, 157
    0x28, 0x12, 0x84, //G 158, 159
    0x28, 0x92, 0x8D, //G 160, 161
    0x29, 0x02, 0x94, //G 162, 163
    0x29, 0x82, 0x9D, //G 164, 165
    0x2A, 0x02, 0xA4, //G 166, 167
    0x2A, 0x82, 0xAD, //G 168, 169
    0x2B, 0x02, 0xB3, //G 170, 171
    0x2B, 0x82, 0xBC, //G 172, 173
    0x2C, 0x02, 0xC3, //G 174, 175
    0x2C, 0x72, 0xCB, //G 176, 177
    0x2C, 0xF2, 0xD2, //G 178, 179
    0x2D, 0x62, 0xDA, //G 180, 181
    0x2D, 0xE2, 0xE1, //G 182, 183
    0x2E, 0x52, 0xE9, //G 184, 185
    0x2E, 0xD2, 0xF1, //G 186, 187
    0x2F, 0x42, 0xF8, //G 188, 189
    0x2F, 0xD3, 0x00, //G 190, 191
    0x30, 0x33, 0x07, //G 192, 193
    0x30, 0xB3, 0x0E, //G 194, 195
    0x31, 0x13, 0x14, //G 196, 197
    0x31, 0x93, 0x1D, //G 198, 199
    0x32, 0x03, 0x22, //G 200, 201
    0x32, 0x63, 0x2A, //G 202, 203
    0x32, 0xD3, 0x30, //G 204, 205
    0x33, 0x33, 0x37, //G 206, 207
    0x33, 0xB3, 0x3F, //G 208, 209
    0x34, 0x23, 0x45, //G 210, 211
    0x34, 0x93, 0x4D, //G 212, 213
    0x35, 0x03, 0x53, //G 214, 215
    0x35, 0x63, 0x5B, //G 216, 217
    0x35, 0xE3, 0x61, //G 218, 219
    0x36, 0x43, 0x68, //G 220, 221
    0x36, 0xD3, 0x70, //G 222, 223
    0x37, 0x33, 0x76, //G 224, 225
    0x37, 0xA3, 0x7E, //G 226, 227
    0x38, 0x13, 0x84, //G 228, 229
    0x38, 0x83, 0x8C, //G 230, 231
    0x38, 0xF3, 0x92, //G 232, 233
    0x39, 0x63, 0x9A, //G 234, 235
    0x39, 0xE3, 0xA1, //G 236, 237
    0x3A, 0x43, 0xA8, //G 238, 239
    0x3A, 0xC3, 0xB0, //G 240, 241
    0x3B, 0x33, 0xB7, //G 242, 243
    0x3B, 0xB3, 0xBF, //G 244, 245
    0x3C, 0x23, 0xC7, //G 246, 247
    0x3C, 0xB3, 0xD0, //G 248, 249
    0x3D, 0x73, 0xE4, //G 250, 251
    0x3E, 0xC3, 0xF0, //G 252, 253
    0x3F, 0x63, 0xFC, //G 254, 255
    0x3F, 0xC0, 0x00, //G 256

    0x00, 0x00, 0x00, //B 0, 1
    0x00, 0x10, 0x03, //B 2, 3
    0x00, 0x60, 0x09, //B 4, 5
    0x00, 0xC0, 0x0F, //B 6, 7
    0x01, 0x50, 0x19, //B 8, 9
    0x01, 0xC0, 0x22, //B 10, 11
    0x02, 0x80, 0x2D, //B 12, 13
    0x03, 0x00, 0x35, //B 14, 15
    0x03, 0x90, 0x40, //B 16, 17
    0x04, 0x30, 0x48, //B 18, 19
    0x04, 0xB0, 0x51, //B 20, 21
    0x05, 0x50, 0x5A, //B 22, 23
    0x05, 0xE0, 0x62, //B 24, 25
    0x06, 0x60, 0x6D, //B 26, 27
    0x07, 0x10, 0x75, //B 28, 29
    0x07, 0x90, 0x7E, //B 30, 31
    0x08, 0x20, 0x87, //B 32, 33
    0x08, 0xA0, 0x8F, //B 34, 35
    0x09, 0x30, 0x99, //B 36, 37
    0x09, 0xB0, 0xA1, //B 38, 39
    0x0A, 0x40, 0xA7, //B 40, 41
    0x0A, 0xB0, 0xB0, //B 42, 43
    0x0B, 0x30, 0xB6, //B 44, 45
    0x0B, 0xC0, 0xBF, //B 46, 47
    0x0C, 0x30, 0xC7, //B 48, 49
    0x0C, 0xB0, 0xCF, //B 50, 51
    0x0D, 0x40, 0xD7, //B 52, 53
    0x0D, 0xB0, 0xE0, //B 54, 55
    0x0E, 0x40, 0xE7, //B 56, 57
    0x0E, 0xA0, 0xED, //B 58, 59
    0x0F, 0x20, 0xF5, //B 60, 61
    0x0F, 0x90, 0xFC, //B 62, 63
    0x10, 0x11, 0x04, //B 64, 65
    0x10, 0x91, 0x0D, //B 66, 67
    0x11, 0x21, 0x16, //B 68, 69
    0x11, 0xA1, 0x1E, //B 70, 71
    0x12, 0x21, 0x26, //B 72, 73
    0x12, 0xA1, 0x31, //B 74, 75
    0x13, 0x41, 0x39, //B 76, 77
    0x13, 0xC1, 0x41, //B 78, 79
    0x14, 0x81, 0x4D, //B 80, 81
    0x15, 0x01, 0x55, //B 82, 83
    0x15, 0x81, 0x5E, //B 84, 85
    0x16, 0x21, 0x67, //B 86, 87
    0x16, 0xA1, 0x6E, //B 88, 89
    0x17, 0x41, 0x77, //B 90, 91
    0x17, 0xB1, 0x80, //B 92, 93
    0x18, 0x41, 0x88, //B 94, 95
    0x18, 0xD1, 0x91, //B 96, 97
    0x19, 0x51, 0x9A, //B 98, 99
    0x19, 0xE1, 0xA1, //B 100, 101
    0x1A, 0x41, 0xAA, //B 102, 103
    0x1A, 0xE1, 0xB2, //B 104, 105
    0x1B, 0x61, 0xBB, //B 106, 107
    0x1B, 0xF1, 0xC4, //B 108, 109
    0x1C, 0x81, 0xCB, //B 110, 111
    0x1C, 0xF1, 0xD5, //B 112, 113
    0x1D, 0x81, 0xDD, //B 114, 115
    0x1E, 0x11, 0xE5, //B 116, 117
    0x1E, 0x81, 0xEC, //B 118, 119
    0x1F, 0x11, 0xF5, //B 120, 121
    0x1F, 0xA1, 0xFE, //B 122, 123
    0x20, 0x12, 0x05, //B 124, 125
    0x20, 0xA2, 0x0E, //B 126, 127
    0x21, 0x12, 0x14, //B 128, 129
    0x21, 0xA2, 0x1D, //B 130, 131
    0x22, 0x12, 0x26, //B 132, 133
    0x22, 0x92, 0x2D, //B 134, 135
    0x23, 0x22, 0x36, //B 136, 137
    0x23, 0xA2, 0x3F, //B 138, 139
    0x24, 0x32, 0x47, //B 140, 141
    0x24, 0xA2, 0x4E, //B 142, 143
    0x25, 0x32, 0x57, //B 144, 145
    0x25, 0xB2, 0x5E, //B 146, 147
    0x26, 0x22, 0x65, //B 148, 149
    0x26, 0x92, 0x6E, //B 150, 151
    0x27, 0x22, 0x76, //B 152, 153
    0x27, 0xB2, 0x7F, //B 154, 155
    0x28, 0x22, 0x85, //B 156, 157
    0x28, 0x92, 0x8C, //B 158, 159
    0x28, 0xF2, 0x94, //B 160, 161
    0x29, 0x92, 0x9D, //B 162, 163
    0x2A, 0x02, 0xA5, //B 164, 165
    0x2A, 0x82, 0xAD, //B 166, 167
    0x2B, 0x12, 0xB5, //B 168, 169
    0x2B, 0x82, 0xBC, //B 170, 171
    0x2B, 0xF2, 0xC3, //B 172, 173
    0x2C, 0x72, 0xCA, //B 174, 175
    0x2D, 0x12, 0xD4, //B 176, 177
    0x2D, 0x72, 0xDB, //B 178, 179
    0x2D, 0xF2, 0xE2, //B 180, 181
    0x2E, 0x52, 0xE9, //B 182, 183
    0x2E, 0xD2, 0xF1, //B 184, 185
    0x2F, 0x42, 0xF9, //B 186, 187
    0x2F, 0xC3, 0x01, //B 188, 189
    0x30, 0x43, 0x07, //B 190, 191
    0x30, 0xA3, 0x0F, //B 192, 193
    0x31, 0x23, 0x16, //B 194, 195
    0x31, 0xA3, 0x1D, //B 196, 197
    0x32, 0x03, 0x24, //B 198, 199
    0x32, 0x63, 0x2A, //B 200, 201
    0x32, 0xE3, 0x31, //B 202, 203
    0x33, 0x33, 0x37, //B 204, 205
    0x33, 0xB3, 0x3F, //B 206, 207
    0x34, 0x33, 0x46, //B 208, 209
    0x34, 0x93, 0x4C, //B 210, 211
    0x35, 0x03, 0x53, //B 212, 213
    0x35, 0x63, 0x59, //B 214, 215
    0x35, 0xC3, 0x61, //B 216, 217
    0x36, 0x53, 0x69, //B 218, 219
    0x36, 0xB3, 0x6F, //B 220, 221
    0x37, 0x33, 0x77, //B 222, 223
    0x37, 0xA3, 0x7D, //B 224, 225
    0x38, 0x13, 0x83, //B 226, 227
    0x38, 0x73, 0x8A, //B 228, 229
    0x38, 0xE3, 0x91, //B 230, 231
    0x39, 0x43, 0x99, //B 232, 233
    0x39, 0xB3, 0x9E, //B 234, 235
    0x3A, 0x13, 0xA3, //B 236, 237
    0x3A, 0x63, 0xA8, //B 238, 239
    0x3A, 0xB3, 0xAD, //B 240, 241
    0x3B, 0x03, 0xB2, //B 242, 243
    0x3B, 0x53, 0xB8, //B 244, 245
    0x3B, 0xB3, 0xBE, //B 246, 247
    0x3C, 0x13, 0xC4, //B 248, 249
    0x3C, 0x83, 0xCC, //B 250, 251
    0x3D, 0x13, 0xD6, //B 252, 253
    0x3D, 0xC3, 0xFC, //B 254, 255
    0x3F, 0xC0, 0x00, //B 256
};
