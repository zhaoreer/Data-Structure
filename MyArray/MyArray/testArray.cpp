#include"MyArray.h"
#include<iostream>
using namespace std;

int main()
{
	Array A;
	InitArray(A,4,3,4,5,8);
	Assign(A,3.5,2,3,4,5);
	ElemType e;
	Value( e,A ,2,3,4, 5);
	cout<<e<<endl;
	system("pause");
	return 0;
}
		