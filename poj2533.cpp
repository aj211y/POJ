#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int N,list[1010],i,dp[1010],j,ans;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d",&list[i]);
			dp[i]=1;
		}
		ans=dp[0];
		for(i=1;i<N;i++)
		{
			for(j=0;j<i;j++)
			{
				if(list[i]>list[j] && dp[j]+1>dp[i])
				{
					dp[i]=dp[j]+1;
				}
			}
			if(dp[i]>ans)
				ans=dp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}