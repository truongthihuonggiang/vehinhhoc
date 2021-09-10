
// vehinhhocView.cpp : implementation of the CvehinhhocView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "vehinhhoc.h"
#endif

#include "vehinhhocDoc.h"
#include "vehinhhocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CvehinhhocView

IMPLEMENT_DYNCREATE(CvehinhhocView, CView)

BEGIN_MESSAGE_MAP(CvehinhhocView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CvehinhhocView construction/destruction

CvehinhhocView::CvehinhhocView() noexcept
{
	// TODO: add construction code here
	mhve = Manhinhve();

}

CvehinhhocView::~CvehinhhocView()
{
}

BOOL CvehinhhocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CvehinhhocView drawing

void CvehinhhocView::OnDraw(CDC* /*pDC*/)
{
	CvehinhhocDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	mhve.vehinh(&pdc);
}

void CvehinhhocView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CvehinhhocView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CvehinhhocView diagnostics

#ifdef _DEBUG
void CvehinhhocView::AssertValid() const
{
	CView::AssertValid();
}

void CvehinhhocView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CvehinhhocDoc* CvehinhhocView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CvehinhhocDoc)));
	return (CvehinhhocDoc*)m_pDocument;
}
#endif //_DEBUG


// CvehinhhocView message handlers


void CvehinhhocView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (mhve.khungve.kttronghinh(point) == 1)
	{
		mhve.p1.x = point.x;
		mhve.p1.y = point.y;
		mhve.p2.x = point.x;
		mhve.p2.y = point.y;
		mhve.taohinh();
		mhve.dangve = 1;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CvehinhhocView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	mhve.bamnutlenh(point);
	CClientDC pdc(this);
	/*if (mhve.khungve.kttronghinh(point) == 1 && mhve.dangve == 1)
	{
		mhve.p2.x = point.x;
		mhve.p2.y = point.y;
		//goi phuong thuc tao hinh va ve hinh
		mhve.capnhathinhchon();
	}*/

	mhve.vehinh(&pdc);

	mhve.dangve = 0;
	CView::OnLButtonUp(nFlags, point);
}


void CvehinhhocView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	float kc = sqrt((point.x - mhve.p2.x) * (point.x - mhve.p2.x) 
		+ (point.y - mhve.p2.y) * (point.y - mhve.p2.y));
	int dx = point.x - mhve.p2.x;
	int dy = point.y - mhve.p2.y;
	if (mhve.dangve == 1 && mhve.khungve.kttronghinh(point) == 1 && kc > 10)
	{
		CClientDC pdc(this);
		mhve.p2.x = point.x;
		mhve.p2.y = point.y;
		if(mhve.nlchon == 0 || mhve.nlchon == 1 || mhve.nlchon == 2)
			mhve.capnhathinhchon();
		if (mhve.nlchon == 5)
			mhve.dichuyenhinh(dx, dy);
		if (mhve.nlchon == 3)
			mhve.phongtohinh();
		if (mhve.nlchon == 4)
			mhve.thunhohinh();
		mhve.vehinh(&pdc);
	}
	CView::OnMouseMove(nFlags, point);
}
