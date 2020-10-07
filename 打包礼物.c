#include<stdio.h>
#include<stdlib.h> 
typedef struct NODE
{
	int num,v;
	int p;
	int flag;
	
}NODE;
NODE node[10000];

int cmp ( const void *a , const void *b ) 
{ 
return (*(NODE*)a).v>(*(NODE*)b).v?1:-1;
}

void print(struct NODE a)
{	
	NODE newa=node[a.p];
	node[a.p].p=-1; 
	if(a.p!=-1)
	{
		print(newa);
		printf(" %d",newa.num);
	 } 
}

int main()
{
	int i,j,k,min=0,cou=0,flag1=0,cou1=0;
	scanf("%d",&k);
	
	for(i=0;i<k;i++)
	{
		scanf("%d",&node[i].v);
		node[i].num=i+1;
		node[i].p=-1;
		node[i].flag=1;
	}
	qsort(node,k,sizeof(node[0]),cmp);
	
	for(i=0,j=1;2*node[i].v<=node[k-1].v && (j<=k-1) && i<j;j++)
	{
		if(node[j].v>=2*node[i].v)
		{
			node[i].p=j;
			node[i].flag=0;
			//node[j].num=node[i].num+1;
			i++;
		}
	}
for(i=0;i<k;i++)
		printf("%d %d %d %d\n",node[i].num,node[i].p,node[i].flag,node[i].v);
	for(i=0;i<k;i++)
		if(node[i].flag) cou++;
	printf("%d\n",cou); 
	/*for(i=k-1;i>0;i--)
	{
		int j=i;
	//printf("%d  %d  %d  %d\n",node[i].v,node[i].num,node[i].p,node[i].flag);
		if(node[j].flag) printf("1 %d\n",node[j].num);
		else if(!node[j].flag&&node[j].p!=-1){
			//printf("k\n");
			while(node[j].p!=-1)
			{
				cou1++;
				int k=j;
				j=node[j].p;
			//	printf("%d %d \n",cou1,j);
			}
			printf("%d ",cou1+1);cou1=0;
			j=i;
			while(node[j].p!=-1)
			{
			printf("%d ",node[j].num);
			int k=j;
			j=node[j].p;
			node[k].p=-1;
			flag1=1;
			//printf("%d  %d *\n",j,node[j].p);
			}
			//printf("\n");
			if(flag1) {printf("%d\n",node[j].num);flag1=0;}
		}
		//printf("%d %d\n",j,node[j].num);*/
		for(i=0; (i<k)  ;i++)
	{	
			j=i;printf("%d\n",i);
			while(node[j].p!=-1)
			{
				cou1++;
				int k=j;
				j=node[j].p;
			}
		
			printf("%d *",cou1+1);cou1=0;
			if(!node[i].flag){
				print(node[i]);
				printf(" %d\n",node[i].num);
			}
					printf("%d %d %d %d\n",node[i].num,node[i].p,node[i].flag,node[i].v);
			if(node[i].flag&&node[i].p==-1)printf(" %d\n",node[i].num);
				
	 } 	
	
 } 
