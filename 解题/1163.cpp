002D:1207.cpp:0211:1:14=48041e4b:16=47d21313:
/*#include<cstdio>

int getLength(int n)
{
	int count = 1;
	while( n != 1)
	{
		if(n % 2 != 0)
			n = 3*n + 1;
		else
			n = n/2;
		count++;
	}
	return count;
}

int main()
{
	long int max; 
	int begin, end;
	int m, n;
	while(scanf("%d%d", &begin, &end) == 2)
	{
		max = 0;
		(begin > end)?m = end: m = begin;
		(begin > end)?n = begin : n = end;
		for(int i = m; i <= n; i++)
		{
			if(getLength(i) > max)
				max = getLength(i);
		}
		printf("%d %d %d\n", begin, end, max);
	}
	return 0;
}*/002D:1218.cpp:02EC:1:14=48041e4b:16=47d21313:
#include<stdio.h>

bool reverse(bool a)
{
	if(a)
		return false;
	else
		return true;
}

int getNum(int n, bool *a)
{
	int count = 0;
	for(int i = 1; i < n+1; i++)
	{
		int j = 1;
		int k = j*i;
		while(k < n+1)
		{
			a[k] = reverse(a[k]);
			j++;
			k = j*i;
		}
	}

	for(i = 1; i < n+1; i++)
	{
		if(a[i])
			count++;
	}
	return count;
}

int main()
{
	int n;
	int *testCase;
	bool *init;
	scanf("%d", &n);
	testCase = new int[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &testCase[i]);
		init = new bool[testCase[i] + 1];
		for(int j = 1; j < testCase[i] + 1; j++)
		{
			init[j] = false;
		}
		printf("%d\n", getNum(testCase[i], init));
		delete []init;
		init = NULL;
	}
	return 0;
}002D:1316.cpp:01D7:1:14=48041e4b:16=47d21313:
#include<cstdio>

