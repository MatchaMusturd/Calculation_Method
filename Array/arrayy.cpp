//
// Created by CHH on 2023/6/8.
//
//
// Created by CHH on 2023/5/27.
//

#include "arrayy.h"
#include "Array1.h"
#include "matrix_.h"

using namespace std;

vvf arrayy::signin(){//输入矩阵
    t= true;
    sini.emplace_back();
    cout<<"请按行依次输入方阵元素(输入/结束)"<<endl;
    while(true) {//先输入第一行元素以确定矩阵列数
        cin >> r;
        sini.at(0).push_back(r);
        cin.clear();
        if (getchar()=='\n') break;
    }
    point=1;
    auto sz= sini.at(0).size();
    //cout<<sz<<endl;
    while(t){
        sini.emplace_back();
        for (auto j = 0; j < sz; ++j) {
            cin >> r;
            if (getchar()=='/'){
                t= false;
                break;
            }
            sini.at(point).push_back(r);
            cin.clear();
        }
        point++;
    }
    sini.erase( sini.end());
    return  sini;
}

vvf arrayy::change1(const vvf&arr1,const vf&arr2){//将输入数组变换为行列相等形式
    matrix mx;
    arr=arr1;
    arr3= mx.tranpoe(arr);
    point=0;
    for (const float &kk:arr2){//将解向量转至二维矩阵中
        arr4.emplace_back();
        arr4.at( point++).emplace_back(kk);
    }
//    output(arr4);
    if (arr1.size()>arr1.at(0).size()){//行数大于列数
        point=0;
        ar11=judg(arr3,arr);
        //  output(ar1);
        ar2=judg(arr3,arr4);
        //    output(ar2);
        for (vf&ch1:ar11)  ch1.emplace_back(ar2.at( point++).at(0));
        return ar11;
    }
    else    return arr1;
}

vf arrayy::sign1(const vvf&arr1){//输入解向量

    cout<<"请输入方阵解向量："<<endl;
    for(int j=0;j<Len;j++){
        cin>>in;
        result.emplace_back(in);
    }
    cin.clear();
    return result;
}

vvf arrayy::Sign(const vvf&arr1,const vf&arr2){//将解向量与系数矩阵整合

    point=0;
    for (vf&ch1:arr3)  ch1.emplace_back(arr2.at( point++));
    return arr3;
}

int arrayy::judge1(const vvf&arr1){//判断是否是严格对角占优阵

    for(int i=0;i<Len;i++){
        for(int j=0;j<Len;j++){
            if(i!=j) ar1.at(i)+=arr1.at(i).at(j);
        }
    }
    for(int i1=0;i1<Len;i1++){
        if(arr1.at(i1).at(i1)>ar1.at(i1)) c1++;
    }
    return c1;
}

