/*
	�����ӵw����
	1. �N�Ҧ��ۦP�w���ݦ��ӧO���@�Ӫ��~�A���O�H�o�D�����|TLE�A�ҥH����
	2.�̾��D�ت��n�D�A�O�Ѥ�W�����w���A�ݯ�զ��h�ֺ� "���P����" ���զX
		�Ӥ��O "�Ҧ��w�����զX"
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int sum[100010],v[110],num[110];//sum[i] ��ܦb�p��Y�@�w���� ����欰i�ɡA�ҨϥΪ��w����
bool money[100010];
int main()
{
	int n,m,i,j,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{	
		memset(money,false,sizeof(money));//�զ����o�ӻ����X�{�L�F�S
		if(n==0&&m==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&v[i]);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);//��i�صw�����w���ƶq
		ans=0;
		money[0]=true;
		for(i=0;i<n;i++)//n�صw��
		{
			memset(sum,0,sizeof(sum));
			for(j=v[i];j<=m;j++)
			{
				//�S�X�{�L�o�ӻ��� && j-v[i]�o�ӻ����X�{�L && �ϥ�coin i���Ӽ��٨S���W�L(�٦�coin i�i�H�ϥ�)
				if(!money[j] && money[j-v[i]] && sum[j-v[i]]<num[i])
				{
					money[j]=true;
					sum[j]=sum[j-v[i]]+1;//�h�ΤF�@��
					ans++;//���״N�O�n�D���X�ؤ��P�������զX
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}