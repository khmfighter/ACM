
/*#include<cstdio>
#include<cstring>

int max(int num1, int num2)
{
	int result;
	(num1 > num2)?result = num1:result = num2;
	return result;
}

int getMaxLength(char *s1, char *s2, int len1, int len2)
{
	/*if(end1 == -1 || end2 == -1)
		return 0;
	if(s1[end1] == s2[end2])
		return 1 + getMaxLength(s1, s2, end1 - 1, end2 - 1);
	return max(getMaxLength(s1, s2, end1-1, end2), getMaxLength(s1, s2, end1, end2-1));*/
/*	int **maxLen;
	maxLen = new int* [len1 + 1];
	for(int i = 0; i <= len1 ; i++)
	{
		maxLen[i] = new int[len2 + 1];
	}
	for(i = 0; i <= len1; i++)
		maxLen[i][0] = 0;
	for(i = 0; i <= len2; i++)
		maxLen[0][i] = 0;
	for(i = 1; i <= len1; i++)
		for(int j = 1; j <= len2; j++)
		{
			if(s1[i] == s2[j])
				maxLen[i][j] = 1 + maxLen[i-1][j-1];
			else
				maxLen[i][j] = max(maxLen[i][j-1], maxLen[i-1][j]);
		}
	return maxLen[len1][len2];
}

int main()
{
	char *s1, *s2;
	s1 = new char[100000 + 2];
	s2 = new char[100000 + 2];
	while(scanf("%s %s", s1+1, s2+1) == 2)
	{
		int len1 = strlen(s1+1);
		int len2 = strlen(s2+1);
		if(len1 == getMaxLength(s1, s2, len1, len2))
			printf("Yes\n");
		else
			printf("No\n");
		delete[]s1;
		delete[]s2;
		s1 = NULL;
		s2 = NULL;

		s1 = new char[100000 + 2];
		s2 = new char[100000 + 2];
	}

	return 0;
}*/