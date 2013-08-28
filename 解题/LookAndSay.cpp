002D:Maya.cpp:0912:1:14=48041e4b:16=47d21313:#include<string>
#include<iostream>
using namespace std;


//慎重考虑边界问题

struct TZO
{
	int day;
	int month;
	int year;
};

int map_Haab(string s)
{
	
		if (!s.compare("pop")) return 0; 
		if (!s.compare("no")) return 1;
		if (!s.compare("zip")) return 2;
		if (!s.compare("zotz")) return 3;
		if (!s.compare("tzec")) return 4;
		if (!s.compare("xul")) return 5;
		if (!s.compare("yoxkin")) return 6;
		if (!s.compare("mol")) return 7;
		if (!s.compare("chen")) return 8;
		if (!s.compare("yax")) return 9;
		if (!s.compare("zac")) return	10;
		if (!s.compare("ceh")) return 11;
		if (!s.compare("mac")) return 12;
		if (!s.compare("kankin")) return 13;
		if (!s.compare("muan")) return 14;
		if (!s.compare("pax")) return 15;
		if (!s.compare("koyab")) return 16;
		if (!s.compare("cumhu")) return 17;
		if (!s.compare("uayet")) return 18;
}

string map_Zol(int t)
{
	switch(t)
	{
		case 1: return "imix";
		case 2: return "ik";
		case 3: return "akbal";
		case 4: return "kan";
		case 5: return "chicchan";
		case 6: return "cimi";
		case 7: return "manik";
		case 8: return "lamat";
		case 9: return "muluk";
		case 10: return "ok";
		case 11: return "chuen";
		case 12: return "eb";
		case 13: return "ben";
		case 14: return "ix";
		case 15: return "mem";
		case 16: return "cib";
		case 17: return "caban";
		case 18: return "eznab";
		case 19: return "canac";
		case 20: return "ahau";
		default : return "";
	}
}

TZO convertHaabToTzolkin(int day, int month, int year)
{
	TZO t;
	int totalTays = year*365 + month*20 + (day+1);
	int tyear = totalTays / 260;
	int tdays = totalTays % 260;
	int tmonth = tdays % 13;
	int tday = tdays % 20;

	if(tmonth == 0)tmonth = 13;
	if(tday == 0)tday = 20;
	if(tdays == 0)tyear = tyear - 1;

	t.day = tday;
	t.year = tyear;
	t.month = tmonth;

	return t;
}


/*int main(void)
{
	int num;
	int i = 0;
	int day, year;
	float f;
	char str[10];
	cin>>num;

	TZO *tzo = new TZO[num];

	while(i < num)
	{
		scanf("%f%s%d", &f, str, &year);
		day = int(f);
		tzo[i] = convertHaabToTzolkin(day, map_Haab(string(str)), year);
		i++;
	}

	cout<<num<<endl;

	i = 0;
	while(i < num)
	{
		cout<< tzo[i].month<<" "<<map_Zol(tzo[i].day)<<" "<<tzo[i].year<<endl;
		i++;
	}
}*/0033:MergeStone.cpp:041E:1:14=48041e4b:16=47d21313:
#include <stdio.h>
#include <iostream>
using namespace std;


//*stone n堆石子数量的数组
//n 代表石子的堆数
int getMaxScore(int *stone, int n)
{
	int **sumij;
	int i, j, t;
	int maxScore = 0;
	sumij = new int*[n];

	if(n = 1)
		return 0;

	for(i = 0; i < n; i++)
	{
		sumij[i] = new int[n];
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			sumij[i][j] = 0;
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<sumij[i][j];
		}
		cout<<endl;
	}


	for(i = 0; i <n; i++)
	{
		sumij[i][i] = stone[i];
	}

	for(i = 1; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(int k = j+1; k <= j+i; k++)
			{
				t = sumij[j][(k-1)%n] + sumij[k%n][(j+i)%n];
				if(sumij[j][(j+i)%n] < t)
				{
					sumij[j][(j+i)%n] = t;
				}
			}
		}
	}	

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<sumij[i][j];
		}
		cout<<endl;
	}
	return 100;
}

