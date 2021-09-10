#pragma once
#include "Hcn.h"
class Nutlenh :
    public Hcn
      
{
public:
    CString nd;
    int gt;
    int chon;
    Nutlenh() :Hcn() {
        gt = 0;
        chon = 0;
    }
    Nutlenh(int mx1, int my1, int mx2, int my2, CString mnd, int mgt) : Hcn(mx1, my1, mx2, my2) {
        nd.Format(mnd);
        gt = mgt;
        chon = 0;
    }
    void vehinh(CClientDC* pdc);
};

