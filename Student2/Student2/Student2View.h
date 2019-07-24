
// Student2View.h : CStudent2View 类的接口
//

#pragma once


class CStudent2View : public CView
{
protected: // 仅从序列化创建
	CStudent2View();
	DECLARE_DYNCREATE(CStudent2View)

// 特性
public:
	CStudent2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CStudent2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Student2View.cpp 中的调试版本
inline CStudent2Doc* CStudent2View::GetDocument() const
   { return reinterpret_cast<CStudent2Doc*>(m_pDocument); }
#endif

