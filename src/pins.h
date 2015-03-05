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

/* SPI port definitions */
#define SCK  PB5
#define MISO PB4
#define MOSI PB3
#define SS   PB2

/* LED pin definitions */
#define POWR_BLU PD7
#define VOTE_RED PD6
#define VOTE_GRN PD5
#define BATT_RED PD4

/* Button pin definitions */
#define BUTTON_D   PC5
#define BUTTON_E   PC4
#define BUTTON_C   PC3
#define BUTTON_B   PC2
#define BUTTON_A   PC1
#define BUTTON_PWR PC0

/* Radio interface definition */
#define R_SWITCH  PD3
#define R_PATTERN PD2
#define R_DATA    PD1
#define R_DCLK    PD0
