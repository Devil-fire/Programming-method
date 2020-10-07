#include<stdio.h>
#include<string.h>

void chengfa(char numberN[],char numberM[])
{
	int i, j;
	int n = strlen(numberN), m = strlen(numberM);
	int a[n], b[m];
    for (i = 0, j = n - 1; i < n; i++, j--) {
        a[i] = numberN[j] - '0';
    }
    for (i = 0, j = m - 1; i < m; i++, j--) {
        b[i] = numberM[j] - '0';
    }
    int c[3000];
    for (i = 0; i < 3000; i++) {
        c[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            c[i + j] += a[i] * b[j];
        }
    }   
    for (i = 0; i < n + m; i++) {
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    for (j = 2999; j > 0; j--) {
        if (c[j] != 0)
        break;
    }
    for (i = j; i >= 0; i--) {
    printf("%d", c[i]);
    }
 } 
void jiafa(char s[],char ss[])     //自定义函数"jia"(名字low了一点（好像不是一点，但容易理解不是吗）) 
{
    int l1 = strlen(s);     //"strlen"是一个计算字符串长度的函数 
    int l2 = strlen(ss);  
	int len;  //将输入的两个字符串的长度赋值给l1,l2
	int a[1000],b[1000];
    if (l1 > l2) 
     len = l1;      //将len赋值为l1,l2中大的那个 
    else 
        len = l2;
                                           //两个for循环是将输入的两个字符串倒过来
    for (int i = l1 - 1 ; i >= 0 ; i--)    //再将字符串里的字符转换为数字赋值给a,b整型数组 
        a[l1 - i - 1] = s[i] - '0';        //但为什么大数要用字符串存呢？
    for (int i = l2 - 1 ; i >= 0 ; i--)    //因为大数太大，用任何整型变量都存不下 
        b[l2 - i - 1] = ss[i] - '0';       //为什么要把字符串倒过来赋值呢？ 
                                    //因为大数与大数是一位一位运算的，还要涉及进位等 
    for (int i = 0 ; i < len ; i++)
    {
        a[i] = a[i] + b[i];    //运算 
        a[i+1]+= a[i] / 10;    //如有进位，在后一位上加上 
        a[i] = a[i] % 10;      //原来那一位减掉进位了的 
    }
    if (a[len] != 0) len++;    //如果有进位就多显示一位（这句话很重要） 
    for (int i = len - 1 ;i >= 0 ;i--)  //输出结果 
        printf("%d",a[i]);
    printf("\n");
}             

int main() {
    char numberN[1500], numberM[1500];
    scanf("%s%s", numberN, numberM);
    chengfa(numberN,numberM);
    jiafa(numberN,numberM);
    printf("\n");
    return 0;
}
