
// LV01View.cpp : implementation of the CLV01View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LV01.h"
#endif

#include "LV01Doc.h"
#include "LV01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLV01View

IMPLEMENT_DYNCREATE(CIND_19546View, CView)

BEGIN_MESSAGE_MAP(CIND_19546View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_KEYDOWN()
ON_WM_CHAR()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CLV01View construction/destruction

CIND_19546View::CIND_19546View() noexcept
{
	// TODO: add construction code here

}

CIND_19546View::~CIND_19546View()
{
}

BOOL CIND_19546View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLV01View drawing

void CIND_19546View::OnDraw(CDC* pDC)
{
	CLV01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	// Uzimamo dimenzije klijentskog dela prozora
	/*CRect rect;
	GetClientRect(&rect);*/

	// Podesavanje mapiranja koordinata
	//pDC->SetMapMode(MM_ISOTROPIC);
	//pDC->SetWindowExt(500, 500);       // Logicki opseg od 0 do 500
	//pDC->SetViewportExt(rect.right, rect.bottom); // Fizicka velicina prozora

	//pDC->SetViewportOrg(25, 25);

	CPen greenPen(PS_SOLID, 4, RGB(0, 255, 0));
	CPen thinGreenPen(PS_SOLID, 2, RGB(0, 255, 0));
	CBrush orangeBrush(RGB(235, 122, 52));

	CPen* pOldPen = pDC->SelectObject(&greenPen);
	CBrush* pOldBrush = pDC->SelectObject(&orangeBrush);

	CPoint orangeTriangle[3] = {
		CPoint(75, 25),
		CPoint(425, 25),
		CPoint(250, 200)
	};

	DrawPolygon(pDC, orangeTriangle, 3);

	pDC->SelectObject(thinGreenPen);
	DrawRegularPolygon(pDC, 250, 100, 40, 4, 0.0f);


	CBrush yellowBrush(RGB(228, 235, 26));
	CPoint yellowTriangle[3] = {
		CPoint(125,75),
		CPoint(250, 200),
		CPoint(125, 200)
	};

	pDC->SelectObject(yellowBrush);
	pDC->SelectObject(greenPen);
	DrawPolygon(pDC, yellowTriangle, 3);

	pDC->SelectObject(thinGreenPen);
	DrawRegularPolygon(pDC, 165, 165, 20, 7, 0.0f);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

	CBrush purpleBrush(RGB(143, 16, 227));
	pDC->SelectObject(greenPen);
	pDC->SelectObject(purpleBrush);

	pDC->Rectangle(125, 200, 250, 325);


	CBrush pinkBrush(RGB(242, 136, 214));

	pDC->SelectObject(greenPen);
	CPoint pinkTr[3] = {
		CPoint(125,200),
		CPoint(125, 325),
		CPoint(250,325)
	};
	pDC->SelectObject(pinkBrush);

	DrawPolygon(pDC, pinkTr, 3);


	pDC->SelectObject(thinGreenPen);
	DrawRegularPolygon(pDC, 170, 300, 20, 9, 0.0f);


	CBrush hatchBrush(HS_DIAGCROSS, RGB(0, 0, 255));
	pDC->SelectObject(&hatchBrush);

	CPoint paralelogram[4] = {
		CPoint(250, 200),   
		CPoint(375, 75),
		CPoint(375, 200),
		CPoint(250,325)
	};
	DrawPolygon(pDC, paralelogram, 4);


	CBrush redBrush(RGB(255, 0, 0));
	CPoint redTriangle[3] = {
		CPoint(125,325),
		CPoint(250,325),
		CPoint(125, 450)
	};

	pDC->SelectObject(redBrush);
	DrawPolygon(pDC, redTriangle, 3);

	pDC->SelectObject(thinGreenPen);
	DrawRegularPolygon(pDC, 165, 355, 20, 7, 0.0f);

	CBrush darkGreen(RGB(0, 150, 0));

	CPoint darkGreenTriangle[3] = {
		CPoint(250,325),
		CPoint(375, 200),
		CPoint(375, 450)
	};

	pDC->SelectObject(darkGreen);
	pDC->SelectObject(greenPen);
	DrawPolygon(pDC, darkGreenTriangle, 3);


	pDC->SelectObject(thinGreenPen);

	DrawRegularPolygon(pDC, 325, 325, 30, 6, 0.0f);


	CPoint pinkTriangle[3] = {
		CPoint(250,325),
		CPoint(75, 475),
		CPoint(425, 475)
	};

	pDC->SelectObject(greenPen);
	pDC->SelectObject(pinkBrush);
	DrawPolygon(pDC, pinkTriangle, 3);

	pDC->SelectObject(thinGreenPen);
	DrawRegularPolygon(pDC, 250, 410, 35, 5, 0.0f);

	if (m_showGrid) {
		//svetlosiva olovka za linije (1 piksel)
		CPen gridPen(PS_SOLID, 1, RGB(224, 224, 224));
		CPen* pOldPen = pDC->SelectObject(&gridPen); //selektujemo olovku u Dc i pamtimo staru

		//vertikalne linije od x = 0 do x = 500 sa korakom 25
		for (int x = 0; x <= 500; x += 25) {
			pDC->MoveTo(x, 0);
			pDC->LineTo(x, 500);
		}

		//horizontalne linije od y = 0 do y  = 500 sa korakom 25
		for (int y = 0; y <= 500; y += 25) {
			pDC->MoveTo(0, y);
			pDC->LineTo(500, y);
		}

		pDC->SelectObject(pOldPen); //vracamo staru olovku nazad na kraju da ne dodje do curenja resursa
	}
}

void CIND_19546View::DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle) {
	//dinamicki alociramo niz temena na soinovu br stranica n
	CPoint* points = new CPoint[n];

	const double PI = 3.14159265358979323846;

	for (int i = 0; i < n; ++i) {
		//racunica za ugao za svakot eme ravnomerno oko krtuga
		double alfa = rotAngle + i * (2.0 * PI / n);

		points[i].x = cx + (int)(r * cos(alfa));
		points[i].y = cy + (int)(r * sin(alfa));
	}

	pDC->Polygon(points, n); //zatvoren poligon se crta

	delete[] points;
}

