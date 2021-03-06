//找錢錢最大值和所有的總和，用binery search尋找可能的分群最小值
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int canbe(int mid,vector<int> money);
int main()
{
	int n,m,dayspend,beg=0,mid,end=0;
	vector<int> money;
	scanf("%d %d",&n,&m);
	while(n--){
		scanf("%d",&dayspend);
		money.push_back(dayspend);
		if(dayspend>beg)
			beg=dayspend; //begin是總和的可能最小值
		end=end+dayspend; //end是總和的可能最大值
	}
	while(beg<end){
		mid=(beg+end)/2;
		if(canbe(mid,money)<m)//如果比m小表示可以再往下找
			end=mid;
		else
			beg=mid+1;//要縮小範圍
	}
	printf("%d\n",beg);
	return 0;
}
int canbe(int mid,vector<int> money)
{
	int i=-1,group=0,div=0;
	while(++i<money.size()){
		group=group+money[i];
		if(group>mid){
			group=0;
			div++;
			i--;
		}
	}
	return div; //分成幾團
}