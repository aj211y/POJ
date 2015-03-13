#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define Max 2100
using namespace std;

int p[Max*2];
int FindSet(int x)
{
	return (p[x]==x)?x:p[x]=FindSet(p[x]);
}
int main()
{						//px py��ۤv�P�@����bug�ʧO  rx ry��px py�ۤϩʧO
	int test,i,j,N,K,x,y,px,py,rx,ry;
	bool ans,blank=false;
	scanf("%d",&test);
	for(i=1;i<=test;i++)
	{
		if(blank)
			printf("\n");
		blank=true;
		scanf("%d%d",&N,&K);//N���� K�����O
		for(j=0;j<N;j++)
		{
			p[j]=j;
			p[j+N]=j+N;
		}
		ans=true;
		for(j=0;j<K;j++)
		{
			scanf("%d%d",&x,&y);//x��y�O���P�ʧO
			if(ans)
			{
				px=FindSet(x);//x���ʧO
				py=FindSet(y);//y���ʧO
				rx=FindSet(x+N);//x���ۤϩʧO
				ry=FindSet(y+N);//y���ۤϩʧO
				if(px==py || rx==ry)
					ans=false;
				p[px]=ry;
				p[py]=rx;
			}
		}
		printf("Scenario #%d:\n",i);
		printf("%s\n",ans?"No suspicious bugs found!":"Suspicious bugs found!");
		
	}
	return 0;
}