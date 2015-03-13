#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	bool flag;
	int T,m,n,i,j,data,k;
	vector<int> data1,data2,dataQ;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&data);
			data1.push_back(data);
		}
		//sort(data1.begin(),data1.end());
		for(i=1;i<m;i++)
		{
			sort(data1.begin(),data1.end());
			for(j=0;j<n;j++)
			{
				scanf("%d",&data);
				data2.push_back(data);
			}
			sort(data2.begin(),data2.end());
			for(j=0;j<n;j++)
				dataQ.push_back(data1[j]+data2[0]);
			make_heap(dataQ.begin(),dataQ.end());//���@��max-heap dataQ.front()�O�̤j�� dataQ.back()�O�̤p��
												//�S�����w���ܡAmake_heap�X�ӬO�j����A�̤W�h���O�̤j��
			for(j=1;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					data=data1[k]+data2[j];
					if(data<dataQ.front())
					{
						pop_heap(dataQ.begin(),dataQ.end());//�o�ӬO��̤j�ȩ��̫�@�Ӧ�m
						dataQ.pop_back();//������̫�@��m����pop�X��
						dataQ.push_back(data);//��i�̫�@��m
						push_heap(dataQ.begin(),dataQ.end());//��̫᪺�o�ӭȲ��ʨ쥿�T����m�W
					}
				}
			}
			copy(dataQ.begin(),dataQ.end(),data1.begin());//dataQ�ƻs��data1
			data2.clear();
			dataQ.clear();
		}
		sort(data1.begin(),data1.end());
		flag=false;
		for(i=0;i<n;i++)
		{
			if(flag)
				printf(" ");
			flag=true;
			printf("%d",data1[i]);
		}
		printf("\n");
		data1.clear();
	}
	return 0;
}