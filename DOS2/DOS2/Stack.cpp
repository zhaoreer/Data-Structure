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
		printf("************ջ�Ļ���������Ӧ��*************\n");
		printf("*1 ��ջ                                   *\n");
		printf("*2 ��ջ                                   *\n");
		printf("*3 ȡջ��Ԫ��                              *\n");
		printf("*4 ���ʽ���(Ӧ�ã�                       *\n");
		printf("*5 �˳�                                    *\n");
		printf("******************************************\n");
		printf("��ѡ�� ");
		scanf("%d",&n);
		switch(n){
		case 1:
			printf("----��ջ----");break;
		case 2:
			printf("----��ջ----");break;
		case 3:
			printf("----ȡջ��Ԫ��---");break;
		case 4:
			printf("----���ʽ���---");break;
		case 5:break;
		default:
			printf("EEROR!");break;
		}
	}while(n!=5);
}
