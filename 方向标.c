#include<stdio.h>  
long long max(long long x,long long y)  
{  
    if(x>y) return x;  
    else return y;  
}      
long long dp[2005];  
int a[2005]; 
int main()  
{  
    int n,left=-1,right=-1,flag1=1,flag2=1;
	dp[1]=1;dp[2]=1;  
    scanf("%d",&n);  
    for(int i=1;i<=n+1;i++)  
        scanf("%d",&a[i]);  
	for(int i=3;i<=n+1;i++)    
    {   
        for(int j=i;j>0;j--)
	    {
            if(a[j]<a[i]&&flag1) {left=j;flag1=0;}
            else if(a[j]>a[i]&&flag2) {right=j;flag2=0;} 
			//printf("%d %d %d %d\n",left,right,a[i],a[j]);
        }
        
        if(left!=-1&&right!=-1) dp[i]=(dp[left]+dp[right])%2147483647;
        else dp[i]=dp[i-1];
        flag1=1;flag2=1;left=-1;right=-1;
    }    
    printf("%lld\n",dp[n+1]);  
    return 0;  
}  
