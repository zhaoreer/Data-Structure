#include "BaseMenu.h"
#include "ListMenu.h"
#include <iostream>
using namespace std;
extern BaseMenu*pBase;

BaseMenu::BaseMenu(void):parent(0)
{
}


BaseMenu::~BaseMenu(void)
{
}

void BaseMenu::Show()
{
	//system("cls");
	cout<<"****************���ݽṹ�γ����***************\n";
	cout<<"*\t1.������Ļ���������Ӧ��\n";
	cout<<"*\t2.ջ�Ļ���������Ӧ��\n";
	cout<<"*\t3.����Ļ���������Ӧ��\n";
	cout<<"*\t4.���Ļ���������Ӧ��\n";
	cout<<"*\t5.ͼ�Ļ���������Ӧ��\n";
	cout<<"*\t6.�˳�\n";
}

void BaseMenu::DoEvent(int ID)
{
	switch(ID)
	{
	case 1:
		OnList();
		break;
	case	 2:
		OnStack();
		break;
	case 3:
		OnArray();
		break;
	case 4:
		OnBinaryTree();
		break;
	case 5:
		OnGraph();
		break;
	case 6:
		OnExit();
		break;
	default:
		OnInvalidate();
	}
}

void BaseMenu::OnList()
{
	pBase=new ListMenu(pBase);
}
void BaseMenu::OnStack()
{}
void BaseMenu::OnArray()
{}
void BaseMenu::OnBinaryTree()
{}
void BaseMenu::OnGraph()
{}

void BaseMenu::OnExit()
{
	BaseMenu *temp=pBase->parent;
	delete pBase;
	pBase=temp;
}


void BaseMenu::OnInvalidate()
{
	cout<<"��������������"<<endl;
	system("pause");
}