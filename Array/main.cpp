//
// Created by CHH on 2023/6/9.
//

//float Array1::deterr(const vvf&arr1){//代数余子式迭代器
//    float Res=0;
//    if(Len==1){
//        return arr1.at(0).at(0);
//    }
//    vvf arr2(Len-1,vector<float>(Len-1));
//    for(int i=0;i<Len;i++){
//        for(int j=0;j<Len-1;j++){
//            for(int k=0;k<Len-1;k++){
//                if(k<i){
//                    arr2.at(j).at(k)=arr1.at(j+1).at(k);
//                }
//                else{
//                    arr2.at(j).at(k)=arr1.at(j+1).at(k+1);
//                }
//            }
//        }
//        Res+=arr1.at(0).at(i)*deterr(arr2);
//        if (i%2!=0) Res*=-1;
//    }
//    return Res;
//}

//vf Array1::feature1(const vvf&arr1){//求特征值
//    vf result1;
//    vvf fea=arr1;
//    float fea1,re=1,fea2;
//    fea1= deterr(fea);
//    fea2=fea1;
//    while (re!=fea2){
//        for (int i = 0; i < Len; ++i){
//            for (int j = 0; j < Len; ++j) {
//                if (i==j) fea.at(i).at(j)-=fea1;
//            }
//        }
//        if (deterr(fea)==0) result1.emplace_back(fea1);
//        for(float &ci:result1)  re*=ci;
//        fea1= deterr(fea);
//    }
//    return result1;
//}

//vvf Array1::rev2(const vvf&arr1){//求转置矩阵
//    auto r2=arr1.at(0).size();
//    vvf arr2(r2,vf(Len));
//    for(int i=0;i<Len;i++){
//        for(int j=0;j<r2;j++){
//            arr2.at(j).at(i)=arr1.at(i).at(j);
//        }
//    }
//    return arr2;
//}

#include "Array1.h"
#include "leatsquares.h"
#include "arrayy.h"
#include "matrix_.h"

using namespace std;
using namespace Eigen;


int main(){
    int swi;
    cout<<"输入1进入矩阵特征模块"<<endl
        <<"输入2进入线性方程组求解模块"<<endl
        <<"输入3进入最小二乘模块"<<endl
        <<"请输入";
    cin>>swi;
    switch (swi) {

        case 1:
        {
            cout<<endl<<"进入矩阵特征模块"<<endl;
            Array1 arra;
            rev_1 rev;
            l_f lf;
            vvf arr1,arr2,ar3,ar4;

            arr1= arra.signin();

            lf.l1f(arr1);//求矩阵范数
            lf.LF(arr1);//求矩阵范数（机器学习）
            // cout<<"矩阵的行列式值为："<<arra.deter(arr1)<<endl;

            cout<<"伴随矩阵为："<<endl;
            output(arra.Adju1(arr1));

            ar3 = rev.Reve1(arr1);
            ar4 = rev.rev1(arr1);

            //   if (ar3== ar4){
            cout<<"逆矩阵为："<<endl;
            output(ar3);//输出逆矩阵
//            }
//            else{
//                output(ar3);//输出逆矩阵
//                cout<<"逆矩阵为："<<endl;
//                output(ar4);
//
            arr2 = judg(ar4,arr1);
            cout<<"原矩阵乘逆矩阵为"<<endl;
            output(arr2);
//            }


            break;
        }
        case 2:
        {
            cout<<"进入求解线性方程组模块"<<endl;
            arrayy arr2;//矩阵运算求解
            ite te;
            esti es;
            dooli di;
            te.example_();
            es.example_();
            di.example_();

            vvf array2=arr2.signin();
            vf array3=arr2.sign1(array2);
            vvf array1=arr2.Sign(array2,array3);
            output(array1);

            if (array2.size()>array2.at(0).size()){
                cout<<"系数矩阵转换为行列相同后"<<endl;
                vvf arr=arr2.change1(array2,array3);//将矩阵变换为方阵
                output(arr);

                if(arr2.judge1(arr)==arr.size()) te.iteration1(arr);//求解方程组
                else{
                    es.estimate1(arr);
                    di.Doolittle1(arr);
                }
            }else if(array2.size()==array2.at(0).size()){
                if(arr2.judge1(array2)==array2.size()) te.iteration1(array1);//求解方程组
                else{
                    es.estimate1(array1);
                    di.Doolittle1(array1);
                }
            }else cout<<"方程组无解"<<endl;
            break;
        }
        case 3:
        {

            fit ft;//最小二乘拟合
            vvf input=ft.input();
            ft.leastsquares(input);
            break;
        }
        default:
            cout<<"请输入正确的数字"<<endl;
            break;
    }

    return 0;

}


