#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N,tmp;
	double num;
	vector<double> list;
	scanf("%d",&N);
	tmp=N;
	while(tmp--){
		scanf("%lf",&num);
		list.push_back(num);
	}
	sort(list.begin(),list.end());
	if(N%2)
		printf("%.1lf\n",list[N/2]);
	else
		printf("%.1lf\n",(list[N/2-1]+list[N/2])/2);
	return 0;
}