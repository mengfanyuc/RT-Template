#include "bsp_led.h"
#include <board.h>

#define LEDG_PIN    GET_PIN(H, 11)

void bsp_led_entry(void *parameter)
{
    rt_pin_mode(LEDG_PIN, PIN_MODE_OUTPUT);
    
    while (1)
    {
        rt_pin_write(LEDG_PIN, PIN_HIGH);
        rt_thread_mdelay(250);
        rt_pin_write(LEDG_PIN, PIN_LOW);
        rt_thread_mdelay(250);
    }
}