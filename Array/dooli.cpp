//
// Created by CHH on 2023/6/23.
//
#include "arrayy.h"
#include "Array1.h"
#include "matrix_.h"

using namespace std;

void dooli::example_(){
    exa2={
            {2,1,2,6},
            {4,5,4,18},
            {6,-3,5,5}
    };
    cout<<"用LU分解求这个方程组"<<endl;
    output(exa2);
    Doolittle1(exa2);
}

vf dooli::Doolittle1(const vvf&arr1){//杜利特尔解方程组
    //arr2=new vvf(Len,vector<float>(Len));
    //arr3=new vvf(Len);
    arr=arr1;

    for(int i1=0;i1<Len;i1++){
        arr2.emplace_back();
        for(int j1=0;j1<Len;j1++){
            arr2.at(i1).emplace_back();
            if (i1==0) arr2.at(i1).at(j1)=arr1.at(i1).at(j1);
            else if(i1>j1){
                for (int i2=0;i2<j1;i2++) {
                    arr.at(i1).at(j1)-=arr2.at(i1).at(i2)*arr2.at(i2).at(j1);
                }
                arr2.at(i1).at(j1)=arr.at(i1).at(j1)/arr2.at(j1).at(j1);
            }
            else if(i1 <= j1){
                arr2.at(i1).at(j1)=arr1.at(i1).at(j1);
                for (int j2 = 0; j2 < i1; j2++) {
                    arr2.at(i1).at(j1)-=arr2.at(i1).at(j2)*arr2.at(j2).at(j1);
                }
            }

        }

    }
    cout<<"LU矩阵为："<<endl;
    output(arr2);
    cout<<"中间解向量为 ："<<endl;
    for (int i3 = 0; i3 < Len; ++i3) {
        arr3.emplace_back(arr1.at(i3).at(Len));
        for (int i4 = 0; i4 < i3; ++i4) {
            arr3.at(i3)-=arr2.at(i3).at(i4)*arr3.at(i4);
        }
        cout<<arr3.at(i3)<<endl;
    }

    for (int i5 = Len-1; i5 >=0; i5--) {
        for (int i6 = Len-1; i6 > i5; i6--) {
            arr3.at(i5)-=arr2.at(i5).at(i6)*arr3.at(i6);

        }
        arr3.at(i5)/=arr2.at(i5).at(i5);

    }
    cout<<"用Doolittle法方程组的解为："<<endl;
    for (float &ii:arr3) cout<<ii<<endl;
    cout<<endl;
    return arr3;
}


