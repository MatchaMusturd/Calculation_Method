//
// Created by CHH on 2023/6/26.
//

#ifndef ARRAY_ARRAYY_H
#define ARRAY_ARRAYY_H

#include <iostream>
#include <vector>


//#define Len arr1.size()
#define vf std::vector<float>
#define vvf std::vector<std::vector<float> >

class arrayy{
public:

    vvf signin();//输入方阵数组

    vf sign1(const vvf&arr1);//输入解向量

    vvf Sign(const vvf&arr1,const vf&arr2);//将解向量与系数矩阵整合

    vvf change1(const vvf&arr1,const vf&arr2);//将输入数组变换为行列相等形式

    int judge1(const vvf&arr1);//判断是否是严格对角占优阵

private:

    float r,in;
    int  point,c1;
    bool t;
    vf result,ar1;
    vvf sini,arr,arr3,ar11,ar2,arr4;

};

class dooli:public arrayy{
public:

    void example_();

    vf Doolittle1(const vvf&arr1);//杜利特尔解方程组

private:

    vvf arr,arr2,exa2;
    vf arr3;
};

class esti:public arrayy{
public:

    void example_();

    vf estimate1(const vvf&arr1);//列选主元法解方程组
private:
    int a2;
    float a1,k1;
    vvf arr2,exa1;
    vf ar2,ar1;
};

class ite:public arrayy{
public:

    void example_();

    void iteration1(const vvf&arr1);//迭代法（严格对角占优阵）

    vf iter1(vf&ar1, const vvf&arr1);//赛德尔迭代
private:
    vvf exa,arr2;
    vf ar2,ar3,ar4,ar5;
    float arend,minvalue,te,ar,minv,pus;//误差判断值
    int ci;//迭代次数计数器

};
#endif //ARRAY_ARRAYY_H
