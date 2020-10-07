#include<stdio.h>
#include<string.h>
int main()
{
	int T,i,j,k,p=0,m=0,z,cou=0,flag=1,flag2=1;char a[1000][1000],n[20];int r[20];char t;char b[12]="fattyhappy";
	scanf("%d",&T);
	for(i=0;i<T;i++)
		scanf("%s",a[i]);
	for(i=0;i<T;i++)
	{ 	
		cou=0;	p=0; m=0;
		int len=strlen(a[i]);	
		if(strlen(a[i])<10) ;
		else
		{
		for(j=0;j<len-9;j++)
		{
			p=0;
			for(k=j;k<j+10;k++)
			{
				if(a[i][k]!=b[p])  
					{
						cou++;n[m]=b[p];r[m++]=k+1;
						if(cou>2) continue;
					}
		//		printf("%c*%c*%d ",a[i][k],b[p],p);
				p++;
			}
			if(cou==0) {printf("%d %d\n",j+3,j+4);flag=0;goto line;}
			else if(cou==1)
			{
				for(z=0;z<j;z++) 
					if(a[i][z]==n[0]) {printf("%d %d\n",r[0],z+1);flag=0;goto line;}
				if(flag)
					for(z=j+10;z<len;z++) 
						if(a[i][z]==n[0]) {printf("%d %d\n",r[0],z+1);flag=0;goto line;}
			//	flag=1;
			 } 
			else if(cou==2)
				{
					flag2=1; flag=1;
					t=a[i][r[0]-1];a[i][r[0]-1]=a[i][r[1]-1];a[i][r[1]-1]=t;
					//printf("%d %d\n",r[0],r[1]);
					p=0;
					for(k=j;k<j+10;k++)
					{
						//printf("%c * %c\n",a[i][k],b[p]);
						if(a[i][k]!=b[p]) 
							flag2=0;
						p++;
					}
					p=0;
					//printf("%d\n",flag2); 
					if(flag2) {printf("%d %d\n",r[0],r[1]);flag=0;goto line;}
					else {t=a[i][r[0]-1];a[i][r[0]-1]=a[i][r[1]-1];a[i][r[1]-1]=t;}	
		}
			cou=0;	p=0; m=0;	
		}
		}
	line:	if(flag) printf("-1\n");
			flag=1;flag2=1;			
}}
