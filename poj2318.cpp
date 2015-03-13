#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;

struct line
{
	int U,L,id;
};
vector<line> list;
int box[6000],x1,x2,y1,y2;
bool inBox(int x,int y,line a)
{
	if(((a.U-a.L)*(y-y2)-(x-a.L)*(y1-y2))>=0)
		return true;
	else 
		return false;
}
void solution(int x,int y)
{
	int i;
	for(i=0;i<list.size();i++)
	{
		if(inBox(x,y,list[i]))
		{
			box[i]++;
			break;
		}
	}
}
int main()
{
	//point p;
	line l;
	int n,m,i,x,y;
	bool flag=false;
	while(scanf("%d",&n)&&n!=0)
	{
		if(flag)
			printf("\n");
		flag=true;
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		memset(box,0,sizeof(box));
		for(i=0;i<n;i++)
		{
			l.id=i;
			scanf("%d%d",&l.U,&l.L);
			list.push_back(l);
		}
		l.id=n;
		l.U=x2;
		l.L=x2;
		list.push_back(l);
		while(m--)
		{
			scanf("%d%d",&x,&y);
			solution(x,y);
		}
		for(i=0;i<=n;i++)
		{
			printf("%d: %d\n",i,box[i]);
		}
		
		list.clear();
	}
	return 0;
}