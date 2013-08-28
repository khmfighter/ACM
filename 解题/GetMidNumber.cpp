#include<iostream>
using namespace std;
/*
A������������
left��A����߽�
right��A���ұ߽�
pivot: ��ֵ
�������ܣ���A�д���Pivot�����ŵ�pivot���ұߣ���pivotС�����ŵ�pivot�����
*/
int partition(int A[], int left, int right, int pivot)
{
	int i = left, j = right;
	int temp = A[pivot];
	A[pivot] = A[right];
	while(i < j)
	{
		while(A[i] <= temp && i < j)
		{
			i++;
		}
		if(i < j)
		{
			A[j] = A[i];
			j--;
		}
		while(A[j] > temp && i < j)
		{
			j--;
		}
		if(i < j)
		{
			A[i] = A[j];
			i++;
		}
	}

	A[i] = temp;

	return i;
}

/*
�������ܣ������λ��
A,B:��������������
n:����A\B��Ԫ�صĸ���
*/
int GetMidNumber(int C[], int n)
{
	int i;

	i = partition(C, 0, 2*n-1, n);
	while(i != n-1)
	{
		if(i < n)
		{
			i = partition(C, i+1, 2*n-1, i+1);
		}
		else
		{
			i = partition(C, 0, i-1, i-1);
		}
	}
	return C[i];
}

/*int main()
{
	int C[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<<GetMidNumber(C, 5);
}*/

