# TizenRT-PIC32
Samsung TizenRT over Microchip PIC32

TizenRT is lightweight RTOS-based platform to support low-end IoT devices.

https://github.com/Samsung/TizenRT

TizenRT based on the NuttX kernel and is a POSIX real-time operating system (RTOS) with an emphasis on standard compliance and a small footprint.


This Version 0.000012

Compiler: 
* Windows MPLAB-X, XC32 (last version)

Board: 
* Curiosity PIC32MZEF 

http://www.microchip.com/Developmenttools/ProductDetails/DM320104?utm_source=MicroSolutions&utm_medium=Link&utm_term=FY19Q1&utm_content=Development%2BTools&utm_campaign=Article

Problems:
* Windows MPLAB-X is dependent on cmd.exe, that has a 32k limit and can not compile the source.
* Linker script, now project can be beduged with simulator or/and board ICD
* pic32mz port... irq, Tizen/Nuttx use single mode interrupts

Workaround: 
* cmd.exe: I merge some files (functions from libc folder) by folders with simple BAT file

copy *.c output.c

This is not the best solutions, but for this experiments...can be

![ScreenShot](https://raw.githubusercontent.com/Wiz-IO/TizenRT-PIC32/master/TizenRT_PIC32MZ.png)


