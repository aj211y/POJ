#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 100010
using namespace std;

int p[2*Max],N,M;

int FindSet(int x)
{
	return p[x]==x?x:p[x]=FindSet(p[x]);
}
void Union(int x,int y)
{
	int px=FindSet(x),py=FindSet(y);
	int ex=FindSet(x+N),ey=FindSet(y+N);
	p[px]=ey;
	p[py]=ex;
}
int main()
{
	int test,a,b,i;
	char c;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&N,&M);
		for(i=0;i<=N;i++)
		{
			p[i]=i;
			p[i+N]=i+N;
		}
		while(M--)
		{
			getchar();
			scanf("%c %d%d",&c,&a,&b);
			if(c=='A')
			{
				if(FindSet(a)==FindSet(b))
					printf("In the same gang.\n");
				else if(FindSet(a)==FindSet(b+N))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");			
			}
			else//c=='D'
			{
				Union(a,b);
			}
		}
	}
	return 0;
}