#include<cstdio>
using namespace std;  
const int INF=0x3f3f3f3f;
  //ֻ������һ�к͵�ǰ�� 
int main()  

{
	int n,m;
	long long a[500005],dp[2][500005]; 
    while(~scanf("%d %d",&n,&m))   //n�����֣�m�Ӷκ� 
    { 
        for(int i=1;i<=n;i++) 
			scanf("%lld",a+i);  
		for(int i=0;i<=n;i++)
			dp[0][i]=0,dp[1][i]=0;    //�ؼ��������ֻ������ֵ
        for(int i=1,k=1;i<=m;i++,k^=1)    //��Ϊi�Σ�kΪ����֮����л�
        {
        	dp[k][i-1]=-INF;   //i==jʱ���ž���ǰһԪ�ع���
            long long maxpre=-INF;    //maxpre��¼��һ�е����ֵ
            for(int j=i;j<=n-m+i;j++)
            {
                maxpre=max(maxpre,dp[k^1][j-1]);     //��ʱ������һ�����ֵ
                dp[k][j]=max(dp[k][j-1],maxpre)+a[j]; //*�����1��2��ѡ��
            }
        }
        long long ans=-INF;
        for(int i=m;i<=n;i++)   //�ҵ���m�е����ֵ����Ϊ��
                ans=max(ans,dp[m&1][i]);
        printf("%lld\n",ans);
    }  
}

