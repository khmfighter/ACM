
#include<iostream>
using namespace std;

int get_max_sum(int *a, int n)
{
	int max = 0;
	int b = 0;
	for(int i = 0; i < n; i++)
	{
		if(b > 0)
			b += a[i];
		else
			b = a[i];
		if(b > max)
			max = b;
	}
	return max;
}

int get_max_submatrix(int **a, int n)
{
	int i, j, k;
	int *b = new int[n];
	int max = 0;
	if(b == NULL)
	{
		cout<<"fatal error!"<<endl;
		exit(0);
	}

	for(i = 0;  i < n; i++)
	{
		for(k = 0; k < n; k++)
			b[k] = 0;
		for(j = i; j < n; j++)
		{
			for(k = 0; k < n; k++)
				b[k] += a[j][k];
			int temp = get_max_sum(b, n);
			if(temp > max)
				max = temp;
		}
	}

	delete []b;
	b = NULL;

	return max;
}

/*int main()
{
	int n;
	int **a;
	
	cin>>n;

	a = new int*[n];

	if(a == NULL)
	{
		exit(1);
	}

	for(int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		if(a[i] == NULL)
			exit(1);
	}

	for(i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin>>a[i][j];
		}

	cout<<get_max_submatrix(a, n);

	for(i = 0; i < n; i++)
	{
		delete []a[i];
		a[i] = NULL;
	}

	delete []a;
	a = NULL;
	return 0;
}*/