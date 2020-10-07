#include<stdio.h> 
#include<string.h> 
int main() 
{ 
  int n,V,item; 
  scanf("%d %d",&n,&V); 
  long long dp[2*V+1]; 
 memset(dp,0,sizeof(dp)); 
   dp[0]=1;  
   
   for(int j=0;j<n;j++){ 
       scanf("%d",&item); 
     if(item%V==0) item=V; 
      else item%=V; 
      for(long long i=2*V;i>=item;i--) 
        { 
          dp[i]+=dp[i-item]; 
          dp[i]%=10000000; 
       } 
      for(long long i=V+1;i<=2*V;i++) 
        { 
          dp[i-V]+=dp[i]; 
          dp[i-V]%=10000000; 
          dp[i]=0; 
       } 
  } 
  printf("%lld\n",dp[V]%10000000);  
 }  
