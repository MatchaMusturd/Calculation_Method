//
// Created by CHH on 2023/6/10.
//

#ifndef NEWTON_COTES_NEWTON_COTES_H
#define NEWTON_COTES_NEWTON_COTES_H

#include <vector>
#include <iomanip>
#include "Split.h"

using namespace std;

class Newton_Cotes{
public:

    Newton_Cotes(int, bool);
    ~Newton_Cotes();

private:
    int a;
    Split *s;

    static void chooserun(const bool &, const Split &, int);

    static void run1(const Split &,int) ;

    static void run2(const Split &,int) ;

    static double N_1(const Split&y, int);

    static double N_2(const Split&y, int);

    static double N_3(const Split&y, int);
};



#endif //NEWTON_COTES_NEWTON_COTES_H
