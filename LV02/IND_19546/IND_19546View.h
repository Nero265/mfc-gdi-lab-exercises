
// IND_19546View.h : interface of the CIND19546View class
//

#pragma once


class CIND19546View : public CView
{
protected: // create from serialization only
	CIND19546View() noexcept;
	DECLARE_DYNCREATE(CIND19546View)

// Attributes
public:
	CIND19546Doc* GetDocument() const;

// Operations
public:
	void Translate(CDC* pDC, float dX, float dY, bool rightMultiply);
	void Scale(CDC* pDC, float sX, float sY, bool rightMultiply);
	void Rotate(CDC* pDC, float angle, bool rightMultiply);
	void DrawFigure(CDC* pDC);
	void DrawMetafilePart(CDC* pDC, CString filename, CRect rect);

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
	virtual ~CIND19546View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	bool m_showGrid = true;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnIconEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // debug version in IND_19546View.cpp
inline CIND19546Doc* CIND19546View::GetDocument() const
   { return reinterpret_cast<CIND19546Doc*>(m_pDocument); }
#endif

