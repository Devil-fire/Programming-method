#include<stdio.h>
typedef struct NODE 
{ 
int t; 
int d; 
}NODE;

int cmp( const void *a ,const void *b) 
{ 
return (*(NODE *)a).t > (*(NODE *)b).t ? 1 : -1; 
} 

int main()
{
	int i,j,n,q,k,r,z=0,sum=0,total=0,cou=0,ex,flag=1,max=0,ti; 
	scanf("%d %d",&n,&q);
	NODE node[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&node[i].t,&node[i].d);
		total+=node[i].d;
	}
	qsort(node,n,sizeof(node[0]),cmp); 
	
	for(j=0;j<q;j++)
	{
		scanf("%d",&k);
		if(k>(node[n-1].t-node[0].t)) printf("0\n");
		else 
		{		max=0;
				ti=node[0].t;ex=node[0].d; 
				for(r=0;r<n&&node[r].t<=node[0].t+k-1;r++)
					sum+=node[r].d;
				if(sum>max) max=sum;
				//printf("%d %d\n",max,node[r].d);
				for(z=0;z<n-r;z++)
				{
					if(node[z+r].t<=ti+k-1) sum+=node[z+r].d;
					else{
						while(node[z+r].t>ti+k-1)
						{
							sum-=ex;
							ex=node[++cou].d;
							ti=node[cou].t;
						}
						sum+=node[z+r].d;
					}
					if(sum>max) max=sum;
					}	
			//	printf("%d\n",sum);
			printf("%d\n",total-max);
			sum=0;	flag=1 ,max=0;ex=0;cou=0;
		 } 
	}
 } 
