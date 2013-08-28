#include <string.h>
#include <stdio.h>

int main()
{
    int a[5]={0, 45, 9045, 1395495, 189414495};
    int b[5]={0, 9, 189, 2889, 38889};
    int c[5]={0, 10, 100, 1000, 10000};
    unsigned long i,j,k,n,t;
    scanf("%d",&t);
	while(t--)
    {
        scanf("%d",&n);
        for ( i = 1; i < 5; i++)
        if (n <= a[i]) break;              
        n -= a[i - 1];
        for (k = 0, j = 1; k < n; j++)
            k = b[i - 1] * j + i * j * (j + 1) / 2;      
        --j;           
        n = n - b[i - 1] * (j - 1) - i * j * (j - 1) / 2;     
        for(i = 1; i < 5; i++)
        if (n <= b[i]) break;                
        if (i == 1)         
			printf("%d\n",n);
        else                              
        {
          n -= b[i-1];   
          k = (n-1) / i + c[i-1];
		  char str[10];
          sprintf(str,"%d",k);
          n -= (n - 1) / i * i; 
		  printf("%c\n",str[n - 1]);
        }
    }    
    return 0;
}