
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void init(int table1[][30], const char* fileName)
{
	ifstream in1(fileName);
	char str[5];
	char ch;
	for(int i = 0; i < 16; i++)
	{
		/*in1.getline(strLine, 5, '\t');
		cout<<strLine;*/
		for(int j = 0; j < 30; j++)
		{
			int k = 0;
			while( isdigit( ch = in1.get() ) )
			{
				k++;
			}
			if(k == 0)
			{
				table1[i][j] = 0;
			}
			else
			{
				in1.seekg(-k-1, ios::cur);
				for(int m = 0; m < k; m++)
					str[m] = in1.get();
				str[m] = '\0';
				table1[i][j] = atoi(str);
				in1.get();
			}
		}

	}
}

int main()
{
	int table1[16][30];
	int table2[16][30];
	int table3[16][30];
	int table4[16][30];
	int table5[16][30];
	int table6[16][30];
	int table7[16][30];
	int table8[16][30];
	int table9[16][30];

//	char str[5];
//	char ch;
//	char pre;
/*	string str1 = "123";
	int a = atoi(str1.c_str());
	cout<<a;*/
//	char strLine[150];

//	ifstream in1("D:\\txt\\1.txt");

/*	int count = 0;
	for(int k = 0; k < 150; k++)
	{
		cout<<(pre = in1.get())<<endl;
		if(pre == '\t')count++;
		if(pre == '\n')break;
	}*/
//	cout<<count;

//	ifstream in2("D:\\txt\\1.txt");
//	ifstream in3("D:\\txt\\1.txt");
//	ifstream in4("D:\\txt\\1.txt");
//	ifstream in5("D:\\txt\\1.txt");
//	ifstream in6("D:\\txt\\1.txt");
//	ifstream in7("D:\\txt\\1.txt");
//	ifstream in8("D:\\txt\\1.txt");
//	ifstream in9("D:\\txt\\1.txt");



//	ofstream out1("D:\\txt\\2_modify.txt", ios::app|ios::in);

/*	while( ( ch = in1.get() ) )
	{
		if( isdigit(ch) )
			out1.put(ch);
		pre = ch;
		ch = in1.get();
		if(ch == '\t' || ch == '\n')
		{
			if(isdigit(pre))
				out1.put(ch);
			if(pre == '\t' || pre == '\n')
			{
				out1.put('0');
				out1.put(ch);
			}
		}
		else
			out1.put(ch);
		out1.flush();
	}*/

/*	ch = in1.get();
	while( ch )
	{
		pre = ch;
		if( pre == '\t' || pre == '\n')
		{
			out1.put(0);
			out1.put(pre);
		}
		else
			out1.put(pre);
		ch = in1.get();
	}*/
	

/*	for(int i = 0; i < 16; i++)
	{
		/*in1.getline(strLine, 5, '\t');
		cout<<strLine;*/
	/*	for(int j = 0; j < 30; j++)
		{
			int k = 0;
			while( isdigit( ch = in1.get() ) )
			{
				k++;
			}
			if(k == 0)
			{
				table1[i][j] = 0;
			}
			else
			{
				in1.seekg(-k-1, ios::cur);
				for(int m = 0; m < k; m++)
					str[m] = in1.get();
				str[m] = '\0';
				table1[i][j] = atoi(str);
				in1.get();
			}
		}

	}

	for(i = 0; i < 16; i++)
	{
		for(int j = 0; j < 30; j++)
			cout<<table1[i][j]<<" ";
		cout<<endl;
	}*/


	init(table1, "D:\\txt\\1.txt");
	init(table2, "D:\\txt\\2.txt");
	init(table3, "D:\\txt\\3.txt");
	init(table4, "D:\\txt\\4.txt");
	init(table5, "D:\\txt\\5.txt");
	init(table6, "D:\\txt\\6.txt");
	init(table7, "D:\\txt\\7.txt");
	init(table8, "D:\\txt\\8.txt");
	init(table9, "D:\\txt\\9.txt");

	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < 30; j++)
			cout<<table5[i][j]<<" ";
		cout<<endl;
	}

	ofstream out("D:\\txt\\out.txt", ios::app);
	ofstream out1("D:\\txt\\out3.txt", ios::app);

	int sum[16][30];

	for(i = 0; i < 16; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			sum[i][j] = table1[i][j] + table2[i][j] + table3[i][j] + table4[i][j] + 
						table5[i][j] + table6[i][j] + table7[i][j] + table8[i][j] + 
						table9[i][j];
			out<<sum[i][j]<<'\t';
		}
		out<<endl;
	}

	for(i=0; i < 16; i++)
	{
		out1<<i+1<<":"<<sum[i][0] + sum[i][1]<<" "<<sum[i][6] + sum[i][7]<<" ";
		out1<<sum[i][12] + sum[i][13]<<" "<<sum[i][18] + sum[i][19]<<" ";
		out1<<sum[i][24] + sum[i][25]<<endl;
	}
	return 0;
}
