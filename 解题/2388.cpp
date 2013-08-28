
/*#include<cstdio>

int getMid(int *a, int begin, int end, int n)
{
	int pivot = (begin + end)/2;
	int temp = a[pivot];
	int i = begin;
	int j = end;
	a[pivot] = a[end];
	
	while(i != j)
	{
		while(a[i] < temp && i < j)
			i++;
		if(i < j)
		{
			a[j] = a[i];
			j--;
		}
		while(a[j] > temp && i < j)
			j--;
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}
	}
	a[i] = temp;
	if(i < n/2)
	{
		return getMid(a, i+1, end, n);
	}
	else if(i > n/2)
	{
		return getMid(a, begin, i-1, n);
	}
	else
		return a[i];
}

int main()
{
	int n;
	int *a;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d\n", getMid(a, 0, n-1, n));
	return 0;
}*/