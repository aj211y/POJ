/*
	有限個硬幣數
	1. 將所有相同硬幣看成個別的一個物品，但是以這題來講會TLE，所以不行
	2.依據題目的要求，是由手上有的硬幣，看能組成多少種 "不同價錢" 的組合
		而不是 "所有硬幣的組合"
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int sum[100010],v[110],num[110];//sum[i] 表示在計算某一硬幣時 當價格為i時，所使用的硬幣數
bool money[100010];
int main()
{
	int n,m,i,j,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{	
		memset(money,false,sizeof(money));//組成的這個價錢出現過了沒
		if(n==0&&m==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&v[i]);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);//第i種硬幣的硬幣數量
		ans=0;
		money[0]=true;
		for(i=0;i<n;i++)//n種硬幣
		{
			memset(sum,0,sizeof(sum));
			for(j=v[i];j<=m;j++)
			{
				//沒出現過這個價錢 && j-v[i]這個價錢出現過 && 使用coin i的個數還沒有超過(還有coin i可以使用)
				if(!money[j] && money[j-v[i]] && sum[j-v[i]]<num[i])
				{
					money[j]=true;
					sum[j]=sum[j-v[i]]+1;//多用了一個
					ans++;//答案就是要求有幾種不同的價錢組合
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}