#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAX 100010
using namespace std;

struct cow
{
	long long int D,T;
	float rate;
};
cow line[MAX];
long long int dp[MAX]; 
bool cmp(cow a,cow b)
{
	if(a.rate==b.rate)
	{
		if(a.T*b.D>b.T*a.D)
			return true;
		else
			return false;
	}
	else if(a.rate<b.rate)
		return true;
	else
		return false;
}
int main()
{
	long long int N,i,ans=0;
	memset(dp,0,sizeof(dp));
	scanf("%lld",&N);
	for(i=0;i<N;i++)
	{
		scanf("%lld%lld",&line[i].T,&line[i].D);
		line[i].rate=((float)line[i].D)/line[i].T;
	}
	sort(line,line+N,cmp);
	dp[0]=line[0].D;
	for(i=1;i<N;i++)
		dp[i]=dp[i-1]+line[i].D;
	for(i=N-1;i>0;i--)
	{
		ans+=2*line[i].T*dp[i-1];
	}
	printf("%lld\n",ans);
	return 0;
}