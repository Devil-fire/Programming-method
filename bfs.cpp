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
int vis[105][105];
char map[105][105];

int main()
{
	int n,m,k,z,a=0,b=0,ans;
	int sx,sy,ex,ey,min,flag[2][2],xt,yt;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>map[i][j];
					
	cin>>a>>b;
	printf("%d %d\n",a,b);
	
	for(int i=0;i<a;i++){
		cin>>sx>>sy;
		if(map[sx-1][sy-1]!='#')
			map[sx-1][sy-1]='E';
	}
	//for(int i=0;i<b;i++)
	//{		
	ans=0;
	cin>>ex>>ey;
	memset(vis,0,sizeof(vis));
	q.push(node(ex,ey,0));
	vis[ex][ey]=1;
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		if(map[tmp.x][tmp.y]=='E')
		{
			ans=tmp.step;
			xt=tmp.x; yt=tmp.y;
			break;
		}
		for(int i=0;i<4;i++)
		{
			int x=tmp.x+dx[i],y=tmp.y+dy[i];
			if(x<0||x>=n||y<0||y>=m||map[x][y]=='#'||vis[x][y]==1)
					continue;
				q.push(node(x,y,tmp.step+1));	
				vis[x][y]=1;	
		}
	}
	//if(ans<min){min=ans;flag[0][0]=ex;flag[0][1]=ey;flag[1][0]=xt;flag[1][1]=yt;}
	q = queue<node>();
	//}
	if(ans!=0) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
