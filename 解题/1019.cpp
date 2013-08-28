
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	unsigned long int n;
	unsigned long int *test;
	cin>> n;
	
	test = new unsigned long int[n];
	unsigned long int sum = 0;

	unsigned long int j;
	if(test == NULL)
	{
		exit(1);
	}

	for(unsigned long int i = 0; i < n; i++)
	{
		cin>>test[i];
	}

	for(i = 0; i < n; i++)
	{
		j = 1;
		sum = 0;
		while(true)
		{
			if(sum + j >= test[i])
			{
				cout<<test[i] - sum<<endl;
				break;
			}
			sum = sum + j;
			j++;
		}
	}

	delete []test;
	test = NULL;
	return 0;
}