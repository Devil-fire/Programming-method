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
int vis[105][105][105];
char map[105][105];

int main()
{
	int n,m,k,z;
	int sx,sy;
	cin>>z;
	for(int p=0;p<z;p++)
	{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		scanf("%s",&map[i]);
		for(int j=0;j<m;j++)
			if(map[i][j]=='S')
			{
				sx=i;sy=j;
			}
	}
	//time++;
	memset(vis,0,sizeof(vis));
	q.push(node(sx,sy,0));
	vis[sx][sy][0]=1;
	int ans=0;
	//printf("%d %c %d %d\n",time%k,map[sx][sy],sx+1,sy+1);
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		//printf("%d\n",ans);
		//time++;//目前问题在time自加上 
		if(map[tmp.x][tmp.y]=='E'){
			ans=tmp.step;
			break;
		}
		for(int i=0;i<4;i++){
			int x=tmp.x+dx[i],y=tmp.y+dy[i];
			//printf("%d  %c  %d  %d  %d\n",time%k,map[x][y],x+1,y+1,tmp.step+1);
			if(x<0||x>=n||y<0||y>=m||map[x][y]=='#'||vis[x][y][(tmp.step+1)%k]==1)
					continue;
			
			if((map[x][y]=='*'&&(tmp.step+1)%k==0&&vis[x][y][(tmp.step+1)%k]==0)||map[x][y]!='*'&&map[x][y]!='#')
			{
				//printf("%d %c %d %d    %d\n",(tmp.step+1)%k,map[x][y],x+1,y+1,tmp.step+1);
				q.push(node(x,y,tmp.step+1));	
				vis[x][y][(tmp.step+1)%k]=1;
			}	
		}
	}
	if(ans!=0) printf("%d\n",ans);
	else printf("-1\n");
	q=queue<node>();
	memset(map,'0',sizeof(map));
	
	}
	return 0;
}
