#include"def.h"
//ϡ��������Ԫ��˳��洢��ʾ
#define MAXSIZE 12500   //�������Ԫ���������ֵΪ12500
typedef double ElemType;
typedef struct{
	int i,j;            //�÷���Ԫ�����±�����±�
	ElemType e;
}Triple;
typedef struct{
	Triple data[MAXSIZE]; //����Ԫ��Ԫ���data[1]δ��
	int mu,nu,tu;      //����������������ͷ���Ԫ����
}TSMatrix;
Status TransposeSMatrix(TSMatrix A,TSMatrix &B);
Status MultSMatrix (TSMatrix A,TSMatrix B,TSMatrix &C);
Status PrintMatrix(TSMatrix A);
