#include "ListMenu.h"

#include<iostream>
using namespace std;

ListMenu::ListMenu(BaseMenu*p)
{
	parent=p;
}


ListMenu::~ListMenu(void)
{
}
void ListMenu::Show()
{	
	//system("cls");
	cout<<"****单链表的基本操作及应用********\n";
	cout<<"*\t1.创建\n";
	cout<<"*\t2.插入\n";
	cout<<"*\t3.删除\n";
	cout<<"*\t4.查找\n";
	cout<<"*\t5.退出\n";
	cout<<"*********************************\n";
}
void ListMenu::DoEvent(int ID)
{
	LinkList L;
	InitList_L(L);
	switch(ID)
	{
		case 1:
			OnCreate();
			break;
		case 2:
			OnInsert();
			break;
		case 3:
			OnDelete();
			break;
		case 4:
			OnGetElem();
			break;
		case 5:
			OnExit();
			break;
		default:
			OnInvalidate();
	}
}

void ListMenu::OnCreate()
{
	cout<<"******创建单链表******"<<endl;
	cout<<"请输入创建长度：";
	int n;
	cin>>n;
	CreatList_L(L,n);
}

void ListMenu::OnInsert()
{
	cout<<"******插入元素******"<<endl;
	cout<<"插入位置及插入值："<<endl;
	int i;
	ElemType e;
	cin>>i>>e;
	ListInsert_L(L,i,e);
}
void ListMenu::OnDelete()
{
	cout<<"******删除元素******"<<endl;
	cout<<"删除位置："<<endl;
	int i;
	ElemType e;
	cin>>i;
	ListDelete_L(L,int i,e)
}
void ListMenu::OnGetElem()
{
	cout<<"******查找元素******"<<endl;
	cout<<"查找位置："<<endl;
	int i;
	cin>>i;
	ElemType e;
	GetElem_L(L,i,e);
	cout<<e<<endl;
}
void ListMenu::OnShow()
{
	ListTraverse(LinkList L,Status(*visit)(ElemType))

}
void ListMenu::OnExit()
{

}
void ListMenu::OnInvalidate()
{}

Status ListMenu::InitList_L(LinkList&L)
{
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;
	return OK;
}

Status ListMenu::DestroyList_L(LinkList&L)
{
	LinkList p=L;
	while(p)
	{
		L=p->next;
		delete p;
		p=L;
	}
	return OK;
}

Status ListMenu::ListEmpty_L(LinkList L)
{
	if(L->next)
		return ERROR;
	return OK;
}
int ListLength_L(LinkList L)
{
	LinkList p=L;
	int i=0;
	while(p->next)p=p->next;i++;
	return i;

}
Status ListMenu::GetElem_L(LinkList L,int i,ElemType&e)
{
	//L为带头结点的单链表的头指针
	//当i个元素存在时，其值赋给e并返回OK,否则返回ERROR
	LinkList p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)return ERROR;
	e=p->data;
	return OK;
}
		
Status ListMenu::ListInsert_L(LinkList&L,int i,ElemType e)
{
	LinkList p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)return ERROR;
	LinkList s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
Status ListMenu::ListDelete_L(LinkList&L,int i,ElemType&e)
{
	LinkList p=L;
	int j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1)return ERROR;
	LinkList q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	return OK;
}
void ListMenu::CreatList_L(LinkList&L,int n)
{
	//逆序输入n个元素的值，建立带表头结点的单链线性表L
	 L=(LNode*)malloc(sizeof(LNode));//先建立一个带头结点的单链表
	L->next=NULL;
	for(int i=n;i>0;i--)
	{
		LinkList p=(LNode*)malloc(sizeof(LNode));//生成新结点
		cin>>p->data;//输入元素值
		p->next=L->next;//插入到表头
		L->next=p;
	}

}


void ListMenu::MergeList_L(LinkList&La,LinkList&Lb,LinkList&Lc)
{
	//已知单链线性表La Lb
	//
	LinkList pa=La->next;
	LinkList pb=Lb->next;
	LinkList pc=La;
	Lc=pc;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
		pc->next=pa?pa:pb;
		free(Lb);

}
Status ListMenu::ListTraverse(LinkList L,Status(*visit)(ElemType))
{
	LinkList p=L->next;
	while(p)
	{
		if(visit(p->data)==ERROR)return ERROR;
		p=p->next;
	}
	return OK;
}
		
