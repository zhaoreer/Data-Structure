
// Student2View.cpp : CStudent2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStudent2View 构造/析构

CStudent2View::CStudent2View()
{
	// TODO: 在此处添加构造代码

}

CStudent2View::~CStudent2View()
{
}

BOOL CStudent2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CStudent2View 绘制

void CStudent2View::OnDraw(CDC* /*pDC*/)
{
	CStudent2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CStudent2View 打印

BOOL CStudent2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudent2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CStudent2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CStudent2View 诊断

#ifdef _DEBUG
void CStudent2View::AssertValid() const
{
	CView::AssertValid();
}

void CStudent2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudent2Doc* CStudent2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudent2Doc)));
	return (CStudent2Doc*)m_pDocument;
}
#endif //_DEBUG


// CStudent2View 消息处理程序
