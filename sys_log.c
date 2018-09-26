#include "sys_log.h"
//#include <proc/p32mz2048efm100.h>

void _mon_putc(char c) {
    up_lowputc(c);
}

void hal_log_s(char * s) {
    if (s)
        while (*s)
            _mon_putc(*s++);
}

int Printf(const char * frm, ...) {
    va_list ar;
    va_start(ar, frm);
    vprintf(frm, ar); //---> _mon_putc
    va_end(ar);
    return 0;
}

void PrintHex(char * begin, char * buffer, int size, char * end) {
    if (begin) Printf(begin);
    int i = 0;
    while (size--)
        Printf("%02X", buffer[i++]&0xFF);
    if (end) Printf(end);
}