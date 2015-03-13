#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n,i,j,id,ni,nj;
	char list[2500],ans[2500];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		getchar();
		scanf("%c",&list[i]);
	}
	for(i=0,j=n-1,id=0;i<=j;)
	{
		if(i==j)
			break;
		if(list[i]>list[j])
			ans[id++]=list[j--];
		else if(list[i]<list[j])
			ans[id++]=list[i++];
		else//list[i]==list[j]
		{
			ni=i;
			nj=j;
			while(list[ni]==list[nj] && ni<nj)
			{
				ni++;
				nj--;
			}
			//一次只能放一個，因為雖然兩兩比較但不見得每個元素都一樣，有可能只是兩兩比較的元素一樣
			//ex: ABCCBA  ->AABBCC
			if(list[ni]<=list[nj])
				ans[id++]=list[i++];
			else// if(list[ni]>list[nj])
				ans[id++]=list[j--];
		}
		//printf("ans-%c\n",ans[id-1]);
	}
	ans[id++]=list[i];
	for(i=0;i<id;)
	{
		printf("%c",ans[i++]);
		if(i%80==0)
			printf("\n");
	}
	return 0;
}