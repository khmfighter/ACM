#include<string>
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
}*/