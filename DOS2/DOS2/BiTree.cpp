#include "BiTree.h"
ShowMainMenu::BiTree()
{
}
ShowMainMenu::~BiTree()
{
}
void BiTree(){
	int n;
	do{
		printf("\n");
		printf("**************�������Ļ���������Ӧ��******\n");
		printf("*1 ����������                           *\n");
		printf("*2 ��������������/��/��                 *\n");
		printf("*3 �����������                          *\n");
		printf("*4 ����Ҷ�ӽڵ����                       *\n");
		printf("*5 ����˫��                                *\n");
		printf("*6 �����ֵ�                               *\n");
		printf("*7 Huffman���루Ӧ�ã�                      *\n");
		printf("*8 �˳� *\n");
		printf("******************************************\n");
		printf("��ѡ��");
		scanf("%d,&n);
			switch(n){
				case 1:
				printf("-----------����������----");break;
			case 2:
				printf("---------����������----");break;
			case 3:
				printf("---------�����������---");break;
			case 4:
				printf("-------����Ҷ�ӽڵ����---");break;
			case 5:
				printf("------����˫��----");break;
			case 6:
				printf("-------�����ֵ�-----");break;
			case 7:
				printf("------Huffman����----");break;
				case 8��break;
			default:
			printf("EEROR!");break;
		}
	}while(n!=8);
}