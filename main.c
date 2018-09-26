#include <stdio.h>

int green_led(int argc, char *argv[]){
    printf("[APP] Task 'green' begin.\n");
    while (1) {
        up_mdelay(500);
        led_g(1);
        up_mdelay(500);
        led_g(0);
        printf("[APP] LOOP\n");
        sleep(5);        
    }
}

int user_main(int argc, char *argv[]) {
    printf("[APP] Task 'main' begin.\n");
    task_create("green", 100, 2048, green_led, 0);
    printf("[APP] Samsung TizenRT over Curiosity PIC32MZ 2018 Georgi Angelov\n");    
    leds_off();
    while (1) {
        up_mdelay(100);
        led_o(1);
        up_mdelay(100);
        led_o(0);
        usleep(1);        
    }
}