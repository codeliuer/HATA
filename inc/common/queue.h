/*************************************************************************
    > File Name: queue.h
    > Author: TOM
    > Mail: 18682303408@163.com
    > Function:
    > Created Time: Sat 21 May 2022 12:32:40 PM HKT
 ************************************************************************/

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdint.h>

#include "util.h"

typedef struct queue queue_t;
typedef struct oper oper_t;

// Single Single Write Unlocked Queue
typedef struct queue {
    int oper_nums;
    struct oper {
        uint32_t cap;
        uint32_t head;
        uint32_t tail;
        struct oper_t *prev;
        struct queue *handle;
    } EXCLUSIVE_CACHE_LINE *oper_t;

    void *data[];
} queue_t;

/*
 * 创建单独单写队列
 * @参数1：oper_nums [IN] 操作者数量
 * @参数2：cap [IN] 队列容量，必须是2的幂
 * @返回：NULL 失败，其他 队列句柄
 */
extern queue_t *queue_create(int oper_nums, uint32_t cap);
/*
 * 释放创建队列时申请的内存
 * @参数1：handle [IN] 队列句柄
 * @返回：= 0 成功释放，< 0 队列数据未消费完，无法释放队列
 */
extern int queue_destroy(queue_t *handle);

/*
 * 注册队列操作者
 * 每次调用返回下一个未被注册的操作者
 * @参数1：handle [IN] 队列句柄
 * @返回：NULL 操作者被注册完了，其他 操作者句柄
 */
static INLINE oper_t *queue_oper_register(queue_t *handle)
{
    return NULL;
}

/*
 * 解除队列操作者
 * 把操作者放回队列
 * @参数1：oper [IN] 操作者句柄
 * @返回：0 解除成功，< 0 消费者未消费完数据，解除失败
 */
static INLINE int queue_oper_unregister(oper_t *oper)
{
    return NULL;
}

/*
 * 操作者读队列指针数据
 * @参数1：oper [IN] 操作者句柄
 * @参数2：data [INOUT] 存放读取队列指针的指针数组
 * @参数3：nums [IN] 数组指针可以存放的指针最大个数，也就是可读取的指针最大个数
 * @返回：返回读取的指针个数，小于等于nums
 */
static INLINE int queue_read(oper_t *oper, void *data[], uint32_t nums)
{
    return 0;
}

/*
 * 操作者写数据指针进入队列
 * @参数1：oper [IN] 操作者句柄
 * @参数2：data [IN] 存放数据指针的数组
 * @参数3：nums [IN] 指针个数
 * @返回：返回写入指针个数，小于等于nums
 */
static INLINE int queue_write(oper_t *oper, void *data[], uint32_t nums)
{
    return 0;
}

/*
 * 操作者移动写者游标(操作者处理完nums个后，调用此接口直接移动游标，不写入指针值)
 * @参数1：oper [IN] 操作者指针
 * @参数2：nums [IN] 游标移动个数
 * @返回：移动的个数，小于等于nums
 */
static INLINE int queue_cursor(oper_t *oper, uint32_t nums)
{
    return 0;
}

#endif