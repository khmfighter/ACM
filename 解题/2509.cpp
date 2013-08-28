
/*#include<cstdio>

int getCig(int n, int k, int left)
{
	if(n + left < k)
		return n;
	return n + getCig((n+left)/k, k, (n+left)%k);
}

int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k) == 2)
	{
		printf("%d\n", getCig(n, k, 0));
	}
	return 0;
}*/