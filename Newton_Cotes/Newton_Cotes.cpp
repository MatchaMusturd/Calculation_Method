#include "Newton_Cotes.h"


    Newton_Cotes::Newton_Cotes(const int div_,const bool t){
        s = new Split;
        s->func_choice(1, div_);
        chooserun(t, *s, div_);
        s->func_choice(2, div_);
        chooserun(t, *s, div_);
        s->func_choice(3, div_);
        chooserun(t, *s, div_);
        cin.clear();
    }

    Newton_Cotes::~Newton_Cotes(){
        delete s;
    }

    void Newton_Cotes::chooserun(const bool &c, const Split &s_, const int div_){
        if(c) run1(s_, div_);
        else run2(s_, div_);
    }

    void Newton_Cotes::run1(const Split &s_, const int div_) {//在每个等分区间内用不同的公式积分
        double n1, n2, n3;
        n1 = N_1(s_, div_);
        n2 = N_2(s_, div_);
        n3 = N_3(s_, div_);
        if (div_ <= 2){

            cout<<"用Cotes公式求积分得"<<n3<<endl;

            cout<<"用Simpson公式求积分得"<<n2<<endl;

            cout<<"用梯形公式求积分得"<<n1<<endl;
        }
        else if (div_ <= 4){

            cout<<"用Simpson公式求积分得"<<n2<<endl;

            cout<<"用梯形公式求积分得"<<n1<<endl;
        }
        else{
            cout<<"用梯形公式求积分得"<<n1<<endl;
        }
    }

    void Newton_Cotes::run2(const Split &s_, const int div) {//不同的积分公式用不同的等分区间使细分区间步长相同
        Split y = s_;
        double n1, n2, n3;
        int div_ = div;

        n3 = N_3(s_, div_);

        div_ *= 2;
        y.ab /= 2;
        n2 = N_2(y, div_);

        div_ *= 2;
        y.ab /= 2;
        n1 = N_1(y, div_);

        cout<<"用Cotes公式求积分得"<<setprecision(9)<<n3<<endl;
        //setprecision保留小数
        cout<<"用Simpson公式求积分得"<<setprecision(9)<<n2<<endl;

        cout<<"用梯形公式求积分得"<<setprecision(9)<<n1<<endl;
    }

    double Newton_Cotes::N_1(const Split&y, const int div_){//梯形公式
        double result;
        double hh = y.ab / 2;
        vector<double> x;//装区间端点
        x.reserve(div_ + 1);
        for (int i = 0; i < div_ + 1; i++)
            x.emplace_back(y.cc + y.ab * float(i));
        result = 0;
        for (int i = 1; i < div_; ++i)
            result += y.funchoice(x.at(i));
        result *= 2;
        result += y.a;
        result *= hh;
        return result;
    }

    double Newton_Cotes::N_2(const Split&y, const int div_){//Simpson公式
        double result, re1, re2, fc;
        double pt = y.ab / 2;
        int dv = 2 * div_;
        double hh = y.ab / 6;
        vector<double> x;
        x.reserve(dv + 1);
        for (int i = 0; i < dv + 1; i++)
            x.emplace_back(y.cc + pt * float(i));

        re1 = 0;
        re2 = 0;
        for (int i = 1; i < dv; ++i) {
            fc = y.funchoice(x.at(i));
            if (i % 2==1) re1 += fc ;
            else if (i % 2==0) re2 += fc;
        }
        re1 *= 4;
        re2 *= 2;
        result = re1 + re2;
        result += y.a;
        result *= hh;
        return result;
    }

    double Newton_Cotes::N_3(const Split&y, const int div_){//Cotes公式
        double result, re1, re2, re3, fc;
        double pt = y.ab / 4;
        int dv = 4 * div_;
        double hh = y.ab / 90;
        vector<double> x;
        x.reserve(dv + 1);
        for (int i = 0; i < dv + 1; i++)
            x.emplace_back(y.cc + pt * float(i));

        re1 = 0;
        re2 = 0;
        re3 = 0;
        for (int i = 1; i < dv; ++i) {
            fc = y.funchoice(x.at(i));
            if (i % 2==1) re1 += fc;
            else if(i % 2==0&&i % 4!=0) re2 += fc;
            else if (i % 4==0) re3 += fc;
        }
        re1 *= 32;
        re2 *= 12;
        re3 *= 14;
        result = re1 + re2 + re3;
        result += 7 * y.a;
        result *= hh;
        return result;
    }




int main() {
    int div;
    bool t;
    cout<<"输入0将求积分区间等分后在每个等分区间内用不同的复化求积公式"<<endl;
    cout<<"输入1在求积分区间内用不同的复化求积公式后使细分求积小区间数相同"<<endl;
    cout<<"请输入";
    cin>>t;

    if(!t) cout<<"所有公式的区间等分数相同"<<endl;
    else{
        cout<<"输入的区间等分数为使用Cotes公式的区间等分数"<<endl;
        cout<<"使用Simpson公式的区间等分数为输入值的二倍"<<endl;
        cout<<"使用梯形公式的区间等分数为输入值的四倍"<<endl;
    }
    cout<<"请输入将求积区间等分数";
    cin>>div;
    Newton_Cotes give_me_a_name(div, t);
    return 0;
}
