//
// Created by CHH on 2023/6/23.
//
#include "Array1.h"
#include "arrayy.h"
#include "matrix_.h"

using namespace std;

void ite::example_(){
    exa={
            {10,-2,-1,3},
            {-2,10,-1,15},
            {-1,-2,5,10}
    };
    cout<<"用赛德尔迭代法解这个方程组"<<endl;
    output(exa);
    iteration1(exa);
}

void ite::iteration1(const vvf&arr1){//迭代法（严格对角占优阵）

    for(int i=0;i<Len;i++){
        arr2.emplace_back();
        for(int j=0;j<Len+1;j++){
            if(i==j) arr2.at(i).emplace_back(0);
            else if(j<Len){
                ar=-arr1.at(i).at(j)/arr1.at(i).at(i);
                arr2.at(i).emplace_back(ar);
            }
            else if(j==Len){
                ar=arr1.at(i).at(Len)/arr1.at(i).at(i);
                arr2.at(i).emplace_back(ar);
            }
        }
    }
    cout<<"输出迭代矩阵"<<endl;
    output(arr2);
    for(int c=0;c<Len;c++){//设置初始迭代值
        arend=*(arr2.at(c).end()-1);
        ar5.emplace_back(arend);//已经迭代一次
    }
    cout<<"请输入误差限（例：输入2为10的-2次方）";
    cin>>te;
    minvalue= powf(10,-te);
    cin.clear();
    cout<<"误差限为"<<minvalue<<endl;

    minv=1;
    ci=1;

    while (minv>minvalue){//ar为误差
        ar3.clear();
        ar2=ar5;
        cout<<"迭代"<<ci<<"次的结果为"<<endl;
        ar5=iter1(ar5,arr2);

        for (int i = 0; i < ar5.size(); ++i) {
            ar=(ar5.at(i)-ar2.at(i));
            ar3.emplace_back(ar);
        }

        ci++;
        minv= *max_element(ar3.begin(),ar3.end());
        cout<<"最大误差为"<<minv<<endl;

    }
    cout<<endl;
}

vf ite::iter1(vf&ar1, const vvf&arr1){//迭代法核心(赛德尔迭代)

    for(int i1=0;i1<Len;i1++){
        pus=0;
        for(int j1=0;j1<Len;j1++){
            pus+=ar1.at(j1)*arr1.at(i1).at(j1);
        }
        ar4.emplace_back(pus);
        *(ar4.end()-1)+=*(arr1.at(i1).end()-1);
        ar1.at(i1)=*(ar4.end()-1);
        cout<<ar1.at(i1)<<"\t\t";//显示每次迭代结果
    }
    cout<<endl;
    return ar1;
}