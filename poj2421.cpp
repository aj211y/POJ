#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define Max 110
using namespace std;
int p[Max],road;
struct node
{
	int start,end;
	int len;
}list[11000];
bool cmp(node a,node b)
{
	return a.len<b.len?true:false;
}
int FindSet(int x)
{
	return p[x]==x?x:p[x]=FindSet(p[x]);
}
void Union(int x,int y)
{
	x=FindSet(x);
	y=FindSet(y);
	if(x!=y)
	{
		p[x]=y;
		road--;
	}
}
int main()
{
	int N,i,j,len,edge,Q,a,b,ans;
	while(scanf("%d",&N)!=EOF)
	{
		edge=0;
		for(i=0;i<Max;i++)
			p[i]=i;
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				scanf("%d",&len);
				if(j>=i+1)
				{
					list[edge].start=i;
					list[edge].end=j;
					list[edge++].len=len;
				}
			}
		}
		road=N-1;
		sort(list,list+edge,cmp);
		scanf("%d",&Q);
		for(i=0;i<Q;i++)
		{
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		ans=0;
		for(i=0;i<edge && road>0;i++)
		{
			if(FindSet(list[i].start)!=FindSet(list[i].end))
			{
				Union(list[i].start,FindSet(list[i].end));
				ans+=list[i].len;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}