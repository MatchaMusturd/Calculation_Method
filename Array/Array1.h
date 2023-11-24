//
// Created by CHH on 2023/6/8.
//

//
// Created by CHH on 2023/4/22.
//
#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <Eigen/Dense>
#include <algorithm>

#define Len arr1.size()
#define vf std::vector<float>
#define vvf std::vector<std::vector<float> >



class Array1 {
public:

    vvf signin();//输入方阵数组

    float deter(const vvf &arr1);//求矩阵行列式的值

    vvf Adju1(const vvf&arr1);//求伴随矩阵

private:

    int f1;
    float result, a1, mm;
    vvf arr, ar1, arr3, arr2;
    Eigen::MatrixXf re;
};

class rev_1:public Array1{
public:

    vvf rev1(const vvf&arr1);//求逆矩阵

    vvf Reve1(const vvf&arr1);//求逆矩阵

private:

    Eigen::MatrixXf initial, reverse;
    vvf result, arr, arr2;
    float mm, result2;
};

class l_f:public Array1{
public:

    void l1f(const vvf &arr1);//求矩阵范数

    vf feature(vvf &arr1);//求矩阵特征值

    vf lf1(const vvf &arr1);//求列范数

    vf lfu(const vvf &arr1);//求行范数

    void LF(const vvf &arr1);//求矩阵范数2）

private:

    rev_1 rev;
    int swi;
    float p1,p2,p1_,p2_,p3,p4,cot1,pls1,pls2,pls3,pls4,rr,a1,mm;
    vvf arr,cm_3,ar_;
    vf cm1,cm1_,cm2,cm2_,cm3,cm4,result2;
    Eigen::MatrixXf ma;
    Eigen::VectorXcf ree;//cf代表complex float意为复数浮点向量

};


//ARRAY_ARRAY_H
