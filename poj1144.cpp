#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<int> list[120];
int ans,low[120],dfn[120],dfs_clock;
void DFS(int cur,int pa)
{
	int child=0;
	bool flag=false;
	low[cur]=dfn[cur]=dfs_clock++;
	
	for(int i=0;i<list[cur].size();i++)
	{
		int next=list[cur][i];
		if(!dfn[next])
		{
			child++;
			DFS(next,cur);
			low[cur]=min(low[cur],low[next]);
			if(low[next]>=dfn[cur])
				flag=true;
		}
		else if(next != pa)
			low[cur]=min(low[cur],dfn[next]);
	}
	if((child>=2 || pa >0) && flag)
		ans++;
	return ;
}
int main()
{
	int n,des,i,start;
	string line;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=0;i<120;i++)
			list[i].clear();
		getchar();
		while(getline(cin,line))
		{
			if(line[0]=='0')//the end of this case
				break;
			start=0;
			for(i=0;line[i]!=' ';i++)
				start=start*10+(line[i]-48);
			des=0;
			i++;
			for(;i<line.size();i++)
			{
				if(line[i]==' ')
				{
					list[start].push_back(des);
					list[des].push_back(start);
					//printf("s%d d%d\n",start,des);
					des=0;
				}
				else
					des=des*10+(line[i]-48);
			}
			//the last node
			list[start].push_back(des);
			list[des].push_back(start);
		}
		ans=0;
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		dfs_clock=1;
		DFS(1,0);
		printf("%d\n",ans);
	}
	return 0;
}