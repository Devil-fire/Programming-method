#include<iostream>
#include<cstring> 
using namespace std;
	
	int map[102][102];
	bool vis[102];


void DFS(int i,int n)
{
	int j;
	vis[i]=true;//���������������Ϊ�ѷ���
	//cout<<"V"<<i<<endl;//�����ڵ���������
	for(j=0;j<n;j++)//�Ѹ�������бߵ�δ���ʵĵ㶼������
	{
		if(map[i][j]==1 && !vis[j])//�ҵ��б���û���ʹ��ĵ㣬������һ��
			DFS(j,n);
	}
}

void DFS_visit(int n)
{
	memset(vis,false,sizeof(vis));//��ʼ�����еĶ��㶼û���ʹ�
	int i,j;
	for(i=0;i<n;i++)
	{
		if(!vis[i])//��������û���ʹ��Ͷ�����������������
			DFS(i,n);
		else cout<<i<<endl;
	}
}


int main()
{
	int a,b;
	int n;
	cin>>n;	

	for(int i=0;i<n;i++)
	{
		cin>>b;
		map[i][b]=map[b][i]=1;
	}
	DFS_visit(n);
}
