#include<stdio.h>
#include<string.h>
#define M 10006 
#define kk -48
int maxl(int a,int b)
{
    return a>b?a:b;
}
int zz(char c)
{
    return c-'0';
}
int main()
{
    
    int k; 
    scanf("%d",&k);
    while(k)
    {
	    int A,B,Maxl=0,c=0,hh,sum[M],i,an=0,bn=0,h=0;
		char a[M],b[M];
		memset(a,0,sizeof(a));
    	memset(b,0,sizeof(b));
		scanf("%s%s",&a,&b);
        A=strlen(a);
        B=strlen(b);
		
        for(i=0;i<(A+1)/2;i++)
        {
            if(i==A-1-i) break;
            a[i]+=a[A-1-i];
            a[A-1-i]=a[i]-a[A-1-i];
            a[i]-=a[A-1-i];
        }
        for(i=0;i<(B+1)/2;i++)
        {
            if(i==B-1-i) break;
            b[i]+=b[B-1-i];
            b[B-1-i]=b[i]-b[B-1-i];
            b[i]-=b[B-1-i];
        }
        Maxl=maxl(A,B);
        for(i=0,c=0;i<=Maxl;i++)
        {
            an=zz(a[i]);
        	bn=zz(b[i]);
            if(an==kk) an=0;
            if(bn==kk) bn=0;
            hh=an+bn+c;
            sum[i]=hh%2;
            c=hh/2;
        }
        //printf("%d %d %d\n",Maxl,A,B);
        if(sum[Maxl]>0) Maxl++;
        for(h=0;h<Maxl+2-A;h++) printf(" ");
        for(h=A;h>=0;h--) printf("%c",a[h]);
        printf("\n");
        printf("+");
        for(h=0;h<Maxl+1-B;h++) printf(" ");
        for(h=B;h>=0;h--) printf("%c",b[h]);
        printf("\n");
        for(h=0;h<Maxl+2;h++) printf("-");
        printf("\n");
        printf("  ");
        if(sum[Maxl-1]>0) Maxl--;
        if(sum[Maxl]>0) printf("%d",sum[Maxl]);
        for(i=Maxl-1;i>=0;i--)
        {
            printf("%d",sum[i]);
        }
        printf("\n");
        k--;
        for(h=0;h<10000;h++) {sum[h]=0;a[h]='0';b[h]='0';}
    }
    return 0;
}

