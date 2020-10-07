#include<iostream>
#include<vector>
using namespace std;
long long max(long long x,long long y)
{
	if(x>y) return x;
	else return y;
}
int a[200005],p[200005];
long long d[200005][2];
int n;
vector<int>e[200005];
void dfs(int t)
{
    if(e[t].empty()){
        d[t][1]=a[t];
        d[t][0]=0;
        return;
    }
    d[t][0]=0;
    d[t][1]=-1000000;
    for(int i=0;i<e[t].size();i++){
        int v=e[t][i];
        dfs(v);
        long long m=d[t][0],n=d[t][1];
        d[t][0]=max(m+d[v][0],n+d[v][1]);
        d[t][1]=max(n+d[v][0],m+d[v][1]);
    }
    d[t][1]=max(d[t][1],d[t][0]+a[t]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>a[i];
        e[p[i]].push_back(i);
    }
    dfs(1);
    cout<<d[1][1]<<endl;
    return 0;
}

