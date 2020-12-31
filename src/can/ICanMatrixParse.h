/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/can/ICanMatrixParse.h
 * @Date: 2020-12-28 15:20:43
 * @Description: 解析CAN矩阵的抽象类
 */

#ifndef ICANMATRIXPARSE_H
#define ICANMATRIXPARSE_H

#include "base/h-typedef.h"

class ICanMatrixParse
{
public:
    virtual ~ICanMatrixParse() {}

    virtual DWORD decode(const BYTE* __buf, const BYTE __start_byte, const BYTE __start_bit, const BYTE __len) = 0;
    virtual DWORD decode(const BYTE* __buf, const BYTE __start_byte, const BYTE __len) = 0;
};

#endif //ICANMATRIXPARSE_H