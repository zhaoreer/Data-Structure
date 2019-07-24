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
		printf("************系数矩阵的压缩存储及应用*************\n");
		printf("*1 创建                 *\n");
		printf("*2 显示             *\n");
		printf("*3 矩阵乘法（应用）         *\n");
		printf("*4 退出                 *\n");
		printf("***********************\n");
		printf("请选择： ");
		scanf("%d",&n);
		switch(n){
		case 1:
			printf("----创建--");break;
		case 2:
			printf("----显示---");break;
		case 3:
			printf("----矩阵乘法---");break;
		case4:break;
		default:
			printf("EEROR!");break;
		}
	}while(n!=4);
}