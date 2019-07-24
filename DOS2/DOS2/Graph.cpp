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
		printf("**************二叉树的基本操作及应用******\n");
		printf("*1 创建二叉树                           *\n");
		printf("*2 遍历二叉树（先/中/后）                 *\n");
		printf("*3 计算树的深度                          *\n");
		printf("*4 计算叶子节点个数                       *\n");
		printf("*5 查找双亲                                *\n");
		printf("*6 查找兄弟                               *\n");
		printf("*7 Huffman编码（应用）                      *\n");
		printf("*8 退出 *\n");
		printf("******************************************\n");
		printf("请选择：");
		scanf("%d,&n);