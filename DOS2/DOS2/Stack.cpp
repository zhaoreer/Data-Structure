#include "Stack.h"
ShowMainMenu::Stack()
{
}
ShowMainMenu::~Stack()
{
}
void Stack(){
	int n;
	do{
		printf("\n");
		printf("************栈的基本操作及应用*************\n");
		printf("*1 进栈                                   *\n");
		printf("*2 出栈                                   *\n");
		printf("*3 取栈顶元素                              *\n");
		printf("*4 表达式求解(应用）                       *\n");
		printf("*5 退出                                    *\n");
		printf("******************************************\n");
		printf("请选择： ");
		scanf("%d",&n);
		switch(n){
		case 1:
			printf("----进栈----");break;
		case 2:
			printf("----出栈----");break;
		case 3:
			printf("----取栈顶元素---");break;
		case 4:
			printf("----表达式求解---");break;
		case 5:break;
		default:
			printf("EEROR!");break;
		}
	}while(n!=5);
}
