//
// Created by CHH on 2023/6/11.
//
//#include "Array1.h"
#include "leatsquares.h"

using namespace std;

fit::fit() {
    cout<<"进入最小二乘拟合模块"<<endl;
}

vvf fit::input() {
    ju= true;
    sam.emplace_back();
    cout<<"请输入一组样本点的x"<<endl;
    while (ju){
        cin>>in;
        if (cin.peek()=='\n') ju= false;
        sam.at(0).emplace_back(in);
        cin.clear();
    }
    auto siz=sam.at(0).size();
    sam.emplace_back();
    cout<<"请输入这组样本点的y"<<endl;
    for (int i = 0; i < siz; ++i) {
        cin>>in;
        sam.at(1).emplace_back(in);
        cin.clear();
    }
    sam.emplace_back();
    cout<<"请输入这组样本点的权重"<<endl;
    for (int i = 0; i < siz; ++i) {
        cin>>in;
        sam.at(2).emplace_back(in);
        cin.clear();
    }
    return sam;
}



void fit::leastsquares(vvf &input) {

    ss.emplace_back(cons(input));//ss装的是拟合误差
    //以上是用常数拟合的求拟合误差过程
    resu= fit_2(input,k);
    ss.emplace_back(resu.error);
    st3.emplace_back();
    for (float ii:resu.re) st3.at(0).emplace_back(ii);
    //以上是一次函数拟合数据求误差的过程

    while (*(ss.end()-1)<*(ss.end()-2)){//用每次求得误差与上一次比较，如果比上次误差小，则继续下次运算，直到误差大于上次误差时结束循环，取上次误差对应的结果
        k++;
        st3.emplace_back();
        resu= fit_2(input,k);
        ss.emplace_back(resu.error);
        for (float ii:resu.re) st3.at(k-2).emplace_back(ii);
    }
    stt=*(st3.end()-2);
    cout<<"从0次到"<<k-1<<"次拟合最小二乘误差为"<<endl;
    for (float ii:ss) cout<<ii<<endl;
    cout<<k-2<<"次拟合的"<<k-1<<"个方程系数为"<<endl;
    for (float ii:stt) cout<<ii<<"\t\t";
    cout<<endl;
}