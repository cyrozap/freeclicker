# freeclicker

[![Build Status](https://travis-ci.org/cyrozap/freeclicker.svg?branch=master)](https://travis-ci.org/cyrozap/freeclicker)

freeclicker is a free (as in freedom) re-implementation of the firmware used on
AVR-based i>clicker devices.

## Toolchain

### Ubuntu

The AVR toolchain, C libraries, and the avrdude downloader/uploader, can be
installed from the Ubuntu repositories:

    apt-get install gcc-avr avr-libc avrdude

## Building

1. Run `make`

2. The output files will be created in the 'build' folder

## Flashing

1. Modify the Makefile
  * Set PROGRAMMER to your programmer. This will be the `-c` option for avrdude
  * Set PORT to the port your programmer is on. This will be the `-P` option for
    avrdude

    By default, the Makefile will attempt to flash the i>clicker's ATmega8
    using a USBtiny programmer.

2. Connect your programmer to the i>clicker's ISP pins.

3. Run `make flash`. You may need to run this command as root (`sudo make
   flash`) or change the permissions of the USB port if your user cannot access
   the port.
