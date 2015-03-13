/*Bipartite matching
A 機器有0~n-1種mode
B 機器有0~m-1種mode

此題的bipartite graph

應為A mode 為x群, B mode 為y群
連接的邊為各個job

找此圖的bipartite matching M
因為兩兩沒有公共點，表示M為最少需要花費的轉移時間，其他邊一定可以被覆蓋

若為mode 0可以執行的，就不需建邊了，因為一開始就在mode 0底下
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int llink[110],rlink[110];
bool used[110];
vector<int> list[110];
bool DFS(int now)
{
	int i,next;
	for(i=0;i<list[now].size();i++)//掃過now這點的所有相連邊
	{
		next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			if(!rlink[next] || DFS(rlink[next]))
			{
				rlink[next]=now;
				llink[now]=next;
				return true;
			}
		}
	}
	return false;
}
int bipartite(int L)
{
	int i,ret=0;
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	for(i=1;i<L;i++)//左邊的每個點都掃過去	
	{
		memset(used,false,sizeof(used));
		if(DFS(i))
			ret++;
	}
	return ret;
}
int main()
{
	int n,m,k,i,id,a,b,ans;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=0;i<110;i++)
			list[i].clear();
		scanf("%d%d",&m,&k);
		for(i=0;i<k;i++)
		{
			scanf("%d%d%d",&id,&a,&b);
			if(a*b!=0)//如果a或b其一為0，則不需畫入圖中，因為一開始就是mode 0
				list[a].push_back(b);
		}
		ans=bipartite(n);
		printf("%d\n",ans);
	}
	return 0;
}