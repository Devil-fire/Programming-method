#include <stdio.h> 
#include <math.h>
int a[100000],n;
void quicksort(int left,int right) 
{ 
    int i,j,t,temp; 
    if(left>right) 
       return;                    
    temp=a[left]; 
    i=left; 
    j=right; 
    while(i!=j) 
    { 
                   while(a[j]>=temp && i<j) 
                            j--; 
                   while(a[i]<=temp && i<j) 
                            i++; 
                   if(i<j) 
                   { 
                            t=a[i]; 
                            a[i]=a[j]; 
                            a[j]=t; 
                   } 
    } 
    a[left]=a[i]; 
    a[i]=temp;       
    quicksort(left,i-1);
    quicksort(i+1,right);
} 
int main() 
{ 
    int i,j,t,c,m,q,cou,time,k,cishu,z;
	double result[100000];
	scanf("%d",&cishu);
	for(z=0;z<cishu;z++)
	{
    scanf("%d %d",&n,&c); 
    for(i=1;i<=n;i++) 
        scanf("%d %d %d",&a[i],&m,&q); 
    quicksort(1,n); 
	scanf("%d",&cou);
	for(i=1;i<=cou;i++)
	{
		scanf("%d %d",&time,&k);
		result[i]=sqrt(2*(double)c*(double)time+(double)a[k]*(double)a[k]);
	}	
    for(i=1;i<=cou;i++) 
        printf("%.3lf\n",result[i]); 	 
	 } 
		 
    return 0; 
} 
