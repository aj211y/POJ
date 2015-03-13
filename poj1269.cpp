//這題的line是線 不是線段
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

struct point
{
	int x,y;
};
int cross(point p1,point p3,point p4)
{
	return (p1.x-p3.x)*(p4.y-p3.y)-(p4.x-p3.x)*(p1.y-p3.y);
}
void solution(point p1,point p2,point p3,point p4)
{
	double dx1,dx2,dy1,dy2;
	double ansx,ansy;
	dx1=p2.x-p1.x;
	dx2=p4.x-p3.x;
	dy1=p2.y-p1.y;
	dy2=p4.y-p3.y;
	ansx=(p3.y*dx2*dx1-p1.y*dx2*dx1+p1.x*dy1*dx2-p3.x*dy2*dx1)/(dy1*dx2-dy2*dx1);
	ansy=(ansx-p3.x)*dy2/dx2+p3.y;
	printf("POINT %.2lf %.2lf\n",ansx,ansy);
}
void check(point p1,point p2,point p3,point p4)
{
	int d1,d2,d3,d4;
	d1=cross(p3,p4,p1);
	d2=cross(p3,p4,p2);
	d3=cross(p1,p2,p3);
	d4=cross(p1,p2,p4);
	//if(d1*d2<0&&d3*d4<0)//兩線相交
	//{
		//printf("cross\n");
	//}
	//else if(d1*d2*d3*d4==0)
	//{
		if(((p2.x-p1.x)*(p4.y-p3.y)-(p2.y-p1.y)*(p4.x-p3.x))==0)//外積為0  平行或同一條線
		{
			if(d1==0&&d2==0)//在同一條線上，但不一定有重疊
				printf("LINE\n");
			else
				printf("NONE\n");
		}
		else
		{
			//printf("cross\n");
			solution(p1,p2,p3,p4);
			/*if(d1==0&&d2!=0&&min(p3.x,p4.x)<=p1.x&&p1.x<=max(p3.x,p4.x)&&min(p3.y,p4.y)<=p1.y&&p1.y<=max(p3.y,p4.y))
				printf("POINT %.2f %.2f\n",p1.x,p1.y);
			else if(d2==0&&d1!=0&&min(p3.x,p4.x)<=p2.x&&p2.x<=max(p3.x,p4.x)&&min(p3.y,p4.y)<=p2.y&&p2.y<=max(p3.y,p4.y))
				printf("POINT %.2f %.2f\n",p2.x,p2.y);
			else if(d3==0&&d4!=0&&min(p1.x,p2.x)<=p3.x&&p3.x<=max(p1.x,p2.x)&&min(p1.y,p2.y)<=p3.y&&p3.y<=max(p1.y,p2.y))
				printf("POINT %.2f %.2f\n",p3.x,p3.y);
			else if(d4==0&&d3!=0&&min(p1.x,p2.x)<=p4.x&&p4.x<=max(p1.x,p2.x)&&min(p1.y,p2.y)<=p4.y&&p4.y<=max(p1.y,p2.y))
				printf("POINT %.2f %.2f\n",p4.x,p4.y);*/
		}
		
	//}
	//else
	//{
		//printf("NONE\n");//只有平行的時候輸出NONE
	//}
}
int main()
{
	int num;
	bool flag=true;
	point p1,p2,p3,p4;
	scanf("%d",&num);
	while(num--)
	{
		if(flag)
		{
			printf("INTERSECTING LINES OUTPUT\n");
			flag=false;
		}
		scanf("%d%d%d%d%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
		check(p1,p2,p3,p4);
	}
	printf("END OF OUTPUT\n");
	return 0;
}