
#include<iostream>
#include<cstdlib>
using namespace std;

int compare(const void* a, const void *b)
{
	int item1 = *(int*)a;
	int item2 = *(int*)b;

	return item1 - item2;
}

/*
//version 1.0
//error
//

bool search(const int* sticks, int n, int length)
{
	int* flag = new int[n];
	int leftLen;
	for(int i = 0; i < n; i++)
	{
		flag[i] = 0;
	}

	for(i = n-1; i > -1; i--)
	{
		if(flag[i] == 1)
			continue;
		leftLen = length;
		for(int j = i; j > -1; j--)
		{
			if(flag[j] == 1)continue;
			if(leftLen - sticks[j] >= 0)
			{
				leftLen = leftLen - sticks[j];
				flag[j] = 1;
			}
			if(leftLen == 0)break;
		}
		if(leftLen != 0)
			return false;
	}

	delete []flag;
	flag = NULL;
	return true;
}*/


int main()
{
	int *sticks;
	int numOfSticks;
	int sum = 0;
	int maxLenSticks;
	while(true)
	{
		cin>>numOfSticks;
		sum = 0;
		if(numOfSticks == 0)
			break;
		sticks = new int[numOfSticks];
		if(freopen("test.txt", "r", stdin) == NULL)
		{
			cout<<"wrong!"<<endl;
			exit(1);
		}
		for(int i = 0; i < numOfSticks; i++)
		{
			cin>>sticks[i];
			sum = sum + sticks[i];
		}
		qsort((void*)sticks, numOfSticks, sizeof(int), compare);
		maxLenSticks = sticks[numOfSticks - 1];
		for(i = maxLenSticks; i <= sum; i++)
		{
			if(sum % i == 0)
			{
				if(search(sticks, numOfSticks, i))
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		delete []sticks;
		sticks = NULL;
		fclose(stdin);
	}
	return 0;
}