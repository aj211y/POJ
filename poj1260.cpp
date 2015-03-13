/*
	硂肈ぃノgreedyぃㄣΤ程ㄎ挡篶
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1010],sum[1010],price[1010];
int main()
{
	int test,n,i,j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		dp[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&sum[i],&price[i]);
			if(i==1)
				dp[i]=(sum[i]+10)*price[i];
			else
			{
				sum[i]+=sum[i-1];//ヘ玡ゎ┮惠潦禦羆痌计
				dp[i]=(sum[i]+10)*price[i];//安砞程ㄎ秆场常程蔼基禦┮惠痌计
				for(j=1;j<i;j++)
				{
					if(dp[j]+(sum[i]-sum[j]+10)*price[i] < dp[i])
						dp[i]=dp[j]+(sum[i]-sum[j]+10)*price[i];
				}
			}
			//printf("%d\n",dp[i]);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}