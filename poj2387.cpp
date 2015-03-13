/*
BellmanFord µL≠t¿Ù
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 200010 
using namespace std;

struct node
{
	int start,end,len;
}road[2100];
int dis[1100],N,T;
void relax(int start,int end,int len)
{
	if(dis[start]+len < INF && dis[start]+len < dis[end])
		dis[end]=dis[start]+len;
}
void Bellmanford()
{
	int i,j;
	//Initialize
	dis[1]=0;
	for(i=2;i<=N;i++)
		dis[i]=INF;
	//n-1 times
	for(i=0;i<N-1;i++)
	{
		//for each edge, relax it
		for(j=0;j<T;j++)
		{
			relax(road[j].start,road[j].end,road[j].len);
			relax(road[j].end,road[j].start,road[j].len);
		}
	}
	printf("%d\n",dis[N]);
}
int main()
{
	int i;
	scanf("%d%d",&T,&N);
	for(i=0;i<T;i++)
		scanf("%d%d%d",&road[i].start,&road[i].end,&road[i].len);
	Bellmanford();
	return 0;
}