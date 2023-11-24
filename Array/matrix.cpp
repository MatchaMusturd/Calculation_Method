//
// Created by CHH on 2023/6/26.
//
//#include "Array1.h"
#include "matrix_.h"

using namespace std;
using namespace Eigen;

void output(const vvf&arr1){//输出矩阵
    for(const vf& i : arr1){
        for(float j:i) cout<<j<<"\t\t";
        cout<<endl;
    }
}

vvf judg(const vvf&arr1, const vvf&arr2){//判断两种方式乘积结果
    matrix mx;
    vvf result;
    if (multiple(arr1, arr2)==mx.pls(arr1, arr2))
        result = multiple(arr1, arr2);
    else result = mx.pls(arr1, arr2);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j <result.at(0).size(); j++){
            if(abs(result[i][j]) < 0.00001) result[i][j] = 0;
        }
    }
    return result;
}

vvf multiple(const vvf&arr1, const vvf&arr2){//矩阵乘积
    auto r1= arr1.size();
    auto r3= arr2.at(0).size();
    auto r2= arr1.at(0).size();
    vvf arr(r1,vf(r3));
    for(int i = 0; i < r1; i++){//向arr输入乘积结果
        for(int j = 0; j < r3; j++)
            for(int k = 0; k < r2; k++)
                arr.at(i).at(j)+=arr1.at(i).at(k)*arr2.at(k).at(j);
    }
    return arr;
}

MatrixXf matrix::trans(vvf &arr1){//将vector转换为matrix
    auto row=arr1.size();
    auto sz=arr1.at(0).size();
    MatrixXf ar(row,sz);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < sz; ++j) {
            ar(i,j)=arr1.at(i).at(j);
        }
    }
    return ar;
}

vvf matrix::trns(MatrixXf &ma){//将matrix转换为vector
    for (int i = 0; i < ma.rows(); ++i) {
        arr1.emplace_back();
        for (int j = 0; j < ma.cols(); ++j) {
            arr1.at(i).emplace_back(ma(i,j));
        }
    }
    return arr1;
}

vvf matrix::pls(const vvf&arr1,const vvf&arr2){//矩阵乘积
    a1=arr1;
    a2=arr2;
    ar1= trans(a1);
    ar2= trans(a2);
    ar=ar1*ar2;
    result= trns(ar);
    return result;
}

vvf matrix::tranpoe(const vvf&arr1){//矩阵转置
     result2=arr1;
    initial= trans(result2);
    tranpo=initial.transpose();
    result2= trns(tranpo);
    return result2;
}
