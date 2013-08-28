#include<iostream>
using namespace std;

//用于存储点的位置
struct pos
{
	int x;
	int y;
};

//核心处理算法
//angle：存储数字三角
//min：存储最小路径值
//pre: 存储取得最小路径的轨迹
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

//设从顶到底部的最短路径为angle[1][1]到angle[i][j]之间的一条论经，打印该路径的轨迹
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