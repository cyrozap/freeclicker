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

#include "pins.h"
#include "XE1203F.h"

void XE1203F_init(void)
{
    // This function does nothing at the moment
    return;
}

unsigned char read_write_spi_byte(unsigned char byte)
{
    cli(); // Disable interrupts

    SPDR = byte; // Load byte into data register

    while (!(SPSR & _BV(SPIF))); // Wait for transmission to finish

    sei(); // Re-enable interrupts

    return SPDR;
}

unsigned char read_write_XE1203F(unsigned char mode, unsigned char reg, unsigned char val)
{
    unsigned char retval = 0x00;

    if (mode == WRITE)
        reg |= W_REGISTER;
    else
        reg |= R_REGISTER;

    _delay_us(10); // Make sure last command was a while ago
    PORTB &= ~_BV(SS); // Set SS low - radio starts to listen for command
    _delay_us(10);
    read_write_spi_byte(reg); // Send the command and the register to the radio
    _delay_us(10);

    if (mode == READ)
        retval = read_write_spi_byte(NOP); // Send NOP once to read back the byte in the register
    else
        read_write_spi_byte(val); // Send byte to write in register

    _delay_us(10);

    PORTB |= _BV(SS);  // Set SS high - radio goes back to doing nothing

    return retval;
}
