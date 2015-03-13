#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define Max 65000
using namespace std;

int list[Max],dp[Max],n,len;
void MSS()
{
	int i,row,j,M=0;
	dp[1]=list[1];
	row=1;
	for(i=2,j=1;i<=len;i++,j++)
	{
		if(j>row+1)//传︽
		{
			j=1;
			row=row+1;
		}
		if(j==1)//程オ娩计
			dp[i]=dp[i-row]+list[i];
		else if(j==row+1)//程娩计
			dp[i]=dp[i-row-1]+list[i];
		else
			dp[i]=max(dp[i-row]+list[i],dp[i-row-1]+list[i]);
		if(M<dp[i])
			M=dp[i];
	}
	printf("%d\n",M);
}
int main()
{
	int i;
	scanf("%d",&n);
	len=(1+n)*n/2;
	for(i=1;i<=len;i++)
		scanf("%d",&list[i]);
	MSS();
	return 0;
}