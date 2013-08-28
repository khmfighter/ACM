#include<iostream>
#define EQUAL 0
#define KILL 1
#define KILLED 2
using namespace std;

typedef int REL;

struct TreeNode
{
	REL relation;
	int fatherID;
};

struct RelRoot
{
	REL relation;
	int ID;
	int distance;
};

REL setREL(REL rel1, REL rel2)
{
	REL rel;
	if(rel1 ==EQUAL && rel2 == EQUAL)
		rel = EQUAL;
	else if(rel1 == EQUAL && rel2 == KILL)
		rel = KILL;
	else if(rel1 == EQUAL && rel2 == KILLED)
		rel = KILLED;
	else if(rel1 == KILL && rel2 == EQUAL)
		rel = KILL;
	else if(rel1 == KILL && rel2 == KILL)
		rel = KILLED;
	else if(rel1 == KILL && rel2 == KILLED)
		rel = EQUAL;
	else if(rel1 == KILLED && rel2 == EQUAL)
		rel = KILLED;
	else if(rel1 == KILLED && rel2 == KILL)
		rel = EQUAL;
	else if(rel1 == KILLED && rel2 == KILLED)
		rel = KILL;

	return rel;
}

RelRoot getREL(const TreeNode &t, const TreeNode* animal)
{
	int father;//¸¸Ç×
	RelRoot R;
	int distance = 0;
	REL rel;//¹ØÏµ
	REL uprel;
	father = t.fatherID;
	rel = t.relation;
	distance++;
	while(animal[father].fatherID != father)
	{
		uprel = animal[father].relation;
		rel = setREL(rel, uprel);
		father = animal[father].fatherID;
		distance++;
	}

	R.ID = father;
	R.relation = rel;
	R.distance = distance;

	return R;
}

bool isLie(int tree1, int tree2, REL rel, TreeNode* animal)
{
	RelRoot r1 = getREL(animal[tree1], animal);
	RelRoot r2 = getREL(animal[tree2], animal);
	REL rel1 = r1.relation;
	REL rel2 = r2.relation;

	if(r1.ID != r2.ID)
	{
		if(r1.distance > r2.distance)
		{
			animal[r2.ID].fatherID = r1.ID;
			REL temp = setREL(rel, rel2);
			if(temp == KILL)
				temp = KILLED;
			else if(temp == KILLED)
				temp = KILL;
			animal[r2.ID].relation = setREL(temp, rel1);
		}
		else
		{
			animal[r1.ID].fatherID = r2.ID;
			REL temp = setREL(rel, rel2);
			if(rel1 == KILL)
				rel1 = KILLED;
			else if(rel1 == KILLED)
				rel1 = KILL;
			animal[r1.ID].relation = setREL(rel1, temp);
		}
		return false;
	}
	else
	{
		if(rel2 == KILLED)
			rel2 = KILL;
		else if(rel2 == KILL)
			rel2 = KILLED;
		if(rel != setREL(rel1, rel2))
			return true;
		else
			return false;
	}
}

int main()
{
	int m, n;
	int rel;
	int x, y;
	int count = 0;
	cin>>m;
	cin>>n;
	TreeNode* animal = new TreeNode[m+1];

	for(int i = 0; i < m+1; i++)
	{
		animal[i].fatherID = i;
		animal[i].relation = EQUAL;
	}

	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d", &rel, &x, &y);
		if(x > m || y > m)
		{
			count++;
			continue;
		}
		if(rel == 2 && x == y)
		{
			count++;
			continue;
		}
		if(rel == 1)
		{
			if( isLie(x, y, EQUAL, animal) )
			{
				count++;
			}
		}
		else
			if( isLie(x, y, KILLED, animal) )
			{
				count++;
			}
	}
	cout<<count;
	return 0;
}









