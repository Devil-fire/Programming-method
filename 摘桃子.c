#include<stdio.h>
int main()
{
	int i,j,k,n,a[3005],b[3005],m,sum=0,sheng=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i],&b[i]);		
	int max=0,day,tol=0,one=0;
	for(i=0;i<n;i++) if(a[i]>max) max=a[i];
	for(day=1;day<=max;day++) {
			for(i=0;i<n;i++)
	{	
		if(a[i]==day) one+=b[i];}
		tol=sheng+one;
		if(m>tol) 
		{
			sum+=tol;
			sheng=0;	
		}
		else
		{
			sum+=m;
			if(m>sheng) sheng=tol-m;
			else sheng=one;	
		}
		one=0;
	}
	
	 if(m>sheng) sum+=sheng; else sum+=m; 
	printf("%d\n",sum);	
	return 0;	
    
 } 
