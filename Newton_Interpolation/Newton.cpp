//
// Created by CHH on 2023/5/25.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "Newton.h"

using namespace std;


    New1::New1(){
        example1();//示例
        int times;
        vector<vector<float> > xy,XY;
        xy=input();
        XY= reve(xy);
        float x,result;
        cout<<"请输入拟合点个数";
        cin>>times;
        while(times--){
            cin.clear();
            cout<<"请输入拟合点";
            cin>>x;
            result=swi(XY , x);
            cout<<"拟合结果为"<<result<<endl;
        }

    }

    void New1::example1(){
        vector<vector<float>> xy,XY;
        float result1,result2,result3;
        xy={
                {0.4,0.55,0.8,0.9,1},
                {0.41075,0.57815,0.88811,1.02652,1.17520}
        };
        ex(xy);
        XY = reve(xy);
        result1 = swi(XY,0.5);
        result2 = swi(XY,0.7);
        result3 = swi(XY,0.85);
        cout<<"0.5的拟合结果为"<<result1<<endl;
        cout<<"0.7的拟合结果为"<<result2<<endl;
        cout<<"0.85的拟合结果为"<<result3<<endl;
    }

     vector<vector<float>> New1::input(){//输入xy向量
        float r;
        vector<vector<float>> ext;
        cout<<"请输入初始x值"<<endl;
        ext.emplace_back();
        while(cin.peek()!='\n'){
            cin>>r;
            ext.at(0).push_back(r);
        }
        cout<<"请输入x对应y的值"<<endl;
        ext.emplace_back();
        for (int tt=0;tt<ext.at(0).size();tt++){
            cin>>r;
            ext.at(1).push_back(r);
        }
        sort(ext.at(0).begin(),ext.at(0).end());//根据X排序

        ex(ext);//求差商表

        return ext;
    }

    vector<vector<float>> New1::reve(vector<vector<float>> &ext){//将输入矩阵转置以便操作
        float pp;
        auto siz = ext.at(0).size();
        vector<vector<float>> ex2;
        for (int i2 = 0; i2 < siz; ++i2) {//转置到X与对应Y在一个行向量
            ex2.emplace_back();
            for(int j3 = 0; j3 < 2; j3++){
                pp = ext.at(j3).at(i2);
                ex2.at(i2).emplace_back(pp);
            }
        }
        return ex2;
    }

     void New1::ex(vector<vector<float>> &ext){//求差商表
        float pp;
        auto siz = ext.at(0).size();
        float ij_ij_1,ij_1;
        for(int i = 1; i < siz; i++){
            ext.emplace_back();
            for(int j = 1; j <= siz - i; j++){
                ij_ij_1 = ext.at(i).at(j) - ext.at(i).at(j - 1);
                ij_1 = ext.at(0).at(i + j - 1) - ext.at(0).at(j - 1);
                pp = ij_ij_1 / ij_1;
                ext.at(i + 1).emplace_back(pp);
            }
        }

        vector<vector<float> > ex;
        for (int i1 = 0; i1 < siz; ++i1) {//转置到X与对应Y在一个行向量 ?
            ex.emplace_back();
            for(int j2 = 0; j2 < ext.size() - i1; j2++){
                pp = ext.at(j2).at(i1);
                ex.at(i1).emplace_back(pp);
            }
        }

        for(const vector<float>& ite:ex){
            for(float it:ite){
                cout<<it<<"         ";
            }
            cout<<endl;
        }
    }

    float New1::swi(const vector<vector<float>>&xy, float x){//主函数
        auto se = xy.size();
        float sw, sw1;
        int v1 = 0;
        vector<vector<float>> x1y = xy;

        for (int i1 = 0; i1 < se; ++i1) //判断拟合点x在插值点数列中的位置
            if (x > xy.at(i1).at(0)) v1++;


        for (auto i1 = se; i1 >0; i1--) {//取最大阶数非零均差对应的解向量组x1y

            if (v1>x1y.size()/2){
                x1y.erase(x1y.begin());
                v1--;
            }
            else{
                x1y.erase(x1y.end());
                v1++;
            }
            sw1=ite(x1y);//迭代结果为最大均差
            if (sw1!=0) break;
        }
        sw=x1y.at(0).at(1);
        auto len=x1y.size();
        vector<float> xx(len-1);
        auto it1=xx.begin();
        for(int i3=0;it1!=xx.end();it1++){
            *it1=x-x1y.at(i3++).at(0);
            //   cout<<*it1<<endl;
        }
        for (int i4 = 0; i4 < len-1; ++i4) {
            vector<vector<float>> a1(i4+2,vector<float>(2,0));
            for(auto aa=0;aa<i4+2;aa++) a1.at(aa)=x1y.at(aa);
            sw1= ite(a1);
//            cout<<i4+1<<"阶均差为";
//            cout<<sw1<<endl;
            for (int i5 = 0; i5 <=i4; ++i5) {
                sw1*=xx.at(i5);
            }
            sw+=sw1;
        }
        return sw;
    }

    float New1::ite(vector<vector<float>>&it){//迭代核心
        auto si = it.size();
        if (si==1) return it.at(0).at(1);
        vector<vector<float>> it1(si - 1,vector<float>(2)),
                                it2(si - 1,vector<float>(2));
        for (auto c1 = 0; c1 < si; c1++){
            if (c1!=0) it2.at(c1 - 1) = it.at(c1);
            if (c1!=si - 1) it1.at(c1) = it.at(c1);
        }
        return (ite(it1) - ite(it2)) / (it1.at(0).at(0) - it2.at(si - 2).at(0));
    }

int main(){
    New1();
}
