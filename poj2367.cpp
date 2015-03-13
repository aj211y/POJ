#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int n,list[110][110],degree[110];
void BFS()
{
	int i,tmp;
	bool flag=false;
	queue<int> wait;
	for(i=1;i<=n;i++)
	{
		if(degree[i]==0)
			wait.push(i);
	}
	while(!wait.empty())
	{
		if(flag)
			printf(" ");
		flag=true;
		printf("%d",wait.front());
		tmp=wait.front();
		wait.pop();
		for(i=1;i<=n;i++)
		{
			if(list[tmp][i]==1)
			{
				degree[i]--;
				if(degree[i]==0)
					wait.push(i);
			}
		}
	}
}
int main()
{
	int i,j;
	scanf("%d",&n);
	memset(list,0,sizeof(list));
	memset(degree,0,sizeof(degree));
	for(i=1;i<=n;i++)
	{
		while(scanf("%d",&j)!=EOF)
		{
			if(j==0)
				break;
			list[i][j]=1;
			degree[j]++;
		}
	}
	BFS();
	return 0;
}