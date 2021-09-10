#pragma once
#include "Hinh.h"
class Tamgiac :
    public Hinh
{
public:
    Tamgiac():Hinh(){}
    Tamgiac(int mx1, int my1, int mx2, int my2):Hinh(mx1, my1, mx2, my2){}
    void vehinh(CClientDC* pdc);
};

