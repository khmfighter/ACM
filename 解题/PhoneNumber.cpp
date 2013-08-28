
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
}*/