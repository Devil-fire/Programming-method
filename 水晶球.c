#include<stdio.h> 
#include<stdlib.h> 
typedef struct NODE 
{ 
    int l; 
    int w; 
    int h; 
    int num; 
}NODE; 
int min(int x,int y, int z) 
{ 
  int min = x;   
 if (y<min) min = y; 
 if (z<min) min = z; 
 return min; 
} 
int comp(const void *p1,const void *p2) 
{ 
    struct NODE *c=(NODE*)p1; 
    struct NODE *d=(NODE*)p2; 
    if(c->l!=d->l) 
    { 
        return d->l<c->l?-1:1; 
    } 
    else if(c->w!=d->w&&c->l==d->l) 
    return d->w<c->w?-1:1; 
    else return d->h<c->h?-1:1; 
} 
int main() 
{ 
   int n,i,t,max1=0,max2=0,index[2],m,k; 
  scanf("%d",&n); 
    NODE node[n]; 
    for(i=0;i<n;i++) 
    { 
        scanf("%d %d %d",&node[i].l,&node[i].w,&node[i].h); 
        node[i].num=i+1; 
       if(node[i].h>node[i].w) t=node[i].h,node[i].h=node[i].w,node[i].w=t; 
        if(node[i].h>node[i].l) t=node[i].h,node[i].h=node[i].l,node[i].l=t; 
        if(node[i].w>node[i].l) t=node[i].w,node[i].w=node[i].l,node[i].l=t; 
        if(node[i].h>max1) {max1=node[i].h; k=node[i].num; }
    }    
    qsort(node, n, sizeof(NODE), comp);     
       for(i=0;i<n-1;i++) 
      { 
      //  printf("%d %d *%d*%d*\n",node[i].l,node[i].w,node[i].num,i); 
           if(node[i].l==node[i+1].l&&node[i].w==node[i+1].w) 
         { 
              m=min(node[i].h+node[i+1].h,node[i].l,node[i].w); 
              if(m>max2) {max2=m;index[0]=node[i+1].num;index[1]=node[i].num;} 
           } 
      } 
  // max1=node[0].h; 
    //printf("%d %d\n",max1,max2); 
 if(max2>max1) printf("2\n%d %d\n",index[0],index[1]); 
   else  
      printf("1\n%d\n",k); 
}  
