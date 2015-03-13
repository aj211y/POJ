#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

struct node
{
	long long int x,y;
};
node middle[1000100];
bool cmp(node a,node b)
{
	if(a.x<b.x || a.x==b.x && a.y< b.y)
		return true;
	else
		return false;
}
int main()
{
	long long int t,n,i,j,m,ans,num;
	node line[1100],tmp;
	scanf("%lld",&t);
	while(t--)
	{
		m=0;
		ans=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld%lld",&line[i].x,&line[i].y);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				middle[m].x=line[i].x+line[j].x;
				middle[m].y=line[i].y+line[j].y;
				m++;
			}
		}
		sort(middle,middle+m,cmp);
		num=0;
		tmp.x=middle[0].x;
		tmp.y=middle[0].y;
		for(i=1;i<m;i++)
		{
			if(middle[i].x==tmp.x && middle[i].y==tmp.y)
				num++;
			else
			{
				tmp.x=middle[i].x;
				tmp.y=middle[i].y;
				if(num>0)
				{
					ans+=(1+num)*num/2;
					num=0;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}