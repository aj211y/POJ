#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int list[1500];
int bubble_sort(int n)
{
	int k,j,count=0;
	for(k=n-1;k>=1;k--)
	{
		for(j=0;j<k;j++)
		{
			if(list[j]>list[j+1])
			{
				swap(list[j],list[j+1]);
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int n,t,i,test=1;
	scanf("%d",&n);
	while(n--)
	{
		memset(list,0,sizeof(list));
		scanf("%d",&t);
		for(i=0;i<t;i++)
			scanf("%d",&list[i]);
		printf("Scenario #%d:\n",test++);
		printf("%d\n\n",bubble_sort(t));
	}
	return 0;
}