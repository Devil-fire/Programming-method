#include<cstdio>
using namespace std;  
const int INF=0x3f3f3f3f;
  //只保存上一行和当前行 
int main()  

{
	int n,m;
	long long a[500005],dp[2][500005]; 
    while(~scanf("%d %d",&n,&m))   //n个数字，m子段和 
    { 
        for(int i=1;i<=n;i++) 
			scanf("%lld",a+i);  
		for(int i=0;i<=n;i++)
			dp[0][i]=0,dp[1][i]=0;    //关键！此题答案只允许正值
        for(int i=1,k=1;i<=m;i++,k^=1)    //分为i段，k为两行之间的切换
        {
        	dp[k][i-1]=-INF;   //i==j时，杜绝与前一元素共伍
            long long maxpre=-INF;    //maxpre记录上一行的最大值
            for(int j=i;j<=n-m+i;j++)
            {
                maxpre=max(maxpre,dp[k^1][j-1]);     //随时更新上一行最大值
                dp[k][j]=max(dp[k][j-1],maxpre)+a[j]; //*对情况1、2的选择
            }
        }
        long long ans=-INF;
        for(int i=m;i<=n;i++)   //找到第m行的最大值，即为答案
                ans=max(ans,dp[m&1][i]);
        printf("%lld\n",ans);
    }  
}

