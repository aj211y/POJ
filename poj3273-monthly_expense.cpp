//т窥窥程㎝┮Τ羆㎝ノbinery search碝тだ竤程
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
			beg=dayspend; //begin琌羆㎝程
		end=end+dayspend; //end琌羆㎝程
	}
	while(beg<end){
		mid=(beg+end)/2;
		if(canbe(mid,money)<m)//狦ゑmボ┕т
			end=mid;
		else
			beg=mid+1;//璶罽絛瞅
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
	return div; //だΘ碭刮
}