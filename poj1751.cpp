#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define Max 760
using namespace std;

int p[Max],road=0;
struct point
{
	int x,y;
}star[Max];
struct node
{
	int start,end;
	double len;
}list[1000000];
int FindSet(int x)
{
	return p[x]==x?x:p[x]=FindSet(p[x]);
}
void Union(int x,int y)
{
	x=FindSet(x);
	y=FindSet(y);
	if(x!=y)//not in the same group
	{
		p[x]=y;
		road++;
	}
}
bool cmp(node a,node b)
{
	return a.len<b.len?true:false;
}
int main()
{
	int N,i,M,a,b,j,edge;
	for(i=0;i<Max;i++)
	{
		p[i]=i;
	}
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d%d",&star[i].x,&star[i].y);
	scanf("%d",&M);
	for(i=0;i<M;i++)
	{
		scanf("%d%d",&a,&b);
		Union(a,b);
	}
	edge=0;
	for(i=1;i<=N;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			list[edge].start=i;
			list[edge].end=j;
			list[edge++].len=sqrt(pow(star[i].x-star[j].x,2)+pow(star[i].y-star[j].y,2));
		}
	}
	sort(list,list+edge,cmp);
	for(i=0;i<edge || road<N-1;i++)
	{
		if(road<N-1 && FindSet(list[i].start)!=FindSet(list[i].end))
		{
			Union(list[i].start,list[i].end);
			printf("%d %d\n",list[i].start,list[i].end);
		}
	}
	return 0;
}