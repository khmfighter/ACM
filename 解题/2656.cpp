
/*#include<cstdio>

int main()
{
	int days;
	int max = 0;
	int home, school;
	int index = 0;
	scanf("%d", &days);
	while(days != 0)
	{
		max = 0;
		index = 0;
		for(int i = 0; i < days; i++)
		{
			scanf("%d%d", &school, &home);
			if(school + home > 8 && school + home >max)
			{
				max = school + home;
				index = i;
			}
		}
		if(max == 0)printf("%d\n", 0);
		else
			printf("%d\n", index+1);
		scanf("%d", &days);
	}
	return 0;
}*/