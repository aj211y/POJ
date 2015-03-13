#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int n,m,x1,x2,y1,y2;
struct line
{
	int U,L;
};
vector<line> list;
int box[1500];
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
	for(i=0;i<=n;i++)
	{
		if(inBox(x,y,list[i]))
		{
			//printf("%d,%d : %d\n",x,y,i);
			box[i]++;
			break;
		}
	}
}
bool cmp(line a,line b)
{
	if(a.U==b.U && a.L<b.L)
		return true;
	else if(a.U<b.U)
		return true;
	else
		return false;
}
void print()
{
	int ans[1200],i;
	memset(ans,0,sizeof(ans));
	printf("Box\n");
	for(i=0;i<=n;i++)
	{
		//printf("%d\n",box[i]);
		ans[box[i]]++;
	}
	/*for(i=0;i<=n;i++)
	{
		printf("%d : %d\n",i,ans[i]);
	}*/
	for(i=1;i<1200;i++)
	{
		if(ans[i])
		{
			printf("%d: %d\n",i,ans[i]);
		}
	}
	
}
int main()
{
	int i,x,y;
	line data;
	while(scanf("%d",&n)&& n!=0)
	{
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		memset(box,0,sizeof(box));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&data.U,&data.L);
			list.push_back(data);
		}
		sort(list.begin(),list.end(),cmp);
		data.U=x2;
		data.L=x2;
		list.push_back(data);
		while(m--)
		{
			scanf("%d%d",&x,&y);
			solution(x,y);
		}
		print();
		list.clear();
	}
	return 0;
}