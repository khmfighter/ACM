
/*#include<cstdio>
#include<cctype>

int bto(char *s)
{
	return (s[0] - 48)*128 + (s[1] - 48)*64 + (s[2] - 48)*32 + (s[3] - 48)*16
			+ (s[4] - 48)*8 + (s[5] - 48)*4 + (s[6] - 48)*2 + (s[7] - 48)*1;
}

int main()
{
	int a, b, c, d;
	int n;
	char c1;
	char s[100];
	char ip1[9], ip2[9], ip3[9], ip4[9];
//	freopen("test.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", s);
		int k = 0;
		int j = 0;
		while(s[k] != '\0')
		{
			if(isdigit(s[k]))
			{
				if(j < 8)
					ip1[j] = s[k];
				else if(j >= 8 && j < 16)
					ip2[j-8] = s[k];
				else if(j >= 16 && j < 24)
					ip3[j-16] = s[k];
				else
					ip4[j-24] = s[k];
				j++;
			}
			k++;
		}
		ip1[9] = '\0';
		ip2[9] = '\0';
		ip3[9] = '\0';
		ip4[9] = '\0';
		a = bto(ip1);
		b = bto(ip2);
		c = bto(ip3);
		d = bto(ip4);
		printf("%d.%d.%d.%d\n", a, b, c, d);
	}
//	fclose(stdin);
	return 0;
}*/