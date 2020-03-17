/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 * 2018-11-19     flybreak     add stm32f429-fire-challenger bsp
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED */
#define LEDR_PIN    GET_PIN(H, 10)
#define LEDG_PIN    GET_PIN(H, 11)
#define LEDB_PIN    GET_PIN(H, 12)

int main(void)
{
    int count = 1;
    /* set LED pin mode to output */
    rt_pin_mode(LEDR_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LEDG_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(LEDB_PIN, PIN_MODE_OUTPUT);

    while (count++)
    {
        rt_pin_write(LEDR_PIN, PIN_HIGH);
        rt_pin_write(LEDG_PIN, PIN_LOW);
        rt_pin_write(LEDB_PIN, PIN_LOW);
        rt_thread_mdelay(250);
        rt_pin_write(LEDR_PIN, PIN_LOW);
        rt_pin_write(LEDG_PIN, PIN_HIGH);
        rt_pin_write(LEDB_PIN, PIN_LOW);
        rt_thread_mdelay(250);
        rt_pin_write(LEDR_PIN, PIN_LOW);
        rt_pin_write(LEDG_PIN, PIN_LOW);
        rt_pin_write(LEDB_PIN, PIN_HIGH);
        rt_thread_mdelay(250);
    }

    return RT_EOK;
}
