#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int T,m,n,k;
	long long dp1sum[2002],dp2sum[2002];
	long long dp1[2002]={0},dp2[2002]={0};
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		memset(dp1,0,sizeof(dp1));memset(dp2,0,sizeof(dp2));
		memset(dp1sum,0,sizeof(dp1sum));memset(dp2sum,0,sizeof(dp2sum));
		scanf("%d %d %d",&n,&m,&k);
		//for(int j=1;j<=n;j++) printf("%d %d",dp1[j],dp2[j]); 
		for(int j=1;j<=n;j++)
		{
			if(j>0&&j<k) {dp1[j]=0;dp2[j]=1;dp1sum[j]=dp1sum[j-1]+dp1[j];dp2sum[j]=dp2sum[j-1]+dp2[j];}
			else {
				//for(int z=1;z<=j-k;z++) {dp1sum1+=dp1[z];dp2sum+=dp2[z];}
				//for(int z=1;z<=j-1;z++) dp1sum2+=dp1[z];
				dp1[j]=(dp1sum[j-k]*(m-1)+dp2sum[j-k]+1)%998244353;
				dp2[j]=(dp1sum[j-1]*m+1)%998244353;
				dp1sum[j]=dp1sum[j-1]+dp1[j];dp2sum[j]=dp2sum[j-1]+dp2[j];
			}
			//printf("%d\n",dp1[j]+dp2[j]);

		}
		printf("%lld\n",(dp1[n]*m+dp2[n])%998244353);
	 } 
 } 
