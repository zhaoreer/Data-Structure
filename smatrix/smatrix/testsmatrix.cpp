#include"smatrix.h"
#include<iostream>

using namespace std;

int main()

{
	/*TSMatrix A={{1,2,12,1,3,9,3,1,-3,3,6,14,4,3,24,5,2,18,6,1,15,6,4,-7},6,7,8};
	PrintMatrix(A);
	TSMatrix B;
	TransposeSMatrix(A,B);
	cout << "" << endl;
	PrintMatrix(B);*/
	TSMatrix A={{1,1,3,1,4,5,2,2,-1,3,1,2},3,4,4};
	TSMatrix B={{1,2,2,2,1,1,3,1,-2,3,2,4},4,2,4};
	TSMatrix C;
	MultSMatrix(A,B,C);
	PrintMatrix(A);
	cout<<""<<endl;
	PrintMatrix(B);
	cout<<""<<endl;
	PrintMatrix(C);
	
	return 0;
}