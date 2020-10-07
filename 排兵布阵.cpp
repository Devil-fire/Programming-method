#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	long int n,i,x[100005],y[100005];
	long long sumx,sumy,sum;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>x[i]>>y[i];
	sort(x,x+n);
	sort(y,y+n);
	for(i=0;i<n;i++)
		x[i]-=i;
	sort(x,x+n);
	sumx=0;
	sumy=0;
	for(i=0;i<n;i++)
	{
		sumx+=abs(x[i]-x[n/2]);
		sumy+=abs(y[i]-y[n/2]);
	}
	sum=sumx+sumy;
	cout<<(sum)<<endl;
}

