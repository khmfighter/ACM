
//中国剩余定理的应用
#include<iostream>
using namespace std;

struct NODE
{
	int p;
	int e;
	int i;
	int d;
	int days;
};

int getDays(int p, int e, int i, int d)
{
	int m, days;
	m = 0;
	while(m < 28*23+1)
	{
		days = m*33 + i - d;
		if((days + d - e)%28 == 0 && (days + d - p)%23==0 && days > d)
		{
			if(days - 21252 > d)
			{
				days = days - 21252;
			}
			return days;
		}
		m++;
	}
	return -1;
}

/*int main(void)
{
	int i, n = 0;
	NODE node;
	while(true)
	{
		cin>>node.p;
		cin>>node.e;
		cin>>node.i;
		cin>>node.d;	
		if(node.p == -1)
		{
			break;
		}
		node.days = getDays(node.p, node.e, node.i, node.d);
		printf("Case %d: the next triple peak occurs in %d days.\n",++n, node.days);
	}
}*/