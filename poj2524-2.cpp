#include<iostream>
#include<cstdio>
#define MAX 50001
int set[MAX];

int find(int x)
{
    if(x!=set[x])//當前位置不等於其所代表的值，表示他與其他人有相同的信仰
        set[x]=find(set[x]);//找信仰
    return set[x];
}
void merge(int a,int b)
{
    set[find(a)]=find(b);
}
int main()
{
    int n,m,a,b,c=1,i;
    while(scanf("%d %d",&n,&m))
    {
		if(n==m&&n==0)
			break;
		for(i=0;i<n;i++)//每一個人本來都是自己的信仰
			set[i]=i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            if(find(a)!=find(b))
            {
                n--;//記錄有幾個信仰
                merge(a,b);
            }
        }
        printf("Case %d: %d\n", c++, n);
    }
}