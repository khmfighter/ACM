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
	int **maxLen;
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

void reverse(char *s)
{
	char temp[101];
	int end = strlen(s) - 1;
	for(int i = 0; i <= strlen(s)-1; i++)
	{
		temp[i] = s[end--];
	}
	temp[i] = '\0';
	strcpy(s, temp);
}

int main()
{
	char s1[102], s2[102];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s %s", s1+1, s2+1);
		int len1 = strlen(s1 + 1);
		int len2 = strlen(s2 + 1);
		if(len2 == getMaxLength(s1, s2, len1, len2))
		{
			printf("YES\n");
			continue;
		}
		reverse(s2 + 1);
		if(len2 == getMaxLength(s1, s2, len1, len2))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}*/