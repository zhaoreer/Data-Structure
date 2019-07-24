#include "LinkList.h"
ShowMainMenu::Linklist()
{
}
ShowMainMenu::~Linklist()
{
}
void LinkList(){
	int n;
	do{
		printf("\n");
		printf("**************单链表的基本操作及应用****************\n");
		printf("*1 创建                                           *\n");
		printf("*2 插入                                           *\n");
		printf("*3 删除                                           *\n");
		printf("*4 查找                                           *\n");
		printf("*5 显示                                   *\n");
		printf("*6 通讯录 （应用）                                   *\n");
		printf("*7 退出                                         *\n");
		printf("******************************************\n");
		printf("请选择：");
		scanf("%d,&n);
			switch(n){
			case 1:
				printf("-----------创建单链表---------");break;
			case 2:
				printf("---------插入元素-----");break;
			case 3:
				printf("---------删除元素-----");break;
			case 4:
				printf("-------查找元素------");break;
			case 5:
				printf("------显示链表-------");break;
			case 6:
				printf("-------通讯录--------");break;
			case 7:break;
			default:
				printf("ERROR!");break；
		}
	}while(n!=7);
}
