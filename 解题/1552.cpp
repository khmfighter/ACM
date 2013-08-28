
/*#include<cstdio>
#include<cstdlib>

int compare(const void *a, const void *b)
{
	int one = *(int *)a;
	int two = *(int *)b;
	return one - two;
}

bool bSearch(int t, int *a, int n)
{
	int left = 0;
	int right = n - 1;
	int middle = 0;
	while(left <= right)
	{
		middle = (left + right)/2;
		if(t < a[middle])
			right = middle - 1;
		else if(t > a[middle])
			left = middle + 1;
		else return true;
	}
	return false;
}

int getPair(int *a, int n)
{
	int count = 0;
	qsort(a, n, sizeof(int), compare);
	for(int i = 0; a[i] <= a[n-1]/2; i++)
	{
		if(bSearch(2*a[i], a, n))
			count++;
	}
	return count;
}

int main()
{
	int a[15];
	int n = 0;
	int input;
	scanf("%d", &input);
	while(input != -1)
	{
		if(input != 0)
		{
			a[n++] = input;
		}
		else
		{
			printf("%d\n", getPair(a, n));
			n = 0;
		}
		scanf("%d", &input);
	}
	return 0;
}*/