# TizenRT-PIC32
Samsung TizenRT over Microchip PIC32

Version 0.00001

TizenRT is lightweight RTOS-based platform to support low-end IoT devices.

https://github.com/Samsung/TizenRT

Compiler: Windows MPLAB-X, XC32 (last version)

Board: Curiosity PIC32MZEF 

http://www.microchip.com/Developmenttools/ProductDetails/DM320104?utm_source=MicroSolutions&utm_medium=Link&utm_term=FY19Q1&utm_content=Development%2BTools&utm_campaign=Article

Problems:

Windows MPLAB-X is dependent on cmd.exe, that has a 32k limit and can not compile the source.

Workaround: I merge some files (functions from libc folder) by folders with simple BAT file

copy *.c output.c

This is not the best solutions, but for this experiments...can be


