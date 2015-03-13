#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MMAX 1000000;
#define M 51000
using namespace std;

int num[M];
struct node
{
	int max,min,beg,end;
};
node list[M*3];
void create(int id,int beg,int end)
{
	int mid=(beg+end)/2;
	list[id].beg=beg;
	list[id].end=end;
	if(beg==end)
	{
		list[id].max=num[beg];
		list[id].min=num[end];
		return;
	}
	create(id*2,beg,mid);
	create(id*2+1,mid+1,end);
	list[id].max=max(list[id*2].max,list[id*2+1].max);
	list[id].min=min(list[id*2].min,list[id*2+1].min);
}
int find_max(int id,int beg,int end)
{
	if(beg>list[id].end || end<list[id].beg)//所求區間完全落在已知區間外
		return 0;
	else if(list[id].beg>=beg && list[id].end<=end)//所求區間完全落在已知區間內
		return list[id].max;
	else
		return max(find_max(id*2,beg,end),find_max(id*2+1,beg,end));//beg所求區間起始點 end所求區間結束點
}
int find_min(int id,int beg,int end)
{
	if(beg>list[id].end || end<list[id].beg)//所求區間完全落在已知區間外
		return MMAX;
	if(list[id].beg>=beg && list[id].end<=end)//所求區間完全落在已知區間內
		return list[id].min;
	else
		return min(find_min(id*2,beg,end),find_min(id*2+1,beg,end));//beg所求區間起始點 end所求區間結束點
}
/*int segment(int beg,int end)
{
	return (find_max(1,beg,end)-find_min(1,beg,end));
}*/
int main()
{
	int N,Q,i,a,b,ans;
	memset(num,0,sizeof(num));
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&num[i]);
	}
	create(1,1,N);
	while(Q--)
	{
		scanf("%d%d",&a,&b);
		//printf("%d %d\n",find_max(1,a,b),find_min(1,a,b));
		ans=find_max(1,a,b)-find_min(1,a,b);
		printf("%d\n",ans);
	}
	return 0;
}