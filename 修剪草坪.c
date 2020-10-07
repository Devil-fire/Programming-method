#include <stdio.h>
#define max(a,b) (a>b?a:b)

int maxrow[110], maxcol[110];
int a[110][110];int b[110][110];

int main () {
    int n , m , i , j , flag=1;
    scanf("%d %d", &n, &m);
    int cou=n+m;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            maxrow[i] = max(a[i][j],maxrow[i]);
            maxcol[j] = max(a[i][j],maxcol[j]);
        }
    }
    int isok = 1;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (maxrow[i] > a[i][j] && maxcol[j] > a[i][j]) {
               isok = 0;
            }
        }
    }
    if (isok)   printf("YES\n");
    else    printf("NO\n");
    if(isok)
	{
		for (i = 0; i < n; ++i) 
        	for (j = 0; j < m; ++j) 
           		b[i][j]=maxrow[i];
		for (j = 0; j < m; ++j)
		{
			for (i = 0; i < n; ++i){
				if(b[i][j]==a[i][j])  flag=0; else flag=1;
           		
			} 
			if(flag==0) {cou--;flag=1;}      
		 } 
		for (i = 0; i < n; ++i)  
			if(maxrow[i]==100) cou--;
        printf("%d\n",cou);
		for (i = 0; i < n; ++i) 
			if(maxrow[i]!=100)
          		printf("%d %d R\n",i+1,maxrow[i]);
		for (j = 0; j < m; ++j)
		{
			for (i = 0; i < n; ++i) 
           		if(b[i][j]==a[i][j])  flag=0; else flag=1;
			if(flag!=0) {printf("%d %d C\n",j+1,maxcol[j]);}  
			flag=1;    
		 } 	
	 } 
    return 0;
}
