/*** 
 * @Author: TimeTravel
 * @FilePath: /Example/src/can/MotoMatrixParse.h
 * @Date: 2020-12-28 19:54:20
 * @Description: Motorola Can Matrix Parse
 */

#include "ICanMatrixParse.h"

class MotoMatrixParse : public ICanMatrixParse
{
public:
    MotoMatrixParse(/* args */);
    virtual ~MotoMatrixParse();

    virtual DWORD decode(const BYTE* __buf, const BYTE __start_byte, const BYTE __start_bit, const BYTE __len) override;
    virtual DWORD decode(const BYTE* __buf, const BYTE __start_bit, const BYTE __len) override;
};


