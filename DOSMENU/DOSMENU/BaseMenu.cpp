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
	cout<<"****************数据结构课程设计***************\n";
	cout<<"*\t1.单链表的基本操作及应用\n";
	cout<<"*\t2.栈的基本操作及应用\n";
	cout<<"*\t3.数组的基本操作及应用\n";
	cout<<"*\t4.树的基本操作及应用\n";
	cout<<"*\t5.图的基本操作及应用\n";
	cout<<"*\t6.退出\n";
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
	cout<<"请重新输入命令"<<endl;
	system("pause");
}