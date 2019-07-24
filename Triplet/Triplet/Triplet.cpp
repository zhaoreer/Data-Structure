// Triplet.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"triplet.h"

#include<iostream>
using namespace std;

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
	//构造了三元组T,依次置T的3的元素的出值为v1,v2和v3.
	T = (ElemType*)malloc(3 * sizeof(ElemType));//分配3 个元素的存储空间
	if (!T)exit(OVERFLOW);//分配空间失败
	T[0] = v1; T[1] = v2; T[2] = v3;
	return OK;
}//InitTriple


Status DestroyTriple(Triplet &T)
{
	//销毁三元组T
	free(T);
	T = NULL;
		return OK;
}//DestroyTriplet


Status Get(Triplet T, int i, ElemType&e)
{
	//1<=i<=3.用e返回T的i个元的值
	if (i < 1 || i>3) return ERROR;
	e = T[i - 1];
	return OK;

}//Get

Status Put(Triplet &T, int i, ElemType e)
{
	//1<=i<=3,置T的i个元的值为e
	if (i < 1 || i>3)return ERROR;
	T[i - 1] = e;
	return OK;

}//Put

Status IsAscending(Triplet T)
{
	//如果T的三个元素按升序排列，则返回1，否则返回0
	return (T[0] <= T[1]) && (T[1] <= T[2]);

}//IsAscending


Status IsDescending(Triplet T)
{
	//如果T的三个元素按降序排列，则返回1，否则返回0
	return (T[0] >= T[1]) && (T[1] >= T[2]);

}//IsDscending

Status Max(Triplet T, ElemType &e)
{
	//用e返回T的3个元素中的最大值
	e = T[0];
	if (T[1] > e)e = T[1];
	if (T[2] > e)e = T[2];
	return OK;

}//Max


Status Min(Triplet T, ElemType &e)
{
	//用e 返回T的3个元素中的最小值
	e = T[0];
	if (T[1] < e)e = T[1];
	if (T[2] < e)e = T[2];
	return OK;

}//Min

int main()
{
    return 0;
}

