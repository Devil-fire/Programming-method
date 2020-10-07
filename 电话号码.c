#include<stdio.h>
#include<string.h>
#include<malloc.h>
long cou[1600];
long p(int b,int x);
long t(char a[]);
int error(char a[]);
void comp(long c[],int q);
int main()
{	
	char a[1600];
	int flag=0,flag1=0,i,q=0;
	long d,c[16000];
	printf("Error:\n");
	while(gets(a)!=NULL)
	{	
		if( error(a) )
		{	
			d=t(a);
			for(i=0;i<=q;i++)
			{	
				if(d==c[i])
				{
					cou[i]++;
					break;
				}
			}
			if(i>q)
			{
				c[i]=d;
				q++;
			}
		}
		else
		{
			printf("%s\n",a);
			flag=1;
		}
	}
	if(!flag)
		printf("Not found.\n");
	printf("\n");
	comp(c,q);
	printf("Duplication:\n");
	for(i=0;i<=q;i++)
		{
			if(cou[i]!=0)
			{
				printf("%ld",c[i]/10000);
				printf("-");
				printf("%.4ld",c[i]%10000);
				printf(" ");
				printf("%d\n",cou[i]+1);
				flag1=1;
			}
		}
	if(!flag1)
		printf("Not found.\n");
}
int error(char temp[1000000])
{
	int i=0,len;
	len=strlen(temp);
	for(i=0;i<len;i++)
         {      
		 		if(temp[i]==45)
                     continue;
                if((temp[i]>=68&&temp[i]<=70)||(temp[i]>=77&&temp[i]<=79)||(temp[i]==51)||(temp[i]==54))
                         return 1;
                else     return 0;
          }
	return 0;
}
long t(char temp[])
{
	int tel[1000000],d=0,i,len,q=0;
	len=strlen(temp);
	for(i=0;i<len;i++)
         {
		      if(temp[i]==45)  
					continue;
               if(temp[i]>=65&&temp[i]<=67)   
							{tel[q]=2;q++;continue;}
               if(temp[i]>=68&&temp[i]<=70)   
							{tel[q]=3;q++;continue;}
               if(temp[i]>=71&&temp[i]<=73)   
							{tel[q]=4;q++;continue;}
               if(temp[i]>=74&&temp[i]<=76)   
							{tel[q]=5;q++;continue;}
               if(temp[i]>=77&&temp[i]<=79)   
							{tel[q]=6;q++;continue;}
               if(temp[i]>=80&&temp[i]<=83)   
							{tel[q]=7;q++;continue;}
               if(temp[i]>=84&&temp[i]<=86)   
							{tel[q]=8;q++;continue;}
               if(temp[i]>=87&&temp[i]<=89)   
							{tel[q]=9;q++;continue;}
               else                           
							{tel[q]=temp[i]-48;q++;continue;}
         } 
	for(q=0;q<7;q++)
	   d=d+ p(tel[q],6-q);
	return d;
}
long p(int y,int x)
{	
	int i;
	long t=1;
	for(i=0;i<x;i++)
		t*=10;
	return y*t;
}
void comp(long c[],int q)
{	
    int i,j,k;
	long temp;
	for(i=0;i<=q-1;i++)
	{	k=i;
		for(j=k;j<=q;j++)
		{	if(c[k]>c[j])
				k=j;
		}
		if(k!=i)
		{	
		    temp=c[k];
			c[k]=c[i];
			c[i]=temp;
			temp=cou[k];
			cou[k]=cou[i];
			cou[i]=temp;
		}
	}
}

