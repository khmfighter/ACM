
/*#include<cstdio>
#include<cctype>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

int king(int begin_i, int begin_j, int end_i, int end_j)
{
	if(abs(begin_i - end_i) > abs(begin_j - end_j))
	{
		return abs(begin_i - end_i);
	}
	else
		return abs(begin_j - end_j);
}

int queen(int begin_i, int begin_j, int end_i, int end_j)
{
	if(begin_i == end_i && begin_j == end_j)
		return 0;
	if(begin_i == end_i || begin_j == end_j || abs(begin_i - end_i) == abs(begin_j - end_j))
		return 1;
	else
		return 2;
}

int bus(int begin_i, int begin_j, int end_i, int end_j)
{
	if(begin_i == end_i && begin_j == end_j)
		return 0;
	if(begin_i == end_i || begin_j == end_j)
		return 1;
	else 
		return 2;
}

int elephant(int begin_i, int begin_j, int end_i, int end_j)
{
	if(begin_i == end_i && begin_j == end_j)
		return 0;
	if(abs(begin_i - end_i) == abs(begin_j - end_j))
		return 1;
	if((begin_i + begin_j)%2 != (end_i + end_j)%2)
		return -1;
	return 2;
}

int main()
{
	int n;
	string begin, end, pos;
	int pos_i[4];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		cin>>begin>>end;
		pos = begin + end;
		int j = 0;
		while(j < 4)
		{
			if(isalpha(pos[j]))
				pos_i[j] = pos[j] - 'a';
			else
				pos_i[j] = pos[j] - '0';
			j++;
		}
		int rking = king(pos_i[0], pos_i[1], pos_i[2], pos_i[3]);
		int rqueen = queen(pos_i[0], pos_i[1], pos_i[2], pos_i[3]);
		int rbus = bus(pos_i[0], pos_i[1], pos_i[2], pos_i[3]);
		int relephant = elephant(pos_i[0], pos_i[1], pos_i[2], pos_i[3]);
		if(relephant == -1)
		{
			printf("%d %d %d Inf\n", rking, rqueen, rbus);
		}
		else
			printf("%d %d %d %d\n", rking, rqueen, rbus, relephant);
	}
	return 0;
}*/