#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;
int a[N],p[N];
ll f[N][2];
int n;
vector<int>e[N];
void dfs(int u)
{
    if(e[u].empty()){
        f[u][1]=a[u];
        f[u][0]=0;
        return;
    }
    f[u][0]=0;
    f[u][1]=-INF;
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        dfs(v);
        ll t0=f[u][0],t1=f[u][1];
        f[u][0]=max(t0+f[v][0],t1+f[v][1]);
        f[u][1]=max(t1+f[v][0],t0+f[v][1]);
    }
    f[u][1]=max(f[u][1],f[u][0]+a[u]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>a[i];
        e[p[i]].push_back(i);
    }
    dfs(1);
    cout<<f[1][1]<<endl;
}

