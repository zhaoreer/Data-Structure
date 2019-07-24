#pragma once
#include "def.h"
#include "basemenu.h"
typedef int ElemType;
	typedef struct LNode{
	ElemType data;
	struct LNode*next;
	}LNode,*LinkList;
class ListMenu :public BaseMenu
{
private:
	Status InitList_L(LinkList&L);
	Status DestroyList_L(LinkList&L);
	Status ListEmpty_L(LinkList L);
	int ListLength_L(LinkList L);
	Status GetElem_L(LinkList L,int i,ElemType&e);
	Status ListInsert_L(LinkList&L,int i,ElemType e);
	Status ListDelete_L(LinkList&L,int i,ElemType&e);
	void CreatList_L(LinkList&L,int n);
	void MergeList_L(LinkList&La,LinkList&Lb,LinkList&Lc);
	Status ListTraverse(LinkList L,Status(*visit)(ElemType));
public:
	ListMenu(BaseMenu*p);
	~ListMenu(void);
	void Show();
	void DoEvent(int ID);

	void OnCreate();
	void OnInsert();
	void OnDelete();
	void OnGetElem();
	void OnShow();
	void OnExit();
	void OnInvalidate();

};




