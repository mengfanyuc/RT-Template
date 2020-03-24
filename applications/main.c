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

#include "main.h"

int main(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("bsp_led", bsp_led_entry, RT_NULL,
                           RT_LED_THREAD_STACK_SIZE, RT_LED_THREAD_PRIORITY, 20);
    RT_ASSERT(tid != RT_NULL);
    
    rt_thread_startup(tid);

    tid = rt_thread_create("bsp_lcd", bsp_lcd_entry, RT_NULL,
                           RT_LCD_THREAD_STACK_SIZE, RT_LCD_THREAD_PRIORITY, 20);
    RT_ASSERT(tid != RT_NULL);
    
    rt_thread_startup(tid);

    return RT_EOK;
}
