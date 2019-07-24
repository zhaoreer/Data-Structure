#include "StdAfx.h"
#include "BaseMenu.h"
#include "stackMenu.h"
#include<iostream>
using namespace std;
extern BaseMenu*pBase;

BaseMenu::BaseMenu(void):parent(0)
{
}


BaseMenu::~BaseMenu(void)
{
}
void  BaseMenu::Show()
{
	cout << endl;
	cout << "*******************算法与数据结构******************\n";
	cout << "* 1  单链表的基本操作及应用                       *\n";
	cout << "* 2  栈的基本操作及应用                           *\n";
	cout << "* 3  数组的基本操作及应用                         *\n";
	cout << "* 4  树的基本操作及应|用                           *\n";
	cout << "* 5  图的基本操作及应用                           *\n";
	cout << "* 6  退出                                         *\n";
	cout << "***************************************************\n";

}
void BaseMenu::DoEvent(int ID)
{
	switch (ID)
	{
	case 1:
		OnList();
		break;
	case 2:
		OnStack();
		break;
	case 3:
		OnArray();
		break;
	case 4:
		OnTree();
		break;
	case 5:
		OnGraph();
		break;
	case 6:
		OnExit();
		break;
	default:
		OnInputError(6);
		break;
	}
}
void BaseMenu::OnList()
{
}
void BaseMenu::OnStack()
{
}
void BaseMenu::OnArray()
{
}
void BaseMenu::OnTree()
{
}
void BaseMenu::OnGraph()
{
}
void BaseMenu::OnExit()
{
	BaseMenu *tmp = pBase;
	pBase = tmp->parent;
	delete tmp;
}
void BaseMenu::OnInputError(int n)
{
	cout << "输入错误，请选择1～" << n << endl;
}

