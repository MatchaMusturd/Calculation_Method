
//
// Created by CHH on 2023/6/24.
//
//
// Created by CHH on 2023/6/23.
//
#include "Array1.h"
#include "leatsquares.h"
#include "arrayy.h"
#include "matrix_.h"

using namespace std;

float leastsquares::cons(vvf &in){//常数拟合

auto sz=in.at(0).size();
     tt=0;
     t2=0;
     for (int i=0;i<sz;i++) {
         tt+=in.at(1).at(i);
         t2+=in.at(2).at(i);
     }
     t=tt/t2;
     result2=0;
     for (int i=0;i<sz;i++){
          st.emplace_back();
          st.at(i)=t-in.at(1).at(i);
          st.at(i)*= st.at(i);
          st.at(i)*=in.at(2).at(i);
          result2+=st.at(i);
     }
     st.clear();
     result2= powf(result2,0.5);
     return result2;
}

leastsquares::Ret leastsquares::fit_2(vvf &in, int k){//二次及以上拟合
    esti ti;
    auto sz=in.at(0).size();
    for (int i = 0; i < k; ++i) {
        st2.emplace_back();
        for (int i2 = 0; i2 < k; ++i2) {
            t=0;
            for (int j=0;j<sz;j++){
                tt=in.at(2).at(j);//tt是权重
                t2= powf(in.at(0).at(j),float(i+i2));
                t+=tt*t2;
            }
            st2.at(i).emplace_back(t);
        }

    }

    for (int i1 = 0; i1 < k; ++i1) {
        t=0;
        for (int j=0;j<sz;j++){
            tt=in.at(1).at(j);//tt是y值
            t2= powf(in.at(0).at(j),float(i1));
            tt*=in.at(2).at(j);
            t+=tt*t2;
        }
        st2.at(i1).emplace_back(t);
    }
    cout<<k-1<<"次拟合矩阵为"<<endl;
    output(st2);

    stt=ti.estimate1(st2);
    st2.clear();
    for (float ii:stt) result.re.emplace_back(ii);

    for (float ii: in.at(0)) {
        t = 0;
        for (int i1 = 0; i1 < k; ++i1) {
            tt = stt.at(i1) * powf(ii, float(i1));
            t += tt;
        }
        st3.emplace_back(t);
    }
    t=0;
    for (int i=0;i<sz;i++){
        st3.at(i)-=in.at(1).at(i);
        st3.at(i)*= st3.at(i);
        st3.at(i)*=in.at(2).at(i);
        t+=st3.at(i);
    }
    t= powf(t,0.5);
    result.error=t;
    return result;
}