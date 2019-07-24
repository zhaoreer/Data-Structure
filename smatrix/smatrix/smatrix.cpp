#include"smatrix.h"
#include<iostream>
#include<cmath>
using namespace std;
Status PrintMatrix(TSMatrix A)
{
	int i;
	for(i=0;i<A.tu;i++)
		cout<<A.data[i].i<<"\t"
		<<A.data[i].j<<"\t"
		<<A.data[i].e<<endl;
	return OK;
}
Status  TransposeSMatrix(TSMatrix A,TSMatrix&B)
{
	int num[MAXSIZE]={0},cpos[MAXSIZE]={0};
	int i,index;
	for(i=0;i<A.tu;i++)
		num[A.data[i].j]++;
	for(i=1;i<=A.nu;i++)
		cpos[i]=cpos[i-1]+num[i-1];
	for(i=0;i<A.tu;i++)
	{
		index=cpos[A.data[i].j];
		B.data[index].i=A.data[i].j;
		B.data[index].j=A.data[i].i;
		B.data[index].e=A.data[i].e;
		cpos[A.data[i].j]++;
	}
	B.nu=A.mu;
	B.mu=A.nu;
	B.tu=A.tu;
	return OK;
}
Status MultSMatrix(TSMatrix A,TSMatrix B,TSMatrix &C)
{
	if(A.nu!=B.mu)
		return ERROR;
	C.mu=A.mu;
	C.nu=B.nu;
	C.tu=0;
		int*Anum=new int[A.mu+1];
	memset(Anum,0,(A.mu+1)*sizeof(int));
	int*Arpos=new int[A.mu+1];
	memset(Arpos,0,(A.mu+1)*sizeof(int));

	int*Bnum=new int[B.mu+1];
	memset(Bnum,0,(B.mu+1)*sizeof(int));
	int*Brpos=new int[B.mu+1];
	memset(Brpos,0,(B.mu+1)*sizeof(int));
	int i,arow,p_up,brow,q,q_up,ccol;
	for (i=0;i<A.tu;i++)
		Anum[A.data[i].i]++;
	//计算A中每行非零元素在data中的起始下标
	for(i=1;i<=A.mu;i++)
		Arpos[i]=Arpos[i-1]+Anum[i-1];
	for(i=0;i<B.tu;i++)
		Bnum[B.data[i].i]++;
	//计算B中每行非零元素中的起始下标
	for(i=1;i<=B.mu;i++)
		Brpos[i]=Brpos[i-1]+Bnum[i-1];
	ElemType*mult=new ElemType[B.nu+1];
	for(arow=0;arow<=A.mu;arow++)
	{
		p_up=arow<A.mu?Arpos[arow+1]:A.tu+1;
		for(int p=Arpos[arow];p<p_up;p++)
		{
			memset(mult,0,(B.nu+1)*sizeof(ElemType));
			brow=A.data[p].j;
			q_up=brow<B.mu?Brpos[brow+1]:B.tu+1;
			for(q=Brpos[brow];q<q_up;q++)
			{
				mult[B.data[q].j]+=A.data[p].e*B.data[q].e;
			}
				for(ccol=1;ccol<=B.nu;ccol++)
				{
					if(fabs(mult[ccol])>1e-7)
					{
						C.data[C.tu].i=arow;
						C.data[C.tu].j=ccol;
						C.data[C.tu].e=mult[ccol];
						C.tu++;
					}
				}
			}
		}
		delete[]Anum;
		delete[]Arpos;
		delete[]Bnum;
		delete[]Brpos;
		return OK;
	}
