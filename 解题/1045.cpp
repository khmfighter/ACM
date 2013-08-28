
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double VS, R, C;
	int n;
	cin>>VS>>R>>C>>n;
	//freopen("test.txt", "r" , stdin);
	double *W = new double[n];
	for(int i = 0; i < n; i++)
	{
		cin>>W[i];
	}
	for(i = 0; i < n; i++)
	{
		printf("%1.3f\n", VS/sqrt(R*R + 1.0/(W[i]*W[i]*C*C))*R);
	}
	delete []W;
	W = NULL;
	//fclose(stdin);
	return 0;
}