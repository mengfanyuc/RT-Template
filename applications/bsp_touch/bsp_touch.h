/*
 * @Description: 
 * @Version: 1.0
 * @Autor: mengfanyu
 * @Date: 2020-03-25 11:11:12
 */
#ifndef __BSP_TOUCH_H__
#define __BSP_TOUCH_H__

#include <board.h>

#define BSP_I2C2_SCL_PIN        GET_PIN(H, 4)
#define BSP_I2C2_SDA_PIN        GET_PIN(H, 5)

#define BSP_TOUCH_RST_PIN       GET_PIN(D, 13)
#define BSP_TOUCH_INT_PIN       GET_PIN(D, 12)

#define RT_TOUCH_THREAD_STACK_SIZE      1024
#define RT_TOUCH_THREAD_PRIORITY        10
#define RT_TOUCH_THREAD_TIMESLICE       10

void bsp_touch_entry(void *parameter);

#endif
