#include<iostream>
#include<cstring>

using namespace std;

long long max1(long long x,long long y)
{
	if(x>y) return x;
	else return y; 
}

int a[200005],p[200005];
long long d[200005][2];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>a[i];
        d[i][0]=0;
        d[i][1]=-100000000; 
    }
    for(int i=n;i>0;i--){
        d[i][1]=max1(d[i][1],d[i][0]+a[i]);
        if(i==1) break;
        long long n,m;
        n=max1(d[p[i]][0]+d[i][0],d[p[i]][1]+d[i][1]);
        m=max1(d[p[i]][1]+d[i][0],d[p[i]][0]+d[i][1]);
        d[p[i]][0]=n;
        d[p[i]][1]=m;
    }
    cout<<d[1][1]<<endl;
    return 0;

}

