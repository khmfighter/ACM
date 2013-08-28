
#include<stdio.h>

bool reverse(bool a)
{
	if(a)
		return false;
	else
		return true;
}

int getNum(int n, bool *a)
{
	int count = 0;
	for(int i = 1; i < n+1; i++)
	{
		int j = 1;
		int k = j*i;
		while(k < n+1)
		{
			a[k] = reverse(a[k]);
			j++;
			k = j*i;
		}
	}

	for(i = 1; i < n+1; i++)
	{
		if(a[i])
			count++;
	}
	return count;
}

int main()
{
	int n;
	int *testCase;
	bool *init;
	scanf("%d", &n);
	testCase = new int[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &testCase[i]);
		init = new bool[testCase[i] + 1];
		for(int j = 1; j < testCase[i] + 1; j++)
		{
			init[j] = false;
		}
		printf("%d\n", getNum(testCase[i], init));
		delete []init;
		init = NULL;
	}
	return 0;
}