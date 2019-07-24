#include "CMainMenu.h"
#include"BaseMenu.h"
BaseMenu::MainMenu()
{
}
BaseMenu::~MainMenu()
{
}
void CMainMenu::ShowMenu()
{
	printf("\n");
	printf("******************算法与数据结构********************\n");
	printf("*1 单链表的基本操作及应用     *\n");
	printf("*2 栈的基本操作及应用         *\n");
	printf("*3 数组的基本操作及应用       *\n");
	printf("*4 树的基本操作及应用         *\n");
	printf("*5 图的基本操作及应用         *\n");
	printf("*6 退出                      *\n");
	printf("******************************\n");
}

void CMainMenu::Event(int EvenID)
{
	BaseMenu*tmp;
	switch (EvenID)
	{
	case ID_LINKLIST:
		SUBMENU(CListMenu)
			break;
	case ID_STACK:
		SUBMENU(CStackMenu)
			break;
	case ID_EXIT:
		MAIN_EXIT = ture;
		break;
	default:
		invalidataAction();
		break;
	}
}

		