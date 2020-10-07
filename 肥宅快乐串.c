#include<stdio.h>
#include<string.h>
#
int main()
{
	int T,i,j,k,p,m=0,z,cou[200],flag=1,flag2=1;char a[1000][1000];char t;char b[12]="fattyhappy";
	scanf("%d",&T);
	for(i=0;i<T;i++)
		scanf("%s",a[i]);
	for(i=0;i<T;i++)
	{ 		
				for(i=0;i<strlen(a[i])-9;i++)
				{
					for(j=i,k=0;j<i+10;j++)
					{
						if(a[i][j]!=b[j-i]) 
						{	
							cou[k++]=j-i;
						}	
					}
					if(k==0)
					{
							printf("%d %d\n",i+3,i+4);flag=1;break;
					}
					if(k==1)
					{
						for(p=0;p<i;p++)
						{
							if(a[i][p]==b[cou[0]]) {printf("%d %d\n",cou[0]+i+1,p+1);flag=1;break;}
						}
						if(flag) break;
						for(p=i+10;p<strlen(a[i]);p++)
						{
							if(a[i][p]==b[cou[0]]) {printf("%d %d\n",cou[0]+i+1,p+1);flag=1;break;}
						}
						if(flag) break;
					}
					if(k==2)
					{
						if( (a[i][cou[0]+i]==b[cou[1]]) && (a[i][cou[1]+i]==b[cou[0]]) ){printf("%d %d\n",cou[0]+i+1,cou[1]+i+1); flag=1;break;}
					}
				 }
				 if(flag==0) printf("-1\n") ;
				 memset(cou,0,sizeof(cou));
}}
