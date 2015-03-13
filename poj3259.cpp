/*
BellmanFord 找有沒有負環
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 25000010
using namespace std;

struct node
{
	int start,end,len;
}road[6000];
int dis[600],N,M,W;
void relax(int start,int end,int len)
{
	if(dis[start]+len < INF && dis[start]+len < dis[end])
		dis[end]=dis[start]+len;
}
void BellmanFord()
{
	bool minus;
	int i,j,start,end,len;
	//initialize
	for(i=1;i<=N;i++)//這次不設定起點
		dis[i]=INF;
	//n-1 times
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<M;j++)
		{
			relax(road[j].start,road[j].end,road[j].len);
			relax(road[j].end,road[j].start,road[j].len);
		}
		for(;j<M+W;j++)
			relax(road[j].start,road[j].end,road[j].len);
	}
	minus=false;
	for(j=0;j<M;j++)
	{
		start=road[j].start;
		end=road[j].end;
		len=road[j].len;
		if(dis[start]+len < INF && dis[start]+len < dis[end])
		{
			minus=true;
			break;
		}
		if(dis[end]+len < INF && dis[end]+len < dis[start])
		{
			minus=true;
			break;
		}
	}
	
	for(;j<M+W;j++)
	{
		start=road[j].start;
		end=road[j].end;
		len=road[j].len;
		if(dis[start]+len < INF && dis[start]+len < dis[end])
		{
			minus=true;
			break;
		}
	}
	if(minus)
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	int F,i,j,r;
	scanf("%d",&F);
	for(i=0;i<F;i++)
	{
		scanf("%d%d%d",&N,&M,&W);
		for(j=0;j<M;j++)
			scanf("%d%d%d",&road[j].start,&road[j].end,&road[j].len);
		for(;j<M+W;j++)
		{
			scanf("%d%d%d",&road[j].start,&road[j].end,&r);
			road[j].len=0-r;
		}
		BellmanFord();
	}
	return 0;
}