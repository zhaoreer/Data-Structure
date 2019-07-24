
#include "LinkList.h"
#include<iostream>
using namespace std;

Status initList_L(LinkList&L)
{
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;
	return OK;
}
int ListLength_(LinkList L)
{
	LinkList p=L;
	int i=0;
	while(p->next)p=p->next,i++;
	return i;
}
Status GetElem_L(LinkList L,int i,ElemType &e)//算法2.8
{
//L为带头结点的单链表的头指针
//当i个元素存在时，其赋值给e并返回OK，否则返回ERROR
LinkList p=L->next;
	int j=1;
	while (p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)return ERROR;
	e=p->data;
	return OK;
}//GetElem_L
Status ListInsert_L(LinkList&L, int i, ElemType e)//算法2.9
 {
	 LinkList p = L;
	 int j = 0;
	 for (j = 0; j < i - 1; i)
	 {
		 if (p)
			 p = p->next;
	 }
	 if (p)
	 {
		 LinkList q = new LNode;
		 q->data = e;
		 q->next = p->next;
		 p->next = q;
		 return OK;
	 }
	 return ERROR;
}
Status ListDelete_L(LinkList&L, int i,ElemType&e)//算法2.10
{
	LinkList p = L;
	int j = 0;
	for (j = 0; j < i - 1; j++)
	{
		if (p)
			p = p->next;
	}
	if (p && p->next)
	{
		e = p->next->data;
		LinkList q = p->next;
		p->next = q->next;
		delete q;
		return OK;
	}
	return ERROR;

}
void CreateList_(LinkList&L,int i, int n)//算法2.11
{
	LinkList p = L;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (i = n; i > 0; --i) {
		p= (LinkList)malloc(sizeof(LNode));
	  scanf_s ("%d",&p->data);
		p->next = L->next; L->next = p;
	}
}//

Status DestroyList_L(LinkList &L)
{
	LinkList p = L;
	{
		while (p)
		{
			L = p->next;
			delete p;
			p = L;
		}
		return OK;
	}
}
	Status ListEmpty_L(LinkList L)
	{
		if (L->next)
			return ERROR;
		return OK;
	}
	void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)//算法2.12
	{
		LinkList pa,pb, pc;
		pa = La->next; pb = Lb->next;
		Lc = pc = La;
		while (pa && pb) {
			if (pa->data <= pb->data) {
				pc->next = pa; pc = pa; pa = pa->next;
			}
			else {
				pc->next = pb; pc = pb; pb = pb->next;
			}
		}
		pc->next = pa ? pa : pb;
		free(Lb);
	}//MergeList_L
	Status A(LinkList L){
		LinkList Q, p;
		if (L&&L->next) {
			Q = L; L = L->next; p = L;
			while (p->next)p = p->next;
			p->next = Q; Q  ->next = NULL;

		}
		return OK;

	}//A
	Status ListTraverse(LinkList L, Status(*visit)(ElemType))
	{
		LinkList p = L->next;
		while (p)
		{
			if (visit(p->data) == ERROR)return ERROR;
			p= p->next;
		}
		return OK;
	}

