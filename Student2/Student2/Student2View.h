
// Student2View.h : CStudent2View ��Ľӿ�
//

#pragma once


class CStudent2View : public CView
{
protected: // �������л�����
	CStudent2View();
	DECLARE_DYNCREATE(CStudent2View)

// ����
public:
	CStudent2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CStudent2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Student2View.cpp �еĵ��԰汾
inline CStudent2Doc* CStudent2View::GetDocument() const
   { return reinterpret_cast<CStudent2Doc*>(m_pDocument); }
#endif

