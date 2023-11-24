//
// Created by CHH on 2023/6/8.
//

#ifndef SAMPLE_STATS_SAMPLES_H
#define SAMPLE_STATS_SAMPLES_H


#include <vector>


using namespace std;
class Sample_stats{
public:
    Sample_stats();

private:

    static vector<float> input();//输入数据

    static float midl(vector<float> &in);//求中位数

    static float average(vector<float> &in);//求平均值

    static float utmostgap(vector<float> &in);//求极差

    static float variance(vector<float> &in);//求方差

    static void oripattern(vector<float> &in,const float);//求原点矩

    static void centrepat(vector<float> &in,const float);//求中心距

    static void expr(vector<float> &in);//求经验分布函数

};

#endif //SAMPLE_STATS_SAMPLES_H