int main()
{
	int a[10000];
	for(int i = 0; i < 10000; i++)
	{
		a[i] = 0;
	}
	int digit;
	int left;
	int sum = 0;
	for(i = 1; i < 10000; i++)
	{
		digit = i % 10;
		left = i;
		sum = i;
		while(digit >= 0)
		{
			sum += digit;
			left = left/10;
			if(left == 0)break;
			digit = left % 10;
		}
		if(sum < 10000)
			a[sum] = 1;
	}

	for(i = 1; i < 10000; i++)
	{
		if(a[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}002D:1519.cpp:01A7:1:14=48041e4b:16=47d21313:
/*#include<cstdio>

long int getDigitRoot(long int integer)
{
	long int sum = 0;
	long int end;
	end = integer;
	while(end != 0)
	{
		sum += end % 10;
		end = end / 10;
	}
	if(sum < 10)
		return sum;
	else
		return getDigitRoot(sum);
}

int main()
{
	long int input;
	scanf("%ld", &input);
	while(input != 0)
	{
		printf("%ld\n", getDigitRoot(input));
		scanf("%ld", &input);
	}
	return 0;
}*/002D:1552.cpp:0388:1:14=48041e4b:16=47d21313:
/*#include<cstdio>
#include<cstdlib>

int compare(const void *a, const void *b)
{
	int one = *(int *)a;
	int two = *(int *)b;
	return one - two;
}

bool bSearch(int t, int *a, int n)
{
	int left = 0;
	int right = n - 1;
	int middle = 0;
	while(left <= right)
	{
		middle = (left + right)/2;
		if(t < a[middle])
			right = middle - 1;
		else if(t > a[middle])
			left = middle + 1;
		else return true;
	}
	return false;
}

int getPair(int *a, int n)
{
	int count = 0;
	qsort(a, n, sizeof(int), compare);
	for(int i = 0; a[i] <= a[n-1]/2; i++)
	{
		if(bSearch(2*a[i], a, n))
			count++;
	}
	return count;
}

int main()
{
	int a[15];
	int n = 0;
	int input;
	scanf("%d", &input);
	while(input != -1)
	{
		if(input != 0)
		{
			a[n++] = input;
		}
		else
		{
			printf("%d\n", getPair(a, n));
			n = 0;
		}
		scanf("%d", &input);
	}
	return 0;
}*/002D:1607.cpp:016B:1:14=48041e4b:16=47d21313:
#include<iostream>
using namespace std;


/*int main()
{
	int input;
	double sum = 0.0;
	int i;
	//freopen("test.txt","r",stdin);
	cout<<"Cards  Overhang"<<endl;
	while(cin>>input)
	{
		sum = 0.0;
		for(i = 1; i <= input; i++)
		{
			sum = 1.0/(2.0*i) + sum;
		}
		printf("%5d     %1.3f\n", input, sum);
	}
//	fclose(stdin);
	return 0;
}*/002D:1657.cpp:06D6:1:14=48041e4b:16=47d21313:
/*#include<cstdio>
#include<cctype>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

int king(int begin_i, int begin_j, int end_i, int end_j)
{
	if(abs(begin_i - end_i) > abs(begin_j - end_j))
	{
		return abs(begin_i - end_i);
	}
	else
		return abs(begin_j - end_j);
}

int queen(int begin_i, int begin_j, int end_i, int end_j)
{
	if(begin_i == end_i && begin_j == end_j)
		return 0;
	if(begin_i == end_i || begin_j == end_j || abs(begin_i - end_i) == abs(begin_j - end_j))
		return 1;
	else
		return 2;
}

int bus(int begin_i, int begin_j, int end_i, int end_j)
{
	if(begin_i == end_i && begin_j == end_j)
		return 0;
	if(begin_i == end_i || begin_j == end_j)
		return 1;
	else 
		return 2;
}

int elephant(int begin_i, int begin_j, int end_i, int end_j)
{
	if(begin_i == end_i && begin_j == end_j)
		return 0;
	if(abs(begin_i - end_i) == abs(begin_j - end_j))
		return 1;
	if((begin_i + begin_j)%2 != (end_i + end_j)%2)
		return -1;
	return 2;
}

int main()
{
	int n;
	string begin, end, pos;
	int pos_i[4];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		cin>>begin>>end;
		pos = begin + end;
		int j = 0;
		while(j < 4)
		{
			if(isalpha(pos[j]))
				pos_i[j] = pos[j] - 'a';
			else
				pos_i[j] = pos[j] - '0';
			j++;
		}
		int rking = king(pos_i[0], pos_i[1], pos_i[2], pos_i[3]);
		int rqueen = queen(pos_i[0], pos_i[1], pos_i[2], pos_i[3]);
		int rbus = bus(pos_i[0], pos_i[1], pos_i[2], pos_i[3]);
		int relephant = elephant(pos_i[0], pos_i[1], pos_i[2], pos_i[3]);
		if(relephant == -1)
		{
			printf("%d %d %d Inf\n", rking, rqueen, rbus);
		}
		else
			printf("%d %d %d %d\n", rking, rqueen, rbus, relephant);
	}
	return 0;
}*/002D:1658.cpp:0189:1:14=48041e4b:16=47d21313:
/*#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int sum;
	int a, b, c, d, e;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		sum = a + b + c + d;
		if(sum == (a + d)*2)
		{
			e = d + d - c;
			printf("%d %d %d %d %d\n", a, b, c, d, e);
		}
		else
		{
			e = d*d/c;
			printf("%d %d %d %d %d\n", a, b, c, d, e);
		}
	}
	return 0;
}*/002C:1664.cpp:04C:1:14=48041e4b:16=47d21313:
#include<iostream>
using namespace std;

int main()
{

	return 0;
}002D:1936.cpp:052F:1:14=48041e4b:16=47d21313:
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
}*/002D:2017.cpp:017C:1:14=48041e4b:16=47d21313:
#include<cstdio>

int main()
{
	int miles = 0;
	int prehour = 0;
	int speed, hour;
	int n;
	scanf("%d", &n);
	while(n != -1)
	{
		prehour = 0;
		miles = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &speed, &hour);
			miles = miles + speed * (hour - prehour);
			prehour = hour;
		}
		printf("%d miles\n", miles);
		scanf("%d", &n);
	}
	return 0;
}0038:2027 No Brainer.cpp:0111:1:14=48041e4b:16=47d21313:
#include<stdio.h>

