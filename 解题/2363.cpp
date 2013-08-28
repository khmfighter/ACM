
#include<iostream>
#include<cmath>
using namespace std;

int getMinPaper(int iNum)
{
	int k;
	int iMinResult = 4*iNum + 2;
	int factor1, factor2;
	int temp = 0;
	int sum = 0;

	for(k = 1; k<=sqrt(iNum); k++)
	{
		if(iNum % k == 0)
		{
			temp = iNum/k;
			for(int i = 1; i <= sqrt(temp); i++)
			{
				if(temp % i == 0)
				{
					factor1 = i;
					factor2 = temp/i;
					sum = 2*(factor1*factor2 + factor1*k + factor2*k);
					if(sum < iMinResult)
					{
						iMinResult = sum;
					}
				}
			}
		}
	}
	return iMinResult;
}

/*int main()
{
	int n;	
	cin>>n;
	int *blocks=new int[n];
	//freopen("test.txt", "r" , stdin);
	for(int i = 0; i < n; i++)
	{
		cin>>blocks[i];
	}
	for(i = 0; i < n; i++)
	{
		cout<<getMinPaper(blocks[i])<<endl;
	}

	//fclose(stdin);
	delete []blocks;
	blocks = NULL;
	return 0;
}*/