#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ncbind.hpp"


class Calc {
public:
    Calc() {}
    ~Calc() {}
    int add(int a, int b) { return a+b; }
    int sub(int a, int b) { return a-b; }
    int mul(int a, int b) { return a*b; }
    int div(int a, int b) { return a/b; }
};

// テンプレート記述（マクロ併用）
NCB_REGISTER_CLASS(Calc) {
    NCB_CONSTRUCTOR(());
    NCB_METHOD(add);
    NCB_METHOD(sub);
    NCB_METHOD(mul);
    NCB_METHOD(div);
};
