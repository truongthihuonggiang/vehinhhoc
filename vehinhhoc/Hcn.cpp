#include "pch.h"
#include "Hcn.h"

void Hcn::vehinh(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}
