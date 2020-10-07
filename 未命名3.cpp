#include<stdio.h>
int main()
{
	int i,j,k,n,cou=0,t=0;
	char a[200002];
	int b[128];
	scanf("%d",&n);
	getchar();
	gets(a);
	for(i=0;i<n;i++)
		b[a[i]]++;
	for(i=48;i<123;i++)
		if(b[i]%2==1) cou++;	
	if(cou==0) printf("0\n");
	else printf("%d\n",cou-1);

		cou=0;
	for(i=48;i<123;i++)
	{
		if(b[i]%2==1&&b[i]!=0) cou++;
		if(cou>1&&b[i]%2==1&&b[i]!=0)
		{
			for(j=0;j<b[i];j++) printf("%c",i); printf("\n"); 
		} 
		else if(cou==1&&b[i]%2==1&&b[i]!=0) {
			k=i;t=b[i];	
		}
	}
	//printf("%d\n",k); 
	for(i=48;i<123;i++)
		if(b[i]%2==0&&b[i]!=0&&i!=' ')
			for(j=0;j<b[i]/2;j++) printf("%c",i);
	for(i=0;i<t;i++)
		printf("%c",k);
	for(i=123;i>=48;i--)
		if(b[i]%2==0&&b[i]!=0&&i!=' ')
			for(j=0;j<b[i]/2;j++) printf("%c",i);
	printf("\n");			
	
}
