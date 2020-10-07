#include<iostream>
#include<cstring> 
using namespace std;
	
	int map[102][102];
	bool vis[102];


void DFS(int i,int n)
{
	int j;
	vis[i]=true;//把现在这个点设置为已访问
	//cout<<"V"<<i<<endl;//把现在的这个点输出
	for(j=0;j<n;j++)//把跟这个点有边的未访问的点都访问了
	{
		if(map[i][j]==1 && !vis[j])//找到有边且没访问过的点，就深入一层
			DFS(j,n);
	}
}

void DFS_visit(int n)
{
	memset(vis,false,sizeof(vis));//初始化所有的顶点都没访问过
	int i,j;
	for(i=0;i<n;i++)
	{
		if(!vis[i])//如果这个点没访问过就对这个点深度优先搜索
			DFS(i,n);
		else cout<<i<<endl;
	}
}


int main()
{
	int a,b;
	int n;
	cin>>n;	

	for(int i=0;i<n;i++)
	{
		cin>>b;
		map[i][b]=map[b][i]=1;
	}
	DFS_visit(n);
}
