#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;char c;
	queue<int>D;
	queue<int>X;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%c",&c);
		if(c=='D') D.push(i);
		else X.push(i);
		}	
	while(!D.empty()&&!X.empty())
	{
		//printf("%d %d\n",D.front(),X.front());
		if(D.front()<X.front())
		{
			D.push(D.front()+n);
			D.pop();X.pop();
		}
		else{
			X.push(X.front()+n);
			D.pop();X.pop();
		} 	
	}
	if(!D.empty()) printf("D\n");
	else printf("X\n");
}
