#include<stdarg.h>
#include"MyArray.h"
#include<iostream>
using namespace std;
Status InitArray(Array &A,int dim,...)//若维数dim和各维长度合法，则构造相应的数组A,并返回OK;
{
	if (dim<1||dim>MAX_ARRAY_DIM) return ERROR;
	A.dim=dim;
	A.bounds=(int *)malloc(dim *sizeof(int));
	if(!A.bounds) return ERROR;    //若各维长度合法，则存入A.bounds,并求出A的元素总数elemtotal
	 int elemtotal=1;
	 va_list ap;
	 va_start(ap,dim);   //ap为va_list类型，是存放变长参数表信息的数组
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
	 A.constants[dim-1]=1;  //L=1,指针的增减以元素的大小为单位
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
			//若ap指示的各下标值合法，则求出该元素在A中相对应的地址
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
			//A是n维数组，e为元素变量，随后是n个下标值
			//若下标不越界，则e赋值为所指定的元素A的元素值
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
