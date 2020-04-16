/*
 * @Description: 
 * @Version: 1.0
 * @Autor: mengfanyu
 * @Date: 2020-03-25 11:11:03
 */
#include "bsp_touch.h"
#include <board.h>
#include <touch.h>
#include "drv_gpio.h"

#define DBG_TAG "touch"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>

static rt_sem_t     gt9157_sem = RT_NULL;

static rt_err_t rx_callback(rt_device_t dev, rt_size_t size)
{
    rt_sem_release(gt9157_sem);
    rt_device_control(dev, RT_TOUCH_CTRL_DISABLE_INT, RT_NULL);
    return 0;
}

void bsp_touch_entry(void *parameter)
{
    void *id;
    void *arg;
    rt_device_t  dev;
    struct rt_touch_data *read_data;
    struct rt_touch_info info;

    dev = rt_device_find("gt9157");
    RT_ASSERT(dev != RT_NULL);

    if (rt_device_open(dev, RT_DEVICE_FLAG_INT_RX) != RT_EOK)
    {
        LOG_E("open device failed!");
        return;
    }

    id = rt_malloc(sizeof(rt_uint8_t) * 8);
    rt_device_control(dev, RT_TOUCH_CTRL_GET_ID, id);
    rt_uint8_t *read_id = (rt_uint8_t *)id;

    LOG_I("id = %d %d %d %d \n", read_id[0] - '0', read_id[1] - '0', read_id[2] - '0', read_id[3] - '0');

    rt_device_control(dev, RT_TOUCH_CTRL_LOAD_CONFIG, arg);

    rt_device_control(dev, RT_TOUCH_CTRL_GET_INFO, id);
    LOG_I("range_x = %d \n", (*(struct rt_touch_info*)id).range_x);
    LOG_I("range_y = %d \n", (*(struct rt_touch_info*)id).range_y);
    LOG_I("point_num = %d \n", (*(struct rt_touch_info*)id).point_num);
    rt_free(id);

    rt_device_set_rx_indicate(dev, rx_callback);

    gt9157_sem = rt_sem_create("dsem", 0, RT_IPC_FLAG_FIFO);
    RT_ASSERT(gt9157_sem != RT_NULL);

    rt_device_control(dev, RT_TOUCH_CTRL_GET_INFO, &info);

    read_data = (struct rt_touch_data *)rt_malloc(sizeof(struct rt_touch_data) * info.point_num);

    while (1)
    {
        rt_sem_take(gt9157_sem, RT_WAITING_FOREVER);

        if (rt_device_read(dev, 0, read_data, info.point_num) == info.point_num)
        {
            for (rt_uint8_t i = 0; i < info.point_num; i++)
            {
                if (read_data[i].event == RT_TOUCH_EVENT_DOWN || read_data[i].event == RT_TOUCH_EVENT_MOVE)
                {
                    LOG_I("%d %d %d %d %d\n", read_data[i].track_id,
                            read_data[i].x_coordinate,
                            read_data[i].y_coordinate,
                            read_data[i].timestamp,
                            read_data[i].width);
                }
            }
        }
        rt_device_control(dev, RT_TOUCH_CTRL_ENABLE_INT, RT_NULL);
    }
}

