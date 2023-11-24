//
// Created by CHH on 2023/5/18.
//
//
// Created by CHH on 2023/4/22.
//

#include "Array1.h"
#include "matrix_.h"

using namespace Eigen;
using namespace std;


vvf Array1::signin(){//输入方阵数组

    cout<<"请输入方阵的行列数"<<endl;
    cin>>f1;
    cout<<"请按行依次输入方阵元素"<<endl;
    for (int i = 0; i < f1; ++i) {
           ar1.emplace_back();
        for (int j = 0; j < f1; ++j) {
                    cin>>a1;
                    ar1.at(i).emplace_back(a1);
                    cin.clear();
        }
    }
    return ar1;
}

float Array1::deter(const vvf &arr1){//求矩阵行列式的值
    matrix mx;
    arr = arr1;
    re = mx.trans(arr);//将vector<vector<float>>矩阵转换为matrix矩阵
    result = re.determinant();//求行列式的值
    return result;
}

vvf Array1::Adju1(const vvf&arr1){//求伴随矩阵
    //vvf arr2(Len-1,vector<float>(Len-1));
    matrix mx;
    for(int i1 = 0; i1 < Len; i1++){
        arr3.emplace_back();
        for(int j1 = 0; j1 < Len; j1++){//前两重循环遍历arr1每个元素，除每个元素所在行列外的其他元素输入到Len-1阶的arr2矩阵中

            for(int i2 = 0; i2 < Len-1; i2++){//每次得到对应arr1矩阵一个元素的余子式
                arr2.emplace_back();
                for(int j2 = 0; j2 < Len - 1; j2++){
                   // cout<<i1<<"  "<<j1<<"  "<<i2<<"  "<<j2<<endl;
                    if(i2 >= i1&&j2 >= j1)
                        arr2.at(i2).emplace_back(arr1.at(i2 + 1).at(j2 + 1));
                    else if(i2 < i1&&j2 < j1)
                        arr2.at(i2).emplace_back(arr1.at(i2).at(j2));
                    else if( i2 < i1&&j2 >= j1)
                        arr2.at(i2).emplace_back(arr1.at(i2).at(j2 + 1));
                    else if(i2 >= i1&&j2 < j1)
                        arr2.at(i2).emplace_back(arr1.at(i2 + 1).at(j2));
                }
            }
            mm = deter(arr2);
            arr2.clear();
            arr3.at(i1).emplace_back(mm);
            //求arr2矩阵的行列式，并将其代数余子式输入到矩阵arr3对应arr1矩阵元素位置
            if ((i1 + j1) % 2!=0)
                arr3.at(i1).at(j1) *= -1;
        }
    }
    arr3 = mx.tranpoe(arr3);//矩阵转置
    return arr3;
}


