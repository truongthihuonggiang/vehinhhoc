#include "pch.h"
#include "Tamgiac.h"

void Tamgiac::vehinh(CClientDC* pdc)
{
	int mx1 = (x1 + x2) / 2;
	int my1 = y1;
	int mx2 = x1;
	int my2 = y2;
	int mx3 = x2;
	int my3 = y2;
	pdc->MoveTo(mx1, my1);
	pdc->LineTo(mx2, my2);
	pdc->LineTo(mx3, my3);
	pdc->LineTo(mx1, my1);
}
