/*
	�o�D�����greedy�A���㦳�̨Τl���c
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
				sum[i]+=sum[i-1];//�ثe����һ��ʶR���`�ï]��
				dp[i]=(sum[i]+10)*price[i];//�����]�̨θѬ��������H�̰�����R�U�һݪ��ï]��
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