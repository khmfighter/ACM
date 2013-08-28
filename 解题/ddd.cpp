#include<iostream>
using namespace std;

int max(int a, int b)
{
	return b;
}

int min(int a, int b)
{
	return a;
}

int main()
{
	 int (*p[2])(int a, int b);
	 p[0] = min;
	 p[1] = max;

	 for(int i = 0; i < 2; i++)
	 {
		 cout<<p[0](1,2)<<"min";
		 cout<<p[1](1,2)<<"max";
	 }
	 system("pause");
}