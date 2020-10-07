#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

struct node{
	int x,y;
	int step;
	node(int _x,int _y,int _step) :x(_x),y(_y),step(_step) {}
};

queue<node>q;
int vis[1005][1005];
char map[1005][1005];

int main()
{
	int n,m,k;
	int sx,sy,ex,ey;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		scanf("%s",&map[i]); 
	}
	cin>>sx>>sy>>ex>>ey;
	sx--;sy--;
	map[ex-1][ey-1]='E';
	/*for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			printf("%c",map[i][j]); */
	memset(vis,0,sizeof(vis));
	q.push(node(sx,sy,0));
	vis[sx][sy]=1;
	int ans=0;
	while(!q.empty()){		
		node tmp=q.front();
		q.pop();
		
	
		for(int i=0;i<4;i++){
			for(int j=1;j<=k;j++)
			{
				int x=tmp.x+dx[i]*j,y=tmp.y+dy[i]*j;
				if(x<0||x>=n||y<0||y>=m||vis[x][y]==1)
					continue;
				if(map[x][y]=='#') break;
				//printf("%c  %d  %d  %d\n",map[x][y],x,y,j);
			if(map[x][y]=='E'){
				ans=tmp.step;
				printf("%d\n",ans+1);
				return 0;
				}
				q.push(node(x,y,tmp.step+1));	
				vis[x][y]=1;
			}	
		}
	}
	printf("-1\n");
	return 0;
}
