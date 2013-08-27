#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Len 200
char r[2*Len-1];
//大整数乘法：输入两个数字串，返回一个结果串（去除前导0的）
void lnmp(char *cs,char *bcs)
{
char cjr[Len][Len][2];
int i,j,k,l,cslen,bcslen,rlen,jw=0,temp,out=0;
cslen=strlen(cs);
bcslen=strlen(bcs);
rlen=cslen+bcslen-1;
//生成矩形表（三维数组）
for(i=cslen-1;i>=0;i--)
for(j=bcslen-1;j>=0;j--)
{
	temp=(cs[i]-'0')*(bcs[j]-'0');
       cjr[j][i][0]=temp/10;
       cjr[j][i][1]=temp%10;
}
//求出结果（注意一个规律性的东西，从最后一位到最前一位，为矩形表里头的下标递减的数字之和）
for(l=rlen;l>=0;l--)
{
       temp=jw;
       for(i=cslen-1;i>=0;i--)
       for(j=bcslen-1;j>=0;j--)
       for(k=1;k>=0;k--)
       if(l==i+j+k) temp=temp+cjr[j][i][k];
       jw=temp/10;
       r[l]=temp%10+'0';
}
for(l=0;l<rlen;l++) if(r[l]!='0') break;
if(l) for(i=l;i<=rlen+1;i++) r[i-l]=r[i];
}
int main()
{
char R[Len];
int N;
int i,j,k,xsdws,temp,flag;
while(scanf("%s %d",R,&N)!=EOF)
{
i=1,flag=0;
temp=strlen(r);
for(i=0;i<temp;i++) r[i]='\0';

//求小数点的位置
temp=strlen(R);
for(i=0;i<temp;i++)
if(R[i]=='.') break;
//如果是小数，先转换成整数，后面再转换回来
if(i!=temp)
{
       flag=1;
       xsdws=(temp-i-1)*N; 
       for(j=i;j<=temp;j++)
       R[j]=R[j+1];
}
//去除前导零，减少不必要的计算次数
for(i=0;i<temp;i++) if(R[i]!='0') break;
if(i) for(j=i;j<=temp;j++) R[j-i]=R[j];
strcpy(r,R);
for(i=1;i<N;i++)
lnmp(r,R);
temp=strlen(r);
//如果是整数，直接输出结果，否则要考虑几种情况
if(!flag)
{
       for(j=0;j<temp;j++)
       putchar(r[j]);
}
//为小数时，需要考虑去掉末尾无效的零，如果位数不够，需要补充零，下面将出示比较典型的例子
else
{       
       i=temp-xsdws;
       if(temp>xsdws)
       {
              i=temp-xsdws;
              for(j=0;j<i;j++)       putchar(r[j]);
              for(k=temp-1;k>=0;k--)       if(r[k]!='0') break;
              if(i<=k) putchar('.');
              for(j=i;j<k+1;j++)       putchar(r[j]);
       }
       else
       {
              i=xsdws-temp;
              putchar('.');
              for(j=0;j<i;j++)       putchar('0');
              for(k=temp-1;k>=0;k--)       if(r[k]!='0') break;
              for(j=0;j<k+1;j++)       putchar(r[j]);       
       }
}
putchar('\n');
}
return 0;
}
