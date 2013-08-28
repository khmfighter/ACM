
#include<cstdio>
#include<cstring>

void encode(const char* text, char* dest)
{
	int i;
	int j = 0;
	int count = 0;
	char pre = '\0';
	for(i = 0; i <= strlen(text); i++)
	{
		if(text[i] == pre)
		{
			count++;
			if(count == 9)
			{
				if(text[i] == '1')
				{
					dest[j] = '9';
					dest[++j] = '1';
					dest[++j] = '1';
				}
				else
				{
					dest[j] = '9';
					dest[++j] = text[i];
				}
				j++;
				count = 0;
			}
		}
		else
		{
			if(count == 0)
			{
				count = 1;
				continue;
			}
			if(count == 1)
			{
				if(pre == '1')
				{
					dest[j] = '1';
					dest[++j] = '1';
				}
				else
					dest[j] = pre;
				j++;
			}
			else if(count > 1)
			{
				if(pre == '1')
				{
					dest[j] = count + 48;
					dest[++j] = '1';
					dest[++j] = '1';
				}
				else
				{
					dest[j] = count + 48;
					dest[++j] = pre;
				}
				j++;
			}
			if(text[i] != '\0')
			{
				dest[j++] = '1';
			}
			count = 1;
		}
		pre = text[i];
	}
	dest[j] = '\0';
}
