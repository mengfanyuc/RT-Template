#ifndef __BSP_LCD_H__
#define __BSP_LCD_H__

#include <board.h>

struct drv_lcd_device
{
    struct rt_device parent;

    struct rt_device_graphic_info lcd_info;

    struct rt_semaphore lcd_lock;

    rt_uint8_t cur_buf;
    rt_uint8_t *front_buf;
    rt_uint8_t *back_buf;
};

#define LCD_WIDTH           800
#define LCD_HEIGHT          480
#define LCD_BITS_PER_PIXEL  16
#define LCD_BUF_SIZE        (LCD_WIDTH * LCD_HEIGHT * LCD_BITS_PER_PIXEL / 8)
#define LCD_PIXEL_FORMAT    RTGRAPHIC_PIXEL_FORMAT_RGB565

#define LCD_HSYNC_WIDTH     2
#define LCD_VSYNC_HEIGHT    2
#define LCD_HBP             46
#define LCD_VBP             23
#define LCD_HFP             22
#define LCD_VFP             22

#define LCD_BACKLIGHT_USING_GPIO
#define LCD_BL_GPIO_NUM     GET_PIN(D, 7)
#define LCD_DISP_GPIO_NUM   GET_PIN(D, 4)

#define RT_LCD_THREAD_STACK_SIZE 512
#define RT_LCD_THREAD_PRIORITY 10

void bsp_lcd_entry(void *parameter);

#endif