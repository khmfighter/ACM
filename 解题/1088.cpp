#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int outDegree;
	int inDegree;
};

int main(int agrv, char argc[])
{
	int m, n;
	int **graph;
	int **gmatrix;
	TreeNode *tree;
	int maxPathLength = 0;
	vector<int> v;
	cin>>m;
	cin>>n;
///////////////////
	graph = new int*[m];
	if(graph == NULL)
	{
		exit(1);
	}

	for(int i = 0; i < m; i++)
	{
		graph[i] = new int[n];
		if(graph[i] == NULL)
		{
			exit(1);
		}
	}
/////////////////////
	gmatrix = new int*[m*n];
	tree = new TreeNode[m*n];
	if(gmatrix == NULL || tree == NULL)
	{
		exit(1);
	}

	for(i = 0; i < m*n; i++)
	{
		gmatrix[i] = new int[m*n];
		if(gmatrix[i] == NULL)
		{
			exit(1);
		}
	}
/////////////////////////////
	freopen("test.txt", "r", stdin);
	for(i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin>>graph[i][j];

	for(i = 0; i < m*n; i++)
	{
		for(int j = 0; j < m*n; j++)
		{
			gmatrix[i][j] = 0;
		}
	}

	for(i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
		{
			if(i - 1 >= 0)
			{
				if(graph[i-1][j] < graph[i][j])
				{
					gmatrix[i*n + j][(i-1)*n + j] = 1;
				}
				else
					gmatrix[i*n + j][(i-1)*n + j] = 0;
			}

			if(i + 1 < m)
			{
				if(graph[i+1][j] < graph[i][j])
				{
					gmatrix[i*n + j][(i+1)*n + j] = 1;
				}
				else
					gmatrix[i*n + j][(i+1)*n + j] = 0;
			}

			if(j + 1 < n)
			{
				if(graph[i][j+1] < graph[i][j])
				{
					gmatrix[i*n + j][i*n+j+1] = 1;
				}
				else
					gmatrix[i*n + j][i*n+j+1] = 0;
			}

			if(j - 1 >= 0)
			{
				if(graph[i][j-1] < graph[i][j])
				{
					gmatrix[i*n + j][i*n + j - 1] = 1;
				}
				else
					gmatrix[i*n + j][i*n + j - 1] = 0;
			}
		}
	fclose(stdin);
////////////////////////////////////
	for(i = 0; i< m*n; i++)
	{
		tree[i].inDegree = 0;
		tree[i].outDegree = 0;
	}

	for(i = 0; i < m*n; i++)
		for(int j = 0; j < m*n; j++)
		{
			if(gmatrix[i][j] == 1)
			{
				tree[i].outDegree++;
				tree[j].inDegree++;
			}
		}
////////////////////////////////////////
	for(i = 0; i < m*n; i++)
		if(tree[i].inDegree == 0)
		{
			v.push_back(i);
		}

	while(v.size() != 0)
	{
		maxPathLength++;
		for(i = 0; i < v.size(); i++)
		{
			int k = v[i];
			for(int j = 0; j < m*n; j++)
			{
				if(gmatrix[k][j] == 1)
				{
					tree[j].inDegree--;
					if(tree[j].inDegree == 0)
						v.push_back(j);
				}
			}
			v.erase(&v[i]);
		}
	}
////////////////////////////////////
	for(i = 0; i < m; i++)
	{
		delete []graph[i];
		graph[i] = NULL;
	}
	delete []graph;
	graph = NULL;

	for(i = 0; i < m*n; i++)
	{
		delete []gmatrix[i];
		gmatrix[i] = NULL;
	}
	delete []gmatrix;
	gmatrix = NULL;

	delete []tree;
	tree = NULL;

	cout<<maxPathLength;
	return 0;
}