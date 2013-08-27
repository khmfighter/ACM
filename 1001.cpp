#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Len 200
char r[2*Len-1];
//�������˷��������������ִ�������һ����������ȥ��ǰ��0�ģ�
void lnmp(char *cs,char *bcs)
{
	char cjr[Len][Len][2];
	int i,j,k,l,cslen,bcslen,rlen,jw=0,temp,out=0;
	cslen=strlen(cs);
	bcslen=strlen(bcs);
	rlen=cslen+bcslen-1;
	//���ɾ��α�����ά���飩
	for(i=cslen-1;i>=0;i--)
	for(j=bcslen-1;j>=0;j--)
	{
	      temp=(cs[i]-'0')*(bcs[j]-'0');
	       cjr[j][i][0]=temp/10;
	       cjr[j][i][1]=temp%10;
	}
	//����������ע��һ�������ԵĶ�����������һλ����ǰһλ��Ϊ���α���ͷ���±��ݼ�������֮�ͣ�
	for(l=rlen;l>=0;l--)
	{
	       temp=jw;
	       for(i=cslen-1;i>=0;i--)
	       for(j=bcslen-1;j>=0;j--)
	       for(k=1;k>=0;k--)
	       if(l==i+j+k) 
	           temp=temp+cjr[j][i][k];
	       jw=temp/10;
	       r[l]=temp%10+'0';
	}
	for(l=0;l<rlen;l++) 
	      if(r[l]!='0') break;
	if(l) 
		for(i=l;i<=rlen+1;i++)
			r[i-l]=r[i];
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
		for(i=0;i<temp;i++) 
			r[i]='\0';
		
		//��С������λ��
		temp=strlen(R);
		for(i=0;i<temp;i++)
			if(R[i]=='.') break;
		//������С������ת����������������ת������
		if(i!=temp)
		{
		       flag=1;
		       xsdws=(temp-i-1)*N; 
		       for(j=i;j<=temp;j++)
			  R[j]=R[j+1];
		}
		//ȥ��ǰ���㣬���ٲ���Ҫ�ļ�������
		for(i=0;i<temp;i++) 
			if(R[i]!='0') 
				break;
		if(i) 
		  for(j=i;j<=temp;j++)
		  	R[j-i]=R[j];
		strcpy(r,R);
		for(i=1;i<N;i++)
			lnmp(r,R);
		temp=strlen(r);
		//������������ֱ����������������Ҫ���Ǽ�������
		if(!flag)
		{
		       for(j=0;j<temp;j++)
		       putchar(r[j]);
		}
		//ΪС��ʱ����Ҫ����ȥ��ĩβ��Ч���㣬����λ����������Ҫ�����㣬���潫��ʾ�Ƚϵ��͵�����
		else
		{       
		       i=temp-xsdws;
		       if(temp>xsdws)
		       {
		              i=temp-xsdws;
		              for(j=0;j<i;j++)     
		              		putchar(r[j]);
		              for(k=temp-1;k>=0;k--)       
		              		if(r[k]!='0') break;
		              if(i<=k) putchar('.');
		        	   for(j=i;j<k+1;j++)     
		        	   	putchar(r[j]);
		       }
		       else
		       {
		              i=xsdws-temp;
		              putchar('.');
		              for(j=0;j<i;j++)     
		              		putchar('0');
		              for(k=temp-1;k>=0;k--)     
		              		if(r[k]!='0') break;
		              for(j=0;j<k+1;j++)      
		              		putchar(r[j]);       
		       }
		}
		putchar('\n');
	}
	return 0;
}
