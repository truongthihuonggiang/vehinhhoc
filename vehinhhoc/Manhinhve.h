#pragma once
#include "Hcn.h"
#include "Hinh.h"
#include "Tamgiac.h"
#include "Nutlenh.h"
#define XP 20
#define YP 10
#define XD 20
#define YD 50
#define CAO 800
#define DAI 1200
class Manhinhve
{
public:
	int nlchon;
	Nutlenh nls[6];
	Hcn khungve;
	Hinh* ds[100];
	int n;
	CPoint p1, p2;
	int dangve;
	int hinhchon;
	Manhinhve();
	void vehinh(CClientDC* pdc);
	void taohinh();
	void bamnutlenh(CPoint p);
	void capnhathinhchon();
	void dichuyenhinh(int dx, int dy);
	void phongtohinh();
	void thunhohinh();
};

