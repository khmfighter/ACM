
#include<cstdio>

int main()
{
	int n;
	int m;
	int count;
	float sum;
	float *score;
	float average;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		score = new float[m];
		sum = 0;
		count = 0;
		for(int j = 0; j < m; j++)
		{
			scanf("%f", &score[j]);
			sum = sum + score[j];
		}
		average = sum/m;
		for(j = 0; j < m; j++)
		{
			if(score[j] > average)
				count++;
		}
		printf("%.3f%%\n", (float)count/m*100);
	}
	return 0;
}