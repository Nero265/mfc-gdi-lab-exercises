
// LV01View.h : interface of the CLV01View class
//

#pragma once


class CIND_19546View : public CView
{
protected: // create from serialization only
	CIND_19546View() noexcept;
	DECLARE_DYNCREATE(CIND_19546View)

	bool m_showGrid = true; //pocetno stanje neka bude da je grid ukljucen

// Attributes
public:
	CLV01Doc* GetDocument() const;

// Operations
public:
	void DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle);
	void DrawPolygon(CDC* pDC, CPoint* points, int n);

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CIND_19546View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // debug version in LV01View.cpp
inline CLV01Doc* CLV01View::GetDocument() const
   { return reinterpret_cast<CLV01Doc*>(m_pDocument); }
#endif

