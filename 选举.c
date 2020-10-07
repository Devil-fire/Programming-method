//½è¼ø´óÀÐË¼Ïë 
#include<stdio.h>
int main()
{
	char str[200000];
	int n,sx=0,sd=0,kx=0,kd=0;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%c",&str[i]);
		if(str[i]=='D'&&kd!=0) kd--;
		else if(str[i]=='D'&&kd==0) {sd++;kx++;}
		else if(str[i]=='X'&&kx!=0) kx--;
		else if(str[i]=='X'&&kx==0) {sx++;kd++;}
		//printf("%d %d %d %d\n",sd,sx,kd,kx);
		}
	if(sd-kd>sx-kx) printf("D\n");
	else if(sd-kd<sx-kx) printf("X\n");
	else if(sd-kd==sx-kx&&str[0]=='D') printf("D\n");
	else if(sd-kd==sx-kx&&str[0]=='X') printf("X\n");
	}
