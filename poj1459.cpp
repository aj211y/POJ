#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#define INF 1000000
using namespace std;

bool visited[105];//DFS�n�Ϊ�
int flow[105][105],cap[105][105],path[105];//cap�e�q flow�y�q
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
			path[i]=s;//�O���W�@�Ӧ�m
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
			if(cap[f][tmp]-flow[f][tmp]>0 || flow[tmp][f]>0)//���y�q�i���ΤϦV
			{
				if(!visited[tmp])
				{
					list.push(tmp);
					visited[tmp]=true;
					path[tmp]=f;//������A����B path[B]=A;
				}
				if(tmp==t)//���쵲���A��ܦ����@���i������
					return true;
			}
		}
	}
	return false;//�S�����i�H���F
}
int findflow(int s,int t)
{
	int f=INF;//�L���j
	for(int i=t,pre;i!=s;i=pre)//��bottleneck
	{
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(int i=t,pre;i!=s;i=pre)//�����y�q
	{
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}
	return f;//�^�Ǭy�q
}
int maxflow(int s,int t)
{
	int ret=0;
	while(1)
	{
		memset(visited,false,sizeof(visited));
		memset(path,0,sizeof(path));
		if(!BFS(s,t))//�䤣��i�H�������|�F �o�DDFS�|TLE
			break;
		ret+=findflow(s,t);//DFS(��BFS)�������|����A�٭n�����|����q�L���̤j�y�q
	}
	return ret;//�^�ǳ̤j�y�q
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