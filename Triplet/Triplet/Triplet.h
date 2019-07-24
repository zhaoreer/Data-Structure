#include "def.h"


typedef int ElemType;//�����������������

//���ö�̬�����˳��洢
typedef ElemType*Triplet;//��InitTriplet����3��Ԫ�ش洢�ռ�

//���������ĺ���ԭ��˵��

Status InitTriplet (Triplet &T, ElemType v1, ElemType v2, ElemType v3);
//�����������������ԭ��T,Ԫ��e1,e2,��e3�ֱ𱻸��Բ���v1,v2��v3��ֵ


Status DestroyTriplet(Triplet &T);
//���������Ԫ��T������

Status Get(Triplet T, int i, ElemType &e);
//��ʼ��������ԭ��T�Ѿ����ڣ�1<=i<=3
//�����������e����T�ĵ�i��Ԫ��ֵ

Status Put(Triplet &T, int i, ElemType e);
//��ʼ��������ԭ��T�Ѿ����ڣ�1<=i<=3
//����������ı�T�ĵ�i��Ԫ��ֵΪe

Status IsAscending(Triplet T);
//��ʼ��������ԭ��T�Ѿ�����
//������������T������Ԫ�ذ��������У��򷵻�1�����򷵻�0

Status IsDescending(Triplet T);
//��ʼ��������ԭ��T�Ѿ�����
//������������T������Ԫ�ذ��������У��򷵻�1�����򷵻�0

Status Max(Triplet T, ElemType &e);
//��ʼ��������ԭ��T�Ѿ�����
//�����������e����T��3��Ԫ�ص����ֵ

Status Min(Triplet T, ElemType &e);
//��ʼ��������ԭ��T�Ѿ�����
//�����������e����T��3��Ԫ���е���Сֵ
