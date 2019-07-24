#include "stdafx.h"
#include"triplet.h"

#include<iostream>
using namespace std;
int mian()
{
	Triplet T;
	int a, b;
	cout << &a << endl;
	//int b;
	cout << &b << endl;
	InitTriplet(T, 1, 2, 3);
	cout << T << endl;
	ElemType e;
	cout << IsAscending(T) << endl;
	Max(T, e);
	cout << e << endl;
	Min(T, e);
	cout << e << endl;
	return 0;


}