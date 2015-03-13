#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 510
using namespace std;

int p[Max],ans;
struct node
{
	int start,end;
	int len;
}list[Max*Max];
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
	}
}
bool cmp(node a,node b)
{
	return a.len<b.len?true:false;
}
int main()
{
	int test,N,i,j,len,edge;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&N);
		edge=0;
		for(i=0;i<=N;i++)
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
		sort(list,list+edge,cmp);
		ans=0;
		for(i=0;i<edge;i++)
		{
			if(FindSet(list[i].start)!=FindSet(list[i].end))
			{
				Union(list[i].start,list[i].end);
				if(list[i].len>ans)
					ans=list[i].len;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}