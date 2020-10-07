#include<stdio.h>
#include<string.h>
int stu[105][2];
int vis[105];

void dfs(int i)
{
	if(vis[i]==0)
	{
		vis[i]=1;
		dfs(stu[i-1][1]);
	 } 
	else printf("%d",i);
}

int main()
{
	int i,n;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		scanf("%d",&stu[i][1]);
		stu[i][0]=i+1;
	}
	memset(vis,0,sizeof(vis));
	for(i=0;i<n-1;i++){
		dfs(i+1);
		printf(" "); 
		memset(vis,0,sizeof(vis));
	}
	dfs(n);
	printf("\n");	
 } 
