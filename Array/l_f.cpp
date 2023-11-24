//
// Created by CHH on 2023/6/26.
//

#include "Array1.h"
#include "matrix_.h"

using namespace Eigen;
using namespace std;


void l_f::l1f(const vvf &arr1){//求矩阵范数
    cout<<"求矩阵范数"<<endl;
    arr = arr1;
    cm_3 = rev.rev1(arr);//cm_3为arr1的逆矩阵

    cm1 = lf1(arr);//cm1为原矩阵列范数
    cm1_ = lf1(cm_3);//cm1_为逆矩阵列范数
    p1 = *max_element(cm1.begin(), cm1.end());
    p1_ = *max_element(cm1_.begin(), cm1_.end());

    cm3 = feature(arr);//原矩阵特征值
    cm4 = feature(cm_3);//逆矩阵特征值
    p3 = *max_element(cm3.begin(), cm3.end());
    p4 = *max_element(cm4.begin(), cm4.end());

    cm2 = lfu(arr);//原矩阵行范数
    cm2_ = lfu(cm_3);//逆矩阵行范数
    p2 = *max_element(cm2.begin(), cm2.end());
    p2_ = *max_element(cm2_.begin(), cm2_.end());

    rr=0;
    for (int j = 0; j < Len; ++j) {
        rr += arr.at(j).at(j);
    }
    a1=1;
    mm=0;
    for (float ii:cm3){
        mm+=ii;
        a1*=ii;
    }

    cout<<"矩阵的列范数为"<<p1<<endl
        <<"矩阵的F范数为"<<powf(p3,0.5)<<endl
        <<"矩阵的行范数为"<<p2<<endl;


    cout<<"壹条件数为"<<p1*p1_<<endl//原矩阵列范数最大值与逆矩阵列范数最大值乘积
        <<"贰条件数为"<<p3*p4<<endl//原矩阵特征值最大值与逆矩阵特征值最大值乘积
        <<"无穷条件数为"<<p2*p2_<<endl;//行范数最大值与逆矩阵行范数最大值乘积

    cout<<"列主元素加和为"<<rr<<endl
        <<"特征值加和为"<<mm<<endl
        <<"特征值乘积为"<<a1<<endl
        <<"行列式的值为"<<deter(arr)<<endl;

}

vf l_f::feature(vvf &arr1){//求矩阵特征值
    matrix mx;
    //  output(arr1);
    ma = mx.trans(arr1);//将vector<vector<float>>转为matrix
    // output(arr1);
    EigenSolver<MatrixXf> es(ma);//es是矩阵特征值向量
    ree = es.eigenvalues();//eigenvalue方法返回复数实数共轭向量
    result2.clear();
    for(int i=0;i<Len;i++){
        rr = ree(i).real();//real方法取实部
        result2.emplace_back(rr);
    }

    return result2;
}

vf l_f::lf1(const vvf &arr1){//求列范数
    ar_ = arr1;
    for (vf &a_1 : ar_){
        p1=0;
        for(float a : a_1){
            p1 += abs(a);
        }
        cm1.emplace_back(p1);
    }
    return cm1;
}

vf l_f::lfu(const vvf &arr1){//求行范数
    ar_ = arr1;
    for (int i = 0; i < ar_.at(0).size(); ++i) {
        p2=0;
        for (auto & j : ar_) {
            p2 += abs(j.at(i));
        }
        cm2.emplace_back(p2);
    }
    return cm2;
}


void l_f::LF(const vvf &arr1){//求矩阵范数(机器学习）

    auto sz1= arr1.size(), sz2= arr1.at(0).size();
//    cout<<"输入0求L0范数"<<endl<<"输入1求L1范数"<<endl<<"输入2求F范数"<<endl<<"输入3求L21范数"<<endl<<"请输入";
//    cin>>swi;
//    switch (swi) {
//        default:
//            cout<<"请输入正确选项"<<endl;
//            break;
//        case 0:
            cot1 = 0;
            for (const vf &i : arr1){
                for (auto j : i) {
                    if (j!=0) cot1++;
                }
            }//L0范数就是矩阵非0元素个数
            cout<<"矩阵的L0范数为："<<cot1<<endl;
//            break;
//        case 1:
            pls1 = 0;
            for (const vf &i : arr1){
                for (auto j : i) pls1+= abs(j);
            }//L1范数就是所有元素绝对值的和
            cout<<"矩阵的L1范数为："<<pls1<<endl;
//            break;
//        case 2:
            pls2 = 0;
            for (auto &i: arr1){
                for (auto j:i) pls2 += powf(j,2);
            }
            pls2= sqrt(pls2);
            //F范数就是所有元素平方和的根
            cout<<"矩阵的F范数为："<<pls2<<endl;
//            break;
//        case 3:
            pls3 = 0;
            pls4 = 0;
            for (int i = 0; i < sz2; ++i) {//外层循环是列遍历
                for (int j = 0; j < sz1; ++j) {//内层循环是行遍历
                    pls3 += powf(arr1.at(j).at(i),2);
                }
                pls3 = sqrt(pls3);
                pls4 += pls3;
            }
            //L21范数就是每一行元素平方和的根的和
            cout<<"矩阵的L21范数为："<<pls4<<endl;
//            break;
//    }
//    cin.clear();
}
