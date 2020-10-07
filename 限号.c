#include<stdio.h>
#include<string.h>
int vis[105],map[105][105],num[105][105][105],n,m,cou=0,flag=0;
void dfs(int step,int e,int nu)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(map[step][i]==1&&vis[i]==0&&num[step][i][nu]==1)
		{//printf("%d \n",map[step][i]);
			//printf("%d %d %d\n",step,i,nu);
			if(i==e) {flag=1;break;}
			vis[i]=1;
			dfs(i,e,nu);
		}
	}
	
	return;
}
int main()
{
	int i,j,x,y,z,nu,k,s,e;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		map[x-1][y-1]=1;map[y-1][x-1]=1;num[x-1][y-1][z]=1;num[y-1][x-1][z]=1;
	}
/*	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}*/
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{ 
		scanf("%d %d",&s,&e);s--;e--;
		for(nu=1;nu<=m;nu++)
		{
			memset(vis,0,sizeof(vis));
			vis[s]=1;
			//printf("%d %d\n",nu,m); 
			dfs(s,e,nu);
			if(flag) cou++;
			flag=0;
		 } 
		printf("%d\n",cou);
		cou=0;
	}
		
//	printf("\n");
	return 0;
}


