#include "def.h"
typedef int ElemType;
typedef struct  LNode{
	ElemType  data;
	struct LNode *next;
}LNode, *LinkList;

Status initList_L(LinkList&L);


Status DestroyList_(LinkList&L);
Status ListEmpty_L(LinkList L);

int ListLength_(LinkList L);
Status GetElem_L(LinkList, int, ElemType&);//算法2.8
Status ListInsert_L(LinkList &L, int i, ElemType e);//算法2.9
void GreateList_(LinkList&L, int n);//算法2.11
void MergeList_(LinkList&La, LinkList&Lb, LinkList&Lc);//算法2.12
Status ListTraverse(LinkList L, Status(*visit)(ElemType));

