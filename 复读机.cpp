#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=0,k=1,m,n,cou=0,t,p=0,flag=1;
	int a[1000],c[1000],d[1000];
	char b[1000][100];
	scanf("%d %d",&m,&n);
	for(i=0;i<1000;i++)
		{
			c[i]=-1;  d[i]=-1;
		}
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		getchar();
		gets(b[i]);
	}
	d[0]=a[0];	
	for(i=0;i<n;i++)
		if(!strcmp(b[i],b[i+1])) c[j++]=a[i+1];
		else d[k++]=a[i+1];
	for(i=0;i<m;i++)
	{
		for(p=0;p<n;p++)
		{
			if(i+1==a[p]) flag=0;
		}	
		if(flag) c[j++]=i+1;
		flag=1;
	}
	
	for(i=0;c[i]!=-1;i++)
		for(j=0;d[j]!=-1;j++)
			if(c[i]==d[j]) c[i]=-2;
			
	for(i=0;c[i]!=-1;i++)               
		for(k=i+1,j=k;j<=999;j++)            
  			if(c[j]!=c[i])                
  				c[k++]=c[j];  
  				
	//for(i=0;i<5;i++) printf("%d\n",c[i]);			                   
	for(i=0;c[i]!=-1;i++)
		if(c[i]!=-2)
			cou++;
	//printf("%d\n",cou);		
 	for ( i = 0; i < cou-1; i ++ )
    	for ( j = i + 1; j < cou; j ++)
    		if ( c[ i ] > c[ j ] ) { t = c[ i ]; c[ i ] = c[ j ]; c[ j ] = t; }	
	/*for(i=0;i<j;i++) printf("%d ",c[i]);
	printf("\n");
	for(i=0;i<k;i++) printf("%d ",d[i]);
	printf("\n");
	printf("%d %d %d\n",c[0],c[1],cou);*/
	if(cou==1) printf("%d\n",c[0]);
	else if(cou>=2)
	{
		for(i=0;i<cou-1;i++)
		{
			if(c[i]==-2) 
				cou++; 
			if(c[i]!=-2)printf("%d ",c[i]);
		}
			
		printf("%d\n",c[cou-1]);
	}
	else if(cou==0) ;
		
 } 
 

