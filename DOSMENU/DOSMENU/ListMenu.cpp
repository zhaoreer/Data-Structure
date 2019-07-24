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
	cout<<"****������Ļ���������Ӧ��********\n";
	cout<<"*\t1.����\n";
	cout<<"*\t2.����\n";
	cout<<"*\t3.ɾ��\n";
	cout<<"*\t4.����\n";
	cout<<"*\t5.�˳�\n";
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
	cout<<"******����������******"<<endl;
	cout<<"�����봴�����ȣ�";
	int n;
	cin>>n;
	CreatList_L(L,n);
}

void ListMenu::OnInsert()
{
	cout<<"******����Ԫ��******"<<endl;
	cout<<"����λ�ü�����ֵ��"<<endl;
	int i;
	ElemType e;
	cin>>i>>e;
	ListInsert_L(L,i,e);
}
void ListMenu::OnDelete()
{
	cout<<"******ɾ��Ԫ��******"<<endl;
	cout<<"ɾ��λ�ã�"<<endl;
	int i;
	ElemType e;
	cin>>i;
	ListDelete_L(L,int i,e)
}
void ListMenu::OnGetElem()
{
	cout<<"******����Ԫ��******"<<endl;
	cout<<"����λ�ã�"<<endl;
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
	//LΪ��ͷ���ĵ������ͷָ��
	//��i��Ԫ�ش���ʱ����ֵ����e������OK,���򷵻�ERROR
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
	//��������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
	 L=(LNode*)malloc(sizeof(LNode));//�Ƚ���һ����ͷ���ĵ�����
	L->next=NULL;
	for(int i=n;i>0;i--)
	{
		LinkList p=(LNode*)malloc(sizeof(LNode));//�����½��
		cin>>p->data;//����Ԫ��ֵ
		p->next=L->next;//���뵽��ͷ
		L->next=p;
	}

}


void ListMenu::MergeList_L(LinkList&La,LinkList&Lb,LinkList&Lc)
{
	//��֪�������Ա�La Lb
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
		
