#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;

int mapping(const char *old, char *phone)
{
	char ch;
	int i=0,j=0;
	while(ch = old[i])
	{
		switch(ch)
		{
		case 'A':case 'B':case 'C':
			phone[j++] = '2';
			break;
		case 'D':case 'E':case 'F':
			phone[j++] = '3';
			break;
		case 'G':case 'H':case 'I':
			phone[j++] = '4';
			break;
		case 'J':case 'K':case 'L':
			phone[j++] = '5';
			break;
		case 'M':case 'N':case 'O':
			phone[j++] = '6';
			break;
		case 'P':case 'R':case 'S':
			phone[j++] = '7';
			break;
		case 'T':case 'U':case 'V':
			phone[j++] = '8';
			break;
		case 'W':case 'X':case 'Y':
			phone[j++] = '9';
			break;
		}
		if(isdigit(ch))
			phone[j++] = ch;
		i++;
		if(j==3)
			phone[j++]='-';
	}
	phone[8]=0;
	return 0;
}

int main()
{
	string str;
	int n;
	int count;
	int bHave = 0;
	vector<char*> svec;
	char phone[9];
	cin>>n;
	while(n--)
	{
		cin>>str;
		mapping(str.c_str(),phone);
		//svec.push_back(phone);
		svec.insert(svec.end(),phone);
	}
	sort(svec.begin(),svec.end());
	for( vector<char*>::iterator it=svec.begin(); it!=svec.end();it++)
		cout<<(*it)<<endl;
	count = 1;
	for(int i=0; i<svec.size(); i++)
	{
		char temp[9];
		strcpy(temp,svec[i]);
		for(int j=i+1;j<svec.size();j++)
		if(strcmp(temp,svec[j])==0)
		{
			bHave = 1;
			count++;
		}
		else 
		{
			cout<<temp<<" "<<count<<endl;
			i=j-1;
			count=1;
		}
		if(j==svec.size())
		{
			cout<<temp<<" "<<count<<endl;
			break;
		}

	}
	if(!bHave)
		cout<<"No duplicates.";
	return 0;
}
