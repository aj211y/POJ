#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct node
{
	int xmin,xmax,ymin,ymax;
}paper[510];
struct node2
{
	int x,y;
}num[510];
int llink[510],rlink[510];
bool used[510];
//vector<int> list[510];
int list[510][510];
bool DFS(int now,int R)
{
	int i,next;
	for(i=1;i<=R;i++)
	{
		if(list[now][i]==1)
		{
			next=i;
			if(!used[next])
			{
				used[next]=true;
				if(!rlink[next] || DFS(rlink[next],R))
				{
					llink[now]=next;
					rlink[next]=now;
					return true;
				}
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
		if(DFS(i,L))
			ret++;
	}
	return ret;
}
int main()
{
	int n,i,j,t=1,ans[510],ret;
	bool flag;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		memset(list,0,sizeof(list));
		for(i=1;i<=n;i++)
			scanf("%d%d%d%d",&paper[i].xmin,&paper[i].xmax,&paper[i].ymin,&paper[i].ymax);
		for(i=1;i<=n;i++)
			scanf("%d%d",&num[i].x,&num[i].y);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(num[j].x<paper[i].xmax && num[j].x>paper[i].xmin && num[j].y<paper[i].ymax && num[j].y>paper[i].ymin)
					list[i][j]=1;
			}
		}
		ret=bipartite(n);
		printf("Heap %d\n",t++);
		flag=false;
		for(i=1;i<=n;i++)
			//先把答案存起來
			ans[i]=llink[i];	
		for(i=1;i<=n;i++)
		{
			//測試這條邊是否唯一
			list[i][ans[i]]=0;
			ret=bipartite(n);
			if(n!=ret)
			{
				flag=true;
				printf("(%c,%d) ",i+64,ans[i]);
			}
			//復原這條邊
			list[i][ans[i]]=1;
		}
		if(!flag)
			printf("none\n\n");
		else
			printf("\n\n");
			
	}
	return 0;
}