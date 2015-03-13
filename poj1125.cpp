#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 10000
using namespace std;

int dis[110][110],n;
void Floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dis[i][k]+dis[k][j] < dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
}
int main()
{
	int i,des,j,num,time,min_p,min_t,tmp_t;
	bool NotReach;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
					dis[i][j]=0;
				else
					dis[i][j]=INF;
			}
		}
		for(i=1;i<=n;i++)//第幾個stockbroker
		{
			scanf("%d",&num);
			for(j=0;j<num;j++)
			{
				scanf("%d%d",&des,&time);
				dis[i][des]=time;
			}
		}
		Floyd();
		min_t=INF;
		for(i=1;i<=n;i++)
		{
			tmp_t=0;
			NotReach=false;
			for(j=1;j<=n;j++)
			{
				if(dis[i][j]==INF)
				{
					NotReach=true;
					break;
				}
				if(i==j)
					continue;
				if(dis[i][j]>tmp_t)
					tmp_t=dis[i][j];
			}
			if(NotReach)//因為點i無法連到每一個點，所以絕對不會是解
				continue;
			if(tmp_t<min_t)
			{
				min_t=tmp_t;
				min_p=i;
			}
		}
		if(min_t==INF)//都沒有更新到這個值，表示沒有一個點能連到每一個地方
			printf("disjoint\n");
		else
			printf("%d %d\n",min_p,min_t);
	}
	return 0;
}