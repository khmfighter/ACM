
/*#include<stdio.h>

int getMaxSum(int **a, int n)
{
	int max = 0;
	for(int i = n-1; i > 0; i--)
		for(int j = 0; j <= i-1; j++)
		{
			(a[i][j] > a[i][j+1]) ? max = a[i][j] : max = a[i][j+1];
			a[i-1][j] = a[i-1][j] + max;
		}
	return a[0][0];
}

int main()
{
	int n;
	int sum = 0;
	int **a;
	scanf("%d", &n);
	a = new int*[n];
	for(int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	for(i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
		{
			scanf("%d", &a[i][j]);
		}

	sum = getMaxSum(a, n);
	printf("%d\n", sum);
	
	for(i = 0; i < n; i++)
		delete [] a[i];
	delete [] a;
	return 0;
}*/