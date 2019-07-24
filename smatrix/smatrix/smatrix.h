#include"def.h"
//稀疏矩阵的三元组顺序存储表示
#define MAXSIZE 12500   //假设非零元个数的最大值为12500
typedef double ElemType;
typedef struct{
	int i,j;            //该非零元的行下标和列下标
	ElemType e;
}Triple;
typedef struct{
	Triple data[MAXSIZE]; //非零元三元组表data[1]未用
	int mu,nu,tu;      //矩阵的行数，列数和非零元个数
}TSMatrix;
Status TransposeSMatrix(TSMatrix A,TSMatrix &B);
Status MultSMatrix (TSMatrix A,TSMatrix B,TSMatrix &C);
Status PrintMatrix(TSMatrix A);
