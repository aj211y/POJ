#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 9999999
using namespace std;

int way[10010],P[510],W[510];
int main()
{
	int test,E,F,cap,n,i,j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&E,&F);
		cap=F-E;//capacity
		scanf("%d",&n);//´XºØ³f¹ô
		for(i=0;i<n;i++)
			scanf("%d%d",&P[i],&W[i]);
		for(i=1;i<10010;i++)
			way[i]=INF;
		way[0]=0;
		for(j=0;j<n;j++)
		{
			for(i=W[j];i<=cap;i++)
			{
				way[i]=min(way[i],P[j]+way[i-W[j]]);
			}
		}
		if(way[cap]==INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",way[cap]);
	}
	return 0;
}