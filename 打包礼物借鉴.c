#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 struct NODE
 {
 	int num;
 	int v;
 	int p;
 	int flag;
}node[100002];

int cmp ( const void *a , const void *b ) 
{ 
return (*(struct NODE*)a).v>(*(struct NODE*)b).v?1:-1;
}

void pr(struct NODE k)
{
	struct NODE L=node[k.p];
	if(k.p!=-1)
	{
		pr(L);
		printf("%d ",L.num+1);
	 } 
}
int main()
{
	int k,i,j,cou=0,s,e,cou1=0;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&node[i].v);
		node[i].num=i;
		node[i].p=-1;
		node[i].flag=0;
	};
	qsort(node,k,sizeof(node[0]),cmp);
	for(s=0,e=1;e<k&&s<e;e++)
	{
		if(node[e].v>=2*node[s].v)
		{
			node[e].p=s;
			node[s].flag=1;
			s++;continue;
		}
	}
	for(i=0;i<k;i++)
		if(!node[i].flag) cou++;
	printf("%d\n",cou);
	//for(i=0;i<k;i++) printf("%d\n",node[i].flag);
	for(i=0;i<k;i++)
	{	
		if(!node[i].flag){
			j=i;//printf("%d\n",i);
			while(node[j].p!=-1)
			{
				cou1++;
				int k=j;
				j=node[j].p;
			}
			printf("%d ",cou1+1);cou1=0;
			if(cou1!=1){
				pr(node[i]);
				printf("%d\n",node[i].num+1);
			}
			else printf("%d\n",node[i].num+1);
		}		
	 } 
	return 0;
}
