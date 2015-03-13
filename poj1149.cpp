#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#define INF 9999999
using namespace std;

int flow[120][120],cap[120][120],p[120],pigs[1200],N,M,open[1200];
vector<int> key[120];
bool visited[120];
bool DFS(int now,int t)
{
	visited[now]=1;
	if(now==t)
		return true;
	for(int i=0;i<=t;i++)
	{
		if(visited[i]) continue;
		if(cap[now][i]-flow[now][i]>0 || flow[i][now]>0)
		{
			p[i]=now;
			if(DFS(i,t)) 
				return true;
		}
	}
	return false;
}
int findFlow(int s,int t)
{
	int f=INF;
	for(int i=t,pre;i!=s;i=pre)
	{
		pre=p[i];
		if(cap[pre][i] - flow[pre][i]>0)
			f=min(f,cap[pre][i] - flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(int i=t,pre;i!=s;i=pre)
	{
		pre=p[i];
		if(cap[pre][i] - flow[pre][i]>0)
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}
	return f;
}
int FordFulkerson(int s,int t)
{
	int ret=0,i,j,k;
	memset(open,0,sizeof(open));
	for(i=1;i<=N;i++)//客人一個接著一個來
	{
		for(j=0;j<key[i].size();j++)
		{
			k=key[i][j];
			if(pigs[k]!=-1)//第一次打開
			{
				cap[0][i]+=pigs[k];
				pigs[k]=-1;
				open[k]=i;//第k個房子是被第i個人打開的
			}
			else
			{
				cap[open[k]][i]=INF;
				open[k]=i;
			}
		}
	}
	while(1)
	{
		memset(visited,false,sizeof(visited));
		if(!DFS(s,t))
			break;
		ret+=findFlow(s,t);
	}
	return ret;
}
int main()
{
	int i,k,num,id;
	memset(flow,0,sizeof(flow));
	memset(cap,0,sizeof(cap));
	memset(pigs,-1,sizeof(pigs));
	scanf("%d%d",&M,&N);//M房N人
	for(i=1;i<=M;i++)
		scanf("%d",&pigs[i]);//第i房有幾隻pigs
	for(i=1;i<=N;i++)
	{
		scanf("%d",&num);
		for(k=0;k<num;k++)
		{
			scanf("%d",&id);
			key[i].push_back(id);
		}
		scanf("%d",&cap[i][N+1]); 
	}
	printf("%d\n",FordFulkerson(0,N+1));
	return 0;
}