#include "pch.h"
#include "Nutlenh.h"

void Nutlenh::vehinh(CClientDC* pdc)
{
	if (chon == 1)
	{
		CBrush* newb = new CBrush(RGB(211, 211, 211));
		CBrush* oldb;
		oldb = pdc->SelectObject(newb);
		Hcn::vehinh(pdc);
		pdc->SelectObject(oldb);
	}
	else
	{
		Hcn::vehinh(pdc);
	}
	
	
	pdc->TextOutW(x1 + 10, y1 + 5, nd);
}
