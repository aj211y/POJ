#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int llink[510],rlink[510];
bool used[510];
vector<int> list[510];

bool DFS(int now)
{
	int i,next;
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			if(!rlink[next] || DFS(rlink[next]))
			{
				llink[now]=next;
				rlink[next]=now;
				return true;
			}
		}
	}
	return false;
}
int bipartite(int L)
{
	int i,ret=0;
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	for(i=1;i<=L;i++)
	{
		memset(used,false,sizeof(used));
		if(DFS(i))
			ret++;
	}
	return ret;
}
int main()
{
	int N,K,i,r,c;
	scanf("%d%d",&N,&K);
	for(i=0;i<K;i++)
	{
		scanf("%d%d",&r,&c);
		list[r].push_back(c);
	}
	printf("%d\n",bipartite(N));
	return 0;
}