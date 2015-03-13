#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
	int x,y;
};
vector<node> list;

bool cmp(node a,node b)//基準點是(0,0)
{
	if((a.x*b.y-a.y*b.x)>0)
		return true;
	else
		return false;
}

int main()
{
	node d;
	int i;
	scanf("%d%d",&d.x,&d.y);
	while(scanf("%d%d",&d.x,&d.y)!=EOF)
	{
		list.push_back(d);
	}
	sort(list.begin(),list.end(),cmp);
	printf("(0,0)\n");
	for(i=0;i<list.size();i++)
	{
		printf("(%d,%d)\n",list[i].x,list[i].y);
	}
	return 0;
}