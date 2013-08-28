#include<iostream>
using namespace std;

//���ڴ洢���λ��
struct pos
{
	int x;
	int y;
};

//���Ĵ����㷨
//angle���洢��������
//min���洢��С·��ֵ
//pre: �洢ȡ����С·���Ĺ켣
void digitTriangle(int **angle, int **min, pos **pre, int n)
{
	int i, j, k;
	int temp;
	int less;

	if(n == 1)
	{
		return angle[1][1];
	}

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			if(min[i-1][j] < min[i-1][j-1])
			{
				less = min[i-1][j] < min[i-1][j-1];
				pre[i][j].x = i-1;
				pre[i][j].y = j;
			}
			else
			{
				less = min[i-1][j-1];
				pre[i][j].x = i-1;
				pre[i][j].y = j-1;
			}
			temp = angle[i][j] + less;
			if(temp < min[i][j])
			{
				min[i][j] = temp;
			}
		}
	}
}

//��Ӷ����ײ������·��Ϊangle[1][1]��angle[i][j]֮���һ���۾�����ӡ��·���Ĺ켣
void printPath(pos **pre, int i, int j)
{
	int k;
	int x = i;
	int y = j;
	for(k = 1; k < n; k++)
	{
		cout<< x <<","<< y <<endl;
		x = pre[x][y].x;
		y = pre[x][y].y;
	}
}