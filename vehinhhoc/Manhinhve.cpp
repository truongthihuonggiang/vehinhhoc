#include "pch.h"
#include "Manhinhve.h"

Manhinhve::Manhinhve()
{
	CString ndhcn, ndtg, ndpt, ndtn,ndtron, nddichuyen;
	ndhcn.Format(_T("HCN"));
	ndtron.Format(_T("Tron"));
	ndtg.Format(_T("Tam giac"));
	ndpt.Format(_T("phong to"));
	ndtn.Format(_T("thu nho"));
	nddichuyen.Format(_T("di chuyen"));
	int mx,  my;
	mx = XP;
	my = YP;
	int d = 35;
	int h = 90;
	nls[0] = Nutlenh(mx, my, mx + h, my + d, ndhcn, 0);
	nls[0].chon = 1;
	mx = mx + h + 10;
	nls[1] = Nutlenh(mx, my, mx + h, my + d, ndtron, 1);
	mx = mx + h + 10;
	nls[2] = Nutlenh(mx, my, mx + h, my + d, ndtg, 2);
	mx = mx + h + 10;
	nls[3] = Nutlenh(mx, my, mx + h, my + d, ndpt, 3);
	mx = mx + h + 10;
	nls[4] = Nutlenh(mx, my, mx + h, my + d, ndtn, 4);
	mx = mx + h + 10;
	nls[5] = Nutlenh(mx, my, mx + h, my + d, nddichuyen, 5);
	khungve = Hcn(XD, YD, XD + DAI, YD + CAO);
	nlchon = 0; //the hien nut lenh dang dc chon
	n = 0; //luu tru so hinh dc ve
	dangve = 0;
	hinhchon = 0; //hinh dang dc chon xu ly
}

void Manhinhve::vehinh(CClientDC* pdc)
{
	for (int i = 0; i < 6; i++)
		nls[i].vehinh(pdc);
	khungve.vehinh(pdc);
	for (int i = 0; i < n; i++)
		ds[i]->vehinh(pdc);
}

void Manhinhve::taohinh()
{
	if (nlchon == 0)
	{
		ds[n] = new Hcn(p1.x, p1.y, p2.x, p2.y);
		hinhchon = n;
		n++;

	}
	if (nlchon == 2)
	{
		ds[n] = new Tamgiac(p1.x, p1.y, p2.x, p2.y);
		hinhchon = n;
		n++;

	}
	if (nlchon == 5 || nlchon == 3 || nlchon == 4)
	{
		//tim hinh dc chon
		for (int i = 0; i < n; i++)
		{
			if (ds[i]->kttronghinh(p1) == 1)
			{
				hinhchon = i;
			}
		}
	
	}
	
}

void Manhinhve::bamnutlenh(CPoint p)
{
	for (int i = 0; i < 6; i++)
	{
		if (nls[i].kttronghinh(p) == 1)
		{
			nls[nlchon].chon = 0; //chuyn nl cu ve trang thai ko chon
			nlchon = i;
			nls[i].chon = 1; //chuyen nl moi ve trang thai dc chon

		}
	}
}

void Manhinhve::capnhathinhchon()
{
	
		ds[hinhchon]->x1 = p1.x;
		ds[hinhchon]->y1 = p1.y;
		ds[hinhchon]->x2 = p2.x;
		ds[hinhchon]->y2 = p2.y;
	
	
	
}

void Manhinhve::dichuyenhinh(int dx, int dy)
{
	ds[hinhchon]->dichphai(dx);
	ds[hinhchon]->dichxuong(dy);
}

void Manhinhve::phongtohinh()
{
	int d= sqrt((p1.x - p2.x) * (p1.x - p2.x)
		+ (p1.y - p2.y) * (p1.y - p2.y));

	ds[hinhchon]->bienhinh(d, 1);
	if (ds[hinhchon]->x2 > khungve.x2 || ds[hinhchon]->x1 < khungve.x1 || ds[hinhchon]->y1 < khungve.y1
		|| ds[hinhchon]->y2 >khungve.y2)
	{
		ds[hinhchon]->bienhinh(d, -1);
	}
}

void Manhinhve::thunhohinh()
{
	int d = sqrt((p1.x - p2.x) * (p1.x - p2.x)
		+ (p1.y - p2.y) * (p1.y - p2.y));

	ds[hinhchon]->bienhinh(d, -1);
	
}
