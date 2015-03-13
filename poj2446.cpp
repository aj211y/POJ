#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

int llink[520],rlink[520],Left[520];
bool used[520];
vector<int> list[520];
set<int> hole;

bool DFS(int now)
{
	int i,next;
	for(i=0;i<list[now].size();i++)
	{
		next=list[now][i];
		if(!used[next])
		{
			used[next]=true;
			if(!rlink[next] || DFS(rlink[next]))
			{
				llink[now]=next;
				rlink[next]=now;
				return true;
			}
		}
	}
	return false;
}
int bipartite(int L)
{
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));
	int i,ret=0;
	for(i=1;i<L;i++)
	{
		memset(used,0,sizeof(used));
		if(DFS(i))
			ret++;
	}
	return ret;
}
int main()
{
	int row,col,k,i,r,c,j,id,next,l,ans;
	map<int ,int > right;
	scanf("%d%d%d",&row,&col,&k);
	for(i=0;i<520;i++)
		list[i].clear();
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&c,&r);
		hole.insert((r-1)*col+c);
	}
	l=1;
	r=1;
	for(i=1;i<=row;i++)
	{
		if(i%2==1)//�_�Ʀ�
			j=1;
		else
			j=2;
		for(;j<=col;j=j+2)
		{
			id=(i-1)*col+j;//���䪺�I
			if(j==2)
				right[id-1]=r++;
			Left[l++]=id;
			if(j!=col)
				right[id+1]=r++;
		}
	}
	ans=l-1;//���ӭn���o��h�ӥ��I
	for(i=1;i<l;i++)
	{
		id=Left[i];
		if(hole.find(id)==hole.end())//���O�@��hole
		{
			if(id%col!=0 && right.find(id+1)!=right.end() && hole.find(id+1)==hole.end())//�k�@�� �ݩ�right�ϰ�
				list[i].push_back(right[id+1]);
			if((id-1)%col!=0 && right.find(id-1)!=right.end()&& hole.find(id-1)==hole.end())//���@�� �ݩ�right�ϰ�
				list[i].push_back(right[id-1]);
			if((id-1)/col!=0 && right.find(id-col)!=right.end()&& hole.find(id-col)==hole.end())//�W�@�� �ݩ�right�ϰ�
				list[i].push_back(right[id-col]);
			if((id-1)/col<row-1 && right.find(id+col)!=right.end()&& hole.find(id+col)==hole.end())//�U�@�� �ݩ�right�ϰ�
				list[i].push_back(right[id+col]);
		}
		else
			ans--;
	}
	if(ans==bipartite(l))
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}