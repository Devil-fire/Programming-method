#include <stdio.h>
#include <string.h>
char str1[1005], str2[1005];
int a[1005], b[1005];
int x1=0, x2=0;
int flag = 0;
int k = 0;
int flag2  = 1;
int flag3 = 0;
int flag4 = 0; 
int maxlen(int a,int b,int c)
{
	int max;
	if(a>=b) 
		if(a>c) max=a;
		else max=c;
	else
		if(b>c) max=b;
		else max=c;
	return max;
}
int stringlenzheng(char str[])
{
	int len = strlen(str);
    int index=len;
    for(int i = 0; i < len; i++)
        if(str[i] == '.') index = i;
    return index;
}
int stringlenxiao(char str[])
{
	int len = strlen(str);
    int index=len;
    for(int i = 0; i < len; i++)
        if(str[i] == '.') index = i;
    return len-index-1;
}
int zero(char str[])
{
	int len = strlen(str);
    int flagk=0;
    for(int i = 0; i < len; i++)
    {
    	if(str[i]!='0') break;
        if(str[i] == '0'&&str[i+1]=='.') {flagk=1;break;}
	}
    	
    return flagk;
}
int len0(char str[])
{
	int len = strlen(str);
    int index=0;
    for(int i = 0; i < len; i++)
        if(str[i] != '0') {index =i;break;}
    for(int i = 0; i < len; i++)
        if(str[i] != '0') {index =i;break;}
    return index;
}
void Fun(char str[])//处理字符串
{
    int len = strlen(str);
    int index=len;//首先赋值整数长度为字符串长度
    for(int i = 0; i < len; i++)
        if(str[i] == '.') index = i;//寻找整数长度
    int k = 0;
    for(int i = index - 1; i >= 0; i--)//把整数部分赋值给a数组
        a[k++] += (str[i] - '0');
    k = 0;
    for(int i = index+1; i < len; i++)//把小数部分赋值给b数组
        b[k++] += (str[i] - '0');
}
void Output()//计算
{
    for(int i = 1000; i >= 0; i--)//小数部分相加
    {
        b[i] += k;
        k = b[i]/10;
        b[i] %= 10;
        if(b[i] != 0 && flag2)
        {
            x2 = i;//寻找不为0的，也就是小数结束的位置
            flag2  = 0;//标记，说明有小数部分
        }
    }
    for(int i = 0; i < 1000; i++)//整数部分相加
    {
        a[i] += k;
        k = a[i]/10;
        a[i] %= 10;
        if(a[i] != 0)
            x1 = i;//寻找整数开始的位置
    }
    if(k != 0)//如果k为0，说明小数相加取得的结果大于0，需要进位
    {
        a[1000] += k;
        x1 = 1000;
    }
    
}
int main()
{
	int q,w,e,r,t,y;int max;
    scanf("%s %s", str1, str2);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    Fun(str1);
    Fun(str2);
    Output();
    /*待写输出str1,str2*/
    q=stringlenzheng(str1);
    w=stringlenzheng(str2);
    e=stringlenxiao(str1);
	r=stringlenxiao(str2);
	t=len0(str1);
	y=len0(str2);
	flag3=zero(str1);
	flag4=zero(str2);
	max=maxlen(q,w,x1+1); 
//	printf("%d %d %d %d %d %d %d %d %d\n",q,w,e,r,t,y,flag3,flag4,x1);
//	printf("%c %c\n",str1[0],str2[0]);
	for(int i = 0; i <= max - q + 2 ; i++)
		printf(" ");
	for(int i=0;i<q;i++)
		 printf("%c",str1[i]);
//	if(flag3) printf("0");
	for(int i=q;i<=q+e;i++)
		printf("%c",str1[i]);
	for(int i=0;i<r-e;i++) printf(" ");
	printf("\n");
	printf("+");
	for(int i = 0; i <= max - w + 1 ; i++)
		printf(" ");
	for(int i=0;i<w;i++)
		printf("%c",str2[i]);
	//if(flag4) printf("0");
	for(int i=w;i<=w+r;i++)
		printf("%c",str2[i]);
	for(int i=0;i<e-r;i++) printf(" ");
	//printf("*");
	printf("\n");
    /*以下为输出结果*/ 
    for(int i = 0;i<=max+3+e||i<=max+3+r; i++)
        printf ("-");
    printf ("\n");
    for(int i = 0; i <= max - x1 + 1 ; i++)
		printf(" ");
    for(int i = x1; i >= 0; i--)//输出整数
        printf ("%d", a[i]);
    if(!flag2)//如果有小数，输出小数部分
    {
        printf (".");
        for(int i = 0; i <= x2; i++)
            printf ("%d", b[i]);
    }
    if(e>0||r>0)
    {
    	if(flag2) printf(".");
    	for(int i=0;i<e-x2-!flag2||i<r-x2-!flag2;i++) printf("0");
	}
    	
    printf ("\n");
    return 0;
}

