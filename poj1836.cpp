/*
�o�D���I�p�����G���wn��float���Ʀr �ϱo�o�@��Ʀr�V���ݩΪ̦V�k�ݤ��|���H��ۤv��(�]���i�ۦP����)
				�ݭn�簣�X�ӼƦr�i�F��W�C�n�D
example:
		3 4 5 1 2 5 4 3   
		�o�@�ꪺ���׬�2�A��]�O����������1��2�A�K�i�Φ�3 4 5 5 4 3���ƦC�˦�
		3 4 5�����ݬҥi�ŦX�n�D 5 4 3�V�k�ݤ]�ҥi�ŦX�n�D
�]���A�b�@���D���ɭԡA���ѥ����k��dp�F�A�ѥk������dp
ans1[i] �O�� �B���mi�� �ѥ��@���ƨ�i�ɳ̤j���ƦC�H��
ans2[i] �O�� �B���mi�� �ѥk�@���ƨ�i�ɳ̤j���ƦC�H��
�̤j�ƦC�H�� M�Gans1[i]+ans2[n-1-i]  0 <= i <= n-1
�簣�H�� n-M�G�`�H��-�̤j�ƦC�H��
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 1010
using namespace std;

int n,dp1[Max],dp2[Max],ans1[Max],ans2[Max];
float list[Max];
void MSS()
{
	int i,j,M1,M2,M;
	//�q�����k��dp
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(list[i]>list[j] && dp1[j]+1 > dp1[i])
			{
				dp1[i]=dp1[j]+1;
			}
		}
	}
	//�q�k������dp
	for(i=n-1;i>=0;i--)
	{
		for(j=n-1;j>i;j--)
		{
			if(list[i]>list[j] && dp2[j]+1 > dp2[i])
			{
				dp2[i]=dp2[j]+1;
			}
		}
	}
	M=0;//�̤j�ƦC�H��
	M1=1;//�q�����k���̤j�ƦC�H��
	M2=1;//�q�k�������̤j�ƦC�H��
	ans1[0]=dp1[0];
	ans2[n-1]=dp2[n-1];
	for(i=1;i<n;i++)
	{
		if(dp1[i]>M1)
			M1=dp1[i];
		if(dp2[n-1-i]>M2)
			M2=dp2[n-1-i];
		ans1[i]=M1;
		ans2[n-1-i]=M2;
	}
	M=ans1[n-1]>ans2[0]?ans1[n-1]:ans2[0];
	for(i=0;i<n-1;i++)
	{
		if(M<ans1[i]+ans2[i+1])
			M=ans1[i]+ans2[i+1];
	}
	printf("%d\n",n-M);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%f",&list[i]);
		dp1[i]=1;
		dp2[i]=1;
		ans1[i]=0;
		ans2[i]=0;
	}
	MSS();
	return 0;
}