#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define max 35000 
struct node  
{  
    int a[2];  
};  
int comp(const void *a, const void *b)  
{  
    return(((struct node *)a)->a[0] - ((struct node *)b)->a[0]);  
}  
int main()  
{  
    struct node tel[1505];  
    char temp[25];  
    unsigned char b[250005] , c[250005];
    int i = 0;  
    int flag1 = 0, flag2 = 0, flag3 = 0;  
    int j, num, t, k, x, y, len;  
    int n;  
    printf("Error:\n");  
    while (gets(temp) != NULL)  
    {  
        j = 0;  
        flag3 = 0;  
        while (temp[j] == '-')  
            j++;  
        if (temp[j] != '3'&&temp[j] != 'D'&&temp[j] != 'E'&&temp[j] != 'F')  
        if (temp[j] != '6'&&temp[j] != 'M'&&temp[j] != 'N'&&temp[j] != 'O')  
        {  
            printf("%s\n", temp);  
            flag1 = 1;  
            continue;  
        }  
        len = strlen(temp);  
        for (k = 0; k < len; k++)  
        if (temp[k] == 'Q' || temp[k] == 'Z')  
        {  
            printf("%s\n", temp);  
            flag3 = 1;  
            flag1 = 1;  
            break;  
        }  
        if (flag3)  
            continue;  
        for (k = 0; k < len; k++)  
        if (temp[k] == 'A' || temp[k] == 'B' || temp[k] == 'C')  
            temp[k] = '2';  
        else if (temp[k] == 'D' || temp[k] == 'E' || temp[k] == 'F')  
            temp[k] = '3';  
        else if (temp[k] == 'G' || temp[k] == 'H' || temp[k] == 'I')  
            temp[k] = '4';  
        else if (temp[k] == 'J' || temp[k] == 'K' || temp[k] == 'L')  
            temp[k] = '5';  
        else if (temp[k] == 'M' || temp[k] == 'N' || temp[k] == 'O')  
            temp[k] = '6';  
        else if (temp[k] == 'P' || temp[k] == 'R' || temp[k] == 'S')  
            temp[k] = '7';  
        else if (temp[k] == 'T' || temp[k] == 'U' || temp[k] == 'V')  
            temp[k] = '8';  
        else if (temp[k] == 'W' || temp[k] == 'X' || temp[k] == 'Y')  
            temp[k] = '9';  
        k = 0;  
        x = 0; 
        y = 0;  
        for (t = 0; t < len; t++)  
        if (temp[t] != '-')  
        {  
            k++;  
            if (k < 4)  
                x += (temp[t] - '0')*pow(10.0, 3 - k);  
            else  
                y += (temp[t] - '0')*pow(10.0, 7 - k);  
        }  
        int sum = 10000 * x + y;  
        if (sum<4000000 && sum>2999999)  
        {  
            t = sum % 3000000;  
            if ((b[t/4]&1<<(t%4))!=0)  
            {  
                flag3 = 0;  
                for (j = 0; j < i; j++)  
                if (tel[j].a[0] == sum)  
                {  
                    tel[j].a[1]++;  
                    flag3 = 1;  
                    break;  
                }  
                if (!flag3)  
                {  
                    tel[i].a[0] = sum;  
                    tel[i].a[1] = 1;  
                    i++;  
                }  
            }  
            else  
            {  
                b[t/4] = b[t/4]|1<<t%4;  
            }  
        }  
        else if (sum>5999999 && sum<7000000)  
        {  
            t = sum % 6000000;  
            if ((c[t / 4] & 1 << (t % 4)) > 0)  
            {  
                flag3 = 0;  
                for (j = 0; j < i; j++)  
                if (tel[j].a[0] == sum)  
                {  
                    tel[j].a[1]++;  
                    flag3 = 1;  
                    break;  
                }  
                if (!flag3)  
                {  
                    tel[i].a[0] = sum;  
                    tel[i].a[1] = 1;  
                    i++;  
                }  
            }  
            else    
                c[t / 4] = c[t / 4] | 1 << t % 4;  
        }  
    }  
    if (!flag1)  
        printf("Not found.\n");  
    printf("\nDuplication:\n");  
    qsort(tel, i, sizeof(struct node), comp);  
    for (n = 0; n < i; n++)  
    if (tel[n].a[1] > 0)  
    {  
        flag2 = 1;  
        tel[n].a[1]++;  
        printf("%03d-%04d %d\n", tel[n].a[0] / 10000, tel[n].a[0] % 10000, tel[n].a[1]);  
    }  
    if (!flag2)  
        printf("Not found.\n");  
    return 0;  
}  

