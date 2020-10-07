#include<stdio.h>
int main()
{
	int a[100]={1,1,1,2,2,2,3,3,3,4,5,6,7,7,7},i,j,n=15;
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",a[i],a[i+1]);
		if(a[i]==a[i+1])
		{
			for(j=i+1;j<n;j++)
				a[j]=a[j+1];
			i--;n--;		
		}
		}
	for(i=0;i<7;i++)
		printf("%d\n",a[i]);	
}  
