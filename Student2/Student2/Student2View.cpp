
// Student2View.cpp : CStudent2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Student2.h"
#endif

#include "Student2Doc.h"
#include "Student2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudent2View

IMPLEMENT_DYNCREATE(CStudent2View, CView)

BEGIN_MESSAGE_MAP(CStudent2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStudent2View ����/����

CStudent2View::CStudent2View()
{
	// TODO: �ڴ˴���ӹ������

}

CStudent2View::~CStudent2View()
{
}

BOOL CStudent2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CStudent2View ����

void CStudent2View::OnDraw(CDC* /*pDC*/)
{
	CStudent2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CStudent2View ��ӡ

BOOL CStudent2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CStudent2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CStudent2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CStudent2View ���

#ifdef _DEBUG
void CStudent2View::AssertValid() const
{
	CView::AssertValid();
}

void CStudent2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudent2Doc* CStudent2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudent2Doc)));
	return (CStudent2Doc*)m_pDocument;
}
#endif //_DEBUG


// CStudent2View ��Ϣ�������
