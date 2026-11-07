
// IND_19546View.cpp : implementation of the CIND19546View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "IND_19546.h"
#endif

#include "IND_19546Doc.h"
#include "IND_19546View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIND19546View

IMPLEMENT_DYNCREATE(CIND19546View, CView)

BEGIN_MESSAGE_MAP(CIND19546View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
//	ON_WM_ICONERASEBKGND()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CIND19546View construction/destruction

CIND19546View::CIND19546View() noexcept
{
	// TODO: add construction code here

}

CIND19546View::~CIND19546View()
{
}

BOOL CIND19546View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CIND19546View drawing

void CIND19546View::OnDraw(CDC* pDC)
{
	CIND19546Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	int oldMode = pDC->SetGraphicsMode(GM_ADVANCED);

	CRect rect;
	GetClientRect(&rect);

	pDC->SetWindowExt(500, 500);
	pDC->SetViewportExt(rect.right, rect.bottom);

	DrawFigure(pDC);

	if (m_showGrid) {
		CPen gridPen(PS_SOLID, 1, RGB(224, 224, 224));
		CPen* pOldPen = pDC->SelectObject(&gridPen);

		for (int x = 0; x <= 500; x += 25) {
			pDC->MoveTo(x, 0);
			pDC->LineTo(x, 500);
		}

		for (int y = 0; y <= 500; y += 25) {
			pDC->MoveTo(0, y);
			pDC->LineTo(500, y);
		}

		pDC->SelectObject(pOldPen);
	}

	pDC->SetGraphicsMode(oldMode);
}

void CIND19546View::Translate(CDC* pDC, float dX, float dY, bool rightMultiply)
{
	XFORM xForm;
	xForm.eM11 = 1.0f;
	xForm.eM12 = 0.0f;
	xForm.eM21 = 0.0f;
	xForm.eM22 = 1.0f;
	xForm.eDx = dX;
	xForm.eDy = dY;
	pDC->ModifyWorldTransform(&xForm, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND19546View::Scale(CDC* pDC, float sX, float sY, bool rightMultiply)
{
	XFORM xForm;
	xForm.eM11 = sX;
	xForm.eM12 = 0.0f;
	xForm.eM21 = 0.0f;
	xForm.eM22 = sY;
	xForm.eDx = 0.0f;
	xForm.eDy = 0.0f;
	pDC->ModifyWorldTransform(&xForm, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND19546View::Rotate(CDC* pDC, float angle, bool rightMultiply)
{
	float c = cos(angle);
	float s = sin(angle);
	XFORM xForm;
	xForm.eM11 = c;
	xForm.eM12 = s;
	xForm.eM21 = -s;
	xForm.eM22 = c;
	xForm.eDx = 0.0f;
	xForm.eDy = 0.0f;
	pDC->ModifyWorldTransform(&xForm, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND19546View::DrawFigure(CDC* pDC)
{
	int nSavedDC = pDC->SaveDC();

	CBrush potBrush(RGB(205, 133, 63));
	CPen potPen(PS_SOLID, 1, RGB(0, 0, 0));

	CBrush* pOldBrush = pDC->SelectObject(&potBrush);
	CPen* pOldPen = pDC->SelectObject(&potPen);

	pDC->Rectangle(187, 425, 312, 450);

	CPoint pot[4] = {
		CPoint(200, 450),
		CPoint(212, 500),
		CPoint(287, 500),
		CPoint(300, 450)
	};
	pDC->Polygon(pot, 4);

	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);

	pDC->RestoreDC(nSavedDC);
}

void CIND19546View::DrawMetafilePart(CDC* pDC, CString filename, CRect rect)
{
	HENHMETAFILE hEmf = GetEnhMetaFile(filename);
	if (hEmf != NULL) {

		pDC->PlayMetaFile(hEmf, &rect);
		DeleteEnhMetaFile(hEmf);
	}
}

// CIND19546View printing

BOOL CIND19546View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIND19546View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIND19546View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CIND19546View diagnostics

#ifdef _DEBUG
void CIND19546View::AssertValid() const
{
	CView::AssertValid();
}

void CIND19546View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIND19546Doc* CIND19546View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIND19546Doc)));
	return (CIND19546Doc*)m_pDocument;
}
#endif //_DEBUG


// CIND19546View message handlers

void CIND19546View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 'g' || nChar == 'G') {

		m_showGrid = !m_showGrid;

		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}

BOOL CIND19546View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(&rect);

	CBrush lightBlueBrush(RGB(135, 207, 235));
	pDC->FillRect(&rect, &lightBlueBrush);

	return TRUE;
}
