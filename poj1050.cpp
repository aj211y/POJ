/*尋找最大的矩形，使得矩形內的數字和最大
概念：在每一行中找到最大的子字串 若為當前遇到的最大數目，則記錄起來
	  找完一行之後，將下一行加入正在找解的陣列中，使其求解時，一直都是對"一行"數字串找最大子字串
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 110
using namespace std;

int array[Max][Max],n;
int MSS(int arr[])
{
	int i,dp[Max],sum;
	sum=0;
	dp[0]=arr[0];
	for(i=1;i<n;i++)
	{
		if(dp[i-1]+arr[i]>=0)
			dp[i]=dp[i-1]+arr[i];
		else
			dp[i]=arr[i];
		if(sum<dp[i])
			sum=dp[i];
	}
	return sum;
}
int Find_Max_Rectangle()
{
	int i,j,k,M,sum,temp[Max];
	M=0;
	for(i=0;i<n;i++)//現在要找從第i行開始的各種矩形解
	{
		for(j=0;j<n;j++)//清空 初始化
			temp[j]=0;
		for(j=i;j<n;j++)//從第i行開始的各種矩形解
		{
			for(k=0;k<n;k++)
				temp[k]+=array[j][k];//將第j行的各個元素加入正在找解的陣列中  
									 //temp陣列現存的各個元素為 範圍從第i行~第j行 的各列元素和
			sum=MSS(temp);//找此新的矩形所擁有的最佳解
			if(sum>M)//如果新的矩形解比之前所找到的解都還要佳(也就是又找到更大的解)
				M=sum;
		}							 
	}
	return M;
}
int main()
{
	int ans,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		//輸入二維陣列
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&array[i][j]);
		}
		//尋找最大的矩形，使得矩形內的數字和最大
		ans=Find_Max_Rectangle();
		printf("%d\n",ans);
	}
	return 0;
}