void CIND_19546View::DrawPolygon(CDC* pDC, CPoint* points, int n) {
	//gdi fja polygon automatski iscrtava ivice i popunaja unutrassnjost trenutno selektovanom cetkom i olovkom u CDC-u
	pDC->Polygon(points, n);
}


// CLV01View printing

BOOL CIND_19546View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CIND_19546View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CIND_19546View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLV01View diagnostics

#ifdef _DEBUG
void CIND_19546View::AssertValid() const
{
	CView::AssertValid();
}

void CIND_19546View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLV01Doc* CIND_19546View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLV01Doc)));
	return (CLV01Doc*)m_pDocument;
}
#endif //_DEBUG


// CLV01View message handlers



void CIND_19546View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 'g' || nChar == 'G') {

		m_showGrid = !m_showGrid;

		Invalidate(); //obavestavamo win da je prozor "nevazeci" i da se mora ponovo nacrtatti
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}

BOOL CIND_19546View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	// 1. Uzimamo dimenzije celog klijentskog prozora
	CRect rect;
	GetClientRect(&rect);

	// 2. Pravimo tamno sivu cetku (npr. RGB(50, 50, 50))
	CBrush darkGrayBrush(RGB(50, 50, 50));

	// 3. Bojimo ceo prozor tom cetkom
	pDC->FillRect(&rect, &darkGrayBrush);

	// 4. Vracamo TRUE da kazemo Windows-u da je pozadina uspesno obrisana
	// (NE pozivamo CView::OnEraseBkgnd jer bi on ponovo prebojao u belo!)
	return TRUE;
}
