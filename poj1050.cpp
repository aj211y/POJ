/*�M��̤j���x�ΡA�ϱo�x�Τ����Ʀr�M�̤j
�����G�b�C�@�椤���̤j���l�r�� �Y����e�J�쪺�̤j�ƥءA�h�O���_��
	  �䧹�@�椧��A�N�U�@��[�J���b��Ѫ��}�C���A�Ϩ�D�ѮɡA�@�����O��"�@��"�Ʀr���̤j�l�r��
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Max 110
using namespace std;

int array[Max][Max],n;
int MSS(int arr[])
{
	int i,dp[Max],sum;
	sum=0;
	dp[0]=arr[0];
	for(i=1;i<n;i++)
	{
		if(dp[i-1]+arr[i]>=0)
			dp[i]=dp[i-1]+arr[i];
		else
			dp[i]=arr[i];
		if(sum<dp[i])
			sum=dp[i];
	}
	return sum;
}
int Find_Max_Rectangle()
{
	int i,j,k,M,sum,temp[Max];
	M=0;
	for(i=0;i<n;i++)//�{�b�n��q��i��}�l���U�دx�θ�
	{
		for(j=0;j<n;j++)//�M�� ��l��
			temp[j]=0;
		for(j=i;j<n;j++)//�q��i��}�l���U�دx�θ�
		{
			for(k=0;k<n;k++)
				temp[k]+=array[j][k];//�N��j�檺�U�Ӥ����[�J���b��Ѫ��}�C��  
									 //temp�}�C�{�s���U�Ӥ����� �d��q��i��~��j�� ���U�C�����M
			sum=MSS(temp);//�䦹�s���x�ΩҾ֦����̨θ�
			if(sum>M)//�p�G�s���x�θѤ񤧫e�ҧ�쪺�ѳ��٭n��(�]�N�O�S����j����)
				M=sum;
		}							 
	}
	return M;
}
int main()
{
	int ans,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		//��J�G���}�C
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&array[i][j]);
		}
		//�M��̤j���x�ΡA�ϱo�x�Τ����Ʀr�M�̤j
		ans=Find_Max_Rectangle();
		printf("%d\n",ans);
	}
	return 0;
}