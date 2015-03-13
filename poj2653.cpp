#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

struct aLine
{
	int id;
	double x1,y1,x2,y2;
};
vector<aLine> line;
queue<int> ans;
int n;
double cross(double bx1,double by1,double bx2,double by2,double ax1,double ay1)
{
	return  (ax1-bx1)*(by2-by1)-(ay1-by1)*(bx2-bx1);
}
bool onSegment(double bx1,double by1,double bx2,double by2,double ax1,double ay1)
{
	if(min(bx1,bx2)<=ax1&&ax1<=max(bx1,bx2) && min(by1,by2)<=ay1&&ay1<=max(by1,by2))
		return true;
	else
		return false;
}
bool isCross(aLine a,aLine b)//有無相交
{
	double d1,d2,d3,d4;
	d1=cross(b.x1,b.y1,b.x2,b.y2,a.x1,a.y1);
	d2=cross(b.x1,b.y1,b.x2,b.y2,a.x2,a.y2);
	d3=cross(a.x1,a.y1,a.x2,a.y2,b.x1,b.y1);
	d4=cross(a.x1,a.y1,a.x2,a.y2,b.x2,b.y2);
	if(d1*d2<0  && d3*d4<0)//有相交
		return true;
	else if(d1==0 && d2==0)//兩線段在同一直線上，要判斷有沒有重疊
	{
		//有重疊
		if(onSegment(b.x1,b.y1,b.x2,b.y2,a.x1,a.y1)||onSegment(b.x1,b.y1,b.x2,b.y2,a.x2,a.y2))
			return true;
		else
			return false;
	}
	else
	{
		if(d1==0)
			return onSegment(b.x1,b.y1,b.x2,b.y2,a.x1,a.y1);
		else if(d2==0)
			return onSegment(b.x1,b.y1,b.x2,b.y2,a.x2,a.y2);
		else if(d3==0)
			return onSegment(a.x1,a.y1,a.x2,a.y2,b.x1,b.y1);
		else if(d4==0)
			return onSegment(a.x1,a.y1,a.x2,a.y2,b.x2,b.y2);
		else
			return false;
	}
}
void solution(aLine top)
{
	aLine tmp;
	int i;
	bool flag=false;
	for(i=top.id;i<n;i++)
	{
		tmp=line[i];
		if(isCross(tmp,top))
		{
			flag=true;
			break;
		}
	}
	if(!flag)
		ans.push(top.id);
}
int main()
{
	int i;
	aLine data;
	while(scanf("%d",&n)&&n!=0)
	{
		for(i=1;i<=n;i++)
		{
			data.id=i;
			scanf("%lf%lf%lf%lf",&data.x1,&data.y1,&data.x2,&data.y2);
			line.push_back(data);
		}
		for(i=0;i<n;i++)
		{
			solution(line[i]);
		}
		printf("Top sticks:");
		while(!ans.empty())
		{
			printf(" %d",ans.front());
			ans.pop();
			if(ans.empty())
				printf(".\n");
			else
				printf(",");
		}
		line.clear();
	}
	return 0;
}