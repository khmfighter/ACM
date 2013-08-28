
#include<cstdio>

int main()
{
	int a[10000];
	for(int i = 0; i < 10000; i++)
	{
		a[i] = 0;
	}
	int digit;
	int left;
	int sum = 0;
	for(i = 1; i < 10000; i++)
	{
		digit = i % 10;
		left = i;
		sum = i;
		while(digit >= 0)
		{
			sum += digit;
			left = left/10;
			if(left == 0)break;
			digit = left % 10;
		}
		if(sum < 10000)
			a[sum] = 1;
	}

	for(i = 1; i < 10000; i++)
	{
		if(a[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}