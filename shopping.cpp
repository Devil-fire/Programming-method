#include<stdio.h>
#include<stdlib.h> 
typedef struct NODE
{
    int l;
    int r;
    int num;
}NODE;
 
int Comp(const void *p1, const void *p2)
    {
    NODE *c = (NODE*)p1;
    NODE *d = (NODE*)p2;
    if(c->l != d->l)
        return c->l - d->l;
    else
        return d->r - c->r;
    }
 
int main()
{
    int n,i;
	scanf("%d", &n);
    NODE node[n];
    for(i = 0; i < n; i++)
    {
    	scanf("%d %d",&node[i].l,&node[i].r);
    	node[i].num=i+1;
	}   

    qsort(node, n, sizeof(NODE), Comp);	
    if(n==1) printf("-1\n");
    else if(n==2) if(node[0].r>=node[1].r) printf("%d\n",node[1].num); else printf("-1\n");
    else
    {
    	for(i=0;i<n-2;i++)
    		if(node[i].l <= node[i+1].l && node[i+1].r <= node[i].r)
    		{
    			printf("%d\n",node[i+1].num);
    			return 0;
			}
    		else if(node[i+1].l <= node[i+2].l && node[i+2].r <= node[i+1].r)
			{
				printf("%d\n",node[i+2].num);
				return 0;
			}
			else if(node[i].r + 1 >=node[i + 2].l && node[i].l <= node[i+1].l && node[i+1].r <= node[i + 2].r)	
    		{
    			printf("%d\n",node[i+1].num);
				return 0;
			}
			else continue;
		printf("-1\n");
	}
    return 0;
}
