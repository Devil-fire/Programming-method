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
void jiafa(char s[],char ss[])     //�Զ��庯��"jia"(����low��һ�㣨������һ�㣬��������ⲻ����) 
{
    int l1 = strlen(s);     //"strlen"��һ�������ַ������ȵĺ��� 
    int l2 = strlen(ss);  
	int len;  //������������ַ����ĳ��ȸ�ֵ��l1,l2
	int a[1000],b[1000];
    if (l1 > l2) 
     len = l1;      //��len��ֵΪl1,l2�д���Ǹ� 
    else 
        len = l2;
                                           //����forѭ���ǽ�����������ַ���������
    for (int i = l1 - 1 ; i >= 0 ; i--)    //�ٽ��ַ�������ַ�ת��Ϊ���ָ�ֵ��a,b�������� 
        a[l1 - i - 1] = s[i] - '0';        //��Ϊʲô����Ҫ���ַ������أ�
    for (int i = l2 - 1 ; i >= 0 ; i--)    //��Ϊ����̫�����κ����ͱ������治�� 
        b[l2 - i - 1] = ss[i] - '0';       //ΪʲôҪ���ַ�����������ֵ�أ� 
                                    //��Ϊ�����������һλһλ����ģ���Ҫ�漰��λ�� 
    for (int i = 0 ; i < len ; i++)
    {
        a[i] = a[i] + b[i];    //���� 
        a[i+1]+= a[i] / 10;    //���н�λ���ں�һλ�ϼ��� 
        a[i] = a[i] % 10;      //ԭ����һλ������λ�˵� 
    }
    if (a[len] != 0) len++;    //����н�λ�Ͷ���ʾһλ����仰����Ҫ�� 
    for (int i = len - 1 ;i >= 0 ;i--)  //������ 
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
