#include "MotoMatrixParse.h"
#include "base/h-bitmask.h"

MotoMatrixParse::MotoMatrixParse()
{

}

MotoMatrixParse::~MotoMatrixParse()
{

}


DWORD MotoMatrixParse::decode(const BYTE* __buf, const BYTE __start_byte, const BYTE __start_bit, const BYTE __len)
{
    if (__len == 0) return 0;
    DWORD tmp = 0;
    for (int i=0; i<4; i++) {
        if (__start_byte+i>8) break;
        tmp += (__buf[__start_byte+i] << (8*i));
    }

    for (int i=3; i>=0; i--) {
        if (__start_byte+i>8) continue;
        tmp += (__buf[__start_byte+i] << (8*(3-i)));
    }
    return BitMask(tmp, __start_bit, __len);
}

DWORD MotoMatrixParse::decode(const BYTE* __buf, const BYTE __start_bit, const BYTE __len)
{
    return decode(__buf, __start_bit / 8, __start_bit % 8, __len);
}