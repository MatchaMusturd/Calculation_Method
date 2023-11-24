//
// Created by CHH on 2023/6/23.
//
#include "arrayy.h"
#include "Array1.h"
#include "matrix_.h"

using namespace std;

void esti::example_() {
    //cout<<"estiruning"<<endl;
    exa1={
            {1,4,-5,3},
            {1,3,-2,2},
            {6,-1,18,2}
    };
    cout<<"用列选主元法解这个方程组"<<endl;
    output(exa1);
    estimate1(exa1);
}

vf esti::estimate1(const vvf&arr1){    //列选主元法解方程组
    //unsigned f1=arr1.size();
    arr2=arr1;
    //ar2(Len+1);
    //ar1=new vf(Len);
    for(int i=0;i<Len-1;i++){//化为上三角阵
        for(int j=i;j<Len;j++){//选出列主元素最大值
            if(arr2.at(j).at(i)>a1){
                a1=arr2.at(j).at(i);
                a2=j;//标记最大元素所在行
            }
        }

        for(int c=0;c<Len+1;c++){//最大列主元素所在行换到第i行
            ar2.emplace_back(arr2.at(a2).at(c));
            arr2.at(a2).at(c)=arr2.at(i).at(c);
            arr2.at(i).at(c)=ar2.at(c);
        }


        for(int c1=i+1;c1<Len;c1++){//消去除列主元素所在行之上的行外列主元素所在列的其他元素
            k1=arr2.at(c1).at(i)/arr2.at(i).at(i);
            for(int r1=i;r1<=Len;r1++){
                arr2.at(c1).at(r1)-=arr2.at(i).at(r1)*k1;
                //  cout<<arr2[c1][r1]<<endl;
            }
        }

    }

    for(int w1=Len-1;w1>=0;w1--){ //三角阵回代
        // cout<<arr2[w1][f1]<<"   "<<arr2[w1][w1]<<endl;
        for(int kk=Len-1;kk>w1;kk--){
            a2=Len-1-kk;
            arr2.at(w1).at(Len)-=arr2.at(w1).at(kk)*ar1.at(a2);
        }
        a1=arr2.at(w1).at(Len)/arr2.at(w1).at(w1);
        if(abs(a1)<0.0001){
            a1=0;
        }
        ar1.emplace_back(a1);
        //cout<<arr1[w1][f1]<<"   "<<arr1[w1][w1]<<endl;
    }
    reverse(ar1.begin(),ar1.end());
    cout<<"用列主元消去法方程组的解为："<<endl;
    for(float &re:ar1) cout<<re<<endl;
    cout<<endl;
    return ar1;
}
