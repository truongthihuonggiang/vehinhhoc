
// vehinhhocView.h : interface of the CvehinhhocView class
//

#pragma once
#include "Manhinhve.h"

class CvehinhhocView : public CView
{
protected: // create from serialization only
	CvehinhhocView() noexcept;
	DECLARE_DYNCREATE(CvehinhhocView)

// Attributes
public:
	CvehinhhocDoc* GetDocument() const;

// Operations
public:
	Manhinhve mhve;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CvehinhhocView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in vehinhhocView.cpp
inline CvehinhhocDoc* CvehinhhocView::GetDocument() const
   { return reinterpret_cast<CvehinhhocDoc*>(m_pDocument); }
#endif

