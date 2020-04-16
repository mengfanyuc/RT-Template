/*
 * @Description: 
 * @Version: 1.0
 * @Autor: mengfanyu
 * @Date: 2020-03-24 11:45:54
 */

#include "main.h"
#include <rtthread.h>

int main(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("bsp_led", bsp_led_entry, RT_NULL,
                           RT_LED_THREAD_STACK_SIZE, RT_LED_THREAD_PRIORITY, RT_LED_THREAD_TIMESLICE);
    RT_ASSERT(tid != RT_NULL);
    
    rt_thread_startup(tid);
    
    tid = rt_thread_create("bsp_lcd", bsp_lcd_entry, RT_NULL,
                           RT_LCD_THREAD_STACK_SIZE, RT_LCD_THREAD_PRIORITY, RT_LCD_THREAD_TIMESLICE);
    RT_ASSERT(tid != RT_NULL);
    
    rt_thread_startup(tid);

    tid = rt_thread_create("bsp_touch", bsp_touch_entry, RT_NULL,
                           RT_TOUCH_THREAD_STACK_SIZE, RT_TOUCH_THREAD_PRIORITY, RT_TOUCH_THREAD_TIMESLICE);
    RT_ASSERT(tid != RT_NULL);
    
    rt_thread_startup(tid);
    
    return RT_EOK;
}
