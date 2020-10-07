#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
int main() 
{
    int flag[4]={1,1,1,1}; 
    priority_queue<int> c; 
    priority_queue<int, vector<int>, greater<int> > d;  
    queue<int> b;
 	stack <int>a;
	int n,k,op;
	while(~scanf("%d",&n)){
			for(int i=0;i<n;i++)
	{
		scanf("%d %d",&op,&k);
		if(op==1){
			a.push(k);b.push(k);c.push(k);d.push(k);
		}
		else if(op==2){
			//printf("%d %d %d %d\n",a.empty(),b.empty(),c.empty(),d.empty());
			if(!a.empty()&&!b.empty()&&!c.empty()&&!d.empty())
			{
				//printf("%d %d %d %d\n",k!=a.top(),k!=b.front(),k!=c.top(),k!=d.top());
				if(k!=a.top()) flag[0]=0;
				if(k!=b.front()) flag[1]=0; 
				if(k!=c.top()) flag[2]=0;
				if(k!=d.top()) flag[3]=0;
				a.pop();b.pop();c.pop();d.pop();
			 } 
			else printf("pool zls\n");
		}
	 }
	 if(flag[0]!=0&&flag[1]==0&&flag[2]==0&&flag[3]==0)printf("stack\n");
	 else if(flag[0]==0&&flag[1]!=0&&flag[2]==0&&flag[3]==0) printf("queue\n");
	 else if(flag[0]==0&&flag[1]==0&&flag[2]!=0&&flag[3]==0) printf("big priority queue\n");
	 else if(flag[0]==0&&flag[1]==0&&flag[2]==0&&flag[3]!=0) printf("small priority queue\n");
	 else if(flag[0]==0&&flag[1]==0&&flag[2]==0&&flag[3]==0) printf("pool zls\n");
	 else printf("not sure\n");
	 memset(flag,1,sizeof(flag));
	c=priority_queue<int> (); 
    d=priority_queue<int, vector<int>, greater<int> > ();  
    b=queue<int> ();
 	a=stack <int>();
	}
}
