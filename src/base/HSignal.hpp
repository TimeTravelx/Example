/***
 * @Author: TimeTravel
 * @FilePath: /Example/src/base/HSignal.hpp
 * @Date: 2021-01-07 15:26:46
 * @Description: hsignal, bind callback
 */
#pragma once

#include <vector>

template<class T>
class HSignal
{
public:
    HSignal() {}

    ~HSignal() { mList.clear(); }

    void connect(const T& value) { mList.emplace_back(value); }

    template<typename ...Args>
    void operator() (Args...args) {
        for (int i = 0; i < mList.size(); i++) {
            T temp = mList[i];
            temp(std::forward<Args>(args)...);
        }
    }

private:
    std::vector<T> mList;
};
