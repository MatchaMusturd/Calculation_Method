//
// Created by CHH on 2023/6/26.
//

#ifndef ARRAY_LEATSQUARES_H
#define ARRAY_LEATSQUARES_H

#include <iostream>
#include <vector>

#define vf std::vector<float>
#define vvf std::vector<std::vector<float> >

class leastsquares{
protected:


    typedef struct{
        vf re;
        float error;
    }Ret;

    Ret result;
    float tt,t2,t,result2;
    vvf st2;
    vf stt,st,st3;

public:

    float cons(vvf &in);//常数拟合

    Ret fit_2(vvf &in,int k);//二次及以上拟合

};

class fit:public leastsquares{
public:

    fit();

    vvf input();//输入一组数据

    void leastsquares(vvf &input);


private:
    bool ju;
    float in;
    Ret resu;
    vf stt,ss;
    vvf st3,sam;
    int k=2;

};
#endif //ARRAY_LEATSQUARES_H
