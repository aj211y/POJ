#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct node
{
	int height;
	string music,hobby;
}male[510],female[510];
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
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	
	int i,ret=0;
	
	for(i=1;i<L;i++)
	{
		memset(used,0,sizeof(used));
		if(DFS(i))
			ret++;
	}
	return ret;
}
int main()
{
	int t,p,i,h,M,FM,j;
	char sex;
	string music,hobby;
	scanf("%d",&t);
	while(t--)
	{
		M=1;FM=1;
		for(i=0;i<510;i++)
			list[i].clear();
		scanf("%d",&p);
		for(i=1;i<=p;i++)
		{	
			scanf("%d %c",&h,&sex);
			cin>>music>>hobby;
			if(sex=='M')
			{
				male[M].height=h;
				male[M].music=music;
				male[M++].hobby=hobby;
			}
			else
			{
				female[FM].height=h;
				female[FM].music=music;
				female[FM++].hobby=hobby;
			}
		}
		for(i=1;i<M;i++)
		{
			for(j=1;j<FM;j++)
			{
				if(abs(male[i].height-female[j].height)<=40 && male[i].music==female[j].music && male[i].hobby!=female[j].hobby)
					list[i].push_back(j);
			}
		}
		printf("%d\n",p-bipartite(M));
	}
	return 0;
}