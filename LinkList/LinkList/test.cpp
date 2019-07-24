
#include"LinkList.h"
#include<iostream>

using namespace std;
Status fun(ElemType e)
{
	cout << e << endl;
	return OK;
}
int main()
{
	LinkList L;
	initList_L(L);
	int i;
	for (i = 1; i <= 10; i++)
		ListInsert_L(L, 1, rand());
	ListTraverse(L, fun);
	system("pause");
	return 0;
}