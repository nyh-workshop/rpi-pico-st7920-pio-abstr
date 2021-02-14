#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
// Our assembled program:
#include "st7920_4bp.pio.h"
#include "pico_st7920_pio_driver.h"

#include "st7920.h"
#include "picture.h"

const uint E_PIN = 15;
const uint RS_PIN = 14;
const uint RST_PIN = 22;
const uint D4_PIN = 18;

extern "C" {
    int main();
}

int main()
{   
    const uint LED_PIN = 25;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    stdio_init_all();

    pp_st7920 pico_pio_st7920(D4_PIN, E_PIN, RS_PIN, RST_PIN);
    ST7920 st7920(&pico_pio_st7920);

    st7920.init();

    st7920.writeText(0,0, (char*)"hello world!");
    st7920.writeText(0,1, (char*)"raspberry pico");

    sleep_ms(3000);

    st7920.command(0x01);
    st7920.graphics(true);
    st7920.clearScreen();
    st7920.fillBitmap((uint8_t*)graphic);
    
    while(1) {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    }

    return 0;
}
