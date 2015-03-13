#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define INF 1000000
using namespace std;

bool visited[105];//DFS要用的
int flow[105][105],cap[105][105],path[105];//cap容量 flow流量
vector<int> spot[105];
/*bool DFS(int s,int t)
{
	visited[s]=true;
	if(s==t)
		return true;
	for(int i=0;i<=t;i++)
	{
		if(visited[i])
			continue;
		if(cap[s][i]-flow[s][i]>0 || flow[i][s]>0)
		{
			path[i]=s;//記錄上一個位置
			if(DFS(i,t))
				return true;
		}
	}
	return false;
}*/
bool BFS(int s,int t)
{
	queue<int> list;
	int f,i,tmp;
	list.push(s);
	visited[s]=true;
	while(!list.empty())
	{
		f=list.front();
		list.pop();
		for(i=0;i<spot[f].size();i++)
		{
			tmp=spot[f][i];
			if(cap[f][tmp]-flow[f][tmp]>0 || flow[tmp][f]>0)//有流量可走或反向
			{
				if(!visited[tmp])
				{
					list.push(tmp);
					visited[tmp]=true;
					path[tmp]=f;//紀錄由A走到B path[B]=A;
				}
				if(tmp==t)//走到結尾，表示有找到一條可走之路
					return true;
			}
		}
	}
	return false;//沒有路可以走了
}
int findflow(int s,int t)
{
	int f=INF;//無限大
	for(int i=t,pre;i!=s;i=pre)//找bottleneck
	{
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(int i=t,pre;i!=s;i=pre)//紀錄流量
	{
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}
	return f;//回傳流量
}
int maxflow(int s,int t)
{
	int ret=0;
	while(1)
	{
		memset(visited,false,sizeof(visited));
		memset(path,0,sizeof(path));
		if(!BFS(s,t))//找不到可以走的路徑了 這題DFS會TLE
			break;
		ret+=findflow(s,t);//DFS(或BFS)有找到路徑之後，還要取路徑中能通過的最大流量
	}
	return ret;//回傳最大流量
}


int main()
{
	int n,np,nc,m,s1,s2,d,i;
	char c;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
	{
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(path,0,sizeof(path));
		while(m--)
		{
			do{
				c=getchar();
			}while(c!='(');
			scanf("%d,%d",&s1,&s2);
			getchar();
			scanf("%d",&d);
			cap[s1+1][s2+1]=d;
			spot[s1+1].push_back(s2+1);
		}
		while(np--)
		{
			do{
				c=getchar();
			}while(c!='(');
			scanf("%d)%d",&s2,&d);
			cap[0][s2+1]=d;
			spot[0].push_back(s2+1);
		}
		while(nc--)
		{
			do{
				c=getchar();
			}while(c!='(');
			scanf("%d)%d",&s1,&d);
			cap[s1+1][n+1]=d;
			spot[s1+1].push_back(n+1);
		}
		printf("%d\n",maxflow(0,n+1));
		for(i=0;i<105;i++)
			spot[i].clear();
	}
	return 0;
}