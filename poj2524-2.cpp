#include<iostream>
#include<cstdio>
#define MAX 50001
int set[MAX];

int find(int x)
{
    if(x!=set[x])//��e��m�������ҥN���ȡA��ܥL�P��L�H���ۦP���H��
        set[x]=find(set[x]);//��H��
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
		for(i=0;i<n;i++)//�C�@�ӤH���ӳ��O�ۤv���H��
			set[i]=i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            if(find(a)!=find(b))
            {
                n--;//�O�����X�ӫH��
                merge(a,b);
            }
        }
        printf("Case %d: %d\n", c++, n);
    }
}