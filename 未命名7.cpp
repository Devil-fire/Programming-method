
#include<cstdio>

#include<iostream>

#include<cstring>

#include<algorithm>

using namespace std;

typedef long long ll;

const int INF=0x3f3f3f3f;

const int N=2e5+5;

int a[N],p[N];

ll f[N][2];

int n;

int main()

{

    //freopen("f.txt","r",stdin);

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        scanf("%d%d",&p[i],&a[i]);

        f[i][0]=0;

        f[i][1]=-INF; //这个要初始化为负无穷，因为f[i][1]刚开始的时候根本就没有加入节点。

    }

//    memset(f,0,sizeof(f));

    for(int i=n;i>0;i--){

        f[i][1]=max(f[i][1],f[i][0]+a[i]);

        if(i==1)break;

        ll t0,t1;

        t0=max(f[p[i]][0]+f[i][0],f[p[i]][1]+f[i][1]);

        t1=max(f[p[i]][1]+f[i][0],f[p[i]][0]+f[i][1]);

        f[p[i]][0]=t0;

        f[p[i]][1]=t1;

    }

    cout<<f[0][0]<<endl;

    return 0;

}

