#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,last,tmp,N;
	long long int data,sum=0;
	vector<long long int> list;
	scanf("%d",&N);
	tmp=N;
	while(tmp--){
		scanf("%lld",&data);
		list.push_back(data);
	}
	sort(list.begin(),list.end());
	last=list.size()-1;
	tmp=N-1;//單點到各點有幾條線
	for(i=0;i<list.size();i++){	
		sum=sum+(list[last]-list[i])*tmp;
		tmp=tmp-2;//新的單點所擁有的點個數會少1，而最常一條(單點到最後一點的距離)以被用過所以還要再少1
	}
	printf("%lld\n",sum*2);
	return 0;
}