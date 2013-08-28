
#include <stdio.h>
#include <iostream>
using namespace std;


//*stone n堆石子数量的数组
//n 代表石子的堆数
int getMaxScore(int *stone, int n)
{
	int **sumij;
	int i, j, t;
	int maxScore = 0;
	sumij = new int*[n];

	if(n = 1)
		return 0;

	for(i = 0; i < n; i++)
	{
		sumij[i] = new int[n];
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			sumij[i][j] = 0;
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<sumij[i][j];
		}
		cout<<endl;
	}


	for(i = 0; i <n; i++)
	{
		sumij[i][i] = stone[i];
	}

	for(i = 1; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(int k = j+1; k <= j+i; k++)
			{
				t = sumij[j][(k-1)%n] + sumij[k%n][(j+i)%n];
				if(sumij[j][(j+i)%n] < t)
				{
					sumij[j][(j+i)%n] = t;
				}
			}
		}
	}	

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<sumij[i][j];
		}
		cout<<endl;
	}
	return 100;
}

int main()
{
	int stone[] = {1, 4, 6, 8, 10, 15, 21};
	cout<<getMaxScore(stone, 7);
	return 0;
}