#pragma once
class Hinh
{
public:
	int x1, x2, y1, y2;
	Hinh();
	Hinh(int mx1, int my1, int mx2, int my2);
	void virtual vehinh(CClientDC *pdc)
	{

	}
	void virtual dichlen(int d);
	void virtual dichxuong(int d);
	void virtual dichtrai(int d);
	void virtual dichphai(int d);
	void virtual bienhinh(int d, int loai);
	int virtual kttronghinh(CPoint p);
};

