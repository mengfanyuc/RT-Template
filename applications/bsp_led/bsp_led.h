/*
 * @Description: 
 * @Version: 1.0
 * @Autor: mengfanyu
 * @Date: 2020-03-24 12:36:11
 */
#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#define RT_LED_THREAD_STACK_SIZE        512
#define RT_LED_THREAD_PRIORITY          10
#define RT_LED_THREAD_TIMESLICE         10

void bsp_led_entry(void *parameter);

#endif