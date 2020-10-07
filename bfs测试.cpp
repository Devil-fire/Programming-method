#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;


const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int vis[1005][1005];
char map[1005][1005];
int pre[2000000];
int flag[2][2];
struct node{
	int x,y;
	int step;
	node(int _x,int _y,int _step) :x(_x),y(_y),step(_step) {}
};
struct Cam
{
    int x,y;
}L[2000000];
void Print(int x)   

{
    int t;
    t = pre[x];
    if(t == 0)
    {
        printf("%d %d\n",flag[1][0]+1,flag[1][1]+1);
        printf("%d %d\n",L[x].x+1,L[x].y+1);
        return ;
    }
    else
    	Print(t);
    	printf("%d %d\n",L[x].x+1,L[x].y+1);
} 
void BFS(int xt,int yt,int x1,int y1,int n,int m)
{
    memset(vis,0,sizeof(vis));
    int Head = 0,End = 1;
    L[0].x = xt;
    L[0].y = yt;
    pre[0] = -1;
    while(Head < End)  
    {
        int x = L[Head].x;
        int y = L[Head].y;
        if(x == x1 && y == y1)
        {
            Print(Head);
            return ;
        }
        for(int i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
             if( !vis[xx][yy] && x >= 0 && x < n && y >= 0 && y < m && map[x][y] !='#' ){
             	 vis[xx][yy] = 1;
                L[End].x = xx;
                L[End].y = yy;
                pre[End] = Head;
                End++;
			 }
               
            }
			Head++;
        }
       return ; 
    }
int xt,yt; 
 int main()
{
	
	int n,m,a,b;
	int sx,sy,ex,ey;int ans=0x3f3f3f,cou=0,min=0x3f3f3f;
	queue<node>q;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",&map[i]); 
	}
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>ex>>ey;
		if(map[ex-1][ey-1]!='#')
		{
			map[ex-1][ey-1]='E';cou=1;
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<b;i++)
	{
		cin>>sx>>sy; 
		sx--;sy--;
		if(map[sx][sy]=='#') continue;
		else if(map[sx][sy]=='E') {printf("0\n%d %d\n",sx+1,sy+1);return 0;}
		q.push(node(sx,sy,0));
		vis[sx][sy]=1;
		while(!q.empty()){		
		node tmp=q.front();
		q.pop();
		for(int i=0;i<4;i++){
				int x=tmp.x+dx[i],y=tmp.y+dy[i];
				if(x<0||x>=n||y<0||y>=m||vis[x][y]==1||map[x][y]=='#')
					continue;
				//printf("%c  %d  %d  %d\n",map[x][y],x,y,j);
			if(map[x][y]=='E'){
				ans=tmp.step;
				xt=x;yt=y;
				break;
				}
				q.push(node(x,y,tmp.step+1));	
				vis[x][y]=1;
		}
	}
	if(ans+1<min) {min=ans+1;flag[0][0]=sx;flag[0][1]=sy;flag[1][0]=xt;flag[1][1]=yt;}
	memset(vis,0,sizeof(vis));   q=queue<node>();
		}
	if(cou==0) printf("Cruel game\n");
	else if(min==0x3f3f3f) printf("Peaceful world\n");
	else {
		printf("%d\n",min);
		//printf("%d %d %d %d %d %d\n",flag[1][0],flag[1][1],flag[0][0],flag[0][1],n,m);
		BFS(flag[1][0],flag[1][1],flag[0][0],flag[0][1],n,m);
	}
	
	return 0;
}
