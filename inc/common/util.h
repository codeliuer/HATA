/*************************************************************************
    > File Name: util.h
    > Author: TOM
    > Mail: 18682303408@163.com
    > Function:
    > Created Time: Sat 21 May 2022 12:45:48 PM HKT
 ************************************************************************/

#ifndef __UTIL_H__
#define __UTIL_H__

#define INLINE __attribute__((always_inline))

#define NATURAL_ALIGN __attribute__((aligned))
#define EXCLUSIVE_CACHE_LINE __attribute__((aligned(64)))

#define SWAP(f, s) \
    do { \
        typeof(f) _f = (f); \
        typeof(s) _s = (s); \
        s = _s; \
        f = _f; \
    } while (0)

#endif