#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct point
{
	float x,y;
}node[220];
float dis[220][220];
int n;
void Floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(max(dis[i][k],dis[k][j])<dis[i][j])
					dis[i][j]=max(dis[i][k],dis[k][j]);
			}
		}
	}
}
int main()
{
	int i,j,cases=1;
	float a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		memset(node,0,sizeof(node));
		for(i=1;i<=n;i++)
			scanf("%f%f",&node[i].x,&node[i].y);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				dis[i][j]=sqrt(pow(node[i].x-node[j].x,2)+pow(node[i].y-node[j].y,2));
				dis[j][i]=dis[i][j];
			}
		}
		Floyd();
		printf("Scenario #%d\n",cases++);
		printf("Frog Distance = %.3f\n\n",dis[1][2]);
	}
	return 0;
}