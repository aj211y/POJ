#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
/*
0 stop serving
1 K P 增加client K到waiting list(有著priority P)
2 服務最高priority的客戶
3 服務最低priority的客戶
*/
int main()
{
	int id,K,P;
	set<int> pri;
	set<int>::iterator it;
	set<int>::reverse_iterator rit;
	map<int,int> list;
	while(scanf("%d",&id)!=EOF)
	{
		if(id==0)
			break;
		if(id==1)//insert
		{
			scanf("%d%d",&K,&P);
			pri.insert(P);
			list[P]=K;
		}
		else if(id==2)//serve highest
		{
			if(pri.begin()==pri.end())//pri為空
				printf("0\n");
			else
			{
				rit=pri.rbegin();//最後一個元素
				printf("%d\n",list[*rit]);
				pri.erase(*rit);
			}
		}
		else if(id==3)
		{
			if(pri.begin()==pri.end())//pri為空
				printf("0\n");
			else
			{
				it=pri.begin();//第一個元素
				printf("%d\n",list[*it]);
				pri.erase(*it);
			}
		}
	}
	return 0;
}