int main()
{
	int numOfSets;
	int eat, alive;
	scanf("%d", &numOfSets);
	for(int i = 0; i < numOfSets; i++)
	{
		scanf("%d%d", &eat, &alive);
		if(eat >= alive)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
	return 0;
}002D:2027.cpp:0113:1:14=48041e4b:16=47d21313:/*#include<stdio.h>

int main()
{
	int numOfSets;
	int eat, alive;
	scanf("%d", &numOfSets);
	for(int i = 0; i < numOfSets; i++)
	{
		scanf("%d%d", &eat, &alive);
		if(eat >= alive)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
	return 0;
}*/002D:2350.cpp:01E8:1:14=48041e4b:16=47d21313:
#include<cstdio>

int main()
{
	int n;
	int m;
	int count;
	float sum;
	float *score;
	float average;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		score = new float[m];
		sum = 0;
		count = 0;
		for(int j = 0; j < m; j++)
		{
			scanf("%f", &score[j]);
			sum = sum + score[j];
		}
		average = sum/m;
		for(j = 0; j < m; j++)
		{
			if(score[j] > average)
				count++;
		}
		printf("%.3f%%\n", (float)count/m*100);
	}
	return 0;
}002D:2363.cpp:0362:1:14=48041e4b:16=47d21313:
#include<iostream>
#include<cmath>
using namespace std;

int getMinPaper(int iNum)
{
	int k;
	int iMinResult = 4*iNum + 2;
	int factor1, factor2;
	int temp = 0;
	int sum = 0;

	for(k = 1; k<=sqrt(iNum); k++)
	{
		if(iNum % k == 0)
		{
			temp = iNum/k;
			for(int i = 1; i <= sqrt(temp); i++)
			{
				if(temp % i == 0)
				{
					factor1 = i;
					factor2 = temp/i;
					sum = 2*(factor1*factor2 + factor1*k + factor2*k);
					if(sum < iMinResult)
					{
						iMinResult = sum;
					}
				}
			}
		}
	}
	return iMinResult;
}

/*int main()
{
	int n;	
	cin>>n;
	int *blocks=new int[n];
	//freopen("test.txt", "r" , stdin);
	for(int i = 0; i < n; i++)
	{
		cin>>blocks[i];
	}
	for(i = 0; i < n; i++)
	{
		cout<<getMinPaper(blocks[i])<<endl;
	}

	//fclose(stdin);
	delete []blocks;
	blocks = NULL;
	return 0;
}*/002D:2388.cpp:02DE:1:14=48041e4b:16=47d21313:
/*#include<cstdio>

int getMid(int *a, int begin, int end, int n)
{
	int pivot = (begin + end)/2;
	int temp = a[pivot];
	int i = begin;
	int j = end;
	a[pivot] = a[end];
	
	while(i != j)
	{
		while(a[i] < temp && i < j)
			i++;
		if(i < j)
		{
			a[j] = a[i];
			j--;
		}
		while(a[j] > temp && i < j)
			j--;
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}
	}
	a[i] = temp;
	if(i < n/2)
	{
		return getMid(a, i+1, end, n);
	}
	else if(i > n/2)
	{
		return getMid(a, begin, i-1, n);
	}
	else
		return a[i];
}

int main()
{
	int n;
	int *a;
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d\n", getMid(a, 0, n-1, n));
	return 0;
}*/