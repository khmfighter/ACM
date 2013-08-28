
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode
{
	int son[4];
	int sonNum;
	int indegree;
};

int main()
{
	int m, n;
	int **graph;
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
	tree = new TreeNode[m*n];
	if(tree == NULL)
	{
		exit(1);
	}
/////////////////////////////
//	freopen("test.txt", "r", stdin);
	for(i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin>>graph[i][j];

	for(i = 0; i < m*n; i++)
	{
		tree[i].indegree = 0;
	}

	for(i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int k = 0;
			if(j + 1 < n)
			{
				if(graph[i][j+1] < graph[i][j])
				{
					tree[i*n + j].son[k] = i*n+j+1;
					tree[i*n+j+1].indegree++;
					k++;
				}	
			}
			if(i - 1 >= 0)
			{
				if(graph[i-1][j] < graph[i][j])
				{
					tree[i*n + j].son[k] = (i-1)*n + j;
					tree[(i-1)*n + j].indegree++;
					k++;
				}
			}

			if(j - 1 >= 0)
			{
				if(graph[i][j-1] < graph[i][j])
				{
					tree[i*n + j].son[k] = i*n+j-1;
					tree[i*n+j-1].indegree++;
					k++;
				}
			}

			if(i + 1 < m)
			{
				if(graph[i+1][j] < graph[i][j])
				{
					tree[i*n + j].son[k] = (i+1)*n+j;
					tree[(i+1)*n + j].indegree++;
					k++;
				}
			}
			tree[i*n + j].sonNum = k;
		}
	} 

	for(i = 0; i < m*n; i++)
	{
		if(tree[i].indegree == 0)
		{
			v.push_back(i);
		}
	}

	while(v.size() != 0)
	{
		maxPathLength++;
		int vLen = v.size();
		for(i = 0; i < vLen; i++)
		{
			int k = v[0];
			for(int j = 0; j < tree[k].sonNum; j++)
			{
				int degree = --tree[tree[k].son[j]].indegree;
				if(degree == 0)
					v.push_back(tree[k].son[j]);
			}
			v.erase(&v[0]);
		}
	}
//	fclose(stdin);
	cout<<maxPathLength;
	for(i = 0; i < m; i++)
	{
		delete []graph[i];
		graph[i] = NULL;
	}
	delete []graph;
	graph = NULL;

	delete []tree;
	tree = NULL;

	return 0;
}