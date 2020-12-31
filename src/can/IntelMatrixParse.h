/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/can/IntelMatrixParse.h
 * @Date: 2020-12-28 19:53:34
 * @Description: Intel Can Matrix Parse
 */

#ifndef INTELMATRIXPARSE_H
#define INTELMATRIXPARSE_H

#include "ICanMatrixParse.h"

class IntelMatrixParse : public ICanMatrixParse
{
public:
    IntelMatrixParse(/* args */);
    virtual ~IntelMatrixParse();

    virtual DWORD decode(const BYTE* __buf, const BYTE __start_byte, const BYTE __start_bit, const BYTE __len) override;
    virtual DWORD decode(const BYTE* __buf, const BYTE __start_byte, const BYTE __len) override;
};


#endif //INTELMATRIXPARSE_H