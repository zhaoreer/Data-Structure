#include "Array.h"
ShowMainMenu::Array()
{
}
ShowMainMenu::~Array()
{
}
void Array(){
	int n;
	do{
		printf("\n");
		printf("************ϵ�������ѹ���洢��Ӧ��*************\n");
		printf("*1 ����                 *\n");
		printf("*2 ��ʾ             *\n");
		printf("*3 ����˷���Ӧ�ã�         *\n");
		printf("*4 �˳�                 *\n");
		printf("***********************\n");
		printf("��ѡ�� ");
		scanf("%d",&n);
		switch(n){
		case 1:
			printf("----����--");break;
		case 2:
			printf("----��ʾ---");break;
		case 3:
			printf("----����˷�---");break;
		case4:break;
		default:
			printf("EEROR!");break;
		}
	}while(n!=4);
}