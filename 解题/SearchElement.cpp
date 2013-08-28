#include<iostream>
using namespace std;
struct point
{
	int x;
	int y;
};

point SearchElement(int A[][5], int a, int b, int c, int d, int x)
{
	int e, f;
	point p;
	e = (a + c) / 2;
	f = (b + d) / 2;

	p.x = -1;
	p.y = -1;

	if(A[e][f] == x)
	{
		p.x = e;
		p.y = f;
		return p;
	}
	else
	{
		if(a==c && b==d)
			return p;
		else
		{
			if(x < A[e][f])
			{
				if(p.x == -1)
					p = SearchElement(A, a, b, e, f, x);
				if(p.x == -1)
					p = SearchElement(A, e, b, c, f-1, x);
				if(p.x == -1)
					p = SearchElement(A, a, f, e-1, d, x);

			}
			else
			{
				if(p.x == -1)
					p = SearchElement(A, e, f, c, d, x);
				if(p.x == -1)
					p = SearchElement(A, e+1, b, c, f, x);
				if(p.x == -1)
					p = SearchElement(A, a, f+1, e, d, x);
			}
			return p;
		}
	}
}

int main()
{
	int A[][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	point p = SearchElement(A, 0, 0, 4, 4, 6);

	cout<<p.x<<p.y;
}





