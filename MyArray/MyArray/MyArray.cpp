#include<stdarg.h>
#include"MyArray.h"
#include<iostream>
using namespace std;
Status InitArray(Array &A,int dim,...)//��ά��dim�͸�ά���ȺϷ���������Ӧ������A,������OK;
{
	if (dim<1||dim>MAX_ARRAY_DIM) return ERROR;
	A.dim=dim;
	A.bounds=(int *)malloc(dim *sizeof(int));
	if(!A.bounds) return ERROR;    //����ά���ȺϷ��������A.bounds,�����A��Ԫ������elemtotal
	 int elemtotal=1;
	 va_list ap;
	 va_start(ap,dim);   //apΪva_list���ͣ��Ǵ�ű䳤��������Ϣ������
	 int i;
	 for(i=0;i<dim;++i)
	 {
		 A.bounds[i]=va_arg(ap,int);
		 if (A.bounds[i]<0) return ERROR;
		 elemtotal *=A.bounds[i];
	 }
	 va_end(ap);
	 A.base=new ElemType [elemtotal];
	 A.constants=new int[dim];
	 A.constants[dim-1]=1;  //L=1,ָ���������Ԫ�صĴ�СΪ��λ
	 for (i=dim-2;i>=0;i--)
		 A.constants[i]=A.constants[i+1]* A.bounds[i+1];
	 return OK;
}


	 Status DestoryArray(Array &A)
	 {
		 delete A.base;
		 A.base=0;
		 delete A.bounds;
		 A.bounds=0;
		 delete A.constants;
		 A.constants=0;
		 return OK;
	 }
		Status Locate(Array A,va_list ap,int &off)  
			//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�����Ӧ�ĵ�ַ
		{
			off=0;
			int i;
			for(i=0;i<A.dim;++i)
			{
				int ind=va_arg(ap,int);
				if(ind<0||ind>=A.bounds[i])
					return ERROR;
				off+=A.constants[i] *ind;
			}
			return OK;
		}
		Status Value(ElemType &e,Array A,...)
			//A��nά���飬eΪԪ�ر����������n���±�ֵ
			//���±겻Խ�磬��e��ֵΪ��ָ����Ԫ��A��Ԫ��ֵ
		{
			va_list ap;
			va_start(ap,A);
			int off;
			if (Locate(A,ap,off)==ERROR)
			return ERROR;
			e=*(A.base+off);
			return OK;
		}
		Status Assign(Array &A,ElemType e,...)
		{
			va_list ap;
			va_start(ap,e);
			int off;
			if (Locate(A,ap,off)==ERROR)
			return ERROR;
			*(A.base+off)=e;
			return OK;
		}
