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
	cout << "*******************�㷨�����ݽṹ******************\n";
	cout << "* 1  ������Ļ���������Ӧ��                       *\n";
	cout << "* 2  ջ�Ļ���������Ӧ��                           *\n";
	cout << "* 3  ����Ļ���������Ӧ��                         *\n";
	cout << "* 4  ���Ļ���������Ӧ|��                           *\n";
	cout << "* 5  ͼ�Ļ���������Ӧ��                           *\n";
	cout << "* 6  �˳�                                         *\n";
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
	cout << "���������ѡ��1��" << n << endl;
}

