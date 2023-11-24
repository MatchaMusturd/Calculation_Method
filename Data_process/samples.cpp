#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "samples.h"

using namespace std;

    Sample_stats::Sample_stats(){
        float aver, gap, vari, varr, vat, mid;
         vector<float> sampleone=input();
         aver = average(sampleone);
       // cout<<"本组数据的平均值为"<<aver<<endl;
        mid = midl(sampleone);
        cout<<"本组数据的中位数为"<<mid<<endl;
        gap = utmostgap(sampleone);
        cout<<"本组数据的极差为"<<gap<<endl;
        vari = variance(sampleone);//求方差
       // cout<<"本组数据的方差为"<<vari<<endl;
        varr = powf(vari,0.5);
       // cout<<"本组数据的标准差为"<<varr<<endl;
        vat = varr / aver;//标准差除以平均数
        cout<<"本组数据的差异系数为"<<vat<<endl;
        expr(sampleone);//经验分布函数
        float k;
        cout<<"求k阶原点矩和中心距请输入k";
        cin>>k;
        oripattern(sampleone, k);//原点矩
        centrepat(sampleone, k);//中心矩
    }


    vector<float> Sample_stats::input(){//输入数据
        vector<float> in;
        float ci;
        cout<<"请输入一组样本值"<<endl;
        while (cin.peek()!='\n'){
            cin.clear();
            cin>>ci;
            in.emplace_back(ci);
        }
        sort(in.begin(),in.end());
        for (float &ii:in) cout<<ii<<endl;
        return in;
    }

    float Sample_stats::midl(vector<float> &in){//求中位数
        int mid = int(in.size() / 2);
        float result;
        if (in.size() % 2 != 0)
            return in.at(mid);
        else{
            result = (in.at(mid) + in.at(mid - 1)) / 2;
            return result;
        }
    }

    float Sample_stats::average(vector<float> &in){//求平均值
        float result=0;
        for (float &ii:in) result+=ii;
        result/=float (in.size());
        return result;
    }

     float Sample_stats::utmostgap(vector<float> &in){//求极差
        float result=*(in.end()-1)-*in.begin();
         return result;
    }

    float Sample_stats::variance(vector<float> &in){//求方差
        float result, re1, aver;
        aver = average(in);
        result = 0;
        for (float &ii : in){
            re1 = ii - aver;
            result += powf(re1,2);
        }
        result /= float(in.size()) - 1;
        return result;
    }

    void Sample_stats::oripattern(vector<float> &in, const float k){//求原点矩
        float result;
        result = 0;
        for (float &ii : in)
            result += powf(ii,k);
        cin.clear();
        result /= float(in.size());
        cout<<"该组数据"<<k<<"阶原点矩为"<<result<<endl;
    }

    void Sample_stats::centrepat(vector<float> &in, const float k){//求中心距
        float result, aver, re1;
        aver = average(in);//平均数
        result = 0;
        for (float &ii : in){
            re1 = ii - aver;
            result += powf(re1,k);
        }
        cin.clear();
        result /= float(in.size());
        cout<<"该组数据"<<k<<"阶中心矩为"<<result<<endl;
    }

    void Sample_stats::expr(vector<float> &in){//求经验分布函数
         vector<vector<float>> ci;
         int sz = int(in.size());
        for (int i = 0, j1 = 0; i < sz; ++i) {
            ci.emplace_back();
            ci.at(j1).emplace_back(in.at(i));
            ci.at(j1).emplace_back(1);
            for (int jj = i + 1; jj < sz; jj++){
                if (in.at(jj)==ci.at(j1).at(0)){
                    ci.at(j1).at(1)++;
                    i++;
                }
            }
            j1++;
        }
        for (vector<float> &pp : ci)
            pp.at(1) /= float(sz);
        for (auto pp1= ci.begin() + 1; pp1 != ci.end(); pp1++)
            pp1->at(1) += (pp1 - 1)->at(1);
        cout<<"本组数据的经验分布函数为"<<endl;
        for (vector<float>&cii : ci){
            for(float vv : cii) cout<<vv<<"\t";
            cout<<endl;
        }
    }

int main() {
    Sample_stats();
    return 0;
}
