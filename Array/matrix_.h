//
// Created by CHH on 2023/6/26.
//

#pragma once

#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <cmath>

#define vf std::vector<float>
#define vvf std::vector<std::vector<float> >


void output(const vvf&arr1);//输出矩阵

vvf judg(const vvf&arr1,const vvf&arr2);//判断两种方式乘积结果

vvf multiple(const vvf&arr1,const vvf&arr2);//矩阵乘积

class matrix{
public:

    Eigen::MatrixXf trans(vvf &arr1);//将vector转换为matrix

    vvf trns(Eigen::MatrixXf &ma);//将matrix转换为vector

    vvf pls(const vvf&arr1,const vvf&arr2);//矩阵乘积

    vvf tranpoe(const vvf&arr1);//矩阵转置

private:

    vvf arr1,a1,a2,result,result2;

    Eigen::MatrixXf ar1,ar2,ar,tranpo,initial;
};
 //ARRAY_MATRIX__H
