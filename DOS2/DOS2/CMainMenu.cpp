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
	printf("******************�㷨�����ݽṹ********************\n");
	printf("*1 ������Ļ���������Ӧ��     *\n");
	printf("*2 ջ�Ļ���������Ӧ��         *\n");
	printf("*3 ����Ļ���������Ӧ��       *\n");
	printf("*4 ���Ļ���������Ӧ��         *\n");
	printf("*5 ͼ�Ļ���������Ӧ��         *\n");
	printf("*6 �˳�                      *\n");
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

		