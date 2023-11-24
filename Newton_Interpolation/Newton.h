//
// Created by CHH on 2023/6/8.
//

#ifndef NEWTON_NEWTON_H
#define NEWTON_NEWTON_H
//
// Created by CHH on 2023/5/25.
//
#include <vector>


using namespace std;

class New1{
public:
    New1();

private:

    static void example1();

    static vector<vector<float>> input();//输入xy向量

    static vector<vector<float>> reve(vector<vector<float>> &ext);//将输入矩阵转置以便操作

    static void ex(vector<vector<float>> &ext);//求差商表

    static float swi(const vector<vector<float>>&xy,float x);

    static float ite(vector<vector<float>>&it);//迭代核心

};

#endif //NEWTON_NEWTON_H
