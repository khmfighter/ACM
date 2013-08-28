
#include<stdio.h>

int main()
{
	int numOfSets;
	int eat, alive;
	scanf("%d", &numOfSets);
	for(int i = 0; i < numOfSets; i++)
	{
		scanf("%d%d", &eat, &alive);
		if(eat >= alive)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
	return 0;
}