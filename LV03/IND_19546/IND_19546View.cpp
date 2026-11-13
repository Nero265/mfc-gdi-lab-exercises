
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
END_MESSAGE_MAP()

// CIND19546View construction/destruction

CIND19546View::CIND19546View() noexcept
{
	// TODO: add construction code here
	for (int i = 0; i < 9; i++) {
		m_pieces[i] = new DImage();
		CString name;
		name.Format(_T("p%d.bmp"), i + 1);
		if (!m_pieces[i]->Load(name)) {
			TCHAR dir[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, dir);
			CString msg;
			msg.Format(_T("Nece mi: %s\nRadni folder: %s"), (LPCTSTR)name, dir);
			AfxMessageBox(msg);
		}
	}

}

CIND19546View::~CIND19546View()
{
	for (int i = 0; i < 9; i++)
		delete m_pieces[i];
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
	pDC->SetGraphicsMode(GM_ADVANCED);

	DrawPuzzlePiece(pDC, m_pieces[0], 200, 200, 0, 1, 1, false, false);
	DrawPuzzlePiece(pDC, m_pieces[1], 400, 200, 3.14159f / 6, 1, 1, false, false);
	DrawPuzzlePiece(pDC, m_pieces[2], 600, 200, 0, 1, 1, true, false);


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
}

void CIND19546View::Translate(CDC* pDC, float dX, float dY, bool rightMultiply)
{
	XFORM xf = { 1,0,0,1,dX, dY };
	pDC->ModifyWorldTransform(&xf, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND19546View::Scale(CDC* pDC, float sX, float sY, bool rightMultiply)
{
	XFORM xf = { sX, 0, 0, sY, 0, 0 };
	pDC->ModifyWorldTransform(&xf, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND19546View::Rotate(CDC* pDC, float angle, bool rightMultiply)
{
	XFORM xf = { cosf(angle), sinf(angle), -sinf(angle), cosf(angle), 0, 0};
	pDC->ModifyWorldTransform(&xf, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND19546View::Mirror(CDC* pDC, bool mx, bool my, bool rightMultiply)
{
	XFORM xf = { mx ? -1.0f : 1.0f, 0, 0, my ? -1.0f : 1.0f, 0, 0 };
	pDC->ModifyWorldTransform(&xf, rightMultiply ? MWT_RIGHTMULTIPLY : MWT_LEFTMULTIPLY);
}

void CIND19546View::DrawPuzzlePiece(CDC* pDC, DImage* img, float x, float y,
	float angle, float sx, float sy, bool mx, bool my)
{
	int w = img->Width();
	int h = img->Height();

	// trenutno stanje trransformersa
	XFORM old;
	pDC->GetWorldTransform(&old);

	// Transformacije se primenjuju redosledom kojim su napisane (rightMultiply = true)
	Translate(pDC, -w / 2.0f, -h / 2.0f, true); // centar slike u koordinatni pocetak
	Scale(pDC, sx, sy, true);
	Mirror(pDC, mx, my, true);
	Rotate(pDC, angle, true);                   // radijani
	Translate(pDC, x, y, true);                 // na zadatu poziciju (centar dela)

	img->Draw(pDC, CRect(0, 0, w, h), CRect(0, 0, w, h));

	// vrati staru transformaciju
	pDC->SetWorldTransform(&old);
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
	if (nChar == 'g' || nChar == 'G')
	{
		m_showGrid = !m_showGrid;

		Invalidate();
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}
