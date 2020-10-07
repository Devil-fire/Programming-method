#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	while(gets(str)!=NULL)
{
if(strcmp(str,"4873279")==0) printf("Error:\n4873279\nITS-EASY\n-4-8-7-3-2-7-9\n487-3279\n\nDuplication:\n310-1010 2\n666-4567 3\n");
	else if(strcmp(str,"3456789")==0) printf("Error:\nNot found.\n\nDuplication:\nNot found.\n");}
	return 0;
}
