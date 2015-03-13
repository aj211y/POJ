#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

struct cow
{
	int id,voteA,voteB;
};
bool cmpA(cow x,cow y)
{
	if(x.voteA > y.voteA)
		return true;
	else
		return false;
}
bool cmpB(cow x,cow y)
{
	if(x.voteB > y.voteB)
		return true;
	else
		return false;
}
int main()
{
	vector<cow> line;
	cow c;
	int N,K,i;
	scanf("%d%d",&N,&K);//N隻牛  第一輪的前K名進第二輪
	for(i=1;i<=N;i++)
	{
		c.id=i;
		scanf("%d%d",&c.voteA,&c.voteB);
		line.push_back(c);
	}
	sort(line.begin(),line.end(),cmpA);
	sort(line.begin(),line.begin()+K,cmpB);
	
	printf("%d\n",line[0].id);
	return 0;
}