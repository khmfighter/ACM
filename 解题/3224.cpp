
#include<cstdio>

int main()
{
	int n;
	int input;
	scanf("%d", &n);
	int max = 0;
	int sum = 0;
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		sum = 0;
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &input);
			sum += input;
		}
		if(sum > max)
		{
			max = sum;
			index = i;
		}
	}
	printf("%d\n", index + 1);
	return 0;
}