
/*#include<cstdio>

int getLength(int n)
{
	int count = 1;
	while( n != 1)
	{
		if(n % 2 != 0)
			n = 3*n + 1;
		else
			n = n/2;
		count++;
	}
	return count;
}

int main()
{
	long int max; 
	int begin, end;
	int m, n;
	while(scanf("%d%d", &begin, &end) == 2)
	{
		max = 0;
		(begin > end)?m = end: m = begin;
		(begin > end)?n = begin : n = end;
		for(int i = m; i <= n; i++)
		{
			if(getLength(i) > max)
				max = getLength(i);
		}
		printf("%d %d %d\n", begin, end, max);
	}
	return 0;
}*/