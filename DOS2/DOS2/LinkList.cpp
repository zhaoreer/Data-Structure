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
		printf("**************������Ļ���������Ӧ��****************\n");
		printf("*1 ����                                           *\n");
		printf("*2 ����                                           *\n");
		printf("*3 ɾ��                                           *\n");
		printf("*4 ����                                           *\n");
		printf("*5 ��ʾ                                   *\n");
		printf("*6 ͨѶ¼ ��Ӧ�ã�                                   *\n");
		printf("*7 �˳�                                         *\n");
		printf("******************************************\n");
		printf("��ѡ��");
		scanf("%d,&n);
			switch(n){
			case 1:
				printf("-----------����������---------");break;
			case 2:
				printf("---------����Ԫ��-----");break;
			case 3:
				printf("---------ɾ��Ԫ��-----");break;
			case 4:
				printf("-------����Ԫ��------");break;
			case 5:
				printf("------��ʾ����-------");break;
			case 6:
				printf("-------ͨѶ¼--------");break;
			case 7:break;
			default:
				printf("ERROR!");break��
		}
	}while(n!=7);
}
