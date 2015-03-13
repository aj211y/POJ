#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

int n;
float dis[50][50];
void Floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dis[i][k]*dis[k][j]>dis[i][j])
					dis[i][j]=dis[i][k]*dis[k][j];
			}
		}
	}
}
int main()
{
	string name,name2;
	int id,i,j,cases=1,edge;
	float rate;
	bool profit;
	map<string,int> dic;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		id=1;
		for(i=0;i<n;i++)
		{
			cin >> name;
			dic[name]=id++;
			
		}
		memset(dis,0,sizeof(dis));
		/*
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				dis[i][j]=0;
			}
		}*/
		scanf("%d",&edge);
		for(i=0;i<edge;i++)
		{
			cin >> name >> rate >> name2;
			dis[dic[name]][dic[name2]]=rate;
		}
		Floyd();
		profit=false;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dis[i][j]*dis[j][i]>1)
				{
					profit=true;
					break;
				}	
			}
			if(profit)
				break;
		}
		printf("Case %d: ",cases++);
		if(profit)
			printf("Yes\n");
		else
			printf("No\n");
		dic.clear();
	}
	return 0;
}