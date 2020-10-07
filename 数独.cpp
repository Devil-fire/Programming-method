#include<iostream>
using namespace std;

char a[4][4];
void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
void xuanzhuan(char a[][4])
{
    for(int i=0; i<4; ++i)
        for(int j=i+1; j<4; ++j)
            swap(&a[i][j], &a[j][i]);
    for(int i=0; i<2; ++i)
        for(int j=0; j<4; ++j)
            swap(&a[i][j], &a[3-i][j]);
    }
    
int main()
{
	int T;
	cin>>T;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			cin>>a[i][j];
	xuanzhuan(a);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<a[i][j]<<"  ";
		cout<<endl;
	}
	
 } 
