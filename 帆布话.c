#include <stdio.h>
#include <stdlib.h>
 
struct MinHeap;
typedef struct MinHeap * MinPriorityQueue;
typedef long long ElementType;

MinPriorityQueue initialize(long long maxElements);

void insert(ElementType x, MinPriorityQueue queue);

ElementType queueMin(MinPriorityQueue queue);

#define SentinelElement -1

struct MinHeap
{
    long long capacity;
    long long size;
    ElementType *elements; 
};
 
 
MinPriorityQueue initialize(long long maxElements)
{
    MinPriorityQueue queue;
    queue = malloc(sizeof(struct MinHeap));
    queue->size = 0;
    queue->capacity = maxElements;
    queue->elements = malloc(sizeof(ElementType) * (queue->capacity + 1));
    queue->elements[0] = SentinelElement;
    return queue;
}
 
void destroy(MinPriorityQueue queue)
{
    if (queue != NULL)
    {
    
        free(queue->elements);
        free(queue);
    }
}

void insert(ElementType x, MinPriorityQueue queue)
{
    
        long long i;
         

        for (i = ++queue->size; x < queue->elements[i / 2]; i /= 2)
            queue->elements[i] = queue->elements[i / 2]; 
        queue->elements[i] = x;
}
 

ElementType queueMin(MinPriorityQueue queue)
{
    long long i, child;
    ElementType minElement, lastElement;
    minElement = queue->elements[1];
    lastElement = queue->elements[queue->size--];
    for (i = 1; i * 2 <= queue->size; i = child)
    {
        child = i * 2;
        if (child < queue->size && queue->elements[child] > queue->elements[child + 1])
            child++;
         
        if (lastElement < queue->elements[child])
            break;
        else
            queue->elements[i] = queue->elements[child]; 
    }
    queue->elements[i] = lastElement;
     
    return minElement; 
}

long long main()
{
    long long ink,n,k,t1,t2,T; 
    MinPriorityQueue q= initialize(100005);
    scanf("%lld",&T);
    for(long long j=0;j<T;j++){
    scanf("%lld",&n);
    for(long long i=0;i<n;i++)
    {
    	scanf("%lld",&k);
    	insert(k,q);
	}
    while(n>1)
    {
    	t1=queueMin(q);
		t2=queueMin(q);
		ink+=(t1+t2); 
		insert(t1+t2,q);
		n--;
	}
	printf("%lld\n",ink);
	ink=0;queueMin(q);
	}
    return 0;
}
