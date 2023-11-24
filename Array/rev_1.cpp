//
// Created by CHH on 2023/6/26.
//
#include "Array1.h"
#include "matrix_.h"

using namespace std;
using namespace Eigen;

vvf rev_1::rev1(const vvf&arr1){//求逆矩阵
    matrix mx;
    result = arr1;
    initial = mx.trans(result);
    reverse = initial.inverse();
    result = mx.trns(reverse);//将matrix矩阵转为vector<vector<float>>矩阵
    for(vf re:result){
        for (float res:re){
            if (abs(res) < 0.00001) res = 0;
        }
    }
    return result;
}

vvf rev_1::Reve1(const vvf&arr1){//求逆矩阵
    arr = arr1;
    result = Adju1(arr1);//伴随矩阵
   // vvf arr2(Len,vector<float>(Len));
    for(int i=0;i<Len;i++){
        arr2.emplace_back();
        for(int j = 0; j < Len; j++) {
            mm = deter(arr);//求行列式
            result2 = result.at(i).at(j) / mm;
            if(abs(result2) < 0.00001) result2 = 0;
            arr2.at(i).emplace_back(result2);
        }
    }
    return arr2;
}