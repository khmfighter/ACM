#include<iostream>
using namespace std;
/*
A：待排序数组
left：A的左边界
right：A的右边界
pivot: 轴值
函数功能：将A中大于Pivot的数放到pivot的右边，比pivot小的数放到pivot的左边
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
函数功能：求得中位数
A,B:代表两个数集合
n:代表A\B中元素的个数
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

