#include<stdio.h>  
long long max(long long x,long long y)  
{  
    if(x>y) return x;  
    else return y;  
}      
long long dp[3][500005];  
int a[500005]; 
int main()  
{  
    int n,k=1;
	long long max1=-1e9,sum=-1e9;  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
        scanf("%d",&a[i]);  
    for(int i=0;i<=n;i++)
		dp[0][i]=0,dp[1][i]=-1e9; 
		
		for(int i=1;i<=3;i++)    
    	{
   	    	dp[k][i-1]=-1e9;   
        	max1=-1e9;    
        	for(int j=i;j<=n-3+i;j++)
        	{
            	max1=max(max1,dp[!k][j-1]);    
            	dp[k][j]=max(dp[k][j-1],max1)+a[j]; 
        	}
        if(k==1) k=0;
        else k=1;
    }   

	for(int i=3;i<=n;i++)  
        sum=max(sum,dp[1][i]);  
    printf("%lld\n",sum);  
    return 0;  
}  
