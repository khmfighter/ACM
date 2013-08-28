

#include<iostream>
#include<string>
using namespace std;

char * multiply(const char *s1, const char *s2)
{
	int *result = new int[300];
	int *temp = new int[300];
	char *str_result = new char[300];
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int a, b, c, d;
	int m = 299;

	for(i = 0; i < 300; i++)
	{
		result[i] = 0;
		temp[i] = 0;
	}

	int * t_s1 = new int[strlen(s1) + 1];
	int * t_s2 = new int[strlen(s2) + 1];

	if(str_result == NULL)
	{
		cerr<<"error"<<endl;
		return 0;
	}

	string str1(s1);
	string str2(s2);

	const char *st1, *st2;

	if(str1.find('.') == -1)
	{
		st1 = s1;
	}
	else
	{
		str1.replace(str1.find('.'), 1, "");
		st1 = str1.c_str();
	}

	if(str2.find('.') == -1)
	{
		st2 = s2;
	}
	else
	{
		str2.replace(str2.find('.'), 1, "");
		st2 = str2.c_str();
	}

	for(i = 0; st1[i] != '\0'; i++)
	{
		t_s1[i] = st1[i] - 48;
	}
	
	for(i = 0; st2[i] != '\0'; i++)
	{
		t_s2[i] = st2[i] - 48;
	}

	for(i = strlen(st1)-1; i > -1; i--)
	{
		a = t_s1[i];
		b = 0;
		c = 0;
		d = 299;
		l = 299;
		for(int n = 0; n < 300; n++)
		{
			temp[n] = 0;
		}
		for(j = strlen(st2)-1; j > -1; j--)
		{
			b = t_s2[j];
			c += a*b;
			temp[d--] = c % 10;
			c = c/10;
		}
		temp[d] = c;
		c = 0;
		
		for(k = m; k > 0; k--)
		{
			int sum = c + temp[l] + result[k];
			result[k] = sum % 10;
			l--;
			c = sum/10;
		}
		m--;
	}

	for(i = 0; i < 300; i++)
	{
		if(result[i] != 0)
			break;
	}

	for(j = i, k = 0; j < 300; j++, k++)
	{
		str_result[k] = result[j] + 48; 
	}

	str_result[k] = '\0';

	delete[]result;
	delete[]temp;

	return str_result;
}

string getResult(char *s, int ex)
{
	int i;
	const char *result;
	int len = 0, length = 0;
	
	string str(s);
	
	if(str.find(".") == -1)
	{
		result = s;
	}
	else
	{
		len = str.substr(str.find('.')).length() - 1;
		result = str.replace(str.find('.'), 1, "").c_str();
	}
	
	for(i= 0; i < ex-1; i++)
	{
		result = multiply(result, s);
	}

	length = strlen(result);
	len = len * ex;

	if(length < len)
	{
		char *zero = new char[len - length + 2];
		for(i = 0; i < len-length+1; i++)
		{
			if(i == 0)
				zero[i] = '.';
			else zero[i] = '0';
		}
		zero[i] = '\0';

		string mystr(zero);
		mystr = mystr + "0";
		str = string(result);
		mystr.replace(mystr.length()-1, 1, str);
		return mystr;
	}
	
	length = length - len;

	if(length == strlen(result))
		return string(result);

	string rstr(result);
	str = rstr.substr(0, length) + ".";

	rstr.replace(0, length, str);

	return rstr;
}

int main()
{
	char st[10];
	int n;
	int i;
	while(cin>>st>>n)
	{
		for(i = strlen(st)-1; i > -1; i--)
		{
			if(st[i] == '0')
			{
				st[i] = '\0';
			}
			else
				break;
		}
		cout<<getResult(st, n)<<endl;
	}
}
