/*
    Copyright (C) 2014-2015  Forest Crossman <cyrozap@gmail.com>

    This file is part of freeclicker.

    freeclicker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    freeclicker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with freeclicker.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
    This file uses information from the Semtech XE1203F datasheet:
    http://www.semtech.com/images/datasheet/xe1203f.pdf
*/

#ifndef XE1203F_H_INCLUDED
#define XE1203F_H_INCLUDED

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


/** Command Definitions **/
#define WRITE 0
#define READ  1


/** Memory Map **/
#define ConfigSwitch 0x00
#define RTParam      0x01
#define FSParam      0x03
#define SWParam      0x06
#define DataOut      0x0C
#define ADParam      0x0E
#define Pattern      0x13
#define TParam       0x17


/** Bit Mnemonics **/
/* Byte 0x00 */
#define ConfigSwitch_config 7

/* Byte 0x01 */
#define RTParam_Bitsync     7
#define RTParam_Barker      6
#define RTParam_Rssi        5
#define RTParam_Rssir       4
#define RTParam_Fei         3
#define RTParam_BW          2
#define RTParam_Osc         1
#define RTParam_Clkout      0

/* Byte 0x02 */
#define RTParam_Stair       7
#define RTParam_Filter      6
#define RTParam_Modul       5
#define RTParam_IQAMP       4
#define RTParam_Switch_ext  3
#define RTParam_Pattern     2
#define RTParam_Band        0

/* Byte 0x03 */
#define FSParam_Dev         0

/* Byte 0x04 */
#define FSParam_Change_Osr  7
#define FSParam_Br          0

/* Byte 0x05 */
#define FSParam_OSR         0

/* Byte 0x06 */
#define SWParam_mode_1      6
#define SWParam_Power_1     4
#define SWParam_Rmode_1     3

/* Bytes 0x07-0x08 */
#define SWParam_Freq_1      0

/* Byte 0x09 */
#define SWParam_mode_2      6
#define SWParam_Power_2     4
#define SWParam_Rmode_2     3

/* Bytes 0x0a-0x0b */
#define SWParam_Freq_2      0

/* Byte 0x0c */
#define DataOut_Rssi        6
#define DataOut_MSB_fei     0

/* Byte 0x0d */
#define DataOut_LSB_fei     0

/* Byte 0x0e */
#define ADParam_Psize               6
#define ADParam_Ptol                4
#define ADParam_Clk_freq            2
#define ADParam_Invert              1
#define ADParam_RegBW               0

/* Byte 0x0f */
#define ADParam_Regfreq             7
#define ADParam_Regcond             6
#define ADParam_Xsel                5
#define ADParam_Resxosc             1
#define ADParam_enable_konnex       0

/* Byte 0x10 */
#define ADParam_Chge_thres          7
#define ADParam_Sync_thres          0

/* Byte 0x11 */
#define ADParam_disable_data_bidir  7
#define ADParam_Trac_thres          0

/* Byte 0x12 */
#define ADParam_Fix_bsync           7
#define ADParam_Sync_loss           0

/* Bytes 0x13-0x16 */
#define PATParam_Pattern    0

/* Byte 0x17 */
#define TParam_BW   3
#define TParam_HPF  0


/** Instruction Mnemonics **/
#define W_REGISTER    0x80
#define R_REGISTER    0xA0
#define NOP           0xFF


/** Function Definitions **/
void XE1203F_init(void);
unsigned char read_write_XE1203F(unsigned char mode, unsigned char reg, unsigned char val);


#endif /* XE1203F_H_INCLUDED */
