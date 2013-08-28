
#include<cstdio>

int main()
{
	int miles = 0;
	int prehour = 0;
	int speed, hour;
	int n;
	scanf("%d", &n);
	while(n != -1)
	{
		prehour = 0;
		miles = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &speed, &hour);
			miles = miles + speed * (hour - prehour);
			prehour = hour;
		}
		printf("%d miles\n", miles);
		scanf("%d", &n);
	}
	return 0;
}