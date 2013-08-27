#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
void Shift()          /*移位密码*/
{
	char c[100];
	int length, i=0, key=0;
	clrscr();

	printf("********Shift Cipher********\nPlease input primal sentence: ");
	gets(c);
	length = strlen(c);
	printf("Input the key(0~26): ");
	scanf("%d", &key);
	getchar();

	if(key<0)
	{
	    printf("The value of key is error!\nPress any key to return...");
	    getch();
	    return;
	}
	for(i=0; i<length; i++)
	{
	    if(c[i]>96&&c[i]<123)
		c[i] = (c[i]+key-97)%26+65;
	    else if(c[i]>64&&c[i]<91)
		c[i] = (c[i]+key-65)%26+65;
	}
	printf("Result is: %s\n", c);
	for(i=0; i<length; i++)
	{
	    if(c[i]>64&&c[i]<91)
		c[i] = (c[i]-key-65+26)%26+97;
	}
	printf("\nAfter translated the sentence,we can see the primal sentence as follow:\n%s\n", c);
	printf("Press any key to return...");
	getch();
}

int gcd(int a, int b)    /*辗转相除法求a,b的最大公因数*/
{
	int k = 0;

	do
	{
	    k = a%b;
	    a = b;
	    b = k;
	}while(k!=0);
	return a;
}

int Ni(int a, int b)  /*求a相对于b的逆*/
{
	int i = 0;
	while(a*(++i)%b!=1);
	return i;
}

void Affine()          /*仿射密码*/
{
	char c[100];
	int length, i=0, ka=0, kb=0, tmp;
	clrscr();

	printf("********Affine Cipher********\nPlease input primal sentence: ");
	gets(c);
	length = strlen(c);
	printf("Input the key(2 numbers): ");
	scanf("%d%d", &ka, &kb);
	getchar();
	if(gcd(ka,26)!=1)
	{
	    printf("The value of the key is error!\nPress any key to return...");
	    return;
	}

	for(i=0; i<length; i++)
	{
	    if(c[i]>96&&c[i]<123)
		c[i] = (ka*(c[i]-97)+kb)%26+65;
	    else if(c[i]>64&&c[i]<91)
		c[i] = (ka*(c[i]-65)+kb)%26+65;
	}
	printf("Result is: %s\n", c);
	for(i=0; i<length; i++)
	{
	    if(c[i]>64&&c[i]<91)
	    {
		tmp = Ni(ka,26)*((c[i]-65)-kb);
		if(tmp<0)
		    c[i] = tmp%26+26+97;
		else
		    c[i] = tmp%26+97;
	    }
	}
	printf("\nAfter translated the sentence,we can see the primal sentence as follow:\n%s\n", c);
	printf("Press any key to return...");
	getch();
}

void Vigenere()    /*维吉利亚密码*/
{
	char c[100], key[100];
	int lenc, lenk, i=0, j=0, tmp;
	clrscr();

	printf("********Vigenere Cipher********\nPlease input primal sentence: ");
	gets(c);
	lenc = strlen(c);
	strcpy(c, strupr(c));
	printf("Input the key: ");
	gets(key);
	lenk = strlen(key);
	strcpy(key, strupr(key));
	for(; i<lenc; i++)
	{
	    j = j%lenk;
	    if(c[i]>64&&c[i]<91)
	    {
		c[i] = (c[i]-65+key[j]-65)%26+65;
		j++;
	    }
	}
	printf("Result is: %s\n", c);
	for(i=0, j=0; i<lenc; i++)
	{
	    j = j%lenk;
	    if(c[i]>64&&c[i]<91)
	    {
		tmp = c[i]-65-(key[j]-65);
		if(tmp>=0)
		    c[i] = tmp%26+97;
		else
		    c[i] = (tmp+26)%26+97;
		j++;
	    }
	}
	printf("\nAfter translated the sentence,we can see the primal sentence as follow:\n%s\n", c);
	printf("Press any key to return...");
	getch();
}

void Permutation() /*置换密码*/
{
	char c[100], *q;
	int *key, len, m, i, j=0;
	clrscr();

	printf("********Permutation Cipher********\nPlease input primal sentence: ");
	gets(c);
	strcpy(c, strupr(c));
	len = strlen(c);
	for(i=0; i<len; i++)
	{
	    if(c[i]<65||c[i]>90)
	    {
		for(j=i; j<len-1; j++)
		    c[j] = c[j+1];
		len--;
	    }
	}
	c[len] = '\0';
	printf("Input the length of the key: ");
	scanf("%d", &m);
	key = (int)malloc(m*sizeof(int));
	q = (int)malloc(len*sizeof(int));
	printf("Input the key: ");
	for(i=0; i<m; i++)
	{
	    scanf("%d", key+i);
	    key[i]--;
	}
	getchar();

	for(i=0; i<len; i++)
	{
	    j = (i/m)*m;
	    q[i] = c[*(key+i%m)+j];
	}
	q[i] = '\0';

	printf("Result is: %s\n", q);

	for(i=0, j=0; i<len; i++)
	{
	    j = (i/m)*m;
	    c[*(key+i%m)+j] = q[i]+32;
	}
	c[len] = '\0';

	printf("After translated the sentence,we can see the primal sentence as follow:\n%s\n", c);
	printf("Press any key to return...");
	free(key);
	free(q);
	getch();
}

void main()
{
    char i = '0';
    clrscr();

    while(i!='5')
    {
	clrscr();
	printf("********Press 1~5 to choose:********\n");
	printf("1.  Shift Cipher\n2.  Affine Cipher\n3.  Vigenere Cipher\n4.  Permutation Cipher\n5.  Exit\n");
        i = getch();
	if(i=='1')
	    Shift();
	else if(i=='2')
	    Affine();
	else if(i=='3')
	    Vigenere();
	else if(i=='4')
	    Permutation();
	else if(i=='5')
	    break;
    }
}