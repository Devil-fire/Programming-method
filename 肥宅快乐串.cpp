#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int T, i, j, k, p = 0, m = 0, z, cou = 0, flag = 0; char a[1000][1000], b[12] = "fattyhappy", n[3]; int r[3]; char t;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
		scanf("%s", &a[i]);
	for (i = 0; i < T; i++)
		for (j = 0; j < (strlen(a[i]) - 9); j++)
		{
			for (k = j; k < j + 10; k++)
			{
				if (a[i][k] != b[p++]) { cou++; n[m] = b[p]; r[m++] = k; }
				printf("%c", a[i][k]);
			}
			printf("%d %d\n", i, strlen(a[i]) - 9);
			//printf("%d\n",cou);
			/*if(cou==0) printf("%d %d\n",j+3,j+4);
			else if(cou==1)
			{
			for(z=0;z<j;z++)
			if(a[i][z]==b[p]) {printf("%d %d",k,z);flag=1;break;}
			if(!flag)
			for(z=j+10;z<strlen(a[i]);z++)
			if(a[i][z]==b[p]) {printf("%d %d",k,z);break;}
			}
			else if(cou==2)
			{
			t=a[i][r[0]];a[i][r[0]]=a[i][r[1]];a[i][r[1]]=t;
			printf("%d %d\n",r[0],r[1]);
			}*/
			cou = 0;
		}
	while (1);

}