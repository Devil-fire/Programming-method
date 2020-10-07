#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=0,k=1,m,n,flag=1;
	int a[1001],c[1001],d[1001];
	char b[1001][105];
	scanf("%d %d",&m,&n);
	for(i=0;i<1001;i++)
	{
		c[i]=-1;  d[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		getchar();
		gets(b[i]);
	}
	for(i=0;i<m;i++)
		c[i]=i+1;
	d[0]=a[0];	
	for(i=0;i<1001;i++)
		if(strcmp(b[i],b[i+1])!=0) d[k++]=a[i+1];
	for(i=0;i<1001;i++)
		for(j=0;j<1001;j++)
			if(c[i]==d[j]) c[i]=-2;
	for(i=0;i<1001;i++)
		if(c[i]!=-1&&c[i]!=-2)
		{
			printf("%d",c[i]);k=i;flag=0;break;
		}
	for(i=k+1;i<1001;i++)
		if(c[i]!=-1&&c[i]!=-2)
			printf(" %d",c[i]);
	if(flag);else printf("\n");			
}
