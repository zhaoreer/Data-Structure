#include<stdarg.h>
#include"def.h"

#define MAX_ARRAY_DIM  8

typedef double ElemType;
typedef  struct{
	ElemType *base;
	int  dim;
	int  *bounds;
	int  *constants;
}Array;
//��������ԭ�Ͳ���˵��

Status InitArray(Array &A, int dim,...);
Status DestoryArray(Array &A);
Status Value(ElemType &e,Array A,...);
Status Assign(Array &A,ElemType e,...);
