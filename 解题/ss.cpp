#include <stdio.h>
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