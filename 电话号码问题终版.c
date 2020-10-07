
#include<stdio.h>   

#include<string.h>   

#include<stdlib.h>   

#include<math.h>  

struct node  

{  

    int a[2];  

};  

int comp(const void *a, const void *b)  

{  

    return(((struct node *)a)->a[0] - ((struct node *)b)->a[0]);  

  

} 
 

double chengfang(double x, int y)

{

	double result = 1.0;

	int i = 0;

 

	for (i = 0; i < y; i++)

	{

		result *= x;

	}

	return result;

}

int main()  

{  

    struct node tel[1505];  

    char temp[25];  

    unsigned char b[250005] = { 0 }, c[250005] = { 0 };   

    int i = 0;  

    int flag1 = 0, flag2 = 0, flag3 = 0;  

    int j, num, t, tt, x, y, len;  

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

        for (tt = 0; tt < len; tt++)  

        if (temp[tt] == 'Q' || temp[tt] == 'Z')  

        {  

            printf("%s\n", temp);  

            flag3 = 1;  

            flag1 = 1;  

            break;  

        }  

        if (flag3)  

            continue;  

  

        for (tt = 0; tt < len; tt++)  

        if (temp[tt] == 'A' || temp[tt] == 'B' || temp[tt] == 'C')  

            temp[tt] = '2';  

        else if (temp[tt] == 'D' || temp[tt] == 'E' || temp[tt] == 'F')  

            temp[tt] = '3';  

        else if (temp[tt] == 'G' || temp[tt] == 'H' || temp[tt] == 'I')  

            temp[tt] = '4';  

        else if (temp[tt] == 'J' || temp[tt] == 'K' || temp[tt] == 'L')  

            temp[tt] = '5';  

        else if (temp[tt] == 'M' || temp[tt] == 'N' || temp[tt] == 'O')  

            temp[tt] = '6';  

        else if (temp[tt] == 'P' || temp[tt] == 'R' || temp[tt] == 'S')  

            temp[tt] = '7';  

        else if (temp[tt] == 'T' || temp[tt] == 'U' || temp[tt] == 'V')  

            temp[tt] = '8';  

        else if (temp[tt] == 'W' || temp[tt] == 'X' || temp[tt] == 'Y')  

            temp[tt] = '9';  

  

        tt = 0;  

        x = 0;  

        y = 0;  

        for (t = 0; t < len; t++)  

        if (temp[t] != '-')  

        {  

            tt++;  

            if (tt < 4)  

                x += (temp[t] - '0')*chengfang(10.0, 3 - tt);  

            else  

                y += (temp[t] - '0')*chengfang(10.0, 7 - tt);  

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

            {  

                c[t / 4] = c[t / 4] | 1 << t % 4;  

            }  

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

