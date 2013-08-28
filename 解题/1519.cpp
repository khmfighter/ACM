
/*#include<cstdio>

long int getDigitRoot(long int integer)
{
	long int sum = 0;
	long int end;
	end = integer;
	while(end != 0)
	{
		sum += end % 10;
		end = end / 10;
	}
	if(sum < 10)
		return sum;
	else
		return getDigitRoot(sum);
}

int main()
{
	long int input;
	scanf("%ld", &input);
	while(input != 0)
	{
		printf("%ld\n", getDigitRoot(input));
		scanf("%ld", &input);
	}
	return 0;
}*/