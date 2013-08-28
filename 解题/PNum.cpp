
//注意字符串的处理
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int filter(string &s)
{
	int i = 0, j = 0;
	for(i = 0; i < s.length(); i++)
	{
		if( isdigit(s[i]) )
		{
			continue;
		}
		switch( s[i] )
		{
			case 'A' : case 'B' : case 'C' :
				s[i] = '2';
				break;
			case 'D' : case 'E' : case 'F' :
				s[i] = '3';
				break;
			case 'G' : case 'H' : case 'I' :
				s[i] = '4';
				break;
			case 'J' : case 'K' : case 'L' :
				s[i] = '5';
				break;
			case 'M' : case 'N' : case 'O' :
				s[i] = '6';
				break;
			case 'P' : case 'R' : case 'S' :
				s[i] = '7';
				break;
			case 'T' : case 'U' : case 'V' :
				s[i] = '8';
				break;
			case 'W' : case 'X' : case 'Y' :
				s[i] = '9';
				break;
			default :
				s.replace(i, 1, "");
				i--;
				break;
		}
	}
	
	return atoi(s.c_str());
}

int sort_function(const void *a, const void *b ) 
{ 
   return *(int*)a - *(int*)b;
} 

/*int main(void)
{
	int n, i = 0;
	int count = 1;
	int len;
	char cstr[10];
	string str;
	int pre;
	bool flag = false;
	int num[100000];
	cin>>n;
	while(i < n)
	{
		cin>>str;
		num[i] = filter(str);
		i++;
	}

	qsort((void *)num, n, sizeof(int), sort_function);

	for(i = 1; i < n; i++)
	{
		pre = num[i - 1];
		if(num[i] == pre)
		{
			count++;
		}
		else
		{
			if(count > 1)
			{
				sprintf(cstr, "%d", pre);
				len = strlen(cstr);
				if(len < 7)
				{
					cstr[7] = '\0';
					for(int k = 6; k > -1; k--)
					{
						if(len > 0)
							cstr[k] = cstr[--len];
						else
							cstr[k] = '0';
					}
				}
				for(int j = 0; j < 8; j++)
				{
					if(j < 3)
					{
						printf("%c", cstr[j]);
					}
					else if(j == 3)printf("%c", '-');
					else
						printf("%c", cstr[j-1]);
				}
				printf(" %d", count);
				printf("\n");
				flag = true;
			}
			count = 1;
		}
	}
	if(count > 1)
	{
		sprintf(cstr, "%d", pre);
		len = strlen(cstr);
		if(len < 7)
		{
			cstr[7] = '\0';
			for(int k = 6; k > -1; k--)
			{
				if(len > 0)
					cstr[k] = cstr[--len];
				else
					cstr[k] = '0';
			}
		}
		for(int j = 0; j < 8; j++)
		{
			if(j < 3)
			{
				printf("%c", cstr[j]);
			}
			else if(j == 3)printf("%c", '-');
			else
				printf("%c", cstr[j-1]);
		}
		printf(" %d", count);
		printf("\n");
		flag = true;
	}
	if( !flag ) cout<<"No duplicates."<<endl;
}*/