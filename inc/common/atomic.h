/*************************************************************************
    > File Name: atomic.h
    > Author: TOM
    > Mail: 18682303408@163.com
    > Function:
    > Created Time: Sat 21 May 2022 12:45:43 PM HKT
 ************************************************************************/

#ifndef __ATOMIC_H__
#define __ATOMIC_H__

// 返回操作数的旧值
#define ATOMIC_FETCH_ADD(ptr, v) __sync_fetch_and_add(ptr, v)
#define ATOMIC_FETCH_SUB(ptr, v) __sync_fetch_and_sub(ptr, v)
#define ATOMIC_FETCH_OR(ptr, v) __sync_fetch_and_or(ptr, v)
#define ATOMIC_FETCH_AND(ptr, v) __sync_fetch_and_and(ptr, v)
#define ATOMIC_FETCH_XOR(ptr, v) __sync_fetch_and_xor(ptr, v)
#define ATOMIC_FETCH_NAND(ptr, v) __sync_fetch_and_xor(ptr, v)

// 返回操作数的新值
#define ATOMIC_ADD_FETCH(ptr, v) __sync_add_and_fetch(ptr, v)
#define ATOMIC_SUB_FETCH(ptr, v) __sync_sub_and_fetch(ptr, v)
#define ATOMIC_OR_FETCH(ptr, v) __sync_or_and_fetch(ptr, v)
#define ATOMIC_AND_FETCH(ptr, v) __sync_and_and_fetch(ptr, v)
#define ATOMIC_XOR_FETCH(ptr, v) __sync_xor_and_fetch(ptr, v)
#define ATOMIC_NAND_FETCH(ptr, v) __sync_nand_and_fetch(ptr, v)

// 比较和交换，成功失败返回bool
#define ATOMIC_BCAS(ptr, oldv, newv) __sync_bool_compare_and_swap(ptr, oldv, newv)
// 比较和交换，成功返回旧值
#define ATOMIC_CAS(ptr, oldv, newv) __sync_val_compare_and_swap(ptr, oldv, newv)

// 内存读写屏障
#define ATOMIC_BARRIER() __sync_synchronize()

// 将v写入ptr，并返回操作之前的值
#define ATOMIC_TEST_SET(ptr, v) __sync_lock_test_and_set(ptr, v)
// 将0写入到ptr，并对ptr解锁
#define ATOMIC_LOCK_RELEASE(ptr) __sync_lock_release(ptr)

#endif
