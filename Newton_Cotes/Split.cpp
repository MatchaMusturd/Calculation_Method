//
// Created by CHH on 2023/10/18.
//
#include "Split.h"


void Split::func_choice(const int choice, const int div){
    float end;
    if(choice==1){
        this->c = 1;
        cc = 0.5;
        end = 1;
        l = 0.5;
        a = func1(cc) + func1(end);
        ab = l / div;//ab为步长
        std::cout<<"function is pow(x,0.5) with a boarder of 0.5 to 1"<<std::endl;
    }else if(choice==2){
        this->c = 2;
        cc = 4;
        end = 5.2;
        l = 1.2;
        a = func2(cc) + func2(end);
        ab = l / div;//ab为步长
        std::cout<<"function is log(x) with a boarder of 4 to 5.2"<<std::endl;
    }else if(choice==3){
        this->c = 3;
        cc = 0;
        end = 1;
        l = 1;
        a = func3(cc) + func3(end);
        ab = l / div;//ab为步长
        std::cout<<"function is 4/(1+pow(x,2)) with a boarder of 0 to 1"<<std::endl;
    }
}

double Split::funchoice(const double &x) const{
    if(this->c==1) return func1(x);
    else if(this->c==2) return func2(x);
    else if(this->c==3) return func3(x);
    else return -1;
}

double Split::func1(const double &x){//求积函数
    return pow(x,0.5);//积分区间0.5~1
}

double Split::func2(const double &x){//求积函数
    return log(x);//积分区间4~5.2
}

double Split::func3(const double &x){//求积函数
    return 4 / (1 + pow(x,2));//积分区间0~1

}

Split::Split() = default;


