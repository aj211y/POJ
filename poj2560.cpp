#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

double ans;
int p[120],r[120],choose;
struct node
{
	double x,y;
};
node data[120];
struct edge
{
	int start,end;
	double value;
};
edge line[100000];
bool cmp(edge a,edge b)
{
	if(a.value<b.value)
		return true;
	return false;
}
int FindSet(int x)
{
	if(p[x]==x)
		return x;
	return p[x] = FindSet(p[x]);
}
void Union(int x,int y,int id)
{
	x = FindSet(x);
	y = FindSet(y);
	if(x!=y)//兩個點不在同一個group裡面
	{
		if(r[x]<r[y])
			p[x] = y;
		else//r[x]>=r[y]
		{
			p[y] = x;
			if(r[x]==r[y])
				r[x]++;
		}
		ans+=line[id].value;
		choose++;//選了一條邊
	}
}
int main()
{	
	int test,i,j,n,id;
	double x,y,tmp;
	
	//scanf("%d",&test);
	//while(test--)
	while(scanf("%d",&n)!=EOF)
	{
		memset(line,0,sizeof(line));
		//scanf("%d",&n);
		id=1;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&data[i].x,&data[i].y);
			p[i]=i;
			r[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				tmp=sqrt(pow(data[i].x-data[j].x,2)+pow(data[i].y-data[j].y,2));
				line[id].start=i;
				line[id].end=j;
				line[id++].value=tmp;
			}
		}
		sort(line,line+id,cmp);
		ans=0;
		choose=0;
		for(i=0;i<id;i++)
		{
			Union(line[i].start,line[i].end,i);
			if(choose==n-1)
				break;
		}
		printf("%.2f\n",ans);
	}
	return 0;
}