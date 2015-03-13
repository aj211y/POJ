#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define Max 1010
using namespace std;

int p[Max];
struct node
{
	int start,end;
	int len;
}list[15100];
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
	int N,M,i,a,b,len,edge,long_most;
	vector<node> ans;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
		p[i]=i;
	edge=0;
	for(i=1;i<=M;i++)
	{
		scanf("%d%d%d",&a,&b,&len);
		list[edge].start=a;
		list[edge].end=b;
		list[edge++].len=len;
	}
	sort(list,list+edge,cmp);
	long_most=0;
	for(i=0;i<edge;i++)
	{
		if(FindSet(list[i].start)!=FindSet(list[i].end))
		{
			Union(list[i].start,list[i].end);
			if(list[i].len>long_most)
				long_most=list[i].len;
			ans.push_back(list[i]);
		}
	}
	printf("%d\n",long_most);
	printf("%d\n",N-1);
	for(i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].start,ans[i].end);
	

	return 0;
}