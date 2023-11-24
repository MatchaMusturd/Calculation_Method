//
// Created by CHH on 2023/10/18.
//

#ifndef NEWTON_COTES_SPLIT_H
#define NEWTON_COTES_SPLIT_H
#include <iostream>
#include <cmath>

class Split{
public:
    double cc{};//区间起点
    double ab{};//步长
    double a{};//起点函数值+终点函数值
    double l{};//起点和终点的距离

    Split();
    [[nodiscard]] double funchoice(const double&) const;
    void func_choice(int, int);

private:
    int c=0;
    static double func1(const double &);
    static double func2(const double &);
    static double func3(const double &);
};

#endif //NEWTON_COTES_SPLIT_H
