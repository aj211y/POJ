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
			make_heap(dataQ.begin(),dataQ.end());//暗max-heap dataQ.front()琌程 dataQ.back()琌程
												//⊿Τ﹚杠make_heapㄓ琌郴帮程糷琌程
			for(j=1;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					data=data1[k]+data2[j];
					if(data<dataQ.front())
					{
						pop_heap(dataQ.begin(),dataQ.end());//硂琌р程程竚
						dataQ.pop_back();//р程竚popㄓ
						dataQ.push_back(data);//秈程竚
						push_heap(dataQ.begin(),dataQ.end());//р程硂簿笆タ絋竚
					}
				}
			}
			copy(dataQ.begin(),dataQ.end(),data1.begin());//dataQ狡籹data1
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