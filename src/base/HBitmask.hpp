/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/base/h-bitmask.hpp
 * @Date: 2020-12-28 16:36:39
 * @Description: 获取某些位的值
 */

#pragma once

template<typename T>
T BitMask(const T __src, const unsigned char __start, const unsigned char  __len)
{
    if (__len == 0) return 0;
    T tmp = 0;
    for (int i = 0; i < __len; i++) {
        tmp += (1 << (__start+__len - 1 - i));
    }
    return ((tmp&__src)>>__start);
}

