/*
這題有點小陷阱：給定n個float的數字 使得這一串數字向左看或者向右看不會有人比自己高(也不可相同高度)
				問要剔除幾個數字可達到上列要求
example:
		3 4 5 1 2 5 4 3   
		這一串的答案為2，原因是拿掉中間的1跟2，便可形成3 4 5 5 4 3的排列樣式
		3 4 5往左看皆可符合要求 5 4 3向右看也皆可符合要求
因此，在作此題的時候，先由左往右做dp；再由右往左做dp
ans1[i] 記錄 處於位置i時 由左一直排到i時最大的排列人數
ans2[i] 記錄 處於位置i時 由右一直排到i時最大的排列人數
最大排列人數 M：ans1[i]+ans2[n-1-i]  0 <= i <= n-1
剔除人數 n-M：總人數-最大排列人數
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 1010
using namespace std;

int n,dp1[Max],dp2[Max],ans1[Max],ans2[Max];
float list[Max];
void MSS()
{
	int i,j,M1,M2,M;
	//從左往右做dp
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(list[i]>list[j] && dp1[j]+1 > dp1[i])
			{
				dp1[i]=dp1[j]+1;
			}
		}
	}
	//從右往左做dp
	for(i=n-1;i>=0;i--)
	{
		for(j=n-1;j>i;j--)
		{
			if(list[i]>list[j] && dp2[j]+1 > dp2[i])
			{
				dp2[i]=dp2[j]+1;
			}
		}
	}
	M=0;//最大排列人數
	M1=1;//從左往右的最大排列人數
	M2=1;//從右往左的最大排列人數
	ans1[0]=dp1[0];
	ans2[n-1]=dp2[n-1];
	for(i=1;i<n;i++)
	{
		if(dp1[i]>M1)
			M1=dp1[i];
		if(dp2[n-1-i]>M2)
			M2=dp2[n-1-i];
		ans1[i]=M1;
		ans2[n-1-i]=M2;
	}
	M=ans1[n-1]>ans2[0]?ans1[n-1]:ans2[0];
	for(i=0;i<n-1;i++)
	{
		if(M<ans1[i]+ans2[i+1])
			M=ans1[i]+ans2[i+1];
	}
	printf("%d\n",n-M);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%f",&list[i]);
		dp1[i]=1;
		dp2[i]=1;
		ans1[i]=0;
		ans2[i]=0;
	}
	MSS();
	return 0;
}