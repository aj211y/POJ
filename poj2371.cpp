#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,data;
	vector<int> list;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&data);
		list.push_back(data);
	}
	sort(list.begin(),list.end());
	getchar();getchar();getchar();getchar();
	scanf("%d",&n);
	while(n--){
		scanf("%d",&data);
		printf("%d\n",list[data-1]);
	}
	return 0;
}