int main()
{
	int stone[] = {1, 4, 6, 8, 10, 15, 21};
	cout<<getMaxScore(stone, 7);
	return 0;
}002F:Parcel.cpp:05EF:1:14=48041e4b:16=47d21313:
/*#include<cstdio>

int main()
{
	int one, two, three, four, five, six;
	int count, threeCount, oneCount, twoCount;
	int oneParcel, twoParcel, threeParcel;
	scanf("%d%d%d%d%d%d", &one, &two, &three, &four, &five, &six);
	while(one != 0 || two !=0 || three !=0 || four != 0 || five !=0 || six !=0)
	{
		count = 0;
		count = six + five + four;
		oneParcel = 11*five;
		twoParcel = 5*four;

		if(three % 4 != 0)
		{
			threeCount = three/4 + 1;
			threeParcel = 4 - three%4;
		}
		else 
		{
			threeCount = three/4;
			threeParcel = 0;
		}
		count = count + threeCount;
		
		if(threeParcel == 1)
		{
			twoParcel = twoParcel + 1;
			oneParcel = oneParcel + 5;
		}
		else if(threeParcel == 2)
		{
			twoParcel = twoParcel + 3;
			oneParcel = oneParcel + 6;
		}
		else if(threeParcel == 3)
		{
			twoParcel = twoParcel + 5;
			oneParcel = oneParcel + 7;
		}
		
		if(two > twoParcel)
		{
			two = two - twoParcel;
			if(two % 9 != 0)
			{
				twoCount = two/9 + 1;
				oneParcel = oneParcel + (9 - two % 9)*4;
			}
			else 
			{
				twoCount = two/9;
			}
		}
		else
		{
			oneParcel = oneParcel + 4*(twoParcel - two);
			twoCount = 0;
		}
		
		if(one > oneParcel)
		{
			one = one - oneParcel;
			if(one % 36 != 0)
				oneCount = one/36 + 1;
			else
				oneCount = one/36;
		}
		else oneCount = 0;

		count = count + oneCount + twoCount;
		printf("%d\n", count);
		scanf("%d%d%d%d%d%d", &one, &two, &three, &four, &five, &six);
	}
	return 0;
}*/0034:PhoneNumber.cpp:05FB:1:14=48041e4b:16=47d21313:
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

void filter(string &s)
{
	int i = 0, j = 0;
	int len = s.length();
	for(i = 0; i < len; i++)
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
				s.erase(i, 1);
				i--;
				break;
		}
	}
	s.insert(3, "-");
}

/*int main(void)
{
	int n, i = 0;
	int count = 1;
	bool flag = false;
	string pre;
	string str;
	vector<string> vstr;
	cin>>n;
	while(i < n)
	{
		cin>>str;
		filter(str);
		vstr.push_back(str);
		i++;
	}

	sort(vstr.begin(), vstr.end(), less<string>());

	for(i = 1; i < vstr.size(); i++)
	{
		pre = vstr[i-1];
		if(pre == vstr[i])
		{
			count++;
		}
		else
		{
			if(count > 1)
			{
				cout<<pre<<" "<<count<<endl;
				flag = true;
			}
			count = 1;
		}
	}
	if(count > 1)
	{
		cout<<pre<<" "<<count<<endl;
		flag = true;
	}
	if( !flag ) cout<<"No duplicates."<<endl;
}*/002D:PNum.cpp:09B6:1:14=48041e4b:16=47d21313:
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
}*/0036:SearchElement.cpp:0424:1:14=48041e4b:16=47d21313:#include<iostream>
using namespace std;
struct point
{
	int x;
	int y;
};

point SearchElement(int A[][5], int a, int b, int c, int d, int x)
{
	int e, f;
	point p;
	e = (a + c) / 2;
	f = (b + d) / 2;

	p.x = -1;
	p.y = -1;

	if(A[e][f] == x)
	{
		p.x = e;
		p.y = f;
		return p;
	}
	else
	{
		if(a==c && b==d)
			return p;
		else
		{
			if(x < A[e][f])
			{
				if(p.x == -1)
					p = SearchElement(A, a, b, e, f, x);
				if(p.x == -1)
					p = SearchElement(A, e, b, c, f-1, x);
				if(p.x == -1)
					p = SearchElement(A, a, f, e-1, d, x);

			}
			else
			{
				if(p.x == -1)
					p = SearchElement(A, e, f, c, d, x);
				if(p.x == -1)
					p = SearchElement(A, e+1, b, c, f, x);
				if(p.x == -1)
					p = SearchElement(A, a, f+1, e, d, x);
			}
			return p;
		}
	}
}

int main()
{
	int A[][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	point p = SearchElement(A, 0, 0, 4, 4, 6);

	cout<<p.x<<p.y;
}





002B:ss.cpp:04D1:1:14=48041e4b:16=47d21313:#include <stdio.h>
#include <string.h>
#include <iostream.h>

bool isTwo(char *);
long calc(int);
int main()
{
char num[32];
char *current;
double result[50];
int length;
int i=0;
do{
// cin>>num;
   scanf("%s",num);
   length=strlen(num);
   result[i]=0;

   if(strlen(num)==1&&num[0]=='0')
    break;
   else
   {
    if(isTwo(num))
    {
     for(current=num+length-1;current>=num;current--)
     {
      if(*current=='2')
       result[i]+=2*(calc(length-(current-num))-1);
      if(*current=='1')
       result[i]+=1*(calc(length-(current-num))-1);
     }
   // cout<<result<<endl;
    }
    else
    {
     for(current=num+length-1;current>=num;current--)
     {
      if(*current=='1')
       result[i]+=1*calc(length-(current-num))-1;
     }
   // cout<<result<<endl;
    }

   }
    i++;

}while(i<50);
for(i=0;i<50;i++)
{
   if(result[i]!=0)
    printf("%d\n",(int)result[i]);
   // cout<<endl;
   if(result[i]==0)
    break;
}


return 0;

}

bool isTwo(char *num)
{
for(char *temp=num;temp<num+strlen(num);temp++)
   if(*temp=='2')
    return true;
return false;
}


long calc(int n)
{
long re=1;
for(int i=0;i<n;i++)
   re=re*2;
return re;

}