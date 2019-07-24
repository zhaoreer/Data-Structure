// Triplet.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"triplet.h"

#include<iostream>
using namespace std;

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
	//��������Ԫ��T,������T��3��Ԫ�صĳ�ֵΪv1,v2��v3.
	T = (ElemType*)malloc(3 * sizeof(ElemType));//����3 ��Ԫ�صĴ洢�ռ�
	if (!T)exit(OVERFLOW);//����ռ�ʧ��
	T[0] = v1; T[1] = v2; T[2] = v3;
	return OK;
}//InitTriple


Status DestroyTriple(Triplet &T)
{
	//������Ԫ��T
	free(T);
	T = NULL;
		return OK;
}//DestroyTriplet


Status Get(Triplet T, int i, ElemType&e)
{
	//1<=i<=3.��e����T��i��Ԫ��ֵ
	if (i < 1 || i>3) return ERROR;
	e = T[i - 1];
	return OK;

}//Get

Status Put(Triplet &T, int i, ElemType e)
{
	//1<=i<=3,��T��i��Ԫ��ֵΪe
	if (i < 1 || i>3)return ERROR;
	T[i - 1] = e;
	return OK;

}//Put

Status IsAscending(Triplet T)
{
	//���T������Ԫ�ذ��������У��򷵻�1�����򷵻�0
	return (T[0] <= T[1]) && (T[1] <= T[2]);

}//IsAscending


Status IsDescending(Triplet T)
{
	//���T������Ԫ�ذ��������У��򷵻�1�����򷵻�0
	return (T[0] >= T[1]) && (T[1] >= T[2]);

}//IsDscending

Status Max(Triplet T, ElemType &e)
{
	//��e����T��3��Ԫ���е����ֵ
	e = T[0];
	if (T[1] > e)e = T[1];
	if (T[2] > e)e = T[2];
	return OK;

}//Max


Status Min(Triplet T, ElemType &e)
{
	//��e ����T��3��Ԫ���е���Сֵ
	e = T[0];
	if (T[1] < e)e = T[1];
	if (T[2] < e)e = T[2];
	return OK;

}//Min

int main()
{
    return 0;
}

