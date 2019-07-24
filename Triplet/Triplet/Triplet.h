#include "def.h"


typedef int ElemType;//额外添加类型名定义

//采用动态分配的顺序存储
typedef ElemType*Triplet;//由InitTriplet分配3个元素存储空间

//基本操作的函数原型说明

Status InitTriplet (Triplet &T, ElemType v1, ElemType v2, ElemType v3);
//操作结果：构造了三原组T,元素e1,e2,和e3分别被赋以参数v1,v2和v3的值


Status DestroyTriplet(Triplet &T);
//操作结果单元组T被销毁

Status Get(Triplet T, int i, ElemType &e);
//初始条件：三原组T已经存在，1<=i<=3
//操作结果：用e返回T的第i个元的值

Status Put(Triplet &T, int i, ElemType e);
//初始条件：三原组T已经存在，1<=i<=3
//操作结果：改变T的的i个元的值为e

Status IsAscending(Triplet T);
//初始条件：三原组T已经存在
//操作结果：如果T的三个元素按升序排列，则返回1，否则返回0

Status IsDescending(Triplet T);
//初始条件：三原组T已经存在
//操作结果：如果T的三个元素按降序排列，则返回1，否则返回0

Status Max(Triplet T, ElemType &e);
//初始条件：三原组T已经存在
//操作结果：用e返回T的3个元素的最大值

Status Min(Triplet T, ElemType &e);
//初始条件：三原组T已经存在
//操作结果：用e返回T的3个元素中的最小值
